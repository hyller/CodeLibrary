/////////////////////////////////////////////////////////////////////
// clock2.h -- "Orthogonal Component" state pattern example
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#ifndef clock2_h
#define clock2_h

class AlarmClock : public QHsm {
public:
   static AlarmClock *instance();        // Singleton accessor method
private:
   AlarmClock() : QHsm((QPseudoState)initial) {}      // private Ctor
   void initial(QEvent const *e);
   QSTATE timekeeping(QEvent const *e);
      QSTATE mode12hr(QEvent const *e);
      QSTATE mode24hr(QEvent const *e);
   QSTATE final(QEvent const *e);
private:
   unsigned myCurrentTime;
   Alarm myAlarm;                       // Alarm orthogonal component
   BOOL isHandled;
   HWND myHwnd;                             // the main window handle
   friend class Alarm;
   friend BOOL CALLBACK alarmClockDlg(HWND hwnd, UINT iEvt, 
                                      WPARAM wParam, LPARAM lParam);
};
//...................................................................
enum AlarmClockSignals {
   TIME_SIG = Q_USER_SIG,
   ALARM_SIG, TERMINATE
}; 
//...................................................................
struct TimeEvt : public QEvent {
   unsigned currentTime;
};

#endif                                                    // clock2_h