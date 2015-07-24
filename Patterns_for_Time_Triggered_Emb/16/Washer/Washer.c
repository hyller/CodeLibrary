/*------------------------------------------------------------------*-

   Washer.C (v1.00)

  ------------------------------------------------------------------

   Multi-state framework for washing-machine controller.


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.H"
#include "Washer.H"

// ------ Private data type declarations ---------------------------

// Possible system states
typedef enum {START, FILL_DRUM, HEAT_WATER, 
              WASH_01, WASH_02, ERROR} eSystem_state;

// ------ Private function prototypes ------------------------------

tByte WASHER_Read_Selector_Dial(void);
bit   WASHER_Read_Start_Switch(void);
bit   WASHER_Read_Water_Level(void);
bit   WASHER_Read_Water_Temperature(void);

void  WASHER_Control_Detergent_Hatch(bit);
void  WASHER_Control_Door_Lock(bit);
void  WASHER_Control_Motor(bit);
void  WASHER_Control_Pump(bit);
void  WASHER_Control_Water_Heater(bit);
void  WASHER_Control_Water_Valve(bit);

// ------ Private constants ----------------------------------------

#define OFF 0
#define ON 1

#define MAX_FILL_DURATION (tLong) 1000
#define MAX_WATER_HEAT_DURATION (tLong) 1000

#define WASH_01_DURATION 30000

// ------ Private variables ----------------------------------------

static eSystem_state System_state_G;

static tWord Time_in_state_G;

static tByte Program_G;

// Ten different programs are supported
// Each one may or may not use detergent
static tByte Detergent_G[10] = {1,1,1,0,0,1,0,1,1,0};

// Each one may or may not use hot water
static tByte Hot_Water_G[10] = {1,1,1,0,0,1,0,1,1,0};

/* --------------------------------------------------------------- */
void WASHER_Init(void)
   {
   // Set up initial state
   // Motor is off
   WASHER_Control_Motor(OFF);

   // Pump is off
   WASHER_Control_Pump(OFF);

   // Heater is off
   WASHER_Control_Water_Heater(OFF);

   // Valve is closed
   WASHER_Control_Water_Valve(OFF);

   // Wait (indefinately) until START is pressed
   while (WASHER_Read_Start_Switch() != 1);

   System_state_G = START;

   // Read the selector dial
   Program_G = WASHER_Read_Selector_Dial();
   }


/* --------------------------------------------------------------- */
void WASHER_Update(void)
   {
   static tWord Time_in_state;

   switch (System_state_G)
      {
      case START: 
         {
         // For demo purposes only
         P1 = (tByte) System_state_G;

         // Lock the door
         WASHER_Control_Door_Lock(ON);

         // Start filling the drum
         WASHER_Control_Water_Valve(ON);

         // Release the detergent (if any)
         if (Detergent_G[Program_G] == 1)
            {
            WASHER_Control_Detergent_Hatch(ON);
            }

         // Ready to go to next state
         System_state_G = FILL_DRUM;
         Time_in_state_G = 0;

         break;
         }

      case FILL_DRUM: 
         {
         // For demo purposes only
         P1 = (tByte) System_state_G;

         // Remain in this state until drum is full
         // NOTE: Timeout facility included here
         if (++Time_in_state_G >= MAX_FILL_DURATION)
            {
            // Should have filled the drum by now...
            System_state_G = ERROR;
            }

         // Check the water level
         if (WASHER_Read_Water_Level() == 1)
            {
            // Drum is full

            // Does the program require hot water?
            if (Hot_Water_G[Program_G] == 1)
               {
               WASHER_Control_Water_Heater(ON);

               // Ready to go to next state
               System_state_G = HEAT_WATER;
               Time_in_state_G = 0;
               }
            else
               {
               // Using cold water only
               // Ready to go to next state
               System_state_G = WASH_01;
               Time_in_state_G = 0;
               }
            }
         break;
         }

      case HEAT_WATER: 
         {
         // For demo purposes only
         P1 = (tByte) System_state_G;

         // Remain in this state until water is hot
         // NOTE: Timeout facility included here
         if (++Time_in_state_G >= MAX_WATER_HEAT_DURATION)
            {
            // Should have warmed the water by now...
            System_state_G = ERROR;
            }

         // Check the water temperature
         if (WASHER_Read_Water_Temperature() == 1)
            {
            // Water is at required temperature
            // Ready to go to next state
            System_state_G = WASH_01;
            Time_in_state_G = 0;
            }

         break;
         }

      case WASH_01: 
         {
         // For demo purposes only
         P1 = (tByte) System_state_G;

         // All wash program involve WASH_01
         // Drum is slowly rotated to ensure clothes are fully wet
         WASHER_Control_Motor(ON);

         if (++Time_in_state >= WASH_01_DURATION)
            {
            System_state_G = WASH_02;
            Time_in_state = 0;
            }

         break;
         }

      // REMAINING WASH PHASES OMITTED HERE ...

      case WASH_02: 
         {
         // For demo purposes only
         P1 = (tByte) System_state_G;

         break;
         }

      case ERROR: 
         {
         // For demo purposes only
         P1 = (tByte) System_state_G;

         break;
         }
      }
   }

/* --------------------------------------------------------------- */
tByte WASHER_Read_Selector_Dial(void)
   {
   // User code here...

   return 0;
   }

/* --------------------------------------------------------------- */
bit WASHER_Read_Start_Switch(void)
   {
   // User code here...

   return 1;
   }

/* --------------------------------------------------------------- */
bit WASHER_Read_Water_Level(void)
   {
   // User code here...

   return 1;
   }

/* --------------------------------------------------------------- */
bit WASHER_Read_Water_Temperature(void)
   {
   // User code here...

   return 1;
   }

/* --------------------------------------------------------------- */
void WASHER_Control_Detergent_Hatch(bit State)
   {
   bit Tmp = State;
   // User code here...
   }

/* --------------------------------------------------------------- */
void WASHER_Control_Door_Lock(bit State)
   {
   bit Tmp = State;
   // User code here...
   }

/* --------------------------------------------------------------- */
void WASHER_Control_Motor(bit State)
   {
   bit Tmp = State;
   // User code here...
   }

/* --------------------------------------------------------------- */
void WASHER_Control_Pump(bit State)
   {
   bit Tmp = State;
   // User code here...
   }

/* --------------------------------------------------------------- */
void WASHER_Control_Water_Heater(bit State)
   {
   bit Tmp = State;
   // User code here...
   }

/* --------------------------------------------------------------- */
void WASHER_Control_Water_Valve(bit State)
   {
   bit Tmp = State;
   // User code here...
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/





