/*------------------------------------------------------------------*-

   I2C_ROM.C (v1.00)

  ------------------------------------------------------------------

   I2C library functions which are intended to allow
   use of 2-wire serial EEPROMs (specifically, AT24C64).

   Easily extended / adapted to work with other 2-wire EEPROMs.

   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"
#include "Delay_T0.h"
#include "I2C_Core.h"
#include "I2C_ROM.h"

// ------ Public variable declarations -----------------------------

extern tByte Error_code_G;

// ------ Private constants ----------------------------------------

// Device identifier of the EEPROM used in this example
// - see text / Philips documentation for IDs used by other devices
#define I2C_EEPROM_ID 0xA0 


/*------------------------------------------------------------------*-

  I2C_Write_Byte_AT24C64()

  Send a byte of data to the EEPROM.
  
-*------------------------------------------------------------------*/
void I2C_Write_Byte_AT24C64(const tWord address, tByte content)
   {
   tByte MSByte;  // Most significant byte of data address
   tByte LSByte;  // Least significant byte of data address

   I2C_Send_Start();   // Generate START condition

   // Send SLAVE address with write request
   if (I2C_Write_Byte(I2C_EEPROM_ID | I2C_WRITE))
     {
     Error_code_G = ERROR_I2C_WRITE_BYTE_AT24C64;
     return;
     }

   // MSByte of address
   MSByte = (address >> 8) & 0x00FF;
   
   // LSByte of Address
   LSByte = address & 0x00FF;

   // Send memory address
   if (I2C_Write_Byte(MSByte))
     {
     Error_code_G = ERROR_I2C_WRITE_BYTE_AT24C64;
     return;
     }

   // Send memory address
   if (I2C_Write_Byte(LSByte))
     {
     Error_code_G = ERROR_I2C_WRITE_BYTE_AT24C64;
     return;
     }

   // Send content to memory address
   if (I2C_Write_Byte(content))
     {
     Error_code_G = ERROR_I2C_WRITE_BYTE_AT24C64;
     return;
     }

   I2C_Send_Stop();    

   return;
   }


/*------------------------------------------------------------------*-

  I2C_Read_Byte_AT24C64()

  Read a byte of data from the EEPROM.

-*------------------------------------------------------------------*/
tByte I2C_Read_Byte_AT24C64(tWord address)
   {
   tByte MSByte;  // Most significant byte of data address
   tByte LSByte;  // Least significant byte of data address
   tByte Result = 0;

   I2C_Send_Start();   // Generate START condition

   // Send SLAVE address with dummy write request
   if (I2C_Write_Byte(I2C_EEPROM_ID|I2C_WRITE))
      {
      Error_code_G = ERROR_I2C_READ_BYTE_AT24C64;
      return 0;
      }

   // MSByte of address
   MSByte = (address >> 8) & 0x00FF;
   
   // LSByte of Address
   LSByte = address & 0x00FF;

   // Send memory address
   if (I2C_Write_Byte(MSByte))
     {
     Error_code_G = ERROR_I2C_READ_BYTE_AT24C64;
     return 0;
     }

   // Send memory address
   if (I2C_Write_Byte(LSByte))
     {
     Error_code_G = ERROR_I2C_READ_BYTE_AT24C64;
     return 0;
     }

   I2C_Send_Start();   // Generate START condition

   // Send SLAVE address with read request
   if (I2C_Write_Byte(I2C_EEPROM_ID | I2C_READ))
      {
      Error_code_G = ERROR_I2C_READ_BYTE_AT24C64;
      return 0;
      }

   Result = I2C_Read_Byte();   // Read memory content

   // Don´t perform a MASTER ACK
   I2C_Send_Stop();            

   return(Result);
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/




