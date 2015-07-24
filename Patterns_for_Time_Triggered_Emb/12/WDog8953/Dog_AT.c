/*------------------------------------------------------------------*-

   Dog_AT.C (v1.00)

  ------------------------------------------------------------------

   Demonstration of watchdog timer facilities on Atmel 89S53.

   [Compiles and runs but does nothing useful]

   ==============================================================

   *** PORTABILITY NOTE ***

   If porting this code to a different chip, then
   take care when using 'idle mode'.  With *some* devices, 
   use of idle mode stops the internal watchdog timer; this 
   may not be what you require.

   In particular, please note that the scheduler code introduced 
   in Chapter 13 (and used throughout much of this book) makes 
   use of idle mode.  If using a watchdog timer with one of the 
   schedulers, you need to check the data sheet for your chosen 
   microcontroller and - if necessary - make the minor changes
   necessary to the file Sch51.c to prevent the scheduler
   using idle mode. 

   (In the AT89S53, use of idle mode does NOT stop the watchdog)
    
   ==============================================================

   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Dog_AT.h"

/*------------------------------------------------------------------*/
void WATCHDOG_Init(void)
   {
   // Set 512 ms watchdog
   // PS2 = 1; PS1 = 0; PS0 = 1
   // Set WDTRST = 1
   // Set WDTEN  = 1 - start the Watchdog 
   // 
   // WMCON |= 10100011
   WMCON |= 0xA3;  
   } 

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/





