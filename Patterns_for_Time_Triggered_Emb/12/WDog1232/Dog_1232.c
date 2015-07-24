/*------------------------------------------------------------------*-

   Dog_1232.C (v1.00)

  ------------------------------------------------------------------

   Watchdog timer library for external 1232 WD.


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Dog_1232.h"
#include "Main.h"

// ------ Port pins ------------------------------------------------

// Connect 1232 (pin /ST) to the WATCHDOG_pin
sbit WATCHDOG_pin = P1^0;

/*------------------------------------------------------------------*-

  WATCHDOG_Feed()

  'Feed' the external 1232-type watchdog chip.

-*------------------------------------------------------------------*/
void WATCHDOG_Feed(void)
   {
   static bit WATCHDOG_state;

   // Change the state of the watchdog pin
   if (WATCHDOG_state == 1)
      {
      WATCHDOG_state = 0;
      WATCHDOG_pin = 0;
      }
   else
      {
      WATCHDOG_state = 1;
      WATCHDOG_pin = 1;
      }
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/