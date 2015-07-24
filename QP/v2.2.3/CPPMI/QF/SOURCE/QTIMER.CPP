/////////////////////////////////////////////////////////////////////
// Quantum Timer implemenatation
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#include "qassert.h"
#include "port.h"

DEFINE_THIS_FILE;

//...................................................................
QTimer *pkgTimerListHead;            // head of linked list of timers

//...................................................................
void QTimer::arm(QActive *act, QSignal sig, unsigned nTicks) {
   REQUIRE(nTicks != 0 &&          // cannot arm a timer with 0 ticks
           !myActive);              // the timer must *not* be in use
   myActive = act;
   myToutEvt.sig = sig;
   myToutEvt.poolId = 0;                          // not a pool event
   myToutEvt.useNum = 0;                            // event not used
   myCtr = nTicks;
   QF_PROTECT();
   myNext = pkgTimerListHead;
   pkgTimerListHead = this;
   QF_UNPROTECT();
}
//...................................................................
// setup a periodic timer to fire EVERY 'nTicks' clock ticks and send
// timeout event 'toutSig' to active object 'act'
void QTimer::fireEvery(QActive *act, QSignal sig, unsigned nTicks) {
   myInterval = nTicks;
   arm(act, sig, nTicks);
}
//...................................................................
// setup a one-shot timer to fire IN 'nTicks' clock ticks and send
// timeout event 'toutSig' to active object 'act'
void QTimer::fireIn(QActive *act, QSignal sig, unsigned nTicks) {   
   myInterval = 0;
   arm(act, sig, nTicks);
}
//...................................................................
// rearm a timer to fire in/every nTicks (if 'nTicks'==0 the old 
// value is restored)
void QTimer::rearm(unsigned nTicks) {
   REQUIRE(nTicks > 0);
   QF_PROTECT();
   myCtr = nTicks; 
   QF_UNPROTECT();    
}
//...................................................................
// disarm the currently armed timer
void QTimer::disarm() {
   REQUIRE(myActive);                   // the timer *must* be in use
   QF_PROTECT();
   myCtr = 1;                                // arm for only one tick
   myInterval = 0;                        // make it a one-shot timer
   myToutEvt.sig = Q_EMPTY_SIG;  // generate Q_EMPTY_SIG upon timeout
   QF_UNPROTECT();    
}
