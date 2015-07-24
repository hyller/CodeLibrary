/*------------------------------------------------------------------*-

   Port.H (v1.00)

  ------------------------------------------------------------------

  'Port Header' (see Chap 10) for the project SCI_DM (Chap 26)


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
#define Error_port P3

#endif

// ------ SCI_DM.C -------------------------------------------------

// This pin is wired to the interrupt input pin
// (usually Pin3.2) of the slave microcontroller
sbit Interrupt_output_pin = P2^7;

// This pin is wired to the 'watchdog' pin on the slave
sbit Slave_watchdog_pin = P2^6;

// This port is used to transfer data to / from the slave
#define SCI_transfer_port P0


// ------ TLight_B.C ----------------------------------------------

sbit Red_light   = (P2^0);
sbit Amber_light = (P2^1);
sbit Green_light = (P2^2);


// ------ LED_Flas.C -----------------------------------------------

// For flashing LED
sbit LED_pin = P1^0;


/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/



