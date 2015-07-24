/////////////////////////////////////////////////////////////////////
// QP hook.cpp -- Ultimate Hook state pattern example
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#include <stdlib.h>
#include <stdio.h>
#include "qassert.h"

DEFINE_THIS_FILE;

#include "qf_win32.h"

class UltimateHook : public QHsm {
protected:
   void initial(QEvent const *e);
   QSTATE generic(QEvent const *e);
      QSTATE specific(QEvent const *e);
   QSTATE final(QEvent const *e);
public:
   UltimateHook() : QHsm((QPseudoState)initial) {}
};

enum UltimateHookSignals {
   A_SIG = Q_USER_SIG, B_SIG, C_SIG, D_SIG
};

//...................................................................
void UltimateHook::initial(QEvent const *) { 
   Q_INIT(&UltimateHook::generic);
}
//...................................................................
QSTATE UltimateHook::final(QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:  exit(0); return 0;
   }
   return (QSTATE)&UltimateHook::top;   
}
//...................................................................
QSTATE UltimateHook::generic(QEvent const *e) {
   switch (e->sig) {
   case Q_INIT_SIG:
      printf("generic:init;");
      Q_INIT(&UltimateHook::specific);
      return 0;
   case A_SIG: printf("generic:A;");   return 0;
   case B_SIG: printf("generic:B;");   return 0;
   case C_SIG:
      printf("generic:C(reset);");
      Q_TRAN(&UltimateHook::generic);
      return 0;
   case D_SIG: Q_TRAN(&UltimateHook::final); return 0;
   }
   return (QSTATE)&UltimateHook::top;
}
//...................................................................
QSTATE UltimateHook::specific(QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG: printf("specific:entry;"); return 0;
   case Q_EXIT_SIG:  printf("specific:exit;");  return 0;
   case A_SIG:       printf("specific:A;");     return 0;
   }
   return (QSTATE)&UltimateHook::generic;
}
//-------------------------------------------------------------------
static UltimateHook test;         

static const QEvent testQEvt[] = { 
   { A_SIG, 0, 0 }, { B_SIG, 0, 0 }, { C_SIG, 0, 0 }, { D_SIG, 0, 0 } 
};
//...................................................................
extern "C" void onAssert__(char const *file, unsigned line) {
   fprintf(stderr, "Assertion failed in %s, line %d", file, line);
   exit(-1); 
}
//...................................................................
int main() {
   printf("Ultimate Hook pattern, version 1.00, libraries: %s\n", 
           QHsm::getVersion());
   test.init();
   for (;;) {
      char c;
      printf("\nSignal<-");
      c = getc(stdin); 
      getc(stdin); // discard '\n'
      if (c < 'a' || 'd' < c) {
         c = 'd'; // exit
      }
      test.dispatch(&testQEvt[c - 'a']); 
   }
   return 0;
}
