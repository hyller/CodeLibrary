/******************************************************************** 
 * Quantum Framework Win32-specific implemenatation
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA.
 * All Rights Reserved.
 *******************************************************************/
#include "qassert.h"
#include "port.h"

DEFINE_THIS_FILE;

CRITICAL_SECTION pkgWin32CritSect;

/*.................................................................*/
const char *QFgetVersion() { 
   return "QF/Win32 version 2.2.1";
}
/*.................................................................*/
void QFosInit__() { 
   InitializeCriticalSection(&pkgWin32CritSect);
}
/*.................................................................*/
void QFosCleanup__() { 
   DeleteCriticalSection(&pkgWin32CritSect);
}
/*.................................................................*/
void QFbackground() { 
   ASSERT(0);      /* Win32 does not support background processing */
}
/*.................................................................*/
static DWORD WINAPI QActiveRun(LPVOID me) {
   QHsmInit((QHsm *)me, 0);          /* execute initial transition */
   for (;;) {
      register QEvent *e = QEQueueGet(&((QActive *)me)->eQueue__);
      QHsmDispatch((QHsm *)me, e);   /* dispatch to the statechart */
      QFpropagate__(e);        /* propagate to the next subscriber */
   }
   return 0;
}
/*.................................................................*/
int QActiveStart(QActive *me, unsigned prio, 
                 QEvent *qSto[], unsigned qLen,
                 int stkSto[], unsigned stkLen)
{
   DWORD threadId;
   REQUIRE(stkSto == 0);     /* Windows allocates stack internally */
   if (!QEQueueCtor(&me->eQueue__, qSto, qLen)) {
      return 0;                                  /* return failure */
   }
   me->prio__ = prio;
   QFadd__(me);             /* make QF aware of this active object */
   switch (me->prio__) {
   case 1:  prio = THREAD_PRIORITY_LOWEST;        break;
   case 2:  prio = THREAD_PRIORITY_IDLE;          break;
   case 3:  prio = THREAD_PRIORITY_BELOW_NORMAL;  break;
   case 4:  prio = THREAD_PRIORITY_NORMAL;        break;
   case 5:  prio = THREAD_PRIORITY_ABOVE_NORMAL;  break;
   case 6:  prio = THREAD_PRIORITY_HIGHEST;       break;
   default: prio = THREAD_PRIORITY_TIME_CRITICAL; break;
   }
   me->thread__ = CreateThread(NULL,
                               stkLen,
                               QActiveRun,
                               me,
                               0, 
                               &threadId);
   if (!me->thread__) {
      return 0;                                  /* return failure */
   }
   SetThreadPriority(me->thread__, prio);
   return !0;                                    /* return success */
}
/*.................................................................*/
void QActiveStop(QActive *me) {
   QFremove__(me);
   ExitThread(0);
   CloseHandle(me->thread__); 
}
/*.................................................................*/
int QActiveEnqueue__(QActive *me, QEvent *e) {
   return QEQueuePutFIFO(&me->eQueue__, e); 
}
/*.................................................................*/
void QActivePostFIFO(QActive *me, QEvent *e) {
   REQUIRE(e->useNum == 0);            /* event must not be in use */
   ALLEGE(QEQueuePutFIFO(&me->eQueue__, e));   /* cannot overflow! */
}
/*.................................................................*/
void QActivePostLIFO(QActive *me, QEvent *e) {
   REQUIRE(e->useNum == 0);            /* event must not be in use */
   ALLEGE(QEQueuePutLIFO(&me->eQueue__, e));   /* cannot overflow! */
}

/******************************************************************** 
 * NOTE01:
 * NOTE02:
 */
