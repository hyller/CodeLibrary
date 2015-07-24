/*------------------------------------------------------------------*-

   PWM_3.C (v1.00)

  ------------------------------------------------------------------

   Simple 3-level PWM example (see Chapter 33).

   Use 'Hyperterminal' (under Windows 95, 98, 2000, etc) 
   or similar terminal emulator program on other operating systems.

   Terminal options: 

   - Data bits    = 8
   - Parity       = None
   - Stop bits    = 1
   - Flow control = Xon / Xoff


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

#include "0_05_11g.h"
#include "PWM_3.h"
#include "PC_IO_T1.h"

// ------ Private constants ----------------------------------------

#define PWM_OFF 1
#define PWM_ON 0

/*------------------------------------------------------------------*-

  PWM_3_Command_Processor()

  This function is the main menu 'command processor' function.  

  Schedule this once every 10 ms (approx.).

-*------------------------------------------------------------------*/
void PWM_3_Command_Processor(void)
   {
   static bit First_time_only;
   char Ch;

   if (First_time_only == 0)
      {
      First_time_only = 1;
      PWM_3_Show_Menu();
      }

   // Check for user inputs
   PC_LINK_IO_Update();

   Ch = PC_LINK_IO_Get_Char_From_Buffer();
      
   if (Ch != PC_LINK_IO_NO_CHAR)
      {
      PWM_3_Perform_Task(Ch);
      PWM_3_Show_Menu();
      }
   }


/*------------------------------------------------------------------*-

  PWM_3_Show_Menu()

  Display menu options on PC screen (via serial link)
  - edit as required to meet the needs of your application.

-*------------------------------------------------------------------*/
void PWM_3_Show_Menu(void)
   {
   PC_LINK_IO_Write_String_To_Buffer("Menu:\n"); 
   PC_LINK_IO_Write_String_To_Buffer("a - 0%\n");
   PC_LINK_IO_Write_String_To_Buffer("b - 50%\n");
   PC_LINK_IO_Write_String_To_Buffer("c - 100%\n\n");
   PC_LINK_IO_Write_String_To_Buffer("? : ");
   }


/*------------------------------------------------------------------*-

  PWM_3_Perform_Task()

  Perform the required user task
  - edit as required to match the needs of your application.

-*------------------------------------------------------------------*/
void PWM_3_Perform_Task(char c)
   {
   // Echo the menu option
   PC_LINK_IO_Write_Char_To_Buffer(c);
   PC_LINK_IO_Write_Char_To_Buffer('\n');

   // Perform the task
   switch (c)
      {
      case 'a':
      case 'A':
         {
         PWM_3_Set_000();
         break;
         }
      
      case 'b':
      case 'B':
         {
         PWM_3_Set_050();
         break;
         }

      case 'c':
      case 'C':
         {
         PWM_3_Set_100();
         }
      } 
   }

/*------------------------------------------------------------------*-

  PWM_3_Set_000()

  Set PWM output to 0% duty cycle.

-*------------------------------------------------------------------*/
void PWM_3_Set_000(void)
   {
   PC_LINK_IO_Write_String_To_Buffer("\n*** 0% ***\n\n");

   TR2   = 0; // Stop timer 2

   PWM_pin = PWM_OFF;  
   }

/*------------------------------------------------------------------*-

  PWM_3_Set_050()

  Set PWM output to 50% duty cycle using Timer 2.

-*------------------------------------------------------------------*/
void PWM_3_Set_050(void)
   {
   PC_LINK_IO_Write_String_To_Buffer("\n*** 50% ***\n\n");

   T2CON &= 0xFD;   // Clear *only* C /T2 bit
   T2MOD |= 0x02;   // Set T2OE bit  (omit in basic 8052 clone)
  
   // Set at lowest frequency (~45Hz with 12MHz xtal)
   // - adjust as required (see PRM HARDWARE)
   TL2     = 0x00;   // Timer 2 low byte
   TH2     = 0x00;   // Timer 2 high byte
   RCAP2L  = 0x00;   // Timer 2 reload capture register, low byte
   RCAP2H  = 0x00;   // Timer 2 reload capture register, high byte

   ET2   = 0; // No interrupt.

   TR2   = 1; // Start timer 2
   }

/*------------------------------------------------------------------*-

  PWM_3_Set_100()

  Set PWM output to 100% duty cycle.

-*------------------------------------------------------------------*/
void PWM_3_Set_100(void)
   {
   PC_LINK_IO_Write_String_To_Buffer("\n*** Doing C ***\n\n");

   TR2   = 0; // Stop timer 2

   PWM_pin = PWM_ON;
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/

