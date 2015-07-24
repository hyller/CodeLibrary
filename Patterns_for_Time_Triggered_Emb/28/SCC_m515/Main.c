/*------------------------------------------------------------------*-

   Main.c (v1.00)

  ------------------------------------------------------------------
 
   DEMO PROGRAM FOR CAN SHARED-CLOCK SCHEDULER - Master

   Required linker options (see Chapter 14 for details):

   OVERLAY (main ~ (LED_Flash_Update,TRAFFIC_LIGHTS_Update), 
   SCH_Dispatch_Tasks ! (LED_Flash_Update,TRAFFIC_LIGHTS_Update))


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"

#include "LED_Flas.h"
#include "SCC_M515.H"
#include "TLight_B.h"

/* ............................................................... */
/* ............................................................... */

void main(void)
   {
   // Prepare for the traffic light task
   TRAFFIC_LIGHTS_Init();

   // Set up the scheduler 
   SCC_A_MASTER_Init_T2_CAN();

   // Set up the flash LED task
   LED_Flash_Init();

   // TIMING IS IN TICKS (6 ms tick interval)
   // Add a 'flash LED' task (on for 1002 ms, off for 1002 ms)
   SCH_Add_Task(LED_Flash_Update, 0, 167);

   // Add the traffic-light task
   SCH_Add_Task(TRAFFIC_LIGHTS_Update, 30, 167);
   
   // Start the scheduler
   SCC_A_MASTER_Start();

   while(1)
      {
      SCH_Dispatch_Tasks();
      }
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
