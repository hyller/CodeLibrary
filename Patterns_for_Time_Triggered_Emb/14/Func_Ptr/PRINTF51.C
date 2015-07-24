/*------------------------------------------------------------------*-

   Printf51.C (v1.00)

  ------------------------------------------------------------------
   
   A simple serial initialisation routine to allow Keil hardware
   simulator to be used to run 'desktop' C examples.

   [Full details of a complete serial interface library are given
   in Chapter 18.  This code is for demo purposes only!!! ]


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"
#include "Printf51.h"

/*------------------------------------------------------------------*-

  Printf51_Init()

  A simple serial initialisation routine to allow Keil hardware
  simulator to be used to run 'desktop' C examples.

-*------------------------------------------------------------------*/
void Printf51_Init(void)
   {
   const tWord BAUD_RATE = 9600;

   PCON &= 0x7F;   // Set SMOD bit to 0 (don't double baud rates)

   //  Receiver enabled.
   //  8-bit data, 1 start bit, 1 stop bit, 
   //  Variable baud rate (asynchronous)
   //  Receive flag will only be set if a valid stop bit is received
   //  Set TI (transmit buffer is empty)
   SCON = 0x72;

   TMOD |= 0x20;   // T1 in mode 2, 8-bit auto reload

   // See Main.H for details of OSC_FREQ and OSC_PER_INST
   TH1 = (256 - (tByte)((((tLong)OSC_FREQ / 100) * 3125) 
            / ((tLong) BAUD_RATE * OSC_PER_INST * 1000)));

   TL1 = TH1;  
   TR1 = 1;  // Run the timer

   TI = 1;   // Send dummy byte

   // Interrupt *NOT* enabled
   ES = 0;
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
