/////////////////////////////////////////////////////////////////////
// Quantum Calculator example
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#include "qassert.h"
#include "calc2.h"
#include "resource.h"

#include <string.h>
#include <commctrl.h>
#include <stdio.h>

DEFINE_THIS_FILE;

QHsm::CQSTATE Calc2::operand2(QEvent const *e) {
   switch (e->sig) {
   case IDC_PERCENT:
      sscanf(myDisplay, "%lf", &myOperand2);
      switch (myOperator) {
      case IDC_PLUS:
         myOperand2 = 1.0 + myOperand2/100.0;       // x*(1 + y%)
         myOperator = IDC_MULT;
         break;
      case IDC_MINUS:
         myOperand2 = 1.0 - myOperand2/100.0;       // x*(1 - y%)
         myOperator = IDC_MULT;
         break;
      case IDC_MULT:                 // intentionally fall thru...
      case IDC_DIVIDE:
         myOperand2 /= 100.0;                       // x*y%, x/y%
         break;
      default:
         ASSERT(0);
      }
      Q_TRAN(&Calc2::result);
      return 0;                                  // event handled
   }
   return Calc1::operand2(e);    // let Calc1 handle other events
}
