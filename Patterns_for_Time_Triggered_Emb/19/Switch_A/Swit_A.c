/*------------------------------------------------------------------*-

   SWIT_A.C (v1.00)
 
  ------------------------------------------------------------------

   Simple switch interface code, with software debounce.


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

#include "Swit_A.h"

// ------ Public variable definitions ------------------------------

bit Sw_pressed_G = 0; // The current switch status


// ------ Private constants ----------------------------------------

// Allows NO or NC switch to be used (or other wiring variations)
#define SW_PRESSED (0)

// SW_THRES must be > 1 for correct debounce behaviour
#define SW_THRES (3)


/*------------------------------------------------------------------*-

  SWITCH_Init()

  Initialisation function for the switch library.

-*------------------------------------------------------------------*/
void SWITCH_Init(void)
   {
   Sw_pin = 1; // Use this pin for input
   }

/*------------------------------------------------------------------*-

  SWITCH_Update()
  
  This is the main switch function.  

  It should be scheduled every 50 - 500 ms.
 
-*------------------------------------------------------------------*/
void SWITCH_Update(void)
   {
   static tByte Duration;

   if (Sw_pin == SW_PRESSED)
      {
      Duration += 1;

      if (Duration > SW_THRES)
         {
         Duration = SW_THRES;

         Sw_pressed_G = 1;  // Switch is pressed...
         return;
         }

      // Switch pressed, but not yet for long enough
      Sw_pressed_G = 0;
      return; 
      }
    
   // Switch not pressed - reset the count
   Duration = 0;
   Sw_pressed_G = 0;  // Switch not pressed...
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
