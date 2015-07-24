/******************************************************************** 
 * Quantum Hierarchical State Machine declarations (C version)
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA.
 * All Rights Reserved.
 *******************************************************************/
#include "qassert.h"
#include "port.h"

DEFINE_THIS_FILE;
                                                   /* helper macro */
#define TRIGGER(state_, sig_) \
   (QState)(*(state_))(me, &pkgStdEvt[sig_])

const char *QHsmGetVersion(void) { 
   return "QHsm 2.2.2";
}

BEGIN_VTABLE(QHsm, Object)
   VMETHOD(Object, xtor) = (void (*)(Object *))QHsmXtor_;
END_VTABLE
//...................................................................
QHsm *QHsmCtor_(QHsm *me, QPseudoState initial) {
   ObjectCtor_(&me->super_);
   VHOOK(QHsm);
   me->state__ = QHsm_top;
   me->source__ = (QState)initial;
   return me;
}
//...................................................................
void QHsmXtor_(QHsm *me) {
   ObjectXtor_(&me->super);
}
//...................................................................
QSTATE QHsm_top(QHsm *me, QEvent const *e) {
   return 0;
}
//...................................................................
void QHsmInit(QHsm *me, QEvent const *e) {
   register QState s;
   REQUIRE(me->state__ == (QState)QHsm_top &&  /* HSM not executed */
           me->source__);  /* we are about to dereference source__ */
   s = me->state__;             /* save me->state__ in a temporary */
   (*(QPseudoState)me->source__)(me, e); /* top-most initial tran. */
                      /* initial transition must go one level deep */
   ASSERT(s == TRIGGER(me->state__, Q_EMPTY_SIG));
   s = me->state__;                        /* update the temporary */
   (*s)(me, &pkgStdEvt[Q_ENTRY_SIG]);           /* enter the state */
   while ((*s)(me, &pkgStdEvt[Q_INIT_SIG]) == 0) {/* init handled? */
                      /* initial transition must go one level deep */
      ASSERT(s == TRIGGER(me->state__, Q_EMPTY_SIG));
      s = me->state__;
      (*s)(me, &pkgStdEvt[Q_ENTRY_SIG]);     /* enter the substate */
   }
}
//...................................................................
int QHsmIsIn(QHsm const *me, QState state) {
   register QState s;
   for (s = me->state__; s;        /* traverse the state hierarchy */
       (QState)(*me->source__)((QHsm *)me, &pkgStdEvt[Q_EMPTY_SIG])) 
   {
      if (s == state) {                    /* do the states match? */
         return !0;                    /* match found, return true */
      }
   }
   return 0;                       /* no match found, return false */
} 
//...................................................................
void QHsmTranStat_(QHsm *me, Tran_ *tran, QState target) {
   register QState s;
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
   if (tran->chain[0] == 0) {   /* is the tran object initialized? */
      QHsmTranSetup__(me, tran, target);   /* setup the transition */
   }
   else {      /* transition initialized, execute transition chain */
      register QState *c = &tran->chain[0];
      register unsigned short a;
      for (a = tran->actions; a; a >>= 2, ++c) {
         (*(*c))(me, &pkgStdEvt[a & 3]);
      }
      me->state__ = *c;
   }
}
//...................................................................
void QHsmDispatch(QHsm *me, QEvent const *e) {
  for (me->source__ = me->state__; me->source__;
       me->source__ = (QState)(*me->source__)(me, e)) 
  {}
}
//...................................................................
void QHsmTranSetup__(QHsm *me, Tran_ *tran, QState target) {
   QState entry[8], p, q, s, *c, *e, *lca;
   unsigned short a = 0;

   #define RECORD(state_, sig_) \
      if (TRIGGER(state_, sig_) == 0) {\
         a |= ((sig_) << 14); \
         a >>= 2; \
         *c++ = (state_); \
      } else ((void)0)

   c = &tran->chain[0];
   *(e = &entry[0]) = 0;
   *(++e) = target;                      /* assume entry to target */

   /* (a) check source == target (transition to self) */
   if (me->source__ == target) {
      RECORD(me->source__, Q_EXIT_SIG);             /* exit source */
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
      RECORD(me->source__, Q_EXIT_SIG);             /* exit source */
      goto inLCA;
   }
   /* (d) check me->source->super == target */
   if (q == target) {
      RECORD(me->source__, Q_EXIT_SIG);             /* exit source */
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
   RECORD(me->source__, Q_EXIT_SIG);                /* exit source */
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
      RECORD(s, Q_EXIT_SIG);                             /* exit s */
   }   
   ASSERT(0);                                     /* malformed HSM */
inLCA:         /* now we are in the LCA of me->source__ and target */
   ASSERT(e < &entry[sizeof(entry)/sizeof(*entry)]); /* entry fits */
   while (s = *e--) {   /* retrace the entry path in reverse order */
      RECORD(s, Q_ENTRY_SIG);                           /* enter s */
   }
   me->state__ = target;                   /* update current state */
   while (TRIGGER(target, Q_INIT_SIG) == 0) {
                       /* initial transition must go one level deep*/
      ASSERT(target == TRIGGER(me->state__, Q_EMPTY_SIG));
      a |= (Q_INIT_SIG << 14);
      a >>= 2;
      *c++ = target;
      target = me->state__;
      RECORD(target, Q_ENTRY_SIG);                 /* enter target */
   }
   #undef RECORD
   *c = target;
   tran->actions = a >> (14 - (c - &tran->chain[0])*2);
   ENSURE(tran->chain[0] != 0 &&         /* transition initialized */
          c < &tran->chain[sizeof(tran->chain)/
                     sizeof(*tran->chain)]);      /* chain fits in */
}
