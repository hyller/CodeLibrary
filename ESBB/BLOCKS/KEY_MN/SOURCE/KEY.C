/*
*********************************************************************************************************
*                                    Embedded Systems Building Blocks
*                                 Complete and Ready-to-Use Modules in C
*
*                                         Matrix Keyboard Driver
*
*                            (c) Copyright 1999, Jean J. Labrosse, Weston, FL
*                                           All Rights Reserved
*
* Filename   : KEY.C
* Programmer : Jean J. Labrosse
*********************************************************************************************************
*                                             DESCRIPTION
*
*    The keyboard is assumed to be a matrix having 4 rows by 6 columns.  However, this code works for any
* matrix arrangements up to an 8 x 8 matrix.  By using from one to three of the column inputs, the driver
* can support "SHIFT" keys.  These keys are: SHIFT1, SHIFT2 and SHIFT3.
*
*    Your application software must declare (see KEY.H):
*
*    KEY_BUF_SIZE            Size of the KEYBOARD buffer
*
*    KEY_MAX_ROWS            The maximum number of rows    on the keyboard
*    KEY_MAX_COLS            The maximum number of columns on the keyboard
*
*    KEY_RPT_DLY             Number of scan times before auto repeat executes the function again
*    KEY_RPT_START_DLY       Number of scan times before auto repeat function engages
*
*    KEY_SCAN_TASK_DLY       The number of milliseconds between keyboard scans
*    KEY_SCAN_TASK_PRIO      Sets the priority of the keyboard scanning task
*    KEY_SCAN_TASK_STK_SIZE  The size of the keyboard scanning task stack
*
*    KEY_SHIFT1_MSK          The mask which determines which column input handles the SHIFT1 key
*                                (A 0x00 indicates that a SHIFT1 key is not present)
*    KEY_SHIFT1_OFFSET       The scan code offset to add when the SHIFT1 key is pressed
*
*    KEY_SHIFT2_MSK          The mask which determines which column input handles the SHIFT2 key
*                                (A 0x00 indicates that an SHIFT2 key is not present)
*    KEY_SHIFT2_OFFSET       The scan code offset to add when the SHIFT2 key is pressed
*
*    KEY_SHIFT3_MSK          The mask which determines which column input handles the SHIFT3 key
*                                (A 0x00 indicates that a SHIFT3 key is not present)
*    KEY_SHIFT3_OFFSET       The scan code offset to add when the SHIFT3 key is pressed
*
*
*    KEY_PORT_ROW            The port address of the keyboard matrix ROWs
*    KEY_PORT_COL            The port address of the keyboard matrix COLUMNs
*    KEY_PORT_CW             The port address of the keyboard I/O ports control word
*
*    KeyInitPort, KeySelRow() and KeyGetCol() are the only three hardware specific functions.  This has
*    been done to localize the interface to the hardware in only these two functions and thus make is
*    easier to adapt to your application.
*********************************************************************************************************
*/

/*$PAGE*/
/*
*********************************************************************************************************
*                                              INCLUDE FILES
*********************************************************************************************************
*/

#include "includes.h"

/*
*********************************************************************************************************
*                                            LOCAL CONSTANTS
*********************************************************************************************************
*/

#define KEY_STATE_UP                 1      /* Key scanning states used in KeyScan()                   */
#define KEY_STATE_DEBOUNCE           2
#define KEY_STATE_RPT_START_DLY      3
#define KEY_STATE_RPT_DLY            4

/*
*********************************************************************************************************
*                                            GLOBAL VARIABLES
*********************************************************************************************************
*/

static  INT8U     KeyBuf[KEY_BUF_SIZE];     /* Keyboard buffer                                         */
static  INT8U     KeyBufInIx;               /* Index into key buf where next scan code will be inserted*/
static  INT8U     KeyBufOutIx;              /* Index into key buf where next scan code will be removed */
static  INT16U    KeyDownTmr;               /* Counts how long key has been pressed                    */
static  INT8U     KeyNRead;                 /* Number of keys read from the keyboard                   */

static  INT8U     KeyRptStartDlyCtr;        /* Number of scan times before auto repeat is started      */
static  INT8U     KeyRptDlyCtr;             /* Number of scan times before auto repeat executes again  */

static  INT8U     KeyScanState;             /* Current state of key scanning function                  */

static  OS_STK    KeyScanTaskStk[KEY_SCAN_TASK_STK_SIZE];  /* Keyboard scanning task stack             */

static  OS_EVENT *KeySemPtr;                               /* Pointer to keyboard semaphore            */

/*
*********************************************************************************************************
*                                       LOCAL FUNCTION PROTOTYPES
*********************************************************************************************************
*/

static  void      KeyBufIn(INT8U code);     /* Insert scan code into keyboard buffer                   */
static  INT8U     KeyDecode(void);          /* Get scan code from current key pressed                  */
static  BOOLEAN   KeyIsKeyDown(void);       /* See if key has been pressed                             */
static  void      KeyScanTask(void *data);  /* Keyboard scanning task                                  */

/*$PAGE*/
/*
*********************************************************************************************************
*                                INSERT KEY CHARACTER INTO KEYBOARD BUFFER
*
* Description : This function inserts a key character into the keyboard buffer
* Arguments   : code    is the keyboard scan code to insert into the buffer
* Returns     : none
*********************************************************************************************************
*/

static  void  KeyBufIn (INT8U code)
{
    OS_ENTER_CRITICAL();                         /* Start of critical section of code, disable ints    */
    if (KeyNRead < KEY_BUF_SIZE) {               /* Make sure that we don't overflow the buffer        */
        KeyNRead++;                              /* Increment the number of keys read                  */
        KeyBuf[KeyBufInIx++] = code;             /* Store the scan code into the buffer                */
        if (KeyBufInIx >= KEY_BUF_SIZE) {        /* Adjust index to the next scan code to put in buffer*/
            KeyBufInIx = 0;
        }
        OS_EXIT_CRITICAL();                      /* End of critical section of code                    */
        OSSemPost(KeySemPtr);                    /* Signal sem if scan code inserted in the buffer     */
    } else {                                     /* Buffer is full, key scan code is lost              */
        OS_EXIT_CRITICAL();                      /* End of critical section of code                    */
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                           DECODE KEYBOARD
*
* Description : This function is called to determine the key scan code of the key pressed.
* Arguments   : none
* Returns     : the key scan code
*********************************************************************************************************
*/

static  INT8U  KeyDecode (void)
{
    INT8U   col;
    INT8U   row;
    INT8U   offset;
    BOOLEAN done;
    INT8U   col_id;
    INT8U   msk;


    done = FALSE;
    row  = 0;
    while (row < KEY_MAX_ROWS && !done) {             /* Find out in which row key was pressed         */
        KeySelRow(row);                               /* Select a row                                  */
        if (KeyIsKeyDown()) {                         /* See if key is pressed in this row             */
            done = TRUE;                              /* We are done finding the row                   */
        } else {
            row++;                                    /* Select next row                               */
        }
    }
    col    = KeyGetCol();                             /* Read columns                                  */
    offset = 0;                                       /* No SHIFT1, SHIFT2 or SHIFT3 key pressed       */
    if (col & KEY_SHIFT1_MSK) {                       /* See if SHIFT1 key was also pressed            */
        offset += KEY_SHIFT1_OFFSET;
    }
    if (col & KEY_SHIFT2_MSK) {                       /* See if SHIFT2 key was also pressed            */
        offset += KEY_SHIFT2_OFFSET;
    }
    if (col & KEY_SHIFT3_MSK) {                       /* See if SHIFT3 key was also pressed            */
        offset += KEY_SHIFT3_OFFSET;
    }
    msk    = 0x01;                                    /* Set bit mask to scan for the column           */
    col_id =    0;                                    /* Set column value (0..7)                       */
    done   = FALSE;
    while (col_id < KEY_MAX_COLS && !done) {          /* Go through all columns                        */
        if (col & msk) {                              /* See if key was pressed in this columns        */
            done  = TRUE;                             /* Done, i has column value of the key (0..7)    */
        } else {
            col_id++;
            msk <<= 1;
        }
    }
    return (row * KEY_MAX_COLS + offset + col_id);    /* Return scan code                              */
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                         FLUSH KEYBOARD BUFFER
*
* Description : This function clears the keyboard buffer
* Arguments   : none
* Returns     : none
*********************************************************************************************************
*/

void  KeyFlush (void)
{
    while (KeyHit()) {                           /* While there are keys in the buffer...              */
        KeyGetKey(0);                            /* ... extract the next key from the buffer           */
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                                 GET KEY
*
* Description : Get a keyboard scan code from the keyboard driver.
* Arguments   : 'to'     is the amount of time KeyGetKey() will wait (in number of ticks) for a key to be
*                        pressed.  A timeout of '0' means that the caller is willing to wait forever for
*                        a key to be pressed.
* Returns     : != 0xFF  is the key scan code of the key pressed
*               == 0xFF  indicates that there is no key in the buffer within the specified timeout
*********************************************************************************************************
*/

INT8U  KeyGetKey (INT16U to)
{
    INT8U code;
    INT8U err;


    OSSemPend(KeySemPtr, to, &err);              /* Wait for a key to be pressed                       */
    OS_ENTER_CRITICAL();                         /* Start of critical section of code, disable ints    */
    if (KeyNRead > 0) {                          /* See if we have keys in the buffer                  */
        KeyNRead--;                              /* Decrement the number of keys read                  */
        code = KeyBuf[KeyBufOutIx];              /* Get scan code from the buffer                      */
        KeyBufOutIx++;
        if (KeyBufOutIx >= KEY_BUF_SIZE) {       /* Adjust index into the keyboard buffer              */
            KeyBufOutIx = 0;
        }
        OS_EXIT_CRITICAL();                      /* End of critical section of code                    */
        return (code);                           /* Return the scan code of the key pressed            */
    } else {
        OS_EXIT_CRITICAL();                      /* End of critical section of code                    */
        return (0xFF);                           /* No scan codes in the buffer, return -1             */
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                  GET HOW LONG KEY HAS BEEN PRESSED
*
* Description : This function returns the amount of time the key has been pressed.
* Arguments   : none
* Returns     : key down time in 'milliseconds'
*********************************************************************************************************
*/

INT32U  KeyGetKeyDownTime (void)
{
    INT16U tmr;


    OS_ENTER_CRITICAL();
    tmr = KeyDownTmr;
    OS_EXIT_CRITICAL();
    return (tmr * KEY_SCAN_TASK_DLY);
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                        SEE IF ANY KEY IN BUFFER
*
* Description : This function checks to see if a key was pressed
* Arguments   : none
* Returns     : TRUE   if a key has been pressed
*               FALSE  if no key pressed
*********************************************************************************************************
*/

BOOLEAN  KeyHit (void)
{
    BOOLEAN hit;


    OS_ENTER_CRITICAL();
    hit = (BOOLEAN)(KeyNRead > 0) ? TRUE : FALSE;
    OS_EXIT_CRITICAL();
    return (hit);
}

/*
*********************************************************************************************************
*                                       KEYBOARD INITIALIZATION
*
* Description: Keyboard initialization function.  KeyInit() must be called before calling any other of
*              the user accessible functions.
* Arguments  : none
* Returns    : none
*********************************************************************************************************
*/

void  KeyInit (void)
{
    KeySelRow(KEY_ALL_ROWS);                     /* Select all row                                     */
    KeyScanState = KEY_STATE_UP;                 /* Keyboard should not have a key pressed             */
    KeyNRead     = 0;                            /* Clear the number of keys read                      */
    KeyDownTmr   = 0;
    KeyBufInIx   = 0;                            /* Key codes inserted at  the beginning of the buffer */
    KeyBufOutIx  = 0;                            /* Key codes removed from the beginning of the buffer */
    KeySemPtr    = OSSemCreate(0);               /* Initialize the keyboard semaphore                  */
    KeyInitPort();                               /* Initialize I/O ports used in keyboard driver       */
    OSTaskCreate(KeyScanTask, (void *)0, &KeyScanTaskStk[KEY_SCAN_TASK_STK_SIZE], KEY_SCAN_TASK_PRIO);
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                           SEE IF KEY PRESSED
*
* Description : This function checks to see if a key is pressed
* Arguments   : none
* Returns     : TRUE   if a key is     pressed
*               FALSE  if a key is not pressed
* Note        : (1 << KEY_MAX_COLS) - 1   is used as a mask to isolate the column inputs (i.e. mask off
*                                         the SHIFT keys).
*********************************************************************************************************
*/

static  BOOLEAN  KeyIsKeyDown (void)
{
    if (KeyGetCol() & ((1 << KEY_MAX_COLS) - 1)) {         /* Key not pressed if 0                     */
        OS_ENTER_CRITICAL();
        KeyDownTmr++;                                      /* Update key down counter                  */
        OS_EXIT_CRITICAL();
        return (TRUE);
    } else {
        return (FALSE);
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                         KEYBOARD SCANNING TASK
*
* Description : This function contains the body of the keyboard scanning task.  The task should be
*               assigned a low priority.  The scanning period is determined by KEY_SCAN_TASK_DLY.
* Arguments   : 'data'   is a pointer to data passed to task when task is created (NOT USED).
* Returns     : KeyScanTask() never returns.
* Notes       : - An auto repeat of the key pressed will be executed after the key has been pressed for
*                 more than KEY_RPT_START_DLY scan times.  Once the auto repeat has started, the key will
*                 be repeated every KEY_RPT_DLY scan times as long as the key is pressed.  For example,
*                 if the scanning of the keyboard occurs every 50 mS and KEY_RPT_START_DLY is set to 40
*                 and KEY_RPT_DLY is set to 2, then the auto repeat function will engage after 2 seconds
*                 and will repeat every 100 mS (10 times per second).
*********************************************************************************************************
*/

/*$PAGE*/
static  void  KeyScanTask (void *data)
{
    INT8U code;


    data = data;                                           /* Avoid compiler warning (uC/OS-II req.)   */
    for (;;) {
        OSTimeDlyHMSM(0, 0, 0, KEY_SCAN_TASK_DLY);         /* Delay between keyboard scans             */
        switch (KeyScanState) {
            case KEY_STATE_UP:                             /* See if need to look for a key pressed    */
                 if (KeyIsKeyDown()) {                     /* See if key is pressed                    */
                     KeyScanState = KEY_STATE_DEBOUNCE;    /* Next call we will have debounced the key */
                     KeyDownTmr   = 0;                     /* Reset key down timer                     */
                 }
                 break;

            case KEY_STATE_DEBOUNCE:                       /* Key pressed, get scan code and buffer    */
                 if (KeyIsKeyDown()) {                     /* See if key is pressed                    */
                     code              = KeyDecode();      /* Determine the key scan code              */
                     KeyBufIn(code);                       /* Input scan code in buffer                */
                     KeyRptStartDlyCtr = KEY_RPT_START_DLY;/* Start delay to auto-repeat function      */
                     KeyScanState      = KEY_STATE_RPT_START_DLY;
                 } else {
                     KeySelRow(KEY_ALL_ROWS);              /* Select all row                           */
                     KeyScanState      = KEY_STATE_UP;     /* Key was not pressed after all!           */
                 }
                 break;

            case KEY_STATE_RPT_START_DLY:
                 if (KeyIsKeyDown()) {                     /* See if key is still pressed              */
                     if (KeyRptStartDlyCtr > 0) {          /* See if we need to delay before auto rpt  */
                         KeyRptStartDlyCtr--;              /* Yes, decrement counter to start of rpt   */
                         if (KeyRptStartDlyCtr == 0) {     /* If delay to auto repeat is completed ... */
                             code         = KeyDecode();   /* Determine the key scan code              */
                             KeyBufIn(code);               /* Input scan code in buffer                */
                             KeyRptDlyCtr = KEY_RPT_DLY;   /* Load delay before next repeat            */
                             KeyScanState = KEY_STATE_RPT_DLY;
                         }
                     }
                 } else {
                     KeyScanState = KEY_STATE_DEBOUNCE;    /* Key was not pressed after all            */
                 }
                 break;

            case KEY_STATE_RPT_DLY:
                 if (KeyIsKeyDown()) {                     /* See if key is still pressed              */
                     if (KeyRptDlyCtr > 0) {               /* See if we need to wait before repeat key */
                         KeyRptDlyCtr--;                   /* Yes, dec. wait time to next key repeat   */
                         if (KeyRptDlyCtr == 0) {          /* See if it's time to repeat key           */
                             code         = KeyDecode();   /* Determine the key scan code              */
                             KeyBufIn(code);               /* Input scan code in buffer                */
                             KeyRptDlyCtr = KEY_RPT_DLY;   /* Reload delay counter before auto repeat  */
                         }
                     }
                 } else {
                     KeyScanState = KEY_STATE_DEBOUNCE;    /* Key was not pressed after all            */
                 }
                 break;
        }
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                              READ COLUMNS
*
* Description : This function is called to read the column port.
* Arguments   : none
* Returns     : the complement of the column port thus, ones are keys pressed
*********************************************************************************************************
*/

#ifndef CFG_C
INT8U  KeyGetCol (void)
{
    return (~inp(KEY_PORT_COL));                 /* Complement columns (ones indicate key is pressed)  */
}
#endif


/*
*********************************************************************************************************
*                                         INITIALIZE I/O PORTS
*********************************************************************************************************
*/

#ifndef CFG_C
void  KeyInitPort (void)
{
    outp(KEY_PORT_CW, 0x82);                     /* Initialize 82C55: A=OUT, B=IN (COLS), C=OUT (ROWS) */
}
#endif


/*
*********************************************************************************************************
*                                            SELECT A ROW
*
* Description : This function is called to select a row on the keyboard.
* Arguments   : 'row'  is the row number (0..7) or KEY_ALL_ROWS
* Returns     : none
* Note        : The row is selected by writing a LOW.
*********************************************************************************************************
*/

#ifndef CFG_C
void  KeySelRow (INT8U row)
{
    if (row == KEY_ALL_ROWS) {
        outp(KEY_PORT_ROW, 0x00);                /* Force all rows LOW                                 */
    } else {
        outp(KEY_PORT_ROW, ~(1 << row));         /* Force desired row LOW                              */
    }
}
#endif
