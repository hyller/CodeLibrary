/*------------------------------------------------------------------*-

   PWM_SOFT.C (v1.00)

  ------------------------------------------------------------------

   Simple 'Software PWM' library.

   See Chapter 33 for details.


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

#include "2_01_12g.h"
#include "PWM_Soft.h"

// Comment out this line if test function is NOT required
#define PWM_test

// ------ Public variable definitions ------------------------------

// Set this variable to the required PWM value
tByte PWM_new_G;

// ------ Private constants ----------------------------------------

#define PWM_ON 0
#define PWM_OFF 1

// ------ Private variables ----------------------------------------

// The PWM counter
static tWord PWM_position_G;
static tByte PWM_G;

/*------------------------------------------------------------------*-

  PWM_Soft_Init()

  Prepares some of the key PWM variables.

-*------------------------------------------------------------------*/
void PWM_Soft_Init(void)
   {
   // Init the main variable
   PWM_new_G = 0;
   PWM_position_G = 0;
   PWM_pin = PWM_OFF;
   }

/*------------------------------------------------------------------*-

  PWM_Soft_Update()

  The key PWM function.  Schedule as rapidle as possible.

-*------------------------------------------------------------------*/
void PWM_Soft_Update(void)
   {
   // Have we reached the end of the current PWM cycle?
   if (++PWM_position_G >= PWM_PERIOD)
      {
      // Reset the PWM position counter
      PWM_position_G = 0;

      // Update the PWM control value
      PWM_G = PWM_new_G; 

      // Set the PWM output to OFF
      PWM_pin = PWM_OFF;

      return;
      }

   // We are in a PWM cycle
   if (PWM_position_G < PWM_G)
      {
      PWM_pin = PWM_ON;
      }
   else
      {
      PWM_pin = PWM_OFF;
      }
   }

/*------------------------------------------------------------------*-

  PWM_Soft_Test()

  To test the PWM library, this function is called once every 
  five seconds, to update the PWM settings.

  NOTE:
  In a real application, this function will be replaced by a user-
  defined function for setting brightness, speed, etc.

-*------------------------------------------------------------------*/
#ifdef PWM_test
void PWM_Soft_Test(void)
   {
   if (++PWM_new_G >= PWM_PERIOD)
      {
      PWM_new_G = 0;
      }
   }
#endif

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/

