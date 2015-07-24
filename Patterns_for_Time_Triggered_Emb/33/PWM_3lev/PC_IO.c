/*------------------------------------------------------------------*-

   PC_IO.C (v1.01)

  ------------------------------------------------------------------

   Core files for simple PC link library for 8051 family

   Uses the USART, and Pins 3.1 (Tx) and 3.0 (Rx) 

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
#include "PC_IO.h"

// ------ Public variable definitions ------------------------------

tByte In_read_index_G;     // Data in buffer that has been read 
tByte In_waiting_index_G;  // Data in buffer not yet read

tByte Out_written_index_G;  // Data in buffer that has been written 
tByte Out_waiting_index_G;  // Data in buffer not yet written

// ------ Public variable declarations -----------------------------

// The error code variable
//
// See Main.H for port on which error codes are displayed
// and for details of error codes
extern tByte Error_code_G;

// ------ Private function prototypes ------------------------------

void PC_LINK_IO_Send_Char(const char);

// ------ Private constants ----------------------------------------

// The receive buffer length
#define RECV_BUFFER_LENGTH 8

// The transmit buffer length
#define TRAN_BUFFER_LENGTH 50

#define XON  0x11
#define XOFF 0x13

// ------ Private variables ----------------------------------------

static tByte Recv_buffer[RECV_BUFFER_LENGTH];
static tByte Tran_buffer[TRAN_BUFFER_LENGTH];


/*------------------------------------------------------------------*-

  PC_LINK_IO_Update()

  Checks for character in the UART (hardware) receive buffer
  Sends next character from the software transmit buffer
  
-*------------------------------------------------------------------*/
void PC_LINK_IO_Update(void)
   {
   // Deal with transmit bytes here

   // Is there any data ready to send?
   if (Out_written_index_G < Out_waiting_index_G)
      {
      PC_LINK_IO_Send_Char(Tran_buffer[Out_written_index_G]);     

      Out_written_index_G++;
      }
   else
      {
      // No data to send - just reset the buffer index
      Out_waiting_index_G = 0;
      Out_written_index_G = 0;
      }

   // Only dealing with received bytes here
   // -> Just check the RI flag
   if (RI == 1)
      {
      // Flag only set when a valid stop bit is received, 
      // -> data ready to be read into the received buffer

      // Want to read into index 0, if old data has been read
      // (simple ~circular buffer)
      if (In_waiting_index_G == In_read_index_G)
         { 
         In_waiting_index_G = 0;
         In_read_index_G = 0;
         } 
      
      // Read the data from USART buffer   
      Recv_buffer[In_waiting_index_G] = SBUF;

      if (In_waiting_index_G < RECV_BUFFER_LENGTH)
         {
         // Increment without overflowing buffer
         In_waiting_index_G++;
         }
    
      RI = 0;  // Clear RT flag
      }
   }

/*------------------------------------------------------------------*-

  PC_LINK_IO_Write_Char_To_Buffer()

  Stores a character in the 'write' buffer, ready for 
  later transmission
 
-*------------------------------------------------------------------*/
void PC_LINK_IO_Write_Char_To_Buffer(const char CHARACTER)
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

  PC_LINK_IO_Write_String_To_Buffer()

  Copies a (null terminated) string to the character buffer.  
  (The contents of the buffer are then passed over the serial link)

  STR_PTR - Pointer to the NULL-TERMINATED string.  

-*------------------------------------------------------------------*/
void PC_LINK_IO_Write_String_To_Buffer(const char* const STR_PTR)
   {
   tByte i = 0;

   while (STR_PTR[i] != '\0')
      {
      PC_LINK_IO_Write_Char_To_Buffer(STR_PTR[i]);
      i++;
      }
   }

/*------------------------------------------------------------------*-

  PC_LINK_IO_Get_Char_From_Buffer()

  Retrieves a character from the (software) buffer, if available

  The character from the buffer is returned, or - if no 
  data are available - PC_LINK_IO_NO_CHAR is returned.

-*------------------------------------------------------------------*/
char PC_LINK_IO_Get_Char_From_Buffer(void)
   {
   char Ch = PC_LINK_IO_NO_CHAR;

   // If there is new data in the buffer
   if (In_read_index_G < In_waiting_index_G)
      {
      Ch = Recv_buffer[In_read_index_G];

      if (In_read_index_G < RECV_BUFFER_LENGTH)
         {
         In_read_index_G++;
         }
      }
   
   return Ch;
   }

/*------------------------------------------------------------------*-

  PC_LINK_IO_Send_Char()

  Based on Keil sample code, with added (loop) timeouts.
  Implements Xon / Off control.

  Uses on-chip UART hardware.

-*------------------------------------------------------------------*/
void PC_LINK_IO_Send_Char(const char CHARACTER)
   {
   tLong Timeout1 = 0;
   tLong Timeout2 = 0;

   if (CHARACTER == '\n')  
      {
      if (RI)  
         {
         if (SBUF == XOFF)  
            {
            Timeout2 = 0;
            do {
               RI = 0;
                
               // Wait for uart (with simple timeout)
               Timeout1 = 0;
               while ((++Timeout1) && (RI == 0));  

               if (Timeout1 == 0)
                  {
                  // USART did not respond - error
                  Error_code_G = ERROR_USART_TI;
                  return;
                  } 

               } while ((++Timeout2) && (SBUF != XON));

            if (Timeout2 == 0)
               {
               // uart did not respond - error
               Error_code_G = ERROR_USART_TI;
               return;
               } 

            RI = 0; 
            }
         }

      Timeout1 = 0;
      while ((++Timeout1) && (TI == 0));  

      if (Timeout1 == 0)
         {
         // uart did not respond - error
         Error_code_G = ERROR_USART_TI;
         return;
         } 

      TI = 0;
      SBUF = 0x0d;  // output CR  
      }
  
   if (RI)  
      {
      if (SBUF == XOFF)  
         {
         Timeout2 = 0;

         do {
            RI = 0;

            // Wait for USART (with simple timeout)
            Timeout1 = 0;
            while ((++Timeout1) && (RI == 0));  

            if (Timeout1 == 0)
               {
               // USART did not respond - error
               Error_code_G = ERROR_USART_TI;
               return;
               } 

            } while ((++Timeout2) && (SBUF != XON));
      
         RI = 0; 
         }
     }

   Timeout1 = 0;
   while ((++Timeout1) && (TI == 0));  

   if (Timeout1 == 0)
      {
      // USART did not respond - error
      Error_code_G = ERROR_USART_TI;
      return;
      } 

   TI = 0;

   SBUF = CHARACTER;
   }


/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
