/*------------------------------------------------------------------*-

   Main.C (v1.00)

  ------------------------------------------------------------------
   
   Demonstration of function pointers.


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.h"
#include "Printf51.h"
#include <stdio.h>

// ------ Private function prototypes ------------------------------
void Square_Number(int, int*);

/* ................................................................. */
/* ................................................................. */

int main(void)
   {
   int a = 2, b = 3;      
   void (* pFn)(int, int*); /* Declares pFn to be a pointer to fn with 
                               int and int pointer parameters 
                               (returning void) */
   int Result_a, Result_b;
   
   // Prepare to use printf() [in Keil hardware simulator]
   Printf51_Init();

   pFn = Square_Number;   // pFn holds address of Square_Number 
 
   printf("Function code starts at address: %u\n", (tWord) pFn);
   printf("Data item a starts at address:   %u\n\n", (tWord) &a);
   
   // Call 'Square_Number' in the conventional way
   Square_Number(a,&Result_a);
   
   // Call 'Square_Number' using function pointer
   (*pFn)(b,&Result_b);
                         
   printf("%d squared is %d (using normal fn call)\n", a, Result_a); 
   printf("%d squared is %d (using fn pointer)\n", b, Result_b); 

   while(1);

   return 0;
   }

/*------------------------------------------------------------------*/

void Square_Number(int a, int* b)
   {
   // Demo - calculate square of a
   *b = a * a;
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/

