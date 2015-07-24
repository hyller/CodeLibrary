/*------------------------------------------------------------------*-

   Main.c (v1.00)

  ------------------------------------------------------------------

   Simple 'ADC to PWM' example program (c515c)


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"

#include "ADC_515c.h"
#include "PWM_515c.h"               

extern tByte Analog_G;

/* ............................................................... */
/* ............................................................... */

void main()
   {
   AD_Init(); 
   PWM_Init_T2();

   while(1)
      {
      AD_Get_Sample();
      PWM_Update_T2(Analog_G);
      }     
   }   

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/


