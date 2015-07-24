/*------------------------------------------------------------------*-

   Main.c (v1.00)

  ------------------------------------------------------------------
 
   Demonstration program for:

   Generic 16-bit manual-reload scheduler (using T0).

   Assumes 12 MHz oscillator (-> 01 ms tick interval).

   *** All timing is in TICKS (not milliseconds) ***


   Required linker options (see Chapter 14 for details):

   OVERLAY (main ~ (LED_Flash_Update), 
   SCH_dispatch_tasks ! (LED_Flash_Update))


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"  

#include "1_01_12g.h"
#include "LED_Flas.h"

/* ............................................................... */
/* ............................................................... */

void main(void)
   {
   // Set up the scheduler
   SCH_Init_T1();

   // Prepare for the 'Flash_LED' task
   LED_Flash_Init();

   // Add the 'Flash LED' task (on for ~1000 ms, off for ~1000 ms)
   // - timings are in ticks (1 ms tick interval)
   // (Max interval / delay is 65535 ticks)
   SCH_Add_Task(LED_Flash_Update, 0, 1000);

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

