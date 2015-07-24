/*------------------------------------------------------------------*-

   Main.c (v1.00)

  ------------------------------------------------------------------

   Automatic light example.


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"

// ------ Port pins ------------------------------------------------

// Omit Port.H in this simple (one-file) example
// Don’t use pins 1^0, 1^1 - NO INTERNAL PULL-UP RESISTORS
sbit Switch_pin_G = P1^2;
sbit Light_pin_G  = P1^3;

// ------ Private function prototypes ------------------------------

// Function prototypes
// NOTE: ISR is not explictly called and does not require a prototype
void Timer_1_Init(void);
void Timer_1_Manual_Reload(void);
void Light_Init(void);

// ------ Private constants ----------------------------------------

#define SWITCH_PRESSED 0

#define LIGHT_ON  0
#define LIGHT_OFF 1

// ------ Private variable definitions------------------------------

static tByte Switch_count_G = 0;
static tByte Auto_switch_off_count_G = 0;
static tByte Switch_blocked_G = 0;

static bit LED_state_G = 0;
static tByte Call_count_G = 0;

/* --------------------------------------------------------------- */

void main(void)
   {
   Timer_1_Init();   // Set up Timer 2
   Light_Init();     // Prepare to flash the LED

   EA = 1;           // Globally enable interrupts
   
   while(1)
      {
      PCON |= 0x01;  // Go to sleep (idle mode)
      }
   }

/* --------------------------------------------------------------- */

void Timer_1_Init(void)
   {
   // Timer 1 is configured as a 16-bit timer,
   // which is manually reloaded when it overflows
   TMOD &= 0x0F; // Clear all T1 bits (T0 left unchanged)
   TMOD |= 0x10; // Set required T1 bits (T0 left unchanged) 

   // Sets up timer reload values
   Timer_1_Manual_Reload();

   //  Interrupt Timer 1 enabled
   ET1  = 1;
   }

/*------------------------------------------------------------------*-

  Timer_1_Manual_Reload()

  This 'One-Year Scheduler' uses a (manually reloaded) 16-bit timer.
  The manual reload means that all timings are approximate. 
  THIS SCHEDULER IS NOT SUITABLE FOR APPLICATIONS WHERE
  ACCURATE TIMING IS REQUIRED!!!
  Timer reload is carried out in this function. 

-*------------------------------------------------------------------*/
void Timer_1_Manual_Reload(void)
   {
   // Stop Timer 1
   TR1 = 0;

   // This code (generic 8051/52) assumes a 4 MHz system osc.  
   // The Timer 1 resolution is then 0.000003 seconds
   // (see Chapter 11 for details)
   //
   // We want to generate an interrupt every 200 ms (approx):
   // this takes 0.2 / 0.000003 timer increments
   // i.e. 66666 timer increments 
   //
   // Reload value of 0x00 gives 65536 increments, which is 
   // sufficiently close for our purposes here (around 2% out)
   TL1  = 0x00;
   TH1  = 0x00;

   //  Start Timer 1
   TR1  = 1;
   }

/*------------------------------------------------------------------*-

  Light_Init()

-*------------------------------------------------------------------*/
void Light_Init(void)
   {
   Switch_count_G = 0;
   Auto_switch_off_count_G = 0;
   Switch_blocked_G = 0;

   // Write 1 to switch pin (to set it up for reading)
   Switch_pin_G = 1;
   }

/*------------------------------------------------------------------*-

 Check_Switch()

-*------------------------------------------------------------------*/
void Check_Switch(void) interrupt INTERRUPT_Timer_1_Overflow
   {
   // This function is an implementation of the pattern On-Off Switch 

   // If the light is on, 'Auto_switch_off_count' will be > 0 
   // Decrement here - and switch the light off when it reaches zero. 
   if (Auto_switch_off_count_G > 0)
      {
      Auto_switch_off_count_G--;

      if (Auto_switch_off_count_G == 0)
         {
         Light_pin_G = LIGHT_OFF;
         }
      }

   // The switch is 'blocked' after each switch press,
   // to give the user time to remove their finger: 
   // If this is not done, the light will switch off again
   // when the user presses the switch for more than 0.4 seconds.
   //
   // If the switch is blocked, decrement the block count and return
   // without checking the switch pin status.
   if (Switch_blocked_G > 0)
      {
      Switch_blocked_G--;
      return;
      }

   // Now read switch pin
   if (Switch_pin_G == SWITCH_PRESSED)
      {
      // If the switch pin is pressed, increment the switch count.  
      if (++Switch_count_G == 2)
         {
         // If Switch_count_G == 2, this means that the pin has been active 
         // for two consecutive calls to this task, i.e. it is a
         // genuine switch press rather than a bounce.

         // The variable Auto_switch_off_count_G acts both as 
         // an indication the light is on (if it is non-zero) 
         // and a counter of the number of task calls the 
         // light will remain on for.
         if (Auto_switch_off_count_G > 0)
            {
            // The light is currently ON 
            // -> switch it off.
            Light_pin_G = LIGHT_OFF;
            Auto_switch_off_count_G = 0;
            }
         else
            {
            // The light is currently OFF
            // -> switch it on and set the counter to 150 
            // (task is called every 0.2s so this gives 30 seconds delay).
            Light_pin_G = LIGHT_ON;
            Auto_switch_off_count_G = 150;
            }
          
         // Reset the switch count, and block the switch for the next 
         // second (5 calls to this task).
         Switch_count_G   = 0;
         Switch_blocked_G = 5; 
         }
      }
   else
      {
      Switch_count_G = 0;
      }  
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
