/********************************************************************
 * QP Sensor.c -- Sensor state pattern example
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
 * All Rights Reserved.
 *******************************************************************/
#include <windows.h>
#include <string.h>
#include <commctrl.h>
#include <stdio.h>

#include "qf_win32.h"
#include "qassert.h"
#include "reminder.h"                                 /* resources */

DEFINE_THIS_FILE;

/*.................................................................*/
enum SensorSignals {
   DATA_READY = Q_USER_SIG,
   TERMINATE
}; 
/*.................................................................*/
SUBCLASS(Sensor, QHsm)
   int pollCtr__; 
   int procCtr__; 
   BOOL isHandled__;
   HWND hWnd__;
METHODS
   Sensor *SensorCtor(Sensor *me);
   void Sensor_initial(Sensor *me, QEvent const *e);
   QSTATE Sensor_polling(Sensor *me, QEvent const *e);
      QSTATE Sensor_processing(Sensor *me, QEvent const *e);
         QSTATE Sensor_idle(Sensor *me, QEvent const *e);
         QSTATE Sensor_busy(Sensor *me, QEvent const *e);
   QSTATE Sensor_final(Sensor *me, QEvent const *e);
END_CLASS
/*-----------------------------------------------------------------*/
static Sensor app;
static HINSTANCE inst;                            /* this instance */
static HWND mainHwnd;                    /* the main window handle */
static char appName[] = "Sensor";

/*.................................................................*/
Sensor *SensorCtor(Sensor *me) {
   if (!QHsmCtor_(&me->super_,(QPseudoState)&Sensor_initial)) {
      return 0;
   }
   return me;
}
/* HSM definition -------------------------------------------------*/
void Sensor_initial(Sensor *me, QEvent const *e) {
   SendMessage(me->hWnd__, WM_SETICON, (WPARAM)TRUE, 
               (LPARAM)LoadIcon(inst, MAKEINTRESOURCE(IDI_QP)));
               /* start 2 Hz timer */
   me->pollCtr__ = 0; 
   me->procCtr__ = 0; 
   Q_INIT(&Sensor_polling);
}
/*.................................................................*/
QSTATE Sensor_final(Sensor *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG: EndDialog(me->hWnd__, 0); return 0;
   }
   return (QSTATE)&QHsm_top;
}
/*.................................................................*/
QSTATE Sensor_polling(Sensor *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG: SetTimer(me->hWnd__, 1, 500, 0); return 0;
   case Q_EXIT_SIG:  KillTimer(me->hWnd__, 1);        return 0;
   case Q_INIT_SIG:  Q_INIT(&Sensor_processing);      return 0;
   case WM_TIMER:
      SetDlgItemInt(me->hWnd__, IDC_POLL, ++me->pollCtr__, FALSE);
      if ((me->pollCtr__ & 0x3) == 0){
         PostMessage(me->hWnd__, WM_COMMAND, DATA_READY, 0);
      }
      return 0;
   case TERMINATE: Q_TRAN(&Sensor_final);  return 0;
   }
   if (e->sig >= Q_USER_SIG) {
      me->isHandled__ = FALSE;
   }
   return (QSTATE)&QHsm_top;
}
/*.................................................................*/
QSTATE Sensor_processing(Sensor *me, QEvent const *e) {
   switch (e->sig) {
   case Q_INIT_SIG: Q_INIT(&Sensor_idle);  return 0;
   }
   return (QSTATE)&Sensor_polling;
}
/*.................................................................*/
QSTATE Sensor_idle(Sensor *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      SetDlgItemText(me->hWnd__, IDC_STATE, "idle");
      return 0;
   case DATA_READY: Q_TRAN(&Sensor_busy);  return 0;
   }
   return (QSTATE)&Sensor_processing;
}
/*.................................................................*/
QSTATE Sensor_busy(Sensor *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      SetDlgItemText(me->hWnd__, IDC_STATE, "busy");
      return 0;
   case WM_TIMER:
      SetDlgItemInt(me->hWnd__, IDC_PROC, ++me->procCtr__, FALSE);
      if ((me->procCtr__ & 0x1) == 0) {
          Q_TRAN(&Sensor_idle);
      }
      return 0;
   }
   return (QSTATE)&Sensor_processing;
}
/*.................................................................*/
void onAssert__(char const *file, unsigned line) {
   char str[160];
   wsprintf(str, "Assertion failed in %s, line %d", file, line);        
   MessageBox(mainHwnd, str, appName, MB_ICONEXCLAMATION | MB_OK);
   exit(-1);
}
/*-----------------------------------------------------------------*/
BOOL CALLBACK reminderDlg(HWND hwnd, UINT iMsg, 
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
   SensorCtor(&app);          /* construct the TServer application */
   DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG), NULL, reminderDlg);       
   return 0;           /* exit application when the dialog returns */
}

