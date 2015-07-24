/*
*********************************************************************************************************
*                                     Embedded Systems Building Blocks
*                                  Complete and Ready-to-Use Modules in C
*
*                                    Asynchronous Serial Communications
*                                    IBM-PC Serial I/O Low Level Driver
*
*                            (c) Copyright 1999, Jean J. Labrosse, Weston, FL
*                                           All Rights Reserved
*
* Filename   : COMM_PC.C
* Programmer : Jean J. Labrosse
*
* Notes      : 1) The code in this file assumes that you are using a National Semiconductor NS16450 (most
*                 PCs do or, an Intel i82C50) serial communications controller.
*
*              2) The functions (actually macros) OS_ENTER_CRITICAL() and OS_EXIT_CRITICAL() are used to
*                 disable and enable interrupts, respectively.  If using the Borland C++ compiler V3.1,
*                 all you need to do is to define these macros as follows:
*
*                     #define OS_ENTER_CRITICAL()  disable()
*                     #define OS_EXIT_CRITICAL()   enable()
*
*              3) You will need to define the following constants:
*                     COMM1_BASE    is the base address of COM1 on your PC (typically 0x03F8)
*                     COMM2_BASE    is the base address of COM2 on your PC (typically 0x02F8)
*                     COMM_MAX_RX   is the number of characters buffered by the UART
*                                        2 for the NS16450
*                                       16 for the NS16550
*
*              4) COMM_BAD_CH, COMM_NO_ERR and COMM_TX_EMPTY,
*                 COMM_NO_PARITY, COMM_ODD_PARITY and COMM_EVEN_PARITY
*                     are all defined in other modules (i.e. COMM1.H, COMM2.H or COMM3.H)
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                               INCLUDES
*********************************************************************************************************
*/

#include "includes.h"

/*$PAGE*/
/*
*********************************************************************************************************
*                                               CONSTANTS
*********************************************************************************************************
*/

#define  BIT0                       0x01
#define  BIT1                       0x02
#define  BIT2                       0x04
#define  BIT3                       0x08
#define  BIT4                       0x10
#define  BIT5                       0x20
#define  BIT6                       0x40
#define  BIT7                       0x80

#define  PIC_INT_REG_PORT         0x0020
#define  PIC_MSK_REG_PORT         0x0021

#define  COMM_UART_RBR                 0
#define  COMM_UART_THR                 0
#define  COMM_UART_DIV_LO              0
#define  COMM_UART_DIV_HI              1
#define  COMM_UART_IER                 1
#define  COMM_UART_IIR                 2
#define  COMM_UART_LCR                 3
#define  COMM_UART_MCR                 4
#define  COMM_UART_LSR                 5
#define  COMM_UART_MSR                 6
#define  COMM_UART_SCR                 7

/*
*********************************************************************************************************
*                                         LOCAL GLOBAL VARIABLES
*********************************************************************************************************
*/

static  void   (*Comm1ISROld)(void);
static  void   (*Comm2ISROld)(void);

/*$PAGE*/
/*
*********************************************************************************************************
*                                            CONFIGURE PORT
*
* Description : This function is used to configure a serial I/O port.  This code is for IBM-PCs and
*               compatibles and assumes a National Semiconductor NS16450.
*
* Arguments   : 'ch'          is the COMM port channel number and can either be:
*                                 COMM1
*                                 COMM2
*               'baud'        is the desired baud rate (anything, standard rates or not)
*               'bits'        defines the number of bits used and can be either 5, 6, 7 or 8.
*               'parity'      specifies the 'parity' to use:
*                                 COMM_PARITY_NONE
*                                 COMM_PARITY_ODD
*                                 COMM_PARITY_EVEN
*               'stops'       defines the number of stop bits used and can be either 1 or 2.
*
* Returns     : COMM_NO_ERR   if the channel has been configured.
*               COMM_BAD_CH   if you have specified an incorrect channel.
*
* Notes       : 1) Refer to the NS16450 Data sheet
*               2) The constant 115200 is based on a 1.8432 MHz crystal oscillator and a 16 x Clock.
*               3) 'lcr' is the Line Control Register and is define as:
*
*                        B7  B6  B5  B4  B3  B2  B1  B0
*                                                ------ #Bits  (00 = 5, 01 = 6, 10 = 7 and 11 = 8)
*                                            --         #Stops (0 = 1 stop, 1 = 2 stops)
*                                        --             Parity enable (1 = parity is enabled)
*                                    --                 Even parity when set to 1.
*                                --                     Stick parity (see 16450 data sheet)
*                            --                         Break control (force break when 1)
*                        --                             Divisor access bit (set to 1 to access divisor)
*               4) This function enables Rx interrupts but not Tx interrupts.
*********************************************************************************************************
*/
INT8U  CommCfgPort (INT8U ch, INT16U baud, INT8U bits, INT8U parity, INT8U stops)
{
    INT16U  div;                                      /* Baud rate divisor                             */
    INT8U   divlo;
    INT8U   divhi;
    INT8U   lcr;                                      /* Line Control Register                         */
    INT16U  base;                                     /* COMM port base address                        */


    switch (ch) {                                     /* Obtain base address of COMM port              */
        case COMM1:
             base = COMM1_BASE;
             break;

        case COMM2:
             base = COMM2_BASE;
             break;

        default:
             return (COMM_BAD_CH);
    }
    div   = (INT16U)(115200L / (INT32U)baud);         /* Compute divisor for desired baud rate         */
    divlo =  div & 0x00FF;                            /* Split divisor into LOW and HIGH bytes         */
    divhi = (div >> 8) & 0x00FF;
    lcr   = ((stops - 1) << 2) + (bits - 5);
    switch (parity) {
        case COMM_PARITY_ODD: 
             lcr |= 0x08;                             /* Odd  parity                                   */
             break;

        case COMM_PARITY_EVEN: 
             lcr |= 0x18;                             /* Even parity                                   */
             break;
    }
    OS_ENTER_CRITICAL();
    outp(base + COMM_UART_LCR, BIT7);                 /* Set divisor access bit                        */
    outp(base + COMM_UART_DIV_LO, divlo);             /* Load divisor                                  */
    outp(base + COMM_UART_DIV_HI, divhi);
    outp(base + COMM_UART_LCR, lcr);                  /* Set line control register (Bit 8 is 0)        */
    outp(base + COMM_UART_MCR, BIT3 | BIT1 | BIT0);   /* Assert DTR and RTS and, allow interrupts      */
    outp(base + COMM_UART_IER, 0x00);                 /* Disable both Rx and Tx interrupts             */
    OS_EXIT_CRITICAL();
    CommRxFlush(ch);                                  /* Flush the Rx input                            */
    return (COMM_NO_ERR);
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                           COMM ISR HANDLER
*
* Description : This function processes an interrupt from a COMM port.  The function verifies whether the
*               interrupt comes from a received character, the completion of a transmitted character or
*               both.
* Arguments   : 'ch'    is the COMM port channel number and can either be:
*                           COMM1
*                           COMM2
* Notes       : 'switch' statements are used for expansion.
*********************************************************************************************************
*/
void  CommISRHandler (INT8U ch)
{
    INT8U   c;
    INT8U   iir;                                          /* Interrupt Identification Register (IIR)   */
    INT8U   stat;
    INT16U  base;                                         /* COMM port base address                    */
    INT8U   err;
    INT8U   max;                                          /* Max. number of interrupts serviced        */


    switch (ch) {                                         /* Obtain pointer to communications channel  */
        case COMM1:
             base = COMM1_BASE;
             break;

        case COMM2:
             base = COMM2_BASE;
             break;

        default:
             base = COMM1_BASE;
             break;
    }
    max = COMM_MAX_RX;
    iir = (INT8U)inp(base + COMM_UART_IIR) & 0x07;        /* Get contents of IIR                       */
    while (iir != 1 && max > 0) {                         /* Process ALL interrupts                    */
        switch (iir) {
            case 0:                                       /* See if we have a Modem Status interrupt   */
                 c = (INT8U)inp(base + COMM_UART_MSR);    /* Clear interrupt (do nothing about it!)    */
                 break;

            case 2:                                       /* See if we have a Tx interrupt             */
                 c = CommGetTxChar(ch, &err);             /* Get next character to send.               */
                 if (err == COMM_TX_EMPTY) {              /* Do we have anymore characters to send ?   */
                                                          /* No,  Disable Tx interrupts                */
                     stat = (INT8U)inp(base + COMM_UART_IER) & ~BIT1; 
                     outp(base + COMM_UART_IER, stat);
                 } else {
                     outp(base + COMM_UART_THR, c);       /* Yes, Send character                       */
                 }
                 break;

            case 4:                                       /* See if we have an Rx interrupt            */
                 c  = (INT8U)inp(base + COMM_UART_RBR);   /* Process received character                */
                 CommPutRxChar(ch, c);                    /* Insert received character into buffer     */
                 break;

            case 6:                                       /* See if we have a Line Status interrupt    */
                 c   = (INT8U)inp(base + COMM_UART_LSR);  /* Clear interrupt (do nothing about it!)    */
                 break;
        }
        iir = (INT8U)inp(base + COMM_UART_IIR) & 0x07;    /* Get contents of IIR                       */
        max--;
    }
    switch (ch) {
        case COMM1:
        case COMM2:
             outp(PIC_INT_REG_PORT, 0x20);                /* Reset interrupt controller                */
             break;

        default:
             outp(PIC_INT_REG_PORT, 0x20);
             break;
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                    RESTORE OLD INTERRUPT VECTOR
*
* Description : This function restores the old interrupt vector for the desired communications channel.
* Arguments   : 'ch'    is the COMM port channel number and can either be:
*                           COMM1
*                           COMM2
* Note(s)     : This function assumes that the 80x86 is running in REAL mode.
*********************************************************************************************************
*/

void  CommRclIntVect (INT8U ch)
{
    CommRxIntDis(ch);
    CommRxFlush(ch);
    CommTxIntDis(ch);
    switch (ch) {
        case COMM1:
             PC_VectSet(0x0C, Comm1ISROld);
             break;

        case COMM2:
             PC_VectSet(0x0B, Comm1ISROld);
             break;
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                            FLUSH RX PORT
*
* Description : This function is called to flush any input characters still in the receiver.  This
*               function is useful when you replace the NS16450 with the more powerful NS16550.
* Arguments   : 'ch'    is the COMM port channel number and can either be:
*                           COMM1
*                           COMM2
*********************************************************************************************************
*/

void  CommRxFlush (INT8U ch)
{
    INT8U  ctr;
    INT16U base;


    switch (ch) {
        case COMM1:
             base = COMM1_BASE;
             break;

        case COMM2:
             base = COMM2_BASE;
             break;
    }
    ctr = COMM_MAX_RX;                                /* Flush Rx input                                */
    OS_ENTER_CRITICAL();
    while (ctr-- > 0) {
        inp(base + COMM_UART_RBR);
    }
    OS_EXIT_CRITICAL();
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                         DISABLE RX INTERRUPTS
*
* Description : This function disables the Rx interrupt.
* Arguments   : 'ch'    is the COMM port channel number and can either be:
*                           COMM1
*                           COMM2
*********************************************************************************************************
*/

void  CommRxIntDis (INT8U ch)
{
    INT8U stat;


    switch (ch) {
        case COMM1:
             OS_ENTER_CRITICAL();
                                                           /* Disable Rx interrupts                    */
             stat = (INT8U)inp(COMM1_BASE + COMM_UART_IER) & ~BIT0;    
             outp(COMM1_BASE + COMM_UART_IER, stat);
             if (stat == 0x00) {                           /* Both Tx & Rx interrupts are disabled ?   */
                                                           /* Yes, disable IRQ4 on the PC              */
                 outp(PIC_MSK_REG_PORT, (INT8U)inp(PIC_MSK_REG_PORT) | BIT4);  
             }
             OS_EXIT_CRITICAL();
             break;

        case COMM2:
             OS_ENTER_CRITICAL();
                                                           /* Disable Rx interrupts                    */
             stat = (INT8U)inp(COMM2_BASE + COMM_UART_IIR) & ~BIT0;    
             outp(COMM2_BASE + COMM_UART_IER, stat);
             if (stat == 0x00) {                           /* Both Tx & Rx interrupts are disabled ?   */
                                                           /* Yes, disable IRQ3 on the PC              */
                 outp(PIC_MSK_REG_PORT, (INT8U)inp(PIC_MSK_REG_PORT) | BIT3);  
             }
             OS_EXIT_CRITICAL();
             break;
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                          ENABLE RX INTERRUPTS
*
* Description : This function enables the Rx interrupt.
* Arguments   : 'ch'    is the COMM port channel number and can either be:
*                           COMM1
*                           COMM2
*********************************************************************************************************
*/

void  CommRxIntEn (INT8U ch)
{
    INT8U stat;


    switch (ch) {
        case COMM1:
             OS_ENTER_CRITICAL();
                                                           /* Enable Rx interrupts                     */
             stat = (INT8U)inp(COMM1_BASE + COMM_UART_IER) | BIT0;     
             outp(COMM1_BASE + COMM_UART_IER, stat);
                                                           /* Enable IRQ4 on the PC                    */
             outp(PIC_MSK_REG_PORT, (INT8U)inp(PIC_MSK_REG_PORT) & ~BIT4);     
             OS_EXIT_CRITICAL();
             break;

        case COMM2:
             OS_ENTER_CRITICAL();
                                                           /* Enable Rx interrupts                     */
             stat = (INT8U)inp(COMM2_BASE + COMM_UART_IER) | BIT0;     
             outp(COMM2_BASE + COMM_UART_IER, stat);
                                                           /* Enable IRQ3 on the PC                    */
             outp(PIC_MSK_REG_PORT, (INT8U)inp(PIC_MSK_REG_PORT) & ~BIT3);     
             OS_EXIT_CRITICAL();
             break;
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                          SET INTERRUPT VECTOR
*
* Description : This function installs the interrupt vector for the desired communications channel.
* Arguments   : 'ch'    is the COMM port channel number and can either be:
*                           COMM1
*                           COMM2
* Note(s)     : This function assumes that the 80x86 is running in REAL mode.
*********************************************************************************************************
*/

void  CommSetIntVect (INT8U ch)
{
    switch (ch) {
        case COMM1:
             Comm1ISROld = PC_VectGet(0x0C);
             PC_VectSet(0x0C, Comm1ISR);
             break;

        case COMM2:
             Comm2ISROld = PC_VectGet(0x0B);
             PC_VectSet(0x0B, Comm2ISR);
             break;
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                         DISABLE TX INTERRUPTS
*
* Description : This function disables the character transmission.
* Arguments   : 'ch'    is the COMM port channel number and can either be:
*                           COMM1
*                           COMM2
*********************************************************************************************************
*/

void  CommTxIntDis (INT8U ch)
{
    INT8U  stat;
    INT8U  cmd;


    switch (ch) {
        case COMM1:
             OS_ENTER_CRITICAL();
                                                           /* Disable Tx interrupts                    */
             stat = (INT8U)inp(COMM1_BASE + COMM_UART_IER) & ~BIT1;    
             outp(COMM1_BASE + COMM_UART_IER, stat);
             if (stat == 0x00) {                           /* Both Tx & Rx interrupts are disabled ?   */
                 cmd = (INT8U)inp(PIC_MSK_REG_PORT) | BIT4;
                 outp(PIC_MSK_REG_PORT, cmd);              /* Yes, disable IRQ4 on the PC              */
             }
             OS_EXIT_CRITICAL();
             break;

        case COMM2:
             OS_ENTER_CRITICAL();
                                                           /* Disable Tx interrupts                    */
             stat = (INT8U)inp(COMM2_BASE + COMM_UART_IER) & ~BIT1;    
             outp(COMM2_BASE + COMM_UART_IER, stat);
             if (stat == 0x00) {                           /* Both Tx & Rx interrupts are disabled ?   */
                 cmd = (INT8U)inp(PIC_MSK_REG_PORT) | BIT3;
                 outp(PIC_MSK_REG_PORT, cmd);              /* Yes, disable IRQ3 on the PC              */
             }
             OS_EXIT_CRITICAL();
             break;
    }
}
/*$PAGE*/
/*
*********************************************************************************************************
*                                          ENABLE TX INTERRUPTS
*
* Description : This function enables transmission of characters.  Transmission of characters is
*               interrupt driven.  If you are using a multi-drop driver, the code must enable the driver
*               for transmission.
* Arguments   : 'ch'    is the COMM port channel number and can either be:
*                           COMM1
*                           COMM2
*********************************************************************************************************
*/

void  CommTxIntEn (INT8U ch)
{
    INT8U  stat;
    INT8U  cmd;


    switch (ch) {
        case COMM1:
             OS_ENTER_CRITICAL();
             stat = (INT8U)inp(COMM1_BASE + COMM_UART_IER) | BIT1;     /* Enable Tx interrupts                     */
             outp(COMM1_BASE + COMM_UART_IER, stat);
             cmd  = (INT8U)inp(PIC_MSK_REG_PORT) & ~BIT4;
             outp(PIC_MSK_REG_PORT, cmd);                              /* Enable IRQ4 on the PC                    */
             OS_EXIT_CRITICAL();
             break;

        case COMM2:
             OS_ENTER_CRITICAL();
             stat = (INT8U)inp(COMM2_BASE + COMM_UART_IER) | BIT1;     /* Enable Tx interrupts                     */
             outp(COMM2_BASE + COMM_UART_IER, stat);
             cmd  = (INT8U)inp(PIC_MSK_REG_PORT) & ~BIT3;
             outp(PIC_MSK_REG_PORT, cmd);                              /* Enable IRQ3 on the PC                    */
             OS_EXIT_CRITICAL();
             break;
    }
}
