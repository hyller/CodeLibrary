/////////////////////////////////////////////////////////////////////
// Quantum Hierarchical State Machine definition
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#include "qassert.h"
#include "port.h"

DEFINE_THIS_FILE;

                                                      // helper macro
#define TRIGGER(state_, sig_) state_(this, &pkgStdEvt[sig_])

//...................................................................
char const *QHsm::getVersion() { 
   return "QHsm/MI 1.0.0";
}
//...................................................................
QHsm::QHsm(CQState::QState initial) 
   : myState(&QHsm::top), mySource(initial)
{}
//...................................................................
QHsm::~QHsm() {
}
//...................................................................
void QHsm::init() {
   REQUIRE(myState == &QHsm::top &&        /* HSM not executed yet */
           mySource);      /* we are about to dereference mySource */
   register CQState s = myState;       // save myState in a temporary
   mySource(this, NULL);
   ASSERT(s == TRIGGER(myState, Q_EMPTY_SIG));
   s = myState;                               // update the temporary
   TRIGGER(s, Q_EMPTY_SIG);
   while (!TRIGGER(s, Q_INIT_SIG)) {
      ASSERT(s == TRIGGER(myState, Q_EMPTY_SIG));
      s = myState;
      TRIGGER(s, Q_ENTRY_SIG);
   }
}
//...................................................................
int QHsm::isIn(CQState state) {
   register CQState s;
   for (s = myState; s; s = TRIGGER(mySource, Q_EMPTY_SIG)) {
      if (s == state) {                       // do the states match?
         return !0;                       // match found, return true
      }
   }
   return 0;                          // no match found, return false
} 
//...................................................................
void QHsm::tranStat(Tran *tran, CQState target) {
   REQUIRE(target != &QHsm::top);
   register CQState s;
   for (s = myState; s != mySource; ) {
      ASSERT(s);                     // we are about to dereference s
      CQState t = TRIGGER(s, Q_EXIT_SIG);
      if (t) {       // exit action unhandled, t points to superstate
         s = t;
      }
      else {                // exit action handled, elicit superstate
         s = TRIGGER(s, Q_EMPTY_SIG);
      }
   }
   if (!tran->myChain[0]) {        // is the tran object initialized?
      tranSetup(tran, target);         // setup the transition object
   }
   else {  // transition object initialized, execute transition chain
      register CQState *c = &tran->myChain[0];
      register unsigned short a;
      for (a = tran->myActions; a; a >>= 2, ++c) {
         (*c)(this, &pkgStdEvt[a&3]);
      }
      myState = *c;
   }
}
//...................................................................
void QHsm::dispatch(QEvent const *e) {
   for (mySource = myState; mySource; mySource = mySource(this, e)) {
   }
}
//...................................................................
void QHsm::tranSetup(Tran *tran, CQState target) {
   CQState entry[8], p, q, s, *c, *e, *lca;
   unsigned short a = 0;

   #define RECORD(state_, sig_) \
      if (!TRIGGER(state_, sig_)) {\
         a |= ((sig_) << 14);   \
         a >>= 2;               \
         *c++ = (state_);       \
      } else ((void)0)

   c = &tran->myChain[0];
   *(e = &entry[0]) = 0;
   *(++e) = target;                         // assume entry to target

   // (a) check mySource == target (transition to self)
   if (mySource == target) {
      RECORD(mySource, Q_EXIT_SIG);                    // exit source
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
      RECORD(mySource, Q_EXIT_SIG);                    // exit source
      goto inLCA;
   }
   // (d) check mySource->super == target
   if (q == target) {
      RECORD(mySource, Q_EXIT_SIG);                    // exit source
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
   RECORD(mySource, Q_EXIT_SIG);                       // exit source
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
      RECORD(s, Q_EXIT_SIG);                                // exit s
   }   
   ASSERT(0);                                        // malformed HSM
inLCA:                // now we are in the LCA of mySource and target
   ASSERT(e < &entry[DIM(entry)]);         // new entry e must fit in
   while (s = *e--) {      // retrace the entry path in reverse order
      RECORD(s, Q_ENTRY_SIG);                              // enter s
   }
   myState = target;                          // update current state
   while (!TRIGGER(target, Q_INIT_SIG)) {
      ASSERT(target == TRIGGER(myState, Q_EMPTY_SIG));
      a |= (Q_INIT_SIG << 14);
      a >>= 2;
      *c++ = target;
      target = myState;
      RECORD(target, Q_ENTRY_SIG);                    // enter target
   }
   #undef DISPATCH
   *c = target;
   tran->myActions = a >> (14 - (c - &tran->myChain[0])*2);
   ENSURE(tran->myChain[0] &&            /* transition initialized */
          c < &tran->myChain[DIM(tran->myChain)]); /*check overflow*/
}
