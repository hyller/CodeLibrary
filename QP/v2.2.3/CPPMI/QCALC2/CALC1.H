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
   Calc1() : QHsm(static_cast<CQSTATE::QState>(&Calc1::initial)) {}
   Q_DEFINE_CALL_MEMBER_FN(Calc1)            // Define callMemberFn()
   virtual CQSTATE initial(QEvent const *e);
   virtual CQSTATE calc(QEvent const *e);
      virtual CQSTATE ready(QEvent const *e);
         virtual CQSTATE result(QEvent const *e);
         virtual CQSTATE begin(QEvent const *e);
      virtual CQSTATE negated1(QEvent const *e);
      virtual CQSTATE operand1(QEvent const *e);
         virtual CQSTATE zero1(QEvent const *e);
         virtual CQSTATE int1(QEvent const *e);
         virtual CQSTATE frac1(QEvent const *e);
      virtual CQSTATE opEntered(QEvent const *e);
      virtual CQSTATE negated2(QEvent const *e);
      virtual CQSTATE operand2(QEvent const *e);
         virtual CQSTATE zero2(QEvent const *e);
         virtual CQSTATE int2(QEvent const *e);
         virtual CQSTATE frac2(QEvent const *e);
   virtual CQSTATE final(QEvent const *e);
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
