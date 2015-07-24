/*------------------------------------------------------------------*-

   Main.c (v1.00)

  ------------------------------------------------------------------
 
   Demo program for MULTI-STATE SWITCH pattern.
   - see Chapter 19 for details.

   Required linker options (see Chapter 14 for details):

   OVERLAY (main ~ (SWITCH_MS_Update, COUNTER_Update), 
   SCH_Dispatch_Tasks ! (SWITCH_MS_Update, COUNTER_Update))

   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"

#include "Swit_D.h"
#include "2_01_12g.H"
#include "Counter.h"
#include "Bargraph.h"

/* ............................................................... */
/* ............................................................... */

void main(void)
   {
   // Set up the scheduler 
   SCH_Init_T2();

   // Set up the display
   BARGRAPH_Init();

   // Set up the switch pin
   SWITCH_MS_Init();

   // Add a 'SWITCH_MS_Update' task, every ~200 ms
   // - timings are in ticks (50 ms tick interval - see Sch 'init' function)
   SCH_Add_Task(SWITCH_MS_Update, 0, 4);

   // Add a 'COUNTER_Update' task every ~1000 ms
   SCH_Add_Task(COUNTER_Update, 0, 20);

   SCH_Start();

   while(1)
      {
      SCH_Dispatch_Tasks();
      }
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
