/*
*********************************************************************************************************
*                                               uC/LCD
*                                         LCD Module Driver
*
*                              (c) Copyright 2005; Micrium; Weston, FL
*
*                   All rights reserved.  Protected by international copyright laws.
*                   Knowledge of the source code may not be used to write a similar
*                   product.  This file may only be used in accordance with a license
*                   and should not be redistributed in any way.
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                 LCD MODULE RTOS INTERFACE SOURCE FILE
*
* Filename      : lcd_os.c
* Programmer(s) :
* Version       :
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                              INCLUDE FILES
*********************************************************************************************************
*/

#include "includes.h"

/*
*********************************************************************************************************
*                                              VARIABLES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                       INITIALIZE RTOS SERVICES
*
* Description : This function creates a semaphore to ensure exclusive access to the LCD module and thus
*               provide thread safe access to the display.
*
* Arguments   : none
*
* Returns     : none
*********************************************************************************************************
*/

void  DispInitOS (void)
{

}

/*
*********************************************************************************************************
*                              EXCLUSIVE ACCESS FUNCTIONS TO THE DISPLAY
*
* Description : These functions are used to gain and release exclusive access to the LCD display.
*
* Arguments   : none
*
* Returns     : none
*********************************************************************************************************
*/

void  DispLock (void)
{

}



void  DispUnlock (void)
{

}
