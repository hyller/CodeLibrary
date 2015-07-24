/*------------------------------------------------------------------*-

   SCC_S515.c (v1.00)

  ------------------------------------------------------------------

   THIS IS A SHARED-SCHEDULER [CAN BASED] FOR 80C515C (etc.) 

   *** Both Master and Slave share the same tick rate ***
   *** - See Master code for details ***

   -----------------------------------------------------------
   --- NOTE: 'Idle mode' must be disabled (in Sch51.C)     ---
   --- or the on-chip watchdog will not function correctly ---
   -----------------------------------------------------------


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

#include "SCC_S515.h"
#include "TLight_B.h"

// ------ Public variable definitions ------------------------------

// Data sent from the master to this slave
tByte Tick_message_data_G[4];

// Data sent from this slave to the master 
// - data may be sent on, by the master, to another slave  
tByte Ack_message_data_G[4] = {'1','1','1','1'}; 

// ------ Public variable declarations -----------------------------

// The array of tasks (see Sch51.c)
extern sTask SCH_tasks_G[SCH_MAX_TASKS];

// The error code variable (see Sch51.c)
extern tByte Error_code_G;

// ------ Private function prototypes ------------------------------
static void  SCC_A_SLAVE_Enter_Safe_State(void);

static void  SCC_A_SLAVE_Send_Ack_Message_To_Master(void);
static tByte SCC_A_SLAVE_Process_Tick_Message(void);

static bit   SCC_A_SLAVE_Read_Command_Bit(const tByte);
static tByte SCC_A_SLAVE_Set_Command_Bit(const tByte);
static tByte SCC_A_SLAVE_Read_Message_ID(const tByte);

static void  SCC_A_SLAVE_Watchdog_Init(void);
static void  SCC_A_SLAVE_Watchdog_Refresh(void) reentrant;


// ------ Private constants ----------------------------------------

// Each slave (and backup) must have a unique (non-zero) ID 
#define SLAVE_ID 0x01

#define NO_NETWORK_ERROR (1) 
#define NETWORK_ERROR (0)

/*------------------------------------------------------------------*-

  SCC_A_SLAVE_Init_CAN()

  Scheduler initialisation function.  Prepares scheduler
  data structures and sets up timer interrupts at required rate.
  Must call this function before using the scheduler.  

-*------------------------------------------------------------------*/
void SCC_A_SLAVE_Init_CAN(void) 
   {
   tByte i;
   tByte Message;

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

   // ------ SYSCON Register 
   // The access to XRAM and CAN controller is enabled.
   // The signals !RD and !WR are not activated during accesses
   // to the XRAM/CAN controller.
   // ALE generation is enabled.
   SYSCON = 0x20;  
  
   //  ------------ CAN Control/Status Register --------------
   //  Start to init the CAN module
   CAN_cr  = 0x41;  // INIT and CCE

   //  ------------ Bit Timing Register ---------------------
   // Baudrate = 333.333 kbaud 
   // - Need 308+ kbaud plus for 1ms ticks, 8 data bytes
   // - See text for details  
   //
   // There are 5 time quanta before sample point
   // There are 4 time quanta after sample point
   // The (re)synchronization jump width is 2 time quanta
   CAN_btr1  = 0x34;  // Bit Timing Register
   CAN_btr0  = 0x42; 

   CAN_gms1  = 0xFF;  // Global Mask Short Register 1
   CAN_gms0  = 0xFF;  // Global Mask Short Register 0

   CAN_ugml1 = 0xFF;  // Upper Global Mask Long Register 1
   CAN_ugml0 = 0xFF;  // Upper Global Mask Long Register 0

   CAN_lgml1 = 0xF8;  // Lower Global Mask Long Register 1
   CAN_lgml0 = 0xFF;  // Lower Global Mask Long Register 0

   //  ------ Configure 'Tick' Message Object 
   //  Message object 1 is valid
   //  enable receive interrupt
   CAN_messages[0].MCR1 = 0x55;    // Message Ctrl. Reg. 1
   CAN_messages[0].MCR0 = 0x99;    // Message Ctrl. Reg. 0

   //  message direction is receive
   //  extended 29-bit identifier
   CAN_messages[0].MCFG = 0x04;    // Message Config. Reg.

   CAN_messages[0].UAR1 = 0x00;    // Upper Arbit. Reg. 1
   CAN_messages[0].UAR0 = 0x00;    // Upper Arbit. Reg. 0
   CAN_messages[0].LAR1 = 0x00;    // Lower Arbit. Reg. 1
   CAN_messages[0].LAR0 = 0x00;    // Lower Arbit. Reg. 0


   //  ------ Configure 'Ack' Message Object 
   CAN_messages[1].MCR1 = 0x55;    // Message Ctrl. Reg. 1
   CAN_messages[1].MCR0 = 0x95;    // Message Ctrl. Reg. 0

   // Message direction is transmit
   // extended 29-bit identifier
   // 5 valid data bytes
   CAN_messages[1].MCFG = 0x5C;      // Message Config. Reg.

   CAN_messages[1].UAR1 = 0x00;    // Upper Arbit. Reg. 1
   CAN_messages[1].UAR0 = 0x00;    // Upper Arbit. Reg. 0
   CAN_messages[1].LAR1 = 0xF8;    // Lower Arbit. Reg. 1
   CAN_messages[1].LAR0 = 0x07;    // Lower Arbit. Reg. 0

   CAN_messages[1].Data[0] = 0x00;   // data byte 0
   CAN_messages[1].Data[1] = 0x00;   // data byte 1
   CAN_messages[1].Data[2] = 0x00;   // data byte 2
   CAN_messages[1].Data[3] = 0x00;   // data byte 3
   CAN_messages[1].Data[4] = 0x00;   // data byte 4

   //  ------ Configure other objects ------------------------------
   // Configure remaining message objects (2-14) - none are valid
   for (Message = 2; Message <= 14; ++Message)
      {
      CAN_messages[Message].MCR1 = 0x55;  // Message Ctrl. Reg. 1
      CAN_messages[Message].MCR0 = 0x55;  // Message Ctrl. Reg. 0
      }

   // ------------ CAN Ctrl. Reg. ---------------------
   //  reset CCE and INIT
   // enable interrupt generation from CAN Modul
   // enable CAN-interrupt of Controller
   CAN_cr = 0x02;
   IEN2 |= 0x02;

   // Start the watchdog
   SCC_A_SLAVE_Watchdog_Init();  
   }

/*------------------------------------------------------------------*-

  SCC_A_SLAVE_Start()

  Starts the slave scheduler, by enabling interrupts.

  NOTE: Usually called after all regular tasks are added,
  to keep the tasks synchronised.

  NOTE: ONLY THE SCHEDULER INTERRUPT SHOULD BE ENABLED!!! 

-*------------------------------------------------------------------*/
void SCC_A_SLAVE_Start(void) 
   {
   tByte Tick_00, Tick_ID;
   bit Start_slave;

   // Disable interrupts 
   EAL = 0;

   // We can be at this point because:
   // 1. The network has just been powered up
   // 2. An error has occurred in the Master, and it is not generating ticks
   // 3. The network has been damaged and no ticks are being received by this slave
   //
   // Try to make sure the system is in a safe state...
   // NOTE: Interrupts are disabled here
   SCC_A_SLAVE_Enter_Safe_State();

   Start_slave = 0;
   Error_code_G = ERROR_SCH_WAITING_FOR_START_COMMAND_FROM_MASTER;
   SCH_Report_Status(); // Sch not yet running - do this manually

   // Now wait (indefinitely) for appropriate signal from the master
   do {
      // Wait for 'Slave ID' message to be received 
      do {
         SCC_A_SLAVE_Watchdog_Refresh(); // Must keep feeding the watchdog
         } while ((CAN_messages[0].MCR1 & 0x03) != 0x02);  

      // Got a message - extract the data 
      if ((CAN_messages[0].MCR1 & 0x0c) == 0x08)  // if MSGLST set
         {
         // Ignore lost message
         CAN_messages[0].MCR1 = 0xf7;  // reset MSGLST
         }

      Tick_00 = (tByte) CAN_messages[0].Data[0]; // Get data byte 0 
      Tick_ID = (tByte) CAN_messages[0].Data[1]; // Get data byte 1 

      CAN_messages[0].MCR0 = 0xfd;  // reset NEWDAT, INTPND
      CAN_messages[0].MCR1 = 0xfd;

      if ((Tick_00 == 0x00) && (Tick_ID == SLAVE_ID))
         {
         // Message is correct
         Start_slave = 1;

         // Send ack
         CAN_messages[1].Data[0] = 0x00;     // Set data byte 0
         CAN_messages[1].Data[1] = SLAVE_ID; // Set data byte 1
         CAN_messages[1].MCR1 = 0xE7;  // Send it
         }
      else
         {
         // Not yet received correct message - wait
         Start_slave = 0;
         }
      } while (!Start_slave);

   // Start the scheduler
   IRCON = 0;
   EAL = 1;
   }

/*------------------------------------------------------------------*-

  SCC_A_SLAVE_Update

  This is the scheduler ISR.  It is called at a rate 
  determined by the timer settings in SCC_A_SLAVE_Init().

  This Slave is triggered by USART interrupts.

-*------------------------------------------------------------------*/
void SCC_A_SLAVE_Update(void) interrupt INTERRUPT_CAN_c515c  
   {
   tByte Index;

   // Reset this when tick is received
   Network_error_pin = NO_NETWORK_ERROR;

   // Check tick data - send ack if necessary
   // NOTE: 'START' message will only be sent after a 'time out'
   if (SCC_A_SLAVE_Process_Tick_Message() == SLAVE_ID)
      {
      SCC_A_SLAVE_Send_Ack_Message_To_Master();

      // Feed the watchdog ONLY when a *relevant* message is received
      // (noise on the bus, etc, will not stop the watchdog...)
      //
      // START messages will NOT refresh the slave
      // - Must talk to every slave at regular intervals 
      SCC_A_SLAVE_Watchdog_Refresh();
      }

   // Check the last error codes on the CAN bus via the status register
   if ((CAN_sr & 0x07) != 0)
      {
      Error_code_G = ERROR_SCH_CAN_BUS_ERROR;
      Network_error_pin = NETWORK_ERROR;
   
      // See Infineon c515c manual for error code details
      CAN_error_pin0 = ((CAN_sr & 0x01) == 0);
      CAN_error_pin1 = ((CAN_sr & 0x02) == 0);
      CAN_error_pin2 = ((CAN_sr & 0x04) == 0);
      }
   else
      {
      CAN_error_pin0 = 1;
      CAN_error_pin1 = 1;
      CAN_error_pin2 = 1;
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
   }   

/*------------------------------------------------------------------*-

  SCC_A_SLAVE_Process_Tick_Message()

  The ticks messages are crucial to the operation of this shared-clock
  scheduler: the arrival of a tick message (at regular intervals) 
  invokes the 'Update' ISR, that drives the scheduler.

  The tick messages themselves may contain data.  These data are 
  extracted in this function. 

-*------------------------------------------------------------------*/
tByte SCC_A_SLAVE_Process_Tick_Message(void)
   {
   tByte Tick_ID;

   if ((CAN_messages[0].MCR1 & 0x0c) == 0x08)  // if MSGLST set
      {
      // Indicates that the CAN controller has stored a new 
      // message into this object, while NEWDAT was still set,
      // i.e. the previously stored message is lost.

      // We simply IGNORE this here and reset the flag
      CAN_messages[0].MCR1 = 0xf7;  // reset MSGLST
      }

   // The first byte is the ID of the slave for which the data are
   // intended
   Tick_ID = CAN_messages[0].Data[0];   // Get data byte 0 (Slave ID)

   if (Tick_ID == SLAVE_ID)
      {
      // Only if there is a match do we need to copy these fields
      Tick_message_data_G[0] = CAN_messages[0].Data[1];   
      Tick_message_data_G[1] = CAN_messages[0].Data[2];   
      Tick_message_data_G[2] = CAN_messages[0].Data[3];   
      Tick_message_data_G[3] = CAN_messages[0].Data[4];   
      }

   CAN_messages[0].MCR0 = 0xfd;  // reset NEWDAT, INTPND
   CAN_messages[0].MCR1 = 0xfd;  

   return Tick_ID;
   }


/*------------------------------------------------------------------*-

  SCC_A_SLAVE_Send_Ack_Message_To_Master()

  Slave must send and 'Acknowledge' message to the master, after
  tick messages are received.  NOTE: Only tick messages specifically
  addressed to this slave should be acknowledged.

  The acknowledge message serves two purposes:
  [1] It confirms to the master that this slave is alive & well.
  [2] It provides a means of sending data to the master and - hence
      - to other slaves.

  NOTE: Data transfer between slaves is NOT permitted!

-*------------------------------------------------------------------*/
void SCC_A_SLAVE_Send_Ack_Message_To_Master(void)
   {
   // First byte of message must be slave ID
   CAN_messages[1].Data[0] = SLAVE_ID;   // data byte 0

   CAN_messages[1].Data[1] = Ack_message_data_G[0];   
   CAN_messages[1].Data[2] = Ack_message_data_G[1];   
   CAN_messages[1].Data[3] = Ack_message_data_G[2];   
   CAN_messages[1].Data[4] = Ack_message_data_G[3];   

   // Send the message on the CAN bus
   CAN_messages[1].MCR1 = 0xE7;  // TXRQ, reset CPUUPD
   }


/*------------------------------------------------------------------*-

  SCC_A_SLAVE_Watchdog_Init()

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
void SCC_A_SLAVE_Watchdog_Init(void)   
   {
   // Watchdog timer prescaler (1/16) enabled 
   // Watchdog timer reload value is 0x6B
   // Watchdog period is 103.2 ms (10.0 MHz xtal, c515c)
   WDTREL = 0xEB;
  
   // Start watchdog timer
   WDT  = 1;
   SWDT = 1;     
   }


/*------------------------------------------------------------------*-

  SCC_A_SLAVE_Watchdog_Refresh()

  Feed the watchdog.

-*------------------------------------------------------------------*/
void SCC_A_SLAVE_Watchdog_Refresh(void) reentrant
   {
   WDT  = 1;
   SWDT = 1;
   }    

/*------------------------------------------------------------------*-

  SCC_A_SLAVE_Enter_Safe_State()

  This is the state enterted by the system when:
  (1) The node is powerec up or reset
  (2) The Master node fails, and no working backup is available
  (3) The network has an error
  (4) Tick messages are delayed for any other reason

  Try to ensure that the system is in a 'safe' state in these 
  circumstances.

-*------------------------------------------------------------------*/
void SCC_A_SLAVE_Enter_Safe_State(void)
   {
   // USER DEFINED 
   TRAFFIC_LIGHTS_Display_Safe_Output();
   }   

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/

