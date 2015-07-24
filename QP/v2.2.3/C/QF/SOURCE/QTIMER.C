/******************************************************************** 
 * Quantum Timer implemenatation (C version)
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA.
 * All Rights Reserved.
 *******************************************************************/
#include "qassert.h"
#include "port.h"

DEFINE_THIS_FILE;

/*.................................................................*/
QTimer *pkgTimerListHead;         /* head of linked list of timers */

/*.................................................................*/
static void QTimerAdd(QTimer *me, QActive *act, 
                      QSignal toutSig, unsigned nTicks)
{
   QF_PROTECT();
   REQUIRE(!me->active__);         /* the timer must not be in use */
   me->active__ = act;
   me->toutEvt__.sig = toutSig;
   me->toutEvt__.poolId = 0;                   /* not a pool event */
   me->toutEvt__.useNum = 0;                     /* event not used */
   me->ctr__ = nTicks;
   me->next__ = pkgTimerListHead;
   pkgTimerListHead = me;
   QF_UNPROTECT();
}
/*...................................................................
 * setup a periodic timer to fire EVERY 'nTicks' clock ticks and send
 * timeout message 'toutSig' to active object 'act'
 */
void QTimerFireEvery(QTimer *me, QActive *act, 
                     QSignal toutSig, unsigned nTicks)
{
   me->interval__ = nTicks;
   QTimerAdd(me, act, toutSig, nTicks);
}
/*...................................................................
 * setup a one-shot timer to fire IN 'nTicks' clock ticks and send
 * timeout message 'toutSig' to active object 'act'
 */
void QTimerFireIn(QTimer *me, QActive *act, 
                  QSignal toutSig, unsigned nTicks)
{   
   me->interval__ = 0;
   QTimerAdd(me, act, toutSig, nTicks);
}
/*...................................................................
 * rearm a timer to fire in/every nTicks (if 'nTicks'==0 the old 
 * value is restored)
 */
void QTimerRearm(QTimer *me, unsigned nTicks) {
   QF_PROTECT();
   me->ctr__ = nTicks; 
   QF_UNPROTECT();    
}
/*...................................................................
 * disarm currently armed timer
 */
void QTimerDisarm(QTimer *me) {
   REQUIRE(me->active__);            /* the timer *must* be in use */
   QF_PROTECT();
   me->ctr__ = 1;                         /* arm for only one tick */
   me->interval__ = 0;                 /* make it a one-shot timer */
   me->toutEvt__.sig = Q_EMPTY_SIG;    /* Q_EMPTY_SIG upon timeout */
   QF_UNPROTECT();    
}

