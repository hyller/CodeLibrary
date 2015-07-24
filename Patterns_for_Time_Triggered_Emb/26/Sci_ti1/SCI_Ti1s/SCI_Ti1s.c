/*------------------------------------------------------------------*-

   SCI_Ti1s.c (v1.00)

  ------------------------------------------------------------------

   This is an implementation of SCI SCHEDULER (TICK) for 8051/52.

   --- See Chapter 26 ---

   *** SLAVE NODE : TICK-ONLY (SIMPLEX) ***
   *** MASTER DOES NOT CHECK FOR SLAVE ACKNOWLEDEMENTS

   *** Uses 1232 watchdog timer ***

   *** Both Master and Slave share the same tick rate (1 ms) ***
   *** - See Master code for details ***


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"
#include "Port.h"

#include "SCI_Ti1s.h"
#include "TLight_A.h"

// ------ Public variable declarations -----------------------------

// The array of tasks (see Sch51.c)
extern sTask SCH_tasks_G[SCH_MAX_TASKS];

// The error code variable (see Sch51.c)
extern tByte Error_code_G;

// ------ Private function prototypes ------------------------------

static void SCI_TICK1_SLAVE_Enter_Safe_State(void);

static void SCI_TICK1_SLAVE_Watchdog_Init(void);
static void SCI_TICK1_SLAVE_Watchdog_Refresh(void) reentrant;

/*------------------------------------------------------------------*-

  SCI_TICK1_SLAVE_Init()

  Scheduler initialisation function.  Prepares scheduler
  data structures and sets up timer interrupts at required rate.

  Must call this function before using the scheduler.  

-*------------------------------------------------------------------*/
void SCI_TICK1_SLAVE_Init(void) 
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
 
   // ---------- External interrupt 0 ----------
   // The slave is driven by an interrupt input
   // The interrupt is enabled 
   // It is triggered by a falling edge at pin P3.2
   IT0 = 1;
   EX0 = 1;

   // Start the watchdog
   SCI_TICK1_SLAVE_Watchdog_Init();  
   }

/*------------------------------------------------------------------*-

  SCI_TICK1_SLAVE_Start()

  Starts the slave scheduler, by enabling interrupts.

  NOTE: Usually called after all regular tasks are added,
  to keep the tasks synchronised.

  NOTE: ONLY THE SCHEDULER INTERRUPT SHOULD BE ENABLED!!! 

-*------------------------------------------------------------------*/
void SCI_TICK1_SLAVE_Start(void) 
   {
   // Place system in a safe state
   // - slave will keep returning here if master does not start
   // - or otherwise fails.
   SCI_TICK1_SLAVE_Enter_Safe_State();

   // Now in a safe state
   // Wait here - indefinitely - for the first tick
   // (Refresh the watchdog to avoid constant watchdog restarts)
   while (IE0 == 0)
      {
      SCI_TICK1_SLAVE_Watchdog_Refresh();
      }

   // Clear the flag
   IE0 = 0;

   // Start the scheduler
   EA = 1;
   }

/*------------------------------------------------------------------*-

  SCI_TICK1_SLAVE_Update

  This is the scheduler ISR.  It is called at a rate 
  determined by the timer settings in SCI_TICK1_SLAVE_Init().

  This Slave is triggered by external interrupts.
 
-*------------------------------------------------------------------*/
void SCI_TICK1_SLAVE_Update(void) interrupt INTERRUPT_EXTERNAL_0  
   {
   tByte Index;

   // Feed the watchdog
   // Master will monitor this pin to check for slave activity 
   SCI_TICK1_SLAVE_Watchdog_Refresh();

   // Now do 'standard' scheduler updates

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

  SCI_TICK1_SLAVE_Watchdog_Init()

  This function sets up the watchdog timer.

  If the Master fails (or other error develop), 
  no tick messages will arrive, and the scheduler
  will stop.  

  To detect this situation, we have a (hardware) watchdog
  running in the slave.  This watchdog - which should be set to
  overflow at around 100ms - is used to set the system into a
  known (safe) state.  The slave will then wait (indefinitely)
  for the problem to be resolved.

  NOTE: The slave will not be generating Ack messages in these 
  circumstances.  The Master (if running) will therefore be aware
  that there is a problem.  

-*------------------------------------------------------------------*/
void SCI_TICK1_SLAVE_Watchdog_Init(void)   
   {
   // INIT NOT REQUIRED FOR 1232 EXTERNAL WATCHDOG
   // - May be required wwith different watchdog hardware
   //
   // Edit as required
   }


/*------------------------------------------------------------------*-

  SCI_TICK1_SLAVE_Watchdog_Refresh()

  Feed the external (1232) watchdog.

  Timeout is between ~60 and 250 ms (hardware dependent)

  HARDWARE: Assumes external 1232 watchdog

-*------------------------------------------------------------------*/
void SCI_TICK1_SLAVE_Watchdog_Refresh(void) reentrant
   {
   static bit WATCHDOG_state;

   // Change the state of the watchdog pin
   if (WATCHDOG_state == 1)
      {
      WATCHDOG_state = 0;
      WATCHDOG_pin = 0;
      }
   else
      {
      WATCHDOG_state = 1;
      WATCHDOG_pin = 1;
      }
   }    

/*------------------------------------------------------------------*-

  SCI_TICK1_SLAVE_Enter_Safe_State()

  This is the state enterted by the system when:
  (1) The node is powered up or reset
  (2) The Master node fails
  (3) The network has an error
  (4) Tick messages are delayed for any other reason

  Try to ensure that the system is in a 'safe' state in these 
  circumstances.

-*------------------------------------------------------------------*/
void SCI_TICK1_SLAVE_Enter_Safe_State(void)
   {
   // USER DEFINED - Edit as required
   TRAFFIC_LIGHTS_Display_Safe_Output();
   }   

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/

