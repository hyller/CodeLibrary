/////////////////////////////////////////////////////////////////////
// Quantum Calculator example (C++ version)
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#include "qassert.h"
#include "calc0.h"
#include "resource.h"

#include <string.h>
#include <commctrl.h>
#include <stdio.h>

DEFINE_THIS_FILE;

enum { PRECISION = 14 };

static HINSTANCE locHinst;                           // this instance
static HWND locHwnd;                                 // window handle

//-------------------------------------------------------------------
void Calc0::clear() {
    myDisplay[0] = ' ';
    myDisplay[1] = '0';
    myDisplay[2] = '\0';
    myIns = &myDisplay[1];
    SetDlgItemText(myHwnd, IDC_DISPLAY, myDisplay);
}
//...................................................................
void Calc0::insert(int keyId) {
   if (myIns < &myDisplay[PRECISION - 1]) {
      *myIns++ = (keyId == IDC_POINT) ? '.' : keyId - IDC_0 + '0';
      *myIns = '\0';
      SetDlgItemText(myHwnd, IDC_DISPLAY, myDisplay);
   }
}
//...................................................................
void Calc0::negate() {
   myDisplay[0] = '-';
   SetDlgItemText(myHwnd, IDC_DISPLAY, myDisplay);
}
//...................................................................
void Calc0::eval() {
   double r;
   switch (myOperator) {
   case IDC_PLUS:
      r = myOperand1 + myOperand2;
      break;
   case IDC_MINUS:
      r = myOperand1 - myOperand2;
      break;
   case IDC_MULT:
      r = myOperand1 * myOperand2;
      break;
   case IDC_DIVIDE:
      if (myOperand2 != 0.0) {
         r = myOperand1 / myOperand2;
      }
      else {
         MessageBox(myHwnd, "Cannot Divide by 0", 
                    "Calculator", MB_OK);
         r = 0.0;
      } 
      break;
   default:
      ASSERT(0);
   }
   if (-1.0e10 < r && r < 1.0e10) {		
      sprintf(myDisplay, "%24.11g", r);        
   }
   else {
      MessageBox(myHwnd, "Result out of range", 
                 "Calculator", MB_OK);
      clear();
   }
   SetDlgItemText(myHwnd, IDC_DISPLAY, myDisplay);
}
//...................................................................
void Calc0::dispState(char const *s) {
   SetDlgItemText(myHwnd, IDC_STATE, s);
}
// HSM definition ---------------------------------------------------
void Calc0::initial(QEvent const *) {
   Q_INIT(&Calc0::calc);
}
//...................................................................
QSTATE Calc0::final(QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      EndDialog(myHwnd, 0);
      return 0;
   }
   return (QSTATE)&Calc0::top;
}
//...................................................................
QSTATE Calc0::calc(QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      dispState("calc");
      return 0;
   case Q_INIT_SIG:
      clear();
      Q_INIT(&Calc0::operand1);
      return 0;
   case IDC_C:
      clear();
      Q_TRAN(&Calc0::calc);
      return 0;
   case TERMINATE:
      Q_TRAN(&Calc0::final);
      return 0;
   }
   if (e->sig >= Q_USER_SIG) {
      isHandled = FALSE;
   }
   return (QSTATE)&Calc0::top;
}
//...................................................................
QSTATE Calc0::result(QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      dispState("result");
      eval();
      return 0;
   case IDC_OPER:
      sscanf(myDisplay, "%lf", &myOperand1);
      myOperator = ((CalcEvt *)e)->keyId;
      Q_TRAN(&Calc0::opEntered);
      return 0;
   case IDC_0:
      clear();
      Q_TRAN(&Calc0::zero1);
      return 0;
   case IDC_1_9:
      clear();
      insert(((CalcEvt *)e)->keyId); 
      Q_TRAN(&Calc0::int1);
      return 0;  
   case IDC_POINT:
      clear();
      insert(IDC_0);
      insert(((CalcEvt *)e)->keyId);
      Q_TRAN(&Calc0::frac1);
      return 0;
   }
   return (QSTATE)&Calc0::calc;
}
//...................................................................
QSTATE Calc0::operand1(QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      dispState("operand1");
      return 0;
   case Q_INIT_SIG:
      Q_INIT(&Calc0::zero1);
      return 0;
   case IDC_OPER:
      sscanf(myDisplay, "%lf", &myOperand1);
      myOperator = ((CalcEvt *)e)->keyId;
      Q_TRAN(&Calc0::opEntered);
      return 0;
   }
   return (QSTATE)&Calc0::calc;
}
//...................................................................
QSTATE Calc0::zero1(QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      dispState("zero1");
      return 0;
   case IDC_1_9:
      insert(((CalcEvt *)e)->keyId); 
      Q_TRAN(&Calc0::int1);
      return 0;
   case IDC_POINT:
      insert(((CalcEvt *)e)->keyId);
      Q_TRAN(&Calc0::frac1);
      return 0;
   }
   return (QSTATE)&Calc0::operand1;
}
//...................................................................
QSTATE Calc0::int1(QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      dispState("int1");
      return 0;
   case IDC_0:
   case IDC_1_9:
      insert(((CalcEvt *)e)->keyId); 
      return 0;
   case IDC_POINT:
      insert(((CalcEvt *)e)->keyId);
      Q_TRAN(&Calc0::frac1);
      return 0;
   }
   return (QSTATE)&Calc0::operand1;
}
//...................................................................
QSTATE Calc0::frac1(QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      dispState("frac1");
      return 0;
   case IDC_0:
   case IDC_1_9:
      insert(((CalcEvt *)e)->keyId); 
      return 0;
   }
   return (QSTATE)&Calc0::operand1;
}
//...................................................................
QSTATE Calc0::opEntered(QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      dispState("opEntered");
      return 0;
   case IDC_0:
      clear();
      Q_TRAN(&Calc0::zero2);
      return 0;
   case IDC_1_9:
      clear();
      insert(((CalcEvt *)e)->keyId); 
      Q_TRAN(&Calc0::int2);
      return 0;
   case IDC_POINT:
      clear();
      insert(IDC_0);
      insert(((CalcEvt *)e)->keyId); 
      Q_TRAN(&Calc0::frac2);
      return 0;
   }
   return (QSTATE)&Calc0::calc;
}
//...................................................................
QSTATE Calc0::operand2(QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      dispState("operand2");
      return 0;
   case IDC_OPER:
      sscanf(myDisplay, "%lf", &myOperand2);
      eval();
      sscanf(myDisplay, "%lf", &myOperand1);
      myOperator = ((CalcEvt *)e)->keyId;
      Q_TRAN(&Calc0::opEntered);
      return 0;
   case IDC_EQUALS:
      sscanf(myDisplay, "%lf", &myOperand2);
      Q_TRAN(&Calc0::result);
      return 0;
   }
   return (QSTATE)&Calc0::calc;
}
//...................................................................
QSTATE Calc0::zero2(QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      dispState("zero2");
      return 0;
   case IDC_1_9:
      insert(((CalcEvt *)e)->keyId); 
      Q_TRAN(&Calc0::int2);
      return 0;
   case IDC_POINT:
      insert(((CalcEvt *)e)->keyId);
      Q_TRAN(&Calc0::frac2);
      return 0;
   }
   return (QSTATE)&Calc0::operand2;
}
//...................................................................
QSTATE Calc0::int2(QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      dispState("int2");
      return 0;
   case IDC_0:
   case IDC_1_9:
      insert(((CalcEvt *)e)->keyId); 
      return 0;
   case IDC_POINT:
      insert(((CalcEvt *)e)->keyId);
      Q_TRAN(&Calc0::frac2);
      return 0;
   }
   return (QSTATE)&Calc0::operand2;
}
//...................................................................
QSTATE Calc0::frac2(QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      dispState("frac2");
      return 0;
   case IDC_0:
   case IDC_1_9:
      insert(((CalcEvt *)e)->keyId); 
      return 0;
   }
   return (QSTATE)&Calc0::operand2;
}
//===================================================================
extern "C" void onAssert__(char const *file, unsigned line) {
   char str[160];
   sprintf(str, "Assertion failed in %s, line %d", file, line);        
   MessageBox(locHwnd, str, "Calulator", MB_OK);
   exit(-1);
}
//...................................................................
BOOL CALLBACK calcDlg(HWND hwnd, UINT iMsg, 
                      WPARAM wParam, LPARAM lParam)
{
   CalcEvt e;
   switch (iMsg) {
   case WM_INITDIALOG:
      Calc0::instance()->myHwnd = locHwnd = hwnd;
      SendMessage(hwnd, WM_SETICON, (WPARAM)TRUE, 
                (LPARAM)LoadIcon(locHinst, MAKEINTRESOURCE(IDI_QP)));
      Calc0::instance()->init();        // take the initial transition
      return TRUE;
   case WM_COMMAND:
      switch (e.keyId = LOWORD(wParam)) {
      case IDCANCEL:
         e.sig = TERMINATE;
         break;
      case IDC_1:
      case IDC_2:
      case IDC_3:
      case IDC_4:
      case IDC_5:
      case IDC_6:
      case IDC_7:
      case IDC_8:
      case IDC_9:
         e.sig = IDC_1_9;
         break;
      case IDC_PLUS:
      case IDC_MINUS:
      case IDC_MULT:
      case IDC_DIVIDE:
         e.sig = IDC_OPER;
         break;
      default:
         e.sig = e.keyId;
         break; 
      }
      Calc0::instance()->isHandled = TRUE;
      Calc0::instance()->dispatch(&e);          // take one RTC step
      return Calc0::instance()->isHandled;
   }
   return FALSE;
}
//...................................................................
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst,
                   PSTR cmdLine, int iCmdShow)
{
    InitCommonControls();             // load common controls library
    locHinst = hInst;                        // store instance handle
    DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG), NULL, calcDlg);                  
    return 0;             // exit application when the dialog returns
}

