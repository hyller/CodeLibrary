/*------------------------------------------------------------------*-

   I2C_ROM.H (v1.00)

  ------------------------------------------------------------------

   - See I2C_ROM.C for details.


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"

// ------ Public function prototypes -------------------------------

// Read byte from EEPROM
tByte I2C_Read_Byte_AT24C64(tWord);

// Write byte to EEPROM
void I2C_Write_Byte_AT24C64(tWord,tByte);

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
