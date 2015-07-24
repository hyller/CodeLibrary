/*------------------------------------------------------------------*-

   PWM_515c.c (v1.00)

  ------------------------------------------------------------------

   Rudimentary PWM library for 80c515c.
   
   Created with help from DaVE.

   Uses T2 / Capture / Compare unit.


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.
 
-*------------------------------------------------------------------*/


#include "Main.h"
#include "PWM_515c.h"

/*------------------------------------------------------------------*-

  PWM_Init_T2()

  Prepare on-chip PWM unit on the c515c.

-*------------------------------------------------------------------*/
void PWM_Init_T2(void)
   {
   // ---------- T2 Mode ---------------------------
   // Mode 1 = Timerfunction

   // Prescaler: Fcpu/6

   // ---------- T2 reload mode selection ----------
   // Mode 0 = auto-reload upon timer overflow
   // Preset the timer register with autoreload value ! 0x0000;
   TL2 = 0x00;
   TH2 = 0xFF;
  
   // ---------- T2 general compare mode ----------
   //  Mode 0 for all channels
   T2CON |= 0x11;

   // ---------- T2 general interrupts ------------
   //  timer 2 overflow interrupt is disabled
   ET2=0;
   //  timer 2 external reload interrupt is disabled
   EXEN2=0;

   // ---------- Compare/capture Channel 0 ---------
   // disabled
   // Set Compare Register CRC on: 0xFF00;
   CRCL = 0x00;
   CRCH = 0xFF;
  
   //  CC0/ext3 interrupt is disabled
   EX3=0;
  
   // ---------- Compare/capture Channel 1 ---------
   // Compare enabled
   // Set Compare Register CC1 on: 0xFF80;
   CCL1 = 0x80;
   CCH1 = 0xFF;
  
   //  CC1/ext4 interrupt is disabled
   EX4=0;
  
   // ---------- Compare/capture Channel 2 ---------
   // disabled
   // Set Compare Register CC2 on: 0x0000;
   CCL2 = 0x00;
   CCH2 = 0x00;
   //  CC2/ext5 interrupt is disabled
   EX5=0;
  
   // ---------- Compare/capture Channel 3 ---------
   // disabled
   // Set Compare Register CC3 on: 0x0000;
   CCL3 = 0x000;
   CCH3 = 0x000;
  
   // CC3/ext6 interrupt is disabled
   EX6=0;
  
   // Set all above mentioned modes for channel 0-3 
   CCEN = 0x08;
   }

/*------------------------------------------------------------------*-

  PWM_Update_T2()

  Update the PWM output value (capture/compare Channel 1)

  Output is on Pin 1.1.

  NOTE: Hardware will continue to produce this value (indefinitely), 
  without software intervention, until the next update.

-*------------------------------------------------------------------*/
void PWM_Update_T2(const tByte New_PWM_value)
   {
   CCL1 = New_PWM_value;
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
