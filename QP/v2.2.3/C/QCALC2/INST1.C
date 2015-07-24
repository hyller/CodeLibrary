/******************************************************************** 
 * Quantum Calculator example ("C+" version)
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA.
 * All Rights Reserved.
 *******************************************************************/
#include "calc1.h"

Calc1 *Calc1Instance(void) {            /* static Singleton method */
   static Calc1 inst;
   static Calc1 *ptr = 0;
   if (!ptr) {
      ptr = Calc1Ctor_(&inst);
   }
   return ptr;
}
