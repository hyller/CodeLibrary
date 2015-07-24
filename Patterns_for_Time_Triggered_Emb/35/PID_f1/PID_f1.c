/*------------------------------------------------------------------*-

   PID_f1.C (v1.00)

  ------------------------------------------------------------------

   Simple PID control implementation. 
   
   See Chapter 35 for details.

     
   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "PID_f1.h"

// ------ Private constants ----------------------------------------

#define PID_KP (0.2f)             // Proportional gain  
#define PID_KI (0.01f)            // Integral gain          
#define PID_KD (0.01f)            // Differential gain  

#define PID_MAX (1.0f)            // Maximum PID controller output
#define PID_MIN (0.0f)            // Minimum PID controller output

// ------ Private variable definitions------------------------------

static float Sum_G;       // Integrator component
static float Old_error_G; // Previous error value

/*------------------------------------------------------------------*-

  PID_Control()

  Simple floating-point version.
  
  See text for details.
  
-*------------------------------------------------------------------*/
float PID_Control(float Error, float Control_old)
   {
   // Proportional term   
   float Control_new = Control_old + (PID_KP * Error);

   // Integral term
   Sum_G += Error;
   Control_new += PID_KI * Sum_G;

   // Differential term
   Control_new += (PID_KD * SAMPLE_RATE * (Error - Old_error_G));
   
   // Control_new cannot exceed PID_MAX or fall below PID_MIN    
   if (Control_new > PID_MAX) 
      {
      Control_new = PID_MAX; 
      }
   else
      {
      if (Control_new < PID_MIN) 
         {
         Control_new = PID_MIN; 
         }
      }    
 
    // Store error value
    Old_error_G = Error;

    return Control_new;
    }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
