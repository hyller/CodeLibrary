/*------------------------------------------------------------------*-
  
   SCH51.H (v1.00)

  ------------------------------------------------------------------

   - see SCH51.C for details


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#ifndef _SCH51_H
#define _SCH51_H

#include "Main.h"

// ------ Public data type declarations ----------------------------

// Store in DATA area, if possible, for rapid access  
// Total memory per task is 7 bytes
typedef data struct 
   {
   // Pointer to the task (must be a 'void (void)' function)
   void (code * pTask)(void);  

   // Delay (ticks) until the function will (next) be run
   // - see SCH_Add_Task() for further details
   tWord Delay;       

   // Interval (ticks) between subsequent runs.
   // - see SCH_Add_Task() for further details
   tWord Period;       

   // Incremented (by scheduler) when task is due to execute
   tByte RunMe;       
   } sTask; 

// ------ Public function prototypes -------------------------------

// Core scheduler functions
void  SCH_Dispatch_Tasks(void);
tByte SCH_Add_Task(void (code*) (void), const tWord, const tWord);  
bit   SCH_Delete_Task(const tByte);
void  SCH_Report_Status(void);

// ------ Public constants -----------------------------------------

// The maximum number of tasks required at any one time
// during the execution of the program
//
// MUST BE ADJUSTED FOR EACH NEW PROJECT
#define SCH_MAX_TASKS   (2)   
 
#endif
                              
/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/

