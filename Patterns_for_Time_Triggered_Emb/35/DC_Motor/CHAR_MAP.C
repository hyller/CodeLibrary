/*------------------------------------------------------------------*-

   Char_Map.C (v1.00)

  ------------------------------------------------------------------

   This lookup table (stored in ROM) are used to convert ‘integer’ 
   values into appropriate character codes for the LCD display 
   and RS232 link.


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

// ------ Public constants -----------------------------------------

const char code CHAR_MAP_G[10] 
                = {'0','1','2','3','4','5','6','7','8','9'};

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/


