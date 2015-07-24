/*------------------------------------------------------------------*-

   Elap_232.C (v1.01)

  ------------------------------------------------------------------

   Simple library function for keeping track of elapsed time 
   Demo version to display time on PC screen via RS232 link.


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"
#include "Elap_232.h"
#include "PC_O.h"

// ------ Public variable definitions ------------------------------

tByte Hou_G = 0;
tByte Min_G = 0;
tByte Sec_G = 0;

// ------ Public variable declarations -----------------------------

// See Char_Map.c
extern const char code CHAR_MAP_G[10]; 

/*------------------------------------------------------------------*-

  Elapsed_Time_RS232_Init()

  Init function for simple library displaying elapsed time on PC
  via RS-232 link.

-*------------------------------------------------------------------*/
void Elapsed_Time_RS232_Init(void)
   {
   char Time_Str[] = "Elapsed time";

   PC_LINK_O_Write_String_To_Buffer(Time_Str);   
   }


/*------------------------------------------------------------------*-

  Elapsed_Time_RS232_Update()

  Function for displaying elapsed time on PC Screen.

  *** Must be scheduled once per second ***

-*------------------------------------------------------------------*/
void Elapsed_Time_RS232_Update(void)     
   {
   char Time_Str[30] = "\rElapsed time:               ";

   if (++Sec_G == 60)  
      { 
      Sec_G = 0;
      
      if (++Min_G == 60)  
         {
         Min_G = 0;
           
         if (++Hou_G == 24)  
            { 
            Hou_G = 0;
            }
         }
      }

   Time_Str[15] = CHAR_MAP_G[Hou_G / 10];
   Time_Str[16] = CHAR_MAP_G[Hou_G % 10];

   Time_Str[18] = CHAR_MAP_G[Min_G / 10];
   Time_Str[19] = CHAR_MAP_G[Min_G % 10];

   Time_Str[21] = CHAR_MAP_G[Sec_G / 10];
   Time_Str[22] = CHAR_MAP_G[Sec_G % 10];
  
   // We don't display seconds in this version.
   // We simply use the seconds data to turn on and off the colon
   // (between hours and minutes) 
   if ((Sec_G % 2) == 0)
      {
      Time_Str[17] = ':';
      Time_Str[20] = ':';
      }
   else
      {
      Time_Str[17] = ' ';
      Time_Str[20] = ' ';
      }

   PC_LINK_O_Write_String_To_Buffer(Time_Str);
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/

