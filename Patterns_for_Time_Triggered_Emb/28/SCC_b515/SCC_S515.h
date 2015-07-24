/*------------------------------------------------------------------*-
  
  SCC_M515.H (v1.00)

  ------------------------------------------------------------------

  - see SCC_M515.C for details


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"
#include "Sch51.h"

// ------ Public function prototypes -------------------------------

void SCC_A_SLAVE_Init_CAN(void);
void SCC_A_SLAVE_Start(void);

// ------ Public constants -----------------------------------------

#define NUMBER_OF_SLAVES 1

// CAN #defines &c - mainly from Infineon DaVE output 

// Control Register
#define CAN_cr   (*((tByte volatile xdata *) 0xF700))

// Status Register
#define CAN_sr   (*((tByte volatile xdata *) 0xF701))

// Bit Timing Register
#define CAN_btr0 (*((tByte volatile xdata *) 0xF704))
#define CAN_btr1 (*((tByte volatile xdata *) 0xF705))

// Global Mask Short
#define CAN_gms0  (*((tByte volatile xdata *) 0xF706))

// Global Mask Short
#define CAN_gms1  (*((tByte volatile xdata *) 0xF707))

// Upper Global Mask Long
#define CAN_ugml0 (*((tByte volatile xdata *) 0xF708))
#define CAN_ugml1 (*((tByte volatile xdata *) 0xF709))

// Lower Global Mask Long
#define CAN_lgml0 (*((tByte volatile xdata *) 0xF70A))
#define CAN_lgml1 (*((tByte volatile xdata *) 0xF70B))

// ------ Private data type declarations ---------------------------

// Data structure representing a single CAN message
struct sCAN_message 
   {
   tByte MCR0;       // Message Control Register 0
   tByte MCR1;       // Message Control Register 1
   tByte UAR0;       // Upper Arbit. Reg. 0
   tByte UAR1;       // Upper Arbit. Reg. 1
   tByte LAR0;       // Lower Arbit. Reg. 0
   tByte LAR1;       // Lower Arbit. Reg. 1
   tByte MCFG;       // Message Configuration Register
   tByte Data[8];    // Message Data 0 .. 7
   tByte Customer;   // Reserved for application specific data
   };

// ------ Private variables ----------------------------------------

// A total of 15 CAN message structures exist 
// (starting at at address 0xF710)
#define CAN_messages ((struct sCAN_message volatile xdata *) 0xF710)

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/

