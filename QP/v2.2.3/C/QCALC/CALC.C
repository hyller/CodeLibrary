/******************************************************************** 
 * Quantum Calculator example (C version)
 * (c) Copyright 2002, Miro Samek, Palo Alto, CA.
 * All Rights Reserved.
 *******************************************************************/
#include "qassert.h"
#include "calc.h"
#include "resource.h"

#include <string.h>
#include <commctrl.h>
#include <stdio.h>

DEFINE_THIS_FILE;

enum { PRECISION = 14 };

static HINSTANCE locHinst;                        /* this instance */
static HWND locHwnd;                              /* window handle */

/*.................................................................*/
Calc *CalcCtor(Calc *me) {
   if (!QHsmCtor_(&me->super_, (QPseudoState)Calc_initial)) {
      return 0;
   }
   return me;
}
/*.................................................................*/
void CalcXtor(Calc *me) {
   QHsmXtor_(&me->super_);
}
/*-----------------------------------------------------------------*/
void CalcClear_(Calc *me) {
    me->display_[0] = ' ';
    me->display_[1] = '0';
    me->display_[2] = '\0';
    me->ins_ = &me->display_[1];
    SetDlgItemText(me->hWnd_, IDC_DISPLAY, me->display_);
}
/*.................................................................*/
void CalcInsert_(Calc *me, int keyId) {
   if (me->ins_ < &me->display_[PRECISION - 1]) {
      *me->ins_++ = (keyId == IDC_POINT) ? '.' : keyId - IDC_0+'0';
      *me->ins_ = '\0';
      SetDlgItemText(me->hWnd_, IDC_DISPLAY, me->display_);
   }
}
/*.................................................................*/
void CalcNegate_(Calc *me) {
   me->display_[0] = '-';
   SetDlgItemText(me->hWnd_, IDC_DISPLAY, me->display_);
}
/*.................................................................*/
void CalcEvtval_(Calc *me) {
   double result;
   switch (me->operator_) {
   case IDC_PLUS:
      result = me->operand1_ + me->operand2_;
      break;
   case IDC_MINUS:
      result = me->operand1_ - me->operand2_;
      break;
   case IDC_MULT:
      result = me->operand1_ * me->operand2_;
      break;
   case IDC_DIVIDE:
      if (me->operand2_ != 0.0) {
         result = me->operand1_ / me->operand2_;
      }
      else {
         MessageBox(me->hWnd_, "Cannot Divide by 0", 
                    "Calulator", MB_OK);
         result = 0.0;
      } 
      break;
   }
   if (-1.0e10 < result && result < 1.0e10) {		
      sprintf(me->display_, "%24.11g", result);        
   }
   else {
      MessageBox(me->hWnd_, "Result out of range", 
                 "Calulator", MB_OK);
      CalcClear_(me);
   }
   SetDlgItemText(me->hWnd_, IDC_DISPLAY, me->display_);
}
/*.................................................................*/
void CalcDispState(Calc *me, char const *s) {
   SetDlgItemText(me->hWnd_, IDC_STATE, s);
}
/* HSM definition -------------------------------------------------*/
void Calc_initial(Calc *me, QEvent const *e) {
   CalcClear_(me);
   me->operand1_ = 0.0;
   me->operand2_ = 0.0;
   me->operator_ = 0;
   Q_INIT(Calc_calc);
}
/*.................................................................*/
QSTATE Calc_calc(Calc *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      CalcDispState(me, "calc"); 
      return 0;
   case Q_INIT_SIG:
      Q_INIT(Calc_ready);
      return 0;
   case IDC_C:
      CalcClear_(me);
      Q_TRAN(Calc_begin);
      return 0;
   case TERMINATE:
      EndDialog(me->hWnd_, 0);
      return 0;
   }
   if (e->sig >= Q_USER_SIG) {
      me->isHandled_ = FALSE;
   }
   return (QSTATE)QHsm_top;
}
/*.................................................................*/
QSTATE Calc_ready(Calc *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      CalcDispState(me, "ready"); 
      return 0;
   case Q_INIT_SIG:
      Q_INIT(Calc_begin);
      return 0;
   case IDC_0:
      CalcClear_(me);
      Q_TRAN(Calc_zero1);
      return 0;
   case IDC_1_9:
      CalcClear_(me);
      CalcInsert_(me, ((CalcEvt *)e)->keyId); 
      Q_TRAN(Calc_int1);
      return 0;  
   case IDC_POINT:
      CalcClear_(me);
      CalcInsert_(me, IDC_0);
      CalcInsert_(me, ((CalcEvt *)e)->keyId);
      Q_TRAN(Calc_frac1);
      return 0;
   case IDC_OPER:
      sscanf(me->display_, "%lf", &me->operand1_);
      me->operator_ = ((CalcEvt *)e)->keyId;
      Q_TRAN(Calc_opEntered);
      return 0;
   }
   return (QSTATE)Calc_calc;
}
/*.................................................................*/
QSTATE Calc_result(Calc *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      CalcDispState(me, "result"); 
      CalcEvtval_(me);
      return 0;
   }
   return (QSTATE)Calc_ready;
}
/*.................................................................*/
QSTATE Calc_begin(Calc *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      CalcDispState(me, "begin"); 
      return 0;
   case IDC_OPER:
      if (((CalcEvt *)e)->keyId == IDC_MINUS) {
         Q_TRAN(Calc_negated1);
         return 0;
      }
      else if (((CalcEvt *)e)->keyId == IDC_PLUS) {   /* unary "+" */
         return 0;                                /* event handled */
      }
      break;                                   /* event unhandled! */
   }
   return (QSTATE)Calc_ready;
}
/*.................................................................*/
QSTATE Calc_negated1(Calc *me, QEvent const *e) {
   switch (e->sig) {    
   case Q_ENTRY_SIG:
      CalcDispState(me, "negated1"); 
      CalcNegate_(me);
      return 0;
   case IDC_CE:
      CalcClear_(me);
      Q_TRAN(Calc_begin);
      return 0;
   case IDC_0:
      CalcInsert_(me, ((CalcEvt *)e)->keyId); 
      Q_TRAN(Calc_zero1);
      return 0;
   case IDC_1_9:
      CalcInsert_(me, ((CalcEvt *)e)->keyId); 
      Q_TRAN(Calc_int1);
      return 0;
   case IDC_POINT:
      CalcInsert_(me, ((CalcEvt *)e)->keyId); 
      Q_TRAN(Calc_frac1);
      return 0;
   }
   return (QSTATE)Calc_calc;
}
/*.................................................................*/
QSTATE Calc_negated2(Calc *me, QEvent const *e) {
   switch (e->sig) {    
   case Q_ENTRY_SIG:
      CalcDispState(me, "negated2"); 
      CalcNegate_(me);
      return 0;
   case IDC_CE:
      Q_TRAN(Calc_opEntered);
      return 0;
   case IDC_0:
      Q_TRAN(Calc_zero2);
      return 0;
   case IDC_1_9:
      CalcInsert_(me, ((CalcEvt *)e)->keyId); 
      Q_TRAN(Calc_int2);
      return 0;
   case IDC_POINT:
      CalcInsert_(me, ((CalcEvt *)e)->keyId); 
      Q_TRAN(Calc_frac2);
      return 0;
   }
   return (QSTATE)Calc_calc;
}
/*.................................................................*/
QSTATE Calc_operand1(Calc *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      CalcDispState(me, "operand1"); 
      return 0;
   case IDC_CE:
      CalcClear_(me);
      Q_TRAN(Calc_begin);
      return 0;
   case IDC_OPER:
      sscanf(me->display_, "%lf", &me->operand1_);
      me->operator_ = ((CalcEvt *)e)->keyId;
      Q_TRAN(Calc_opEntered);
      return 0;
   }
   return (QSTATE)Calc_calc;
}
/*.................................................................*/
QSTATE Calc_zero1(Calc *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      CalcDispState(me, "zero1"); 
      return 0;
   case IDC_1_9:
      CalcInsert_(me, ((CalcEvt *)e)->keyId); 
      Q_TRAN(Calc_int1);
      return 0;
   case IDC_POINT:
      CalcInsert_(me, ((CalcEvt *)e)->keyId);
      Q_TRAN(Calc_frac1);
      return 0;
   }
   return (QSTATE)Calc_operand1;
}
/*.................................................................*/
QSTATE Calc_int1(Calc *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      CalcDispState(me, "int1"); 
      return 0;
   case IDC_0:
   case IDC_1_9:
      CalcInsert_(me, ((CalcEvt *)e)->keyId); 
      return 0;
   case IDC_POINT:
      CalcInsert_(me, ((CalcEvt *)e)->keyId);
      Q_TRAN(Calc_frac1);
      return 0;
   }
   return (QSTATE)Calc_operand1;
}
/*.................................................................*/
QSTATE Calc_frac1(Calc *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      CalcDispState(me, "frac1"); 
      return 0;
   case IDC_0:
   case IDC_1_9:
      CalcInsert_(me, ((CalcEvt *)e)->keyId); 
      return 0;
   }
   return (QSTATE)Calc_operand1;
}
/*.................................................................*/
QSTATE Calc_opEntered(Calc *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      CalcDispState(me, "opEntered"); 
      return 0;
   case IDC_OPER:
      if (((CalcEvt *)e)->keyId == IDC_MINUS) {
         CalcClear_(me);
         Q_TRAN(Calc_negated2);
      }
      return 0;
   case IDC_0:
      CalcClear_(me);
      Q_TRAN(Calc_zero2);
      return 0;
   case IDC_1_9:
      CalcClear_(me);
      CalcInsert_(me, ((CalcEvt *)e)->keyId); 
      Q_TRAN(Calc_int2);
      return 0;
   case IDC_POINT:
      CalcClear_(me);
      CalcInsert_(me, IDC_0);
      CalcInsert_(me, ((CalcEvt *)e)->keyId); 
      Q_TRAN(Calc_frac2);
      return 0;
   }
   return (QSTATE)Calc_calc;
}
/*.................................................................*/
QSTATE Calc_operand2(Calc *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      CalcDispState(me, "operand2"); 
      return 0;
   case IDC_CE:
      CalcClear_(me);
      Q_TRAN(Calc_opEntered);
      return 0;
   case IDC_OPER:
      sscanf(me->display_, "%lf", &me->operand2_);
      CalcEvtval_(me);
      sscanf(me->display_, "%lf", &me->operand1_);
      me->operator_ = ((CalcEvt *)e)->keyId;
      Q_TRAN(Calc_opEntered);
      return 0;
   case IDC_EQUALS:
      sscanf(me->display_, "%lf", &me->operand2_);
      Q_TRAN(Calc_result);
      return 0;
   }
   return (QSTATE)Calc_calc;
}
/*.................................................................*/
QSTATE Calc_zero2(Calc *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      CalcDispState(me, "zero2"); 
      return 0;
   case IDC_1_9:
      CalcInsert_(me, ((CalcEvt *)e)->keyId); 
      Q_TRAN(Calc_int2);
      return 0;
   case IDC_POINT:
      CalcInsert_(me, ((CalcEvt *)e)->keyId);
      Q_TRAN(Calc_frac2);
      return 0;
   }
   return (QSTATE)Calc_operand2;
}
/*.................................................................*/
QSTATE Calc_int2(Calc *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      CalcDispState(me, "int2"); 
      return 0;
   case IDC_0:
   case IDC_1_9:
      CalcInsert_(me, ((CalcEvt *)e)->keyId); 
      return 0;
   case IDC_POINT:
      CalcInsert_(me, ((CalcEvt *)e)->keyId);
      Q_TRAN(Calc_frac2);
      return 0;
   }
   return (QSTATE)Calc_operand2;
}
/*.................................................................*/
QSTATE Calc_frac2(Calc *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      CalcDispState(me, "frac2"); 
      return 0;
   case IDC_0:
   case IDC_1_9:
      CalcInsert_(me, ((CalcEvt *)e)->keyId); 
      return 0;
   }
   return (QSTATE)Calc_operand2;
}
/*=================================================================*/
void onAssert__(char const *file, unsigned line) {
   char str[160];
   sprintf(str, "Assertion failed in %s, line %d", file, line);        
   MessageBox(locHwnd, str, "Calulator", MB_OK);
   exit(-1);
}
/*.................................................................*/
BOOL CALLBACK DlgProc(HWND hwnd, UINT iMsg, 
                      WPARAM wParam, LPARAM lParam)
{
   CalcEvt e;
   switch (iMsg) {
   case WM_INITDIALOG:
      CalcInstance()->hWnd_ = locHwnd = hwnd;
      SendMessage(hwnd, WM_SETICON, (WPARAM)TRUE, 
                (LPARAM)LoadIcon(locHinst, MAKEINTRESOURCE(IDI_QP)));
      QHsmInit((QHsm *)CalcInstance(), 0);
      return TRUE;
   case WM_COMMAND:
      switch (e.keyId = LOWORD(wParam)) {
      case IDCANCEL:
         e.super_.sig = TERMINATE;
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
         e.super_.sig = IDC_1_9;
         break;
      case IDC_PLUS:
      case IDC_MINUS:
      case IDC_MULT:
      case IDC_DIVIDE:
         e.super_.sig = IDC_OPER;
         break;
      default:
         e.super_.sig = e.keyId;
         break; 
      }
      CalcInstance()->isHandled_ = TRUE;
      QHsmDispatch((QHsm *)CalcInstance(), (QEvent *)&e);
      return CalcInstance()->isHandled_;
   }
   return FALSE;
}
/*.................................................................*/
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst,
                   PSTR cmdLine, int iCmdShow)
{
    InitCommonControls();          /* load common controls library */
    locHinst = hInst;                     /* store instance handle */
    DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG), NULL, 
              DlgProc);                  
    return 0;          /* exit application when the dialog returns */
}

