/////////////////////////////////////////////////////////////////////
// Quantum Framework RTK32-specific implemenatation
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#include "qassert.h"
#include "port.h"

DEFINE_THIS_FILE;

//...................................................................
const char *QF::getVersion() { 
   return "QF/RTK32 version 2.1.0";
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
      QEvent *e;
      RTKGet(myEqueue, &e); 
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
          qSto == 0 && stkSto == 0);        // RTK-32 allocates these
   myEqueue = RTKCreateMailbox(sizeof(QEvent *), qLen, "");
   if (!myEqueue) {
      return 0;    // failed to create RTK-32 mailbox -- return error
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
   return RTKPutCond(myEqueue, &e);
}
//...................................................................
void QActive::post(QEvent *e) {
   REQUIRE(e->useNum == 0);               // event must not be in use
   ALLEGE(RTKPutFrontCond(myEqueue, &e));
}
/////////////////////////////////////////////////////////////////////
// NOTE01:
// NOTE02:
//
