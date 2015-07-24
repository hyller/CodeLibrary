/*------------------------------------------------------------------*-

   LED_Hyb.C (v1.00)

  ------------------------------------------------------------------
   
   Simple 'Flash LED' test function for HYBRID scheduler.

   *** With lock mechanism ***


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"
#include "Port.H"

#include "LED_Hyb.h"
#include "Delay_T0.h"

// ------ Private constants -----------------------------------------

// For the lock mechanism
#define LOCKED 1
#define UNLOCKED 0

// ------ Private variable definitions ------------------------------

static bit LED_short_state_G;

// The lock flag
static bit LED_lock_G = UNLOCKED;

/*------------------------------------------------------------------*-

  LED_Flash_Init()

  - Prepare to flash LEDs.

-*------------------------------------------------------------------*/
void LED_Short_Init(void)
   {
   LED_short_state_G = 0;
   LED_long_port = 0xAA;
   LED_lock_G = UNLOCKED;
   }


/*------------------------------------------------------------------*-

  LED_Short_Update()

  Flashes an LED (or pulses a buzzer, etc) on a specified port pin.

  Must schedule at twice the required flash rate: thus, for 1 Hz
  flash (on for 0.5 seconds, off for 0.5 seconds) must schedule
  at 2 Hz.

-*------------------------------------------------------------------*/
void LED_Short_Update(void)
   {
   // The port has a lock
   // If it is locked, we simply return
   if (LED_lock_G == LOCKED)
      {
      return;
      }

   // Port is free - lock it
   LED_lock_G = LOCKED;

   // Change the LED from OFF to ON (or vice versa)
   if (LED_short_state_G == 1)
      {
      LED_short_state_G = 0;
      LED_short_pin = 0;
      }
   else
      {
      LED_short_state_G = 1;
      LED_short_pin = 1;
      }

   // Unlock the port
   LED_lock_G = UNLOCKED;
   }

/*------------------------------------------------------------------*-

  LED_Long_Update()

  Demo 'long' task (10 second duration).

-*------------------------------------------------------------------*/
void LED_Long_Update(void)
   {
   tByte i;

   // The port has a lock
   // If it is locked, we simply return
   if (LED_lock_G == LOCKED)
      {
      return;
      }

   // Port is free - lock it
   LED_lock_G = LOCKED;

   for (i = 0; i < 5; i++)
       {
       LED_long_port = 0x0F;
       Hardware_Delay_T0(1000);
       LED_long_port = 0xF0;
       Hardware_Delay_T0(1000);
       }

   // Unlock the port
   LED_lock_G = UNLOCKED;
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
