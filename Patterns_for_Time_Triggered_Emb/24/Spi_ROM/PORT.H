/*------------------------------------------------------------------*-

   Port.H (v1.00)

  ------------------------------------------------------------------

   'Port Header' (see Chap 10) for project SPI_ROM (see Chap 24)


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
#define Error_port P2

#endif

// ------ SPI_Core.C -----------------------------------------------

// Create sbits for all required chip selects here
sbit SPI_CS = P1^4;  

// NOTE: pins P1.4, P1.5, P1.6 and P1.7 also used - see text

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/



