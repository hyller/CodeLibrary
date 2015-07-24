/*------------------------------------------------------------------*-

   hSCH51.C (v1.00) 

  ------------------------------------------------------------------

   /// HYBRID SCHEDULER CORE ///

   *** THESE ARE THE CORE SCHEDULER FUNCTIONS ***
   --- These functions may be used with all 8051 devices ---

   *** hSCH_MAX_TASKS *must* be set by the user ***
   --- see "Sch51.h" ---

   *** Includes power-saving mode ***
   --- You *MUST* confirm that the power-down mode is adapted ---
   --- to match your chosen device (usually only necessary with 
   --- Extended 8051s, such as c515c, c509, etc ---

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

#include "hSch51.h"

// ------ Public variable definitions ------------------------------

// The array of tasks
sTaskH hSCH_tasks_G[hSCH_MAX_TASKS];

// Used to display the error code
// See Main.H for details of error codes
// See Port.H for details of the error port
tByte Error_code_G = 0;

// ------ Private function prototypes ------------------------------

static void hSCH_Go_To_Sleep(void);

// ------ Private variables ----------------------------------------

// Keeps track of time since last error was recorded (see below)
static tWord Error_tick_count_G;

// The code of the last error (reset after ~1 minute)
static tByte Last_error_code_G;


/*------------------------------------------------------------------*-

  hSCH_Dispatch_Tasks()

  This is the 'dispatcher' function.  When a task (function)
  is due to run, hSCH_Dispatch_Tasks() will run it.
  This function must be called (repeatedly) from the main loop.

-*------------------------------------------------------------------*/
void hSCH_Dispatch_Tasks(void) 
   {
   tByte Index;

   // Dispatches (runs) the next task (if one is ready)
   for (Index = 0; Index < hSCH_MAX_TASKS; Index++)
      {
      // Only dispatching co-operative tasks
      if ((hSCH_tasks_G[Index].Co_op) && (hSCH_tasks_G[Index].RunMe > 0)) 
         {
         (*hSCH_tasks_G[Index].pTask)();  // Run the task

         hSCH_tasks_G[Index].RunMe -= 1;   // Reset / reduce RunMe flag

         // Periodic tasks will automatically run again
         // - if this is a 'one shot' task, remove it from the array
         if (hSCH_tasks_G[Index].Period == 0)
            {
            // Faster than call to delete task
            hSCH_tasks_G[Index].pTask = 0;
            }
         }
      }

   // Report system status
   hSCH_Report_Status();  

   // The scheduler enters idle mode at this point 
   hSCH_Go_To_Sleep();          
   }

/*------------------------------------------------------------------*-

  hSCH_Add_Task()

  Causes a task (function) to be executed at regular intervals 
  or after a user-defined delay

  Fn_P  - The name of the function which is to be scheduled.
          NOTE: All scheduled functions must be 'void, void' -
          that is, they must take no parameters, and have 
          a void return type. 
                   
  Del   - The interval (TICKS) before the task is first executed

  Rep   - If 'Rep' is 0, the function is only called once,
          at the time determined by 'Del'.  If Rep is non-zero,
          then the function is called repeatedly at an interval
          determined by the vakue of Rep (see below for examples
          that should help clarify this).

  Co-op - Set to 1 if it a co-op task; 0 if pre-emptive

  RETN:   The position in the task array at which the task has been added.
          If the return value is hSCH_MAX_TASKS then the task could not be
          added to the array (there was insufficient space).  If the
          return value is < hSCH_MAX_TASKS, then the task was added 
          successfully.  

          Note: this return value may be required, if a task is
          to be subsequently deleted - see hSCH_Delete_Task().


  EXAMPLES:

  Task_ID = hSCH_Add_Task(Do_X,1000,0,0);
  Causes the function Do_X() to be executed once after 1000 ticks.
  (Pre-emptive task)          

  Task_ID = hSCH_Add_Task(Do_X,0,1000,1);
  Causes the function Do_X() to be executed regularly, every 1000 ticks.            
  (co-operative task)          

  Task_ID = hSCH_Add_Task(Do_X,300,1000,0);
  Causes the function Do_X() to be executed regularly, every 1000 ticks.
  Task will be first executed at T = 300 ticks, then 1300, 2300, etc.            
  (Pre-emptive task)          
 
-*------------------------------------------------------------------*/
tByte hSCH_Add_Task(void (code* Fn_p)(), // Task function pointer
                   tWord   Del,    // Num ticks 'til task first runs 
                   tWord   Per,    // Num ticks between repeat runs
                   bit     Co_op)  // Co_op / pre_emp
   {
   tByte Index = 0;
   
   // First find a gap in the array (if there is one)
   while ((hSCH_tasks_G[Index].pTask != 0) && (Index < hSCH_MAX_TASKS))
      {
      Index++;
      } 
   
   // Have we reached the end of the list?   
   if (Index == hSCH_MAX_TASKS)
      {
      // Task list is full
      //
      // Set the global error variable
      Error_code_G = ERROR_SCH_TOO_MANY_TASKS;

      // Also return an error code
      return hSCH_MAX_TASKS;  
      }
      
   // If we're here, there is a space in the task array
   hSCH_tasks_G[Index].pTask = Fn_p;
     
   hSCH_tasks_G[Index].Delay  = Del;
   hSCH_tasks_G[Index].Period = Per;

   hSCH_tasks_G[Index].Co_op = Co_op;

   hSCH_tasks_G[Index].RunMe  = 0;

   return Index; // return position of task (to allow later deletion)
   }

/*------------------------------------------------------------------*-

  hSCH_Delete_Task()

  Removes a task from the scheduler.  Note that this does
  *not* delete the associated function from memory: 
  it simply means that it is no longer called by the scheduler. 

  PARAMS:   Task_index - The task index.  Provided by hSCH_Add_Task(). 

  RETURNS:  RETURN_ERROR or RETURN_NORMAL

-*------------------------------------------------------------------*/
bit hSCH_Delete_Task(tByte Task_index) 
   {
   bit Return_code;

   if (hSCH_tasks_G[Task_index].pTask == 0)
      {
      // No task at this location...
      //
      // Set the global error variable
      Error_code_G = ERROR_SCH_CANNOT_DELETE_TASK;

      // ...also return an error code
      Return_code = RETURN_ERROR;
      }
   else
      {
      Return_code = RETURN_NORMAL;
      }      
   
   hSCH_tasks_G[Task_index].pTask   = 0;
   hSCH_tasks_G[Task_index].Delay   = 0;
   hSCH_tasks_G[Task_index].Period  = 0;

   hSCH_tasks_G[Task_index].RunMe   = 0;

   return Return_code;       // return status
   }


/*------------------------------------------------------------------*-

  hSCH_Report_Status()

  Simple function to display error codes.

  This version displays code on a port with attached LEDs:
  adapt, if required, to report errors over serial link, etc.

  Errors are only displayed for a limited period 
  (60000 ticks = 1 minute at 1ms tick interval).
  After this the the error code is reset to 0. 

  This code may be easily adapted to display the last
  error 'for ever': this may be appropriate in your
  application.

  See Chapter 14 for further information.
 
-*------------------------------------------------------------------*/
void hSCH_Report_Status(void)
   {
#ifdef SCH_REPORT_ERRORS
   // ONLY APPLIES IF WE ARE REPORTING ERRORS
   // Check for a new error code
   if (Error_code_G != Last_error_code_G)
      {
      // Negative logic on LEDs assumed
      Error_port = 255 - Error_code_G;
      
      Last_error_code_G = Error_code_G;

      if (Error_code_G != 0)
         {
         Error_tick_count_G = 60000;
         }
      else
         {
         Error_tick_count_G = 0;
         }
      }
   else
      {
      if (Error_tick_count_G != 0)
         {
         if (--Error_tick_count_G == 0)
            {
            Error_code_G = 0; // Reset error code
            }
         }
      }
#endif
   }


/*------------------------------------------------------------------*-

  hSCH_Go_To_Sleep()

  This scheduler enters 'idle mode' between clock ticks
  to save power.  The next clock tick will return the processor
  to the normal operating state.

  Note: a slight performance improvement is possible if this
  function is implemented as a macro, or if the code here is simply 
  pasted into the 'dispatch' function.  

  However, by making this a function call, it becomes easier 
  - during development - to assess the performance of the 
  scheduler, using the 'performance analyser' in the Keil 
  hardware simulator. See Chapter 14 for examples for this. 

  *** May wish to disable this if using a watchdog ***

  *** ADAPT AS REQUIRED FOR YOUR HARDWARE ***

-*------------------------------------------------------------------*/
void hSCH_Go_To_Sleep()
   {
   PCON |= 0x01;    // Enter idle mode (generic 8051 version)

   // Entering idle mode requires TWO consecutive instructions 
   // on 80c515 / 80c505 - to avoid accidental triggering
   //PCON |= 0x01;    // Enter idle mode (#1)
   //PCON |= 0x20;    // Enter idle mode (#2)
   }


/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/


