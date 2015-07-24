/*------------------------------------------------------------------*-

   Main.c (v1.00)

  ------------------------------------------------------------------

   Framework for traffic-light controller (multi-state task).
 
   Required linker options (see text for details):

   OVERLAY (main ~ (TRAFFIC_LIGHTS_Update), 
   SCH_Dispatch_Tasks ! (TRAFFIC_LIGHTS_Update))


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
#include "T_lights.h"

/* ................................................................. */
/* ................................................................. */

void main(void)
   {
   // Set up the scheduler 
   SCH_Init_T2();

   // Prepare for the traffic light task
   TRAFFIC_LIGHTS_Init(RED);

   // Add a 'traffic light' task
   SCH_Add_Task(TRAFFIC_LIGHTS_Update, 30, 1000);
   
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
