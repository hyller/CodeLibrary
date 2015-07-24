/*------------------------------------------------------------------*-

   PID_wf1.H (v1.00)

  ------------------------------------------------------------------

   See PID_wf1.C for details.


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

// ------ Public function prototypes -------------------------------

float PID_Control(float,float);   

// ------ Public constants -----------------------------------------

#define SAMPLE_RATE (1)        // Hz

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
