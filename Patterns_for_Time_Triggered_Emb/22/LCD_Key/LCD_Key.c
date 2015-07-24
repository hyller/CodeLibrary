/*------------------------------------------------------------------*-

   LCD_Key.C (v1.00)

  ------------------------------------------------------------------

   Simple demonstration function for transferring keypad inputs 
   to an LCD display. 


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"
#include "Keypad.h"
#include "LCD_Key.h"
#include "LCD_A.h"

// ------ Private variables ----------------------------------------

static tByte Char_G;

// ------ Public variable declarations -----------------------------

extern char LCD_data_G[LCD_LINES][LCD_CHARACTERS+1];

/*------------------------------------------------------------------*-

  LCD_KEY_Init()

  Init function for simple keypad - LCD library.

-*------------------------------------------------------------------*/
void LCD_KEY_Init(void)
   {
   tByte c;
   char* pPrompt = "Type on the keypad:      ";

   // Clear the keypad buffer
   KEYPAD_Clear_Buffer();
   
   // Prepare the display
   for (c = 0; c < LCD_CHARACTERS; c++)
       {
       LCD_data_G[0][c] = pPrompt[c];
       LCD_data_G[1][c] = '*';
       }

   Char_G = 0;
   }


/*------------------------------------------------------------------*-

  LCD_KEY_Update()

  Function for displaying keypad inputs on LCD display.

-*------------------------------------------------------------------*/
void LCD_KEY_Update(void)     
   {
   char Key, FnKey;

   KEYPAD_Update();
   
   if (KEYPAD_Get_Data_From_Buffer(&Key, &FnKey) == 0)
      {
      // Buffer is empty
      return;
      }

   // Function key has been pressed (with another key)
   if (FnKey)
      {
      LCD_data_G[1][Char_G] = FnKey;

      if (++Char_G == LCD_CHARACTERS) 
         {
         Char_G = 0;
         }
      } 

   LCD_data_G[1][Char_G] = Key;
      
   if (++Char_G == LCD_CHARACTERS) 
      {
      Char_G = 0;
      }
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/ 
