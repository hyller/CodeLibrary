/*------------------------------------------------------------------*-

   T_lights.C (v1.00)

  ------------------------------------------------------------------
   
   Traffic light control program (Test Version 1.0)


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/


#include "Main.h"
#include "Port.h"

#include "T_lights.h"

// ------ Private constants ----------------------------------------

// Easy to change logic here
#define ON  0
#define OFF 1

// Times in each of the (four) possible light states
// (Times are in seconds - must call the update task once per second)
//
#define RED_DURATION  (10)
#define RED_AND_AMBER_DURATION  (10)

// NOTE: 
// GREEN_DURATION must equal RED_DURATION
// AMBER_DURATION must equal RED_AND_AMBER_DURATION
#define GREEN_DURATION RED_DURATION 
#define AMBER_DURATION RED_AND_AMBER_DURATION

// ------ Private variables ----------------------------------------

// The state of the system
static eLight_State Light_state_G;

/*------------------------------------------------------------------*-

  TRAFFIC_LIGHTS_Init()

  Prepare for the scheduled traffic light activity.

-*------------------------------------------------------------------*/
void TRAFFIC_LIGHTS_Init(const eLight_State START_STATE)
   {
   Light_state_G = START_STATE;  // Slave is Green; Master is Red
   }


/*------------------------------------------------------------------*-

  TRAFFIC_LIGHTS_Update()

  Must be called once per second.

-*------------------------------------------------------------------*/
void TRAFFIC_LIGHTS_Update(void)
   {
   static tWord Time_in_state;

   switch (Light_state_G)
      {
      case RED: 
         {
         Red_light = ON;
         Amber_light = OFF;
         Green_light = OFF;

         if (++Time_in_state == RED_DURATION)
            {
            Light_state_G = RED_AND_AMBER;
            Time_in_state = 0;
            }

         break;
         }

      case RED_AND_AMBER: 
         {
         Red_light = ON;
         Amber_light = ON;
         Green_light = OFF;

         if (++Time_in_state == RED_AND_AMBER_DURATION)
            {
            Light_state_G = GREEN;
            Time_in_state = 0;
            }

         break;
         }

      case GREEN: 
         {
         Red_light = OFF;
         Amber_light = OFF;
         Green_light = ON;

         if (++Time_in_state == GREEN_DURATION)
            {
            Light_state_G = AMBER;
            Time_in_state = 0;
            }

         break;
         }

      case AMBER: 
         {
         Red_light = OFF;
         Amber_light = ON;
         Green_light = OFF;

         if (++Time_in_state == AMBER_DURATION)
            {
            Light_state_G = RED;
            Time_in_state = 0;
            }

         break;
         }
      }
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
