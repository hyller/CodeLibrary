/******************************************************************** 
 * Quantum Calculator example (C version)
 * (c) Copyright 2002, Miro Samek, Palo Alto, CA.
 * All Rights Reserved.
 *******************************************************************/
#ifndef calc_h
#define calc_h

#include <windows.h>
#include "qf_win32.h"

SUBCLASS(CalcEvt, QEvent)
   int keyId;                           /* ID of the key depressed */
METHODS
END_CLASS

SUBCLASS(Calc, QHsm)
   HWND hWnd_;                     /* the calculator window handle */
   BOOL isHandled_;
   char display_[40];
   char *ins_;
   double operand1_;
   double operand2_;
   int operator_;
METHODS
   Calc *CalcCtor(Calc *me);
   void CalcXtor(Calc *me);
   Calc *CalcInstance(void);   /* static Singleton accessor method */
   void Calc_initial(Calc *me, QEvent const *e);
   QSTATE Calc_calc(Calc *me, QEvent const *e);
      QSTATE Calc_ready(Calc *me, QEvent const *e);
         QSTATE Calc_result(Calc *me, QEvent const *e);
         QSTATE Calc_begin(Calc *me, QEvent const *e);
      QSTATE Calc_negated1(Calc *me, QEvent const *e);
      QSTATE Calc_operand1(Calc *me, QEvent const *e);
         QSTATE Calc_zero1(Calc *me, QEvent const *e);
         QSTATE Calc_int1(Calc *me, QEvent const *e);
         QSTATE Calc_frac1(Calc *me, QEvent const *e);
      QSTATE Calc_opEntered(Calc *me, QEvent const *e);
      QSTATE Calc_negated2(Calc *me, QEvent const *e);
      QSTATE Calc_operand2(Calc *me, QEvent const *e);
         QSTATE Calc_zero2(Calc *me, QEvent const *e);
         QSTATE Calc_int2(Calc *me, QEvent const *e);
         QSTATE Calc_frac2(Calc *me, QEvent const *e);

   void CalcClear_(Calc *me);
   void CalcInsert_(Calc *me, int keyId);
   void CalcNegate_(Calc *me);
   void CalcEval_(Calc *me);
   void CalcDispState(Calc *me, char const *s);
END_CLASS

#endif                                                   /* calc_h */
