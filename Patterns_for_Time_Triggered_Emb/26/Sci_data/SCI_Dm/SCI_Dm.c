/*------------------------------------------------------------------*-

   SCI_Dm.c (v1.00)

  ------------------------------------------------------------------

   This is an implementation of SCI SCHEDULER (DATA) for 8051/52.

   --- See Chapter 26 ---

   *** MASTER NODE ***

   *** Uses T2 for timing, 16-bit auto reload ***
   *** 12 MHz oscillator -> 1 ms (precise) tick interval ***

   --- Assumes '1232' watchdog on Slave ---


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

#include "SCI_Dm.H"
#include "Delay_T0.h"
#include "TLight_B.h"

// ------ Public variable definitions ------------------------------

tByte Tick_message_data_G = RETURN_NORMAL;  
tByte Ack_message_data_G = RETURN_NORMAL;

// Used to detect slave activity
bit First_call_G;
bit Watchdog_input_previous_G;

// ------ Public variable declarations -----------------------------

// The array of tasks (see Sch51.c)
extern sTask SCH_tasks_G[SCH_MAX_TASKS];

// The error code variable (see Sch51.c)
extern tByte Error_code_G;

// Used to reset system in event of slave error (see Main.C)
extern bit System_reset_G;

// ------ Private function prototypes ------------------------------

static void SCI_D_MASTER_Send_Tick_Message(void);
static bit  SCI_D_MASTER_Process_Ack(void);

/*------------------------------------------------------------------*-

  SCI_D_MASTER_Init_T2()

  Scheduler initialisation function.  Prepares scheduler data 
  structures and sets up timer interrupts at required rate.
  You must call this function before using the scheduler.  

-*------------------------------------------------------------------*/
void SCI_D_MASTER_Init_T2(void) 
   {
   tByte i;

   // No interrupts (yet)
   EA = 0;

   // ------ Set up the scheduler ----------------------------------
   // Sort out the tasks
   for (i = 0; i < SCH_MAX_TASKS; i++) 
      {
      SCH_Delete_Task(i);
      }

   // Reset the global error variable
   // - SCH_Delete_Task() will generate an error code, 
   //   (because the task array is empty)
   Error_code_G = 0;

   // ------ Set up Timer 2 (begin) --------------------------------
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
   // ------ Set up Timer 2 (end) ----------------------------------
   }

/*------------------------------------------------------------------*-

  SCI_D_MASTER_Start()

  Starts the scheduler, by enabling interrupts.

  NOTE: Usually called after all regular tasks are added,
  to keep the tasks synchronised.

  NOTE: ONLY THE SCHEDULER INTERRUPT SHOULD BE ENABLED!!! 
 
-*------------------------------------------------------------------*/
void SCI_D_MASTER_Start(void) 
   {
   // Try to place system in 'safe' state at start or after errors
   SCI_D_MASTER_Enter_Safe_State();

   // Delay here to cause the slave to time out and reset
   // Adjust this delay to match the timeout periods on the slaves
   Hardware_Delay_T0(500);

   // Now send first tick to start the slave
   // (starts on falling edge)
   Interrupt_output_pin = 1;
   Hardware_Delay_T0(5);
   Interrupt_output_pin = 0;
   Hardware_Delay_T0(5);

   Interrupt_output_pin = 1; // Ready for first tick

   // Start the scheduler
   EA = 1;
   }

/*------------------------------------------------------------------*-

  SCI_D_MASTER_Update_T2

  This is the scheduler ISR.  It is called at a rate determined by 
  the timer settings in SCI_D_MASTER_Init_T2().  This version is 
  triggered by Timer 2 interrupts: timer is automatically reloaded.

-*------------------------------------------------------------------*/
void SCI_D_MASTER_Update_T2(void) interrupt INTERRUPT_Timer_2_Overflow  
   {
   tByte Index;

   TF2 = 0; // Must manually clear this. 

   // Get the ack message from the slave
   if (SCI_D_MASTER_Process_Ack() == RETURN_ERROR)
      {
      // Did not receive ack!
      Error_code_G = ERROR_SCH_LOST_SLAVE;

      // Enter safe state and remain here until reset
      SCI_D_MASTER_Enter_Safe_State();
      while(1); 
      }
 
   // Send 'tick' message to the slave
   SCI_D_MASTER_Send_Tick_Message(); 

   // NOTE: calculations are in *TICKS* (not milliseconds)
   for (Index = 0; Index < SCH_MAX_TASKS; Index++)
      {
      // Check if there is a task at this location
      if (SCH_tasks_G[Index].pTask)
         {
         if (SCH_tasks_G[Index].Delay == 0)
            {
            // The task is due to run
            SCH_tasks_G[Index].RunMe += 1;  // Increment the run flag

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

   // Prepare for next tick
   Interrupt_output_pin = 1;
   }   

/*------------------------------------------------------------------*-

  SCI_D_MASTER_Send_Tick_Message()

  This function sends a tick message.

  The receipt of this message will cause an interrupt to be generated
  in the slave(s): this will, in turn, invoke the scheduler 'update' 
  function in the slave(s).

-*------------------------------------------------------------------*/
void SCI_D_MASTER_Send_Tick_Message(void) 
   {
   // Apply the tick data to the port
   SCI_transfer_port = Tick_message_data_G;

   // Send tick (falling edge) to the slave
   Interrupt_output_pin = 0;
   }


/*------------------------------------------------------------------*-

  SCI_D_MASTER_Process_Ack()

  Checks that the slave is operating.

  Reads data from the slave.

-*------------------------------------------------------------------*/

bit SCI_D_MASTER_Process_Ack(void) 
   {
   if (First_call_G)
      {
      // This is the first time this function has been called
      First_call_G = 0;

      // Prepare for subsequent checking of the watchdog pin
      Watchdog_input_previous_G = Slave_watchdog_pin;
      }
   else
      {
      // Watchdog pin should change state every time
      // - if the slave is running correctly
      if (Watchdog_input_previous_G == Slave_watchdog_pin)
         {
         // Error!
         return RETURN_ERROR;
         }

      // Slave is OK
      Watchdog_input_previous_G = Slave_watchdog_pin;
      }

   // Set up port for reading
   SCI_transfer_port = 0xFF;

   // Read ack message
   Ack_message_data_G = SCI_transfer_port;

   return RETURN_NORMAL;
   }

/*------------------------------------------------------------------*-

  SCI_D_MASTER_Enter_Safe_State()

  This is the state entered by the system when:
  (1) The node is powered up or reset
  (2) The slave node fails
  (3) The network has an error
  (4) Ack messages are delayed for any other reason

  Try to ensure that the system is in a 'safe' state in these 
  circumstances.

-*------------------------------------------------------------------*/
void SCI_D_MASTER_Enter_Safe_State(void) reentrant
   {
   // USER DEFINED - Edit as required

   // Here we display a safe output
   TRAFFIC_LIGHTS_Display_Safe_Output();
   }  

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
