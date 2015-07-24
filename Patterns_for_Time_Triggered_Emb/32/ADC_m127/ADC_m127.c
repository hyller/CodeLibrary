/*------------------------------------------------------------------*-

   ADC_m127.C (v1.00)

  ------------------------------------------------------------------

   Code library for Max127 (I2C) ADC.


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

#include "I2C_Core.h"
#include "ADC_m127.h"

#include "Delay_t0.h"

// ------ Public variable definitions ------------------------------

// The ADC value
tByte ADC_G;

// ------ Public variable declarations -----------------------------

// The error codes - see scheduler
extern tByte Error_code_G;

// ------ Private constants ----------------------------------------

// Chip address = 0101xxxW
#define I2C_MAX127_ADDRESS (80) 

// Start bit set
// Normal power mode (not in power-down mode)
// Range 0 - 5V
#define I2C_MAX127_MODE (0x80)


// ------ Private variable definitions------------------------------

// The ADC channel (0 - 7)
// *** Value here is required channel value << 4 ***
// *** We are using Channel 2 ***
static tByte I2C_MAX127_Channel_G = 0x20;


/*------------------------------------------------------------------*-

  I2C_ADC_Max127_Read()

  Reads from the I2C 12-bit ADC

  The channel used is given by ADC_Channel_G

  This version reads only 8-bits (most sig) data

-*-------------------------------------------------------------------*/
void I2C_ADC_Max127_Read(void)
   {
   I2C_Send_Start(); // Generate I2C START condition
   
   // Send DAC device address (with write access request)
   if (I2C_Write_Byte(I2C_MAX127_ADDRESS | I2C_WRITE))    
      {
      Error_code_G = ERROR_I2C_ADC_MAX127;
      return;
      }
   
   // Set the ADC mode and channel - see above
   if (I2C_Write_Byte(I2C_MAX127_MODE | I2C_MAX127_Channel_G)) 
      {
      Error_code_G = ERROR_I2C_ADC_MAX127;
      return;
      }
   
   I2C_Send_Stop(); // Generate STOP condition

   I2C_Send_Start(); // Generate START condition (again)
       
   // Send Max127 device address (with READ access request)
   if (I2C_Write_Byte(I2C_MAX127_ADDRESS | I2C_READ))  
      {
      Error_code_G = ERROR_I2C_ADC_MAX127;
      return;
      }
   
   // Receive first (MS) byte from I2C bus
   ADC_G = I2C_Read_Byte();
   
   I2C_Send_Master_Ack(); // Perform a MASTER ACK
   
   // Here we require temperature only accurate to 1 degree C
   // - we discard LS byte (perform a dummy read)
   I2C_Read_Byte();
   
   I2C_Send_Master_NAck(); // Perform a MASTER NACK
   
   I2C_Send_Stop(); // Generate STOP condition
   }

/*------------------------------------------------------------------*-
---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
