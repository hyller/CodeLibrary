/////////////////////////////////////////////////////////////////////
// QHsmTst example
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#include <stdlib.h>
#include <stdio.h>
#include "qf_win32.h"

enum QHsmTstSignals {
   A_SIG = Q_USER_SIG, B_SIG, C_SIG, 
   D_SIG, E_SIG, F_SIG, G_SIG, H_SIG
};

class QHsmTst : public QHsm {
public:
   QHsmTst() : QHsm((QPseudoState)initial) {}
protected:
   void initial(QEvent const *e);              // initial pseudostate
   QSTATE s0(QEvent const *e);                       // state-handler
      QSTATE s1(QEvent const *e);                    // state-handler
         QSTATE s11(QEvent const *e);                // state-handler 
      QSTATE s2(QEvent const *e);                    // state-handler
         QSTATE s21(QEvent const *e);                // state-handler
            QSTATE s211(QEvent const *e);            // state-handler
private:                               // extended state variables...
   int myFoo;
};

void QHsmTst::initial(QEvent const *) {
   printf("top-INIT;"); 
   myFoo = 0;                   // initialize extended state variable
   Q_INIT(&QHsmTst::s0);                        // initial transition
}

QSTATE QHsmTst::s0(QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG: printf("s0-ENTRY;"); return 0;
   case Q_EXIT_SIG:  printf("s0-EXIT;");  return 0;
   case Q_INIT_SIG:  printf("s0-INIT;");  Q_INIT(&QHsmTst::s1);   
      return 0;
   case E_SIG: printf("s0-E;"); Q_TRAN(&QHsmTst::s211); return 0;
   }
   return (QSTATE)&QHsmTst::top;
}

QSTATE QHsmTst::s1(QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG: printf("s1-ENTRY;"); return 0;
   case Q_EXIT_SIG:  printf("s1-EXIT;");  return 0;
   case Q_INIT_SIG:  printf("s1-INIT;");  Q_INIT(&QHsmTst::s11);
      return 0;
   case A_SIG: printf("s1-A;"); Q_TRAN(&QHsmTst::s1);   return 0;
   case B_SIG: printf("s1-B;"); Q_TRAN(&QHsmTst::s11);  return 0;
   case C_SIG: printf("s1-C;"); Q_TRAN(&QHsmTst::s2);   return 0;
   case D_SIG: printf("s1-D;"); Q_TRAN(&QHsmTst::s0);   return 0;
   case F_SIG: printf("s1-F;"); Q_TRAN(&QHsmTst::s211); return 0;
   } 
   return (QSTATE)&QHsmTst::s0;
}

QSTATE QHsmTst::s11(QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG: printf("s11-ENTRY;"); return 0;
   case Q_EXIT_SIG:  printf("s11-EXIT;");  return 0;
   case G_SIG: printf("s11-G;"); Q_TRAN(&QHsmTst::s211); return 0;
   case H_SIG:                    // internal transition with a guard
      if (myFoo) {                        // test the guard condition
         printf("s11-H;");
         myFoo = 0;
         return 0;
      }
      break;
   } 
   return (QSTATE)&QHsmTst::s1;
}

QSTATE QHsmTst::s2(QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG: printf("s2-ENTRY;"); return 0;
   case Q_EXIT_SIG:  printf("s2-EXIT;");  return 0;
   case Q_INIT_SIG:  printf("s2-INIT;");  Q_INIT(&QHsmTst::s21); 
      return 0;
   case C_SIG: printf("s2-C;"); Q_TRAN(&QHsmTst::s1);  return 0;
   case F_SIG: printf("s2-F;"); Q_TRAN(&QHsmTst::s11); return 0;
   } 
   return (QSTATE)&QHsmTst::s0;
}

QSTATE QHsmTst::s21(QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG: printf("s21-ENTRY;"); return 0;
   case Q_EXIT_SIG:  printf("s21-EXIT;");  return 0;
   case Q_INIT_SIG:  printf("s21-INIT;");  Q_INIT(&QHsmTst::s211); 
      return 0;
   case B_SIG: printf("s21-B;"); Q_TRAN(&QHsmTst::s211); return 0;
   case H_SIG:                        // self transition with a guard
      if (!myFoo) {                       // test the guard condition
         printf("s21-H;");
         myFoo = 1;
         Q_TRAN(&QHsmTst::s21);                    // self transition
         return 0;
      }
      break;                        // break to return the superstate
   } 
   return (QSTATE)&QHsmTst::s2;              // return the superstate
}

QSTATE QHsmTst::s211(QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG: printf("s211-ENTRY;"); return 0;
   case Q_EXIT_SIG:  printf("s211-EXIT;");  return 0;
   case D_SIG: printf("s211-D;"); Q_TRAN(&QHsmTst::s21); return 0;
   case G_SIG: printf("s211-G;"); Q_TRAN(&QHsmTst::s0);  return 0;
   } 
   return (QSTATE)&QHsmTst::s21;
}

static const QEvent testQEvt[] = { 
   {A_SIG, 0, 0}, {B_SIG, 0, 0}, {C_SIG, 0, 0}, {D_SIG, 0, 0}, 
   {E_SIG, 0, 0}, {F_SIG, 0, 0}, {G_SIG, 0, 0}, {H_SIG, 0, 0}
};
static QHsmTst test;         

int main() {
   printf("QHsmTst example, version 1.00, libraries: %s\n", 
           QHsm::getVersion());
   test.init();                        // take the initial transition
   for (;;) {
      printf("\nSignal<-");
      char c = getc(stdin); 
      getc(stdin);                                    // discard '\n'
      if (c < 'a' || 'h' < c) {                          // in range?
         return 0; 
      }
      test.dispatch(&testQEvt[c - 'a']);            // dispatch event
   }
   return 0;
}

extern "C" void onAssert__(char const *file, unsigned line) {
   fprintf(stderr, "Assertion failed in %s, line %d", file, line);
   exit(-1); 
}

