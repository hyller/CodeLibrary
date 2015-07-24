/////////////////////////////////////////////////////////////////////
// Quantum Hierarchical State Machine dynamic transition definition
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#include "qassert.h"
#include "port.h"

DEFINE_THIS_FILE;
                                                      // helper macro
#define TRIGGER(state_, sig_) \
   Q_STATE_CAST((this->*(state_))(&pkgStdEvt[sig_]))

void QHsm::tran(QState target) {
   REQUIRE(target != &QHsm::top);        // cannot target "top" state
   QState entry[8], p, q, s, *e, *lca;
   for (s = myState; s != mySource; ) {
      ASSERT(s);                     // we are about to dereference s
      QState t = TRIGGER(s, Q_EXIT_SIG);
      if (t) {       // exit action unhandled, t points to superstate
         s = t;
      }
      else {                // exit action handled, elicit superstate
         s = TRIGGER(s, Q_EMPTY_SIG);
      }
   }

   *(e = &entry[0]) = 0;
   *(++e) = target;                         // assume entry to target

   // (a) check mySource == target (transition to self)
   if (mySource == target) {
      TRIGGER(mySource, Q_EXIT_SIG);                   // exit source
      goto inLCA;
   }
   // (b) check mySource == target->super
   p = TRIGGER(target, Q_EMPTY_SIG);
   if (mySource == p) {
      goto inLCA;
   }
   // (c) check mySource->super == target->super (most common)
   q = TRIGGER(mySource, Q_EMPTY_SIG);
   if (q == p) {
      TRIGGER(mySource, Q_EXIT_SIG);                   // exit source
      goto inLCA;
   }
   // (d) check mySource->super == target
   if (q == target) {
      TRIGGER(mySource, Q_EXIT_SIG);                   // exit source
      --e;                                    // do not enter the LCA
      goto inLCA;
   }
   // (e) check rest of mySource == target->super->super... hierarchy
   *(++e) = p;
   for (s = TRIGGER(p, Q_EMPTY_SIG); s;
        s = TRIGGER(s, Q_EMPTY_SIG)) 
   {
      if (mySource == s) {
         goto inLCA;
      }
      *(++e) = s;
   }
   TRIGGER(mySource, Q_EXIT_SIG);                      // exit source
   // (f) check rest of mySource->super == target->super->super...
   for (lca = e; *lca; --lca) {
      if (q == *lca) {
         e = lca - 1;                         // do not enter the LCA
         goto inLCA;
      }
   }
   // (g) check each mySource->super->super..for each target...
   for (s = q; s; s = TRIGGER(s, Q_EMPTY_SIG)) {
      for (lca = e; *lca; --lca) {
         if (s == *lca) {
            e = lca - 1;                      // do not enter the LCA
            goto inLCA;
         }
      }
      TRIGGER(s, Q_EXIT_SIG);                               // exit s
   }   
   ASSERT(0);                                        // malformed HSM
inLCA:                // now we are in the LCA of mySource and target
   ASSERT(e < &entry[DIM(entry)]);         // new entry e must fit in
   while (s = *e--) {      // retrace the entry path in reverse order
      TRIGGER(s, Q_ENTRY_SIG);                             // enter s
   }
   myState = target;                          // update current state
   while (TRIGGER(target, Q_INIT_SIG) == 0) {
                       // initial transition must go *one* level deep
      ASSERT(target == TRIGGER(myState, Q_EMPTY_SIG));
      target = myState;
      TRIGGER(target, Q_ENTRY_SIG);                   // enter target
   }
}
