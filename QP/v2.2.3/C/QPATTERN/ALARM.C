/********************************************************************
 * alarm.h -- "Orthogonal Component" state pattern example
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

/* FSM definition -------------------------------------------------*/
Alarm *AlarmCtor(Alarm *me) {
   if (!QFsmCtor_(&me->super_, (QFsmState)&Alarm_initial)) {
      return 0;
   }
   return me;
}
/*................................................................ */
void Alarm_initial(Alarm *me, QEvent const *e) {
   me->hWnd__ = ((AlarmInitEvt *)e)->hWnd;
   CheckRadioButton(me->hWnd__, IDC_ON, IDC_OFF, 
                    IDC_ON);
   SetDlgItemText(me->hWnd__, IDC_ALARM, "12:00");
   QFSM_TRAN(&Alarm_on);
}
/*................................................................ */
void Alarm_on(Alarm *me, QEvent const *e) {
   switch (e->sig) {
   case TIME_SIG:
      if (((TimeEvt *)e)->currentTime == me->alarmTime__) {
         Beep(1000, 20);
         PostMessage(me->hWnd__, WM_COMMAND, ALARM_SIG, 0);
      }
      return;
   case IDC_OFF:
      CheckRadioButton(me->hWnd__, IDC_ON, IDC_OFF, IDC_OFF);
      EnableWindow(GetDlgItem(me->hWnd__, IDC_ALARM), TRUE);
      ShowWindow(GetDlgItem(me->hWnd__, IDC_BELL), SW_HIDE);
      QFSM_TRAN(&Alarm_off);
      return;
   }
}
/*................................................................ */
void Alarm_off(Alarm *me, QEvent const *e) {
   char buf[12];
   unsigned h, m;
   switch (e->sig) {
   case IDC_ON:
      GetDlgItemText(me->hWnd__, IDC_ALARM, buf, sizeof(buf)); 
      if (2 == sscanf(buf, "%d:%d", &h, &m) &&  /*check if the user*/ 
          0 <= h && h < 24 && 0 <= m && m < 60) /* input represents*/
      {                                         /* .. a valid time */
         me->alarmTime__ = h*60+ m;
         CheckRadioButton(me->hWnd__, IDC_ON, IDC_OFF, IDC_ON);
         EnableWindow(GetDlgItem(me->hWnd__, IDC_ALARM), FALSE);
         QFSM_TRAN(&Alarm_on);
      }
      else {
         CheckRadioButton(me->hWnd__, IDC_ON, IDC_OFF, IDC_OFF);
      }
      return;
   }
}
