/*------------------------------------------------------------------*-

   Main.C (v1.00)

  ------------------------------------------------------------------

   Test program for 'Software PWM' library.

   See Chapter 33 for details.


   Required linker options (see Chapter 14 for details):

   OVERLAY (main ~ (PWM_Soft_Update,PWM_Soft_Test), 
   SCH_Dispatch_Tasks ! (PWM_Soft_Update,PWM_Soft_Test))
 

   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"
#include "2_01_12g.h"
#include "PWM_Soft.h"

/* ............................................................... */
/* ............................................................... */

void main()
   {
   SCH_Init_T2();  

   PWM_Soft_Init();  

   // Call every millisecond to update PWM output
   SCH_Add_Task(PWM_Soft_Update, 0, 1);

   // Call every five seconds to change PWM control value
   SCH_Add_Task(PWM_Soft_Test, 10, 3000);

   SCH_Start();

   while(1)
      {
      SCH_Dispatch_Tasks();
      }     
   } 

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
