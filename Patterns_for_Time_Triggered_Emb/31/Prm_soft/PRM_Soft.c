/*------------------------------------------------------------------*-

   PRM_Soft.c (v1.01)

  ------------------------------------------------------------------

   Simple Software PRM library.

   See Chapter 31 for details.


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
#include "PRM_Soft.h"

// Comment out this line if test function is NOT required
#define PRM_test

// ------ Public variable definitions ------------------------------

// Set this variable to the required PRM value
tWord PRM_period_new_G; 

// ------ Private variable definitions------------------------------

// The PRM counter
static tWord PRM_position_G;
static tByte PRM_period_G;

/*------------------------------------------------------------------*-

  PRM_Soft_Init()

  Prepare for software PRM.

-*------------------------------------------------------------------*/
void PRM_Soft_Init(void)
   {
   // Init the main variable
   PRM_period_G = 2;
   PRM_period_new_G = 2;

   PRM_position_G = 0;
   }

/*------------------------------------------------------------------*-

  PRM_Soft_Update()

  Update the software PRM output. 

  We have three key variables (see text for details):

  1. PRM_period_G is the PRM period
     (units are milliseconds, if we schedule once / ms)

  2. PRM_period_new_G is the new PRM period, set by the user
     (The 'new' value is copied to PRM-period only at the
      end of a cycle, to avoid noise)
     (units are milliseconds, if we schedule once / ms)

  3. PRM_position_G is the current position in the PRM cycle
     (units are milliseconds, if we schedule once / ms)


-*------------------------------------------------------------------*/
void PRM_Soft_Update(void)
   {
   // Increment the 'position' variable 
   if (++PRM_position_G >= PRM_period_G)
      {
      PRM_position_G = 0;

      PRM_period_G = PRM_period_new_G; 

      PRM_pin = 0;

      return;
      }

   // Generate the PRM output
   if (PRM_position_G < (PRM_period_G / 2))
      {
      PRM_pin = 1;
      }
   else
      {
      PRM_pin = 0;
      }
   }

/*------------------------------------------------------------------*-

  PRM_Soft_Test()

  To test the PRM library, this function is called once every 
  minute, to change the PRM output setting.

-*------------------------------------------------------------------*/
#ifdef PRM_test
void PRM_Soft_Test(void)
   {
   PRM_period_new_G += 2;

   if (PRM_period_new_G >= 60000)
      {
      PRM_period_new_G = 2;
      }
   }
#endif

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/

