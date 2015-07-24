/////////////////////////////////////////////////////////////////////
// QP defer.cpp -- Deferred Event state pattern example
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#include <windows.h>
#include <string.h>
#include <commctrl.h>
#include <stdio.h>

#include "qf_win32.h"
#include "qassert.h"
#include "defer.h"                                 // defer resources

DEFINE_THIS_FILE;

//...................................................................
class TServer : public QHsm {
public:
   TServer() : QHsm((QPseudoState)initial) {}
private:
   void initial(QEvent const *e);
   QSTATE operational(QEvent const *e);
      QSTATE idle(QEvent const *e);
      QSTATE receiving(QEvent const *e);
      QSTATE authorizing(QEvent const *e);
   QSTATE final(QEvent const *e);

   BOOL defer(QEvent const *e);                        // defer event
   void recall();                           // recall deferred events
private:
   QEvent myDeferredRequest;
   BOOL isHandled;
   HWND myHwnd;                          // the main window handle
   friend BOOL CALLBACK tServerDlg(HWND hwnd, UINT iEvt, 
                                   WPARAM wParam, LPARAM lParam);
};
//...................................................................
enum TServerSignals {
   TERMINATE = Q_USER_SIG
}; 
//-------------------------------------------------------------------
static TServer app;
static HINSTANCE inst;                               // this instance
static HWND mainHwnd;                       // the main window handle
static char appName[] = "TServer";

//...................................................................
BOOL TServer::defer(QEvent const *e) {
   if (IsDlgButtonChecked(myHwnd, IDC_DEFERRED)) {       // deferred?
      return FALSE;                   // cannot defer any more events
   } 
   myDeferredRequest = *e;          // save the event (copy by value)
   CheckDlgButton(myHwnd, IDC_DEFERRED, BST_CHECKED);     // deferred
   return TRUE;
}
//...................................................................
void TServer::recall() {
   if (IsDlgButtonChecked(myHwnd, IDC_DEFERRED)) {       // deferred?
      PostMessage(myHwnd, WM_COMMAND, myDeferredRequest.sig, 0);
      CheckDlgButton(myHwnd, IDC_DEFERRED, BST_UNCHECKED);
   }
}
// HSM definition ---------------------------------------------------
void TServer::initial(QEvent const *) {
   SendMessage(myHwnd, WM_SETICON, (WPARAM)TRUE, 
               (LPARAM)LoadIcon(inst, MAKEINTRESOURCE(IDI_QP)));
   Q_INIT(&TServer::operational);
}
//...................................................................
QSTATE TServer::final(QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      EndDialog(myHwnd, 0);
      return 0;
   }
   return (QSTATE)&TServer::top;
}
//...................................................................
QSTATE TServer::operational(QEvent const *e) {
   switch (e->sig) {
   case Q_INIT_SIG:
      Q_INIT(&TServer::idle);
      return 0;
   case IDC_NEW:
      if (!defer(e)) {                               // cannot defer?
         Beep(1000, 20);                             // warn the user
      }
      return 0;
   case TERMINATE:
      Q_TRAN(&TServer::final);
      return 0;
   }
   if (e->sig >= Q_USER_SIG) {
      isHandled = FALSE;
   }
   return (QSTATE)&TServer::top;
}
//...................................................................
QSTATE TServer::idle(QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      SetDlgItemText(myHwnd, IDC_STATE, "idle");
      recall();
      return 0;
   case IDC_NEW:
      Q_TRAN(&TServer::receiving);
      return 0;
   }
   return (QSTATE)&TServer::operational;
}
//...................................................................
QSTATE TServer::receiving(QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      SetDlgItemText(myHwnd, IDC_STATE, "receiving");
      SetTimer(myHwnd, 1, 1000, 0);   // arrange for timeout in 1 sec
      return 0;
   case WM_TIMER:
      Q_TRAN(&TServer::authorizing);
      return 0;
   case Q_EXIT_SIG:
      KillTimer(myHwnd, 1);
      return 0;
   }
   return (QSTATE)&TServer::operational;
}
//...................................................................
QSTATE TServer::authorizing(QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      SetDlgItemText(myHwnd, IDC_STATE, "authorizing");
      SetTimer(myHwnd, 1, 2000, 0);   // arrange for timeout in 2 sec
      return 0;
   case WM_TIMER:
      Q_TRAN(&TServer::idle);
      return 0;
   case Q_EXIT_SIG:
      KillTimer(myHwnd, 1);
      return 0;
   }
   return (QSTATE)&TServer::operational;
}
//...................................................................
extern "C" void onAssert__(char const *file, unsigned line) {
   char str[160];
   sprintf(str, "Assertion failed in %s, line %d", file, line);        
   MessageBox(mainHwnd, str, appName, MB_ICONEXCLAMATION | MB_OK);
   exit(-1);
}
//-------------------------------------------------------------------
BOOL CALLBACK tServerDlg(HWND hwnd, UINT iMsg, 
                         WPARAM wParam, LPARAM lParam)
{
   QEvent e;
   e.sig = iMsg;
   switch (iMsg) {
   case WM_INITDIALOG:
      app.myHwnd = mainHwnd = hwnd;
      app.init();                      // take the initial transition
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
      // intentionally fall thru
   case WM_TIMER:
      app.isHandled = TRUE;
      app.dispatch(&e);
      return app.isHandled;
   }
   return FALSE;
}
//...................................................................
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst,
                   PSTR cmdLine, int iCmdShow)
{
   InitCommonControls();              // load common controls library
   inst = hInst;                             // store instance handle
   DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG), NULL, tServerDlg);                  
   return 0;              // exit application when the dialog returns
}

