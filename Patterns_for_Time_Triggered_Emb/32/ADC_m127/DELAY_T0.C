/*------------------------------------------------------------------*-

   Delay_T0.C (v1.00)

  ------------------------------------------------------------------

   Simple hardware delays based on T0.


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.H"

// ------ Private constants ----------------------------------------
 
// Timer preload values for use in simple (hardware) delays
// - Timers are 16-bit, manual reload ('one shot').
//
// NOTE: These values are portable but timings are *approximate*
//       and *must* be checked by hand if accurate timing is required.
//
// Define Timer 0 / Timer 1 reload values for ~1 msec delay
// NOTE: Adjustment made to allow for function call overheard etc.
#define PRELOAD01  (65536 - (tWord)(OSC_FREQ / (OSC_PER_INST * 1063)))    
#define PRELOAD01H (PRELOAD01 / 256)
#define PRELOAD01L (PRELOAD01 % 256)

/*------------------------------------------------------------------*-

  Hardware_Delay_T0()

  Function to generate N millisecond delay (approx). 

  Uses Timer 0 (easily adapted to Timer 1).

-*------------------------------------------------------------------*/
void Hardware_Delay_T0(const tWord N)   
   {
   tWord ms;
   
   // Configure Timer 0 as a 16-bit timer 
   TMOD &= 0xF0; // Clear all T0 bits (T1 left unchanged)
   TMOD |= 0x01; // Set required T0 bits (T1 left unchanged) 

   ET0 = 0;  // No interupts

   // Delay value is *approximately* 1 ms per loop   
   for (ms = 0; ms < N; ms++)
      {                 
      TH0 = PRELOAD01H;  
      TL0 = PRELOAD01L;   

      TF0 = 0;          // clear overflow flag
      TR0 = 1;          // start timer 0

      while (TF0 == 0); // Loop until Timer 0 overflows (TF0 == 1)

      TR0 = 0;          // Stop Timer 0
      }
   }        

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
