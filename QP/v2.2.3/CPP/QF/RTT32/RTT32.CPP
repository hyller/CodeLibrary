/////////////////////////////////////////////////////////////////////
// Quantum Framework RTT32-specific implemenatation
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#include "qassert.h"
#include "port.h"

DEFINE_THIS_FILE;

unsigned char pkgReadyList;

//...................................................................
const char *QF::getVersion() { 
   return "QF/RTT32 version 2.2.02";
}
//...................................................................
void QF::osInit() { 
}
//...................................................................
void QF::osCleanup() { 
}
//...................................................................
void QF::background() {
   static const unsigned char lbLkup[] = {
      0, 1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4,
      5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
      6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
      6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
      7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
      7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
      7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
      7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
      8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
      8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
      8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
      8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
      8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
      8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
      8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
      8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 
   };

   while (pkgReadyList) {
      QActive *a = pkgActive[lbLkup[pkgReadyList]];
      register QEvent *e = (QEvent *)a->myEqueue.get();
      a->dispatch(e);             // dispatch event to the statechart
      QF::propagate(e);           // propagate to the next subscriber 
   }   
}
//...................................................................
void QActive::run() {
   ASSERT(0);                // RTT32 does not support multithreading
}
// start ............................................................
int QActive::start(unsigned prio, QEvent *qSto[], unsigned qLen,
                   int stkSto[], unsigned stkLen)
{
   REQUIRE(0 < prio && prio <= QF_MAX_ACTIVE &&
           stkSto == 0);      // RTT-32 does not need per-actor stack
   myPrio = prio;
   QF::add(this);              // make QF aware of this active object 
   if (!myEqueue.init(qSto, qLen)) {
      return 0;                                     // return failure
   }
   myEqueue.myOsEvent = 1 << (myPrio - 1);  // bit-mask of this actor
   QHsm::init();                        // execute initial transition
   return !0;                                       // return success
}
// stop .............................................................
void QActive::stop() {
   QF::remove(this);
}
//...................................................................
int QActive::enqueue(QEvent *e) {
   return myEqueue.putFIFO(e); 
}
//...................................................................
void QActive::postFIFO(QEvent *e) {
   REQUIRE(e->useNum == 0);               // event must not be in use
   ALLEGE(myEqueue.putLIFO(e));              // queue cannot overflow
}
//...................................................................
void QActive::postLIFO(QEvent *e) {
   REQUIRE(e->useNum == 0);               // event must not be in use
   ALLEGE(myEqueue.putLIFO(e));              // queue cannot overflow
}
/////////////////////////////////////////////////////////////////////
// NOTE01:
// NOTE02:
//
