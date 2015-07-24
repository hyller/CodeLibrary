/*------------------------------------------------------------------*-

   Main.C (v1.00)

  ------------------------------------------------------------------

   Framework for washing-machine controller (multi-state task).

   Required linker options (see Chapter 14 for details):

   OVERLAY (main ~ (WASHER_Update), 
   SCH_dispatch_tasks ! (WASHER_Update))
   

   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.H"
#include "Washer.H"
#include "2_01_12g.h" 

/* ............................................................... */

void main(void)
   {
   // Set up the scheduler
   SCH_Init_T2();

   // Prepare for the 'WASHER_Update' task
   WASHER_Init();

   // Add the 'WASHER_Update' task 
   // - timings are in ticks (1 ms tick interval)
   SCH_Add_Task(WASHER_Update, 0, 1000);

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
