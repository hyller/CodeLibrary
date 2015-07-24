/*------------------------------------------------------------------*-

   Port.H (v1.00)

  ------------------------------------------------------------------

  'Port Header' (see Chap 10) for project LCD_TIME (see Chap 22)


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

// ------ Sch51.C ----------------------------------------

// Comment this line out if error reporting is NOT required
#define SCH_REPORT_ERRORS

#ifdef SCH_REPORT_ERRORS
// The port on which error codes will be displayed
// ONLY USED IF ERRORS ARE REPORTED
#define Error_port P1

#endif

// ------ LCD_A.c --------------------------------------------------

// NOTE: Any combination of 6 pins may be used (any ports, any order)
// NOTE: Number in [] are pin numbers on *MANY* LCDs  

sbit LCD_D4 = P3^2; // DB4 [11]
sbit LCD_D5 = P3^3; // DB5 [12]
sbit LCD_D6 = P3^4; // DB6 [13]
sbit LCD_D7 = P3^5; // DB7 [14]

sbit LCD_RS = P3^6; // Display register select output [4]
sbit LCD_EN = P3^7; // Display enable output [6]

// Connect Vss [1] on LCD to Gnd
// Connect Vcc [2] on LCD to +5V
// Connect Vo  [3] on LCD to Gnd
// Connect RW  [5] on LCD to Gnd


/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/



