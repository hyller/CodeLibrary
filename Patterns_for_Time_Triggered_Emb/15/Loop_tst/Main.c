/*------------------------------------------------------------------*-

   Main.C (v1.00)

  ------------------------------------------------------------------

   Testing timeout loops.


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.H"
#include "TimeoutL.H"

// Function prototypes
void Test_1ms(void); 
void Test_10ms(void); 
void Test_500ms(void); 

/*------------------------------------------------------------------*/
void main(void)
   {
   while(1) 
      {
      Test_1ms();  
      Test_10ms();  
      Test_500ms();  
      }
   }

/*------------------------------------------------------------------*/
void Test_1ms(void)
   {
   tWord Timeout_loop = LOOP_TIMEOUT_INIT_001ms;

   // Simple loop timeout...
   while (++Timeout_loop != 0);
   }
/*------------------------------------------------------------------*/
void Test_10ms(void)
   {
   tWord Timeout_loop = LOOP_TIMEOUT_INIT_010ms;

   // Simple loop timeout...
   while (++Timeout_loop != 0);
   }

/*------------------------------------------------------------------*/
void Test_500ms(void)
   {
   tWord Timeout_loop = LOOP_TIMEOUT_INIT_500ms;

   // Simple loop timeout...
   while (++Timeout_loop != 0);
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
