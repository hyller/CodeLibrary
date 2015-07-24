/*------------------------------------------------------------------*-

   Port.H (v1.00)

  ------------------------------------------------------------------

  'Port Header' (see Chap 10) for project SCC_b515 (see Chap 28)


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
//#define SCH_REPORT_ERRORS

#ifdef SCH_REPORT_ERRORS
// The port on which error codes will be displayed
// ONLY USED IF ERRORS ARE REPORTED
#define Error_port P1

#endif

// ------ SCC_M.C ------------------------------------------------

// *****************************************************************
// P4.6, 4.7 used for CAN outputs 
// *****************************************************************

// Connect LED from +5V (etc) to these pins, via appropriate resistor
sbit Network_error_pin = P4^4;

// Three pins used to report CAN bus errors
sbit CAN_error_pin0 = P5^3;
sbit CAN_error_pin1 = P5^4;
sbit CAN_error_pin2 = P5^5;


// ------ TLights_B.C ----------------------------------------------

sbit Red_light   = (P4^0);
sbit Amber_light = (P4^1);
sbit Green_light = (P4^2);


// ------ LED_Flas.C -----------------------------------------------

// Connect LED from +5V (etc) to this pin, via appropriate resistor
// [see Chapter 7 for details]
sbit LED_pin = P4^3;


/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/



