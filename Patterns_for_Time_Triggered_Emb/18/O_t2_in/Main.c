/*------------------------------------------------------------------*-

   Main.c (v1.01)

  ------------------------------------------------------------------

   Test program for output-only PC link library, based on c515c.


   Required linker options (see Chapter 14 for details):

   OVERLAY (main ~ (PC_LINK_Update,Elapsed_Time_RS232_Update), 
   SCH_Dispatch_Tasks ! (PC_LINK_Update,Elapsed_Time_RS232_Update))


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"

#include "2_01_10i.h"
#include "PC_O_in.h"
#include "Elap_232.h"

/* ............................................................... */
/* ............................................................... */

void main(void)
   {
   // Set up the scheduler
   SCH_Init_T2();

   // Set baud rate to 9600, using internal baud rate generator
   PC_LINK_O_Init_Internal(9600);

   // Prepare the elapsed time library
   Elapsed_Time_RS232_Init();

   // We have to schedule this task (~100x a second is enough here)
   // - this writes data to PC 
   //
   // TIMING IS IN TICKS (1 ms tick interval)
   SCH_Add_Task(PC_LINK_O_Update, 10, 10);

   // Update the time once per second
   SCH_Add_Task(Elapsed_Time_RS232_Update, 1000, 1000);

   SCH_Start();

   while(1)
      {
      // Displays error codes on P4 (see Sch51.C)
      SCH_Dispatch_Tasks();
      }
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
