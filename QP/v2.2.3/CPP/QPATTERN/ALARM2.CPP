/////////////////////////////////////////////////////////////////////
// alarm.cpp -- "Orthogonal Component" state pattern example
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#include <windows.h>
#include <string.h>
#include <commctrl.h>
#include <stdio.h>

#include "qf_win32.h"
#include "alarm2.h"
#include "clock2.h"
#include "qassert.h"
#include "comp.h"                                        // resources

DEFINE_THIS_FILE;

// FSM definition ---------------------------------------------------
void Alarm::initial(QEvent const *) {
   CheckRadioButton(AlarmClock::instance()->myHwnd, 
                    IDC_ON, IDC_OFF, IDC_ON);
   SetDlgItemText(AlarmClock::instance()->myHwnd, IDC_ALARM, "12:00");
   QFSM_TRAN(&Alarm::on);
}
//...................................................................
void Alarm::on(QEvent const *e) {
   switch (e->sig) {
   case TIME_SIG:
      if (((TimeEvt *)e)->currentTime == myAlarmTime) {
         Beep(1000, 20);
         PostMessage(AlarmClock::instance()->myHwnd, 
                     WM_COMMAND, ALARM_SIG, 0);             // notify
      }
      return;
   case IDC_OFF:
      CheckRadioButton(AlarmClock::instance()->myHwnd, 
                       IDC_ON, IDC_OFF, IDC_OFF);
      EnableWindow(GetDlgItem(AlarmClock::instance()->myHwnd, 
                   IDC_ALARM), TRUE);
      ShowWindow(GetDlgItem(AlarmClock::instance()->myHwnd,IDC_BELL), 
                 SW_HIDE);
      QFSM_TRAN(&Alarm::off);
      return;
   }
}
//...................................................................
void Alarm::off(QEvent const *e) {
   char buf[12];
   unsigned h, m;
   switch (e->sig) {
   case IDC_ON:
      GetDlgItemText(AlarmClock::instance()->myHwnd, 
                     IDC_ALARM, buf, sizeof(buf)); 
      if (2 == sscanf(buf, "%d:%d", &h, &m) &&  //  check if the user 
          0 <= h && h < 24 && 0 <= m && m < 60) // ..input represents
      {                                         // ..    a valid time
         myAlarmTime = h*60+ m;
         CheckRadioButton(AlarmClock::instance()->myHwnd, 
                          IDC_ON, IDC_OFF, IDC_ON);
         EnableWindow(GetDlgItem(AlarmClock::instance()->myHwnd, 
                      IDC_ALARM), FALSE);
         QFSM_TRAN(&Alarm::on);
      }
      else {
         CheckRadioButton(AlarmClock::instance()->myHwnd, 
                          IDC_ON, IDC_OFF, IDC_OFF);
      }
      return;
   }
}
