/////////////////////////////////////////////////////////////////////
// comp2.cpp -- "Orthogonal Component" state pattern example
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#include <windows.h>
#include <string.h>
#include <commctrl.h>
#include <stdio.h>

#include "qf_win32.h"
#include "qassert.h"
#include "alarm2.h"
#include "clock2.h"
#include "comp.h"                                        // resources

DEFINE_THIS_FILE;

//-------------------------------------------------------------------
static HINSTANCE inst;                               // this instance
static HWND mainHwnd;                               // the main window
static char appName[] = "AlarmClock";

//...................................................................
AlarmClock * AlarmClock::instance() {   // Singleton pattern accessor
   static AlarmClock app;
   return &app;
}
// HSM definition ---------------------------------------------------
void AlarmClock::initial(QEvent const *e) {
   SendMessage(myHwnd, WM_SETICON, (WPARAM)TRUE, 
               (LPARAM)LoadIcon(inst, MAKEINTRESOURCE(IDI_QP)));
   myCurrentTime = 0;
   myAlarm.init();       // initial transition in the alarm component 
   Q_INIT(&AlarmClock::timekeeping);
}
//...................................................................
QSTATE AlarmClock::final(QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      EndDialog(myHwnd, 0);
      return 0;
   }
   return (QSTATE)&AlarmClock::top;
}
//...................................................................
QSTATE AlarmClock::timekeeping(QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG: SetTimer(myHwnd, 1, 50, 0);   return 0;
   case Q_EXIT_SIG:  KillTimer(myHwnd, 1);         return 0;
   case Q_INIT_SIG: Q_INIT(&AlarmClock::mode24hr); return 0;
   case IDC_12H:    Q_TRAN(&AlarmClock::mode12hr); return 0;
   case IDC_24H:    Q_TRAN(&AlarmClock::mode24hr); return 0;
   case ALARM_SIG:
      ShowWindow(GetDlgItem(myHwnd, IDC_BELL), SW_SHOW);
      return 0;
   case IDC_ON:
   case IDC_OFF:
      myAlarm.dispatch(e);  // dispatch event to orthogonal component
      return 0;
   case TERMINATE:  Q_TRAN(&AlarmClock::final); return 0;
   }
   if (e->sig >= Q_USER_SIG) {
      isHandled = FALSE;
   }
   return (QSTATE)&AlarmClock::top;
}
//...................................................................
QSTATE AlarmClock::mode24hr(QEvent const *e) {
   char buf[12];
   TimeEvt pe;                                    // propagated event
   switch (e->sig) {
   case Q_ENTRY_SIG:
      CheckRadioButton(myHwnd, IDC_12H, IDC_24H, IDC_24H);
      return 0;
   case WM_TIMER:
      if (++myCurrentTime == 24*60) {
         myCurrentTime = 0;
      }
      wsprintf(buf, "%02d:%02d", myCurrentTime/60, myCurrentTime%60);
      SetDlgItemText(myHwnd, IDC_TIME, buf);
      pe.sig = TIME_SIG;
      pe.currentTime = myCurrentTime;
      myAlarm.dispatch(&pe); //dispatch event to orthogonal component
      return 0;
   }
   return (QSTATE)&AlarmClock::timekeeping;
}
//...................................................................
QSTATE AlarmClock::mode12hr(QEvent const *e) {
   char buf[12];
   unsigned h;
   TimeEvt pe;                                    // propagated event
   switch (e->sig) {
   case Q_ENTRY_SIG:
      CheckRadioButton(myHwnd, IDC_12H, IDC_24H, IDC_12H);
      return 0;
   case WM_TIMER:
      if (++myCurrentTime == 24*60) {
         myCurrentTime = 0;
      }
      h = myCurrentTime/60;
      wsprintf (buf, "%02d:%02d %s", (h % 12) ? (h % 12) : 12, 
                     myCurrentTime % 60, (h / 12) ? "PM" : "AM"); 
      SetDlgItemText(myHwnd, IDC_TIME, buf);
      pe.sig = TIME_SIG;
      pe.currentTime = myCurrentTime;
      myAlarm.dispatch(&pe); //dispatch event to orthogonal component
      return 0;
   }
   return (QSTATE)&AlarmClock::timekeeping;
}
//...................................................................
extern "C" void onAssert__(char const *file, unsigned line) {
   char str[160];
   wsprintf(str, "Assertion failed in %s, line %d", file, line);        
   MessageBox(mainHwnd, str, appName, MB_ICONEXCLAMATION | MB_OK);
   exit(-1);
}
//-------------------------------------------------------------------
BOOL CALLBACK alarmClockDlg(HWND hwnd, UINT iMsg, 
                            WPARAM wParam, LPARAM lParam)
{
   QEvent e;
   e.sig = iMsg;
   switch (iMsg) {
   case WM_INITDIALOG:
      AlarmClock::instance()->myHwnd = mainHwnd = hwnd;
      AlarmClock::instance()->init();  // take the initial transition
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
      AlarmClock::instance()->isHandled = TRUE;
      AlarmClock::instance()->dispatch(&e);
      return AlarmClock::instance()->isHandled;
   }
   return FALSE;
}
//...................................................................
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst,
                   PSTR cmdLine, int iCmdShow)
{
   InitCommonControls();              // load common controls library
   inst = hInst;                             // store instance handle
   DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG), 0, alarmClockDlg);                  
   return 0;              // exit application when the dialog returns
}

