/////////////////////////////////////////////////////////////////////
// Quantum Calculator example (C++ version)
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#ifndef calc1_h
#define calc1_h

#include "qf_win32.h"

struct CalcEvt : public QEvent {
   int keyId;                              // ID of the key depressed
};

class Calc1 : public QHsm {
public:
   static Calc1 *instance();             // Singleton accessor method
protected:
   Calc1() : QHsm((QPseudoState)initial) {}  // protected constructor
   void initial(QEvent const *e);
   virtual QSTATE calc(QEvent const *e);
      virtual QSTATE ready(QEvent const *e);
         virtual QSTATE result(QEvent const *e);
         virtual QSTATE begin(QEvent const *e);
      virtual QSTATE negated1(QEvent const *e);
      virtual QSTATE operand1(QEvent const *e);
         virtual QSTATE zero1(QEvent const *e);
         virtual QSTATE int1(QEvent const *e);
         virtual QSTATE frac1(QEvent const *e);
      virtual QSTATE opEntered(QEvent const *e);
      virtual QSTATE negated2(QEvent const *e);
      virtual QSTATE operand2(QEvent const *e);
         virtual QSTATE zero2(QEvent const *e);
         virtual QSTATE int2(QEvent const *e);
         virtual QSTATE frac2(QEvent const *e);
   virtual QSTATE final(QEvent const *e);
protected:
   virtual void clear();
   virtual void insert(int keyId);
   virtual void negate();
   virtual void eval();
   void dispState(char const *s);
protected:
   HWND myHwnd;                       // the calculator window handle
   BOOL isHandled;
   char myDisplay[40];
   char *myIns;
   double myOperand1;
   double myOperand2;
   int myOperator;
   friend BOOL CALLBACK calcDlg(HWND hwnd, UINT iEvt, 
                                WPARAM wParam, LPARAM lParam);
};

#endif                                                     // calc1_h
