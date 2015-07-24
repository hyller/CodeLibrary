/////////////////////////////////////////////////////////////////////
// Quantum Event Quantum Framewrok implemenatation
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
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
static QF_EPOOL locPool[MAX_POOL];   // allocate MAX_POOL event pools

            // The pool pointers keep track of pools actually used.
            // The first and last poolPtr are not used (must be 0),
            // which is guaranteed by static initialization in C/C++.
static QF_EPOOL *locPoolPtr[1 + MAX_POOL + 1];

//...................................................................
void QF::init(QSubscrList subscr[], unsigned maxSignal) {
   locSubscrList = subscr;
   locMaxSignal = maxSignal;
   osInit();
}
//...................................................................
void QF::cleanup() {
   osCleanup();
}
//...................................................................
void QF::tick() {  
   register QTimer *t, *tp;
   QF_ISR_PROTECT();
   for (t = tp = pkgTimerListHead; t; t = t->myNext) {
      if (--t->myCtr == 0) {
                                             // queue cannot overflow
         ALLEGE(t->myActive->enqueue(&t->myToutEvt));
         if (t->myInterval) {                      // periodic timer?
            t->myCtr = t->myInterval;              // rearm the timer
            tp = t;
         }
         else {   // one-shot timer, disarm by removing from the list
            if (t == pkgTimerListHead) {
               pkgTimerListHead = tp = t->myNext;              
            }
            else {
               tp->myNext = t->myNext;
            }
            t->myActive = 0;            // mark the timer free to use
         }
      }
      else {
         tp = t;
      }
   }            
   QF_ISR_UNPROTECT();
}
//...................................................................
void QF::poolInit(QEvent *poolSto, 
                  unsigned nEvts, unsigned evtSize)
{
   static unsigned poolId = 0;
   REQUIRE(poolId < MAX_POOL);        // cannot exceed the # of pools
      // please initialize event pools in ascending order of evtSize:
   REQUIRE(poolId == 0 || locPoolPtr[poolId]->myEvtSize < evtSize);
   QF_EPOOL_INIT(&locPool[poolId], poolSto, nEvts, evtSize);
   locPoolPtr[poolId + 1] = &locPool[poolId];//add *initialized* pool
   ++poolId;                 // one more pool; (poolId of 0 not used)
}
//...................................................................
QEvent *QF::create(unsigned evtSize, QSignal sig) {
   register unsigned id;
   register QEPool *p;
   for (id = 1, p = locPoolPtr[1]; p; p = locPoolPtr[++id]) {
      if (evtSize <= p->myEvtSize) { //will evtSize fit in this pool?
         QEvent *e;
         QF_EPOOL_GET(p, e);
         ASSERT(e);            // the pool must not run out of events
         e->poolId = id;       // to know where to recycle this event
         e->sig = sig;                   // set signal for this event
         e->useNum = 0;            // this event is new, not used yet
         return e;
      } 
   }
   ASSERT(0);         // event too big to fit in any initialized pool
   return 0;  // should never be reached, just to avoid compiler fuss
}
//...................................................................
void QF::annihilate(QEvent *e) {
   if (e->poolId) {                            // is it a pool event?
      ASSERT(e->poolId <= MAX_POOL && locPoolPtr[e->poolId]);
      QF_EPOOL_PUT(locPoolPtr[e->poolId], e);
   }
   else {                                 // this is not a pool event
      e->useNum = 0;  // recycle event by clearing the number of uses
   }
}
//...................................................................
void QF::add(QActive *a) {
   REQUIRE(a->myPrio < QF_MAX_ACTIVE && pkgActive[a->myPrio] == 0);
   pkgActive[a->myPrio] = a;
}
//...................................................................
void QF::remove(QActive *a) {
   register QSignal sig;
   for (sig = Q_USER_SIG; sig < locMaxSignal; ++sig) {
       QF::unsubscribe(a, sig);
   }
   pkgActive[a->myPrio] = 0;            // free-up the priority level
}
//...................................................................
void QF::subscribe(QActive *a, QSignal sig) {
   register unsigned char p = a->myPrio; // priority of active object
   REQUIRE(Q_USER_SIG <= sig && sig < locMaxSignal &&
           p < QF_MAX_ACTIVE && pkgActive[p] == a);
   QF_PROTECT();
   register QSubscrList sl = *(locSubscrList + sig);
   ASSERT((sl & 0xF0000000) == 0); //must have at least one free slot
   for (register int n = 0; n < 32; n += 4) {   // find priority slot
      if (p > ((sl >> n) & 0xF)) {
          sl =  (sl & ~(~0 << n)) |
                (p << n) |
                ((sl << 4) & (~0 << (n + 4))); 
          *(locSubscrList + sig) = sl;
          break;      // subscriber registered (attached to the list)
      }
   }
   QF_UNPROTECT();
}
//...................................................................
void QF::unsubscribe(QActive *a, QSignal sig) {
   REQUIRE(Q_USER_SIG <= sig && sig < locMaxSignal);
   register unsigned char p = a->myPrio; // priority of active object
   QF_PROTECT();
   register QSubscrList sl = *(locSubscrList + sig);
   for (register int n = 0; n < 32; n += 4) {   // find priority slot
      if (p == ((sl >> n) & 0xF)) {
          sl =  (sl & ~(~0 << n)) | ((sl >> 4) & (~0 << n)); 
          *(locSubscrList + sig) = sl;
          break;     // subscription canceled (removed from the list)
      }
   }
   QF_UNPROTECT();
}
//...................................................................
void QF::publish(QEvent *e) {
   REQUIRE(e->sig < locMaxSignal &&
           e->useNum == 0);           // do not publish event in use!
   register QSubscrList sl = *(locSubscrList + e->sig);
   if (sl) {                                      // any subscribers?
      register unsigned char p = (unsigned char)(sl & 0xF);
      e->useNum = 1;                                 // the first use
      ASSERT(pkgActive[p]);     // active object must have subscribed
      ALLEGE(pkgActive[p]->enqueue(e));      // queue cannot overflow
   }
   else {                                           // no subscribers
      QF::annihilate(e);                     // do not leak the event
   }
}
//...................................................................
void QF::propagate(QEvent *e) {
   if (e->useNum > 0) {            // should QF propagate this event?
      ASSERT(e->sig < locMaxSignal);                   // range check
      register QSubscrList sl = locSubscrList[e->sig];
      sl >>= (e->useNum*4); // shift out already serviced subscribers
      if (sl) {                        // more subscribers available?
         register unsigned char p = (unsigned char)(sl & 0xF);
         ++e->useNum;                                     // next use
         ASSERT(pkgActive[p]);     // active object must have started
         ALLEGE(pkgActive[p]->enqueue(e));   // queue cannot overflow
         return;                                  // event propagated
      }
   }
   QF::annihilate(e);         // event not propagated; don't leak it!
}
/////////////////////////////////////////////////////////////////////
// NOTE01:
// NOTE02:
//
