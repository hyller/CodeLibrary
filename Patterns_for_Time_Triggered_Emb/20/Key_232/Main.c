/*------------------------------------------------------------------*-

   Main.c (v1.00)

  ------------------------------------------------------------------

   Test program for keypad library, based on c515c

   Sends output (to PC) over serial (RS232) link

   Required linker options (see Chapter 14 for details):

   OVERLAY (main ~ (PC_LINK_Update, Keypad_RS232_Update), 
   SCH_Dispatch_Tasks ! (PC_LINK_Update, Keypad_RS232_Update))


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
#include "Keypad.h"
#include "Keyp_232.h"

/* ............................................................... */
/* ............................................................... */

void main(void)
   {
   // Set up the scheduler
   SCH_Init_T2();

   // Set baud rate to 9600, using internal baud rate generator
   PC_LINK_O_Init_Internal(9600);

   // Prepare the keypad
   KEYPAD_Init();

   // Prepare the Keypad -> RS232 library
   Keypad_RS232_Init();
 
   // We have to schedule this task (~100x a second is enough here)
   // - this writes data to PC 
   //
   // TIMING IS IN TICKS (1 ms tick interval)
   SCH_Add_Task(PC_LINK_O_Update, 10, 10);

   // Read the keypad every ~50 ms
   SCH_Add_Task(Keypad_RS232_Update, 0, 50);

   SCH_Start();

   while(1)
      {
      SCH_Dispatch_Tasks();
      }
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
