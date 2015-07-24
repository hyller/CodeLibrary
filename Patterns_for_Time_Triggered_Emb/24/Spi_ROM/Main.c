/*------------------------------------------------------------------*-

   Main.C (v1.00)

  ------------------------------------------------------------------

   Simple test program for SPI code library.

   Writes and reads Xicor X25320 (4k x 8-bit) EEPROM


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"
#include "SPI_Core.h"
#include "SPI_X25.h"
#include "Delay_T0.h"

// In this test program, we define the error code variable here.
tByte Error_code_G = 0;

void main(void)
   {
   tByte Data1 = 0;
   tByte Data2 = 0;

   tWord Data_address = 0;

   // See text for details 
   SPI_Init_AT89S53(0x51);

   while (1) 
      {
      // Write to EEPROM
      SPI_X25_Write_Byte(Data_address, Data1++);

      // Read back from EEPROM
      Data2 = SPI_X25_Read_Byte(Data_address);

      // Display value from EEPROM
      P2 = 255 - Data2;

      // Display error codes (if any)
      P3 = 255 - Error_code_G;

      if (++Data_address == 4095)
         {
         Data_address = 0;
         }

      Hardware_Delay_T0(1000);
      }   
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/


