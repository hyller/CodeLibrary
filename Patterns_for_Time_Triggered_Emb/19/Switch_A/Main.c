/*------------------------------------------------------------------*-

   Main.c (v1.00)

  ------------------------------------------------------------------
 
   Demo program for SWITCH INTERFACE (SOFTWARE) pattern.

   12MHz oscillator, Standard 8051/52 (12 osc / machine cycle)
   1 ms tick interval.

   Required linker options (see Chapter 14 for details):

   OVERLAY (main ~ (SWITCH_Update, LED_Flash_Switch_Update), 
   SCH_Dispatch_Tasks ! (SWITCH_Update,LED_Flash_Switch_Update))


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"
#include "Swit_A.h"
#include "0_01_12g.H"
#include "LED_Swit.h"

/* ............................................................... */
/* ............................................................... */

void main(void)
   {
   // Set up the scheduler 
   SCH_Init_T0();

   // Set up the switch pin
   SWITCH_Init();

   // Prepare for the 'Flash_LED' task
   LED_Flash_Switch_Init();

   // Add a 'SWITCH_Update' task, every ~200 ms.
   // Scheduler timings is in ticks. 
   // [1 ms tick interval - see Sch 'init' function]
   SCH_Add_Task(SWITCH_Update, 0, 200);

   // Add LED task
   // Here, LED will only flash while switch is pressed...
   SCH_Add_Task(LED_Flash_Switch_Update, 5, 1000);

   SCH_Start();

   while(1)
      {
      SCH_Dispatch_Tasks();
      }
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
