/*------------------------------------------------------------------*-

   SPI_Core.C (v1.00)

  ------------------------------------------------------------------

   Core SPI library for Atmel AT89S53.


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

#include "SPI_Core.h"
#include "TimeoutH.H"

// ------ Public variable declarations -----------------------------

// The error code variable
//
// See Main.C for port on which error codes are displayed
// and for details of error codes
extern tByte Error_code_G;

/*------------------------------------------------------------------*-

  SPI_Init_AT89S53()

  Set up the on-chip SPI module.

-*------------------------------------------------------------------*/
void SPI_Init_AT89S53(const tByte SPI_MODE)
   {
   // SPI Control Register (SPCR)
   // Bit 7 = SPIE (enable SPI interrupt, if ES is also 1)
   // Bit 6 = SPE  (enable SPI)
   // Bit 5 = DORD (data order, 1 for LSB first, 0 for MSB first)
   // Bit 4 = MSTR (1 for master, 0 for slave)
   // Bit 3 = CPOL (clock polarity, 1 = high when idle, 0 = low when idle)
   // Bit 2 = CPHA (transfer format)
   // Bit 1 = SPR1 (SPR0, SPR1 control the clock rate)
   // Bit 0 = SPR0 
   SPCR = SPI_MODE;
   }

/*------------------------------------------------------------------*-

  SPI_Exchange_Bytes()

  Exchange a byte of data with the slave device.

-*------------------------------------------------------------------*/
tByte SPI_Exchange_Bytes(const tByte OUT)
   {
   // Write byte to SPI register (starts clock)
   // - these data will be transferred to the slave device
   SPDR = OUT;                  

   // Wait until byte transmitted with 5ms timeout - START 

   // Configure Timer 0 as a 16-bit timer for timeout
   TMOD &= 0xF0; // Clear all T0 bits (T1 left unchanged)
   TMOD |= 0x01; // Set required T0 bits (T1 left unchanged) 

   ET0 = 0;  // No interrupts

   // Simple timeout feature - approx 5ms
   TH0 = T_05ms_H; // See TimeoutH.H for T_ details
   TL0 = T_05ms_L;
   TF0 = 0; // Clear flag
   TR0 = 1; // Start timer

   while (((SPSR & SPIF_) == 0) && (!TF0)); 

   TR0 = 0;  

   if (TF0 == 1)
      {
      // SPI device timed out
      Error_code_G = ERROR_SPI_EXCHANGE_BYTES_TIMEOUT;
      }

   // Clear SPIF and WCOL
   SPSR &= 0x3F; 

   // Return contents of SPI register
   // - these are the data from the slave device               
   return SPDR;                 
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/

