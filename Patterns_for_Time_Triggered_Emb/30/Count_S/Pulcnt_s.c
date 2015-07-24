/*------------------------------------------------------------------*-

   PulCnt_S.C (v1.00)

  ------------------------------------------------------------------

   Software pulse-count library (see Chapter 30).


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

#include "Bargraph.h"
#include "PulCnt_S.h"

// ------ Public variable definitions -----------------------------

// Stores the average count value
extern tBargraph Count_G;

// ------ Private constants ----------------------------------------

#define PULSE_HIGH (1)
#define PULSE_LOW (0)

// ------ Private variable definitions------------------------------

// Stores the instantaneous count value
static tWord Count_local_G;

// The previous state of the pulse-count pin
static bit Previous_state_G;

/*------------------------------------------------------------------*-

  PC_SOFT_Init() 

  Prepare for software pulse counts.

-*------------------------------------------------------------------*/
void PC_SOFT_Init(void)
   {
   Count_local_G = 0;
   Count_G = 0;
   }

/*------------------------------------------------------------------*-

  PC_SOFT_Poll_Count()

  Using software to count falling edges on a specified pin
  - T0 is *NOT* used here.

-*------------------------------------------------------------------*/
void PC_SOFT_Poll_Count(void)
   {
   bit State = Count_pin;

   if ((Previous_state_G == PULSE_HIGH) && (State == PULSE_LOW))
      {
      Count_local_G++;
      } 

   Previous_state_G = State;     
   }

/*------------------------------------------------------------------*-

  PC_SOFT_Get_Count()

  Schedule this function at regular intervals.

  Copies 'polled' count to global variable.

-*------------------------------------------------------------------*/
void PC_SOFT_Get_Count(void)
   {
   Count_G = Count_local_G;
   Count_local_G = 0;
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
 
