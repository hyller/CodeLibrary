/*------------------------------------------------------------------*-

   SCU_Am.c (v1.00)

  ------------------------------------------------------------------

   This is an implementation of SCU SCHEDULER (LOCAL) for 8051/52.
   AND an implementation of SCU SCHEDULER (RS-232) for 8051/52.

   --- See Chapter 27 ---

   *** MASTER NODE ***
   *** CHECKS FOR SLAVE ACKNOWLEDEMENTS ***
   *** Local / RS-232 version (no 'enable' support) ***

   *** Uses 1232 watchdog timer ***

   *** Both Master and Slave share the same tick rate (5 ms) ***


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

#include "SCU_Am.H"
#include "Delay_T0.h"
#include "TLight_B.h"

// ------ Public variable definitions ------------------------------

tByte Tick_message_data_G[NUMBER_OF_SLAVES] = {'M'};  
tByte Ack_message_data_G[NUMBER_OF_SLAVES];

// ------ Public variable declarations -----------------------------

// The array of tasks (see Sch51.c)
extern sTask SCH_tasks_G[SCH_MAX_TASKS];

// The error code variable (see Sch51.c)
extern tByte Error_code_G;

// ------ Private variable definitions -----------------------------

static tByte Current_slave_index_G = 0;
static bit First_ack_G = 1;
static bit WATCHDOG_state_G = 0;

// ------ Private function prototypes ------------------------------

static void SCU_A_MASTER_Reset_the_Network(void);
static void SCU_A_MASTER_Shut_Down_the_Network(void);
static void SCU_A_MASTER_Switch_To_Backup_Slave(const tByte);

static void SCU_A_MASTER_Send_Tick_Message(const tByte);
static bit  SCU_A_MASTER_Process_Ack(const tByte);

static void  SCU_A_MASTER_Watchdog_Init(void);
static void  SCU_A_MASTER_Watchdog_Refresh(void) reentrant;

// ------ Private constants ----------------------------------------

// Slave IDs may be any NON-ZERO tByte value (all must be different)
// NOTE: ID 0x00 is for error handling.
static const tByte MAIN_SLAVE_IDs[NUMBER_OF_SLAVES] = {0x31};
static const tByte BACKUP_SLAVE_IDs[NUMBER_OF_SLAVES] = {0x31};

#define NO_NETWORK_ERROR (1) 
#define NETWORK_ERROR (0)

// Adjust (if required) to increase interval between network resets
// (in the event of sustained network error)
#define SLAVE_RESET_INTERVAL 0U

// ------ Private variables ----------------------------------------

static tWord Slave_reset_attempts_G[NUMBER_OF_SLAVES];

// See MAIN_SLAVE_IDs[] above
static tByte Current_Slave_IDs_G[NUMBER_OF_SLAVES] = {0};

static bit Message_byte_G = 1;

/*------------------------------------------------------------------*-

  SCU_A_MASTER_Init_T1_T2()

  Scheduler initialisation function.  Prepares scheduler data 
  structures and sets up timer interrupts at required rate.
  You must call this function before using the scheduler.  

  BAUD_RATE - The required baud rate.

-*------------------------------------------------------------------*/
void SCU_A_MASTER_Init_T1_T2(const tWord BAUD_RATE) 
   {
   tByte Task_index;
   tByte Slave_index;

   // No interrupts (yet)
   EA = 0;

   // Start the watchdog
   SCU_A_MASTER_Watchdog_Init();

   Network_error_pin = NO_NETWORK_ERROR;

   // ------ Set up the scheduler ----------------------------------
   // Sort out the tasks
   for (Task_index = 0; Task_index < SCH_MAX_TASKS; Task_index++) 
      {
      SCH_Delete_Task(Task_index);
      }

   // Reset the global error variable
   // - SCH_Delete_Task() will generate an error code, 
   //   (because the task array is empty)
   Error_code_G = 0;

   // We allow any combination of ID numbers in slaves
   // - but reserve ID 0x00
   for (Slave_index = 0; Slave_index < NUMBER_OF_SLAVES; Slave_index++)
      {
      Slave_reset_attempts_G[Slave_index] = 0;
      Current_Slave_IDs_G[Slave_index] = MAIN_SLAVE_IDs[Slave_index];
      }

   // ------ Set the baud rate (begin) -----------------------------
   PCON &= 0x7F;   // Set SMOD bit to 0 (don't double baud rates)

   //  Receiver enabled
   //  *9-bit data*, 1 start bit, 1 stop bit, variable baud rate (asynchronous)
   SCON = 0xD2;

   TMOD |= 0x20;   // T1 in mode 2, 8-bit auto reload

   TH1 = (256 - (tByte)((((tLong)OSC_FREQ / 100) * 3125) 
            / ((tLong) BAUD_RATE * OSC_PER_INST * 1000)));

   TL1 = TH1;  
   TR1 = 1;  // Run the timer
   TI = 1;   // Send first character (dummy)
   // ------ Set the baud rate (end) -------------------------------

   // Serial interrupt *NOT* enabled
   ES = 0;
   // ------ Set up the serial link (end) --------------------------

   // ------ Set up Timer 2 (begin) --------------------------------
   // Crystal is assumed to be 12 MHz, 12 osc/increment
   //
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
   // ------ Set up Timer 2 (end) ----------------------------------
   }

/*------------------------------------------------------------------*-

  SCU_A_MASTER_Start()

  Starts the scheduler, by enabling interrupts.

  NOTE: Usually called after all regular tasks are added,
  to keep the tasks synchronised.

  NOTE: ONLY THE SCHEDULER INTERRUPT SHOULD BE ENABLED!!! 

  NOTE: Delays here (2ms) assume a baud rate of at leadt 9600 baud.
  You will need to fine-tune this code if you opt for a lower baud
  rate.
 
-*------------------------------------------------------------------*/
void SCU_A_MASTER_Start(void) 
   {
   tByte Slave_ID;
   tByte Num_active_slaves;
   tByte Id, i;
   bit First_byte = 0;
   bit Slave_replied_correctly;
   tByte Slave_index;

   // Refresh the watchdog
   SCU_A_MASTER_Watchdog_Refresh();

   // Place system in 'safe state'
   SCU_A_MASTER_Enter_Safe_State();

   // Report error as we wait to start
   Network_error_pin = NETWORK_ERROR;

   Error_code_G = ERROR_SCH_WAITING_FOR_SLAVE_TO_ACK;
   SCH_Report_Status(); // Sch not yet running - do this manually

   // Pause here (3000 ms), to time-out all the slaves
   // (This is the means by which we synchronise the network)
   for (i = 0; i < 100; i++)
      {
      Hardware_Delay_T0(30);
      SCU_A_MASTER_Watchdog_Refresh();
      }     

   // Currently disconnected from all slaves
   Num_active_slaves = 0;

   // After the initial (long) delay, all (operational) slaves will have timed out.
   // All operational slaves will now be in the 'READY TO START' state
   // Send them a (single-byte) message to get them started
   // DO THIS TWICE IN A ROW, WITH COMMAND BIT 
   // This cannot happen under normal circumstances
   Slave_index = 0;
   do {
      // Refresh the watchdog
      SCU_A_MASTER_Watchdog_Refresh();

      // Clear 'first byte' flag
      First_byte = 0;

      // Find the slave ID for this slave 
      Slave_ID = (tByte) Current_Slave_IDs_G[Slave_index];  

      // Send a 'Slave ID' message
      TI = 0;
      TB8 = 1; // Set command bit
      SBUF = Slave_ID;          

      // Wait to give slave time to reply
      Hardware_Delay_T0(5);   

      // Check we had a reply 
      if (RI == 1) 
         {
         // Get the reply data
         Id = (tByte) SBUF;  
         RI = 0;

         // Check reply - with command bit
         if ((Id == Slave_ID) && (RB8 == 1))
            {
            First_byte = 1;
            }
         }   

      // Send second byte
      TI = 0;
      TB8 = 1;
      SBUF = Slave_ID;   

      // Wait to give slave time to reply
      Hardware_Delay_T0(5);   

      // Check we had a reply
      Slave_replied_correctly = 0;
      if (RI != 0)
         {
         // Get the reply data
         Id = (tByte) SBUF;  
         RI = 0;

         if ((Id == Slave_ID) && (RB8 == 1) && (First_byte == 1))
            {
            Slave_replied_correctly = 1;
            }
         }

      if (Slave_replied_correctly)
         {
         // Slave responded correctly
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
            // NOTE: we don't abort the loop, to allow for more flexible
            // error handling (below).
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

      // Here we display error and shut down the network
      Error_code_G = ERROR_SCH_ONE_OR_MORE_SLAVES_DID_NOT_START;
      SCU_A_MASTER_Shut_Down_the_Network();
      }
   else
      {
      Error_code_G = 0;
      Network_error_pin = NO_NETWORK_ERROR;
      }

   // Get ready to send first tick message
   Message_byte_G = 1;
   First_ack_G = 1;
   Current_slave_index_G = 0;

   // Start the scheduler
   EA = 1;   
   }


/*------------------------------------------------------------------*-

  SCU_A_MASTER_Update_T2

  This is the scheduler ISR.  It is called at a rate determined by 
  the timer settings in SCU_A_MASTER_Init_T2().  This version is 
  triggered by Timer 2 interrupts: timer is automatically reloaded.

-*------------------------------------------------------------------*/
void SCU_A_MASTER_Update_T2(void) interrupt INTERRUPT_Timer_2_Overflow  
   {
   tByte Task_index;
   tByte Previous_slave_index;

   TF2 = 0; // Must manually clear this. 

   // Refresh the watchdog
   SCU_A_MASTER_Watchdog_Refresh();

   // Default
   Network_error_pin = NO_NETWORK_ERROR;

   // Keep track of the current slave
   // FIRST VALUE IS 0
   Previous_slave_index = Current_slave_index_G;   

   // Assume 2-byte messages sent and received
   // - it takes two ticks to deliver each message
   if (Message_byte_G == 0)
      {
      Message_byte_G = 1;  
      }
   else
      {
      Message_byte_G = 0;

      if (++Current_slave_index_G >= NUMBER_OF_SLAVES)
         {
         Current_slave_index_G = 0;
         }
      }

   // Check that the appropriate slave responded to the previous message:
   // (if it did, store the data sent by this slave)
   if (SCU_A_MASTER_Process_Ack(Previous_slave_index) == RETURN_ERROR)
      {
      Network_error_pin = NETWORK_ERROR;
      Error_code_G = ERROR_SCH_LOST_SLAVE;

      // If we have lost contact with a slave, we attempt to
      // switch to a backup device (if one is available) as we reset the network
      //
      // NOTE: We don't do this every tick (or the the network will be constantly reset)
      //
      // Choose a value of SLAVE_RESET_INTERVAL to allow resets (say) every 5 seconds
      if (++Slave_reset_attempts_G[Previous_slave_index] >= SLAVE_RESET_INTERVAL)
         {
         SCU_A_MASTER_Reset_the_Network();
         }
      }
   else
      {
      // Reset this counter
      Slave_reset_attempts_G[Previous_slave_index] = 0;
      }

   // Send 'tick' message to all connected slaves
   // (sends one data byte to the current slave)
   SCU_A_MASTER_Send_Tick_Message(Current_slave_index_G);

   // NOTE: calculations are in *TICKS* (not milliseconds)
   for (Task_index = 0; Task_index < SCH_MAX_TASKS; Task_index++)
      {
      // Check if there is a task at this location
      if (SCH_tasks_G[Task_index].pTask)
         {
         if (SCH_tasks_G[Task_index].Delay == 0)
            {
            // The task is due to run
            SCH_tasks_G[Task_index].RunMe += 1;  // Increment the run flag

            if (SCH_tasks_G[Task_index].Period)
               {
               // Schedule periodic tasks to run again
               SCH_tasks_G[Task_index].Delay = SCH_tasks_G[Task_index].Period;
               }
            }
         else
            {
            // Not yet ready to run: just decrement the delay 
            SCH_tasks_G[Task_index].Delay -= 1;
            }
         }         
      }
   }   

/*------------------------------------------------------------------*-

  SCU_A_MASTER_Send_Tick_Message()

  This function sends a tick message, over the USART network.
  The receipt of this message will cause an interrupt to be generated
  in the slave(s): this invoke the scheduler 'update' function
  in the slave(s).

-*------------------------------------------------------------------*/
void SCU_A_MASTER_Send_Tick_Message(const tByte SLAVE_INDEX) 
   {
   tLong Timeout;

   // Find the slave ID for this slave 
   tByte Slave_ID = (tByte) Current_Slave_IDs_G[SLAVE_INDEX];

   // Sending one byte of data at a time, depending on index value
   // If Message_byte_G is 0, send first byte (the slave ID)
   if (Message_byte_G == 0)
      {
      Timeout = 0;
      while ((++Timeout) && (TI == 0));  

      if (Timeout == 0)
         {
         // UART did not respond - error
         Error_code_G = ERROR_USART_TI; 
         return;
         } 

      TI = 0;                                            
      TB8 = 1;  // Set 'Command' bit
      SBUF = Slave_ID;
      }
   else
      {
      // Message_byte_G is 1, send the data byte 
      Timeout = 0;
      while ((++Timeout) && (TI == 0));  

      if (Timeout == 0)
         {
         // usart did not respond - error
         Error_code_G = ERROR_USART_TI; 
         return;
         } 

      TI = 0;
      TB8 = 0;
      SBUF = Tick_message_data_G[SLAVE_INDEX];
      }
 
   // Data sent - return
   }


/*------------------------------------------------------------------*-

  SCU_A_MASTER_Process_Ack()

  Make sure the slave (SLAVE_ID) has acknowledged the previous
  message that was sent.  If it has, extract the message data
  from the USART hardware: if not, call the appropriate error
  handler.

  Slave_index - The index of the slave. 

  RETURNS:  RETURN_NORMAL - Ack received (data in Ack_message_data_G)
            RETURN_ERROR  - No ack received (-> no data)

-*------------------------------------------------------------------*/

bit SCU_A_MASTER_Process_Ack(const tByte Slave_index) 
   {
   tByte Message_contents;
   tByte Slave_ID;

   // First time this is called there is no ack tick to check 
   // - we simply return 'OK'
   if (First_ack_G)
      {
      First_ack_G = 0;
      return RETURN_NORMAL;
      }

   // Find the slave ID for this slave 
   Slave_ID = (tByte) Current_Slave_IDs_G[Slave_index];

   // Data should already be in the buffer
   if (RI == 0)
      {
      // Slave has not replied to last tick message

      // Set error LED
      Network_error_pin = NETWORK_ERROR;

      return RETURN_ERROR;
      } 

   // There is data - get it
   Message_contents = (tByte) SBUF;
   RI = 0;

   // This is the reply to the last message 
   // - reverse the message byte interpretation 
   if (Message_byte_G == 1)
      {
      // Check the 'command bit' is set
      if (RB8 == 1)
         {
         // Check that the ID is correct
         if (Slave_ID == (tByte) Message_contents)
            {
            // Required Ack message was received
            return RETURN_NORMAL;
            }
         }

       // Something is wrong...

       // Set error LED
       Network_error_pin = NETWORK_ERROR;

       return RETURN_ERROR;
       }
    else
       {  
       // There *ARE* data available 
       // Extract the data from the slave message
       //
       // NOTE: We *assume* these data are OK
       // - you may wish to send crucial data twice, etc.
       Ack_message_data_G[Slave_index] = Message_contents;
  
       return RETURN_NORMAL;  // return the slave data
       }
   }

/*------------------------------------------------------------------*-

  SCU_A_MASTER_Reset_the_Network()

  This function resets (that is, restarts) the whole network.

-*------------------------------------------------------------------*/
void SCU_A_MASTER_Reset_the_Network(void)
   {
   EA = 0;   // Disable interrupts
   while(1); // Watchdog will time out
   }

/*------------------------------------------------------------------*-

  SCU_A_MASTER_Shut_Down_the_Network()

  This function shuts down the whole network.

-*------------------------------------------------------------------*/
void SCU_A_MASTER_Shut_Down_the_Network(void)
   {
   EA = 0; // Disable interrupts

   Network_error_pin = NETWORK_ERROR;
   SCH_Report_Status(); // Sch not running - do this manually

   while(1)
      {
      SCU_A_MASTER_Watchdog_Refresh();
      }
   }


/*------------------------------------------------------------------*-

  SCU_A_MASTER_Enter_Safe_State()

  This is the state enterted by the system when:
  (1) The node is powered up or reset
  (2) The Master node cannot detect a slave
  (3) The network has an error

  Try to ensure that the system is in a 'safe' state in these 
  circumstances.

-*------------------------------------------------------------------*/
void SCU_A_MASTER_Enter_Safe_State(void)
   {
   // USER DEFINED - Edit as required
   TRAFFIC_LIGHTS_Display_Safe_Output();
   } 

/*------------------------------------------------------------------*-

  SCU_A_MASTER_Watchdog_Init()

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
void SCU_A_MASTER_Watchdog_Init(void)   
   {
   // INIT NOT REQUIRED FOR 1232 EXTERNAL WATCHDOG
   // - May be required wwith different watchdog hardware
   //
   // Edit as required
   }


/*------------------------------------------------------------------*-

  SCU_A_MASTER_Watchdog_Refresh()

  Feed the external (1232) watchdog.

  Timeout is between ~60 and 250 ms (hardware dependent)

  Assumes external 1232 watchdog

-*------------------------------------------------------------------*/
void SCU_A_MASTER_Watchdog_Refresh(void) reentrant
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
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
