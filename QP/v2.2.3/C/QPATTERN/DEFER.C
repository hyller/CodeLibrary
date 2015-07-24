/********************************************************************
 * QP defer.c -- Deferred Event state pattern example
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
 * All Rights Reserved.
 *******************************************************************/
#include <windows.h>
#include <string.h>
#include <commctrl.h>
#include <stdio.h>

#include "qf_win32.h"
#include "qassert.h"
#include "defer.h"                              /* defer resources */

DEFINE_THIS_FILE;

/*.................................................................*/
SUBCLASS(TServer, QHsm)
   QEvent deferredRequest__;
   BOOL isHandled__;
   HWND hWnd__;
METHODS
   TServer *TServerCtor(TServer *me);
   void TServer_initial(TServer *me, QEvent const *e);
   QSTATE TServer_operational(TServer *me, QEvent const *e);
      QSTATE TServer_idle(TServer *me, QEvent const *e);
      QSTATE TServer_receiving(TServer *me, QEvent const *e);
      QSTATE TServer_authorizing(TServer *me, QEvent const *e);
   QSTATE TServer_final(TServer *me, QEvent const *e);

   BOOL TServer_defer(TServer *me, QEvent const *e);/* defer event */
   void TServer_recall(TServer *me);     /* recall deferred events */
END_CLASS
/*.................................................................*/
enum TServerSignals {
   TERMINATE = Q_USER_SIG
}; 
/*-----------------------------------------------------------------*/
static TServer app;
static HINSTANCE inst;                            /* this instance */
static HWND mainHwnd;                           /* the main window */
static char appName[] = "TServer";

/*.................................................................*/
TServer *TServerCtor(TServer *me) {
   QHsmCtor_(&me->super_, (QPseudoState)&TServer_initial); 
   return me;
}
/*.................................................................*/
BOOL TServer_defer(TServer *me, QEvent const *e) {
   if (IsDlgButtonChecked(me->hWnd__, IDC_DEFERRED)) { /* deferred?*/
      return FALSE;                /* cannot defer any more events */
   } 
   me->deferredRequest__ = *e;   /* save the event (copy by value) */
   CheckDlgButton(me->hWnd__, IDC_DEFERRED, BST_CHECKED);
   return TRUE;
}
/*.................................................................*/
void TServer_recall(TServer *me) {
   if (IsDlgButtonChecked(me->hWnd__, IDC_DEFERRED)) { /* deferred?*/
      PostMessage(me->hWnd__, WM_COMMAND, 
                  me->deferredRequest__.sig, 0);
      CheckDlgButton(me->hWnd__, IDC_DEFERRED, BST_UNCHECKED);
   }
}

/* HSM definition -------------------------------------------------*/
void TServer_initial(TServer *me, QEvent const *e) {
   SendMessage(me->hWnd__, WM_SETICON, (WPARAM)TRUE, 
               (LPARAM)LoadIcon(inst, MAKEINTRESOURCE(IDI_QP)));
   Q_INIT(&TServer_operational);
}
/*.................................................................*/
QSTATE TServer_final(TServer *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      EndDialog(me->hWnd__, 0);
      return 0;
   }
   return (QSTATE)&QHsm_top;
}
/*.................................................................*/
QSTATE TServer_operational(TServer *me, QEvent const *e) {
   switch (e->sig) {
   case Q_INIT_SIG:
      Q_INIT(&TServer_idle);
      return 0;
   case IDC_NEW:
      if (!TServer_defer(me, e)) {                /* cannot defer? */
         Beep(1000, 20);                          /* warn the user */
      }
      return 0;
   case TERMINATE:
      Q_TRAN(&TServer_final);
      return 0;
   }
   if (e->sig >= Q_USER_SIG) {
      me->isHandled__ = FALSE;
   }
   return (QSTATE)&QHsm_top;
}
/*.................................................................*/
QSTATE TServer_idle(TServer *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      SetDlgItemText(me->hWnd__, IDC_STATE, "idle");
      TServer_recall(me);
      return 0;
   case IDC_NEW:
      Q_TRAN(&TServer_receiving);
      return 0;
   }
   return (QSTATE)&TServer_operational;
}
/*.................................................................*/
QSTATE TServer_receiving(TServer *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      SetDlgItemText(me->hWnd__, IDC_STATE, "receiving");
      SetTimer(me->hWnd__, 1, 1000, 0); /*schedule timeout in 1 sec*/
      return 0;
   case WM_TIMER:
      Q_TRAN(&TServer_authorizing);
      return 0;
   case Q_EXIT_SIG:
      KillTimer(me->hWnd__, 1);
      return 0;
   }
   return (QSTATE)&TServer_operational;
}
/*.................................................................*/
QSTATE TServer_authorizing(TServer *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      SetDlgItemText(me->hWnd__, IDC_STATE, "authorizing");
      SetTimer(me->hWnd__, 1, 2000, 0); /*schedule timeout in 2 sec*/
      return 0;
   case WM_TIMER:
      Q_TRAN(&TServer_idle);
      return 0;
   case Q_EXIT_SIG:
      KillTimer(me->hWnd__, 1);
      return 0;
   }
   return (QSTATE)&TServer_operational;
}
/*.................................................................*/
void onAssert__(char const *file, unsigned line) {
   char str[160];
   sprintf(str, "Assertion failed in %s, line %d", file, line);        
   MessageBox(mainHwnd, str, appName, MB_ICONEXCLAMATION | MB_OK);
   exit(-1);
}
/*-----------------------------------------------------------------*/
BOOL CALLBACK TServerDlg(HWND hwnd, UINT iMsg, 
                                   WPARAM wParam, LPARAM lParam)
{
   QEvent e;
   e.sig = iMsg;
   switch (iMsg) {
   case WM_INITDIALOG:
      app.hWnd__ = mainHwnd = hwnd;
      QHsmInit((QHsm *)&app, 0);    /* take the initial transition */
      return TRUE;
   case WM_COMMAND:
      switch (LOWORD(wParam)) {
      case IDCANCEL:
         e.sig = TERMINATE;
         break;
      default:
          e.sig = LOWORD(wParam);
          break;
      }
      /* intentionally fall thru */
   case WM_TIMER:
      app.isHandled__ = TRUE;
      QHsmDispatch((QHsm *)&app, &e);
      return app.isHandled__;
   }
   return FALSE;
}
/*.................................................................*/
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst,
                   PSTR cmdLine, int iCmdShow)
{
   InitCommonControls();           /* load common controls library */
   inst = hInst;                          /* store instance handle */
   TServerCtor(&app);         /* construct the TServer application */
   DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG), NULL, TServerDlg);                  
   return 0;           /* exit application when the dialog returns */
}

