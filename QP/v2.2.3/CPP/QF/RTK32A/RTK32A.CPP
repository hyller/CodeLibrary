/////////////////////////////////////////////////////////////////////
// Quantum Framework RTK32-specific implemenatation
// Copyright (c) 2001, Miro Samek, Palo Alto, CA
// All Rights Reserved 
/////////////////////////////////////////////////////////////////////
#include "qassert.h"
#include "port.h"

DEFINE_THIS_FILE;

//...................................................................
const char *QF::getVersion() { 
   return "QF/RTK32A version 2.1.0";
}
//...................................................................
void QF::osInit() { 
}
//...................................................................
void QF::osCleanup() { 
}
//...................................................................
void QF::background() { 
   ASSERT(0);         // RTK32 does not support background processing
}
//...................................................................
void QActive::run() {
   QHsm::init();                        // execute initial transition
   for (;;) {
      register QEvent *e = (QEvent *)myEqueue.get(); //wait for event
      dispatch(e);                  // dispatch evt to the statechart
      QF::propagate(e);           // propagate to the next subscriber
   }
}
//...................................................................
static void RTKAPI run(void *a) {
   ((QActive *)a)->run();
}   
// start ............................................................
int QActive::start(unsigned prio, QEvent *qSto[], unsigned qLen,
                   int stkSto[], unsigned stkLen)
{
   myPrio = prio;
   QF::add(this);              // make QF aware of this active object 
   ASSERT(prio < RTK_MAX_PRIO &&
          stkSto == 0);                    // RTK-32A allocates stack
   if (!myEqueue.init(qSto, qLen)) {
      return 0;                                     // return failure
   }
   if ((myThread = RTKCreateThread((RTKThreadFunction)::run,
                                   prio,
                                   stkLen,
                                   TF_MATH_CONTEXT,
                                   (void *)this,
                                   "")) == 0)
   {                     
      return 0;      // failed to create RTK32 thread -- return error
   }
   return !0;                                       // return success
}
// stop .............................................................
void QActive::stop() {
   QF::remove(this);
   RTKTerminateTask(&myThread);
}
//...................................................................
int QActive::enqueue(QEvent *e) {
   return myEqueue.putFIFO(e); 
}
//...................................................................
void QActive::postFIFO(QEvent *e) {
   REQUIRE(e->useNum == 0);               // event must not be in use
   ALLEGE(myEqueue.putFIFO(e));              // queue cannot overflow
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
