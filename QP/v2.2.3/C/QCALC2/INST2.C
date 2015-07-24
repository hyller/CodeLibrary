/******************************************************************** 
 * Quantum Calculator2 example ("C+" version)
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA.
 * All Rights Reserved.
 *******************************************************************/
#include "calc2.h"

Calc1 *Calc1Instance(void) {            /* static Singleton method */
   static Calc2 inst;
   static Calc1 *ptr = 0;
   if (!ptr) {
      ptr = (Calc1 *)Calc2Ctor_(&inst);
   }
   return ptr;
}
