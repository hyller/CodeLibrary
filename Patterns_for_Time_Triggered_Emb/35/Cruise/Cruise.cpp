/*------------------------------------------------------------------*-

   Cruise.CPP (v1.00)

  ------------------------------------------------------------------

   Desktop C++ program to demonstrate PID control.

   Cruise-control application using simple vehicle model.

   See Chapter 35 for details.

     
   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include <iostream.h>
#include <fstream.h>
#include <math.h>
#include "PID_wf1.h"

// ------ Private constants ----------------------------------------

#define MS_to_MPH (2.2369)    // Convert metres/sec to miles per hour

#define FRIC (50)             // Friction coeff- Newton Second / Metre 
#define MASS (1000)           // Mass of vehicle (kgs)
#define N_SAMPLES (1000)      // Number of samples
#define ENGINE_POWER (5000)   // N  
#define DESIRED_SPEED (31.3f) // Metres/sec [* 2.2369 to convert to mph]  

/* ............................................................... */
/* ............................................................... */

int main()
   {
   float Throttle = 0.313f;  // Throttle setting (fraction)
   float Old_speed = DESIRED_SPEED, Old_throttle = 0.313f; 
   float Speed, Accel; 
   float Dist;
   float Sum = 0.0f;  
   
   float Error;
   
   // Open file to store results
   fstream out_FP;
   out_FP.open("pid.txt", ios::out);   
      
   if (!out_FP)
      {
      cerr << "ERROR: Cannot open an essential file.";
      return 1; 
      }

   for (int t = 0; t < N_SAMPLES; t++)
      {
      // Error drives the controller 
      Error = (DESIRED_SPEED - Old_speed);
     
      // Calculate throttle setting
      Throttle = PID_Control(Error, Throttle);
      // Throttle = 0.313f; // Use for open-loop demo
      
      // Simple car model
      Accel = (float)(Throttle * ENGINE_POWER - (FRIC * Old_speed)) / MASS;
      Dist = Old_speed + Accel * (1.0f / SAMPLE_RATE);
      Speed = (float) sqrt((Old_speed * Old_speed) + (2 * Accel * Dist));

      // Disturbances
      if (t == 50)
         {
         Speed = 35.8f;  // Sudden gust of wind into rear of car
         }
      
      if (t == 550)
         {
         Speed = 26.8f;  // Sudden gust of wind into front of car
         }

      // Display speed in miles per hour
      cout   << Speed * MS_to_MPH << endl;
      out_FP << Speed * MS_to_MPH << endl;
       
      // Ready for next loop
      Old_speed = Speed;
      Old_throttle = Throttle;
      }
         
 return 0;
 }  

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
