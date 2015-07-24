/*------------------------------------------------------------------*-

   Main.C (v1.00)

  ------------------------------------------------------------------

   Simple test program for I2C (Max127 ADC) library.

   Connect a Max127 to the SDA and SCL pins described 
   in the library file (I2C_Core.C).

   Terminating resistors not generally required on the bus.


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"
#include "ADC_m127.h"
#include "Delay_T0.h"

extern tByte ADC_G;

// In this test program, we define the error code variable here
// (Usually in the scheduler library)
tByte Error_code_G = 0;

void main( void )
   {
   while(1) 
      {
      I2C_ADC_Max127_Read();
      P1 = ADC_G;
      P2 = Error_code_G;
      Hardware_Delay_T0(1000);
      }   
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/

