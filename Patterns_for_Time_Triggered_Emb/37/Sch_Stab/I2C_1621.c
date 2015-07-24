/*------------------------------------------------------------------*-

   I2C_1621.C (v1.00)

  ------------------------------------------------------------------

   I2C-based library for DS1621 temperature sensor.


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"

#include "I2C_core.h"
#include "I2C_1621.h"
#include "Delay_T0.h"

// ------ Public variable declarations -----------------------------

extern tByte Temperature_G;
extern tByte Error_code_G;

// ------ Private constants ----------------------------------------

#define I2C_DS1621_ID   0x90    


/*------------------------------------------------------------------*-

  I2C_Init_Temperature_DS1621()

  Sets the sensor to 'continuous convert' mode to allow 
  temperature readings to be subsequently obtained.

-*------------------------------------------------------------------*/
void I2C_Init_Temperature_DS1621(void)
   {
   I2C_Send_Start();   // Generate START condition

   // Send SLAVE address with write request
   if (I2C_Write_Byte(I2C_DS1621_ID | I2C_WRITE))
      {
      Error_code_G = ERROR_I2C_DS1621; 
      return;
      }

   // Send control byte :
   // configure command
   if (I2C_Write_Byte(0xAC))
      {
      Error_code_G = ERROR_I2C_DS1621; 
      return;
      }

   // Send configuration data - CONTINUOUS mode
   if (I2C_Write_Byte(0x00)) 
      {
      Error_code_G = ERROR_I2C_DS1621;
      return;
      }

   I2C_Send_Stop();    // Generate STOP condition

   // Must delay here to allow EEPROM (in sensor)
   // to store these data.  Sheet says 10ms.
   Hardware_Delay_T0(100);  

   // Now start temperature conversions
   I2C_Send_Start();   // Generate START condition

   // Send SLAVE address with write request
   if (I2C_Write_Byte(I2C_DS1621_ID | I2C_WRITE))
      {
      Error_code_G = ERROR_I2C_DS1621;
      return;
      }

    // Send command data - start converting
    if (I2C_Write_Byte(0xEE)) 
       {
       Error_code_G = ERROR_I2C_DS1621;
       return;
       }

   I2C_Send_Stop();    // Generate STOP condition
   }

  
/*------------------------------------------------------------------*-

  I2C_Read_Temperature_DS1621()

  The sensor samples continuously (around 1 new value per second).
  We obtain the latest value.

-*------------------------------------------------------------------*/
void I2C_Read_Temperature_DS1621(void)
   {
   tByte result = 0;

   I2C_Send_Start();   // Generate START condition

   // Send DS1621 device address (with write access request)
   if (I2C_Write_Byte(I2C_DS1621_ID | I2C_WRITE))
      {
      Error_code_G = ERROR_I2C_DS1621;
      return;
      }

    // Send command - Read Temperature (0xAA)
    if (I2C_Write_Byte(0xAA))
       {
      Error_code_G = ERROR_I2C_DS1621;
       return;
       }

   I2C_Send_Start();   // Generate START condition (again)

   // Send DS1621 device address (with READ access request this time)
   if (I2C_Write_Byte(I2C_DS1621_ID | I2C_READ))
      {
      Error_code_G = ERROR_I2C_DS1621;
      return;
      }

    // Receive first (MS) byte from I2C bus
    Temperature_G = I2C_Read_Byte();
    I2C_Send_Master_Ack();     // Perform a MASTER ACK

    // Here we require temperature only accurate to 1 degree C
    // - we discard LS byte (perform a dummy read)
    I2C_Read_Byte();
    I2C_Send_Master_NAck();    // Perform a MASTER NACK

    I2C_Send_Stop();    // Generate STOP condition
    }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/



