/*------------------------------------------------------------------*-

   Main.c (v1.00)

  ------------------------------------------------------------------
 
   Speech playback example, uses hybrid scheduler.
   

   Required linker options (see Chapter 14 for details):

   OVERLAY 
   (main ~ (SWITCH_Update), 
    SWITCH_Update ~ (SPEECH_PLAYBACK_Update),
    hSCH_dispatch_tasks ! (SWITCH_Update, SPEECH_PLAYBACK_Update))
 

   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"
#include "2_01_12h.h" 
#include "Swit_Ply.h"
#include "Playback.h"

/* ............................................................... */
/* ............................................................... */

void main(void)
   {
   // Set up the scheduler
   hSCH_Init_T2();

   // Set up the switch pin
   SWITCH_Init();

   // Add the 'switch' task (check every 200 ms)
   // THIS IS A PRE-EMPTIVE TASK
   hSCH_Add_Task(SWITCH_Update, 0, 200, 0);

   // NOTE:
   // 'Playback' task is added by the SWITCH_Update task
   // (as requested by user)
   // 'Playback' is CO-OPERATIVE
   // *** NOTE REQUIRED LINKER OPTIONS (see above) ***

   // Start the scheduler
   hSCH_Start();

   while(1)
      {
      hSCH_Dispatch_Tasks();
      }
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
