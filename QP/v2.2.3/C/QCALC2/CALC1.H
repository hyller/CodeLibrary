/******************************************************************** 
 * Quantum Calc1ulator example ("C+" version)
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA.
 * All Rights Reserved.
 *******************************************************************/
#ifndef calc1_h
#define calc1_h

#include <windows.h>
#include "qf_win32.h"

SUBCLASS(CalcEvt, QEvent)
   int keyId;                           /* ID of the key depressed */
METHODS
END_CLASS

SUBCLASS(Calc1, QHsm)
   HWND hWnd_;                     /* the calculator window handle */
   BOOL isHandled_;
   char display_[40];
   char *ins_;
   double operand1_;
   double operand2_;
   int operator_;
VTABLE(Calc1, QHsm)
   QSTATE (*calc)(Calc1 *me, QEvent const *e);
   QSTATE (*ready)(Calc1 *me, QEvent const *e);
   QSTATE (*result)(Calc1 *me, QEvent const *e);
   QSTATE (*begin)(Calc1 *me, QEvent const *e);
   QSTATE (*negated1)(Calc1 *me, QEvent const *e);
   QSTATE (*operand1)(Calc1 *me, QEvent const *e);
   QSTATE (*zero1)(Calc1 *me, QEvent const *e);
   QSTATE (*int1)(Calc1 *me, QEvent const *e);
   QSTATE (*frac1)(Calc1 *me, QEvent const *e);
   QSTATE (*opEntered)(Calc1 *me, QEvent const *e);
   QSTATE (*negated2)(Calc1 *me, QEvent const *e);
   QSTATE (*operand2)(Calc1 *me, QEvent const *e);
   QSTATE (*zero2)(Calc1 *me, QEvent const *e);
   QSTATE (*int2)(Calc1 *me, QEvent const *e);
   QSTATE (*frac2)(Calc1 *me, QEvent const *e);
   void (*clear_)(Calc1 *me);
   void (*insert_)(Calc1 *me, int keyId);
   void (*negate_)(Calc1 *me);
   void (*eval_)(Calc1 *me);
METHODS
   Calc1 *Calc1Ctor_(Calc1 *me);          /* protected constructor */
   void Calc1Xtor(Calc1 *me);
   Calc1 *Calc1Instance(void); /* static Singleton accessor method */
   void Calc1_initial(Calc1 *me, QEvent const *e);
   QSTATE Calc1_calc(Calc1 *me, QEvent const *e);
      QSTATE Calc1_ready(Calc1 *me, QEvent const *e);
         QSTATE Calc1_result(Calc1 *me, QEvent const *e);
         QSTATE Calc1_begin(Calc1 *me, QEvent const *e);
      QSTATE Calc1_negated1(Calc1 *me, QEvent const *e);
      QSTATE Calc1_operand1(Calc1 *me, QEvent const *e);
         QSTATE Calc1_zero1(Calc1 *me, QEvent const *e);
         QSTATE Calc1_int1(Calc1 *me, QEvent const *e);
         QSTATE Calc1_frac1(Calc1 *me, QEvent const *e);
      QSTATE Calc1_opEntered(Calc1 *me, QEvent const *e);
      QSTATE Calc1_negated2(Calc1 *me, QEvent const *e);
      QSTATE Calc1_operand2(Calc1 *me, QEvent const *e);
         QSTATE Calc1_zero2(Calc1 *me, QEvent const *e);
         QSTATE Calc1_int2(Calc1 *me, QEvent const *e);
         QSTATE Calc1_frac2(Calc1 *me, QEvent const *e);

   void Calc1Clear_(Calc1 *me);
   void Calc1Insert_(Calc1 *me, int keyId);
   void Calc1Negate_(Calc1 *me);
   void Calc1Eval_(Calc1 *me);
END_CLASS

#endif                                                  /* calc1_h */
