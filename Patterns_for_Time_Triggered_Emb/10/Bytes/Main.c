/*------------------------------------------------------------------*-

   Main.C (v1.00)

  ------------------------------------------------------------------

   Test program for pattern PORT I-O
 
   Reads from P1 and copies the value to P2.


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

// File Main.H is the 'Project Header' and is described in Chapter 9.
#include <Main.H>  

/* ............................................................... */

void main (void)
   {
   unsigned char Port1_value;

   // Must set up P1 for reading
   P1 = 0xFF;

   while(1) 
     { 
     // Read the value of P1
     Port1_value = P1;

     // Copy the value to P2
     P2 = Port1_value;
     }
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
