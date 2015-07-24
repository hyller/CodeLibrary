/*------------------------------------------------------------------*-

   Main.c (v1.00)

  ------------------------------------------------------------------

   Demo of hardware PRM.

 
   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"
#include "PRM_Hard.h"


// ------ Public variable declarations -----------------------------

extern tWord PRM_reload_G;

/* ............................................................... */
/* ............................................................... */

void main(void)
   {
   tLong Count = 0;

   PRM_Hardware_Init();

   while(1)
      {
      if (++Count > 10000UL)
         {
         // Slowly increase the PRM frequency
         PRM_reload_G++;

         PRM_Hardware_Update();

         Count = 0;
         }
      }
    }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/





