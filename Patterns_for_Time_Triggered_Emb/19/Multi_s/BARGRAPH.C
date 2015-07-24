/*------------------------------------------------------------------*-

   Bargraph.c (v1.00)

  ------------------------------------------------------------------

   Simple bargraph library.  

   See Chapter 10 for further details.


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

#include "Bargraph.h"

// ------ Public variable declarations -----------------------------

// The data to be displayed
tBargraph Data_G;

// ------ Private constants ----------------------------------------

#define BARGRAPH_ON (1)
#define BARGRAPH_OFF (0)

// ------ Private variables ----------------------------------------

// These  variables store the thresholds
// used to update the display
static tBargraph M9_1_G;
static tBargraph M9_2_G;
static tBargraph M9_3_G;
static tBargraph M9_4_G;
static tBargraph M9_5_G;
static tBargraph M9_6_G;
static tBargraph M9_7_G;
static tBargraph M9_8_G;


/*------------------------------------------------------------------*-

  BARGRAPH_Init()

  Prepare for the bargraph display.

-*------------------------------------------------------------------*/
void BARGRAPH_Init(void)
   {
   Pin0 = BARGRAPH_OFF;   
   Pin1 = BARGRAPH_OFF;   
   Pin2 = BARGRAPH_OFF;   
   Pin3 = BARGRAPH_OFF;   
   Pin4 = BARGRAPH_OFF;   
   Pin5 = BARGRAPH_OFF;   
   Pin6 = BARGRAPH_OFF;   
   Pin7 = BARGRAPH_OFF;   

   // Use a linear scale to display data 
   // Remember: *9* possible output states
   // - do all calculations ONCE
   M9_1_G = (BARGRAPH_MAX - BARGRAPH_MIN) / 9;
   M9_2_G = M9_1_G * 2;
   M9_3_G = M9_1_G * 3;
   M9_4_G = M9_1_G * 4;
   M9_5_G = M9_1_G * 5;
   M9_6_G = M9_1_G * 6;
   M9_7_G = M9_1_G * 7;
   M9_8_G = M9_1_G * 8;
   }

/*------------------------------------------------------------------*-

  BARGRAPH_Update()

  Update the bargraph display.

-*------------------------------------------------------------------*/
void BARGRAPH_Update(void)
   {
   tBargraph Data = Data_G - BARGRAPH_MIN; 

   Pin0 = ((Data >= M9_1_G) == BARGRAPH_ON);
   Pin1 = ((Data >= M9_2_G) == BARGRAPH_ON);
   Pin2 = ((Data >= M9_3_G) == BARGRAPH_ON);
   Pin3 = ((Data >= M9_4_G) == BARGRAPH_ON);
   Pin4 = ((Data >= M9_5_G) == BARGRAPH_ON);
   Pin5 = ((Data >= M9_6_G) == BARGRAPH_ON);
   Pin6 = ((Data >= M9_7_G) == BARGRAPH_ON);
   Pin7 = ((Data >= M9_8_G) == BARGRAPH_ON);
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/

