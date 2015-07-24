/*------------------------------------------------------------------*-
  
   SCU_Bm.H (v1.00)

  ------------------------------------------------------------------

   - see SCU_Bm.C for details


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"
#include "SCH51.H"

// ------ Public function prototypes -------------------------------

void SCU_B_MASTER_Init_T1_T2(const tWord);
void SCU_B_MASTER_Start(void);
void SCU_B_MASTER_Enter_Safe_State(void);

// ------ Public constants -----------------------------------------

#define NUMBER_OF_SLAVES 1
                              
/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/


