/*
*********************************************************************************************************
*                                  Embedded Systems Building Blocks
*                               Complete and Ready-to-Use Modules in C
*
*                                           Configuration File
*
*                            (c) Copyright 1999, Jean J. Labrosse, Weston, FL
*                                           All Rights Reserved
*
* Filename   : CFG.C
* Programmer : Jean J. Labrosse
*********************************************************************************************************
*/

#include "includes.h"

static  INT16S  AITestCnts;

/*$PAGE*/
/*
*********************************************************************************************************
*                                              KEYBOARD
*                                         INITIALIZE I/O PORTS
*********************************************************************************************************
*/

#if  MODULE_KEY_MN
void  KeyInitPort (void)
{
    outp(KEY_PORT_CW, 0x82);                    /* Initialize 82C55A: A=OUT, B=IN (COLS), C=OUT (ROWS) */
}

/*
*********************************************************************************************************
*                                              KEYBOARD
*                                            SELECT A ROW
*
* Description : This function is called to select a row on the keyboard.
* Arguments   : 'row'  is the row number (0..7) or KEY_ALL_ROWS
* Returns     : none
* Note        : The row is selected by writing a LOW.
*********************************************************************************************************
*/

void  KeySelRow (INT8U row)
{
    if (row == KEY_ALL_ROWS) {
        outp(KEY_PORT_ROW, 0x00);                /* Force all rows LOW                                 */
    } else {
        outp(KEY_PORT_ROW, ~(1 << row));         /* Force desired row LOW                              */
    }
}

/*
*********************************************************************************************************
*                                              KEYBOARD
*                                            READ COLUMNS
*
* Description : This function is called to read the column port.
* Arguments   : none
* Returns     : the complement of the column port thus, ones are keys pressed
*********************************************************************************************************
*/

INT8U  KeyGetCol (void)
{
    return (~inp(KEY_PORT_COL));                 /* Complement columns (ones indicate key is pressed)  */
}
#endif

/*$PAGE*/
/*
*********************************************************************************************************
*                                        MULTIPLEXED LED DISPLAY
*                                        I/O PORTS INITIALIZATION
*
* Description: This is called by DispInit() to initialize the output ports used in the LED multiplexing.
* Arguments  : none
* Returns    : none
* Notes      : 74HC573  8 bit latches are used for both the segments and digits outputs.
*********************************************************************************************************
*/

#if  MODULE_LED
void  DispInitPort (void)
{
    outp(DISP_PORT_SEG, 0x00);              /* Turn OFF segments                                       */
    outp(DISP_PORT_DIG, 0x00);              /* Turn OFF digits                                         */
}

/*
*********************************************************************************************************
*                                       MULTIPLEXED LED DISPLAY
*                                           SEGMENTS output
*
* Description: This function outputs seven-segment patterns.
* Arguments  : seg    is the seven-segment patterns to output
* Returns    : none
*********************************************************************************************************
*/

void  DispOutSeg (INT8U seg)
{
    outp(DISP_PORT_SEG, seg);
}

/*
*********************************************************************************************************
*                                        MULTIPLEXED LED DISPLAY
*                                             DIGIT output
*
* Description: This function outputs the digit selector.
* Arguments  : msk    is the mask used to select the current digit.
* Returns    : none
*********************************************************************************************************
*/

void  DispOutDig (INT8U msk)
{
    outp(DISP_PORT_DIG, msk);
}
#endif

/*$PAGE*/
/*
*********************************************************************************************************
*                                           LCD DISPLAY MODULE
*                                   INITIALIZE DISPLAY DRIVER I/O PORTS
*
* Description : This initializes the I/O ports used by the display driver.
* Arguments   : none
* Returns     : none
*********************************************************************************************************
*/

#if  MODULE_LCD
void  DispInitPort (void)
{
    outp(DISP_PORT_CMD, 0x82);         /* Set to Mode 0: A are output, B are inputs, C are outputs     */
}

/*
*********************************************************************************************************
*                                           LCD DISPLAY MODULE
*                                       WRITE DATA TO DISPLAY DEVICE
*
* Description : This function sends a single BYTE to the display device.
* Arguments   : 'data'  is the BYTE to send to the display device
* Returns     : none
* Notes       : You will need to adjust the value of DISP_DLY_CNTS (LCD.H) to produce a delay between
*               writes of at least 40 uS.  The display I used for the test actually required a delay of
*               80 uS!  If characters seem to appear randomly on the screen, you might want to increase
*               the value of DISP_DLY_CNTS.
*********************************************************************************************************
*/
void  DispDataWr (INT8U data)
{
    INT8U  dly;


    outp(DISP_PORT_DATA, data);                  /* Write data to display module                       */
    outp(DISP_PORT_CMD,  0x01);                  /* Set E   line HIGH                                  */
    DispDummy();                                 /* Delay about 1 uS                                   */
    outp(DISP_PORT_CMD,  0x00);                  /* Set E   line LOW                                   */
    for (dly = DISP_DLY_CNTS; dly > 0; dly--) {  /* Delay for at least 40 uS                           */
        DispDummy();
    }
}

/*
*********************************************************************************************************
*                                          LCD DISPLAY MODULE
*                                    SELECT COMMAND OR DATA REGISTER
*
* Description : This function read a BYTE from the display device.
* Arguments   : none
*********************************************************************************************************
*/
void  DispSel (INT8U sel)
{
    if (sel == DISP_SEL_CMD_REG) {
        outp(DISP_PORT_CMD, 0x02);     /* Select the command register (RS low)                         */
    } else {
        outp(DISP_PORT_CMD, 0x03);     /* Select the data    register (RS high)                        */
    }
}
#endif

/*$PAGE*/
/*
*********************************************************************************************************
*                                        CLOCK/CALENDAR MODULE
*********************************************************************************************************
*/

#if MODULE_CLK
#endif

/*
*********************************************************************************************************
*                                             TIMER MANAGER
*********************************************************************************************************
*/

#if MODULE_TMR
#endif

/*$PAGE*/
/*
*********************************************************************************************************
*                                          DISCRETE I/O MODULE
*                                        INITIALIZE PHYSICAL I/Os
*
* Description : This function is by DIOInit() to initialze the physical I/O used by the DIO driver.
* Arguments   : None.
* Returns     : None.
* Notes       : The physical I/O is assumed to be an 82C55A chip initialized as follows:
*                   Port A = OUT  (Discrete outputs)   (Address 0x0300)
*                   Port B = IN   (Discrete inputs)    (Address 0x0301)
*                   Port C = OUT  (not used)           (Address 0x0302)
*                   Control Word                       (Address 0x0303)
*               Refer to the Intel 82C55A data sheet.
*********************************************************************************************************
*/

#if  MODULE_DIO
void  DIOInitIO (void)
{
    outp(0x0303, 0x82);                          /* Port A = OUT, Port B = IN, Port C = OUT            */
}

/*
*********************************************************************************************************
*                                           DISCRETE I/O MODULE
*                                           READ PHYSICAL INPUTS
*
* Description : This function is called to read and map all of the physical inputs used for discrete
*               inputs and map these inputs to their appropriate discrete input data structure.
* Arguments   : None.
* Returns     : None.
*********************************************************************************************************
*/

void  DIRd (void)
{
    DIO_DI *pdi;
    INT8U   i;
    INT8U   in;
    INT8U   msk;


    pdi = &DITbl[0];                                       /* Point at beginning of discrete inputs    */
    msk = 0x01;                                            /* Set mask to extract bit 0                */
    in  = inp(0x0301);                                     /* Read the physical port (8 bits)          */
    for (i = 0; i < 8; i++) {                              /* Map all 8 bits to first 8 DI channels    */
        pdi->DIIn   = (BOOLEAN)(in & msk) ? 1 : 0;
        msk       <<= 1;
        pdi++;
    }
}

/*
*********************************************************************************************************
*                                           DISCRETE I/O MODULE
*                                         UPDATE PHYSICAL OUTPUTS
*
* Description : This function is called to map all of the discrete output channels to their appropriate
*               physical destinations.
* Arguments   : None.
* Returns     : None.
*********************************************************************************************************
*/

void  DOWr (void)
{
    DIO_DO *pdo;
    INT8U   i;
    INT8U   out;
    INT8U   msk;


    pdo = &DOTbl[0];                        /* Point at first discrete output channel                  */
    msk = 0x01;                             /* First DO will be mapped to bit 0                        */
    out = 0x00;                             /* Local 8 bit port image                                  */
    for (i = 0; i < 8; i++) {               /* Map first 8 DOs to 8 bit port image                     */
        if (pdo->DOOut == TRUE) {
            out |= msk;
        }
        msk <<= 1;
        pdo++;
    }
    outp(0x0300, out);                      /* Output port image to physical port                      */
}
#endif

/*$PAGE*/
/*
*********************************************************************************************************
*                                          ANALOG I/O MODULE
*                                       INITIALIZE PHYSICAL I/Os
*
* Description : This function is called by AIOInit() to initialize the physical I/O used by the AIO
*               driver.
* Arguments   : None.
* Returns     : None.
*********************************************************************************************************
*/

#if  MODULE_AIO
void  AIOInitIO (void)
{
    /* This is where you will need to put you initialization code for the ADCs and DACs                */
    /* You should also consider initializing the contents of your DAC(s) to a known value.             */
    
    AITestCnts = 0;
}

/*
*********************************************************************************************************
*                                           ANALOG I/O MODULE
*                                          READ PHYSICAL INPUTS
*
* Description : This function is called to read a physical ADC channel.  The function is assumed to
*               also control a multiplexer if more than one analog input is connected to the ADC.
* Arguments   : ch     is the ADC logical channel number (0..AIO_MAX_AI-1).
* Returns     : The raw ADC counts from the physical device.
*********************************************************************************************************
*/

INT16S  AIRd (INT8U ch)
{
    /* This is where you will need to provide the code to read your ADC(s).                            */
    /* AIRd() is passed a 'LOGICAL' channel number.  You will have to convert this logical channel     */
    /* number into actual physical port locations (or addresses) where your MUX. and ADCs are located. */
    /* AIRd() is responsible for:                                                                      */
    /*     1) Selecting the proper MUX. channel,                                                       */
    /*     2) Waiting for the MUX. to stabilize,                                                       */
    /*     3) Starting the ADC,                                                                        */
    /*     4) Waiting for the ADC to complete its conversion,                                          */
    /*     5) Reading the counts from the ADC and,                                                     */
    /*     6) Returning the counts to the calling function.                                            */

                                       /* Simulate a RAMPING voltage                                   */
    AITestCnts += 10;                  /* Always assume ADC returns a signed 16-bit count              */
    if (AITestCnts > 28670) {          /* Max. counts for LM34A at 300 F, with gain of 2.5             */
        AITestCnts = 0;
    }
    return (AITestCnts);
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                           ANALOG I/O MODULE
*                                        UPDATE PHYSICAL OUTPUTS
*
* Description : This function is called to write the 'raw' counts to the proper analog output device
*               (i.e. DAC).  It is up to this function to direct the DAC counts to the proper DAC if more
*               than one DAC is used.
* Arguments   : ch     is  the DAC logical channel number (0..AIO_MAX_AO-1).
*               cnts   are the DAC counts to write to the DAC
* Returns     : None.
*********************************************************************************************************
*/

void  AOWr (INT8U ch, INT16S cnts)
{
    ch   = ch;
    cnts = cnts;

    /* This is where you will need to provide the code to update your DAC(s).                          */
    /* AOWr() is passed a 'LOGICAL' channel number.  You will have to convert this logical channel     */
    /* number into actual physical port locations (or addresses) where your DACs are located.          */
    /* AOWr() is responsible for writing the counts to the selected DAC based on a logical number.     */
}
#endif
