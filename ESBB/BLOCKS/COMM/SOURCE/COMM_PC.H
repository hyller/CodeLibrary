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
* Filename   : COMM_PC.H
* Programmer : Jean J. Labrosse
*
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                       CONFIGURATION CONSTANTS
*********************************************************************************************************
*/

#ifndef  CFG_H

#define  COMM1_BASE        0x03F8                /* Base address of PC's COM1                          */
#define  COMM2_BASE        0x02F8                /* Base address of PC's COM2                          */

#define  COMM_MAX_RX            2                /* NS16450 has 2 byte buffer                          */

#endif

/*
*********************************************************************************************************
*                                          FUNCTION PROTOTYPES
*********************************************************************************************************
*/

void     Comm1ISR(void);
void     Comm2ISR(void);
INT8U    CommCfgPort(INT8U ch, INT16U baud, INT8U bits, INT8U parity, INT8U stops);
void     CommISRHandler(INT8U ch);
void     CommRxFlush(INT8U ch);
void     CommRxIntDis(INT8U ch);
void     CommRxIntEn(INT8U ch);
void     CommTxIntDis(INT8U ch);
void     CommTxIntEn(INT8U ch);
void     CommRclIntVect(INT8U ch);
void     CommSetIntVect(INT8U ch);
