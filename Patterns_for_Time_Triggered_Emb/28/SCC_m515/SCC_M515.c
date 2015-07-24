/*------------------------------------------------------------------*-

   SCC_M515.c (v1.01)

  ------------------------------------------------------------------

   *** THIS IS A SHARED-CLOCK (CAN) SCHEDULER (MASTER) ***
   *** FOR 80C515C (etc.) ***

   *** Uses T2 for timing, 16-bit auto reload ***

   *** This version assumes 10 MHz crystal on 515c ***
   *** 6 ms (precise) tick interval ***

   *** Both Master and Slave(s) share the same tick rate ***


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

#include "Delay_T0.h"
#include "TLight_B.h"
#include "SCC_M515.h"

// ------ Public variable definitions ------------------------------

// Four bytes of data (plus ID information) are sent 
tByte Tick_message_data_G[NUMBER_OF_SLAVES][4] = {'M'};  
tByte Ack_message_data_G[NUMBER_OF_SLAVES][4];

// ------ Public variable declarations -----------------------------

// The array of tasks (see Sch51.c)
extern sTask SCH_tasks_G[SCH_MAX_TASKS];

// The error code variable (see Sch51.c)
extern tByte Error_code_G;

// ------ Private variable definitions -----------------------------

static tByte Slave_index_G = 0;
static bit First_ack_G = 1;

// ------ Private function prototypes ------------------------------

static void SCC_A_MASTER_Send_Tick_Message(const tByte);
static bit  SCC_A_MASTER_Process_Ack(const tByte);

static void SCC_A_MASTER_Shut_Down_the_Network(void);

static void SCC_A_MASTER_Enter_Safe_State(void);

static void SCC_A_MASTER_Watchdog_Init(void);
static void SCC_A_MASTER_Watchdog_Refresh(void) reentrant;

static tByte  SCC_A_MASTER_Start_Slave(const tByte)  reentrant;


// ------ Private constants ----------------------------------------

// Do not use ID 0x00 (used to start slaves)
static const tByte MAIN_SLAVE_IDs[NUMBER_OF_SLAVES] = {0x01};
static const tByte BACKUP_SLAVE_IDs[NUMBER_OF_SLAVES] = {0x02};

#define NO_NETWORK_ERROR (1) 
#define NETWORK_ERROR (0)

// ------ Private variables ----------------------------------------

static tWord Slave_reset_attempts_G[NUMBER_OF_SLAVES];

// Slave IDs may be any non-zero tByte value (but all must be different)
static tByte Current_Slave_IDs_G[NUMBER_OF_SLAVES] = {0};


/*------------------------------------------------------------------*-

  SCC_A_MASTER_Init_T2_CAN()

  Scheduler initialisation function.  Prepares scheduler data 
  structures and sets up timer interrupts at required rate.
  Must call this function before using the scheduler.  

-*------------------------------------------------------------------*/
void SCC_A_MASTER_Init_T2_CAN(void) 
   {
   tByte i;
   tByte Message;
   tByte Slave_index;

   // No interrupts (yet)
   EAL = 0;

   // Start the watchdog
   SCC_A_MASTER_Watchdog_Init();

   Network_error_pin = NO_NETWORK_ERROR;

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

   // We allow any combination of ID numbers in slaves
   for (Slave_index = 0; Slave_index < NUMBER_OF_SLAVES; Slave_index++)
      {
      Slave_reset_attempts_G[Slave_index] = 0;
      Current_Slave_IDs_G[Slave_index] = MAIN_SLAVE_IDs[Slave_index];
      }

   // Get ready to send first tick message
   First_ack_G = 1;
   Slave_index_G = 0;

   // ------ Set up the CAN link (begin) ------------------------

   // ---------------- SYSCON Register --------------
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
   CAN_btr1  = 0x34;      // Bit Timing Register
   CAN_btr0  = 0x42; 

   CAN_gms1  = 0xFF;  // Global Mask Short Register 1
   CAN_gms0  = 0xFF;  // Global Mask Short Register 0

   CAN_ugml1 = 0xFF;  // Upper Global Mask Long Register 1
   CAN_ugml0 = 0xFF;  // Upper Global Mask Long Register 0

   CAN_lgml1 = 0xF8;  // Lower Global Mask Long Register 1
   CAN_lgml0 = 0xFF;  // Lower Global Mask Long Register 0

   // --- Configure the 'Tick' Message Object ---
   // 'Message Object 1' is valid
   CAN_messages[0].MCR1  = 0x55;    // Message Control Register 1
   CAN_messages[0].MCR0  = 0x95;    // Message Control Register 0

   // Message direction is transmit
   // Extended 29-bit identifier 
   // These have ID 0x000000 and 5 valid data bytes
   CAN_messages[0].MCFG = 0x5C;      // Message Configuration Register

   CAN_messages[0].UAR1  = 0x00;    // Upper Arbit. Reg. 1
   CAN_messages[0].UAR0  = 0x00;    // Upper Arbit. Reg. 0
   CAN_messages[0].LAR1  = 0x00;    // Lower Arbit. Reg. 1
   CAN_messages[0].LAR0  = 0x00;    // Lower Arbit. Reg. 0

   CAN_messages[0].Data[0] = 0x00;   // data byte 0
   CAN_messages[0].Data[1] = 0x00;   // data byte 1
   CAN_messages[0].Data[2] = 0x00;   // data byte 2
   CAN_messages[0].Data[3] = 0x00;   // data byte 3
   CAN_messages[0].Data[4] = 0x00;   // data byte 4

   // --- Configure the 'Ack' Message Object ---
   
   // 'Message Object 2' is valid
   // NOTE: Object 2 receives *ALL* ack messages
   CAN_messages[1].MCR1  = 0x55;    // Message Control Register 1
   CAN_messages[1].MCR0  = 0x95;    // Message Control Register 0

   // Message direction is receive
   // Extended 29-bit identifier
   // These all have ID: 0x000000FF (5 valid data bytes)
   CAN_messages[1].MCFG = 0x04;      // Message Configuration Register

   CAN_messages[1].UAR1  = 0x00;    // Upper Arbit. Reg. 1
   CAN_messages[1].UAR0  = 0x00;    // Upper Arbit. Reg. 0
   CAN_messages[1].LAR1  = 0xF8;    // Lower Arbit. Reg. 1
   CAN_messages[1].LAR0  = 0x07;    // Lower Arbit. Reg. 0

   // Configure remaining message objects - none are valid
   for (Message = 2; Message <= 14; ++Message)
      {                                 
      CAN_messages[Message].MCR1  = 0x55;  // Message Control Register 1
      CAN_messages[Message].MCR0  = 0x55;  // Message Control Register 0
      }

   // ------------ CAN Control Register ---------------------
   //  reset CCE and INIT
   CAN_cr = 0x00;

   // ------ Set up the CAN link (end) --------------------------

   // ------ Set up Timer 2 (begin) --------------------------------
   // 80c515c, 10 MHz
   // Timer 2 is set to overflow every 6 ms - see text
   // Mode 1 = Timerfunction

   // Prescaler: Fcpu/12
   T2PS = 1;

   // Mode 0 = auto-reload upon timer overflow
   // Preset the timer register with autoreload value
   // NOTE: Timing is same as standard (8052) T2 timing
   // - if T2PS = 1 (otherwise twice as fast as 8052)
   TL2 = 0x78;
   TH2 = 0xEC;
     
   //  Mode 0 for all channels
   T2CON |= 0x11;

   //  timer 2 overflow interrupt is enabled
   ET2 = 1;
   //  timer 2 external reload interrupt is disabled
   EXEN2 = 0;

   // Compare/capture Channel 0 
   // Disabled
   // Compare Register CRC on: 0x0000;
   CRCL = 0x78;
   CRCH = 0xEC;
  
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

  SCC_A_MASTER_Start()

  Starts the scheduler, by enabling interrupts.

  NOTE: Usually called after all regular tasks are added,
  to keep the tasks synchronised.

  NOTE: ONLY THE SCHEDULER INTERRUPT SHOULD BE ENABLED!!! 

-*------------------------------------------------------------------*/
void SCC_A_MASTER_Start(void) 
   {
   tByte Num_active_slaves;
   tByte i;
   bit Slave_replied_correctly;
   tByte Slave_index, Slave_ID;

   // Refresh the watchdog
   SCC_A_MASTER_Watchdog_Refresh();

   // Place system in 'safe state'
   SCC_A_MASTER_Enter_Safe_State();

   // Report error as we wait to start
   Network_error_pin = NETWORK_ERROR;

   Error_code_G = ERROR_SCH_WAITING_FOR_SLAVE_TO_ACK;
   SCH_Report_Status(); // Sch not yet running - do this manually

   // Pause here (300 ms), to time-out all the slaves
   // (This is the means by which we synchronise the network)
   for (i = 0; i < 10; i++)
      {
      Hardware_Delay_T0(30);
      SCC_A_MASTER_Watchdog_Refresh();
      }     

   // Currently disconnected from all slaves
   Num_active_slaves = 0;

   // After the initial (long) delay, all (operational) slaves will have timed out.
   // All operational slaves will now be in the 'READY TO START' state
   // Send them a 'slave id' message to get them started
   Slave_index = 0;
   do {
      // Refresh the watchdog
      SCC_A_MASTER_Watchdog_Refresh();

      // Find the slave ID for this slave 
      Slave_ID = (tByte) Current_Slave_IDs_G[Slave_index]; 

      Slave_replied_correctly = SCC_A_MASTER_Start_Slave(Slave_ID);

      if (Slave_replied_correctly)
         {
         Num_active_slaves++;
         Slave_index++;
         }
      else
         {
         // Slave did not reply correctly 
         // - try to switch to backup device (if available)
         if (Current_Slave_IDs_G[Slave_index] != BACKUP_SLAVE_IDs[Slave_index])
            {
            // There is a backup available: switch to backup and try again
            Current_Slave_IDs_G[Slave_index] = BACKUP_SLAVE_IDs[Slave_index];
            }
         else
            {
            // No backup available (or backup failed too) - have to continue
            Slave_index++;
            }
         }
      } while (Slave_index < NUMBER_OF_SLAVES);

   // DEAL WITH CASE OF MISSING SLAVE(S) HERE ...
   if (Num_active_slaves < NUMBER_OF_SLAVES)
      {
      // User-defined error handling here...
      // 1 or more slaves have not replied
      // NOTE: In some circumstances you may wish to abort if slaves are missing
      // - or reconfigure the network.

      // Simplest solution is to display an error and carry on
      // (this is what we do here)      
      Error_code_G = ERROR_SCH_ONE_OR_MORE_SLAVES_DID_NOT_START;
      Network_error_pin = NETWORK_ERROR;
      }
   else
      {
      Error_code_G = 0;
      Network_error_pin = NO_NETWORK_ERROR;
      }

   // Start the scheduler
   IRCON = 0;
   EAL = 1;   
   }

/*------------------------------------------------------------------*-

  SCC_A_MASTER_Update_T2

  This is the scheduler ISR.  It is called at a rate determined by 
  the timer settings in SCC_A_MASTER_Init_T2().  This version is 
  triggered by Timer 2 interrupts: timer is automatically reloaded.
 
-*------------------------------------------------------------------*/
void SCC_A_MASTER_Update_T2(void) interrupt INTERRUPT_Timer_2_Overflow  
   {
   tByte Index;
   tByte Previous_slave_index;
   bit Slave_replied_correctly;

   TF2 = 0;  // Must clear this. 

   // Refresh the watchdog
   SCC_A_MASTER_Watchdog_Refresh();

   // Default
   Network_error_pin = NO_NETWORK_ERROR;

   // Keep track of the current slave
   Previous_slave_index = Slave_index_G;   // First value of prev slave is 0...

   if (++Slave_index_G >= NUMBER_OF_SLAVES)
      {
      Slave_index_G = 0;
      }    

   // Check that the appropriate slave responded to the previous message:
   // (if it did, store the data sent by this slave)
   if (SCC_A_MASTER_Process_Ack(Previous_slave_index) == RETURN_ERROR)
      {
      Error_code_G = ERROR_SCH_LOST_SLAVE;
      Network_error_pin = NETWORK_ERROR;

      // If we have lost contact with a slave, we attempt to
      // switch to a backup device (if one is available)
      if (Current_Slave_IDs_G[Slave_index_G] != BACKUP_SLAVE_IDs[Slave_index_G])
         {
         // There is a backup available: switch to backup and try again
         Current_Slave_IDs_G[Slave_index_G] = BACKUP_SLAVE_IDs[Slave_index_G];
         }
      else
         {
         // There is no backup available (or we are already using it) 
         // Try main device.
         Current_Slave_IDs_G[Slave_index_G] = MAIN_SLAVE_IDs[Slave_index_G];
         }

      // Try to connect to the slave
      Slave_replied_correctly = SCC_A_MASTER_Start_Slave(Current_Slave_IDs_G[Slave_index_G]);

      if (!Slave_replied_correctly)
         {
         // No backup available (or backup failed too) - we shut down
         // OTHER BEHAVIOUR MAY BE MORE APPROPRIATE IN YOUR APPLICATION
         SCC_A_MASTER_Shut_Down_the_Network();
         }
      }
  
   // Send 'tick' message to all connected slaves
   // (sends one data byte to the current slave)
   SCC_A_MASTER_Send_Tick_Message(Slave_index_G);

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
            SCH_tasks_G[Index].RunMe += 1;  // Incr. the 'Run Me' flag

            if (SCH_tasks_G[Index].Period)
               {
               // Schedule rperiodic tasks to run again
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

  SCC_A_MASTER_Send_Tick_Message()

  This function sends a tick message, over the CAN network.
  The receipt of this message will cause an interrupt to be generated
  in the slave(s): this invoke the scheduler 'update' function
  in the slave(s).

-*------------------------------------------------------------------*/
void SCC_A_MASTER_Send_Tick_Message(const tByte SLAVE_INDEX) 
   {
   // Find the slave ID for this slave 
   // ALL SLAVES MUST HAVE A UNIQUE (non-zero) ID
   tByte Slave_ID = (tByte) Current_Slave_IDs_G[SLAVE_INDEX];
   CAN_messages[0].Data[0] = Slave_ID;   

   // Fill the data fields 
   CAN_messages[0].Data[1] = Tick_message_data_G[SLAVE_INDEX][0];   
   CAN_messages[0].Data[2] = Tick_message_data_G[SLAVE_INDEX][1];   
   CAN_messages[0].Data[3] = Tick_message_data_G[SLAVE_INDEX][2];   
   CAN_messages[0].Data[4] = Tick_message_data_G[SLAVE_INDEX][3];   

   // Send the message on the CAN bus
   CAN_messages[0].MCR1 = 0xE7;  // TXRQ, reset CPUUPD
   }

/*------------------------------------------------------------------*-

  SCC_A_MASTER_Process_Ack()

  Make sure the slave (SLAVE_ID) has acknowledged the previous
  message that was sent.  If it has, extract the message data
  from the USART hardware: if not, call the appropriate error
  handler.

  PARAMS:   The index of the slave. 

  RETURNS:  RETURN_NORMAL - Ack received (data in Ack_message_data_G)
            RETURN_ERROR  - No ack received (-> no data)

-*------------------------------------------------------------------*/

bit SCC_A_MASTER_Process_Ack(const tByte SLAVE_INDEX) 
   {
   tByte Ack_ID, Slave_ID;

   // First time this is called there is no ack tick to check 
   // - we simply return 'OK'
   if (First_ack_G)
      {
      First_ack_G = 0;
      return RETURN_NORMAL;
      }

   if ((CAN_messages[1].MCR1 & 0x03) == 0x02)    // if NEWDAT
      {
      // An ack message was received
      //
      // Extract the data
      Ack_ID = CAN_messages[1].Data[0];   // Get data byte 0

      Ack_message_data_G[SLAVE_INDEX][0] = CAN_messages[1].Data[1];   
      Ack_message_data_G[SLAVE_INDEX][1] = CAN_messages[1].Data[2];   
      Ack_message_data_G[SLAVE_INDEX][2] = CAN_messages[1].Data[3];   
      Ack_message_data_G[SLAVE_INDEX][3] = CAN_messages[1].Data[4];   

      CAN_messages[1].MCR0 = 0xfd;  // reset NEWDAT, INTPND
      CAN_messages[1].MCR1 = 0xfd;
      
      // Find the slave ID for this slave 
      Slave_ID = (tByte) Current_Slave_IDs_G[SLAVE_INDEX];

      if (Ack_ID == Slave_ID)
         {
         return RETURN_NORMAL;
         }
      }

   // No message, or ID incorrect
   return RETURN_ERROR;  
   }


/*------------------------------------------------------------------*-

  SCC_A_MASTER_Shut_Down_the_Network()

  This function will be called when a slave fails to 
  acknowledge a tick message.

-*------------------------------------------------------------------*/
void SCC_A_MASTER_Shut_Down_the_Network(void)
   {
   EAL = 0;

   while(1)
      {
      SCC_A_MASTER_Watchdog_Refresh();
      }  
   }

/*------------------------------------------------------------------*-

  SCC_A_MASTER_Enter_Safe_State()

  This is the state enterted by the system when:
  (1) The node is powered up or reset
  (2) The Master node cannot detect a slave
  (3) The network has an error

  Try to ensure that the system is in a 'safe' state in these 
  circumstances.

-*------------------------------------------------------------------*/
void SCC_A_MASTER_Enter_Safe_State(void)
   {
   // USER DEFINED - Edit as required

   TRAFFIC_LIGHTS_Display_Safe_Output();
   } 

/*------------------------------------------------------------------*-

   SCC_A_MASTER_Watchdog_Init()

  This function sets up the watchdog timer.

-*------------------------------------------------------------------*/
void SCC_A_MASTER_Watchdog_Init(void)   
   {
   // Watchdog timer prescaler (1/16) enabled 
   // Watchdog timer reload value is 0x6B
   // Oscillator is 10 MHz -> watchdog period is ~103 ms
   WDTREL = 0xEB;
  
   // Start watchdog timer
   WDT  = 1;
   SWDT = 1;
   }

/*------------------------------------------------------------------*-

  SCC_A_MASTER_Watchdog_Refresh()

  Feed the internal c515c watchdog.

-*------------------------------------------------------------------*/
void SCC_A_MASTER_Watchdog_Refresh(void) reentrant
   {
   WDT = 1; 
   SWDT = 1;
   }   

/*------------------------------------------------------------------*-

  SCC_A_MASTER_Start_Slave()

  Try to connect to a slave device.

-*------------------------------------------------------------------*/
tByte SCC_A_MASTER_Start_Slave(const tByte SLAVE_ID) reentrant
   {
   tByte Slave_replied_correctly = 0;

//   tByte Slave_ID;
   tByte Ack_ID, Ack_00;

   // Send a 'Slave ID' message
   CAN_messages[0].Data[0] = 0x00;  // Not a valid slave ID    
   CAN_messages[0].Data[1] = SLAVE_ID;    
   CAN_messages[0].MCR1 = 0xE7;  // Send it

   // Wait to give slave time to reply
   Hardware_Delay_T0(5);   

   // Check we had a reply
   if ((CAN_messages[1].MCR1 & 0x03) == 0x02)    // if NEWDAT
      {
      // An ack message was received - extract the data
      Ack_00 = (tByte) CAN_messages[1].Data[0];  // Get data byte 0
      Ack_ID = (tByte) CAN_messages[1].Data[1];  // Get data byte 1

      CAN_messages[1].MCR0 = 0xfd;  // reset NEWDAT, INTPND
      CAN_messages[1].MCR1 = 0xfd;

      if ((Ack_00 == 0x00) && (Ack_ID == SLAVE_ID)) 
         {
         Slave_replied_correctly = 1;
         }
      }

   return Slave_replied_correctly;
   }
  

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
