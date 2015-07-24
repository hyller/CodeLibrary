/*------------------------------------------------------------------*-

   Main.c (v1.00)

  ------------------------------------------------------------------

   Demo program for ADC -> Bargraph display


   Required linker options (see Chapter 14 for details):

   OVERLAY 
   (main ~ (ADC_Max150_Get_Sample,BARGRAPH_Update), 
   sch_dispatch_tasks ! (ADC_Max150_Get_Sample,BARGRAPH_Update))


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
#include "ADC_m150.h"
#include "BarGraph.h"

/* ............................................................... */
/* ............................................................... */

void main(void)
   {
   SCH_Init_T2();      // Set up the scheduler
   ADC_Max150_Init();  // Prepare the ADC
   BARGRAPH_Init();    // Prepare a bargraph-type display (P4)

   // Read the ADC regularly  
   SCH_Add_Task(ADC_Max150_Get_Sample, 10, 1000);

   // Simply display the count here (bargraph display)
   SCH_Add_Task(BARGRAPH_Update, 12, 1000);

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

