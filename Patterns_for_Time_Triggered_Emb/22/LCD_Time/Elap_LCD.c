/*------------------------------------------------------------------*-

   Elap_LCD.C (v1.00)

  ------------------------------------------------------------------

   Simple library function for keeping track of elapsed time 
   This version for LCD display.


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"
#include "Elap_LCD.h"
#include "LCD_A.h"

// ------ Public variable definitions ------------------------------

tByte Hou_G = 0;
tByte Min_G = 0;
tByte Sec_G = 0;

// ------ Public variable declarations -----------------------------

extern char LCD_data_G[LCD_LINES][LCD_CHARACTERS+1];
extern char code CHAR_MAP_G[10];

extern tByte Hou_G, Min_G;


/*------------------------------------------------------------------*-

  Elapsed_Time_LCD_Init()

  Init function for simple library displaying elapsed time on LCD
  character panel.

-*------------------------------------------------------------------*/
void Elapsed_Time_LCD_Init(void)
   {
   // Set up the initial data to be sent to the LCD
   // ASSUMES 20 CHARACTER DISPLAY
   char* pTime =  "Elapsed :-      ";
   tByte c;
   
   for (c = 0; c < LCD_CHARACTERS; c++)
      {
      LCD_data_G[0][c] = pTime[c];
      
      // For demo purposes only
      if (c % 2)
         {
         LCD_data_G[1][c] = LCD_UDC_DEGREES_C;
         }
      else
         {
         LCD_data_G[1][c] = LCD_UDC_POUNDS;
         }  
      }

   LCD_data_G[0][11] = CHAR_MAP_G[Hou_G / 10];
   LCD_data_G[0][12] = CHAR_MAP_G[Hou_G % 10];
   LCD_data_G[0][14] = CHAR_MAP_G[Min_G / 10];
   LCD_data_G[0][15] = CHAR_MAP_G[Min_G % 10];
   }


/*------------------------------------------------------------------*-

  Elapsed_Time_LCD_Update()

  Function for displaying elapsed time on LCD character panel.

  *** Must be scheduled once per second ***

-*------------------------------------------------------------------*/
void Elapsed_Time_LCD_Update(void)     
   {
   bit Min_update = 0;
   bit Hou_update = 0;

   // Set (for example) to 2 to test - otherwise 60
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

   if (Hou_update)
      {
      // Need to update the 'hours' data
      LCD_data_G[0][11] = CHAR_MAP_G[Hou_G / 10];
      LCD_data_G[0][12] = CHAR_MAP_G[Hou_G % 10];
      Hou_update = 0;
      }

   if (Min_update)
      {
      // Need to update the minutes data
      LCD_data_G[0][14] = CHAR_MAP_G[Min_G / 10];
      LCD_data_G[0][15] = CHAR_MAP_G[Min_G % 10];
      Min_update = 0;
      }
  
   // We don't display seconds in this version.
   // We simply use the seconds data to turn on and off the colon
   // (between hours and minutes) 
   if ((Sec_G % 2) == 0)
      {
      LCD_data_G[0][13] = ' ';
      }
   else
      {
      LCD_data_G[0][13] = ':';
      }
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
