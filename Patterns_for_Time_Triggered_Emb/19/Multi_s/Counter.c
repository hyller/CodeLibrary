/*------------------------------------------------------------------*-

   Counter.C (v1.00)

  ------------------------------------------------------------------

   Simple 'counter' function, 
   (to illustrate use of multi-state switches.)


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"
#include "Counter.h"
#include "Bargraph.h"

// ------ Public variable definitions ------------------------------

extern tBargraph Data_G;

// ------ Public variable declarations -----------------------------

extern tByte Sw_status_G;


/*------------------------------------------------------------------*-

  COUNTER_Update()

  Simple counter function (demo purposes).

-*------------------------------------------------------------------*/
void COUNTER_Update(void)
   {
   Data_G += Sw_status_G;

   if (Data_G > BARGRAPH_MAX)
      {
      Data_G = 0;
      }

   BARGRAPH_Update();
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/

