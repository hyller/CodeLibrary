/*------------------------------------------------------------------*-

   Main.c (v1.00)

  ------------------------------------------------------------------
 
   Demonstration program for:

   Stable Scheduler (see Chapter 37)

   Drives 4 multiplexed multi-segment LED displays
   - displays elapsed time.

   Required linker options (see Chapter 14 for details):

   OVERLAY 
   (main ~ (CLOCK_LED_Time_Update,LED_MX4_Display_Update,
   SCH_Calculate_Ave_Temp_DS1621), 
   SCH_dispatch_tasks !(CLOCK_LED_Time_Update,LED_MX4_Display_Update,
   SCH_Calculate_Ave_Temp_DS1621))


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"

#include "2_01_12s.h" 
#include "LED_Mx4.h"
#include "Cloc_Mx4.h"
#include "I2C_1621.h"


/* ............................................................... */
/* ............................................................... */

void main(void)
   {
   // Set up the scheduler
   SCH_Init_T2();

   // Prepare for temperature measurements
   I2C_Init_Temperature_DS1621();

   // Add the 'Time Update' task (once per second)
   // - timings are in ticks (1 ms tick interval)
   // (Max interval / delay is 65535 ticks)
   SCH_Add_Task(CLOCK_LED_Time_Update,100,10);

   // Add the 'Display Update' task (once per second)
   // Need to update a 4-segment display every 3 ms (approx)
   // Need to update a 2-segment display every 6 ms (approx)
   SCH_Add_Task(LED_MX4_Display_Update,0,3);

   // This is scheduled once per minute
   SCH_Add_Task(SCH_Calculate_Ave_Temp_DS1621,33,60000);

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
