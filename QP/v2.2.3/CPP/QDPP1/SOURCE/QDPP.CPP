/////////////////////////////////////////////////////////////////////
// Quantum Dining Philosophers
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#include <stdlib.h>
#include <stdio.h>
#include "qassert.h"
#include "port.h"

DEFINE_THIS_FILE;

enum { THINK_TIME = 7, EAT_TIME = 5 };

static void flaky() {
   static int failCtr = 20;
   if (--failCtr == 0) {
      failCtr = 20;
      throw "fail";
   }
}

void Philosopher::initial(QEvent const *) {
   QF::subscribe(this, EAT_SIG);
   Q_INIT(&Philosopher::catchall);
}

QSTATE Philosopher::catchall(QEvent const *e) {
   switch (e->sig) {
   case Q_INIT_SIG:
      Q_INIT(&Philosopher::thinking);
      return 0;
   case EXCEPTION_SIG:
      Beep(1000, 10);
      return 0;
   }
   return (QSTATE)&Philosopher::top;
}

QSTATE Philosopher::thinking(QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      myTimer.fireIn(this, TIMEOUT_SIG, THINK_TIME);
      return 0;
   case TIMEOUT_SIG:
      Q_TRAN(&Philosopher::hungry);
      return 0;
   }
   return (QSTATE)&Philosopher::catchall;
}

QSTATE Philosopher::hungry(QEvent const *e) {
   TableEvt *pe;
   switch (e->sig) {
   case Q_ENTRY_SIG:
      pe = Q_NEW(TableEvt, HUNGRY_SIG);
      pe->philNum = myNum;
      QF::publish(pe);
      try {
         flaky();
      }
      catch (...) {
         ExceptEvt *ee = Q_NEW(ExceptEvt, EXCEPTION_SIG);
         ee->errNum = 0;
         postLIFO(ee);
      }
      return 0;
   case EAT_SIG:
      if (((TableEvt *)e)->philNum == myNum) {
         Q_TRAN(&Philosopher::eating);
      }
      return 0;
   } 
   return (QSTATE)&Philosopher::catchall;
}

QSTATE Philosopher::eating(QEvent const *e) {
   TableEvt *pe;
   switch (e->sig) {
   case Q_ENTRY_SIG:
      myTimer.fireIn(this, TIMEOUT_SIG, EAT_TIME);
      return 0;
   case TIMEOUT_SIG:
      Q_TRAN(&Philosopher::thinking);
      return 0;
   case Q_EXIT_SIG:
      pe = Q_NEW(TableEvt, DONE_SIG);
      pe->philNum = myNum;
      QF::publish(pe);
      return 0;
   } 
   return (QSTATE)&Philosopher::catchall;
}

#define RIGHT(n_) (((n_) + (N - 1)) % N)
#define LEFT(n_)  (((n_) + 1) % N)
enum { FREE = 0, USED = !0 };

void Table::initial(QEvent const *) {
   QF::subscribe(this, HUNGRY_SIG);
   QF::subscribe(this, DONE_SIG);
   for (unsigned n = 0; n < N; ++n) {
      myFork[n] = FREE;
      isHungry[n] = 0;
   }
   Q_INIT(&Table::serving);
}

QSTATE Table::serving(QEvent const *e) {
   unsigned n, m;
   TableEvt *pe;
   switch (e->sig) {
   case HUNGRY_SIG:
      n = ((TableEvt *)e)->philNum;
      ASSERT(n < N && !isHungry[n]);
      printf("Philospher %1d is hungry\n", n);
      m = LEFT(n);
      if (myFork[m] == FREE && myFork[n] == FREE) {
         myFork[m] = myFork[n] = USED;
         pe = Q_NEW(TableEvt, EAT_SIG);
         pe->philNum = n;
         QF::publish(pe);
         printf("Philospher %1d is eating\n", n);
      }
      else {
         isHungry[n] = 1;
      }
      return 0;
   case DONE_SIG:
      n = ((TableEvt *)e)->philNum;
      ASSERT(n < N);    
      printf("Philospher %1d is thinking\n", n);
      myFork[LEFT(n)] = myFork[n] = FREE;
      m = RIGHT(n);                       // check the right neighbor
      if (isHungry[m] && myFork[m] == FREE) {
         myFork[n] = myFork[m] = USED;
         isHungry[m] = 0;
         pe = Q_NEW(TableEvt, EAT_SIG);
         pe->philNum = m;
         QF::publish(pe);
         printf("Philospher %1d is eating\n", m);
      }
      m = LEFT(n);                         // check the left neighbor
      n = LEFT(m);
      if (isHungry[m] && myFork[n] == FREE) {
         myFork[m] = myFork[n] = USED;
         isHungry[m] = 0;
         pe = Q_NEW(TableEvt, EAT_SIG);
         pe->philNum = m;
         QF::publish(pe);
         printf("Philospher %1d is eating\n", m);
      }
      return 0;
   } 
   return (QSTATE)&Table::top;
}
