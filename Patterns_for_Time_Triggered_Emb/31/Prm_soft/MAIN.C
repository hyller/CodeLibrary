/*------------------------------------------------------------------*-

   Main.c (v1.00)

  ------------------------------------------------------------------

   Demo of Software PRM.

 
   Required linker options (see Chapter 14 for details):

   OVERLAY (main ~ (PRM_Soft_Update,PRM_Soft_Test), 
   SCH_Dispatch_Tasks ! (PRM_Soft_Update,PRM_Soft_Test))
 

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
#include "PRM_Soft.h"

/* ............................................................... */
/* ............................................................... */

void main()
   {
   SCH_Init_T2();  

   PRM_Soft_Init();  

   // Call every millisecond to update PRM output
   SCH_Add_Task(PRM_Soft_Update, 10, 1);

   // Call every minute to change PRM control value
   SCH_Add_Task(PRM_Soft_Test, 0, 60000);

   SCH_Start();

   while(1)
      {
      SCH_Dispatch_Tasks();
      }     
   } 

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
