/*------------------------------------------------------------------*-

   LCD_A.C (v1.01)
 
  ------------------------------------------------------------------

   LCD LIBRARY CODE 

   Designed for scheduled operation, 
   in this case for a 2-line x 20-character display 

   '4-BIT' INTERFACE (uses 6 pins) to standard HD44780-based LCD

 
   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

// Hardware resources: 
// Uses T0 (for delays) plus six I/O pins

#include "Main.h"
#include "Port.h"

#include "LCD_A.h"
#include "Delay_T0.h"


// ------ Public variable definitions ------------------------------

// The LCD data
char LCD_data_G[LCD_LINES][LCD_CHARACTERS+1] 
     = {" PLEASE WAIT        "," ...                "};

// ------ Private function prototypes ------------------------------

static void LCD_Send_Byte(const tByte, const bit) ;
static void LCD_Create_Character(const tByte, const tByte* const);

static void LCD_SetDDRAM(tByte);  
static void LCD_Delay(void);

// ------ Private constants ----------------------------------------

// Bitmaps for user-defined characters [for demonstration purposes]

// This is a UK Pound (currency) sign
// 765 43210
// ... ...11 - 3 (Decimal)
// ... ..1.. - 4 
// ... .111. - 14 
// ... ..1.. - 4 
// ... ..1.. - 4 
// ... ..1.. - 4 
// ... 11111 - 31 
// ... ..... - 0 
const tByte LCD_UDC_Pounds[8] = {3,4,14,4,4,31,0};
// #define LCD_UDC_POUNDS 1 (See LCD_A.H)

// This is 'Degrees Celsius' (as in temp. of boiling water = 100oC)
// 765 43210
// ... .11.. = 12 (Decimal)
// ... 1..1. = 18
// ... .11.. = 12
// ... ...11 = 3
// ... ..1.. = 4
// ... ..1.. = 4
// ... ...11 = 3  
// ... ..... - 0 
const tByte LCD_UDC_Degrees_C[8] = {12,18,12,3,4,4,3,0};
// #define LCD_UDC_DEGREES_C 2 (See LCD_A.H)

#define LCD_DISPLAY_OFF_CURSOR_OFF_BLINKING_OFF 0x08
#define LCD_DISPLAY_ON_CURSOR_OFF_BLINKING_OFF 0x0C

#define LCD_INC_ADDR_NO_SCROLL 0x06
#define LCD_CURSOR_OFF 0x08
#define LCD_DISPLAY_ON 0x04
#define LCD_CLEAR_DISPLAY 0x01
#define LCD_8BIT_2LINE_5x8FONT 0x38  // 0011 1000 
#define LCD_4BIT_2LINE_5x8FONT 0x28  // 0010 1000

// Define Timer 0 / Timer 1 reload values for ~50 us delay
#define PRELOAD50micros  (65536 - (tWord)((OSC_FREQ / 20000)/(OSC_PER_INST)))    
#define PRELOAD50microsH (PRELOAD50micros / 256)
#define PRELOAD50microsL (PRELOAD50micros % 256)

/*------------------------------------------------------------------*-

 LCD_Init()

 RATHER SLOW, BUT MANAGES TO INITIALISE ALL TESTED DISPLAYS 
 (and is only called at the start of the program)

 NOTE: I suggest you call this function THREE TIMES.

 Set TURN_DISPLAY_ON to '1' last time function is called.

-*------------------------------------------------------------------*/
void LCD_Init(const bit TURN_DISPLAY_ON)
   {
   tByte loop;
   tByte l,c;

   Hardware_Delay_T0(10);  

   // Set up the LCD port
   LCD_D4 = 1;
   LCD_D5 = 1;
   LCD_D6 = 1;
   LCD_D7 = 1;

   LCD_RS = 1;
   LCD_EN = 1;    

   Hardware_Delay_T0(10);  

   LCD_RS = 0;
   LCD_EN = 0;    

   // Now wait for the display to initialise
   // - data sheet says at least 40 ms
   Hardware_Delay_T0(100);

   // Data sheet says send this instruction 3 times...
   for (loop = 0; loop < 3; loop++)
      {
      // Using a 4-bit bus, 2 display lines and a 5x7 dot font
      LCD_Send_Byte(LCD_4BIT_2LINE_5x8FONT,0);  
      Hardware_Delay_T0(1);
      }
   
   // Turn the display off and the cursor off and blinking off
   LCD_Send_Byte(LCD_DISPLAY_OFF_CURSOR_OFF_BLINKING_OFF,0); 
   Hardware_Delay_T0(1);
   
   // Clear the display
   LCD_Send_Byte(LCD_CLEAR_DISPLAY,0); 
   Hardware_Delay_T0(1);

   // Invisible cursor (dummy function call to avoid library error)
   LCD_Control_Cursor(0,0,0);
   Hardware_Delay_T0(1);

   // Clear the display
   LCD_Send_Byte(LCD_CLEAR_DISPLAY,0); 
   Hardware_Delay_T0(1);

   if (TURN_DISPLAY_ON)
      {
      // Increment display address for each character but do not scroll
      LCD_Send_Byte(LCD_INC_ADDR_NO_SCROLL,0); 
      Hardware_Delay_T0(1);

      // Update all characters in the display
      for (l = 0; l < LCD_LINES; l++)
          {
          for (c = 0; c < LCD_CHARACTERS; c++)
              {
              LCD_data_G[l][c] = ' ';
              LCD_Update();
              Hardware_Delay_T0(1);
              } 
          }

      // Set up user-defined character(s) - if required
      LCD_Create_Character(LCD_UDC_DEGREES_C, LCD_UDC_Degrees_C);
      Hardware_Delay_T0(1);

      LCD_Create_Character(LCD_UDC_POUNDS, LCD_UDC_Pounds);
      Hardware_Delay_T0(1); 

      // Turn the display on and the cursor off and blinking off
      LCD_Send_Byte(LCD_DISPLAY_ON_CURSOR_OFF_BLINKING_OFF,0); 
      Hardware_Delay_T0(1);
      }      
   }


/*------------------------------------------------------------------*-

 LCD_Update()

 This function updates one character in the LCD panel
 (if it requires updating).
 
 Duration: ~0.1 ms.

 Schedule roughly every 25 ms (2-line x 20-char display) to
 force one complete display update every second.

-*------------------------------------------------------------------*/
void LCD_Update(void) 
   {
   static tByte Line;
   static tByte Character;

   tByte Tests, Data;
   bit Update_required;

   // Find next character to be updated
   Tests = LCD_CHARACTERS * LCD_LINES;
   do {
      if (++Character == LCD_CHARACTERS)
         {
         Character = 0;

         if (++Line == LCD_LINES)
            {
            Line = 0;
            }
         }

      // Array contents set to \0 after data is written to LCD 
      Update_required = (LCD_data_G[Line][Character] != '\0');
      } while ((Tests-- > 0) && (!Update_required));

   if (!Update_required)
      {
      return;  // No data in LCD requires updating
      }

  // Set DDRAM address which character is to be written to
  // - Assumes 2 line display (or 16x1)
  // - See text for adjustments needed for other display sizes
  if (Line == 0)
      {
      LCD_SetDDRAM(0x00 + Character);  // First line
      }
   else
      {
      LCD_SetDDRAM(0x40 + Character);  // Second line
      }

   // This is the data for updating
   Data = LCD_data_G[Line][Character];

   // New
   LCD_Send_Byte(Data,1);

   // Once data has been written to LCD
   LCD_data_G[Line][Character] = '\0';  
   }

/*------------------------------------------------------------------*-

 LCD_Send_Byte()

 This function writes a byte to the LCD panel.
 
 Duration < 0.1 ms .

 Parameters: Data
               The byte to be written to the display.

             DATA_FLAG:
               If DATA_FLAG == 1, a data byte is sent
               If DATA_FLAG == 0, a command byte is sent


-*------------------------------------------------------------------*/
void LCD_Send_Byte(const tByte DATA, const bit DATA_FLAG) 
   {
   // Delays *are* needed
   // [you may find it possible to reduce them on
   // on some displays]
   LCD_D4 = 0;
   LCD_D5 = 0;
   LCD_D6 = 0;
   LCD_D7 = 0;
   LCD_RS = DATA_FLAG; // Data register
   LCD_EN = 0;
   LCD_Delay();

   // Write the data (high nybble)
   LCD_D4 = ((DATA & 0x10) == 0x10);
   LCD_D5 = ((DATA & 0x20) == 0x20);
   LCD_D6 = ((DATA & 0x40) == 0x40);
   LCD_D7 = ((DATA & 0x80) == 0x80); 

   LCD_Delay();
   LCD_EN = 1; // Latch the high nybble
   LCD_Delay();
   LCD_EN = 0;
   LCD_Delay();
   LCD_D4 = 0;
   LCD_D5 = 0;
   LCD_D6 = 0;
   LCD_D7 = 0;
   LCD_RS = DATA_FLAG;
   LCD_EN = 0;
   LCD_Delay();

   // Write the data (low nybble)
   LCD_D4 = ((DATA & 0x01) == 0x01);
   LCD_D5 = ((DATA & 0x02) == 0x02);
   LCD_D6 = ((DATA & 0x04) == 0x04);
   LCD_D7 = ((DATA & 0x08) == 0x08);

   LCD_Delay();
   LCD_EN = 1; // Latch the low nybble
   LCD_Delay();
   LCD_EN = 0;
   LCD_Delay();   
   } 


/*------------------------------------------------------------------*-

  LCD_Control_Cursor()

  This function enables or clears the cursor and moves
  it to a specified point.

  Params:  Visible  - Set if the cursor should be visible.
           Blinking - Set if character should be blinking
           Address  - Address (DDRAM) we want to adjust.

-*------------------------------------------------------------------*/ 
void LCD_Control_Cursor(const bit VISIBLE, const bit BLINKING, 
                        const tByte ADDRESS) 
   {
   // Cursor / blinking appears at current DDRAM address 
   // - use SetDDRAM() to alter the cursor position
   tByte Command = 0x0C;  

   if (VISIBLE) 
      {
      Command |= 0x02;
      }

   if (BLINKING) 
      {
      Command |= 0x01;
      }

   LCD_Send_Byte(Command,0);
   LCD_SetDDRAM(ADDRESS);
   }

/*------------------------------------------------------------------*-

 LCD_SetDDRAM()

 Set the DDRAM to a particular address.

 Used to determine where we write to in the LCD RAM and - thus -
 whether the text appears on Line 0, Line 1, etc.

 See text for details.

 Params: The DDRAM address we wish to write to. 

-*------------------------------------------------------------------*/
void LCD_SetDDRAM(tByte ADDRESS)
   {
   ADDRESS &= 0x7f;
   ADDRESS |= 0x80;
   LCD_Send_Byte(ADDRESS,0);
   }


/*------------------------------------------------------------------*-

  LCD_SetCGRAM

  Set the CGRAM to a particular address.

  Used to determine where we write to in the LCD RAM

  See text for details.

  Params: The CGRAM address we wish to write to

-*------------------------------------------------------------------*/
void LCD_SetCGRAM(tByte Address)
   {
   Address &= 0x3f;
   Address |= 0x40;
   LCD_Send_Byte(Address,0);
   }


/*------------------------------------------------------------------*-

  LCD_Create_Character()

  Stores a user-defined character in the CG RAM. Up to 8 characters
  may be stored in this way.  Note: characters are assumed to be 
  5x8 in size: if you need 5x11 characters you will need to adapt
  this code.

  Parameters: The character data (see start of file) 

-*------------------------------------------------------------------*/
void LCD_Create_Character(const tByte UDC_ID, 
                          const tByte* const pUDC_PAT)
   {
   tByte Row;  

   LCD_SetCGRAM(UDC_ID << 3);
   
   // Now write the data 
   for (Row = 0; Row < 8; Row++)
      { 
      LCD_Send_Byte(pUDC_PAT[Row], 1);
      }
   

   // Make sure we next write to DD RAM
   LCD_SetDDRAM(0x00);
   }                                       


/*------------------------------------------------------------------*-

  LCD_Delay()

  This function provides a short delay for the LCD library.

-*------------------------------------------------------------------*/
void LCD_Delay(void)   
   {
   int x;

   x++;
   x++;
   x++;
   }        

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/


