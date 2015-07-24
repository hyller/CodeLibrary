/*
*********************************************************************************************************
*                                             Clock/Calendar
*
*                            (c) Copyright 1999, Jean J. Labrosse, Weston, FL
*                                           All Rights Reserved
*
* Filename   : CLK.C
* Programmer : Jean J. Labrosse
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                              INCLUDE FILES
*********************************************************************************************************
*/

#define  CLK_GLOBALS                   /* CLK.H is informed to allocate storage for globals            */
#include "includes.h"

/*
*********************************************************************************************************
*                                            LOCAL CONSTANTS
*********************************************************************************************************
*/

#define  CLK_TS_BASE_YEAR    2000      /* Time stamps start year                                       */

/*
*********************************************************************************************************
*                                            LOCAL VARIABLES
*********************************************************************************************************
*/

static  OS_EVENT   *ClkSem;            /* Semaphore used to access the time of day clock               */
static  OS_EVENT   *ClkSemSec;         /* Counting semaphore used to keep track of seconds             */

static  OS_STK      ClkTaskStk[CLK_TASK_STK_SIZE];

static  INT8U       ClkTickCtr;        /* Counter used to keep track of system clock ticks             */


/*$PAGE*/
/*
*********************************************************************************************************
*                                              LOCAL TABLES
*********************************************************************************************************
*/

#if CLK_DATE_EN
static  char *ClkDOWTbl[] = {          /* NAME FOR EACH DAY OF THE WEEK                                */
    "Sunday ",
    "Monday ",
    "Tuesday ",
    "Wednesday ",
    "Thursday ",
    "Friday ",
    "Saturday "
};


static  CLK_MONTH ClkMonthTbl[] = {    /* MONTHS TABLE                                                 */
    {0,  "",           0},             /* Invalid month                                                */
    {31, "January ",   6},             /* January                                                      */
    {28, "February ",  2},             /* February (note leap years are handled by code)               */
    {31, "March ",     2},             /* March                                                        */
    {30, "April ",     5},             /* April                                                        */
    {31, "May ",       0},             /* May                                                          */
    {30, "June ",      3},             /* June                                                         */
    {31, "July ",      5},             /* July                                                         */
    {31, "August ",    1},             /* August                                                       */
    {30, "September ", 4},             /* September                                                    */
    {31, "October ",   6},             /* October                                                      */
    {30, "November ",  2},             /* November                                                     */
    {31, "December ",  4}              /* December                                                     */
};
#endif

/*
*********************************************************************************************************
*                                        LOCAL FUNCTION PROTOTYPES
*********************************************************************************************************
*/

        void          ClkTask(void *data);
static  BOOLEAN       ClkUpdateTime(void);

#if     CLK_DATE_EN
static  BOOLEAN       ClkIsLeapYear(INT16U year);
static  void          ClkUpdateDate(void);
static  void          ClkUpdateDOW(void);
#endif

/*$PAGE*/
/*
*********************************************************************************************************
*                                    FORMAT CURRENT DATE INTO STRING
*
* Description : Formats the current date into an ASCII string.
* Arguments   : n      is the format type:
*                      1   will format the time as "MM-DD-YY"           (needs at least  9 characters)
*                      2   will format the time as "Day Month DD, YYYY" (needs at least 30 characters)
*                      3   will format the time as "YYYY-MM-DD"         (needs at least 11 characters)
*               s      is a pointer to the destination string.  The destination string must be large
*                      enough to hold the formatted date.
*                      contain
* Returns     : None.
* Notes       : - A 'switch' statement has been used to allow you to add your own date formats.  For
*                 example, you could display the date in French, Spanish, German etc. by assigning
*                 numbers for those types of conversions.
*               - This function assumes that strcpy(), strcat() and itoa() are reentrant.
*********************************************************************************************************
*/

#if  CLK_DATE_EN
void  ClkFormatDate (INT8U n, char *s)
{
    INT8U   err;
    INT16U  year;
    char    str[5];


    OSSemPend(ClkSem, 0, &err);                  /* Gain exclusive access to time-of-day clock         */
    switch (n) {
        case  1:
              strcpy(s, "MM-DD-YY");             /* Create the template for the selected format        */
              s[0] = ClkMonth / 10 + '0';        /* Convert DATE to ASCII                              */
              s[1] = ClkMonth % 10 + '0';
              s[3] = ClkDay   / 10 + '0';
              s[4] = ClkDay   % 10 + '0';
              year = ClkYear % 100;
              s[6] = year / 10 + '0';
              s[7] = year % 10 + '0';
              break;

        case  2:
              strcpy(s, ClkDOWTbl[ClkDOW]);                  /* Get the day of the week                */
              strcat(s, ClkMonthTbl[ClkMonth].MonthName);    /* Get name of month                      */
              if (ClkDay < 10) {
                 str[0] = ClkDay + '0';
                 str[1] = 0;
              } else {
                 str[0] = ClkDay / 10 + '0';
                 str[1] = ClkDay % 10 + '0';
                 str[2] = 0;
              }
              strcat(s, str);
              strcat(s, ", ");
              itoa(ClkYear, str, 10);
              strcat(s, str);
              break;

        case  3:
              strcpy(s, "YYYY-MM-DD");           /* Create the template for the selected format        */
              s[0] = year / 1000 + '0';
              year = year % 1000;
              s[1] = year /  100 + '0';
              year = year %  100;
              s[2] = year /   10 + '0';
              s[3] = year %   10 + '0';
              s[5] = ClkMonth / 10 + '0';        /* Convert DATE to ASCII                              */
              s[6] = ClkMonth % 10 + '0';
              s[8] = ClkDay   / 10 + '0';
              s[9] = ClkDay   % 10 + '0';
              break;

        default:
              strcpy(s, "?");
              break;
    }
    OSSemPost(ClkSem);                           /* Release access to clock                            */
}
#endif

/*$PAGE*/
/*
*********************************************************************************************************
*                                    FORMAT CURRENT TIME INTO STRING
*
* Description : Formats the current time into an ASCII string.
* Arguments   : n      is the format type:
*                      1   will format the time as "HH:MM:SS"     (24 Hour format)
*                                                                 (needs at least  9 characters)
*                      2   will format the time as "HH:MM:SS AM"  (With AM/PM indication)
*                                                                 (needs at least 13 characters)
*               s      is a pointer to the destination string.  The destination string must be large
*                      enough to hold the formatted time.
*                      contain
* Returns     : None.
* Notes       : - A 'switch' statement has been used to allow you to add your own time formats.
*               - This function assumes that strcpy() is reentrant.
*********************************************************************************************************
*/

void  ClkFormatTime (INT8U n, char *s)
{
    INT8U err;
    INT8U hr;


    OSSemPend(ClkSem, 0, &err);                       /* Gain exclusive access to time-of-day clock    */
    switch (n) {
        case  1:
              strcpy(s, "HH:MM:SS");                  /* Create the template for the selected format   */
              s[0] = ClkHr  / 10 + '0';               /* Convert TIME to ASCII                         */
              s[1] = ClkHr  % 10 + '0';
              s[3] = ClkMin / 10 + '0';
              s[4] = ClkMin % 10 + '0';
              s[6] = ClkSec / 10 + '0';
              s[7] = ClkSec % 10 + '0';
              break;

        case  2:
              strcpy(s, "HH:MM:SS AM");               /* Create the template for the selected format   */
              s[9] = (ClkHr >= 12) ? 'P' : 'A';       /* Set AM or PM indicator                        */
              if (ClkHr > 12) {                       /* Adjust time to be displayed                   */
                  hr   = ClkHr - 12;
              } else {
                  hr = ClkHr;
              }
              s[0] = hr     / 10 + '0';               /* Convert TIME to ASCII                         */
              s[1] = hr     % 10 + '0';
              s[3] = ClkMin / 10 + '0';
              s[4] = ClkMin % 10 + '0';
              s[6] = ClkSec / 10 + '0';
              s[7] = ClkSec % 10 + '0';
              break;

        default:
              strcpy(s, "?");
              break;
    }
    OSSemPost(ClkSem);                                /* Release access to time-of-day clock           */
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                         FORMAT TIME-STAMP
*
* Description : This function converts a time-stamp to an ASCII string.
* Arguments   : n         is the desired format number:
*                            1 : "MM-DD-YY HH:MM:SS"         (needs at least 18 characters)
*                            2 : "YYYY-MM-DD HH:MM:SS"       (needs at least 20 characters)
*               ts        is the time-stamp value to format
*               s         is the destination ASCII string
* Returns     : none
* Notes       : - The time stamp is a 32 bit unsigned integer as follows:
*
*        Field: -------Year------ ---Month--- ------Day----- ----Hours----- ---Minutes--- --Seconds--
*        Bit# : 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
*
*               - The year is based from CLK_TS_BASE_YEAR.  That is, if bits 31..26 contain 0 it really 
*                 means that the year is really CLK_TS_BASE_YEAR.  If bits 31..26 contain 13, the year 
*                 is CLK_TS_BASE_YEAR + 13.
*********************************************************************************************************
*/

#if CLK_TS_EN && CLK_DATE_EN
void  ClkFormatTS (INT8U n, TS ts, char *s)
{
    INT16U yr;
    INT8U month;
    INT8U day;
    INT8U hr;
    INT8U min;
    INT8U sec;


    yr    = CLK_TS_BASE_YEAR + (ts >> 26);       /* Unpack time-stamp                                  */
    month = (ts >> 22) & 0x0F;
    day   = (ts >> 17) & 0x1F;
    hr    = (ts >> 12) & 0x1F;
    min   = (ts >>  6) & 0x3F;
    sec   = (ts & 0x3F);
    switch (n) {
        case  1:
              strcpy(s, "MM-DD-YY HH:MM:SS");    /* Create the template for the selected format        */
              yr    = yr % 100;
              s[ 0] = month / 10 + '0';          /* Convert DATE to ASCII                              */
              s[ 1] = month % 10 + '0';
              s[ 3] = day   / 10 + '0';
              s[ 4] = day   % 10 + '0';
              s[ 6] = yr    / 10 + '0';
              s[ 7] = yr    % 10 + '0';
              s[ 9] = hr    / 10 + '0';           /* Convert TIME to ASCII                             */
              s[10] = hr    % 10 + '0';
              s[12] = min   / 10 + '0';
              s[13] = min   % 10 + '0';
              s[15] = sec   / 10 + '0';
              s[16] = sec   % 10 + '0';
              break;

        case  2:
              strcpy(s, "YYYY-MM-DD HH:MM:SS");  /* Create the template for the selected format        */
              s[ 0] = yr    / 1000 + '0';        /* Convert DATE to ASCII                              */
              yr    = yr % 1000;
              s[ 1] = yr    /  100 + '0';
              yr    = yr %  100;
              s[ 2] = yr    /   10 + '0';
              s[ 3] = yr    %   10 + '0';
              s[ 5] = month / 10 + '0';          
              s[ 6] = month % 10 + '0';
              s[ 8] = day   / 10 + '0';
              s[ 9] = day   % 10 + '0';
              s[11] = hr    / 10 + '0';           /* Convert TIME to ASCII                             */
              s[12] = hr    % 10 + '0';
              s[14] = min   / 10 + '0';
              s[15] = min   % 10 + '0';
              s[17] = sec   / 10 + '0';
              s[18] = sec   % 10 + '0';
              break;

        default:
              strcpy(s, "?");
              break;
    }
}
#endif

/*$PAGE*/
/*
*********************************************************************************************************
*                                             GET TIME-STAMP
*
* Description : This function is used to return a time-stamp to your application.  The format of the
*               time-stamp is shown below:
*
*        Field: -------Year------ ---Month--- ------Day----- ----Hours----- ---Minutes--- --Seconds--
*        Bit# : 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
*
* Arguments   : None.
* Returns     : None.
* Notes       : The year is based from CLK_TS_BASE_YEAR.  That is, if bits 31..26 contain 0 it really 
*               means that the year is CLK_TS_BASE_YEAR.  If bits 31..26 contain 13, the year is 
*               CLK_TS_BASE_YEAR + 13.
*********************************************************************************************************
*/

#if CLK_TS_EN && CLK_DATE_EN
TS  ClkGetTS (void)
{
    TS ts;


    OS_ENTER_CRITICAL();
    ts = ClkTS;
    OS_EXIT_CRITICAL();
    return (ts);
}
#endif

/*$PAGE*/
/*
*********************************************************************************************************
*                                        TIME MODULE INITIALIZATION
*                                     TIME-OF-DAY CLOCK INITIALIZATION
*
* Description : This function initializes the time module.  The time of day clock task will be created
*               by this function.
* Arguments   : None
* Returns     : None.
*********************************************************************************************************
*/

void  ClkInit (void)
{
    ClkSem     = OSSemCreate(1);       /* Create time of day clock semaphore                           */
    ClkSemSec  = OSSemCreate(0);       /* Create counting semaphore to signal the occurrence of 1 sec. */
    ClkTickCtr =    0;
    ClkSec     =    0;
    ClkMin     =    0;
    ClkHr      =    0;
#if CLK_DATE_EN
    ClkDay     =    1;
    ClkMonth   =    1;
    ClkYear    = 1999;
#endif
#if CLK_TS_EN && CLK_DATE_EN
    ClkTS      = ClkMakeTS(ClkMonth, ClkDay, ClkYear, ClkHr, ClkMin, ClkSec);
#endif
    OSTaskCreate(ClkTask, (void *)0, &ClkTaskStk[CLK_TASK_STK_SIZE], CLK_TASK_PRIO);
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                     DETERMINE IF WE HAVE A LEAP YEAR
*
* Description : This function determines whether the 'year' passed as an argument is a leap year.
* Arguments   : year    is the year to check for leap year.
* Returns     : TRUE    if 'year' is a leap year.
*               FALSE   if 'year' is NOT a leap year.
*********************************************************************************************************
*/
#if CLK_DATE_EN
static  BOOLEAN  ClkIsLeapYear(INT16U year)
{
    if (!(year % 4) && (year % 100) || !(year % 400)) {
        return TRUE;
    } else {
        return (FALSE);
    }
}
#endif

/*$PAGE*/
/*
*********************************************************************************************************
*                                           MAKE TIME-STAMP
*
* Description : This function maps a user specified date and time into a 32 bit variable called a
*               time-stamp.
* Arguments   : month     is the desired month   (1..12)
*               day       is the desired day     (1..31)
*               year      is the desired year    (CLK_TS_BASE_YEAR .. CLK_TS_BASE_YEAR+63)
*               hr        is the desired hour    (0..23)
*               min       is the desired minutes (0..59)
*               sec       is the desired seconds (0..59)
* Returns     : A time-stamp based on the arguments passed to the function.
* Notes       : - The time stamp is formatted as follows using a 32 bit unsigned integer:
*
*        Field: -------Year------ ---Month--- ------Day----- ----Hours----- ---Minutes--- --Seconds--
*        Bit# : 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
*
*               - The year is based from CLK_TS_BASE_YEAR.  That is, if bits 31..26 contain 0 it really 
*                 means that the year is really CLK_TS_BASE_YEAR.  If bits 31..26 contain 13, the year is 
*                 CLK_TS_BASE_YEAR + 13.
*********************************************************************************************************
*/

#if CLK_TS_EN && CLK_DATE_EN
TS  ClkMakeTS (INT8U month, INT8U day, INT16U yr, INT8U hr, INT8U min, INT8U sec)
{
    TS ts;


    yr -= CLK_TS_BASE_YEAR;
    ts  = ((INT32U)yr << 26) | ((INT32U)month << 22) | ((INT32U)day << 17);
    ts |= ((INT32U)hr << 12) | ((INT32U)min   <<  6) |  (INT32U)sec;
    return (ts);
}
#endif

/*$PAGE*/
/*
*********************************************************************************************************
*                                            SET DATE ONLY
*
* Description : Set the date of the time-of-day clock
* Arguments   : month     is the desired month (1..12)
*               day       is the desired day   (1..31)
*               year      is the desired year  (CLK_TS_BASE_YEAR .. CLK_TS_BASE_YEAR+63)
* Returns     : None.
* Notes       : It is assumed that you are specifying a correct date (i.e. there is no range checking
*               done by this function).
*********************************************************************************************************
*/

#if  CLK_DATE_EN
void  ClkSetDate (INT8U month, INT8U day, INT16U year)
{
    INT8U err;


    OSSemPend(ClkSem, 0, &err);                  /* Gain exclusive access to time-of-day clock         */
    ClkMonth = month;
    ClkDay   = day;
    ClkYear  = year;
    ClkUpdateDOW();                              /* Compute the day of the week (i.e. Sunday ...)      */
    OSSemPost(ClkSem);                           /* Release access to time-of-day clock                */
}
#endif

/*$PAGE*/
/*
*********************************************************************************************************
*                                          SET DATE AND TIME
*
* Description : Set the date and time of the time-of-day clock
* Arguments   : month     is the desired month   (1..12)
*               day       is the desired day     (1..31)
*               year      is the desired year    (2xxx)
*               hr        is the desired hour    (0..23)
*               min       is the desired minutes (0..59)
*               sec       is the desired seconds (0..59)
* Returns     : None.
* Notes       : It is assumed that you are specifying a correct date and time (i.e. there is no range
*               checking done by this function).
*********************************************************************************************************
*/

#if  CLK_DATE_EN
void  ClkSetDateTime (INT8U month, INT8U day, INT16U year, INT8U hr, INT8U min, INT8U sec)
{
    INT8U err;


    OSSemPend(ClkSem, 0, &err);                  /* Gain exclusive access to time-of-day clock         */
    ClkMonth = month;
    ClkDay   = day;
    ClkYear  = year;
    ClkHr    = hr;
    ClkMin   = min;
    ClkSec   = sec;
    ClkUpdateDOW();                              /* Compute the day of the week (i.e. Sunday ...)      */
    OSSemPost(ClkSem);                           /* Release access to time-of-day clock                */
}
#endif

/*$PAGE*/
/*
*********************************************************************************************************
*                                          SET TIME ONLY
*
* Description : Set the time-of-day clock
* Arguments   : hr        is the desired hour    (0..23)
*               min       is the desired minutes (0..59)
*               sec       is the desired seconds (0..59)
* Returns     : None.
* Notes       : It is assumed that you are specifying a correct time (i.e. there is no range checking
*               done by this function).
*********************************************************************************************************
*/

void  ClkSetTime (INT8U hr, INT8U min, INT8U sec)
{
    OS_ENTER_CRITICAL();                         /* Gain exclusive access to time-of-day clock         */
    ClkHr  = hr;
    ClkMin = min;
    ClkSec = sec;
    OS_EXIT_CRITICAL();                          /* Release access to time-of-day clock                */
}

/*$PAGE*/
/*
*********************************************************************************************************
*                          SIGNAL CLOCK MODULE THAT A 'CLOCK TICK' HAS OCCURRED
*
* Description : This function is called by the 'clock tick' ISR on every tick.  This function is thus
*               responsible for counting the number of clock ticks per second.  When a second elapses,
*               this function will signal the time-of-day clock task.
* Arguments   : None.
* Returns     : None.
* Note(s)     : CLK_DLY_TICKS must be set to the number of ticks to produce 1 second.  
*               This would typically correspond to OS_TICKS_PER_SEC if you use uC/OS-II.
*********************************************************************************************************
*/

void  ClkSignalClk (void)
{
    ClkTickCtr++;                           /* count the number of 'clock ticks' for one second        */
    if (ClkTickCtr >= CLK_DLY_TICKS) {
        ClkTickCtr = 0;
        OSSemPost(ClkSemSec);               /* Signal that one second elapsed                          */
    }
}

/*
*********************************************************************************************************
*                                        TIME-OF-DAY CLOCK TASK
*
* Description : This task is created by ClkInit() and is responsible for updating the time and date.
*               ClkTask() executes every second.
* Arguments   : None.
* Returns     : None.
* Notes       : CLK_DLY_TICKS must be set to produce 1 second delays.
*********************************************************************************************************
*/

void  ClkTask (void *data)
{
    INT8U err;


    data = data;                            /* Avoid compiler warning (uC/OS requirement)              */
    for (;;) {

#if CLK_USE_DLY
        OSTimeDlyHMSM(0, 0, 1, 0);          /* Delay for one second                                    */
#else
        OSSemPend(ClkSemSec, 0, &err);      /* Wait for one second to elapse                           */
#endif

        OSSemPend(ClkSem, 0, &err);         /* Gain exclusive access to time-of-day clock              */
        if (ClkUpdateTime() == TRUE) {      /* Update the TIME (i.e. HH:MM:SS)                         */
#if CLK_DATE_EN
            ClkUpdateDate();                /* And date if a new day (i.e. MM-DD-YY)                   */
#endif
        }
#if CLK_TS_EN && CLK_DATE_EN
        ClkTS = ClkMakeTS(ClkMonth, ClkDay, ClkYear, ClkHr, ClkMin, ClkSec);
#endif
        OSSemPost(ClkSem);                  /* Release access to time-of-day clock                     */
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                            UPDATE THE DATE
*
* Description : This function is called to update the date (i.e. month, day and year)
* Arguments   : None.
* Returns     : None.
* Notes       : This function updates ClkDay, ClkMonth, ClkYear and ClkDOW.
*********************************************************************************************************
*/

#if CLK_DATE_EN
static  void  ClkUpdateDate (void)
{
    BOOLEAN newmonth;


    newmonth = TRUE;
    if (ClkDay >= ClkMonthTbl[ClkMonth].MonthDays) {  /* Last day of the month?                        */
        if (ClkMonth == 2) {                          /* Is this February?                             */
            if (ClkIsLeapYear(ClkYear) == TRUE) {     /* Yes, Is this a leap year?                     */
                if (ClkDay >= 29) {                   /* Yes, Last day in february?                    */
                    ClkDay = 1;                       /* Yes, Set to 1st day in March                  */
                } else {
                    ClkDay++;
                    newmonth = FALSE;
                }
            } else {
                ClkDay = 1;
            }
        } else {
            ClkDay = 1;
        }
    } else {
        ClkDay++;
        newmonth = FALSE;
    }
    if (newmonth == TRUE) {                      /* See if we have completed a month                   */
        if (ClkMonth >= 12) {                    /* Yes, Is this december ?                            */
            ClkMonth = 1;                        /* Yes, set month to january...                       */
            ClkYear++;                           /*      ...we have a new year!                        */
        } else {
            ClkMonth++;                          /* No,  increment the month                           */
        }
    }
    ClkUpdateDOW();                              /* Compute the day of the week (i.e. Sunday ...)      */
}
#endif

/*$PAGE*/
/*
*********************************************************************************************************
*                                         COMPUTE DAY-OF-WEEK
*
* Description : This function computes the day of the week (0 == Sunday) based on the current month,
*               day and year.
* Arguments   : None.
* Returns     : None.
* Notes       : - This function updates ClkDOW.
*               - This function is called by ClkUpdateDate().
*********************************************************************************************************
*/
#if CLK_DATE_EN
static  void  ClkUpdateDOW (void)
{
    INT16U dow;


    dow = ClkDay + ClkMonthTbl[ClkMonth].MonthVal;
    if (ClkMonth < 3) {
        if (ClkIsLeapYear(ClkYear)) {
            dow--;
        }
    }
    dow    += ClkYear + (ClkYear / 4);
    dow    += (ClkYear / 400) - (ClkYear / 100);
    dow    %= 7;
    ClkDOW  = dow;
}
#endif

/*$PAGE*/
/*
*********************************************************************************************************
*                                            UPDATE THE TIME
*
* Description : This function is called to update the time (i.e. hours, minutes and seconds)
* Arguments   : None.
* Returns     : TRUE     if we have completed one day.
*               FALSE    otherwise
* Notes       : This function updates ClkSec, ClkMin and ClkHr.
*********************************************************************************************************
*/

static  BOOLEAN  ClkUpdateTime (void)
{
    BOOLEAN newday;


    newday = FALSE;                         /* Assume that we haven't completed one whole day yet      */
    if (ClkSec >= 59) {                     /* See if we have completed one minute yet                 */
        ClkSec = 0;                         /* Yes, clear seconds                                      */
        if (ClkMin >= 59) {                 /*    See if we have completed one hour yet                */
            ClkMin = 0;                     /*    Yes, clear minutes                                   */
            if (ClkHr >= 23) {              /*        See if we have completed one day yet             */
                ClkHr = 0;                  /*        Yes, clear hours ...                             */
                newday    = TRUE;           /*        ... change flag to indicate we have a new day    */
            } else {
                ClkHr++;                    /*        No,  increment hours                             */
            }
        } else {
            ClkMin++;                       /*    No,  increment minutes                               */
        }
    } else {
        ClkSec++;                           /* No,  increment seconds                                  */
    }
    return (newday);
}

