/*------------------------------------------------------------------*-

   Bargraph.h (v1.00)

  ------------------------------------------------------------------

   - See Bargraph.c for details.


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"

// ------ Public data type declarations ----------------------------

typedef tByte tBargraph;

// ------ Public function prototypes -------------------------------

void BARGRAPH_Init(void);
void BARGRAPH_Update(void);

// ------ Public constants -----------------------------------------

#define BARGRAPH_MAX (255)
#define BARGRAPH_MIN (0)

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/

