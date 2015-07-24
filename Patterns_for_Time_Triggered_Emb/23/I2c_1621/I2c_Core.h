/*------------------------------------------------------------------*-

   I2C_Core.H (v1.00)

  ------------------------------------------------------------------

   - See I2C_Core.C for details.

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

void  I2C_Send_Start(void);        
void  I2C_Send_Stop(void);         

tByte I2C_Write_Byte(const tByte); 
tByte I2C_Read_Byte(void);         

void I2C_Send_Master_Ack(void);
void I2C_Send_Master_NAck(void);

// ------ Public constants -----------------------------------------

#define I2C_READ      0x01    // Read command
#define I2C_WRITE     0x00    // Write command

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/

