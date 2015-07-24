/*------------------------------------------------------------------*-

   PC_O.C (v1.01)

  ------------------------------------------------------------------

   Core files for simple write-only PC link library for 8051 family
   [Sends data to PC - cannot receive data from PC]

   Uses the USART, and Pin 3.1 (Tx) 

   See text for details (Chapter 18).


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"
#include "PC_O.h"

// ------ Public variable definitions ------------------------------

tByte Out_written_index_G;  // Data in buffer that has been written 
tByte Out_waiting_index_G;  // Data in buffer not yet written

// ------ Public variable declarations -----------------------------

// The error code variable
//
// See Main.H for port on which error codes are displayed
// and for details of error codes
extern tByte Error_code_G;

// ------ Private constants ----------------------------------------

// The transmit buffer length
#define TRAN_BUFFER_LENGTH 20

// ------ Private variables ----------------------------------------

static tByte Tran_buffer[TRAN_BUFFER_LENGTH];

/*------------------------------------------------------------------*-

  PC_LINK_O_Update()

  Sends next character from the software transmit buffer

  NOTE: Output-only library (Cannot receive chars)

  Uses on-chip UART hardware.

-*------------------------------------------------------------------*/
void PC_LINK_O_Update(void)
   {
   // Deal with transmit bytes here

   // Is there any data ready to send?
   if (Out_written_index_G < Out_waiting_index_G)
      {
      PC_LINK_O_Send_Char(Tran_buffer[Out_written_index_G]);     

      Out_written_index_G++;
      }
   else
      {
      // No data to send - just reset the buffer index
      Out_waiting_index_G = 0;
      Out_written_index_G = 0;
      }

   }

/*------------------------------------------------------------------*-

  PC_LINK_O_Write_String_To_Buffer()

  Copies a (null terminated) string to the character buffer.  
  (The contents of the buffer are then passed over the serial link)

-*------------------------------------------------------------------*/
void PC_LINK_O_Write_String_To_Buffer(const char* const STR_PTR)
   {
   tByte i = 0;

   while (STR_PTR[i] != '\0')
      {
      PC_LINK_O_Write_Char_To_Buffer(STR_PTR[i]);
      i++;
      }
   }

/*------------------------------------------------------------------*-

  PC_LINK_O_Write_Char_To_Buffer()

  Stores a character in the 'write' buffer, ready for 
  later transmission
 
-*------------------------------------------------------------------*/
void PC_LINK_O_Write_Char_To_Buffer(const char CHARACTER)
   {
   // Write to the buffer *only* if there is space
   if (Out_waiting_index_G < TRAN_BUFFER_LENGTH)
      {
      Tran_buffer[Out_waiting_index_G] = CHARACTER;
      Out_waiting_index_G++;     
      }
   else
      {
      // Write buffer is full
      // Increase the size of TRAN_BUFFER_LENGTH
      // or increase the rate at which UART 'update' function is called 
      // or reduce the amount of data sent to PC
      Error_code_G = ERROR_USART_WRITE_CHAR;
      }
   }

/*------------------------------------------------------------------*-

  PC_LINK_O_Send_Char()

  Based on Keil sample code, with added (loop) timeouts.
  Implements Xon / Off control.

  Uses on-chip UART hardware.

-*------------------------------------------------------------------*/
void PC_LINK_O_Send_Char(const char CHARACTER)
   {
   tLong Timeout1 = 0;

   if (CHARACTER == '\n')  
      {
      Timeout1 = 0;
      while ((++Timeout1) && (TI == 0));  

      if (Timeout1 == 0)
         {
         // usart did not respond - error
         Error_code_G = ERROR_USART_TI;
         return;
         } 

      TI = 0;
      SBUF = 0x0d;  // output CR  
      }
  
   Timeout1 = 0;
   while ((++Timeout1) && (TI == 0));  

   if (Timeout1 == 0)
      {
      // usart did not respond - error
      Error_code_G = ERROR_USART_TI;
      return;
      } 

   TI = 0;

   SBUF = CHARACTER;
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
