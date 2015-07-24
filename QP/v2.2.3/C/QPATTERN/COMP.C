/********************************************************************
 * QP comp.c -- "Orthogonal Component" state pattern example
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
 * All Rights Reserved.
 *******************************************************************/
#include <windows.h>
#include <string.h>
#include <commctrl.h>
#include <stdio.h>

#include "qf_win32.h"
#include "clock.h"
#include "alarm.h"
#include "qassert.h"
#include "comp.h"                                     /* resources */

DEFINE_THIS_FILE;

SUBCLASS(AlarmClock, QHsm)
   unsigned currentTime__;
   Alarm alarm__;                    /* Alarm orthogonal component */
   BOOL isHandled__;
   HWND hWnd__;                                   /* window handle */
METHODS
   AlarmClock *AlarmClockCtor(AlarmClock *me);
   void AlarmClock_initial(AlarmClock *me, QEvent const *e);
   QSTATE AlarmClock_timekeeping(AlarmClock *me, QEvent const *e);
      QSTATE AlarmClock_mode12hr(AlarmClock *me, QEvent const *e);
      QSTATE AlarmClock_mode24hr(AlarmClock *me, QEvent const *e);
   QSTATE AlarmClock_final(AlarmClock *me, QEvent const *e);
END_CLASS
/*-----------------------------------------------------------------*/
static AlarmClock app;
static HINSTANCE inst;                            /* this instance */
static HWND mainHwnd;                           /* the main window */
static char appName[] = "AlarmClock";

/* HSM definition ------------------------------------------------ */
AlarmClock *AlarmClockCtor(AlarmClock *me) {
   QHsmCtor_(&me->super_, (QPseudoState)&AlarmClock_initial);
   AlarmCtor(&me->alarm__);             /* construct the component */
   return me;
}
void AlarmClock_initial(AlarmClock *me, QEvent const *e) {
   AlarmInitEvt ie;
   SendMessage(me->hWnd__, WM_SETICON, (WPARAM)TRUE, 
               (LPARAM)LoadIcon(inst, MAKEINTRESOURCE(IDI_QP)));
   me->currentTime__ = 0;
   ie.hWnd = me->hWnd__;
   QFsmInit((QFsm *)&me->alarm__, (QEvent *)&ie); /* initial tran. */ 
   Q_INIT(&AlarmClock_timekeeping);
}
/*................................................................ */
QSTATE AlarmClock_final(AlarmClock *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG: EndDialog(me->hWnd__, 0); return 0;
   }
   return (QSTATE)&QHsm_top;
}
/*................................................................ */
QSTATE AlarmClock_timekeeping(AlarmClock *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG: SetTimer(me->hWnd__, 1, 50, 0); return 0;
   case Q_EXIT_SIG:  KillTimer(me->hWnd__, 1);       return 0;
   case Q_INIT_SIG:  Q_INIT(&AlarmClock_mode24hr);   return 0;
   case IDC_12H:     Q_TRAN(&AlarmClock_mode12hr);   return 0;
   case IDC_24H:     Q_TRAN(&AlarmClock_mode24hr);   return 0;
   case ALARM_SIG:
      ShowWindow(GetDlgItem(me->hWnd__, IDC_BELL), SW_SHOW);
      return 0;
   case IDC_ON:
   case IDC_OFF:
      QFsmDispatch((QFsm *)&me->alarm__, e); /* dispatch e to alarm*/
      return 0;
   case TERMINATE:   Q_TRAN(&AlarmClock_final);      return 0;
   }
   if (e->sig >= Q_USER_SIG) {
      me->isHandled__ = FALSE;
   }
   return (QSTATE)&QHsm_top;
}
/*................................................................ */
QSTATE AlarmClock_mode24hr(AlarmClock *me, QEvent const *e) {
   char buf[12];
   TimeEvt pe;                                 /* propagated event */
   switch (e->sig) {
   case Q_ENTRY_SIG:
      CheckRadioButton(me->hWnd__, IDC_12H, IDC_24H, IDC_24H);
      return 0;
   case WM_TIMER:
      if (++me->currentTime__ == 24*60) {
         me->currentTime__ = 0;
      }
      wsprintf(buf, "%02d:%02d", me->currentTime__/60, 
                                 me->currentTime__%60);
      SetDlgItemText(me->hWnd__, IDC_TIME, buf);
      ((QEvent *)&pe)->sig = TIME_SIG;
      pe.currentTime = me->currentTime__;
      QFsmDispatch((QFsm *)&me->alarm__, (QEvent *)&pe);
      return 0;
   }
   return (QSTATE)&AlarmClock_timekeeping;
}
/*.................................................................*/
QSTATE AlarmClock_mode12hr(AlarmClock *me, QEvent const *e) {
   char buf[12];
   unsigned h;
   TimeEvt pe;                                 /* propagated event */
   switch (e->sig) {
   case Q_ENTRY_SIG:
      CheckRadioButton(me->hWnd__, IDC_12H, IDC_24H, IDC_12H);
      return 0;
   case WM_TIMER:
      if (++me->currentTime__ == 24*60) {
         me->currentTime__ = 0;
      }
      h = me->currentTime__/60;
      wsprintf (buf, "%02d:%02d %s", (h % 12) ? (h % 12) : 12, 
                     me->currentTime__ % 60, (h / 12) ? "PM" : "AM"); 
      SetDlgItemText(me->hWnd__, IDC_TIME, buf);
      ((QEvent *)&pe)->sig = TIME_SIG;
      pe.currentTime = me->currentTime__;
      QFsmDispatch((QFsm *)&me->alarm__, (QEvent *)&pe);
      return 0;
   }
   return (QSTATE)&AlarmClock_timekeeping;
}
/*.................................................................*/
void onAssert__(char const *file, unsigned line) {
   char str[160];
   wsprintf(str, "Assertion failed in %s, line %d", file, line);        
   MessageBox(mainHwnd, str, appName, MB_ICONEXCLAMATION | MB_OK);
   exit(-1);
}
/*-----------------------------------------------------------------*/
BOOL CALLBACK alarmClockDlg(HWND hwnd, UINT iMsg, 
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
    InitCommonControls();          /* load common controls library */
    inst = hInst;                         /* store instance handle */
    AlarmClockCtor(&app);  /* construct the AlarmClock application */
    DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG), NULL, 
              alarmClockDlg);                  
    return 0;          /* exit application when the dialog returns */
}

