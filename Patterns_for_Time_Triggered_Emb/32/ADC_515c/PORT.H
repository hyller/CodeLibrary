/*------------------------------------------------------------------*-

   Port.H (v1.00)

  ------------------------------------------------------------------

  'Port Header' (see Chap 10) for the project ADC_BAR (see Chap 32)


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

// ------ ADC_515c.C -----------------------------------------------

// Reads from ADC channel 0 (Pin 6.0)

// ------ Bargraph.C -----------------------------------------------

// Connect LED from +5V (etc) to these pins, via appropriate resistor
// [see Chapter 7 for details]
// The 8 port pins may be distributed over several ports if required
sbit Pin0 = P4^0;
sbit Pin1 = P4^1;
sbit Pin2 = P4^2;
sbit Pin3 = P4^3;
sbit Pin4 = P4^4;
sbit Pin5 = P4^5;
sbit Pin6 = P4^6;
sbit Pin7 = P4^7;


/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/



