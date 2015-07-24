/////////////////////////////////////////////////////////////////////
// Quantum Calculator example (C++ version)
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#ifndef calc0_h
#define calc0_h

#include <windows.h>
#include "qf_win32.h"

struct CalcEvt : public QEvent {
   int keyId;                              // ID of the key depressed
};

class Calc0 : public QHsm {               // calculator state machine
public:
    Calc0() : QHsm((QPseudoState)initial) {}
    static Calc0 *instance();            // Singleton accessor method
private:
   void initial(QEvent const *e);
   QSTATE calc(QEvent const *e);
      QSTATE result(QEvent const *e);
      QSTATE operand1(QEvent const *e);
         QSTATE zero1(QEvent const *e);
         QSTATE int1(QEvent const *e);
         QSTATE frac1(QEvent const *e);
      QSTATE opEntered(QEvent const *e);
      QSTATE operand2(QEvent const *e);
         QSTATE zero2(QEvent const *e);
         QSTATE int2(QEvent const *e);
         QSTATE frac2(QEvent const *e);
   QSTATE final(QEvent const *e);
                                                 // helper methods...
   void clear();
   void insert(int keyId);
   void negate();
   void eval();
   void dispState(char const *s);
private:
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

#endif                                                     // calc0_h
