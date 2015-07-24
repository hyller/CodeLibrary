/*------------------------------------------------------------------*-

   Port.H (v1.01)

  ------------------------------------------------------------------

  'Port Header' (see Chap 10) for project PID_moto (see Chap 35)


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
#define Error_port P5

#endif

// ------ PIDmotor.C -----------------------------------------------

// ADC reading from Pin 6.0
// PWM output on Pin 1.1

// Opto-encoder (or similar) connected to this pin
sbit Pulse_count_pin = P3^5;                      

// ------ Lnk_O.C -----------------------------------------------
    
// Pin 3.1 used for RS-232 interface


/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/



