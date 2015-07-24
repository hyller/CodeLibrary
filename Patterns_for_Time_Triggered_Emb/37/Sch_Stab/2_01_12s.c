/*------------------------------------------------------------------*-

   2_01_12s.C (v1.00) 

  ------------------------------------------------------------------

   *** THIS IS A STABLE SCHEDULER FOR STANDARD 8051 / 8052 ***

   *** Uses T2 for timing, 16-bit auto reload ***
   *** 12 MHz oscillator -> 1 ms (precise) tick interval ***

   *** Assumes DS1621 temperature sensor available ***


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2000 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "2_01_12s.h"
#include "I2C_1621.h"

// ------ Public variable definitions ------------------------------

// The current temperature, recorded every hour
tByte Temperature_G;

// ------ Public variable declarations -----------------------------

// The array of tasks (see Sch51.C)
extern sTask SCH_tasks_G[SCH_MAX_TASKS];

// The error code variable
//
// See Port.H for port on which error codes are displayed
// and for details of error codes
extern tByte Error_code_G;

// Running total / average temperature (calculated every 24 hours)
static int Temperature_average_G = 0;

// Called every minute: only take reading once an hour
// (calling every hour requires changes to scheduler,
// increasing the required memory for EVERY task).
static tByte Minute_G;
static tByte Hour_G;

// The temperature compensation data
// 
// The Timer 2 reload values (low and high bytes) are varied depending 
// on the current average temperature.
// 
// NOTE (1):
// Only temperature values from 10 - 30 celsius are considered 
// in this version
//
// NOTE (2):
// Adjust these values to match your hardware!
tByte code T2_reload_L[21] = 
           // 10   11   12   13   14   15   16   17   18   19
           {0xBA,0xB9,0xB8,0xB7,0xB6,0xB5,0xB4,0xB3,0xB2,0xB1,
           // 20   21   22   23   24   25   26   27   28   29   30
            0xB0,0xAF,0xAE,0xAD,0xAC,0xAB,0xAA,0xA9,0xA8,0xA7,0xA6};

tByte code T2_reload_H[21] = 
           // 10   11   12   13   14   15   16   17   18   19
           {0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,
           // 20   21   22   23   24   25   26   27   28   29   30
            0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C,0x3C};

/*------------------------------------------------------------------*-

  SCH_Init_T2()

  Scheduler initialisation function.  Prepares scheduler
  data structures and sets up timer interrupts at required rate.
  Must call this function before using the scheduler.  

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

   // Crystal is assumed to be 12 MHz
   // The Timer 2 resolution is 0.000001 seconds (1 µs)
   // The required Timer 2 overflow is 0.001 seconds (1 ms)
   // - this takes 1000 timer ticks
   // Reload value is 65536 - 1000 = 64536 (dec) = 0xFC18

   T2CON = 0x04;   // load Timer 2 control register
   T2MOD = 0x00;   // load Timer 2 mode register

   TH2    = 0xFC;  // load timer 2 high byte
   RCAP2H = 0xFC;  // load timer 2 reload capture reg, high byte
   TL2    = 0x18;  // load timer 2 low byte
   RCAP2L = 0x18;  // load timer 2 reload capture reg, low byte
   
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
               // Schedule this regular task to run again
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

  SCH_Calculate_Ave_Temp_DS1621()

  This function should be scheduled once per minute.

  Based on 1 measurement per hour,
  this function updates a variable Temperature_average_G) 
  with the average temperature over the last 24 hours.

  The updates are carried out every 24 hours.

-*------------------------------------------------------------------*/
void SCH_Calculate_Ave_Temp_DS1621(void)
   {
   if (++Minute_G == 60)
      {
      Minute_G = 0;

      // An hour has elapsed - take temperature reading
      I2C_Read_Temperature_DS1621();

      // Add current reading to running total
      Temperature_average_G += Temperature_G;

      if (++Hour_G == 24)
         {
         // 24 hours have elapsed - get average temperature
         Hour_G = 0;
         Temperature_average_G /= 24;

         // Update the scheduler
         SCH_Perform_Temperature_Adjustment();  
         }
      }
   }

/*------------------------------------------------------------------*-

  SCH_Perform_Temperature_Adjustment()

  This scheduler adjusts its timing to take into account
  changes in ambient temperature.

-*------------------------------------------------------------------*/
void SCH_Perform_Temperature_Adjustment(void)
   {
   static int Previous_temperature_average_G;

   if ((Previous_temperature_average_G - Temperature_average_G) != 0)
      {
      // Only consider temperatures in range 10 - 30 Celsius in this 
      // version (easily adjusted)
      if (Temperature_average_G < 10)
         {
         Temperature_average_G = 10;
         }
      else
         {
         if (Temperature_average_G > 30)
            {
            Temperature_average_G = 30;
            }
         }

      ET2 = 0;  // Disable interrupt
      TR2 = 0;  // Stop T2

      // Reload the timer 
      TL2     = T2_reload_L[Temperature_average_G-10];   
      RCAP2L  = T2_reload_L[Temperature_average_G-10];   
      TH2     = T2_reload_H[Temperature_average_G-10];   
      RCAP2H  = T2_reload_H[Temperature_average_G-10];   

      ET2   = 1;      
      TR2   = 1;     
      }

   Previous_temperature_average_G = Temperature_average_G;

   Temperature_average_G = 0;
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
