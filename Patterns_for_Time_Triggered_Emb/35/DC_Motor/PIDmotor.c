/*------------------------------------------------------------------*-

   PID_Motor.c (v1.01)

  ------------------------------------------------------------------

   Small library for PID control of a DC motor.
   For C515c microcontroller.
   
   The set point (required speed) is read via a potentiometer 
   and on-chip ADC.
   
   The current speed is read via an optical encoder.  The pulses
   from the encoder are counted using T0.

   The new speed is set by PWM using the on-chip capture-compare 
   unit (Timer 2).


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

#include "PIDMotor.h"
#include "PC_O_in.h"


// ------ Public constants -----------------------------------------

extern const char code CHAR_MAP_G[10];

// ------ Private function prototypes ------------------------------

static tByte PID_MOTOR_Get_Required_Speed(void);
static tByte PID_MOTOR_Read_Current_Speed(void);
static void  PID_MOTOR_Set_New_PWM_Output(const tByte);

// ------ Private constants ----------------------------------------

#define PULSE_HIGH (0)
#define PULSE_LOW (1)

// PID parameters
#define PID_PROPORTIONAL (5)
#define PID_INTEGRAL     (50)
#define PID_DIFFERENTIAL (50)

// ------ Private variables ----------------------------------------

// Used for demo purposes only
tWord Ticks = 0;

// Stores the latest count value
static tByte Pulse_count_G;

// Data to be copied to the serial port
static char PID_MOTOR_data_G[50] = {"  "};

// Measured speed, required speed and controller output variables
static tByte Speed_measured_G = 45;
static tByte Speed_required_G = 50;
static tByte Controller_output_G = 128;

static int Old_error_G = 0;
static int Sum_G = 0;


/*------------------------------------------------------------------*-

  PID_MOTOR_Init()

  Prepare for UD motor control.

-*------------------------------------------------------------------*/
void PID_MOTOR_Init(void)
   {
   // -----------------------------------------------------------
   // Set up the initial data to be sent to the PC via RS-232
   // -----------------------------------------------------------
   char* pScreen_Data =  "Cur     Des     PWM     \n";

   tByte c;
   
   for (c = 0; c < 30; c++)
      {
      PID_MOTOR_data_G[c] = pScreen_Data[c];
      }  

   // -----------------------------------------------------------
   // Set up the A-D converter
   // (used to measure the 'set point' (the desired motor speed)
   // -----------------------------------------------------------

   // Select internally-triggered single conversion
   // Reading from P6.0 (single channel)
   ADCON0 = 0xC0;  // Mask bits 0 - 5 to 0 
   
   // Select appropriate prescalar ratio: see manual for details
   ADCON1 = 0x80;  // Make bit 7 = 1 : Prescaler ratio=8

   // -----------------------------------------------------------
   // Set up the PWM output (Cap Com) unit - T2
   // (used to set the desired motor speed)
   // -----------------------------------------------------------

   // ---------- T2 Mode ---------------------------
   // Mode 1 = Timerfunction
 
   // Prescaler: Fcpu/6

   // ---------- T2 reload mode selection ----------
   // Mode 0 = auto-reload upon timer overflow
   // Preset the timer register with autoreload value ! 0xFF00;
   TL2 = 0x00;
   TH2 = 0xFF;
    
   // ---------- T2 general compare mode ----------
   //  Mode 0 for all channels
   T2CON |= 0x11;

   // ---------- T2 general interrupts ------------
   //  Timer 2 overflow interrupt is disabled
   ET2=0;
   //  Timer 2 external reload interrupt is disabled
   EXEN2=0;

   // ---------- Compare/capture Channel 0 ---------
   // Disabled??
   // Set Compare Register CRC on: 0xFF00;
   CRCL = 0x00;
   CRCH = 0xFF;
  
   // CC0/ext3 interrupt is disabled
   EX3=0;
  
   // ---------- Compare/capture Channel 1 ---------
   // Compare enabled
   // Set Compare Register CC1 on: 0xFF80;
   CCL1 = 0x80;
   CCH1 = 0xFF;
  
   // CC1/ext4 interrupt is disabled
   EX4=0;
  
   // ---------- Compare/capture Channel 2 ---------
   // Disabled
   // Set Compare Register CC2 on: 0x0000;
   CCL2 = 0x00;
   CCH2 = 0x00;
   //  CC2/ext5 interrupt is disabled
   EX5=0;
  
   // ---------- Compare/capture Channel 3 ---------
   // Disabled
   // Set Compare Register CC3 on: 0x0000;
   CCL3 = 0x00;
   CCH3 = 0x00;
  
   // CC3/ext6 interrupt is disabled
   EX6=0;
  
   // Set all above mentioned modes for channel 0-3 
   CCEN = 0x08; 

   // -----------------------------------------------------------
   // Count pulses on Pin 3.5 [software only]
   // (used to measure the current motor speed)
   // -----------------------------------------------------------
   Pulse_count_pin = 1;
   Pulse_count_G = 0;   
   }

/*------------------------------------------------------------------*-

  PID_MOTOR_Control_Motor()

  The main motor control function.

-*------------------------------------------------------------------*/
void PID_MOTOR_Control_Motor(void)
   { 
   int Error;
   int Control_i;

   // Get the current speed value (0-255)
   Speed_measured_G = PID_MOTOR_Read_Current_Speed();

   // Get the desired speed value (0-255)
   Speed_required_G = 
   PID_MOTOR_Get_Required_Speed();

   if (++Ticks == 100)
      {
      Speed_required_G = 200;
      }
   
   // Difference between required and actual speed (0-255)
   Error = Speed_required_G - Speed_measured_G;

   // Proportional term
   Control_i = Controller_output_G + (Error / PID_PROPORTIONAL);

   // Integral term [SET TO 0 IF NOT REQUIRED]
   if (PID_INTEGRAL)
      {
      Sum_G += Error;
      Control_i += (Sum_G / (1 + PID_INTEGRAL));
      }

   // Differential term [SET TO 0 IF NOT REQUIRED]
   if (PID_DIFFERENTIAL)
      {
      Control_i += (Error - Old_error_G) / (1 + PID_DIFFERENTIAL);

      // Store error value
      Old_error_G = Error;
      }

   // Adjust to 8-bit range
   if (Control_i > 255)
      {
      Control_i = 255;
      Sum_G -= Error;  // Windup protection
      }

   if (Control_i < 0)
      {
      Control_i = 0;
      Sum_G -= Error;  // Windup protection
      } 

   // Convert to required 8-bit format
   Controller_output_G = (tByte) Control_i; 

   // Update the PWM setting
   PID_MOTOR_Set_New_PWM_Output(Controller_output_G);

   // Update display
   PID_MOTOR_data_G[4] = CHAR_MAP_G[Speed_measured_G / 100];
   PID_MOTOR_data_G[5] = CHAR_MAP_G[(Speed_measured_G % 100) / 10];
   PID_MOTOR_data_G[6] = CHAR_MAP_G[Speed_measured_G % 10];

   PID_MOTOR_data_G[12] = CHAR_MAP_G[Speed_required_G / 100];
   PID_MOTOR_data_G[13] = CHAR_MAP_G[(Speed_required_G % 100) / 10];
   PID_MOTOR_data_G[14] = CHAR_MAP_G[Speed_required_G % 10];

   PID_MOTOR_data_G[20] = CHAR_MAP_G[Controller_output_G / 100];
   PID_MOTOR_data_G[21] = CHAR_MAP_G[(Controller_output_G % 100) / 10];
   PID_MOTOR_data_G[22] = CHAR_MAP_G[Controller_output_G % 10];

   PC_LINK_O_Write_String_To_Buffer(PID_MOTOR_data_G);
   } 

/*------------------------------------------------------------------*-

  PID_MOTOR_Get_Required_Speed()

  Get the required speed via the Pot and ADC.

-*------------------------------------------------------------------*/
tByte PID_MOTOR_Get_Required_Speed(void)
   {
   // Take sample from A-D

   // Write (value not important) to ADDATL to start conversion
   ADDATL = 0x01; 
     
   // Wait for conversion to complete
   // NOTE: This demo software has no timeout...
   while (BSY == 1);

   // 10-bit A-D result is now available
   // return 8-bit result
   return ADDATH;
   }

/*------------------------------------------------------------------*-

  PID_MOTOR_Set_New_PWM_Output()

  Adjust the PWM output value.

-*------------------------------------------------------------------*/
void PID_MOTOR_Set_New_PWM_Output(const tByte Controller_output_G)
   {
   // Changing value in CCL1 to generate appropriate PWM duty cycle
   CCL1 = Controller_output_G;
   }


/*------------------------------------------------------------------*-

  PID_MOTOR_Read_Current_Speed()

  Schedule this function at regular intervals.

  Remember: max count is 65536 (16-bit counter)
  - it is your responsibility to ensure this count
  is not exceeded.  Choose an appropriate schedule
  interval and allow a margin for error.

  For high-frequency pulses, you need to take account of
  the fact that the count is stop for a (very brief) period,
  to read the counter.  

  Note: the delay before the first count is taken should 
  generally be the same as the inter-count interval,
  to ensure that the first count is as accurate as possible.

  For example, this is OK:

    Sch_Add_Task(PID_MOTOR_Read_Current_Speed, 1000, 1000);

  While this will give a very low first count:

   Sch_Add_Task(PID_MOTOR_Read_Current_Speed, 0, 1000);

-*------------------------------------------------------------------*/

tByte PID_MOTOR_Read_Current_Speed(void)
   {
   int C;
   tByte Count = Pulse_count_G;

   Pulse_count_G = 0;    

   // Normalised: 0 -> 255
   C = 9 * ((int) Count - 28);

   if (C < 0)
      {
      C = 0;
      }

   if (C > 255)
      {
      C = 255;
      }

   return (tByte) C;
   }

/*------------------------------------------------------------------*-

  PID_MOTOR_Poll_Speed_Pulse()

  Using software to count falling edges on a specified pin
  - T0 is *NOT* used here.

-*------------------------------------------------------------------*/
void PID_MOTOR_Poll_Speed_Pulse(void)
   {
   static bit Previous_state;
   bit Current_state = Pulse_count_pin;

   if ((Previous_state == PULSE_HIGH) && (Current_state == PULSE_LOW))
      {
      Pulse_count_G++;
      }

   Previous_state = Current_state;  
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
