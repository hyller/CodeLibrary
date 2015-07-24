/*------------------------------------------------------------------*-

   Main.c (v1.00)

  ------------------------------------------------------------------

   Demo application for Software Pulse Count (Chapter 30).

   Required linker options (see Chapter 14 for details):

   OVERLAY 
   (main ~ (PC_SOFT_Poll_Count, PC_SOFT_Get_Count, BARGRAPH_Update), 
   SCH_Dispatch_Tasks ! (PC_SOFT_Poll_Count, PC_SOFT_Get_Count, 
   BARGRAPH_Update))


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"

#include "2_01_12g.h"

#include "PulCnt_S.h"
#include "BarGraph.h"

/* ............................................................... */
/* ............................................................... */

void main(void)
   {
   SCH_Init_T2();   // Set up the scheduler
   PC_SOFT_Init();      // Prepare to count pulses
   BARGRAPH_Init(); // Prepare a bargraph-type display (P4)

   // TIMING IS IN TICKS (1 ms interval)

   // Add a 'pulse count poll' task 
   // Every 40 milliseconds
   SCH_Add_Task(PC_SOFT_Poll_Count, 0, 20);

   // Add a 'pulse get count' task 
   // Every 20 seconds
   SCH_Add_Task(PC_SOFT_Get_Count, 0, 20000);

   // Simply display the count here (bargraph display)
   // Max count is ~250
   SCH_Add_Task(BARGRAPH_Update, 50, 10000);

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

