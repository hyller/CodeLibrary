/******************************************************************** 
 * Quantum Hierarchical State Machine dynamic transition definition
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
 * All Rights Reserved.
 *******************************************************************/
#include "qassert.h"
#include "port.h"

DEFINE_THIS_FILE;
                                                   /* helper macro */
#define TRIGGER(state_, sig_) \
   (QState)(*(state_))(me, &pkgStdEvt[sig_])

void QHsmTran_(QHsm *me, QState target) {
   QState entry[8], p, q, s, *e, *lca;
   REQUIRE(target != (QState)QHsm_top); /* cannot target top state */
   for (s = me->state__; s != me->source__; ) {
      QState t;
      ASSERT(s);                  /* we are about to dereference s */
      t = TRIGGER(s, Q_EXIT_SIG);
      if (t) {    /* exit action unhandled, t points to superstate */
         s = t;
      }
      else {             /* exit action handled, elicit superstate */
         s = TRIGGER(s, Q_EMPTY_SIG);
      }
   }

   *(e = &entry[0]) = 0;
   *(++e) = target;                      /* assume entry to target */

   /* (a) check source == target (transition to self) */
   if (me->source__ == target) {
      TRIGGER(me->source__, Q_EXIT_SIG);            /* exit source */
      goto inLCA;
   }
   /* (b) check source == target->super */
   p = TRIGGER(target, Q_EMPTY_SIG);
   if (me->source__ == p) {
      goto inLCA;
   }
   /* (c) check source->super == target->super (most common) */
   q = TRIGGER(me->source__, Q_EMPTY_SIG);
   if (q == p) {
      TRIGGER(me->source__, Q_EXIT_SIG);            /* exit source */
      goto inLCA;
   }
   /* (d) check me->source->super == target */
   if (q == target) {
      TRIGGER(me->source__, Q_EXIT_SIG);            /* exit source */
      --e;                                 /* do not enter the LCA */
      goto inLCA;
   }
   /* (e) check rest of source == target->super->super... hierarchy*/
   *(++e) = p;
   for (s = TRIGGER(p, Q_EMPTY_SIG); s; 
        s = TRIGGER(s, Q_EMPTY_SIG)) 
   {
      if (me->source__ == s) {
         goto inLCA;
      }
      *(++e) = s;
   }
   TRIGGER(me->source__, Q_EXIT_SIG);               /* exit source */
   /* (f) check rest of source->super == target->super->super... */
   for (lca = e; *lca; --lca) {
      if (q == *lca) {
         e = lca - 1;                      /* do not enter the LCA */
         goto inLCA;
      }
   }
   /* (g) check each me->source__->super->super..for each target...*/
   for (s = q; s; s = TRIGGER(s, Q_EMPTY_SIG)) {
      for (lca = e; *lca; --lca) {
         if (s == *lca) {
            e = lca - 1;                   /* do not enter the LCA */
            goto inLCA;
         }
      }
      TRIGGER(s, Q_EXIT_SIG);                            /* exit s */
   }   
   ASSERT(0);                                     /* malformed HSM */
inLCA:         /* now we are in the LCA of me->source__ and target */
   ASSERT(e < &entry[sizeof(entry)/sizeof(*entry)]); /* entry fits */
   while (s = *e--) {   /* retrace the entry path in reverse order */
      TRIGGER(s, Q_ENTRY_SIG);                          /* enter s */
   }
   me->state__ = target;                   /* update current state */
   while (TRIGGER(target, Q_INIT_SIG) == 0) {
                      /* initial transition must go one level deep */
      ASSERT(target == TRIGGER(me->state__, Q_EMPTY_SIG));
      target = me->state__;
      TRIGGER(target, Q_ENTRY_SIG);                /* enter target */
   }
}
