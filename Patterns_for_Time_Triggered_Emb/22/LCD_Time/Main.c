/*------------------------------------------------------------------*-

   Main.c (v1.00)

  ------------------------------------------------------------------
   
   TEST PROGRAM FOR LCD LIBRARY CODE

   * Designed for 2-line x 20-character HD44780-based display 
   * '4-BIT' INTERFACE (uses 6 pins...) 
   * Requires T0 (for delays and timeouts) 

   Required linker options (see Chapter 14 for details):

   OVERLAY (main ~ (Elapsed_Time_LCD_Update,LCD_Update), 
   Sch_Dispatch_Tasks ! (Elapsed_Time_LCD_Update,LCD_Update))


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"
#include "LCD_A.h"
#include "2_01_12g.h"
#include "Elap_LCD.h"

/* ............................................................... */
void main(void)
   {
   // Initialisation can be problematic with some display / supply
   // combinations.  You may get away with calling this function
   // twice (or once) but - for maximum reliability under a very wide range 
   // of conditions - it is called three times here.
   LCD_Init(0);
   LCD_Init(0);
   LCD_Init(1);

   // Prepare the elapsed time library
   Elapsed_Time_LCD_Init();

   // Prepare the scheduler
   SCH_Init_T2();

   // Add tasks to the scheduler
   //
   // Update the time every second (*** 1ms sched ticks ***)
   SCH_Add_Task(Elapsed_Time_LCD_Update, 100, 1000);

   // Update the whole display ~ every second 
   // - do this by updating a character once every 24 ms
   // (assumes a 40 character display)
   SCH_Add_Task(LCD_Update, 1000, 24);

   // All tasks added: start running the scheduler
   SCH_Start();   

   while(1)
      {
      SCH_Dispatch_Tasks();
      }
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/

