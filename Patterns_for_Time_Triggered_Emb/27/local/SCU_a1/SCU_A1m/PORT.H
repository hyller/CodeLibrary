/*------------------------------------------------------------------*-

   Port.H (v1.00)

  ------------------------------------------------------------------

  'Port Header' (see Chap 10) for the project SCU_Am (see Chap 27)


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
#define Error_port P0

#endif

// ------ SCU_Am.C ------------------------------------------------

// *****************************************************************
// P3.0, 3.1 used for (UART) outputs 
// *****************************************************************

sbit WATCHDOG_pin = P1^7;

// Connect LED from +5V (etc) to these pins, via appropriate resistor
// [see Chapter 7 for details]
sbit Network_error_pin = P2^7;

// ------ TLights_B.C ----------------------------------------------

// Connect LED from +5V (etc) to these pins, via appropriate resistor
sbit Red_light   = (P2^0);
sbit Amber_light = (P2^1);
sbit Green_light = (P2^2);

// ------ LED_Flas.C -----------------------------------------------

// Connect LED from +5V (etc) to this pin, via appropriate resistor
sbit LED_pin = P2^3;

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/