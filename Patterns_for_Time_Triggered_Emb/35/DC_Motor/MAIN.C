/*------------------------------------------------------------------*-

   Main.c (v1.01)

  ------------------------------------------------------------------

   Motor (speed) control demonstrator.
   PI algorithm.  See text for details (Chapter 35).

   Required linker options (see Chapter 14 for details):

   OVERLAY (main ~ (PID_MOTOR_Poll_Speed_Pulse, 
   PID_MOTOR_Control_Motor, PC_LINK_O_Update), 
   SCH_Dispatch_Tasks ! (PID_MOTOR_Poll_Speed_Pulse, 
   PID_MOTOR_Control_Motor, PC_LINK_O_Update))
 

   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"
#include "2_01_10i.h"

#include "PIDMotor.h"
#include "PC_O_in.h"

/* ............................................................... */
/* ............................................................... */

void main(void)
   {   
   SCH_Init_T2(); // Set up the scheduler
   PID_MOTOR_Init();

   // Set baud rate to 9600, using internal baud rate generator
   PC_LINK_O_Init_Internal(9600);

   // Add a 'pulse count poll' task 
   // TIMING IS IN TICKS (1ms interval)
   // Every 5 milliseconds (200 times per second)
   SCH_Add_Task(PID_MOTOR_Poll_Speed_Pulse, 1, 1);

   SCH_Add_Task(PID_MOTOR_Control_Motor, 300, 1000);

   // Sending data to serial port
   SCH_Add_Task(PC_LINK_O_Update, 3, 1);
     
   // All tasks added: start running the scheduler
   SCH_Start();        

   while(1)
      {
      SCH_Dispatch_Tasks();
      }
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/

