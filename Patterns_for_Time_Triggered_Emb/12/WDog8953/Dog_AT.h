/*------------------------------------------------------------------*-

   Dog_AT.H (v1.00)

  ------------------------------------------------------------------

   - see Dog_AT.C for details.


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/


#include <At89S53.h>

// Function prototypes
void WATCHDOG_Init(void);  // Start the watchdog

// We use a macro to feed the watchdog (for speed)
#define WATCHDOG_Feed() WMCON |= 0x02

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/





