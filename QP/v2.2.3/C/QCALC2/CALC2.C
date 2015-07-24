/******************************************************************** 
 * Quantum Calculator2 example (C version)
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA.
 * All Rights Reserved.
 *******************************************************************/
#include "qassert.h"
#include "calc2.h"
#include "resource.h"

#include <string.h>
#include <commctrl.h>
#include <stdio.h>

DEFINE_THIS_FILE;

/*.................................................................*/
BEGIN_VTABLE(Calc2, Calc1)
   VMETHOD(Calc1, operand2) = 
      (QSTATE (*)(Calc1*, QEvent const *))Calc2_operand2;
END_VTABLE
/*.................................................................*/
Calc2 *Calc2Ctor_(Calc2 *me) {
   if (!Calc1Ctor_(&me->super_)) {
      return 0;
   }
   VHOOK(Calc2);
   return me;
}
/*.................................................................*/
QSTATE Calc2_operand2(Calc2 *me, QEvent const *e) {
   switch (e->sig) {
   /*
   case Q_ENTRY_SIG:
      Beep(1000, 20);
      return 0;
   */
   case IDC_PERCENT:
      sscanf(me->super_.display_, "%lf", &me->super_.operand2_);
      switch (me->super_.operator_) {
      case IDC_PLUS:
         me->super_.operand2_ = 1.0 + me->super_.operand2_/100.0;
         me->super_.operator_ = IDC_MULT;
         break;
      case IDC_MINUS:
         me->super_.operand2_ = 1.0 - me->super_.operand2_/100.0;
         me->super_.operator_ = IDC_MULT;
         break;
      case IDC_MULT:                 /* intentionally fall thru... */
      case IDC_DIVIDE:
         me->super_.operand2_ /= 100.0;              /* x*y%, x/y% */
         break;
      default:
         ASSERT(0);
      }
      Q_TRAN(VPTR(Calc1, me)->result);
      return 0;                                   /* event handled */
   }
                                   /* let Calc handle other events */
   return Calc1_operand2((Calc1 *)me, e); 
}
