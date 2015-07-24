/******************************************************************** 
 * Quantum Calc1ulator example ("C+" version)
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA.
 * All Rights Reserved.
 *******************************************************************/
#include "qassert.h"
#include "calc1.h"
#include "resource.h"

#include <string.h>
#include <commctrl.h>
#include <stdio.h>

DEFINE_THIS_FILE;

enum { PRECISION = 14 };

static HWND locHwnd;                              /* window handle */
static HINSTANCE locHinst;                        /* this instance */

/*.................................................................*/
BEGIN_VTABLE(Calc1, QHsm)
   VMETHOD(Object, xtor) = (void (*)(Object *))Calc1Xtor;
   VMETHOD(Calc1, calc) = Calc1_calc;
   VMETHOD(Calc1, ready) = Calc1_ready;
   VMETHOD(Calc1, result) = Calc1_result;
   VMETHOD(Calc1, begin) = Calc1_begin;
   VMETHOD(Calc1, negated1) = Calc1_negated1;
   VMETHOD(Calc1, operand1) = Calc1_operand1;
   VMETHOD(Calc1, zero1) = Calc1_zero1;
   VMETHOD(Calc1, int1) = Calc1_int1;
   VMETHOD(Calc1, frac1) = Calc1_frac1;
   VMETHOD(Calc1, opEntered) = Calc1_opEntered;
   VMETHOD(Calc1, negated2) = Calc1_negated2;
   VMETHOD(Calc1, operand2) = Calc1_operand2;
   VMETHOD(Calc1, zero2) = Calc1_zero2;
   VMETHOD(Calc1, int2) = Calc1_int2;
   VMETHOD(Calc1, frac2) = Calc1_frac2;

   VMETHOD(Calc1, clear_) = Calc1Clear_;
   VMETHOD(Calc1, insert_) = Calc1Insert_;
   VMETHOD(Calc1, negate_) = Calc1Negate_;
   VMETHOD(Calc1, eval_) = Calc1Eval_;
END_VTABLE
/*.................................................................*/
Calc1 *Calc1Ctor_(Calc1 *me) {
   if (!QHsmCtor_(&me->super_, (QPseudoState)Calc1_initial)) {
      return 0;
   }
   VHOOK(Calc1);
   return me;
}
/*.................................................................*/
void Calc1Xtor(Calc1 *me) {
   QHsmXtor_(&me->super_);
}
/*-----------------------------------------------------------------*/
void Calc1Clear_(Calc1 *me) {
    me->display_[0] = ' ';
    me->display_[1] = '0';
    me->display_[2] = '\0';
    me->ins_ = &me->display_[1];
    SetDlgItemText(me->hWnd_, IDC_DISPLAY, me->display_);
}
/*.................................................................*/
void Calc1Insert_(Calc1 *me, int keyId) {
   if (me->ins_ < &me->display_[PRECISION - 1]) {
      *me->ins_++ = (keyId == IDC_POINT) ? '.' : keyId - IDC_0+'0';
      *me->ins_ = '\0';
      SetDlgItemText(me->hWnd_, IDC_DISPLAY, me->display_);
   }
}
/*.................................................................*/
void Calc1Negate_(Calc1 *me) {
   me->display_[0] = '-';
   SetDlgItemText(me->hWnd_, IDC_DISPLAY, me->display_);
}
/*.................................................................*/
void Calc1Eval_(Calc1 *me) {
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
      Calc1Clear_(me);
   }
   SetDlgItemText(me->hWnd_, IDC_DISPLAY, me->display_);
}
/*.................................................................*/
static Calc1DispState(Calc1 *me, const char *s) {
   SetDlgItemText(me->hWnd_, IDC_STATE, s);
}
/* HSM definition -------------------------------------------------*/
void Calc1_initial(Calc1 *me, QEvent const *e) {
   VCALL(Calc1, clear_, me)END_CALL;
   me->operand1_ = 0.0;
   me->operand2_ = 0.0;
   me->operator_ = 0;
   Q_INIT(VPTR(Calc1, me)->calc);
}
/*.................................................................*/
QSTATE Calc1_calc(Calc1 *me, QEvent const *e) {
   me->isHandled_ = TRUE;
   switch (e->sig) {
   case Q_ENTRY_SIG:
      Calc1DispState(me, "calc"); 
      return 0;
   case Q_INIT_SIG:
      Q_INIT(VPTR(Calc1, me)->ready);
      return 0;
   case IDC_C:
      VCALL(Calc1, clear_, me)END_CALL;
      Q_TRAN(VPTR(Calc1, me)->calc);
      return 0;
   case TERMINATE:
      EndDialog(me->hWnd_, 0);
      return 0;
   }
   me->isHandled_ = FALSE;
   return (QSTATE)QHsm_top;
}
/*.................................................................*/
QSTATE Calc1_ready(Calc1 *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      Calc1DispState(me, "ready"); 
      return 0;
   case Q_INIT_SIG:
      Q_INIT(VPTR(Calc1, me)->begin);
      return 0;
   case IDC_0:
      VCALL(Calc1, clear_, me)END_CALL;
      Q_TRAN(VPTR(Calc1, me)->zero1);
      return 0;
   case IDC_1_9:
      VCALL(Calc1, clear_, me)END_CALL;
      VCALL(Calc1, insert_, me), ((CalcEvt *)e)->keyId END_CALL;
      Q_TRAN(VPTR(Calc1, me)->int1);
      return 0;  
   case IDC_POINT:
      VCALL(Calc1, clear_, me)END_CALL;
      VCALL(Calc1, insert_, me), IDC_0 END_CALL;
      VCALL(Calc1, insert_, me), ((CalcEvt *)e)->keyId END_CALL;
      Q_TRAN(VPTR(Calc1, me)->frac1);
      return 0;
   case IDC_OPER:
      sscanf(me->display_, "%lf", &me->operand1_);
      me->operator_ = ((CalcEvt *)e)->keyId;
      Q_TRAN(VPTR(Calc1, me)->opEntered);
      return 0;
   }
   return (QSTATE)VPTR(Calc1, me)->calc;
}
/*.................................................................*/
QSTATE Calc1_result(Calc1 *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      Calc1DispState(me, "result"); 
      VCALL(Calc1, eval_, me)END_CALL;
      return 0;
   }
   return (QSTATE)VPTR(Calc1, me)->ready;
}
/*.................................................................*/
QSTATE Calc1_begin(Calc1 *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      Calc1DispState(me, "begin"); 
      return 0;
   case IDC_OPER:
      if (((CalcEvt *)e)->keyId == IDC_MINUS) {
         Q_TRAN(Calc1_negated1);
         return 0;
      }
      else if (((CalcEvt *)e)->keyId == IDC_PLUS) {   /* unary "+" */
         return 0;                                /* event handled */
      }
      break;                                   /* event unhandled! */
   }
   return (QSTATE)VPTR(Calc1, me)->ready;
}
/*.................................................................*/
QSTATE Calc1_negated1(Calc1 *me, QEvent const *e) {
   switch (e->sig) {    
   case Q_ENTRY_SIG:
      Calc1DispState(me, "negated1"); 
      VCALL(Calc1, negate_, me)END_CALL;
      return 0;
   case IDC_CE:
      VCALL(Calc1, clear_, me)END_CALL;
      Q_TRAN(VPTR(Calc1, me)->begin);
      return 0;
   case IDC_0:
      VCALL(Calc1, insert_, me), ((CalcEvt *)e)->keyId END_CALL;
      Q_TRAN(VPTR(Calc1, me)->zero1);
      return 0;
   case IDC_1_9:
      VCALL(Calc1, insert_, me), ((CalcEvt *)e)->keyId END_CALL;
      Q_TRAN(VPTR(Calc1, me)->int1);
      return 0;
   case IDC_POINT:
      VCALL(Calc1, insert_, me), ((CalcEvt *)e)->keyId END_CALL;
      Q_TRAN(VPTR(Calc1, me)->frac1);
      return 0;
   }
   return (QSTATE)VPTR(Calc1, me)->calc;
}
/*.................................................................*/
QSTATE Calc1_negated2(Calc1 *me, QEvent const *e) {
   switch (e->sig) {    
   case Q_ENTRY_SIG:
      Calc1DispState(me, "negated2"); 
      VCALL(Calc1, negate_, me)END_CALL;
      return 0;
   case IDC_CE:
      Q_TRAN(VPTR(Calc1, me)->opEntered);
      return 0;
   case IDC_0:
      Q_TRAN(VPTR(Calc1, me)->zero2);
      return 0;
   case IDC_1_9:
      VCALL(Calc1, insert_, me), ((CalcEvt *)e)->keyId END_CALL;
      Q_TRAN(VPTR(Calc1, me)->int2);
      return 0;
   case IDC_POINT:
      VCALL(Calc1, insert_, me), ((CalcEvt *)e)->keyId END_CALL;
      Q_TRAN(VPTR(Calc1, me)->frac2);
      return 0;
   }
   return (QSTATE)VPTR(Calc1, me)->calc;
}
/*.................................................................*/
QSTATE Calc1_operand1(Calc1 *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      Calc1DispState(me, "operand1"); 
      return 0;
   case IDC_CE:
      VCALL(Calc1, clear_, me)END_CALL;
      Q_TRAN(VPTR(Calc1, me)->begin);
      return 0;
   case IDC_OPER:
      sscanf(me->display_, "%lf", &me->operand1_);
      me->operator_ = ((CalcEvt *)e)->keyId;
      Q_TRAN(VPTR(Calc1, me)->opEntered);
      return 0;
   }
   return (QSTATE)VPTR(Calc1, me)->calc;
}
/*.................................................................*/
QSTATE Calc1_zero1(Calc1 *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      Calc1DispState(me, "zero1"); 
      return 0;
   case IDC_1_9:
      VCALL(Calc1, insert_, me), ((CalcEvt *)e)->keyId END_CALL;
      Q_TRAN(VPTR(Calc1, me)->int1);
      return 0;
   case IDC_POINT:
      VCALL(Calc1, insert_, me), ((CalcEvt *)e)->keyId END_CALL;
      Q_TRAN(VPTR(Calc1, me)->frac1);
      return 0;
   }
   return (QSTATE)VPTR(Calc1, me)->operand1;
}
/*.................................................................*/
QSTATE Calc1_int1(Calc1 *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      Calc1DispState(me, "int1"); 
      return 0;
   case IDC_0:
   case IDC_1_9:
      VCALL(Calc1, insert_, me), ((CalcEvt *)e)->keyId END_CALL;
      return 0;
   case IDC_POINT:
      VCALL(Calc1, insert_, me), ((CalcEvt *)e)->keyId END_CALL;
      Q_TRAN(VPTR(Calc1, me)->frac1);
      return 0;
   }
   return (QSTATE)VPTR(Calc1, me)->operand1;
}
/*.................................................................*/
QSTATE Calc1_frac1(Calc1 *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      Calc1DispState(me, "frac1"); 
      return 0;
   case IDC_0:
   case IDC_1_9:
      VCALL(Calc1, insert_, me), ((CalcEvt *)e)->keyId END_CALL;
      return 0;
   }
   return (QSTATE)VPTR(Calc1, me)->operand1;
}
/*.................................................................*/
QSTATE Calc1_opEntered(Calc1 *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      Calc1DispState(me, "opEntered"); 
      return 0;
   case IDC_OPER:
      if (((CalcEvt *)e)->keyId == IDC_MINUS) {
         VCALL(Calc1, clear_, me)END_CALL;
         Q_TRAN(VPTR(Calc1, me)->negated2);
      }
      return 0;
   case IDC_0:
      VCALL(Calc1, clear_, me)END_CALL;
      Q_TRAN(VPTR(Calc1, me)->zero2);
      return 0;
   case IDC_1_9:
      VCALL(Calc1, clear_, me)END_CALL;
      VCALL(Calc1, insert_, me), ((CalcEvt *)e)->keyId END_CALL;
      Q_TRAN(VPTR(Calc1, me)->int2);
      return 0;
   case IDC_POINT:
      VCALL(Calc1, clear_, me)END_CALL;
      VCALL(Calc1, insert_, me), IDC_0 END_CALL;
      VCALL(Calc1, insert_, me), ((CalcEvt *)e)->keyId END_CALL;
      Q_TRAN(VPTR(Calc1, me)->frac2);
      return 0;
   }
   return (QSTATE)VPTR(Calc1, me)->calc;
}
/*.................................................................*/
QSTATE Calc1_operand2(Calc1 *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      Calc1DispState(me, "operand2"); 
      return 0;
   case IDC_CE:
      VCALL(Calc1, clear_, me)END_CALL;
      Q_TRAN(VPTR(Calc1, me)->opEntered);
      return 0;
   case IDC_OPER:
      sscanf(me->display_, "%lf", &me->operand2_);
      Calc1Eval_(me);
      sscanf(me->display_, "%lf", &me->operand1_);
      me->operator_ = ((CalcEvt *)e)->keyId;
      Q_TRAN(VPTR(Calc1, me)->opEntered);
      return 0;
   case IDC_EQUALS:
      sscanf(me->display_, "%lf", &me->operand2_);
      Q_TRAN(VPTR(Calc1, me)->result);
      return 0;
   }
   return (QSTATE)VPTR(Calc1, me)->calc;
}
/*.................................................................*/
QSTATE Calc1_zero2(Calc1 *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      Calc1DispState(me, "zero2"); 
      return 0;
   case IDC_1_9:
      VCALL(Calc1, insert_, me), ((CalcEvt *)e)->keyId END_CALL;
      Q_TRAN(VPTR(Calc1, me)->int2);
      return 0;
   case IDC_POINT:
      VCALL(Calc1, insert_, me), ((CalcEvt *)e)->keyId END_CALL;
      Q_TRAN(VPTR(Calc1, me)->frac2);
      return 0;
   }
   return (QSTATE)VPTR(Calc1, me)->operand2;
}
/*.................................................................*/
QSTATE Calc1_int2(Calc1 *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      Calc1DispState(me, "int2"); 
      return 0;
   case IDC_0:
   case IDC_1_9:
      VCALL(Calc1, insert_, me), ((CalcEvt *)e)->keyId END_CALL;
      return 0;
   case IDC_POINT:
      VCALL(Calc1, insert_, me), ((CalcEvt *)e)->keyId END_CALL;
      Q_TRAN(VPTR(Calc1, me)->frac2);
      return 0;
   }
   return (QSTATE)VPTR(Calc1, me)->operand2;
}
/*.................................................................*/
QSTATE Calc1_frac2(Calc1 *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      Calc1DispState(me, "frac2"); 
      return 0;
   case IDC_0:
   case IDC_1_9:
      VCALL(Calc1, insert_, me), ((CalcEvt *)e)->keyId END_CALL;
      return 0;
   }
   return (QSTATE)VPTR(Calc1, me)->operand2;
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
      Calc1Instance()->hWnd_ = locHwnd = hwnd;
      SendMessage(hwnd, WM_SETICON, (WPARAM)TRUE, 
                (LPARAM)LoadIcon(locHinst, MAKEINTRESOURCE(IDI_QP)));
      QHsmInit((QHsm *)Calc1Instance(), 0);
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
      Calc1Instance()->isHandled_ = TRUE;
      QHsmDispatch((QHsm *)Calc1Instance(), (QEvent *)&e);
      return Calc1Instance()->isHandled_;
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

