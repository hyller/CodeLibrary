/*------------------------------------------------------------------*-

   PC_IO.H (v1.01)

  ------------------------------------------------------------------

   - see PC_IO.C for details.


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

// ------ Public constants -----------------------------------------

// Value returned by PC_LINK_Get_Char_From_Buffer if no character is 
// available in buffer
#define PC_LINK_IO_NO_CHAR 127 

// ------ Public function prototypes -------------------------------

void PC_LINK_IO_Write_String_To_Buffer(const char* const);
void PC_LINK_IO_Write_Char_To_Buffer(const char);

char PC_LINK_IO_Get_Char_From_Buffer(void);

// Must schedule or otherwise regularly call this function...
void PC_LINK_IO_Update(void);

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/

