/*------------------------------------------------------------------*-

   PRM_Hard.C (v1.00)

  ------------------------------------------------------------------

   Simple library demonstrating hardware (T2) pulse-rate modulation.

   See Chapter 31 for details.


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"

// ------ Public variable definitions ------------------------------

tWord PRM_reload_G = 0;

/*------------------------------------------------------------------*-

  PRM_Hardware_Init()

  Start PRM.

-*------------------------------------------------------------------*/
void PRM_Hardware_Init(void)
   {
   T2CON &= 0xFD;   // Clear *only* C /T2 bit
   T2MOD |= 0x02;   // Set T2OE bit  (omit in basic 8052 clone)
  
   // Start at lowest frequency (~45Hz with 12MHz xtal)
   TL2     = 0x00;   // Timer 2 low byte
   TH2     = 0x00;   // Timer 2 high byte
   RCAP2L  = 0x00;   // Timer 2 reload capture register, low byte
   RCAP2H  = 0x00;   // Timer 2 reload capture register, high byte

   ET2   = 0; // No interrupt.

   TR2   = 1; // Start timer 2
   }


/*------------------------------------------------------------------*-

  PRM_Hardware_Update()

  Call this function only when you need to change the pulse rate. 

  See text for details of resulting PRM frequency.

-*------------------------------------------------------------------*/
void PRM_Hardware_Update(void)
   {
   TR2 = 0;

   TL2    = PRM_reload_G % 256;
   RCAP2L = TL2;
   TH2    = PRM_reload_G / 256;
   RCAP2H = TH2;
  
   TR2 = 1;
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/