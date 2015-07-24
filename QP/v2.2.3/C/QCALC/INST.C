/******************************************************************** 
 * Quantum Calculator example ("C+" version)
 * (c) Copyright 2001, Miro Samek, Palo Alto
 * All Rights Reserved
 *******************************************************************/
#include "calc.h"

Calc *CalcInstance(void) {              /* static Singleton method */
   static Calc inst;
   static Calc *ptr = 0;
   if (!ptr) {
      ptr = CalcCtor(&inst);
   }
   return ptr;
}
