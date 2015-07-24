/////////////////////////////////////////////////////////////////////
// Quantum Framework Win32-specific implemenatation
// Copyright (c) 2002 Miro Samek, Palo Alto, CA.
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#include "qassert.h"
#include "port.h"

DEFINE_THIS_FILE;

CRITICAL_SECTION pkgWin32CritSect;

//...................................................................
const char *QF::getVersion() { 
   return "QF/Win32 version 2.2.1";
}
//...................................................................
void QF::osInit() { 
   InitializeCriticalSection(&pkgWin32CritSect);
}
//...................................................................
void QF::osCleanup() { 
   DeleteCriticalSection(&pkgWin32CritSect);
}
//...................................................................
void QF::background() { 
   ASSERT(0);         // Win32 does not support background processing
}
//...................................................................
void QActive::run() {
   QHsm::init();                        // execute initial transition
   for (;;) {
      register QEvent *e = myEqueue.get();          // wait for event
      dispatch(e);                               // process the event
      QF::propagate(e);           // propagate to the next subscriber 
   }
}
//...................................................................
static DWORD WINAPI run(LPVOID a) { 
   ((QActive *)a)->run();
   return 0;
}   
// start ............................................................
int QActive::start(unsigned prio, QEvent *qSto[], unsigned qLen,
                   int stkSto[], unsigned stkLen)
{
   REQUIRE(stkSto == 0);        // Windows allocates stack internally
   if (!myEqueue.init(qSto, qLen)) {
      return 0;                                     // return failure
   }
   myPrio = prio;
   QF::add(this);              // make QF aware of this active object 
   switch (myPrio) {
   case 1:  prio = THREAD_PRIORITY_LOWEST;        break;
   case 2:  prio = THREAD_PRIORITY_IDLE;          break;
   case 3:  prio = THREAD_PRIORITY_BELOW_NORMAL;  break;
   case 4:  prio = THREAD_PRIORITY_NORMAL;        break;
   case 5:  prio = THREAD_PRIORITY_ABOVE_NORMAL;  break;
   case 6:  prio = THREAD_PRIORITY_HIGHEST;       break;
   default: prio = THREAD_PRIORITY_TIME_CRITICAL; break;
   }
   DWORD threadId;
   myThread = CreateThread(NULL,
                           stkLen,
                           ::run,
                           this,
                           0, 
                           &threadId);
   if (!myThread) {
      return 0;                                     // return failure
   }
   SetThreadPriority(myThread, prio);
   return !0;                                       // return success
}
// stop .............................................................
void QActive::stop() {
   QF::remove(this);
   ExitThread(0);
   CloseHandle(myThread); 
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
