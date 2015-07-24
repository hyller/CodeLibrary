/*------------------------------------------------------------------*-

   SPI_X25.C (v1.00)

  ------------------------------------------------------------------

   Simple SPI library for Atmel AT89S53
   - allows data storage on Xicor X25138 EEPROM (or similar)


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

#include "SPI_Core.h"
#include "SPI_X25.h"
#include "TimeoutH.h"

// ------ Public variable declarations -----------------------------

// Used to display the error code
// See Main.H for details of error codes
// See Port.H for details of the error port
extern tByte Error_code_G;

// ------ Private function prototypes ------------------------------

void SPI_Delay_T0(void);
void SPI_X25_Read_Status_Register(void);

/*------------------------------------------------------------------*-

  SPI_X25_Write_Byte()

  Store a byte of data on the EEPROM.

-*------------------------------------------------------------------*/
void SPI_X25_Write_Byte(const tWord ADDRESS, const tByte DATA)
   {
   // 0. We check the status register
   SPI_X25_Read_Status_Register();  
   
   // 1. Pin /CS is pulled low to select the device
   SPI_CS = 0;
  
   // 2. The 'Write Enable' instruction is sent (0x06)
   SPI_Exchange_Bytes(0x06);

   // 3. The /CS must now be pulled high
   SPI_CS = 1;

   // 4. Wait (briefly)
   SPI_Delay_T0();

   // 5. Pin /CS is pulled low to select the device
   SPI_CS = 0;
  
   // 6. The 'Write' instruction is sent (0x02)
   SPI_Exchange_Bytes(0x02);

   // 7. The address we wish to read from is sent.  
   //    NOTE: we send a 16-bit address: 
   //    - depending on the size of the device, some bits may be ignored.
   SPI_Exchange_Bytes((ADDRESS >> 8) & 0x00FF);  // Send MSB
   SPI_Exchange_Bytes(ADDRESS & 0x00FF);         // Send LSB

   // 8. The data to be written is shifted out on MOSI
   SPI_Exchange_Bytes(DATA);

   // 9. Pull the /CS pin high to complete the operation
   SPI_CS = 1;
   }


/*------------------------------------------------------------------*-

  SPI_X25_Read_Byte()

  Read a byte of data from the EEPROM.

-*------------------------------------------------------------------*/
tByte SPI_X25_Read_Byte(const tWord ADDRESS)
   {
   tByte Data;

   // 0. We check the status register
   SPI_X25_Read_Status_Register();  
   
   // 1. Pin /CS is pulled low to select the device
   SPI_CS = 0;
  
   // 2. The 'Read' instruction is sent (0x03)
   SPI_Exchange_Bytes(0x03);

   // 3. The address we wish to read from is sent.  
   // NOTE: we send a 16-bit address: 
   // depending on the size of the device, some bits may be ignored.
   SPI_Exchange_Bytes((ADDRESS >> 8) & 0x00FF);
   SPI_Exchange_Bytes(ADDRESS & 0x00FF);

   // 4. The data requested is shifted out on SO by sending a dummy byte
   Data = SPI_Exchange_Bytes(0x00);

   // 5. We pull the /CS pin high to complete the operation
   SPI_CS = 1;

   return Data; // Return SPI data byte
   }

/*------------------------------------------------------------------*-

  SPI_X25_Read_Status_Register()

  We read the status register only to make sure that previous
  'Write' operations (if any) are now complete.

  To do this, we check the WIP ('Write In Progress') flag.

  *** NB: THE INTERNAL EEPROM WRITE OPERATION TAKES UP 10ms ***
  *** Schedule writes (and reads after writes) at sensible ***
  *** intervals - or you will get task jitter ***

  We timeout after ~15ms.

  Uses T0 for (hardware) timeout - see Chapter 15.

-*------------------------------------------------------------------*/
void SPI_X25_Read_Status_Register()
   {
   tByte Data;
   bit Wip;

   // Configure Timer 0 as a 16-bit timer 
   TMOD &= 0xF0; // Clear all T0 bits (T1 left unchanged)
   TMOD |= 0x01; // Set required T0 bits (T1 left unchanged) 

   ET0 = 0;  // No interrupts

   // Simple timeout feature - approx 15ms
   TH0 = T_15ms_H; // See TimeoutH.H for T_ details
   TL0 = T_15ms_L;
   TF0 = 0; // Clear flag
   TR0 = 1; // Start timer

   do {
      // 0. Pin /CS is pulled low to select the device
      SPI_CS = 0;

      // 1. The 'RDSR' instruction is sent (0x05)
      SPI_Exchange_Bytes(0x05);

      // 2. The contents of the ROM status register are read
      Data = SPI_Exchange_Bytes(0x00);

      // 3. Pull the /CS pin high to complete the operation
      SPI_CS = 1;

      // Check the WIP flag
      Wip = (Data & 0x01);
      } while ((Wip != 0) && (TF0 != 1));

   TR0 = 0;  

   if (TF0 == 1)
      {
      // ROM timed out
      Error_code_G = ERROR_SPI_X25_TIMEOUT;
      }
   } 

/*------------------------------------------------------------------*-

  SPI_Delay_T0()

  A delay of approx 50 µs using 'timeout' code.

-*------------------------------------------------------------------*/
void SPI_Delay_T0(void)
   {
   // Configure Timer 0 as a 16-bit timer 
   TMOD &= 0xF0; // Clear all T0 bits (T1 left unchanged)
   TMOD |= 0x01; // Set required T0 bits (T1 left unchanged) 

   ET0 = 0;  // No interrupts

   // Simple timeout feature - approx 50 µs
   TH0 = T_50micros_H; // See TimeoutH.H for T_ details
   TL0 = T_50micros_L;
   TF0 = 0; // Clear flag
   TR0 = 1; // Start timer

   while (!TF0);

   TR0 = 0;  
   }
  
/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/ 
