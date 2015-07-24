/*------------------------------------------------------------------*-

   SCI_Ds.c (v1.00)

  ------------------------------------------------------------------

   This is an implementation of SCI SCHEDULER (DATA) for 8051/52.

   --- See Chapter 26 ---

   *** SLAVE NODE ***

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

#include "SCI_Ds.h"
#include "TLight_B.h"

// ------ Public variable definitions ------------------------------

// Data sent from the master to this slave
tByte Tick_message_data_G = RETURN_NORMAL;

// Data sent from this slave to the master 
// - data may be sent on, by the master, to another slave  
tByte Ack_message_data_G = RETURN_NORMAL; 

// ------ Public variable declarations -----------------------------

// The array of tasks (see Sch51.c)
extern sTask SCH_tasks_G[SCH_MAX_TASKS];

// The error code variable (see Sch51.c)
extern tByte Error_code_G;

// ------ Private function prototypes ------------------------------

static void SCI_D_SLAVE_Enter_Safe_State(void);

static void SCI_D_SLAVE_Send_Ack_Message_To_Master(void);
static void SCI_D_SLAVE_Process_Tick_Message(void);

static void SCI_D_SLAVE_Watchdog_Init(void);
static void SCI_D_SLAVE_Watchdog_Refresh(void) reentrant;

/*------------------------------------------------------------------*-

  SCI_D_SLAVE_Init()

  Scheduler initialisation function.  Prepares scheduler
  data structures and sets up timer interrupts at required rate.

  Must call this function before using the scheduler.  

-*------------------------------------------------------------------*/
void SCI_D_SLAVE_Init(void) 
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
   SCI_D_SLAVE_Watchdog_Init();  
   }

/*------------------------------------------------------------------*-

  SCI_D_SLAVE_Start()

  Starts the slave scheduler, by enabling interrupts.

  NOTE: Usually called after all regular tasks are added,
  to keep the tasks synchronised.

  NOTE: ONLY THE SCHEDULER INTERRUPT SHOULD BE ENABLED!!! 

-*------------------------------------------------------------------*/
void SCI_D_SLAVE_Start(void) 
   {
   // Place system in a safe state
   // - slave will keep returning here if master does not start
   // - or otherwise fails.
   SCI_D_SLAVE_Enter_Safe_State();

   // Now in a safe state
   // Wait here - indefinitely - for the first tick
   // (Refresh the watchdog to avoid constant watchdog restarts)
   while (IE0 == 0)
      {
      SCI_D_SLAVE_Watchdog_Refresh();
      }

   // Clear the flag
   IE0 = 0;

   // Start the scheduler
   EA = 1;
   }

/*------------------------------------------------------------------*-

  SCI_D_SLAVE_Update

  This is the scheduler ISR.  It is called at a rate 
  determined by the timer settings in SCI_D_SLAVE_Init().

  This Slave is triggered by external interrupts.
 
-*------------------------------------------------------------------*/
void SCI_D_SLAVE_Update(void) interrupt INTERRUPT_EXTERNAL_0  
   {
   tByte Index;

   // Extract the tick-message data
   SCI_D_SLAVE_Process_Tick_Message();

   // Send data back to Master       
   SCI_D_SLAVE_Send_Ack_Message_To_Master();

   // Feed the watchdog 
   SCI_D_SLAVE_Watchdog_Refresh();

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
               // Schedule this periodic task to run again
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

  SCI_D_SLAVE_Send_Ack_Message_To_Master()

  Slave must send and 'Acknowledge' message to the master, after
  tick messages are received.  

  The acknowledge message serves two purposes:
  [1] It confirms to the master that the slave is alive & well.
  [2] It provides a means of sending data to the master.

-*------------------------------------------------------------------*/
void SCI_D_SLAVE_Send_Ack_Message_To_Master(void)
   {
   SCI_Transfer_Port = Ack_message_data_G;
   }

/*------------------------------------------------------------------*-

  SCI_D_SLAVE_Process_Tick_Message()

  The ticks messages are crucial to the operation of this S-C
  scheduler: the arrival of a tick message (at regular intervals) 
  invokes the 'Update' ISR, that drives the scheduler.

  The tick messages themselves may contain data.  These data are 
  extracted in this function. 

-*------------------------------------------------------------------*/
void SCI_D_SLAVE_Process_Tick_Message(void)
   {
   // Set up port for reading
   SCI_Transfer_Port = 0xFF;

   // Read the data
   Tick_message_data_G = SCI_Transfer_Port;
   }


/*------------------------------------------------------------------*-

  SCI_D_SLAVE_Watchdog_Init()

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
void SCI_D_SLAVE_Watchdog_Init(void)   
   {
   // INIT NOT REQUIRED FOR 1232 EXTERNAL WATCHDOG
   // - May be required wwith different watchdog hardware
   //
   // Edit as required
   }


/*------------------------------------------------------------------*-

  SCI_D_SLAVE_Watchdog_Refresh()

  Feed the external (1232) watchdog.

  Timeout is between ~60 and 250 ms (hardware dependent)

  HARDWARE: Assumes external 1232 watchdog

-*------------------------------------------------------------------*/
void SCI_D_SLAVE_Watchdog_Refresh(void) reentrant
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

  SCI_D_SLAVE_Enter_Safe_State()

  This is the state enterted by the system when:
  (1) The node is powered up or reset
  (2) The Master node fails
  (3) The network has an error
  (4) Tick messages are delayed for any other reason

  Try to ensure that the system is in a 'safe' state in these 
  circumstances.

-*------------------------------------------------------------------*/
void SCI_D_SLAVE_Enter_Safe_State(void)
   {
   // USER DEFINED - Edit as required
   TRAFFIC_LIGHTS_Display_Safe_Output();
   }   

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/

