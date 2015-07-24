/*------------------------------------------------------------------*-

   Port.H (v1.00)

  ------------------------------------------------------------------

  'Port Header' (see Chap 10) for project I2C_ROM (see Chap 23)


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

// ------ I2C_Core.C -----------------------------------------------

// The two-wire I2C bus
sbit I2C_SCL = P1^7;
sbit I2C_SDA = P1^6;

/* Hardware connections for AT24C64 EEPROM
   ---------------------------------------

   The SDA and SCL pins make up one end of the I2C bus
   These pins need to be connected to the 24C64 memory chip.  

   Note that, while the bus requires pull-up resistors on 
   both SDA and SCL lines (around 3-5K),
   these may not be necessary if your port has on-chip 
   pull-up resistors.
 
   Note that the 80C552 / 80C652 etc bring out 
   SCL on Pin 1.6 and
   SDA on Pin 1.7 - using these pins gives a degree of portability 

   NOTE: This code does not use the 'write protect' option
   If left unconnected, the Write Protect pin on the chip will
   be internally pulled to ground - gives no write protection  */


/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/



