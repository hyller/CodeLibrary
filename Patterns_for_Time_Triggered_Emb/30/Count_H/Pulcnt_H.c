/*------------------------------------------------------------------*-

   PulCnt_H.C (v1.10)

  ------------------------------------------------------------------

   Hardware pulse-count library (see Chapter 30).


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

#include "PulCnt_H.h"

// ------ Public variable declarations -----------------------------

// Global count variable - stores the latest count value
extern tBargraph Count_G;

/*------------------------------------------------------------------*-

  PC_HARD_Init_T0()

  Prepare for 'Hardware Pulse Count' using Timer 0.

-*------------------------------------------------------------------*/
void PC_HARD_Init_T0(void)
   {
   // Timer 0 used as 16-bit timer, counting pulses 
   // (falling edges) on Pin 3.4 (T0 pin)
   TMOD &= 0xF0;      // Clear all T0 bits (T1 left unchanged)
   TMOD |= 0x05;      // Set required T0 bits (T1 left unchanged) 
   
   TH0 = 0; TL0 = 0;  // Set timer count to 0
   Count_G = 0;       // Set global count to 0

   TR0 = 1;           // Start the counter
   }

/*------------------------------------------------------------------*-

  PC_HARD_Get_Count_T0()

  Schedule this function at regular intervals.

  Remember: max count is 65536 (16-bit counter)
  - it is your responsibility to ensure this count
  is not exceeded.  Choose an appropriate schedule
  interval and allow a margin for error.

  For high-frequency pulses, you need to take account of
  the fact that the count is stopped for a (very brief) period,
  to read the counter.  

  Note: the delay before the first count is taken should 
  generally be the same as the inter-count interval,
  to ensure that the first count is as accurate as possible.

  For example, this is OK:

    Sch_Add_Task(PC_HARD_Get_Count_T0, 1000, 1000);

  While this will give a very low first count:

   Sch_Add_Task(PC_HARD_Get_Count_T0, 10, 1000);

-*------------------------------------------------------------------*/
void PC_HARD_Get_Count_T0(void)
   {
   TR0 = 0; // Stop counter

   Count_G = (TH0 << 8) + TL0;  // Read count

   TH0 = 0; TL0 = 0;            // Reset count

   if (TF0 == 1)
      {
      // Timer has overflowed 
      // - pulse frequency too high 
      // - or schedule rate too low
      
      // We code this error as a 'max count'
      // - could also set a global error flag, if required
      Count_G = 65535;
      TF0 = 0;
      }

   TR0 = 1; // Restart counter
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
