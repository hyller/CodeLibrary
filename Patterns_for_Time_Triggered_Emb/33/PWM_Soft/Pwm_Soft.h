/*------------------------------------------------------------------*-

   PWM_SOFT.H (v1.00)

  ------------------------------------------------------------------

   - See PWM_SOFT.C for details.


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"

// ------ Public function prototypes -------------------------------

void PWM_Soft_Init(void);
void PWM_Soft_Update(void);
void PWM_Soft_Test(void);

// ------ Public constants -----------------------------------------

// Use a value of 2^N where N is PWM bits, if required:
// E.g. use 255 for '8-bit PWM'
// E.g. use 32 for '5-bit PWM'
// However, any value may be used
#define PWM_PERIOD 5

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
   
