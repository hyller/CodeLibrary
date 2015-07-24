/*------------------------------------------------------------------*-

   Cloc_Mx4.C (v1.00)

  ------------------------------------------------------------------

   Simple library function for keeping track of elapsed time 
  
   This version for (Mx) LED display


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

#include "Cloc_Mx4.h"

// ------ Public variable declarations -----------------------------

extern tByte LED_Mx4_Data_G[4];
extern tByte code LED_Table_G[20];

// ------ Private variable definitions------------------------------

// Time variables
static tByte Hou_G, Min_G, Sec_G; 

/*------------------------------------------------------------------*-

  CLOCK_LED_Time_Update()

  Updates the global time variables.

  *** Must be scheduled once per second ***

-*------------------------------------------------------------------*/
void CLOCK_LED_Time_Update(void)     
   {
   bit Min_update = 0;
   bit Hou_update = 0;

   if (++Sec_G == 60)  
      { 
      Sec_G = 0;
      Min_update = 1;
      
      if (++Min_G == 60)  
         {
         Min_G = 0;
         Hou_update = 1;
           
         if (++Hou_G == 24)  
            { 
            Hou_G = 0;
            }
         }
      }

   if (Min_update)
      {
      // Need to update the minutes data
      // (both digits)
      LED_Mx4_Data_G[1] = LED_Table_G[Min_G / 10];
      LED_Mx4_Data_G[0] = LED_Table_G[Min_G % 10];
      }

   // We don't display seconds in this version.
   // We simply use the seconds data to turn on and off the decimal
   // point between hours and minutes 
   if ((Sec_G % 2) == 0)
      {
      LED_Mx4_Data_G[2] = LED_Table_G[Hou_G % 10];
      }
   else
      {
      LED_Mx4_Data_G[2] = LED_Table_G[(Hou_G % 10) + 10];
      }
   
   if (Hou_update)
      {
      // Need to update the 'tens of hours' data
      LED_Mx4_Data_G[3] = LED_Table_G[Hou_G / 10];
      }
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
