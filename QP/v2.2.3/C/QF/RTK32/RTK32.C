/******************************************************************** 
 * Quantum Framework RTK32 port implemenatation (C version)
 * (c) Copyright 2001, Miro Samek, Palo Alto, CA
 * All Rights Reserved
 *******************************************************************/
#include "qassert.h"
#include "port.h"

DEFINE_THIS_FILE;

/*.................................................................*/
const char *QFgetVersion() { 
   return "QF/RTK32 version 2.1.0";
}
/*.................................................................*/
void QFosInit__() { 
}
/*.................................................................*/
void QFosCleanup__() { 
}
/*.................................................................*/
void QFbackground() { 
   ASSERT(0);      /* RTK32 does not support background processing */
}
/*.................................................................*/
static void RTKAPI QActiveRun(QActive *me) {
   QHsmInit((QHsm *)me, 0);          /* execute initial transition */
   for (;;) {
      QEvent *evt;
      RTKGet(me->eQueue__, &evt); 
      QHsmDispatch((QHsm *)me, evt);    /* dispatch evt to the HSM */
      QFpropagate__(evt);      /* propagate to the next subscriber */ 
   }
}
/*.................................................................*/
int QActiveStart(QActive *me, unsigned prio,
                 QEvent **qSto, unsigned qLen,
                 int *stkSto, unsigned stkLen)
{
   me->prio__ = prio;
   QFadd__(me);             /* make QF aware of this active object */ 
   ASSERT(prio < RTK_MAX_PRIO &&
          qSto == 0 && stkSto == 0);     /* RTK-32 allocates these */
   me->eQueue__ = RTKCreateMailbox(sizeof(QEvent *), qLen, "");
   if (!me->eQueue__) {
      return 0;   /* failed to create RTK-32 mailbox--return error */
   }
   if ((me->thread__ = RTKCreateThread((RTKThreadFunction)QActiveRun,
                                       prio,
                                       stkLen,
                                       TF_MATH_CONTEXT,
                                       (void *)me,
                                       "")) == 0)
   {                     
      return 0;   /* failed to create RTK32 thread -- return error */
   }
   return !0;                                    /* return success */
}
/*.................................................................*/
void QActiveStop(QActive *me) {
   QFremove__(me);
   RTKTerminateTask(&me->thread__);
}
/*.................................................................*/
int QActiveEnqueue__(QActive *me, QEvent *evt) {
   return RTKPutCond(me->eQueue__, &evt);
}
/*.................................................................*/
void QActivePostFIFO(QActive *me, QEvent *evt) {
   REQUIRE(evt->useNum == 0);          /* event must not be in use */
   ALLEGE(RTKPutCond(me->eQueue__, &evt));
}
/*.................................................................*/
void QActivePostLIFO(QActive *me, QEvent *evt) {
   REQUIRE(evt->useNum == 0);          /* event must not be in use */
   ALLEGE(RTKPutFrontCond(me->eQueue__, &evt));
}
