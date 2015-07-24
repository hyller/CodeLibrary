/*------------------------------------------------------------------*-

   Menu.C (v1.01)

  ------------------------------------------------------------------

   Simple framework for interactive operation (e.g. data downloads) 
   to / from desktop / notebook PC (etc) via serial (UART) link.

   Use 'Hyperterminal' (under Windows 95, 98, 2000) or similar 
   terminal emulator program on other operating systems.

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
#include "2_01_10i.h"
#include "Menu_A.h"
#include "PC_IO_in.h"

/*------------------------------------------------------------------*-

  MENU_Command_Processor()

  This function is the main menu 'command processor' function.  

  Schedule this (say) once every 10 ms (approx.).

-*------------------------------------------------------------------*/
void MENU_Command_Processor(void)
   {
   static bit First_time_only;
   char Ch;

   if (First_time_only == 0)
      {
      First_time_only = 1;
      MENU_Show_Menu();
      }

   // Check for user inputs
   PC_LINK_IO_Update();

   Ch = PC_LINK_IO_Get_Char_From_Buffer();
      
   if (Ch != PC_LINK_IO_NO_CHAR)
      {
      MENU_Perform_Task(Ch);
      MENU_Show_Menu();
      }
   }


/*------------------------------------------------------------------*-

  MENU_Show_Menu()

  Display menu options on PC screen (via serial link)
  - edit as required to meet the needs of your application.

-*------------------------------------------------------------------*/
void MENU_Show_Menu(void)
   {
   PC_LINK_IO_Write_String_To_Buffer("Menu:\n"); 
   PC_LINK_IO_Write_String_To_Buffer("a - x\n");
   PC_LINK_IO_Write_String_To_Buffer("b - x\n");
   PC_LINK_IO_Write_String_To_Buffer("c - x\n\n");
   PC_LINK_IO_Write_String_To_Buffer("? : ");
   }


/*------------------------------------------------------------------*-

  MENU_Perform_Task()

  Perform the required user task
  - edit as required to match the needs of your application.

-*------------------------------------------------------------------*/
void MENU_Perform_Task(char c)
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
         Function_A();
         break;
         }
      
      case 'b':
      case 'B':
         {
         Function_B();
         break;
         }

      case 'c':
      case 'C':
         {
         Function_C();
         }
      } 
   }

/*------------------------------------------------------------------*-

  Placeholder function

-*------------------------------------------------------------------*/
void Function_A(void)
   {
   PC_LINK_IO_Write_String_To_Buffer("\n* Doing A *\n\n");
   }

/*------------------------------------------------------------------*-

  Placeholder function

-*------------------------------------------------------------------*/
void Function_B(void)
   {
   PC_LINK_IO_Write_String_To_Buffer("\n* Doing B *\n\n");
   }

/*------------------------------------------------------------------*-

  Placeholder function

-*------------------------------------------------------------------*/
void Function_C(void)
   {
   PC_LINK_IO_Write_String_To_Buffer("\n* Doing C *\n\n");
   P1 = 'C';
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/

