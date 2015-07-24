/*------------------------------------------------------------------*-

   2_01_24h.C (v1.00) 

  ------------------------------------------------------------------

   *** THIS IS A *HYBRID* SCHEDULER FOR STANDARD 8051 / 8052 ***

   *** Uses T2 for timing, 16-bit auto reload ***
   *** 24 MHz oscillator -> 1 ms (precise) tick interval ***


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "2_01_24h.h"

// ------ Public variable declarations -----------------------------

// The array of tasks (see Sch51.C)
extern sTaskH hSCH_tasks_G[hSCH_MAX_TASKS];

// Used to display the error code
// See Main.H for details of error codes
// See Port.H for details of the error port
extern tByte Error_code_G;

/*------------------------------------------------------------------*-

  hSCH_Init_T2()

  Scheduler initialisation function.  Prepares scheduler
  data structures and sets up timer interrupts at required rate.

  You must call this function before using the scheduler.  

-*------------------------------------------------------------------*/
void hSCH_Init_T2(void) 
   {
   tByte i;

   for (i = 0; i < hSCH_MAX_TASKS; i++) 
      {
      hSCH_Delete_Task(i);
      }

   // Reset the global error variable
   // - hSCH_Delete_Task() will generate an error code, 
   //   (because the task array is empty)
   Error_code_G = 0;  

   // Now set up Timer 2
   // 16-bit timer function with automatic reload

   // Crystal is assumed to be 24 MHz
   // The Timer 2 resolution is 0.0000005 seconds (0.5 µs)
   // The required Timer 2 overflow is 0.001 seconds (1 ms)
   // - this takes 2000 timer ticks
   // Reload value is 65536 - 2000 = 63536 (dec) = 0xF830

   T2CON = 0x04;   // load Timer 2 control register
   T2MOD = 0x00;   // load Timer 2 mode register

   TH2    = 0xF8;  // load timer 2 high byte
   RCAP2H = 0xF8;  // load timer 2 reload capture reg, high byte
   TL2    = 0x30;  // load timer 2 low byte
   RCAP2L = 0x30;  // load timer 2 reload capture reg, low byte
   
   ET2   = 1;  // Timer 2 interrupt is enabled

   TR2   = 1;  // Start Timer 2
   }


/*------------------------------------------------------------------*-

  hSCH_Start()

  Starts the scheduler, by enabling interrupts.

  NOTE: Usually called after all regular tasks are added,
  to keep the tasks synchronised.

  NOTE: ONLY THE SCHEDULER INTERRUPT SHOULD BE ENABLED!!! 

-*------------------------------------------------------------------*/
void hSCH_Start(void) 
   {
   EA = 1;
   }

/*------------------------------------------------------------------*-

  hSCH_Update

  This is the scheduler ISR.  It is called at a rate 
  determined by the timer settings in hSCH_Init().
  This version is triggered by Timer 2 interrupts:
  timer is automatically reloaded.
 
 -*------------------------------------------------------------------*/
void hSCH_Update(void) interrupt INTERRUPT_Timer_2_Overflow  
   {
   tByte Index;

   TF2 = 0; // Have to manually clear this. 

   // NOTE: calculations are in *TICKS* (not milliseconds)
   for (Index = 0; Index < hSCH_MAX_TASKS; Index++)
      {
      // Check if there is a task at this location
      if (hSCH_tasks_G[Index].pTask)
         {
         if (hSCH_tasks_G[Index].Delay == 0)
            {
            // The task is due to run
            // 
            if (hSCH_tasks_G[Index].Co_op)
               {
               // If it is a co-operative task, increment the RunMe flag
               hSCH_tasks_G[Index].RunMe += 1;  
               }
            else
               {
               // If it is a pre-emptive task, run it IMMEDIATELY
               (*hSCH_tasks_G[Index].pTask)();  // Run the task

               hSCH_tasks_G[Index].RunMe -= 1;   // Reset / reduce RunMe flag

               // Periodic tasks will be scheduled again (see below)
               // - if this is a 'one shot' task, remove it from the array
               if (hSCH_tasks_G[Index].Period == 0)
                  {
                  hSCH_tasks_G[Index].pTask  = 0;
                  }
               }

            if (hSCH_tasks_G[Index].Period)
               {
               // Schedule this periodic task to run again
               hSCH_tasks_G[Index].Delay = hSCH_tasks_G[Index].Period;
               }
            }
         else
            {
            // Not yet ready to run: just decrement the delay 
            hSCH_tasks_G[Index].Delay -= 1;
            }
         }         
      }
   }   


/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
