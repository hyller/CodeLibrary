/*------------------------------------------------------------------*-

   Main.c (v1.00)

  ------------------------------------------------------------------

   One-task scheduler demonstration program
 
   - See Chapter 36 for details.


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.H"
#include "Port.H"

#define INTERRUPT_Timer_2_Overflow 5

// Global variable
static tByte LED_state_G;

// Function prototypes
// NOTE: ISR is not explictly called and does not require a prototype
void Timer_2_Init(void);
void LED_Flash_Init(void);
void Go_To_Sleep(void);

/* --------------------------------------------------------------- */

void main(void)
   {
   Timer_2_Init();    // Set up Timer 2

   LED_Flash_Init();  // Prepare to flash LED

   EA = 1;            // Globally enable interrupts
   
   while(1)           // Super Loop
      {
      Go_To_Sleep();  // Enter idle mode to save power
      }
   }

/* --------------------------------------------------------------- */

void Timer_2_Init(void)
   {
   // Timer 2 is configured as a 16-bit timer,
   // which is automatically reloaded when it overflows
   //
   // This code (generic 8051/52) assumes a 12 MHz system osc.  
   // The Timer 2 resolution is then 1.000 µs
   // (see Chapter 11 for details)
   //
   // Reload value is FC18 (hex) = 64536 (decimal)
   // Timer (16-bit) overflows when it reaches 65536 (decimal)
   // Thus, with these setting, timer will overflow every 1 ms
   T2CON   = 0x04;   // Load Timer 2 control register
   T2MOD   = 0x00;   // Load Timer 2 mode register

   TH2     = 0xFC;   // Load Timer 2 high byte
   RCAP2H  = 0xFC;   // Load Timer 2 reload capt. reg. high byte
   TL2     = 0x18;   // Load Timer 2 low byte
   RCAP2L  = 0x18;   // Load Timer 2 reload capt. reg. low byte

   // Timer 2 interrupt is enabled, and ISR will be called 
   // whenever the timer overflows - see below.
   ET2     = 1;

   // Start Timer 2 running
   TR2   = 1;        
   }

/*------------------------------------------------------------------*-

  LED_Flash_Init()

  - See below.

-*------------------------------------------------------------------*/
void LED_Flash_Init(void)
   {
   LED_state_G = 0;
   }


/*------------------------------------------------------------------*-

  LED_Flash_Update()

  Flashes an LED (or pulses a buzzer, etc) on a specified port pin.

  Code assumes this function will called every 1 ms.
  The LED will flash at 0.5Hz (on for 1 second, off for 1 second)

-*------------------------------------------------------------------*/
void LED_Flash_Update(void) interrupt INTERRUPT_Timer_2_Overflow
   {
   // This ISR is called every 1 ms
   // - only want to update the LED every second
   static data tWord Call_count;

   TF2 = 0;  // Reset the T2 flag   

   if (++Call_count < 1000)
      {
      return;
      }

   Call_count = 0;

   // Change the LED from OFF to ON (or vice versa)
   // (Do this every second)
   if (LED_state_G == 1)
      {
      LED_state_G = 0;
      LED_pin = 0;
      }
   else
      {
      LED_state_G = 1;
      LED_pin = 1;
      }
   }

/*------------------------------------------------------------------*-
  
  Go_To_Sleep()

  This one-task scheduler enters 'idle mode' between clock ticks
  to save power.  The next clock tick will return the processor
  to the normal operating state.

  Note: a slight performance improvement is possible if this
  function is implemented as a macro, or if the code here is simply 
  pasted into the 'dispatch' function.  

  However, by making this a function call, it becomes easier 
  - during development - to assess the performance of the 
  scheduler, using the 'performance analyser' in the Keil 
  hardware simulator. See Chapter 14 for examples for this. 

  *** May wish to disable this if using a watchdog ***

  *** ADAPT AS REQUIRED FOR YOUR HARDWARE ***

-*------------------------------------------------------------------*/
void Go_To_Sleep(void)
   {
   PCON |= 0x01;    // Enter idle mode (generic 8051 version)

   // Entering idle mode requires TWO consecutive instructions 
   // on 80c515 / 80c505 - to avoid accidental triggering
   //PCON |= 0x01;    // Enter idle mode (#1)
   //PCON |= 0x20;    // Enter idle mode (#2)
   }


/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
