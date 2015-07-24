/*------------------------------------------------------------------*-

   Main.c (v1.00)

  ------------------------------------------------------------------

   Demo application for Hardware Pulse Count (Chapter 30).

   Required linker options (see Chapter 14 for details):

   OVERLAY 
   (main ~ (PC_HARD_Get_Count_T0, BARGRAPH_Update), 
   SCH_Dispatch_Tasks ! (PC_HARD_Get_Count_T0, BARGRAPH_Update))


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

#include "PulCnt_H.h"
#include "BarGraph.h"

/* ............................................................... */
/* ............................................................... */

void main(void)
   {
   SCH_Init_T2();      // Set up the scheduler
   PC_HARD_Init_T0();      // Prepare to count pulses
   BARGRAPH_Init();    // Prepare a bargraph-type display 

   // Add a 'pulse count' task 
   SCH_Add_Task(PC_HARD_Get_Count_T0, 1000, 1000);

   // Simply display the count here (bargraph display)
   SCH_Add_Task(BARGRAPH_Update, 1200, 1000);

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

