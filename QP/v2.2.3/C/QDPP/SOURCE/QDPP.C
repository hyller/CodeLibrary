/******************************************************************** 
 * Quantum Dining Philosophers (C version)
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA.
 * All Rights Reserved.
 *******************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "qassert.h"
#include "port.h"

DEFINE_THIS_FILE;

enum { THINK_TIME = 3, EAT_TIME = 4 };

/*.................................................................*/
Philosopher *PhilosopherCtor(Philosopher *me, int n) {
   QActiveCtor_(&me->super_, (QPseudoState)Philosopher_initial);
   me->num__ = n;
   return me;
}
/*.................................................................*/
void Philosopher_initial(Philosopher *me, QEvent const *e) {
   printf("Initializing philospher %1d\n", me->num__);
   QFsubscribe((QActive *)me, EAT_SIG);
   Q_INIT(Philosopher_thinking);
}
/*.................................................................*/
QSTATE Philosopher_thinking(Philosopher *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      QTimerFireIn(&me->timer__, (QActive *)me, TIMEOUT_SIG, 5);
      return 0;
   case TIMEOUT_SIG:
      Q_TRAN(Philosopher_hungry);
      return 0;
   }
   return (QSTATE)QHsm_top;
}
/*.................................................................*/
QSTATE Philosopher_hungry(Philosopher *me, QEvent const *e) {
   TableEvt *pe;
   switch (e->sig) {
   case Q_ENTRY_SIG:
      pe = Q_NEW(TableEvt, HUNGRY_SIG);
      pe->philNum = me->num__;
      QFpublish((QEvent *)pe);
      return 0;
   case EAT_SIG:
      if (((TableEvt *)e)->philNum == me->num__) {
         Q_TRAN(Philosopher_eating);
      }
      return 0;
   } 
   return (QSTATE)QHsm_top;
}
/*.................................................................*/
QSTATE Philosopher_eating(Philosopher *me, QEvent const *e) {
   TableEvt *pe;
   switch (e->sig) {
   case Q_ENTRY_SIG:
      QTimerFireIn(&me->timer__, (QActive *)me, TIMEOUT_SIG, 8);
      return 0;
   case TIMEOUT_SIG:
      pe = Q_NEW(TableEvt, DONE_SIG);
      pe->philNum = me->num__;
      QFpublish((QEvent *)pe);
      Q_TRAN(Philosopher_thinking);
      return 0;
   } 
   return (QSTATE)QHsm_top;
}
/*.................................................................*/
#define RIGHT(i) (((i) + (N - 1)) % N)
#define LEFT(i)  (((i) + 1) % N)
enum { FREE = 0, USED = !0 };
/*.................................................................*/
Table *TableCtor(Table *me) {
   QActiveCtor_(&me->super_, (QPseudoState)Table_initial);
   return me;
}
/*.................................................................*/
void Table_initial(Table *me, QEvent const *e) {
   unsigned n;
   QFsubscribe((QActive *)me, HUNGRY_SIG);
   QFsubscribe((QActive *)me, DONE_SIG);
   for (n = 0; n < N; ++n) {
      me->fork__[n] = FREE;
      me->isHungry__[n] = 0;
   }
   Q_INIT(Table_serving);
}
/*.................................................................*/
QSTATE Table_serving(Table *me, QEvent const *e) {
   unsigned n, m;
   TableEvt *pe;
   switch (e->sig) {
   case HUNGRY_SIG:
      n = ((TableEvt *)e)->philNum;
      ASSERT(n < N && !me->isHungry__[n]);
      printf("Philospher %1d is hungry\n", n);
      m = LEFT(n);
      if (me->fork__[m] == FREE && me->fork__[n] == FREE) {
         me->fork__[m] = me->fork__[n] = USED;
         pe = Q_NEW(TableEvt, EAT_SIG);
         pe->philNum = n;
         QFpublish((QEvent *)pe);
         printf("Philospher %1d is eating\n", n);
      }
      else {
         me->isHungry__[n] = 1;
      }
      return 0;
   case DONE_SIG:
      n = ((TableEvt *)e)->philNum;
      ASSERT(n < N);    
      printf("Philospher %1d is thinking\n", n);
      me->fork__[LEFT(n)] = me->fork__[n] = FREE;
      m = RIGHT(n);
      if (me->isHungry__[m] && me->fork__[m] == FREE) {
         me->fork__[n] = me->fork__[m] = USED;
         me->isHungry__[m] = 0;
         pe = Q_NEW(TableEvt, EAT_SIG);
         pe->philNum = m;
         QFpublish((QEvent *)pe);
         printf("Philospher %1d is eating\n", m);
      }
      m = LEFT(n);
      n = LEFT(m);
      if (me->isHungry__[m] && me->fork__[n] == FREE) {
         me->fork__[m] = me->fork__[n] = USED;
         me->isHungry__[m] = 0;
         pe = Q_NEW(TableEvt, EAT_SIG);
         pe->philNum = m;
         QFpublish((QEvent *)pe);
         printf("Philospher %1d is eating\n", m);
      }
      return 0;
   } 
   return (QSTATE)QHsm_top;
}
