/*------------------------------------------------------------------*-

   T_Lights.H (v1.00)

  ------------------------------------------------------------------
   
   - See T_Lights.C for details.


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

// ------ Public data type declarations ----------------------------

// Possible system states
typedef 
enum {RED, RED_AND_AMBER, GREEN, AMBER, BULB_BLOWN} eLight_State;


// ------ Public constants -----------------------------------------

#define MASTER 1
#define SLAVE 0

// ------ Public function prototypes -------------------------------

void TRAFFIC_LIGHTS_Init(const eLight_State);
void TRAFFIC_LIGHTS_Update(void);

void TRAFFIC_LIGHTS_Display_Safe_Output(void);

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
