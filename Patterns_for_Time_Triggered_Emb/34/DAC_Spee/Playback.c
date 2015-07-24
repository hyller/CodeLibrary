/*------------------------------------------------------------------*-

   Playback.C (v1.00)

  ------------------------------------------------------------------
   
   Library of functions to allow playback of stored speech sample
   from on-chip ROM.

   Assumes presence of AD7248A DAC: see text for hardware details.

   Play back continuously while switch is depressed.

   Data are replayed at 10 kHz, 12-bit resolution.


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"
#include "Port.h"

#include "Playback.h"

// ------ Public constants -----------------------------------------

// The speech data we are going to play
extern const tWord code BA_12_BIT_10KHZ_G[3500];

// ------ Public variable declarations -----------------------------

extern bit Sw_pressed_G;

// ------ Public variable definitions ------------------------------

bit SPEECH_PLAYBACK_Playing_G = 0;

// ------ Private variables ----------------------------------------

static bit LED_state_G;

// ------ Private constants ----------------------------------------

#define T_100micros (65536 - (tWord)((OSC_FREQ / 13000)/(OSC_PER_INST)))    
#define T_100micros_H (T_100micros / 256)
#define T_100micros_L (T_100micros % 256)

/*------------------------------------------------------------------*-

  SPEECH_PLAYBACK_Update()

  The main update function for the playback software.

  This will usually be scheduled, as required, as a one-shot 
  (co-operative) task.

  Task duration is approximately 350 milliseconds. 
  
  User can abort at any time by releasing the switch.

-*------------------------------------------------------------------*/
void SPEECH_PLAYBACK_Update(void)
   {
   int Sample;

   SPEECH_PLAYBACK_Playing_G = 0;

   // Configure Timer 0 as a 16-bit timer 
   TMOD &= 0xF0; // Clear all T0 bits (T1 left unchanged)
   TMOD |= 0x01; // Set required T0 bits (T1 left unchanged) 
   ET0 = 0;  // No interrupts

   // Playback at ~ 10 kHz
   for (Sample = 0; Sample < 3500; Sample++)
      {
      // Avoid multiple calls to this function
      SPEECH_PLAYBACK_Playing_G = 1;

      // Play a sample
      SPEECH_PLAYBACK_Play_Sample(BA_12_BIT_10KHZ_G[Sample]);

      // Delay ~0.1 ms (to give 10 kHz sample rate)            
      TR0 = 0;  
      TH0 = T_100micros_H; 
      TL0 = T_100micros_L;
      TF0 = 0; // Clear flag
      TR0 = 1; // Start timer
      while (!TF0);
      TR0 = 0;  

      if (!Sw_pressed_G)
         {
         break; // Abort loop if user releases switch
         }
      }

   // Set flag to 0 as we leave this function
   SPEECH_PLAYBACK_Playing_G = 0;
   }

/*------------------------------------------------------------------*-

  SPEECH_PLAYBACK_Play_Sample()

  Send 12-bit data sample to AD7248A ADC. 

-*------------------------------------------------------------------*/
void SPEECH_PLAYBACK_Play_Sample(const tWord SAMPLE)
   {
   // Samples are 12-bits, in 16-bit (tWord) value

   // Send lower 8 bits first
   tByte Data_8bit = (tByte) (SAMPLE & 0x00FF);

   SPEECH_Port = Data_8bit;
   SPEECH_CSLSB_pin = 0;
   SPEECH_CSMSB_pin = 1; 

   // Now the upper 4 bits
   Data_8bit = (tByte) ((SAMPLE >> 8) & (0x0F));

   SPEECH_Port = Data_8bit;
   SPEECH_CSLSB_pin = 1;
   SPEECH_CSMSB_pin = 0; 
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
