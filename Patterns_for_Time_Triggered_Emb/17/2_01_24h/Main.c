/*------------------------------------------------------------------*-

   Main.c (v1.00)

  ------------------------------------------------------------------
 
   Demonstration program for:

   /// HYBRID SCHEDULER ///

   Generic 16-bit auto-reload hybrid scheduler (using T2).

   Assumes 24 MHz oscillator (-> 01 ms tick interval).

   *** All timing is in TICKS (not milliseconds) ***


   Required linker options (see Chapter 14 for details):

   OVERLAY (main ~ (LED_Short_Update, LED_Long_Update),
   hSCH_dispatch_tasks ! (LED_Short_Update, LED_Long_Update))


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"
#include "2_01_24h.h" 
#include "LED_Hyb.h"

/* ............................................................... */
/* ............................................................... */

void main(void)
   {
   // Set up the scheduler
   hSCH_Init_T2();

   LED_Short_Init();

   // Add the 'short' task (on for ~1000 ms, off for ~1000 ms)
   // THIS IS A PRE-EMPTIVE TASK
   hSCH_Add_Task(LED_Short_Update, 0, 1000, 0);

   // Add the 'long' task (duration 10 seconds)
   // THIS IS A CO-OPERATIVE TASK
   hSCH_Add_Task(LED_Long_Update, 0, 20000, 1);

   // Start the scheduler
   hSCH_Start();

   while(1)
      {
      hSCH_Dispatch_Tasks();
      }
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
