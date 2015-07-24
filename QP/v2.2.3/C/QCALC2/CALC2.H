/******************************************************************** 
 * Quantum Calculator2 example (C version)
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA.
 * All Rights Reserved.
 *******************************************************************/
#ifndef calc2_h
#define calc2_h

#include "calc1.h"

SUBCLASS(Calc2, Calc1)
VTABLE(Calc2, Calc1)
METHODS
   Calc2 *Calc2Ctor_(Calc2 *me);          /* protected constructor */
   QSTATE Calc2_operand2(Calc2 *me, QEvent const *e);
END_CLASS

#endif                                                  /* calc2_h */
