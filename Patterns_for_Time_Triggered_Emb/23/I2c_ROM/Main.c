/*------------------------------------------------------------------*-

   Main.C (v1.00)

  ------------------------------------------------------------------

   Simple test program for I2C (24C64) library.

   Connect a 24C64 to the SDA and SCL pins described 
   in the library file (I2C_Core.C).

   Terminating resistors not generally required on the bus.

   Pull all three address lines (on the EEPROM) to ground.


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"
#include "I2C_ROM.h"
#include "Delay_T0.h"

// In this test program, we define the error code variable here
// (Usually in the scheduler library)
tByte Error_code_G = 0;

void main( void )
   {
   tByte data1 = 0;
   tByte data2 = 0;

   tWord Data_address = 0;

   while (1) 
      {
      Data_address = data1;

      // Write to eeprom
      I2C_Write_Byte_AT24C64(Data_address, data1);

      // Read back from eeprom
      data2 = I2C_Read_Byte_AT24C64(Data_address);

      // Display value from eeprom
      P1 = 255 - data2;

      // Display error code
      P2 = 255 - Error_code_G;

      if (++data1 == 255)
         {
         data1 = 0;
         }

      Hardware_Delay_T0(1000);
      }   
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/


