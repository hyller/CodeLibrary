/*------------------------------------------------------------------*-

   LCD_A.h (v1.01)

  ------------------------------------------------------------------

   - See LCD_A.c for details.
 

   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

// ------ Public function prototypes -------------------------------

void LCD_Init(const bit);

void LCD_Update(void);

// Controls display of cursor and / or blinking at spec. address
void LCD_Control_Cursor(const bit, const bit, const tByte);

void LCD_Create_Character(const tByte, const tByte* const);


// ------ Public constants -----------------------------------------

// 2 x 20 display here
#define LCD_LINES 2
#define LCD_CHARACTERS 20

// User-defined characters
#define LCD_UDC_POUNDS 1
#define LCD_UDC_DEGREES_C 2 

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/



