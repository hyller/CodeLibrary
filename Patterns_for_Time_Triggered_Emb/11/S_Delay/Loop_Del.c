/*------------------------------------------------------------------*-

   Loop_Del.c (v1.00)

  ------------------------------------------------------------------

   One possible implementation of the pattern SOFTWARE DELAY, 
   using a loop.   


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

void Loop_Delay(const unsigned int);

/*------------------------------------------------------------------*-

 Loop_Delay()

 Delay duration varies with parameter.  

 Parameter is, *ROUGHLY*, the delay, in milliseconds,
 on 12MHz 8051 (12 osc cycles).

 You need to adjust the timing for your application!

-*------------------------------------------------------------------*/
void Loop_Delay(const unsigned int DELAY)
   {
   unsigned int x, y;

   for (x = 0; x <= DELAY; x++)
      {
      for (y = 0; y <= 120; y++);
      }
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
