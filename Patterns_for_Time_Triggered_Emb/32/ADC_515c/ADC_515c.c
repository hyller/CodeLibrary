/*------------------------------------------------------------------*-

   ADC_515c.c (v1.00)

  ------------------------------------------------------------------

   Simple, single-channel, 8-bit A-D (input) library for C515c


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.H"

// ------ Public variable definitions ------------------------------
// Stores the latest ADC reading
tByte Analog_G;

/*------------------------------------------------------------------*-

  AD_Init()

  Set up the A-D converter.

-*------------------------------------------------------------------*/
void AD_Init(void)
   {
   // Select internally-triggered single conversion
   // Reading from P6.0 (single channel)
   ADEX = 0;  // Internal A/D trigger
   ADM = 0;   // Single conversion  
   MX2 = MX1 = MX0 = 0;  // Read from Channel 0 (Pin 6.0)
 
   // Leave ADCON1 at reset value: prescalar is /4  
   }

/*------------------------------------------------------------------*-

  AD_Get_Sample()

  Get a single data sample (8 bits) from the (10-bit) ADC.

-*------------------------------------------------------------------*/
void AD_Get_Sample(void)
   {
   tWord Time_out_loop = 1;

   // Take sample from A-D
   // Write (value not important) to ADDATL to start conversion
   ADDATL = 0x01; 

   // Take sample from A-D (with simple loop time-out)
   while ((BSY == 1) && (Time_out_loop != 0));
      {
  //    Time_out_loop++;  // Disable for use in dScope...
      }

   if (!Time_out_loop)
      {
      Analog_G = 0;
      }
   else 
      {     
      // 10-bit A-D result is now available
      Analog_G = ADDATH;  // Read only 8 most significant 8-bits of A-D
      }
   } 

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
