/*------------------------------------------------------------------*-

   I2C_CORE.C (v1.00)

  ------------------------------------------------------------------

   Core of the I2C library.

   You will typically need other components 
   (see, for example, I2C_ROM.C) to create a complete library.

   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"
#include "I2C_Core.h"
#include "TimeoutH.H"

// ------ Port pins ------------------------------------------------

// The two-wire I2C bus
sbit I2C_SCL = P1^7;
sbit I2C_SDA = P1^6;

// ------ Private function prototypes ------------------------------

static tByte I2C_Get_Ack_From_Slave(void); 
static bit   I2C_Sync_The_Clock_T0(void);   
static void  I2C_Delay(void);  

// Comment out this line if these functions are *not* required
// (see text for details)
#define I2C_ACK_NACK

/*------------------------------------------------------------------*-

  I2C_Send_Start()

  Generates a 'start' condition (see text for details).

-*------------------------------------------------------------------*/
void I2C_Send_Start(void)
   {
   // Prepare the bus
   I2C_SCL = 1; 
   I2C_SDA = 1; 
   I2C_Delay();  

   // Generate the START condition
   I2C_SDA = 0; 
   I2C_Delay(); 
   I2C_SCL = 0;
   }


/*------------------------------------------------------------------*-

  I2C_Send_Stop()

  Generates a 'stop' condition (see text for details).

-*------------------------------------------------------------------*/
void I2C_Send_Stop(void)
   {
   I2C_SDA = 0; 
   I2C_Delay();   
   I2C_SCL = 1; 
   I2C_Delay();   
   I2C_SDA = 1;   
   }

/*------------------------------------------------------------------*-

  I2C_Get_Ack_From_Slave()

  We are implementing a 'Master-Slave' communication protocol
  here, with the microcontroller as the Master.  This function
  waits (with timeout) for an acknowledgement from the Slave device.

-*------------------------------------------------------------------*/
tByte I2C_Get_Ack_From_Slave(void)
   {
   // Prepare the bus
   I2C_SDA = 1; 
   I2C_SCL = 1;

   if(I2C_Sync_The_Clock_T0())
     {
     return 1; // Error - failed to sync
     }

   // Managed to synchronise the clock
   I2C_Delay();       
   
   if (I2C_SDA)       
      {
      // Generate a clock cycle
      I2C_SCL = 0;  

      return 1;  // Error - No ack from slave 
      }

   I2C_SCL = 0; // Generate a clock cycle

   return 0;     // OK - Slave issued ack
   }


/*------------------------------------------------------------------*-

  I2C_Write_Byte()

  Send a byte of data to the Slave.  
  Supports slow Slaves by allowing 'clock stretching'.

-*------------------------------------------------------------------*/
tByte I2C_Write_Byte(tByte Data)
   {
   tByte Bit = 0;  

   // Sending data one bit at a time (MS bit first) 
   for (Bit = 0; Bit < 8; Bit++ )
     {
     I2C_SDA = (bit)((Data & 0x80) >> 7); 
     I2C_SCL = 1;  
                      
     if (I2C_Sync_The_Clock_T0())
       {
       return 1; // Error - failed to sync
       }

     I2C_Delay(); 

     // Generate a clock cycle
     I2C_SCL = 0;                        

     // Prepare to send next bit
     Data <<= 1;                    
     }

   // Make sure the slave acknowledges
   return(I2C_Get_Ack_From_Slave());
   }


/*------------------------------------------------------------------*-

  I2C_Read_Byte()

  Read a byte of data from the Slave.  
  Supports slow Slaves by allowing 'clock stretching'.

-*------------------------------------------------------------------*/
tByte I2C_Read_Byte(void)
   {
   tByte result  = 0;  // Return value with read I2C byte
   tByte Bit = 0;      // Bitcounter

   for (Bit = 0; Bit < 8; Bit++ )
     {
     I2C_SDA = 1;           // Release SDA
     I2C_SCL = 1;           // Release SCL

     if (I2C_Sync_The_Clock_T0())
       {
       return 1; // Error - failed to sync
       }

     I2C_Delay(); 

     result <<= 1;      // Shift left the result

     if (I2C_SDA)
        {
        result |= 0x01;  // Set actual SDA state to LSB
        }

     I2C_SCL = 0;       // Force a clock cycle
     I2C_Delay();       
     }

   return(result);
   }

/*------------------------------------------------------------------*-

  I2C_Sync_The_Clock_T0()

  Low-level function used during I2C data transfers.

  *** With 1ms hardware (Timer 0) timeout ***

  RETURNS:  1 - Error (not synchronised)
            0 - OK (clock synchronised)

-*------------------------------------------------------------------*/
bit I2C_Sync_The_Clock_T0(void)
   {
   // Configure Timer 0 as a 16-bit timer 
   TMOD &= 0xF0; // Clear all T0 bits (T1 left unchanged)
   TMOD |= 0x01; // Set required T0 bits (T1 left unchanged) 

   ET0 = 0;  // No interrupts

   // Simple timeout feature - approx 1ms
   TH0 = T_01ms_H; // See TimeoutH.H for T_ details
   TL0 = T_01ms_L;
   TF0 = 0; // Clear flag
   TR0 = 1; // Start timer

   // Try to synchronise the clock
   while ((I2C_SCL == 0) && (TF0 != 1)); 

   TR0 = 0; // Stop the timer  

   if (TF0 == 1)
      {
      return 1;  // Error - Timeout condition failed
      }

   return 0;  // OK - Clock synchronised
   }

/*------------------------------------------------------------------*-

  I2C_Delay()

  A short software delay (around 10 µs).  

  Adjust this for a minimum of 5.425 µs to work with
  'standard' I2C devices.  Any delay longer than this will also work.
  With modern devices shorter delays may also be used.

  NOTE: Cannot do this with a Hardware Delay!!!

-*------------------------------------------------------------------*/
void I2C_Delay(void)
   {
   int x;

   x++;
   x++;
   }

#ifdef I2C_ACK_NACK
/*------------------------------------------------------------------*-

  I2C_Send_Master_Ack()

  Generates an 'Acknowledge' condition (see text for details).

-*------------------------------------------------------------------*/
void I2C_Send_Master_Ack(void)
   {
   I2C_SDA = 0; 
   I2C_SCL = 1;

   I2C_Sync_The_Clock_T0();

   I2C_Delay();  
   I2C_SCL = 0;  
   }


/*------------------------------------------------------------------*-

  I2C_Send_Master_NAck()

  Generates a 'Not Acknowledge' condition (see text for details).

-*------------------------------------------------------------------*/
void I2C_Send_Master_NAck(void)
   {
   I2C_SDA = 1; I2C_SCL = 1; 

   I2C_Sync_The_Clock_T0();

   I2C_Delay();
   I2C_SCL = 0;
   } 
#endif

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/




