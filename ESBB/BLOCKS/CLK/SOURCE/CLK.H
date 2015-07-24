/*
*********************************************************************************************************
*                                             Clock/Calendar
*
*                            (c) Copyright 1999, Jean J. Labrosse, Weston, FL
*                                           All Rights Reserved
*
* Filename   : CLK.H
* Programmer : Jean J. Labrosse
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                               CONSTANTS
*********************************************************************************************************
*/

#ifndef  CFG_H

#define  CLK_DLY_TICKS       OS_TICKS_PER_SEC    /* # of clock ticks to obtain 1 second                */
#define  CLK_TASK_PRIO        50                 /* This defines the priority of ClkTask()             */
#define  CLK_TASK_STK_SIZE   512                 /* Stack size in BYTEs for ClkTask()                  */

#define  CLK_DATE_EN           1                 /* Enable DATE (when 1)                               */
#define  CLK_TS_EN             1                 /* Enable TIME-STAMPS (when 1)                        */
#define  CLK_USE_DLY           1                 /* Task will use OSTimeDly() instead of pend on sem.  */

#endif

#ifdef   CLK_GLOBALS
#define  CLK_EXT
#else
#define  CLK_EXT  extern
#endif

/*
*********************************************************************************************************
*                                               DATA TYPES
*********************************************************************************************************
*/

typedef  INT32U  TS;                   /* Definition of Time Stamp                                     */


#if CLK_DATE_EN
typedef struct clk_month {             /* MONTH RELATED VARIABLES                                      */
    INT8U  MonthDays;                  /* Number of days in each month                                 */
    char  *MonthName;                  /* Name of the month                                            */
    INT8U  MonthVal;                   /* Value used to compute day of the week                        */
} CLK_MONTH;
#endif

/*
*********************************************************************************************************
*                                            GLOBAL VARIABLES
*********************************************************************************************************
*/

CLK_EXT  INT8U   ClkHr;
CLK_EXT  INT8U   ClkMin;
CLK_EXT  INT8U   ClkSec;               /* Counters for local TIME                                      */

#if      CLK_DATE_EN
CLK_EXT  INT8U   ClkDay;               /* Counters for local DATE                                      */
CLK_EXT  INT8U   ClkDOW;               /* Day of week (0 is Sunday)                                    */
CLK_EXT  INT8U   ClkMonth;
CLK_EXT  INT16U  ClkYear;
#endif

#if      CLK_TS_EN
CLK_EXT  TS      ClkTS;                /* Current TIME-STAMP                                           */
#endif

/*
*********************************************************************************************************
*                                          FUNCTION PROTOTYPES
*********************************************************************************************************
*/

void   ClkInit(void);

void   ClkFormatTime(INT8U n, char *s);
void   ClkSetTime(INT8U hr, INT8U min, INT8U sec);

void   ClkSignalClk(void);

#if    CLK_DATE_EN
void   ClkFormatDate(INT8U n, char *s);
void   ClkSetDate(INT8U month, INT8U day, INT16U year);
void   ClkSetDateTime(INT8U month, INT8U day, INT16U year, INT8U hr, INT8U min, INT8U sec);
#endif

#if    CLK_TS_EN
TS     ClkGetTS(void);
TS     ClkMakeTS(INT8U month, INT8U day, INT16U year, INT8U hr, INT8U min, INT8U sec);
void   ClkFormatTS(INT8U n, TS ts, char *s);
#endif
