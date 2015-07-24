/*------------------------------------------------------------------*-

   LED_Swit.C (v1.00)

  ------------------------------------------------------------------
   
   Simple 'Flash LED' test function for scheduler.

   (Controlled by switch press)


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

#include "LED_Swit.h"

// ------ Public variable declarations -----------------------------

extern bit Sw_pressed_G;


// ------ Private variables ----------------------------------------

static bit LED_state_G;


/*------------------------------------------------------------------*-

  LED_Flash_Switch_Init()

  - See below.

-*------------------------------------------------------------------*/
void LED_Flash_Switch_Init(void)
   {
   LED_state_G = 0;
   }


/*------------------------------------------------------------------*-

  LED_Flash_Switch_Update()

  Flashes an LED (or pulses a buzzer, etc) on a specified port pin.

  Must schedule at twice the required flash rate: thus, for 1 Hz
  flash (on for 0.5 seconds, off for 0.5 seconds) must schedule
  at 2 Hz.

-*------------------------------------------------------------------*/
void LED_Flash_Switch_Update(void)
   {
   // Do nothing if switch is not pressed
   if (!Sw_pressed_G)
      {
      return;
      }

   // Change the LED from OFF to ON (or vice versa)
   if (LED_state_G == 1)
      {
      LED_state_G = 0;
      LED_pin = 0;
      }
   else
      {
      LED_state_G = 1;
      LED_pin = 1;
      }
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
