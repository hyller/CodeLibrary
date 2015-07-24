/*------------------------------------------------------------------*-

   Port.H (v1.00)

  ------------------------------------------------------------------

  'Port Header' (see Chap 10) for the project SCI_Ti2s (see Chap 26)


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


// ------ SCI_Ti2s.C -------------------------------------------------

// P3^3 used for interrupt input

// Connect 1232 (pin /ST) to the WATCHDOG_pin
sbit WATCHDOG_pin = P3^2;


// ------ TLight_A.C ----------------------------------------------

sbit Red_light   = (P2^0);
sbit Amber_light = (P2^1);
sbit Green_light = (P2^2);

// ------ LED_Flas.C -----------------------------------------------

// For flashing LED
sbit LED_pin = P2^7;


/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
