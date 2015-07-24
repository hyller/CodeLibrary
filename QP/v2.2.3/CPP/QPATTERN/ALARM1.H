/////////////////////////////////////////////////////////////////////
// alarm1.h -- "Orthogonal Component" state pattern example
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#ifndef alarm1_h
#define alarm1_h

class Alarm : public QHsm { // the HSM version of the Alarm component
public:
   Alarm() : QHsm((QPseudoState)initial) {}
private:
   void initial(QEvent const *e);
   QSTATE alarm(QEvent const *e);
      QSTATE on(QEvent const *e);
      QSTATE off(QEvent const *e);
private:
   unsigned myAlarmTime;
   HWND myHwnd;                                      // window handle
};

#endif                                                    // alarm1_h