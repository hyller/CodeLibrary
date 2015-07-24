/*------------------------------------------------------------------*-

   Main.c (v1.00)

  ------------------------------------------------------------------
 
   Demonstration program for: 

   Keypad-LCD.

   This version for '8052' / 11.059MHz / 5 ms tick

   Required linker options (see Chapter 14 for details):

   OVERLAY (main ~ (LCD_Update, LCD_KEY_Update), 
   SCH_dispatch_tasks ! (LCD_Update, LCD_KEY_Update)))


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"

#include "2_05_11g.H"
#include "LCD_A.h"
#include "Keypad.h"
#include "LCD_Key.h"

/* ............................................................... */
/* ............................................................... */

void main(void)
   {
   // Prepare for the tasks
   LCD_Init(0);  // 3x!!!
   LCD_Init(0);
   LCD_Init(1);

   KEYPAD_Init();
   LCD_KEY_Init();

   // Set up the scheduler
   SCH_Init_T2();

   // Update the LCD from LCD buffer
   SCH_Add_Task(LCD_Update, 1000, 24);

   // Transfer keypad data to the LCD buffer
   SCH_Add_Task(LCD_KEY_Update, 2000, 50);

   // Start the scheduler
   SCH_Start();

   while(1)
      {
      SCH_Dispatch_Tasks();
      }
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
