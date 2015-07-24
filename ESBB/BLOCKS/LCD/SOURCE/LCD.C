/*
*********************************************************************************************************
*                                   Embedded Systems Building Blocks
*                                Complete and Ready-to-Use Modules in C
*
*                                        LCD Display Module Driver
*
*                            (c) Copyright 1999, Jean J. Labrosse, Weston, FL
*                                           All Rights Reserved
*
* Filename   : LCD.C
* Programmer : Jean J. Labrosse
*********************************************************************************************************
*                                              DESCRIPTION
*
*
* This module provides an interface to an alphanumeric display module.
*
* The current version of this driver supports any  alphanumeric LCD module based on the:
*     Hitachi HD44780 DOT MATRIX LCD controller.
*
* This driver supports LCD displays having the following configuration:
*
*     1 line  x 16 characters     2 lines x 16 characters     4 lines x 16 characters
*     1 line  x 20 characters     2 lines x 20 characters     4 lines x 20 characters
*     1 line  x 24 characters     2 lines x 24 characters
*     1 line  x 40 characters     2 lines x 40 characters
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

                                       /* ---------------------- HD44780 COMMANDS -------------------- */
#define  DISP_CMD_CLS            0x01  /* Clr display : clears display and returns cursor home         */
#define  DISP_CMD_FNCT           0x3B  /* Function Set: Set 8 bit data length, 1/16 duty, 5x8 dots     */
#define  DISP_CMD_MODE           0x06  /* Entry mode  : Inc. display data address when writing         */
#define  DISP_CMD_ON_OFF         0x0C  /* Disp ON/OFF : Display ON, cursor OFF and no BLINK character  */

/*
*********************************************************************************************************
*                                            LOCAL VARIABLES
*********************************************************************************************************
*/

static  INT8U       DispMaxCols;       /* Maximum number of columns (i.e. characters per line)         */
static  INT8U       DispMaxRows;       /* Maximum number of rows for the display                       */
static  OS_EVENT   *DispSem;           /* Semaphore used to access display functions                   */


static  INT8U       DispBar1[] = {0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10};
static  INT8U       DispBar2[] = {0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18};
static  INT8U       DispBar3[] = {0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C};
static  INT8U       DispBar4[] = {0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E};
static  INT8U       DispBar5[] = {0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F};

/*
*********************************************************************************************************
*                                        LOCAL FUNCTION PROTOTYPES
*********************************************************************************************************
*/

static  void        DispCursorSet(INT8U row, INT8U col);

/*$PAGE*/
/*
*********************************************************************************************************
*                                           DISPLAY A CHARACTER
*
* Description : This function is used to display a single character on the display device
* Arguments   : 'row'   is the row    position of the cursor in the LCD Display
*                       'row' can be a value from 0 to 'DispMaxRows - 1'
*               'col'   is the column position of the cursor in the LCD Display
*                       'col' can be a value from 0 to 'DispMaxCols - 1'
*               'c'     is the character to write to the display at the current ROW/COLUMN position.
* Returns     : none
*********************************************************************************************************
*/

void  DispChar (INT8U row, INT8U col, char c)
{
    INT8U err;


    if (row < DispMaxRows && col < DispMaxCols) {
        OSSemPend(DispSem, 0, &err);        /* Obtain exclusive access to the display                  */
        DispCursorSet(row, col);            /* Position cursor at ROW/COL                              */
        DispSel(DISP_SEL_DATA_REG);
        DispDataWr(c);                      /* Send character to display                               */
        OSSemPost(DispSem);                 /* Release access to display                               */
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                             CLEAR LINE
*
* Description : This function clears one line on the LCD display and positions the cursor at the
*               beginning of the line.
* Arguments   : 'line'  is the line number to clear and can take the value
*                       0 to 'DispMaxRows - 1'
* Returns     : none
*********************************************************************************************************
*/

void  DispClrLine (INT8U line)
{
    INT8U i;
    INT8U err;


    if (line < DispMaxRows) {
        OSSemPend(DispSem, 0, &err);             /* Obtain exclusive access to the display             */
        DispCursorSet(line, 0);                  /* Position cursor at begin of the line to clear      */
        DispSel(DISP_SEL_DATA_REG);              /* Select the LCD Display DATA register               */
        for (i = 0; i < DispMaxCols; i++) {      /* Write ' ' into all column positions of that line   */
            DispDataWr(' ');                     /* Write an ASCII space at current cursor position    */
        }
        DispCursorSet(line, 0);                  /* Position cursor at begin of the line to clear      */
        OSSemPost(DispSem);                      /* Release access to display                          */
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                            CLEAR THE SCREEN
*
* Description : This function clears the display
* Arguments   : none
* Returns     : none
*********************************************************************************************************
*/

void  DispClrScr (void)
{
    INT8U err;


    OSSemPend(DispSem, 0, &err);       /* Obtain exclusive access to the display                       */
    DispSel(DISP_SEL_CMD_REG);         /* Select the LCD display command register                      */
    DispDataWr(DISP_CMD_CLS);          /* Send command to LCD display to clear the display             */
    OSTimeDly(2);                      /* Delay at least  2 mS (2 ticks ensures at least this much)    */
    OSSemPost(DispSem);                /* Release access to display                                    */
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                     POSITION THE CURSOR (Internal)
*
* Description : This function positions the cursor into the LCD buffer
* Arguments   : 'row'   is the row    position of the cursor in the LCD Display
*                       'row' can be a value from 0 to 'DispMaxRows - 1'
*               'col'   is the column position of the cursor in the LCD Display
*                       'col' can be a value from 0 to 'DispMaxCols - 1'
* Returns     : none
*********************************************************************************************************
*/

static  void  DispCursorSet (INT8U row, INT8U col)
{
    DispSel(DISP_SEL_CMD_REG);                             /* Select LCD display command register      */
    switch (row) {
        case 0:
             if (DispMaxRows == 1) {                       /* Handle special case when only one line   */
                 if (col < (DispMaxCols >> 1)) {
                     DispDataWr(0x80 + col);               /* First  half of the line starts at 0x80   */
                 } else {                                  /* Second half of the line starts at 0xC0   */
                     DispDataWr(0xC0 + col - (DispMaxCols >> 1));
                 }
             } else {
                 DispDataWr(0x80 + col);                   /* Select LCD's display line 1              */
             }
             break;

        case 1:
             DispDataWr(0xC0 + col);                       /* Select LCD's display line 2              */
             break;

        case 2:
             DispDataWr(0x80 + DispMaxCols + col);         /* Select LCD's display line 3              */
             break;

        case 3:
             DispDataWr(0xC0 + DispMaxCols + col);         /* Select LCD's display line 4              */
             break;
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                            DEFINE CHARACTER
*
* Description : This function defines the dot pattern for a character.
* Arguments   : 'id'    is the identifier for the desired dot pattern.
*               'pat'   is a pointer to an 8 BYTE array containing the dot pattern.
* Returns     : None.
*********************************************************************************************************
*/

void  DispDefChar (INT8U id, INT8U *pat)
{
    INT8U err;
    INT8U i;


    OSSemPend(DispSem, 0, &err);            /* Obtain exclusive access to the display                  */
    DispSel(DISP_SEL_CMD_REG);              /* Select command register                                 */
    DispDataWr(0x40 + (id << 3));           /* Set address of CG RAM                                   */
    DispSel(DISP_SEL_DATA_REG);             /* Select the data register                                */
    for (i = 0; i < 8; i++) {
        DispDataWr(*pat++);                 /* Write pattern into CG RAM                               */
    }
    OSSemPost(DispSem);                     /* Release access to display                               */
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                            DUMMY FUNCTION
*
* Description : This function doesn't do anything.  It is used to act like a NOP (i.e. No Operation) to
*               waste a few CPU cycles and thus, act as a short delay.
* Arguments   : none
* Returns     : none
*********************************************************************************************************
*/

void  DispDummy (void)
{
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                       DISPLAY A HORIZONTAL BAR
*
* Description : This function allows you to display horizontal bars (bar graphs) on the LCD module.
* Arguments   : 'row'   is the row    position of the cursor in the LCD Display
*                       'row' can be a value from 0 to 'DispMaxRows - 1'
*               'val'   is the value of the horizontal bar.  This value cannot exceed:
*                           DispMaxCols * 5
* Returns     : none
* Notes       : To use this function, you must first call DispHorBarInit()
*********************************************************************************************************
*/

void  DispHorBar (INT8U row, INT8U col, INT8U val)
{
    INT8U i;
    INT8U full;
    INT8U fract;
    INT8U err;


    full  = val / 5;                        /* Find out how many 'full' blocks to turn ON              */
    fract = val % 5;                        /* Compute portion of block                                */
    if (row < DispMaxRows && (col + full - 1) < DispMaxCols) {
        OSSemPend(DispSem, 0, &err);        /* Obtain exclusive access to the display                  */
        i = 0;                              /* Set counter to limit column to maximum allowable column */
        DispCursorSet(row, col);            /* Position cursor at beginning of the bar graph           */
        DispSel(DISP_SEL_DATA_REG);
        while (full > 0) {                  /* Write all 'full' blocks                                 */
            DispDataWr(5);                  /* Send custom character #5 which is full block            */
            i++;                            /* Increment limit counter                                 */
            full--;
        }
        if (fract > 0) {
            DispDataWr(fract);              /* Send custom character # 'fract' (i.e. portion of block) */
        }
        OSSemPost(DispSem);                 /* Release access to display                               */
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                      INITIALIZE HORIZONTAL BAR
*
* Description : This function is used to initialize the bar graph capability of this module.  You must
*               call this function prior to calling DispHorBar().
* Arguments   : none
* Returns     : none
*********************************************************************************************************
*/

void  DispHorBarInit (void)
{
    DispDefChar(1, &DispBar1[0]);
    DispDefChar(2, &DispBar2[0]);
    DispDefChar(3, &DispBar3[0]);
    DispDefChar(4, &DispBar4[0]);
    DispDefChar(5, &DispBar5[0]);
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                      DISPLAY DRIVER INITIALIZATION
*
* Description : This function initializes the display driver.
* Arguments   : maxrows      specifies the number of lines on the display (1 to 4)
*               maxcols      specified the number of characters per line
* Returns     : None.
* Notes       : - DispInit() MUST be called only when multitasking has started.  This is because
*                 DispInit() requires time delay services from the operating system.
*               - DispInit() MUST only be called once during initialization.
*********************************************************************************************************
*/

void  DispInit (INT8U maxrows, INT8U maxcols)
{
    DispInitPort();                    /* Initialize I/O ports used in display driver                  */
    DispMaxRows = maxrows;
    DispMaxCols = maxcols;
    DispSem     = OSSemCreate(1);      /* Create display access semaphore                              */

                                       /* INITIALIZE THE DISPLAY MODULE                                */
    DispSel(DISP_SEL_CMD_REG);         /* Select command register.                                     */
    OSTimeDlyHMSM(0, 0, 0, 50);        /* Delay more than 15 mS after power up (50 mS should be enough)*/
    DispDataWr(DISP_CMD_FNCT);         /* Function Set: Set 8 bit data length, 1/16 duty, 5x8 dots     */
    OSTimeDly(2);                      /* Busy flag cannot be checked yet!                             */
    DispDataWr(DISP_CMD_FNCT);         /* The above command is sent four times!                        */
    OSTimeDly(2);                      /*     This is recommended by Hitachi in the HD44780 data sheet */
    DispDataWr(DISP_CMD_FNCT);
    OSTimeDly(2);
    DispDataWr(DISP_CMD_FNCT);
    OSTimeDly(2);

    DispDataWr(DISP_CMD_ON_OFF);       /* Disp ON/OFF: Display ON, cursor OFF and no BLINK character   */
    DispDataWr(DISP_CMD_MODE);         /* Entry mode: Inc. display data address when writing           */
    DispDataWr(DISP_CMD_CLS);          /* Send command to LCD display to clear the display             */
    OSTimeDly(2);                      /* Delay at least  2 mS (2 ticks ensures at least this much)    */
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                         DISPLAY AN ASCII STRING
*
* Description : This function is used to display an ASCII string on a line of the LCD display
* Arguments   : 'row'   is the row    position of the cursor in the LCD Display
*                       'row' can be a value from 0 to 'DispMaxRows - 1'
*               'col'   is the column position of the cursor in the LCD Display
*                       'col' can be a value from 0 to 'DispMaxCols - 1'
*               's'     is a pointer to the string to write to the display at
*                       the desired row/col.
* Returns     : none
*********************************************************************************************************
*/

void  DispStr (INT8U row, INT8U col, char *s)
{
    INT8U i;
    INT8U err;


    if (row < DispMaxRows && col < DispMaxCols) {
        OSSemPend(DispSem, 0, &err);        /* Obtain exclusive access to the display                  */
        DispCursorSet(row, col);            /* Position cursor at ROW/COL                              */
        DispSel(DISP_SEL_DATA_REG);
        i = col;                            /* Set counter to limit column to maximum allowable column */
        while (i < DispMaxCols && *s) {     /* Write all chars within str + limit to DispMaxCols       */
            DispDataWr(*s++);               /* Send character to LCD display                           */
            i++;                            /* Increment limit counter                                 */
        }
        OSSemPost(DispSem);                 /* Release access to display                               */
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                      WRITE DATA TO DISPLAY DEVICE
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

#ifndef CFG_C
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
#endif

/*
*********************************************************************************************************
*                                  INITIALIZE DISPLAY DRIVER I/O PORTS
*
* Description : This initializes the I/O ports used by the display driver.
* Arguments   : none
* Returns     : none
*********************************************************************************************************
*/

#ifndef CFG_C
void  DispInitPort (void)
{
    outp(DISP_PORT_CMD, 0x82);         /* Set to Mode 0: A are output, B are inputs, C are outputs     */
}
#endif

/*
*********************************************************************************************************
*                                   SELECT COMMAND OR DATA REGISTER
*
* Description : This function read a BYTE from the display device.
* Arguments   : none
*********************************************************************************************************
*/

#ifndef CFG_C
void  DispSel (INT8U sel)
{
    if (sel == DISP_SEL_CMD_REG) {
        outp(DISP_PORT_CMD, 0x02);     /* Select the command register (RS low)                         */
    } else {
        outp(DISP_PORT_CMD, 0x03);     /* Select the data    register (RS high)                        */
    }
}
#endif
