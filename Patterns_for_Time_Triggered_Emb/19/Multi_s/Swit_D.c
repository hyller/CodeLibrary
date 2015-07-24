/*------------------------------------------------------------------*-

   SWIT_D.C (v1.00)
 
  ------------------------------------------------------------------

   4-state switch interface code, with software debounce.


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

#include "Swit_D.h"


// ------ Public variables -----------------------------------------

tByte Sw_status_G; // The current switch status

// ------ Private constants ----------------------------------------

// SW_THRES must be > 1 for correct debounce behaviour
#define SW_THRES (1)
#define SW_THRES_X2 (SW_THRES + SW_THRES + SW_THRES + SW_THRES)
#define SW_THRES_X3 (SW_THRES_X2 + SW_THRES_X2)

// Allows NO or NC switch to be used (or other wiring variations)
#define SW_PRESSED (0)

// ------ Private variables ----------------------------------------

static tByte Sw_press_duration_G = 0;


/*------------------------------------------------------------------*-

  SWITCH_MS_Init()

  Initialisation function for the switch library.
 
-*------------------------------------------------------------------*/
void SWITCH_MS_Init(void)
   {
   Sw_pin = 1; // Use this pin for input

   Sw_status_G = 0;  // Switch is initially OFF
   Sw_press_duration_G = 0;  
   }

/*------------------------------------------------------------------*-

  SWITCH_MS_Update()
  
  This is the main switch function.  It should be scheduled every
  50 - 500 ms.

  Alters Sw_press_duration_G depending on duration of switch press.

-*------------------------------------------------------------------*/
void SWITCH_MS_Update(void)
   {
   if (Sw_pin == SW_PRESSED)
      {
      Sw_press_duration_G += 1;

      if (Sw_press_duration_G > (SW_THRES_X3))
         {
         Sw_press_duration_G = SW_THRES_X3;
         Sw_status_G = 3;  // Switch has been pressed for a long time...
         return;
         } 

      if (Sw_press_duration_G > (SW_THRES_X2))
         {
         Sw_status_G = 2;  // Switch has been pressed for a medium time...
         return;
         }
    
      // SW_THRES must be > 1 for software debounce  
      if (Sw_press_duration_G > SW_THRES)
         {
         Sw_status_G = 1;  // Switch has been pressed for a short time...
         return;
         }

      // switch pressed, but not yet for long enough
      Sw_status_G = 0; 
      return; 
      }
    
   // Switch not pressed - reset the count
   Sw_press_duration_G = 0;
   Sw_status_G = 0;  // Switch not pressed...
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
