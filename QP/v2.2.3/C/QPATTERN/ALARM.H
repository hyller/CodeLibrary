/********************************************************************
 * alarm.h -- "Orthogonal Component" state pattern example
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
 * All Rights Reserved.
 *******************************************************************/
#ifndef alarm_h
#define alarm_h

SUBCLASS(Alarm, QFsm)
   unsigned alarmTime__;
   HWND hWnd__;                                   /* window handle */
METHODS
   Alarm *AlarmCtor(Alarm *me);
   void Alarm_initial(Alarm *me, QEvent const *e);
   void Alarm_on(Alarm *me, QEvent const *e);
   void Alarm_off(Alarm *me, QEvent const *e);
END_CLASS

#endif                                                  /* alarm_h */