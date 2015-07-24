/*------------------------------------------------------------------*-

   2_06_10i.c (v1.00)

  ------------------------------------------------------------------

   *** THIS IS A SCHEDULER FOR 80C515C (etc.) ***
   *** For use in single-processor applications  ***

   *** Uses T2 for timing, 16-bit auto reload ***

   *** This version assumes 10 MHz crystal on 515c ***
   *** 6 ms tick interval ***

   *** Includes display of error codes ***


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"
#include "2_06_10i.H"

// ------ Public variable declarations -----------------------------

// The array of tasks (see Sch51.C)
extern sTask SCH_tasks_G[SCH_MAX_TASKS];

// Used to display the error code
// See Main.H for details of error codes
// See Port.H for details of the error port
extern tByte Error_code_G;

/*------------------------------------------------------------------*-

  SCH_Init_T2()

  Scheduler initialisation function.  Prepares scheduler data 
  structures and sets up timer interrupts at required rate.
  Must call this function before using the scheduler.  

-*------------------------------------------------------------------*/
void SCH_Init_T2(void) 
   {
   tByte i;

   // Sort out the tasks
   for (i = 0; i < SCH_MAX_TASKS; i++) 
      {
      SCH_Delete_Task(i);
      }

   // Reset the global error variable
   // - SCH_Delete_Task() will generate an error code, 
   //   (because the task array is empty)
   Error_code_G = 0;

   // Now set up Timer 2
   // 16-bit timer function with automatic reload
   // Crystal is assumed to be 10 MHz
   // Using c515c, so timer can be incremented at 1/6 crystal frequency
   // if prescalar is not used

   // Prescaler not used -> Crystal/6
   T2PS = 0;

   // The Timer 2 resolution is  0.0000006 seconds (0.6 µs)
   // The required Timer 2 overflow is 0.006 seconds (6 ms)
   // - this takes  10000 timer ticks 
   // Reload value is 65536 - 10000 = 64536 (dec) = 0xD8F0
   TH2 = 0xD8; 
   TL2 = 0xF0;
     
   // Compare/capture Channel 0 
   // Disabled
   // Compare Register CRC on: 0x0000;
   CRCH = 0xD8;
   CRCL = 0xF0;

   //  Mode 0 for all channels
   T2CON |= 0x11;

   //  timer 2 overflow interrupt is enabled
   ET2 = 1;
   //  timer 2 external reload interrupt is disabled
   EXEN2 = 0;
  
   //  CC0/ext3 interrupt is disabled
   EX3 = 0;
  
   // Compare/capture Channel 1-3 
   // Disabled
   CCL1 = 0x00;
   CCH1 = 0x00;
   CCL2 = 0x00;
   CCH2 = 0x00;
   CCL3 = 0x00;
   CCH3 = 0x00;
  
   // Interrupts Channel 1-3 
   // Disabled
   EX4 = 0;
   EX5 = 0;
   EX6 = 0;
  
   // all above mentioned modes for Channel 0 to Channel 3 
   CCEN = 0x00;
   // ------ Set up Timer 2 (end) ----------------------------------
   }

/*------------------------------------------------------------------*-

  SCH_Start()

  Starts the scheduler, by enabling interrupts.

  NOTE: Usually called after all regular tasks are added,
  to keep the tasks synchronised.

  NOTE: ONLY THE SCHEDULER INTERRUPT SHOULD BE ENABLED!!! 
 
-*------------------------------------------------------------------*/
void SCH_Start(void) 
   {
   // Comment out as required, depending on compiler used
   //EA = 1;   // Use with C51 v5.X
   EAL = 1;  // Use with C51 v6.X
   }

/*------------------------------------------------------------------*-
  
  SCH_Update()

  This is the scheduler ISR.  It is called at a rate determined by 
  the timer settings in SCH_Init_T2().  This version is 
  triggered by Timer 2 interrupts: timer is automatically reloaded.
 
-*------------------------------------------------------------------*/
void SCH_Update(void) interrupt INTERRUPT_Timer_2_Overflow  
   {
   tByte Index;

   TF2 = 0; // Have to manually clear this. 

   // NOTE: calculations are in *TICKS* (not milliseconds)
   for (Index = 0; Index < SCH_MAX_TASKS; Index++)
      {
      // Check if there is a task at this location
      if (SCH_tasks_G[Index].pTask)
         {
         if (SCH_tasks_G[Index].Delay == 0)
            {
            // The task is due to run
            SCH_tasks_G[Index].RunMe += 1;  // Incr. the run flag

            if (SCH_tasks_G[Index].Period)
               {
               // Schedule period tasks to run again
               SCH_tasks_G[Index].Delay = SCH_tasks_G[Index].Period;
               }
            }
         else
            {
            // Not yet ready to run: just decrement the delay 
            SCH_tasks_G[Index].Delay -= 1;
            }
         }         
      }
   }   

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/


