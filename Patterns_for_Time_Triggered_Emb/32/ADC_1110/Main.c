/*------------------------------------------------------------------*-

   Main.C (v1.00)

  ------------------------------------------------------------------

   Simple test program for SPI code library.

   Reads from Max1110 / 1111 SPI ADC.


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
#include "SPI_1110.h"
#include "Delay_T0.h"

// In this test program, we define the error code variable here.
tByte Error_code_G = 0;

void main(void)
   {
   tByte Data1 = 0;
   tByte Data2 = 0;

   tWord Data_address = 0;

   // See text for details 

   // SPI Control Register.
   // Bit 0 = SPR0
   // Bit 1 = SPR1 (these two control the clock rate)
   // Bit 2 = CPHA (transfer format, see p15 of AT89S53 docs)
   // Bit 3 = CPOL (clock polarity, 1 = high when idle, 0 = low when idle)
   // Bit 4 = MSTR (1 for master, 0 for slave)
   // Bit 5 = DORD (data order, 1 for LSB first, 0 for MSB first)
   // Bit 6 = SPE  (enable SPI)
   // Bit 7 = SPIE (enable SPI interrupt, if ES is also 1)

   // To interface with the MAX1110 ADC, we need a clock rate in the range 
   // 50-500 kHz, so with a 12 MHz oscillator SPR0 and SPR1 are set at 1 and 0, 
   // so SPI speed is Fosc / 64, which is 187.5 kHz
   // 
   // CPHA and CPOL both need to be zero, see MAX1110 docs
   // DORD needs to be zero (MSB first)
   // MSTR, SPE, SPIE need to be one
   //  SPCR = 0x52;
   SPI_Init_AT89S53(0x52);

   while (1) 
      {
      // Read ADC byte
      Data2 = SPI_MAX1110_Read_Byte();

      // Display data
      P2 = 255 - Data2;

      // Display error codes (if any)
      P3 = 255 - Error_code_G;

      Hardware_Delay_T0(1000);
      }   
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/


