/////////////////////////////////////////////////////////////////////
// Quantum Timer declarations (C++ version)
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#ifndef qtimer_h
#define qtimer_h

#ifndef qevent_h
   #include "qevent.h"
#endif

class QActive;        // forward declaration (used as opaque pointer)
class QTimer {
public:
   QTimer() : myActive(0) {}                          // default ctor
   void fireIn(QActive *act, QSignal sig, unsigned nTicks);
   void fireEvery(QActive *act, QSignal sig, unsigned nTicks);
   void disarm();    
   void rearm(unsigned nTicks);
private:
   void arm(QActive *act, QSignal sig, unsigned nTicks);
private:
   QTimer *myNext;                      // to link timers in the list
   QEvent myToutEvt;                // timeout event instance to send
   QActive *myActive;
   unsigned short myCtr;
   unsigned short myInterval;
   friend class QF; 
};

#endif                                                    // qtimer_h
