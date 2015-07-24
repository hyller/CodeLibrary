/*------------------------------------------------------------------*-

   Keypad.h (v1.00)

  ------------------------------------------------------------------

   - see Keypad.C for details.


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

// ------ Public function prototypes -------------------------------

void KEYPAD_Init(void);
void KEYPAD_Update(void);

bit  KEYPAD_Get_Data_From_Buffer(char* const, char* const);
void KEYPAD_Clear_Buffer(void);

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/

