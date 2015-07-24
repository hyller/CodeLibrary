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
* Filename   : LED.C
* Programmer : Jean J. Labrosse
*********************************************************************************************************
*                                              DESCRIPTION
*
* This module provides an interface to a multiplexed "8 segments x N digits" LED matrix.
*
* To use this driver:
*
*     1) You must define (LED.H):
*
*        DISP_N_DIG          The total number of digits to display (up to 8)
*        DISP_N_SS           The total number of seven-segment digits in the display (up to 8)
*        DISP_PORT_DIG       The address of the DIGITS   output port
*        DISP_PORT_SEG       The address of the SEGMENTS output port
*
*     2) You must allocate a hardware timer which will interrupt the CPU at a rate of at least:
*
*        DISP_N_DIG * 60  (Hz)
*
*        The timer interrupt must vector to DispMuxISR (defined in LED_IA.ASM).  You MUST write the
*        code to clear the interrupt source.  The interrupt source must be cleared either in DispMuxISR
*        or in DispMuxHandler().
*
*     3) Adapt DispInitPort(), DispOutSeg() and DispOutDig() for your environment.
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
*                                            LOCAL VARIABLES
*********************************************************************************************************
*/

static   INT8U  DispDigMsk;                 /* Bit mask used to point to next digit to display         */
static   INT8U  DispSegTbl[DISP_N_DIG];     /* Segment pattern table for each digit to display         */
static   INT8U  DispSegTblIx;               /* Index into DispSegTbl[] for next digit to display       */

/*$PAGE*/
/*
*********************************************************************************************************
*                             ASCII to SEVEN-SEGMENT conversion table
*                                                             a
*                                                           ------
*                                                        f |      | b
*                                                          |  g   |
* Note: The segments are mapped as follows:                 ------
*                                                        e |      | c
*        a    b    c    d    e    f    g                   |  d   |
*        --   --   --   --   --   --   --   --              ------
*        B7   B6   B5   B4   B3   B2   B1   B0
*********************************************************************************************************
*/

const INT8U DispASCIItoSegTbl[] = {    /* ASCII to SEVEN-SEGMENT conversion table                      */
    0x00,                              /* ' '                                                          */
    0x00,                              /* '!', No seven-segment conversion for exclamation point       */
    0x44,                              /* '"', Double quote                                            */
    0x00,                              /* '#', Pound sign                                              */
    0x00,                              /* '$', No seven-segment conversion for dollar sign             */
    0x00,                              /* '%', No seven-segment conversion for percent sign            */
    0x00,                              /* '&', No seven-segment conversion for ampersand               */
    0x40,                              /* ''', Single quote                                            */
    0x9C,                              /* '(', Same as '['                                             */
    0xF0,                              /* ')', Same as ']'                                             */
    0x00,                              /* '*', No seven-segment conversion for asterix                 */
    0x00,                              /* '+', No seven-segment conversion for plus sign               */
    0x00,                              /* ',', No seven-segment conversion for comma                   */
    0x02,                              /* '-', Minus sign                                              */
    0x00,                              /* '.', No seven-segment conversion for period                  */
    0x00,                              /* '/', No seven-segment conversion for slash                   */
    0xFC,                              /* '0'                                                          */
    0x60,                              /* '1'                                                          */
    0xDA,                              /* '2'                                                          */
    0xF2,                              /* '3'                                                          */
    0x66,                              /* '4'                                                          */
    0xB6,                              /* '5'                                                          */
    0xBE,                              /* '6'                                                          */
    0xE0,                              /* '7'                                                          */
    0xFE,                              /* '8'                                                          */
    0xF6,                              /* '9'                                                          */
    0x00,                              /* ':', No seven-segment conversion for colon                   */
    0x00,                              /* ';', No seven-segment conversion for semi-colon              */
    0x00,                              /* '<', No seven-segment conversion for less-than sign          */
    0x12,                              /* '=', Equal sign                                              */
    0x00,                              /* '>', No seven-segment conversion for greater-than sign       */
    0xCA,                              /* '?', Question mark                                           */
    0x00,                              /* '@', No seven-segment conversion for commercial at-sign      */
/*$PAGE*/
    0xEE,                              /* 'A'                                                          */
    0x3E,                              /* 'B', Actually displayed as 'b'                               */
    0x9C,                              /* 'C'                                                          */
    0x7A,                              /* 'D', Actually displayed as 'd'                               */
    0x9E,                              /* 'E'                                                          */
    0x8E,                              /* 'F'                                                          */
    0xBC,                              /* 'G', Actually displayed as 'g'                               */
    0x6E,                              /* 'H'                                                          */
    0x60,                              /* 'I', Same as '1'                                             */
    0x78,                              /* 'J'                                                          */
    0x00,                              /* 'K', No seven-segment conversion                             */
    0x1C,                              /* 'L'                                                          */
    0x00,                              /* 'M', No seven-segment conversion                             */
    0x2A,                              /* 'N', Actually displayed as 'n'                               */
    0xFC,                              /* 'O', Same as '0'                                             */
    0xCE,                              /* 'P'                                                          */
    0x00,                              /* 'Q', No seven-segment conversion                             */
    0x0A,                              /* 'R', Actually displayed as 'r'                               */
    0xB6,                              /* 'S', Same as '5'                                             */
    0x1E,                              /* 'T', Actually displayed as 't'                               */
    0x7C,                              /* 'U'                                                          */
    0x00,                              /* 'V', No seven-segment conversion                             */
    0x00,                              /* 'W', No seven-segment conversion                             */
    0x00,                              /* 'X', No seven-segment conversion                             */
    0x76,                              /* 'Y'                                                          */
    0x00,                              /* 'Z', No seven-segment conversion                             */
    0x00,                              /* '['                                                          */
    0x00,                              /* '\', No seven-segment conversion                             */
    0x00,                              /* ']'                                                          */
    0x00,                              /* '^', No seven-segment conversion                             */
    0x00,                              /* '_', Underscore                                              */
    0x00,                              /* '`', No seven-segment conversion for reverse quote           */
    0xFA,                              /* 'a'                                                          */
    0x3E,                              /* 'b'                                                          */
    0x1A,                              /* 'c'                                                          */
    0x7A,                              /* 'd'                                                          */
    0xDE,                              /* 'e'                                                          */
    0x8E,                              /* 'f', Actually displayed as 'F'                               */
    0xBC,                              /* 'g'                                                          */
    0x2E,                              /* 'h'                                                          */
    0x20,                              /* 'i'                                                          */
    0x78,                              /* 'j', Actually displayed as 'J'                               */
    0x00,                              /* 'k', No seven-segment conversion                             */
    0x1C,                              /* 'l', Actually displayed as 'L'                               */
    0x00,                              /* 'm', No seven-segment conversion                             */
    0x2A,                              /* 'n'                                                          */
    0x3A,                              /* 'o'                                                          */
    0xCE,                              /* 'p', Actually displayed as 'P'                               */
    0x00,                              /* 'q', No seven-segment conversion                             */
    0x0A,                              /* 'r'                                                          */
    0xB6,                              /* 's', Actually displayed as 'S'                               */
    0x1E,                              /* 't'                                                          */
    0x38,                              /* 'u'                                                          */
    0x00,                              /* 'v', No seven-segment conversion                             */
    0x00,                              /* 'w', No seven-segment conversion                             */
    0x00,                              /* 'x', No seven-segment conversion                             */
    0x76,                              /* 'y', Actually displayed as 'Y'                               */
    0x00                               /* 'z', No seven-segment conversion                             */
};

/*$PAGE*/
/*
*********************************************************************************************************
*                             HEXADECIMAL to SEVEN-SEGMENT conversion table
*                                                             a
*                                                           ------
*                                                        f |      | b
*                                                          |  g   |
* Note: The segments are mapped as follows:                 ------
*                                                        e |      | c
*        a    b    c    d    e    f    g                   |  d   |
*        --   --   --   --   --   --   --   --              ------
*        B7   B6   B5   B4   B3   B2   B1   B0
*********************************************************************************************************
*/

const INT8U DispHexToSegTbl[] = {      /* HEXADECIMAL to SEVEN-SEGMENT conversion table                */
    0xFC,                              /* '0'                                                          */
    0x60,                              /* '1'                                                          */
    0xDA,                              /* '2'                                                          */
    0xF2,                              /* '3'                                                          */
    0x66,                              /* '4'                                                          */
    0xB6,                              /* '5'                                                          */
    0xBE,                              /* '6'                                                          */
    0xE0,                              /* '7'                                                          */
    0xFE,                              /* '8'                                                          */
    0xF6,                              /* '9'                                                          */
    0xEE,                              /* 'A'                                                          */
    0x3E,                              /* 'B', Actually displayed as 'b'                               */
    0x9C,                              /* 'C'                                                          */
    0x7A,                              /* 'D', Actually displayed as 'd'                               */
    0x9E,                              /* 'E'                                                          */
    0x8E                               /* 'F'                                                          */
};

/*$PAGE*/
/*
*********************************************************************************************************
*                                          CLEAR THE DISPLAY
*
* Description: This function is called to clear the display.
* Arguments  : none
* Returns    : none
*********************************************************************************************************
*/

void  DispClrScr (void)
{
    INT8U i;


    for (i = 0; i < DISP_N_DIG; i++) {           /* Clear the screen by turning OFF all segments       */
        OS_ENTER_CRITICAL();
        DispSegTbl[i] = 0x00;
        OS_EXIT_CRITICAL();
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                      DISPLAY DRIVER INITIALIZATION
*
* Description : This function initializes the display driver.
* Arguments   : None.
* Returns     : None.
*********************************************************************************************************
*/

void  DispInit (void)
{
    DispInitPort();                    /* Initialize I/O ports used in display driver                  */
    DispDigMsk   = 0x80;
    DispSegTblIx = 0;
    DispClrScr();                      /* Clear the Display                                            */
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                        DISPLAY NEXT SEVEN-SEGMENT DIGIT
*
* Description: This function is called by DispMuxISR() to output the segments and select the next digit
*              to be multiplexed.  DispMuxHandler() is called by DispMuxISR() defined in LED_IA.ASM
* Arguments  : none
* Returns    : none
* Notes      : - You MUST supply the code to clear the interrupt source.  Note that with some
*                microprocessors (i.e. Motorola's MC68HC11), you must clear the interrupt source before
*                enabling interrupts.
*********************************************************************************************************
*/

void  DispMuxHandler (void)
{
                                                 /* Insert code to CLEAR INTERRUPT SOURCE here         */

    DispOutSeg(0x00);                            /* Turn OFF segments while changing digits            */
    DispOutDig(DispDigMsk);                      /* Select next digit to display                       */
    DispOutSeg(DispSegTbl[DispSegTblIx]);        /* Output digit's seven-segment pattern               */
    if (DispSegTblIx == (DISP_N_DIG - 1)) {      /* Adjust index to next seven-segment pattern         */
        DispSegTblIx =    0;                     /* Index into first segments pattern                  */
        DispDigMsk   = 0x80;                     /* 0x80 will select the first seven-segment digit     */
    } else {
        DispSegTblIx++;
        DispDigMsk >>= 1;                        /* Select next digit                                  */
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                         CLEAR STATUS SEGMENT
*
* Description: This function is called to turn OFF a single segment on the display.
* Arguments  : dig   is the position of the digit where the segment appears (0..DISP_N_DIG-1)
*              bit   is the segment bit to turn OFF (0..7)
* Returns    : none
*********************************************************************************************************
*/

void  DispStatClr (INT8U dig, INT8U bit)
{
    OS_ENTER_CRITICAL();
    DispSegTbl[dig] &= ~(1 << bit);
    OS_EXIT_CRITICAL();
}


/*
*********************************************************************************************************
*                                           SET STATUS SEGMENT
*
* Description: This function is called to turn ON a single segment on the display.
* Arguments  : dig   is the position of the digit where the segment appears (0..DISP_N_DIG-1)
*              bit   is the segment bit to turn ON (0..7)
* Returns    : none
*********************************************************************************************************
*/

void  DispStatSet (INT8U dig, INT8U bit)
{
    OS_ENTER_CRITICAL();
    DispSegTbl[dig] |= 1 << bit;
    OS_EXIT_CRITICAL();
}

/*$PAGE*/
/*
*********************************************************************************************************
*                            DISPLAY ASCII STRING ON SEVEN-SEGMENT DISPLAY
*
* Description: This function is called to display an ASCII string on the seven-segment display.
* Arguments  : dig   is the position of the first digit where the string will appear:
*                        0 for the first  seven-segment digit.
*                        1 for the second seven-segment digit.
*                        .  .   .     .     .      .      .
*                        .  .   .     .     .      .      .
*                        DISP_N_SS - 1 is the last seven-segment digit.
*              s     is the ASCII string to display
* Returns    : none
* Notes      : - Not all ASCII characters can be displayed on a seven-segment display.  Consult the
*                ASCII to seven-segment conversion table DispASCIItoSegTbl[].
*********************************************************************************************************
*/

void  DispStr (INT8U dig, char *s)
{
    INT8U stat;


    while (*s && dig < DISP_N_SS) {
        OS_ENTER_CRITICAL();
        stat              = DispSegTbl[dig] & 0x01;                  /* Save state of B0 (i.e. status) */
        DispSegTbl[dig++] = DispASCIItoSegTbl[*s++ - 0x20] | stat;
        OS_EXIT_CRITICAL();
    }
}

/*$PAGE*/
#ifndef CFG_C
/*
*********************************************************************************************************
*                                        I/O PORTS INITIALIZATION
*
* Description: This is called by DispInit() to initialize the output ports used in the LED multiplexing.
* Arguments  : none
* Returns    : none
* Notes      : 74HC573  8 bit latches are used for both the segments and digits outputs.
*********************************************************************************************************
*/

void  DispInitPort (void)
{
    outp(DISP_PORT_SEG, 0x00);              /* Turn OFF segments                                       */
    outp(DISP_PORT_DIG, 0x00);              /* Turn OFF digits                                         */
}


/*
*********************************************************************************************************
*                                        DIGIT output
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


/*
*********************************************************************************************************
*                                        SEGMENTS output
*
* Description: This function outputs seven-segment patterns.
* Arguments  : seg    is the seven-segment pattern to output
* Returns    : none
*********************************************************************************************************
*/

void  DispOutSeg (INT8U seg)
{
    outp(DISP_PORT_SEG, seg);
}
#endif
