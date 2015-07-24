/*------------------------------------------------------------------*-

   PC_IO_T2.C (v1.01)

  ------------------------------------------------------------------

   PC link library. Bidirectional. T2 used for baud rate generation.

   Uses the USART, and Pins 3.1 (Tx) and 3.0 (Rx) 

   See text for details (Chapter 18).


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"
#include "PC_IO_T2.h"

// ------ Public variable declarations -----------------------------

extern tByte In_read_index_G;     
extern tByte In_waiting_index_G;  

extern tByte Out_written_index_G;  
extern tByte Out_waiting_index_G;  

/*------------------------------------------------------------------*-

  PC_LINK_IO_Init_T2()

  This version uses T2 for baud rate generation.

-*------------------------------------------------------------------*/
void PC_LINK_IO_Init_T2(const tWord BAUD_RATE)
   {
   tWord RCAP2;

   PCON &= 0x7F;   // Set SMOD bit to 0 (don't double baud rates)

   //  Receiver enabled.
   //  8-bit data, 1 start bit, 1 stop bit, 
   //  Variable baud rate (asynchronous)
   //  Receive flag will only be set if a valid stop bit is received
   //  Set TI (transmit buffer is empty)
   SCON = 0x72;

   // T2 used for baud rate generation.
   // Gives accurate baud rates, even at 12 MHz, etc...
   T2CON = 0x34; // Load timer 2 control register
   T2MOD = 0x00; // Load timer 2 mode register
   ET2   = 0;

   // Typically, as a timer, T2  would increment at fOSC /12. 
   // As a baud rate generator, it increments at fOSC /2. 
   //
   // The baud rate (Mode 1 or 3) is given by the formula:
   //
   // Baud rate = fOSC /(32 * [65536 - (RCAP2H, RCAP2L)])
   //
   // This allows us to do the following:
   RCAP2  = 65536 - (tWord)((tLong)OSC_FREQ/((tLong)32 * BAUD_RATE));
   RCAP2H = RCAP2 / 256;
   TH2    = RCAP2H;
   RCAP2L = RCAP2 % 256;
   TL2    = RCAP2L;

   TR2   = 1;  // Start timer 2

   TI = 1;     // Send first character (dummy)

   // Set up the buffers for reading and writing
   In_read_index_G = 0;
   In_waiting_index_G = 0;
   Out_written_index_G = 0;
   Out_waiting_index_G = 0;

   PC_LINK_IO_Write_String_To_Buffer("Serial OK\n");

   // Interrupt *NOT* enabled
   ES = 0;
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
