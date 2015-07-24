/*------------------------------------------------------------------*-

   SPI_1110.C (v1.00)

  ------------------------------------------------------------------

   Simple SPI library for Atmel AT89S53
   - allows data to be read from Max1110 / 1111 ADC


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.H"
#include "Port.H"

#include "SPI_Core.h"
#include "SPI_1110.h"
#include "TimeoutH.h"

// ------ Public variable declarations -----------------------------

// The error code variable
//
// See Port.H for port on which error codes are displayed
// and for details of error codes
extern tByte Error_code_G;

/*------------------------------------------------------------------*-

  SPI_MAX1110_Read_Byte()

  Read a byte of data from the ADC.

-*------------------------------------------------------------------*/
tByte SPI_MAX1110_Read_Byte(void)
   {
   tByte Data, Data0, Data1;
   
   // 0. Pin /CS is pulled low to select the device
   SPI_CS = 0;
  
   // 1. Send a MAX1110 control byte

   // Bit 7 = 1 (start of control byte)
   // Bit 6 = SEL2 
   // Bit 5 = SEL1 
   // Bit 4 = SEL0  (these three select the input channel, p9 MAX1110 docs)
   // Bit 3 = 1 for unipolar, 0 for bipolar
   // Bit 2 = 1 for single ended, 0 for differential
   // Bit 1 = 1 for fully operational, 0 for power-down mode
   // Bit 0 = 1 for external clock, 0 for internal clock
   //  
   // Control byte 0x8F sets single-ended unipolar mode, input channel 0 (pin 1)
   SPI_Exchange_Bytes(0x8F);

   // 2. The data requested is shifted out on SO by sending two dummy bytes
   Data0 = SPI_Exchange_Bytes(0x00);
   Data1 = SPI_Exchange_Bytes(0x00);

   // The data are contained in bits 5-0 of Data0 
   // and 7-6 of Data1 - shift these bytes to give a combined byte,
   Data0 <<= 2;   
   Data1 >>= 6;
   Data = (Data0 | Data1);

   // 3. We pull the /CS pin high to complete the operation
   SPI_CS = 1;

   // 4. We return the required data
   return Data; // Return SPI data byte
   }
  
/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/ 
