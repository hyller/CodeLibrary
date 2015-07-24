/******************************************************************** 
 * Quantum Framewrok implemenatation (C version)
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA.
 * All Rights Reserved.
 *******************************************************************/
#include "qassert.h"
#include "port.h"

DEFINE_THIS_FILE;

QActive *pkgActive[QF_MAX_ACTIVE];
QEvent const pkgStdEvt[] = {
   { Q_EMPTY_SIG, 0, 0 },
   { Q_INIT_SIG,  0, 0 },
   { Q_ENTRY_SIG, 0, 0 },
   { Q_EXIT_SIG,  0, 0 }
};

static QSubscrList *locSubscrList;
static unsigned locMaxSignal;

enum { MAX_POOL = 3 };
static QF_EPOOL locPool[MAX_POOL]; /* allocate MAX_POOL event pools*/

            /* The pool pointers keep track of pools actually used.
             * The first and last poolPtr are not used (must be 0),
             * which is guaranteed by static initialization in C/C++.
            */
static QF_EPOOL *locPoolPtr[1 + MAX_POOL + 1];

/*.................................................................*/
void QFinit(QSubscrList subscr[], unsigned maxSignal) {
   locSubscrList = subscr;
   locMaxSignal = maxSignal;
   QFosInit__();
}
/*.................................................................*/
void QFcleanup() {
   QFosCleanup__();
}
/*...................................................................
 * QFtick() method called usually from ISR context
 */
void QFtick() {  
   register QTimer *t, *tp;
   QF_ISR_PROTECT();
   for (t = tp = pkgTimerListHead; t; t = t->next__) {
      if (--t->ctr__ == 0) {
                                          /* queue cannot overflow */
         ALLEGE(QActiveEnqueue__(t->active__, &t->toutEvt__));
         if (t->interval__) {                   /* periodic timer? */
            t->ctr__ = t->interval__;           /* rearm the timer */
            tp = t;
         }
         else { /* one-shot timer, disarm by removing from the list*/
            if (t == pkgTimerListHead) {
               pkgTimerListHead = tp = t->next__;              
            }
            else {
               tp->next__ = t->next__;
            }
            t->active__ = 0;         /* mark the timer free to use */
         }
      }
      else {
         tp = t;
      }
   }            
   QF_ISR_UNPROTECT();
}
/*.................................................................*/
void QFpoolInit(QEvent *poolSto, 
                unsigned nEvts, unsigned evtSize)
{
   static unsigned poolId = 0;
   REQUIRE(poolId < MAX_POOL);     /* cannot exceed the # of pools */
   /* please initialize event pools in ascending order of evtSize: */
   REQUIRE(poolId == 0 || locPoolPtr[poolId]->evtSize__ < evtSize);
   poolId++;         /* bump up the poolId; poolPtr[0] is not used */
   locPoolPtr[poolId] = &locPool[poolId - 1];
   QF_EPOOL_INIT(locPoolPtr[poolId], poolSto, nEvts, evtSize);
}
/*.................................................................*/
QEvent *QFcreate(unsigned evtSize, QSignal sig) {
   register unsigned id;
   register QEPool *p;
   for (id = 1, p = locPoolPtr[1]; p; p = locPoolPtr[++id]) {
      if (evtSize <= p->evtSize__) {          /* will evtSize fit? */
         QEvent *e;
         QF_EPOOL_GET(p, e);
         ASSERT(e);         /* the pool must not run out of events */
         e->poolId = id;      /* to know where to recycle this evt */
         e->sig = sig;                  /* set signal for this evt */
         e->useNum = 0;           /* this evt is new, not used yet */
         return e;
      } 
   }
   ASSERT(0);      /* event too big to fit in any initialized pool */
   return 0; /*should never be reached, just to avoid compiler fuss*/
}
/*.................................................................*/
void QFannihilate__(QEvent *e) {
   if (e->poolId) {                         /* is it a pool event? */
      ASSERT(e->poolId <= MAX_POOL && locPoolPtr[e->poolId]);
      QF_EPOOL_PUT(locPoolPtr[e->poolId], e);
   }
   else {                              /* this is not a pool event */
      e->useNum = 0;     /* recycle by clearing the number of uses */
   }
}
/*.................................................................*/
void QFadd__(QActive *a) {
   REQUIRE(a->prio__ < QF_MAX_ACTIVE && pkgActive[a->prio__] == 0);
   pkgActive[a->prio__] = a;
}
/*.................................................................*/
void QFremove__(QActive *a) {
   register QSignal sig;
   for (sig = Q_USER_SIG; sig < locMaxSignal; ++sig) {
       QFunsubscribe(a, sig);
   }
   pkgActive[a->prio__] = 0;         /* free-up the priority level */
}
/*.................................................................*/
void QFsubscribe(QActive *a, QSignal sig) {
   register unsigned char p = a->prio__;/*priority of active object*/
   register QSubscrList sl;
   register int n;
   REQUIRE(Q_USER_SIG <= sig && sig < locMaxSignal &&
           p < QF_MAX_ACTIVE && pkgActive[p] == a);
   QF_PROTECT();
   sl = *(locSubscrList + sig);
   ASSERT((sl & 0xF0000000) == 0);        /* must have a free slot */
   for (n = 0; n < 32; n += 4) {             /* find priority slot */
      if (p > ((sl >> n) & 0xF)) {
          sl =  (sl & ~(~0 << n)) |
                (p << n) |
                ((sl << 4) & (~0 << (n + 4))); 
          *(locSubscrList + sig) = sl;
          break;   /* subscriber registered (attached to the list) */
      }
   }
   QF_UNPROTECT();
}
/*.................................................................*/
void QFunsubscribe(QActive *a, QSignal sig) {
   register unsigned char p = a->prio__;/*priority of active object*/
   register QSubscrList sl;
   register int n;
   REQUIRE(Q_USER_SIG <= sig && sig < locMaxSignal);
   QF_PROTECT();
   sl = *(locSubscrList + sig);
   for (n = 0; n < 32; n += 4) {             /* find priority slot */
      if (p == ((sl >> n) & 0xF)) {
          sl =  (sl & ~(~0 << n)) | ((sl >> 4) & (~0 << n)); 
          *(locSubscrList + sig) = sl;
          break;  /* subscription canceled (removed from the list) */
      }
   }
   QF_UNPROTECT();
}
/*.................................................................*/
void QFpublish(QEvent *e) {
   register QSubscrList sl;
   REQUIRE(e->sig < locMaxSignal &&
           e->useNum == 0);        /* do not publish event in use! */
   sl = *(locSubscrList + e->sig);
   if (sl) {                                   /* any subscribers? */
      register unsigned char p = (unsigned char)(sl & 0xF);
      e->useNum = 1;                              /* the first use */
      ASSERT(pkgActive[p]);  /* active object must have subscribed */
                                   /* event queue cannot overflow! */
      ALLEGE(QActiveEnqueue__(pkgActive[p], e));
   }
   else {                                        /* no subscribers */
      QFannihilate__(e);                  /* do not leak the event */
   }
}
/*.................................................................*/
void QFpropagate__(QEvent *e) {
   if (e->useNum > 0) {         /* should QF propagate this event? */
      register QSubscrList sl;
      ASSERT(e->sig < locMaxSignal);                /* range check */
      sl = *(locSubscrList + e->sig);
      sl >>= (e->useNum*4);
      if (sl) {
         register unsigned char p = (unsigned char)(sl & 0xF);
         ++e->useNum;                                  /* next use */
         ASSERT(pkgActive[p]);  /* active object must have started */
                                   /* event queue cannot overflow! */
         ALLEGE(QActiveEnqueue__(pkgActive[p], e));
         return;                               /* event propagated */
      }
   }
   QFannihilate__(e);      /* event not propagated; don't leak it! */
} 
/******************************************************************** 
 * NOTE01:
 * NOTE02:
 */
