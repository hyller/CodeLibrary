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

void Philosopher::initial(QEvent const *) {
   QF::subscribe(this, EAT0_SIG + myNum);
   Q_INIT(&Philosopher::thinking);
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
   return (QSTATE)&Philosopher::top;
}

QSTATE Philosopher::hungry(QEvent const *e) {
   TableEvt *pe;
   switch (e->sig) {
   case Q_ENTRY_SIG:
      pe = Q_NEW(TableEvt, HUNGRY_SIG);
      pe->philNum = myNum;
      QF::publish(pe);
      return 0;
   case EAT0_SIG:
   case EAT1_SIG:
   case EAT2_SIG:
   case EAT3_SIG:
   case EAT4_SIG:
      ASSERT(e->sig == EAT0_SIG + myNum);
      Q_TRAN(&Philosopher::eating);
      return 0;
   } 
   return (QSTATE)&Philosopher::top;
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
   return (QSTATE)&Philosopher::top;
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
   QEvent *pe;
   switch (e->sig) {
   case HUNGRY_SIG:
      n = ((TableEvt *)e)->philNum;
      ASSERT(n < N && !isHungry[n]);
      printf("Philospher %1d is hungry\n", n);
      m = LEFT(n);
      if (myFork[m] == FREE && myFork[n] == FREE) {
         myFork[m] = myFork[n] = USED;
         pe = Q_NEW(QEvent, EAT0_SIG + n);
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
         pe = Q_NEW(QEvent, EAT0_SIG + m);
         QF::publish(pe);
         printf("Philospher %1d is eating\n", m);
      }
      m = LEFT(n);                         // check the left neighbor
      n = LEFT(m);
      if (isHungry[m] && myFork[n] == FREE) {
         myFork[m] = myFork[n] = USED;
         isHungry[m] = 0;
         pe = Q_NEW(QEvent, EAT0_SIG + m);
         QF::publish(pe);
         printf("Philospher %1d is eating\n", m);
      }
      return 0;
   } 
   return (QSTATE)&Table::top;
}
