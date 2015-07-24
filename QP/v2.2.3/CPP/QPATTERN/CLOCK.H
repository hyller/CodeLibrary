/////////////////////////////////////////////////////////////////////
// clock.h -- "Orthogonal Component" state pattern example
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#ifndef clock_h
#define clock_h

enum AlarmClockSignals {
   TIME_SIG = Q_USER_SIG,
   ALARM_SIG, TERMINATE
}; 
//...................................................................
struct AlarmInitEvt : public QEvent {
   HWND hWnd;
};
//...................................................................
struct TimeEvt : public QEvent {
   unsigned currentTime;
};

#endif                                                     // clock_h