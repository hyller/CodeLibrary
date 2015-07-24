/*------------------------------------------------------------------*-

   TLight_A.C (v1.00)

  ------------------------------------------------------------------
   
   Traffic light control program 

   Simplex version 
   - has no information about bulb status on other node.


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

#include "TLight_A.h"

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

// Must specify whether this is a MASTER or a SLAVE unit
#define MASTER_SLAVE MASTER

// ------ Private variables ----------------------------------------

// The state of the system
static eLight_State Light_state_G;

// ------ Private function prototypes ------------------------------

bit TRAFFIC_LIGHTS_Check_Local_Bulb(void);

/*------------------------------------------------------------------*-

  TRAFFIC_LIGHTS_Init()

  Prepare for scheduling.

-*-----------------------------------------------------------------*/
void TRAFFIC_LIGHTS_Init(void)
   {
   // Master and slave must start in opposite states
   if (MASTER_SLAVE == MASTER)
      {
      Light_state_G = RED;
      }
   else
      {
      Light_state_G = GREEN;
      }

   // Display safe output until scheduler starts
   TRAFFIC_LIGHTS_Display_Safe_Output();
   }

/*------------------------------------------------------------------*-

  TRAFFIC_LIGHTS_Update()

  Must be scheduled once per second.

-*------------------------------------------------------------------*/
void TRAFFIC_LIGHTS_Update(void)
   {
   static tWord Time_in_state;

   // Check for blown bulbs on this node
   TRAFFIC_LIGHTS_Check_Local_Bulb();

   // This is the main update code
   switch (Light_state_G)
      {
      case RED: 
         {
         Red_light = ON;
         Amber_light = OFF;
         Green_light = OFF;

         if (++Time_in_state == RED_DURATION)
            {
            Light_state_G = RED_AMBER;
            Time_in_state = 0;
            }

         break;
         }

      case RED_AMBER: 
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

      case BULB_BLOWN: 
         {
         // Blown bulb detected
         // Switch all bulbs off
         // (Drivers won't be happy, but it will be clear
         //  that something is wrong)
         Red_light = OFF;
         Amber_light = OFF;
         Green_light = OFF;

         // We remain in this state until state
         // is changed manually, or system is reset
         break;
         }
      }
   }

/*------------------------------------------------------------------*-

  TRAFFIC_LIGHTS_Check_Local_Bulb()

  Check the status of the local bulbs (DUMMY FUNCTION HERE)

-*------------------------------------------------------------------*/
bit TRAFFIC_LIGHTS_Check_Local_Bulb(void)
    {
    // This dummy function confirms the bulbs are OK
    //
    // - See Chapter 32 for further info.
    return RETURN_NORMAL;
    }

/*------------------------------------------------------------------*-

  TRAFFIC_LIGHTS_Display_Safe_Output()

  Used in the event of system failure, etc.

-*------------------------------------------------------------------*/
void TRAFFIC_LIGHTS_Display_Safe_Output(void)
   {
   if (TRAFFIC_LIGHTS_Check_Local_Bulb() == RETURN_NORMAL)
      {
      // Bulbs are OK 
      // - best thing to do is to display STOP
      Red_light = ON;
      Amber_light = OFF;
      Green_light = OFF;
      }
   else
      {
      // At least one bulb has blown 
      // - best thing we can do is extinguish all bulbs
      Red_light = OFF;
      Amber_light = OFF;
      Green_light = OFF;
      } 
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
