/*------------------------------------------------------------------*-

   Main.c (v1.01)

  ------------------------------------------------------------------

   Test program for menu-driven PC link library.

   Uses 12 MHz crystal, *T2* for baud rate -> 9600 baud.

   Required linker options (see Chapter 14 for details):

   OVERLAY (main ~ (MENU_Command_Processor), 
   SCH_Dispatch_Tasks ! (MENU_Command_Processor))


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"
#include "0_01_12g.h"
#include "PC_IO_T2.h"
#include "Menu_A.h"

/* ............................................................... */
/* ............................................................... */

void main(void)
   {
   // Set up the scheduler
   SCH_Init_T0();

   // Set baud rate to 9600 using T2
   PC_LINK_IO_Init_T2(9600);

   // We have to schedule this task (10x - 100x a second)
   //
   // TIMING IS IN TICKS NOT MILLISECONDS (5 ms tick interval)
   SCH_Add_Task(MENU_Command_Processor,10,2);

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
