/*------------------------------------------------------------------*-

   ADC_m150.c (v1.00)

  ------------------------------------------------------------------

   Simple, single-channel, 8-bit A-D (input) library for 8051 family
   - uses Max150 8-bit parallel ADC.

   See Chapter 32 for details.


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.H"
#include "Port.h"

#include "Bargraph.h"

// ------ Public variable definitions ------------------------------

// Stores the latest ADC reading
tByte Analog_G;

// ------ Public variable declarations -----------------------------

extern tByte Error_code_G;


/*------------------------------------------------------------------*-

  ADC_Max150_Init()

  Set up the Max150 ADC.  Using WR-RD mode (see data sheet)

-*------------------------------------------------------------------*/
void ADC_Max150_Init(void)
   {
   // Set 'NOT read' pin high
   ADC_Max150_NOT_Read_pin = 1;

   // Set 'NOT write' pin high
   ADC_Max150_NOT_Write_pin = 1;

   // Prepare 'NOT Int' pin for reading
   ADC_Max150_NOT_Int_pin   = 1;
   }

/*------------------------------------------------------------------*-

  ADC_Max150_Get_Sample()

  Get a single data sample (8 bits) from the ADC.

-*------------------------------------------------------------------*/
void ADC_Max150_Get_Sample(void)
   {
   tWord Time_out_loop = 1;

   // Start conversion by pulling 'NOT Write' low
   ADC_Max150_NOT_Write_pin = 0;

   // Take sample from A-D (with simple loop time-out)
   while ((ADC_Max150_NOT_Int_pin == 1) && (Time_out_loop != 0));
      {
      Time_out_loop++;  // Disable for use in dScope...
      }

   if (!Time_out_loop)
      {
      // Timed out
      Error_code_G =  
      Analog_G = 0;
      }
   else 
      {     
      // Set port to 'read' mode
      ADC_Max150_port = 0xFF;  

      // Set 'NOT read' pin low
      ADC_Max150_NOT_Read_pin = 0;

      // ADC result is now available
      Analog_G = ADC_Max150_port; 

      // Set 'NOT read' pin high
      ADC_Max150_NOT_Read_pin = 1;
      }

   // Pull 'NOT Write' high
   ADC_Max150_NOT_Write_pin = 1;
   } 

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
