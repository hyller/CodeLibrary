/*------------------------------------------------------------------*-

   SWIT_C.C (v1.00)
 
  ------------------------------------------------------------------

   On-Off Switch code, with software debounce.


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

#include "Swit_C.h"

// ------ Public variable definitions ------------------------------

bit Sw_pressed_G = 0; // The current switch status


// ------ Private constants ----------------------------------------

// Allows NO or NC switch to be used (or other wiring variations)
#define SW_PRESSED (0)

// SW_THRES must be > 1 for correct debounce behaviour
#define SW_THRES (3)

// ------ Private variables ----------------------------------------

static tByte Sw_press_duration_G = 0;
static tByte Sw_blocked_G = 0;


/*------------------------------------------------------------------*-

  FUNCTION: SWITCH_ON_OFF_Init()

  Initialisation function for the switch library.

-*------------------------------------------------------------------*/
void SWITCH_ON_OFF_Init(void)
   {
   Sw_pin = 1;      // Use this pin for input

   Sw_pressed_G = 0;  // Switch is initially OFF
   Sw_press_duration_G = 0;  
   Sw_blocked_G = 0;
   }

/*------------------------------------------------------------------*-

  FUNCTION: SWITCH_ON_OFF_Update()
  
  This is the main on-off switch function.  

  It should be scheduled every 50 - 500 ms.

-*------------------------------------------------------------------*/
void SWITCH_ON_OFF_Update(void)
   {
   // If the switch is blocked, decrement the count and return
   // without checking the switch pin status.
   // This is done to give the user time to remove their finger 
   // from the switch - otherwise if they keep their finger on
   // the switch for more than 0.4s the light will switch off again.

   if (Sw_blocked_G)
      {
      Sw_blocked_G--;
      return;
      }

   if (Sw_pin == SW_PRESSED)
      {
      Sw_press_duration_G += 1;

      if (Sw_press_duration_G > SW_THRES)
         {
         Sw_press_duration_G = SW_THRES;

         // Change switch state
         if (Sw_pressed_G == 1)
            { 
            Sw_pressed_G = 0;  // Switch state changed to OFF
            }
         else
            { 
            Sw_pressed_G = 1;  // Switch state changed to ON
            }

         // Allow no other changes for ~1 second
         Sw_blocked_G = 5;  
         return;
         }

      // Switch pressed, but not yet for long enough
      return; 
      }
    
   // Switch not pressed - reset the count
   Sw_press_duration_G = 0;
   }


/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
