/*------------------------------------------------------------------*-

   Main.C (v1.00)

  ------------------------------------------------------------------

   Test program for pattern PORT I-O
 
   Illustrating the use of bitwise operators

   Reading and writing individual bits
   NOTE: Both bits on same port

   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

// File Main.H is detailed in Appendix A
// This generic code may be used with any 8051 device
// The code is independent of oscillator frequency
#include <Main.H>  

void Write_Bit_P1(unsigned char, bit);
bit Read_Bit_P1(unsigned char);

/* ............................................................... */

void main (void)
   {
   bit x;
   
   for(;;) // Forever...
     {
     x = Read_Bit_P1(0);   // Read Port 1, Pin 0
     Write_Bit_P1(1,x);    // Write to Port 1, Pin 1
     }
   }

/* --------------------------------------------------------------- */

void Write_Bit_P1(unsigned char Pin, bit Value)
   {
   unsigned char p = 1;
   p <<= Pin;  // Left shift
   
   // If we want 1 output at this pin
   if (Value)
      {
      P1 |= p;  // Bitwise OR
      return;
      }
   
   // If we want 0 output at this pin
   p = ~p;  // Complement
   P1 &= p; // Bitwise AND  
   }

/* --------------------------------------------------------------- */

bit Read_Bit_P1(unsigned char Pin)
   {
   unsigned char p = 1;
   p <<= Pin;  // Left shift
   
   // Write a 1 to the pin (to set up for reading)
   Write_Bit_P1(Pin, 1);
   return (P1 & p); // Read the pin
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
