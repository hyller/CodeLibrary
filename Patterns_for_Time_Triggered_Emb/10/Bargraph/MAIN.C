/*------------------------------------------------------------------*-

   Main.c (v1.00)

  ------------------------------------------------------------------

   Demo program for bargraph display


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"
#include "Bargraph.h"

// ------ Public variable declarations -----------------------------

extern tBargraph Data_G;

/* ............................................................... */
/* ............................................................... */

void main(void)
   {
   tWord x;

   BARGRAPH_Init();

   while(1)
      {
      if (++x == 1000)
         {
         x = 0;
         Data_G++;
         }

      BARGRAPH_Update();
      }
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/

