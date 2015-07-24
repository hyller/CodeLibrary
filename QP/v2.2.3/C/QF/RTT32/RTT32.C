/******************************************************************** 
 * Quantum Framework RTT32 port implemenatation (C version)
 * (c) Copyright 2001, Miro Samek, Palo Alto, CA
 * All Rights Reserved
 *******************************************************************/
#include "qassert.h"
#include "port.h"

DEFINE_THIS_FILE;

unsigned char pkgRdyMask;

/*.................................................................*/
const char *QFgetVersion() { 
   return "QF/RTT32 version 2.1.0";
}
/*.................................................................*/
void QFosInit__() { 
}
/*.................................................................*/
void QFosCleanup__() { 
}
/*.................................................................*/
void QFbackground() {
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

   while (pkgRdyMask) {
      QActive *a = pkgActive[lbLkup[pkgRdyMask]];
      register QEvent *evt = (QEvent *)QEQueueGet(&a->eQueue__);
      QHsmDispatch((QHsm *)a, evt);     /* dispatch evt to the HSM */
      QFpropagate__(evt);      /* propagate to the next subscriber */ 
   }   
}
/*.................................................................*/
int QActiveStart(QActive *me, unsigned prio, 
                 QEvent **qSto, unsigned qLen,
                 int *stkSto, unsigned stkLen)
{
   REQUIRE(0 < prio && prio <= QF_MAX_ACTIVE &&
           stkSto == 0);      /* DOS does not need per-actor stack */
   me->prio__ = prio;
   QFadd__(me);             /* make QF aware of this active object */ 
   if (!QEQueueCtor(&me->eQueue__, qSto, qLen)) {
      return 0;                                  /* return failure */
   }
   me->eQueue__.osEvent__ = 1 << (prio - 1); /*bit-mask 4 the actor*/
   QHsmInit((QHsm *)me, 0);          /* execute initial transition */
   return !0;                                    /* return success */
}
/*.................................................................*/
void QActiveStop(QActive *me) {
   QFremove__(me);
}
/*.................................................................*/
int QActiveEnqueue__(QActive *me, QEvent *evt) {
   return QEQueuePutFIFO(&me->eQueue__, evt); 
}
/*.................................................................*/
void QActivePostFIFO(QActive *me, QEvent *evt) {
   REQUIRE(evt->useNum == 0);          /* event must not be in use */
   ALLEGE(QEQueuePutFIFO(&me->eQueue__, evt));  /* cannot overflow!*/
}
/*.................................................................*/
void QActivePostLIFO(QActive *me, QEvent *evt) {
   REQUIRE(evt->useNum == 0);          /* event must not be in use */
   ALLEGE(QEQueuePutLIFO(&me->eQueue__, evt));  /* cannot overflow!*/
}
