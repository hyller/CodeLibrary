/*
*********************************************************************************************************
*                                    Embedded Systems Building Blocks
*                                 Complete and Ready-to-Use Modules in C
*
*                                     Multiplexed LED Display Driver
*
*                            (c) Copyright 1999, Jean J. Labrosse, Weston, FL
*                                           All Rights Reserved
*
* Filename   : LED.H
* Programmer : Jean J. Labrosse
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                               CONSTANTS
*********************************************************************************************************
*/

#ifndef  CFG_H
#define  DISP_PORT_DIG   0x0301             /* Port address of DIGITS   output                         */
#define  DISP_PORT_SEG   0x0300             /* Port address of SEGMENTS output                         */

#define  DISP_N_DIG           8             /* Total number of digits (including status indicators)    */
#define  DISP_N_SS            7             /* Total number of seven-segment digits                    */
#endif

/*
*********************************************************************************************************
*                                          FUNCTION PROTOTYPES
*********************************************************************************************************
*/

void  DispClrScr(void);
void  DispInit(void);
void  DispMuxHandler(void);
void  DispMuxISR(void);
void  DispStr(INT8U dig, char *s);
void  DispStatClr(INT8U dig, INT8U bit);
void  DispStatSet(INT8U dig, INT8U bit);

/*
*********************************************************************************************************
*                                          FUNCTION PROTOTYPES
*                                           HARDWARE SPECIFIC
*********************************************************************************************************
*/

void  DispInitPort(void);
void  DispOutDig(INT8U msk);
void  DispOutSeg(INT8U seg);
