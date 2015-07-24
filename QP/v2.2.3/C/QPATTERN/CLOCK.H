/********************************************************************
 * clock.h -- "Orthogonal Component" state pattern example
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
 * All Rights Reserved.
 *******************************************************************/
#ifndef clock_h
#define clock_h

enum AlarmClockSignals {
   TIME_SIG = Q_USER_SIG,
   ALARM_SIG, TERMINATE
}; 
/*.................................................................*/
SUBCLASS(AlarmInitEvt, QEvent)
   HWND hWnd;
METHODS
END_CLASS
/*.................................................................*/
SUBCLASS(TimeEvt, QEvent)
   unsigned currentTime;
METHODS
END_CLASS

#endif                                                  /* clock_h */