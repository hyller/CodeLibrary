/*
*********************************************************************************************************
*                                     Embedded Systems Building Blocks
*                                  Complete and Ready-to-Use Modules in C
*
*                                    Asynchronous Serial Communications
*                                           Buffered Serial I/O 
*                                                 (RTOS)
*
*                            (c) Copyright 1999, Jean J. Labrosse, Weston, FL
*                                           All Rights Reserved
*
* Filename   : COMMRTOS.H
* Programmer : Jean J. Labrosse
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                       CONFIGURATION CONSTANTS
*********************************************************************************************************
*/

#ifndef  CFG_H

#define  COMM_RX_BUF_SIZE      64                /* Number of characters in Rx ring buffer             */
#define  COMM_TX_BUF_SIZE      64                /* Number of characters in Tx ring buffer             */

#endif

/*
*********************************************************************************************************
*                                               CONSTANTS
*********************************************************************************************************
*/

#ifndef  NUL
#define  NUL                 0x00
#endif

#define  COMM1                  1
#define  COMM2                  2

                                                 /* ERROR CODES                                        */
#define  COMM_NO_ERR            0                /* Function call was successful                       */
#define  COMM_BAD_CH            1                /* Invalid communications port channel                */
#define  COMM_RX_EMPTY          2                /* Rx buffer is empty, no character available         */
#define  COMM_TX_FULL           3                /* Tx buffer is full, could not deposit character     */
#define  COMM_TX_EMPTY          4                /* If the Tx buffer is empty.                         */
#define  COMM_RX_TIMEOUT        5                /* If a timeout occurred while waiting for a character*/
#define  COMM_TX_TIMEOUT        6                /* If a timeout occurred while waiting to send a char.*/


#define  COMM_PARITY_NONE       0                /* Defines for setting parity                         */
#define  COMM_PARITY_ODD        1
#define  COMM_PARITY_EVEN       2


#ifdef   COMM_GLOBALS
#define  COMM_EXT
#else
#define  COMM_EXT  extern
#endif
/*$PAGE*/
/*
*********************************************************************************************************
*                                          FUNCTION PROTOTYPES
*********************************************************************************************************
*/

INT8U    CommGetChar(INT8U ch, INT16U to, INT8U *err);
INT8U    CommGetTxChar(INT8U ch, INT8U *err);
void     CommInit(void);
BOOLEAN  CommIsEmpty(INT8U ch);
BOOLEAN  CommIsFull(INT8U ch);
INT8U    CommPutChar(INT8U ch, INT8U c, INT16U to);
void     CommPutRxChar(INT8U ch, INT8U c);
