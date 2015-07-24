/////////////////////////////////////////////////////////////////////
// QP reminder.cpp -- Sensor state pattern example
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#include <windows.h>
#include <string.h>
#include <commctrl.h>
#include <stdio.h>

#include "qf_win32.h"
#include "qassert.h"
#include "reminder.h"                           // reminder resources

DEFINE_THIS_FILE;

//...................................................................
enum SensorSignals {
   DATA_READY = Q_USER_SIG,
   TERMINATE
}; 
//...................................................................
class Sensor : public QHsm {
public:
   Sensor() : QHsm((QPseudoState)initial) {}
private:
   void initial(QEvent const *e);
   QSTATE polling(QEvent const *e);
      QSTATE processing(QEvent const *e);
         QSTATE idle(QEvent const *e);
         QSTATE busy(QEvent const *e);
   QSTATE final(QEvent const *e);
private:
   int myPollCtr; 
   int myProcCtr; 
   BOOL isHandled;
   HWND myHwnd;                          // the main window handle
   friend BOOL CALLBACK reminderDlg(HWND hwnd, UINT iEvt, 
                                    WPARAM wParam, LPARAM lParam);
};
//-------------------------------------------------------------------
static Sensor app;
static HINSTANCE inst;                               // this instance
static HWND mainHwnd;                              // the main window
static char appName[] = "Sensor";

// HSM definition ---------------------------------------------------
void Sensor::initial(QEvent const *) {
   SendMessage(myHwnd, WM_SETICON, (WPARAM)TRUE, 
               (LPARAM)LoadIcon(inst, MAKEINTRESOURCE(IDI_QP)));
   myPollCtr = 0; 
   myProcCtr = 0; 
   Q_INIT(&Sensor::polling);
}
//...................................................................
QSTATE Sensor::final(QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      EndDialog(myHwnd, 0);
      return 0;
   }
   return (QSTATE)&Sensor::top;
}
//...................................................................
QSTATE Sensor::polling(QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG: SetTimer(myHwnd, 1, 500, 0);  return 0;
   case Q_EXIT_SIG:  KillTimer(myHwnd, 1);         return 0;
   case Q_INIT_SIG:  Q_INIT(&Sensor::processing);  return 0;
   case WM_TIMER:
      SetDlgItemInt(myHwnd, IDC_POLL, ++myPollCtr, FALSE);
      if ((myPollCtr & 0x3) == 0){
         PostMessage(myHwnd, WM_COMMAND, DATA_READY, 0);
      }
      return 0;
   case TERMINATE: Q_TRAN(&Sensor::final);  return 0;
   }
   if (e->sig >= Q_USER_SIG) {
      isHandled = FALSE;
   }
   return (QSTATE)&Sensor::top;
}
//...................................................................
QSTATE Sensor::processing(QEvent const *e) {
   switch (e->sig) {
   case Q_INIT_SIG: Q_INIT(&Sensor::idle);  return 0;
   }
   return (QSTATE)&Sensor::polling;
}
//...................................................................
QSTATE Sensor::idle(QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      SetDlgItemText(myHwnd, IDC_STATE, "idle");
      return 0;
   case DATA_READY: Q_TRAN(&Sensor::busy);  return 0;
   }
   return (QSTATE)&Sensor::processing;
}
//...................................................................
QSTATE Sensor::busy(QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      SetDlgItemText(myHwnd, IDC_STATE, "busy");
      return 0;
   case WM_TIMER:
      SetDlgItemInt(myHwnd, IDC_PROC, ++myProcCtr, FALSE);
      if ((myProcCtr & 0x1) == 0) {
          Q_TRAN(&Sensor::idle);
      }
      return 0;
   }
   return (QSTATE)&Sensor::processing;
}
//...................................................................
extern "C" void onAssert__(char const *file, unsigned line) {
   char str[160];
   wsprintf(str, "Assertion failed in %s, line %d", file, line);        
   MessageBox(mainHwnd, str, appName, MB_ICONEXCLAMATION | MB_OK);
   exit(-1);
}
//-------------------------------------------------------------------
BOOL CALLBACK reminderDlg(HWND hwnd, UINT iMsg, 
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
   DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG), NULL, reminderDlg);                  
   return 0;              // exit application when the dialog returns
}

