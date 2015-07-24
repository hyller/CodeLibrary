/*
*********************************************************************************************************
*                                  Embedded Systems Building Blocks
*                               Complete and Ready-to-Use Modules in C
*
*                                        Configuration Header File
*
*                            (c) Copyright 1999, Jean J. Labrosse, Weston, FL
*                                           All Rights Reserved
*
* Filename   : CFG.H
* Programmer : Jean J. Labrosse
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                          TEST TASK PRIORITIES
*********************************************************************************************************
*/
                                                 
#define  TEST_AIO_TASK_PRIO         10
#define  TEST_CLK_TASK_PRIO         11
#define  TEST_TX_TASK_PRIO          12
#define  TEST_RX_TASK_PRIO          13
#define  TEST_DIO_TASK_PRIO         14
#define  TEST_TMR_TASK_PRIO         15

#define  STAT_TASK_PRIO             16

/*
*********************************************************************************************************
*                                     KEYBOARD CONFIGURATION CONSTANTS
*                                               (Chapter 3)
*
* Note: These #defines would normally reside in your application specific code.
*********************************************************************************************************
*/

#if      MODULE_KEY_MN

#define  KEY_BUF_SIZE               10      /* Size of the KEYBOARD buffer                             */

#define  KEY_MAX_ROWS                4      /* The maximum number of rows    on the keyboard           */
#define  KEY_MAX_COLS                6      /* The maximum number of columns on the keyboard           */

#define  KEY_PORT_ROW           0x0312      /* The port address of the keyboard matrix ROWs            */
#define  KEY_PORT_COL           0x0311      /* The port address of the keyboard matrix COLUMNs         */
#define  KEY_PORT_CW            0x0313      /* The port address of the I/O ports control word          */

#define  KEY_RPT_DLY                20      /* Number of scan times before auto repeat executes again  */
#define  KEY_RPT_START_DLY         100      /* Number of scan times before auto repeat function engages*/

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

/*$PAGE*/
/*
*********************************************************************************************************
*                          MULTIPLEXED LED DISPLAY DRIVER CONFIGURATION CONSTANTS
*                                               (Chapter 4)
*********************************************************************************************************
*/

#if      MODULE_LED

#define  DISP_PORT_SEG          0x0300      /* Port address of SEGMENTS output                         */
#define  DISP_PORT_DIG          0x0301      /* Port address of DIGITS   output                         */

#define  DISP_N_DIG                  8      /* Total number of digits (including status indicators)    */
#define  DISP_N_SS                   7      /* Total number of seven-segment digits                    */

#endif

/*
*********************************************************************************************************
*                            LCD DISPLAY MODULE DRIVER CONFIGURATION CONSTANTS
*                                               (Chapter 5)
*********************************************************************************************************
*/

#if      MODULE_LCD

#define  DISP_DLY_CNTS             100      /* Number of iterations to delay for 40 uS (software loop) */

#define  DISP_PORT_DATA         0x0300      /* Port address of the DATA port of the LCD module         */
#define  DISP_PORT_CMD          0x0303      /* Address of the Control Word (82C55) to control RS & E   */

#endif

/*$PAGE*/
/*
*********************************************************************************************************
*                             CLOCK/CALENDAR MODULE CONFIGURATION CONSTANTS
*                                               (Chapter 6)
*********************************************************************************************************
*/

#if      MODULE_CLK

#define  CLK_TASK_PRIO              51      /* This defines the priority of ClkTask()                  */
#define  CLK_DLY_TICKS     OS_TICKS_PER_SEC /* # of clock ticks to obtain 1 second                     */
#define  CLK_TASK_STK_SIZE         512      /* Stack size in BYTEs for ClkTask()                       */

#define  CLK_DATE_EN                 1      /* Enable DATE (when 1)                                    */
#define  CLK_TS_EN                   1      /* Enable TIME-STAMPS (when 1)                             */
#define  CLK_USE_DLY                 1      /* Task will use OSTimeDly() instead of pend on sem.       */

#endif

/*
*********************************************************************************************************
*                                             TIMER MANAGER
*                                              (Chapter 7)
*********************************************************************************************************
*/

#if      MODULE_TMR

#define  TMR_TASK_PRIO              52
#define  TMR_DLY_TICKS            (OS_TICKS_PER_SEC / 10)
#define  TMR_TASK_STK_SIZE         512

#define  TMR_MAX_TMR                20

#define  TMR_USE_SEM                 0

#endif

/*$PAGE*/
/*
*********************************************************************************************************
*                               DISCRETE I/O MODULE CONFIGURATION CONSTANTS
*                                              (Chapter 8)
*********************************************************************************************************
*/

#if      MODULE_DIO

#define  DIO_TASK_PRIO              53
#define  DIO_TASK_DLY_TICKS        (OS_TICKS_PER_SEC / 10)
#define  DIO_TASK_STK_SIZE         512

#define  DIO_MAX_DI                  8      /* Maximum number of Discrete Input  Channels (1..255)     */
#define  DIO_MAX_DO                  8      /* Maximum number of Discrete Output Channels (1..255)     */

#define  DI_EDGE_EN                  1      /* Enable code generation to support edge trig. (when 1)   */

#define  DO_BLINK_MODE_EN            1      /* Enable code generation to support blink mode (when 1)   */

#endif

/*
*********************************************************************************************************
*                                ANALOG I/O MODULE CONFIGURATION CONSTANTS
*                                               (Chapter 10)
*********************************************************************************************************
*/

#if      MODULE_AIO

#define  AIO_TASK_PRIO              54
#define  AIO_TASK_DLY              100      /* Task execution period in milliseconds                   */
#define  AIO_TASK_STK_SIZE         512

#define  AIO_MAX_AI                  8      /* Maximum number of Analog Input  Channels (1..250)       */
#define  AIO_MAX_AO                  8      /* Maximum number of Analog Output Channels (1..250)       */

#endif

/*$PAGE*/
/*
*********************************************************************************************************
*                ASYNCHRONOUS SERIAL COMMUNICATIONS MODULE CONFIGURATION CONSTANTS
*                                            (Chapter 11)
*********************************************************************************************************
*/

#if      MODULE_COMM_PC

#define  COMM1_BASE        0x03F8           /* Base address of PC's COM1                               */
#define  COMM2_BASE        0x02F8           /* Base address of PC's COM2                               */

#define  COMM_MAX_RX            2           /* Maximum number of characters in Rx buffer of ...        */
                                            /* ... NS16450 UART.  2 for 16450, 16 for 16550.           */
#endif


#if      MODULE_COMM_BGND

#define  COMM1                  1
#define  COMM2                  2

#define  COMM_RX_BUF_SIZE      64           /* Number of characters in Rx ring buffer                  */
#define  COMM_TX_BUF_SIZE      64           /* Number of characters in Tx ring buffer                  */

#endif


#if      MODULE_COMM_RTOS

#define  COMM1                  1
#define  COMM2                  2

#define  COMM_RX_BUF_SIZE      64           /* Number of characters in Rx ring buffer                  */
#define  COMM_TX_BUF_SIZE      64           /* Number of characters in Tx ring buffer                  */

#endif
