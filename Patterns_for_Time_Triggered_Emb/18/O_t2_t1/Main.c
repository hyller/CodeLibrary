/*------------------------------------------------------------------*-

   Main.c (v1.01)

  ------------------------------------------------------------------

   Test program for menu-driven PC link library, generic version.

   Required linker options (see Chapter 14 for details):

   OVERLAY (main ~ (PC_LINK_O_Update,Elapsed_Time_RS232_Update), 
   SCH_Dispatch_Tasks ! (PC_LINK_O_Update,Elapsed_Time_RS232_Update))


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"
#include "2_05_11g.h"
#include "PC_O_T1.h"
#include "Elap_232.h"

/* ............................................................... */
/* ............................................................... */

void main(void)
   {
   // Set up the scheduler
   SCH_Init_T2();

   // Set baud rate to 9600
   PC_LINK_O_Init_T1(9600);

   // Prepare the elapsed time library
   Elapsed_Time_RS232_Init();

   // We have to schedule this task (~100x a second is enough here)
   // - this writes data to PC 
   //
   // TIMING IS IN TICKS (5 ms tick interval)
   SCH_Add_Task(PC_LINK_O_Update, 10, 2);

   // Update the time once per second
   SCH_Add_Task(Elapsed_Time_RS232_Update, 1000, 200);

   SCH_Start();

   while(1)
      {
      SCH_Dispatch_Tasks();
      }
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
