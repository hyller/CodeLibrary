/*------------------------------------------------------------------*-

   PC_O.h (v1.01)

  ------------------------------------------------------------------

   - see PC_O.h for details.


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

// ------ Public function prototypes -------------------------------

void PC_LINK_O_Write_String_To_Buffer(const char* const);
void PC_LINK_O_Write_Char_To_Buffer(const char);
void PC_LINK_O_Send_Char(const char);
void PC_LINK_O_Update(void);

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/

