/*------------------------------------------------------------------*-

   2_05_12g.C (v1.00) 

  ------------------------------------------------------------------

   *** THIS IS A SCHEDULER FOR STANDARD 8051 / 8052 ***

   *** Uses T2 for timing, 16-bit auto reload ***
   *** 12 MHz oscillator -> 5 ms (precise) tick interval ***


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "2_05_12g.h"

// ------ Public variable declarations -----------------------------

// The array of tasks (see Sch51.C)
extern sTask SCH_tasks_G[SCH_MAX_TASKS];

// Used to display the error code
// See Main.H for details of error codes
// See Port.H for details of the error port
extern tByte Error_code_G;

/*------------------------------------------------------------------*-

  SCH_Init_T2()

  Scheduler initialisation function.  Prepares scheduler
  data structures and sets up timer interrupts at required rate.

  You must call this function before using the scheduler.  

-*------------------------------------------------------------------*/
void SCH_Init_T2(void) 
   {
   tByte i;

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

   // Crystal is assumed to be 12 MHz (12 osc / increment)
   // The Timer 2 resolution is 0.000001 seconds (1 µs)
   // The required Timer 2 overflow is 0.005 seconds (5 ms)
   // - this takes 5000 timer ticks
   // Reload value is 65536 - 5000 = 60536 (dec) = 0xEC78

   T2CON = 0x04;   // load Timer 2 control register
   T2MOD = 0x00;   // load Timer 2 mode register

   TH2    = 0xEC;  // load timer 2 high byte
   RCAP2H = 0xEC;  // load timer 2 reload capture reg, high byte
   TL2    = 0x78;  // load timer 2 low byte
   RCAP2L = 0x78;  // load timer 2 reload capture reg, low byte
   
   ET2   = 1;  // Timer 2 interrupt is enabled

   TR2   = 1;  // Start Timer 2
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
   EA = 1;
   }

/*------------------------------------------------------------------*-

  SCH_Update()

  This is the scheduler ISR.  It is called at a rate 
  determined by the timer settings in the 'init' function.

  This version is triggered by Timer 2 interrupts:
  timer is automatically reloaded.

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
            SCH_tasks_G[Index].RunMe += 1;  // Inc. the 'RunMe' flag

            if (SCH_tasks_G[Index].Period)
               {
               // Schedule periodic tasks to run again
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

