/////////////////////////////////////////////////////////////////////
// alarm.h -- "Orthogonal Component" state pattern example
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#ifndef alarm_h
#define alarm_h

class Alarm : public QFsm {
public:
   Alarm() : QFsm((QFsmState)initial) {}
private:
   void initial(QEvent const *e);
   void on(QEvent const *e);
   void off(QEvent const *e);
private:
   unsigned myAlarmTime;
   HWND myHwnd;                                      // window handle
};

#endif                                                     // alarm_h