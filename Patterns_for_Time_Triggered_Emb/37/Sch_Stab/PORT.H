/*------------------------------------------------------------------*-

   Port.H (v1.00)

  ------------------------------------------------------------------

  'Port Header' (see Chap 10) for project SCH_STAB (see Chap 38)


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

// ------ Sch51.C --------------------------------------------------

// Comment this line out if error reporting is NOT required
#define SCH_REPORT_ERRORS

#ifdef SCH_REPORT_ERRORS
// The port on which error codes will be displayed
// ONLY USED IF ERRORS ARE REPORTED
#define Error_port P2

#endif

// ------ I2C_CORE.C -----------------------------------------------

// The two-wire I2C bus
sbit I2C_SCL = P1^7;
sbit I2C_SDA = P1^6;


// ------ LED_MX4.C ------------------------------------------------

// LED connection requires 12 port pins
#define LED_DATA_PORT (P2)

/* Connections to LED_DATA_PORT - See Figure 21.6 for details

     DP   G    F    E    D    C    B    A    =   LED display pins
     |    |    |    |    |    |    |    |
    x.7  x.6  x.5  x.4  x.3  x.2  x.1  x.0   =   Port pins

    x.7 == LED_DATA_PORT^7, etc

   LED codes (NB - positive logic assumed here)

   0  = abcdef  => 00111111 = 0x3F
   1  = bc      => 00000110 = 0x06
   2  = abdeg   => 01011011 = 0x5B
   3  = abcdg   => 01001111 = 0x4F
   4  = bcfg    => 01100110 = 0x66
   5  = acdfg   => 01101101 = 0x6D
   6  = acdefg  => 01111101 = 0x7D
   7  = abc     => 00000111 = 0x07
   8  = abcdefg => 01111111 = 0x7F
   9  = abcdfg  => 01101111 = 0x6F

   To display decimal point, add 10 (decimal) to the above values  */

// Any combination of (4) pins on any ports may be used here
sbit LED_DIGIT_0 = P3^3;
sbit LED_DIGIT_1 = P3^4;
sbit LED_DIGIT_2 = P3^5;
sbit LED_DIGIT_3 = P3^6;


/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/



