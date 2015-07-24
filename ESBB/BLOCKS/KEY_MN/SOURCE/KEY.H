/*
*********************************************************************************************************
*                                   Embedded Systems Building Blocks
*                                Complete and Ready-to-Use Modules in C
*
*                                         Matrix Keyboard Driver
*
*                            (c) Copyright 1999, Jean J. Labrosse, Weston, FL
*                                           All Rights Reserved
*
* Filename   : KEY.H
* Programmer : Jean J. Labrosse
*********************************************************************************************************
*                                          USER DEFINED CONSTANTS
*
* Note: These #defines would normally reside in your application specific code.
*********************************************************************************************************
*/

#ifndef  CFG_H
#define  KEY_BUF_SIZE               10      /* Size of the KEYBOARD buffer                             */

#define  KEY_PORT_ROW           0x0312      /* The port address of the keyboard matrix ROWs            */
#define  KEY_PORT_COL           0x0311      /* The port address of the keyboard matrix COLUMNs         */
#define  KEY_PORT_CW            0x0313      /* The port address of the I/O ports control word          */

#define  KEY_MAX_ROWS                4      /* The maximum number of rows    on the keyboard           */
#define  KEY_MAX_COLS                6      /* The maximum number of columns on the keyboard           */

#define  KEY_RPT_DLY                 2      /* Number of scan times before auto repeat executes again  */
#define  KEY_RPT_START_DLY          10      /* Number of scan times before auto repeat function engages*/

#define  KEY_SCAN_TASK_DLY          50      /* Number of milliseconds between keyboard scans           */
#define  KEY_SCAN_TASK_PRIO         50      /* Set priority of keyboard scan task                      */
#define  KEY_SCAN_TASK_STK_SIZE   1024      /* Size of keyboard scan task stack                        */

#define  KEY_SHIFT1_MSK           0x80      /* The SHIFT1 key is on bit B7 of the column input port    */
                                            /*     (A 0x00 indicates that a SHIFT1 key is not present) */
#define  KEY_SHIFT1_OFFSET          24      /* The scan code offset to add when SHIFT1 is pressed      */

#define  KEY_SHIFT2_MSK           0x40      /* The SHIFT2 key is on bit B6 of the column input port    */
                                            /*     (A 0x00 indicates that an SHIFT2 key is not present)*/
#define  KEY_SHIFT2_OFFSET          48      /* The scan code offset to add when SHIFT2 is pressed      */

#define  KEY_SHIFT3_MSK           0x00      /* The SHIFT3 key is on bit B5 of the column input port    */
                                            /*     (A 0x00 indicates that a SHIFT3 key is not present) */
#define  KEY_SHIFT3_OFFSET           0      /* The scan code offset to add when SHIFT3 is pressed      */
#endif


#define  KEY_ALL_ROWS             0xFF      /* Select all rows (i.e. all rows LOW)                     */

/*
*********************************************************************************************************
*                                           FUNCTION PROTOTYPES
*********************************************************************************************************
*/

void    KeyFlush(void);                /* Flush the keyboard buffer                                    */
INT8U   KeyGetKey(INT16U to);          /* Get a key scan code from driver if one is present, -1 else   */
INT32U  KeyGetKeyDownTime(void);       /* Get how long key has been pressed (in milliseconds)          */
BOOLEAN KeyHit(void);                  /* See if a key has been pressed (TRUE if so, FALSE if not)     */
void    KeyInit(void);                 /* Initialize the keyboard handler                              */


void    KeyInitPort(void);             /* Initialize I/O ports                                         */
INT8U   KeyGetCol(void);               /* Read COLUMNs                                                 */
void    KeySelRow(INT8U row);          /* Select a ROW                                                 */
