/*------------------------------------------------------------------*-

   PC_IN_in.C (v1.01)

  ------------------------------------------------------------------

   PC link library. Bidirectional. c515,517 etc - internal baud rate.

   Uses the USART, and Pins 3.1 (Tx) and 3.0 (Rx) 

   See text for details.


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"
#include "PC_IO_in.h"

// ------ Public variable declarations -----------------------------

extern tByte In_read_index_G;     
extern tByte In_waiting_index_G;  

extern tByte Out_written_index_G;  
extern tByte Out_waiting_index_G;  

/*------------------------------------------------------------------*-

  PC_LINK_Init_Internal()

  This version uses internal baud rate generator on C5x5 family.

-*------------------------------------------------------------------*/
void PC_LINK_IO_Init_Internal(const tWord BAUD_RATE)
   {
   tWord SRELplus1024;
   tWord SRELx;

   PCON &= 0x7F;   // Set SMOD bit to 0 (don't double baud rates)

   //  Receiver enabled.
   //  8-bit data, 1 start bit, 1 stop bit, 
   //  Variable baud rate (asynchronous)
   //  Receive flag will only be set if a valid stop bit is received
   //  Set TI (transmit buffer is empty)
   SCON = 0x72;

   // Use the internal baudrate generator (80c5x5 family)
   ADCON0 |= 0x80;

   // Set the baud rate (begin)
   SRELplus1024 = (tWord)((((tLong) OSC_FREQ / 100) * 3125) 
                     / ((tLong) BAUD_RATE * 1000));

   SRELx = 1024 - SRELplus1024;

   SRELL = (tByte)(SRELx & 0x00FF);
   SRELH = (tByte)((SRELx & 0x0300) >> 8);

   TI = 1;
   // Set the baud rate (end)

   // Set up the buffers for reading and writing
   In_read_index_G = 0;
   In_waiting_index_G = 0;
   Out_written_index_G = 0;
   Out_waiting_index_G = 0;

   PC_LINK_IO_Write_String_To_Buffer("Serial OK\n");

   // Serial interrupt *NOT* enabled
   ES = 0;
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/



