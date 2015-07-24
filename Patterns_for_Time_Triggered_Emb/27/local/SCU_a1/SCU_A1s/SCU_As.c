/*------------------------------------------------------------------*-

   SCU_As.c (v1.00)

  ------------------------------------------------------------------

   This is an implementation of SCU SCHEDULER (LOCAL) for 8051/52.
   AND an implementation of SCU SCHEDULER (RS-232) for 8051/52.

   --- See Chapter 27 ---

   *** MASTER NODE ***
   *** CHECKS FOR SLAVE ACKNOWLEDEMENTS ***
   *** Local / RS-232 version (no 'enable' support) ***

   *** Uses 1232 watchdog timer ***

   *** Assumes 12 MHz osc (same as Master) ***

   *** Both Master and Slave share the same tick rate (5 ms) ***
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

#include "SCU_As.h"
#include "TLight_B.h"

// ------ Public variable definitions ------------------------------

// Data sent from the master to this slave
tByte Tick_message_data_G;

// Data sent from this slave to the master 
// - data may be sent on, by the master, to another slave  
tByte Ack_message_data_G = 'S'; 

// ------ Public variable declarations -----------------------------

// The array of tasks (see Sch51.c)
extern sTask SCH_tasks_G[SCH_MAX_TASKS];

// The error code variable (see Sch51.c)
extern tByte Error_code_G;

// ------ Private function prototypes ------------------------------

static void  SCU_A_SLAVE_Enter_Safe_State(void);

static void  SCU_A_SLAVE_Send_Ack_Message_To_Master(void);
static tByte SCU_A_SLAVE_Process_Tick_Message(void);

static void  SCU_A_SLAVE_Watchdog_Init(void);
static void  SCU_A_SLAVE_Watchdog_Refresh(void) reentrant;


// ------ Private constants ----------------------------------------

// Each slave must have a unique non-zero ID 
#define SLAVE_ID 0x31

#define NO_NETWORK_ERROR (1) 
#define NETWORK_ERROR (0)

// ------ Private variables ----------------------------------------

static bit Message_byte_G;
static bit WATCHDOG_state_G = 0;
static tByte Message_ID_G = 0;


/*------------------------------------------------------------------*-
  SCU_A_SLAVE_Init_T1()

  Scheduler initialisation function.  Prepares scheduler
  data structures and sets up timer interrupts at required rate.
  Must call this function before using the scheduler.  
 
  BAUD_RATE - The required baud rate

-*------------------------------------------------------------------*/
void SCU_A_SLAVE_Init_T1(const tWord BAUD_RATE) 
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

   // Set the network error pin (reset when tick message received)
   Network_error_pin = NETWORK_ERROR;

   // Ready for first tick message
   Message_byte_G = 1;
 
   // ------ Set the baud rate (begin) -----------------------------
   PCON &= 0x7F;   // Set SMOD bit to 0 (don't double baud rates)

   //  receiver enabled
   //  9-bit data, 1 start bit, 1 stop bit, variable baud rate (asynchronous)
   SCON = 0xD2;

   TMOD |= 0x20;   // T1 in mode 2, 8-bit auto reload

   TH1 = (256 - (tByte)((((tLong)OSC_FREQ / 100) * 3125) 
            / ((tLong) BAUD_RATE * OSC_PER_INST * 1000)));

   TL1 = TH1;  
   TR1 = 1;  // Run the timer
   TI = 1;   // Send first character (dummy)

   // ------ Set the baud rate (end) -------------------------------

   // Interrupt enabled
   // (Both receiving and SENDING a byte will generate a serial interrupt)
   // Global interrupts not yet enabled.
   ES = 1;

   // Start the watchdog
   SCU_A_SLAVE_Watchdog_Init();  
   }

/*------------------------------------------------------------------*-
  SCU_A_SLAVE_Start()

  Starts the slave scheduler, by enabling interrupts.

  NOTE: Usually called after all regular tasks are added,
  to keep the tasks synchronised.

  NOTE: ONLY THE SCHEDULER INTERRUPT SHOULD BE ENABLED!!! 

-*------------------------------------------------------------------*/
void SCU_A_SLAVE_Start(void) 
   {
   tByte Command = 0;
   tByte Message_byte;
   tByte Count = 0;
   bit Slave_started = 0;

   // Disable interrupts 
   EA = 0;

   // We can be at this point because:
   // 1. The network has just been powered up
   // 2. An error has occurred in the Master, and it is not generating ticks
   // 3. The network has been damaged and no ticks are being received by this slave
   //
   // Try to make sure the system is in a safe state...
   SCU_A_SLAVE_Enter_Safe_State();

   // NOTE: Interrupts are disabled here
   Count = 0;

   Error_code_G = ERROR_SCH_WAITING_FOR_START_COMMAND_FROM_MASTER;
   SCH_Report_Status(); // Sch not yet running - do this manually

   // Now wait (indefinitely) for appropriate signals from the master
   do {
      // Wait for tick messages (byte 1), all bits set to 0, to be received 
      do {
         SCU_A_SLAVE_Watchdog_Refresh(); // Must keep feeding the watchdog
         } while (RI == 0);  

      Message_byte = (tByte) SBUF; 
      RI = 0;

      // Must get two ID messages in a row...
      // (with command bit)
      // Ack each one
      if ((Message_byte == (tByte) SLAVE_ID) && (RB8 == 1))
         {
         Count++;

         // Received message for this slave - send ack
         TI = 0;                                            
         TB8 = 1; // Set command bit
         SBUF = (tByte) SLAVE_ID; 
         }
      else
         {
         Count = 0;
         }
      } while (Count < 2);

   // Start the scheduler
   EA = 1;
   }

/*------------------------------------------------------------------*-

  SCU_A_SLAVE_Update

  This is the scheduler ISR.  It is called at a rate 
  determined by the timer settings in SCU_A_SLAVE_Init().

  This Slave is triggered by USART interrupts.
 
-*------------------------------------------------------------------*/
void SCU_A_SLAVE_Update(void) interrupt INTERRUPT_UART_Rx_Tx  
   {
   tByte Index;

   if (RI == 1) // Must check this. 
      {
      // Default
      Network_error_pin = NO_NETWORK_ERROR;

      // Two-byte messages are sent (Ack) and received (Tick)
      // - it takes two sched ticks to process each message
      //
      // Keep track of the current byte
      if (Message_byte_G == 0)
         {
         Message_byte_G = 1;
         }
      else
         {
         Message_byte_G = 0;
         }

      // Check tick data - send ack if necessary
      // NOTE: 'START' message will only be sent after a 'time out'
      if (SCU_A_SLAVE_Process_Tick_Message() == SLAVE_ID)
         {
         SCU_A_SLAVE_Send_Ack_Message_To_Master();

         // Feed the watchdog ONLY when a *relevant* message is received
         // (noise on the bus, etc, will not stop the watchdog...)
         //
         // START messages will NOT refresh the slave
         // - Must talk to every slave at regular intervals 
         SCU_A_SLAVE_Watchdog_Refresh();
         }

      // NOTE: calculations are in *TICKS* (not milliseconds)
      for (Index = 0; Index < SCH_MAX_TASKS; Index++)
         {
         // Check if there is a task at this location
         if (SCH_tasks_G[Index].pTask)
            {
            if (SCH_tasks_G[Index].Delay == 0)
               {
               // The task is due to run
               SCH_tasks_G[Index].RunMe = 1;  // Set the run flag
   
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
      RI = 0;  // Reset the RI flag   
      }
   else
      {
      // ISR call was triggered by TI flag, after last character was sent
      // Must clear the TI flag
      TI = 0;
      }
   }   

/*------------------------------------------------------------------*-

  SCU_A_SLAVE_Send_Ack_Message_To_Master()

  Slave must send and 'Acknowledge' message to the master, after
  tick messages are received.  NOTE: Only tick messages specifically
  addressed to this slave should be acknowledged.

  The acknowledge message serves two purposes:
  [1] It confirms to the master that this slave is alive & well.
  [2] It provides a means of sending data to the master and - hence
      - to other slaves.

  NOTE: Direct data transfer between slaves is NOT possible.

-*------------------------------------------------------------------*/
void SCU_A_SLAVE_Send_Ack_Message_To_Master(void)
   {
   // Sending one byte of data at a time, depending on index value
   // If Message_byte_G is 0, send first byte (the slave ID)
   if (Message_byte_G == 0)
      {
      TI = 0;                                            
      TB8 = 1;  // Set 'Command' bit
      SBUF = SLAVE_ID;
      }
   else
      {
      // Message_byte_G is 1, send the data byte 
      TI = 0;
      TB8 = 0;
      SBUF = Ack_message_data_G;
      }
 
   // Data sent - return    
   }

/*------------------------------------------------------------------*-

  SCU_A_SLAVE_Process_Tick_Message()

  The ticks messages are crucial to the operation of this shared-clock
  scheduler: the arrival of a tick message (at regular intervals) 
  invokes the 'Update' ISR, that drives the scheduler.

  The tick messages themselves may contain data.  These data are 
  extracted in this function. 

-*------------------------------------------------------------------*/
tByte SCU_A_SLAVE_Process_Tick_Message(void)
   {
   tByte Data;

   // Try to get data byte
   if (RI == 0)
      {
      // No data - something is wrong

      // Set the error flag bit
      Network_error_pin = NETWORK_ERROR;

      // Return slave ID 0
      return 0x00;
      } 
 
   // There *ARE* data available
   Data = (tByte) SBUF;
   RI = 0;  // Clear RI flag

   // What we do with this message depends if it a first or second byte
   if (Message_byte_G == 0)
      {
      // This is (should be) an ID byte
      Message_ID_G = Data;   

      if (RB8 == 0)
         {
         Message_ID_G = 0;  // Command bit should be set
         }
      }
   else
      {
      // This is (should be) a data byte
      // - Command bit should not be set
      if ((Message_ID_G == SLAVE_ID) && (RB8 == 0))
         {
         Tick_message_data_G = Data;
         }
      else
         {
         // Something is wrong - set Message_ID to 0
         Message_ID_G = 0; 

         // Set the error flag bit
         Network_error_pin = NETWORK_ERROR;
         }
      }

   return Message_ID_G;
   }


/*------------------------------------------------------------------*-

  SCU_A_SLAVE_Watchdog_Init()

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
void SCU_A_SLAVE_Watchdog_Init(void)   
   {
   // INIT NOT REQUIRED FOR 1232 EXTERNAL WATCHDOG
   // - May be required wwith different watchdog hardware
   //
   // Edit as required
   }


/*------------------------------------------------------------------*-

  SCU_A_SLAVE_Watchdog_Refresh()

  Feed the external (1232) watchdog.

  Timeout is between ~60 and 250 ms (hardware dependent)

  Assumes external 1232 watchdog

-*------------------------------------------------------------------*/
void SCU_A_SLAVE_Watchdog_Refresh(void) reentrant
   {
   // Change the state of the watchdog pin
   if (WATCHDOG_state_G == 1)
      {
      WATCHDOG_state_G = 0;
      WATCHDOG_pin = 0;
      }
   else
      {
      WATCHDOG_state_G = 1;
      WATCHDOG_pin = 1;
      } 
   }    

/*------------------------------------------------------------------*-

  SCU_A_SLAVE_Enter_Safe_State()

  This is the state enterted by the system when:
  (1) The node is powered up or reset
  (2) The Master node fails, and no working backup is available
  (3) The network has an error
  (4) Tick messages are delayed for any other reason

  Try to ensure that the system is in a 'safe' state in these 
  circumstances.

-*------------------------------------------------------------------*/
void SCU_A_SLAVE_Enter_Safe_State(void)
   {
   // USER DEFINED - Edit as required
   TRAFFIC_LIGHTS_Display_Safe_Output();
   }  

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/

