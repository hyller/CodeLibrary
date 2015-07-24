/********************************************************************
 * QP hook.c -- Ultimate Hook state pattern example
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
 * All Rights Reserved.
 *******************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "qassert.h"

DEFINE_THIS_FILE;

#include "qf_win32.h"

/*.................................................................*/
SUBCLASS(UltimateHook, QHsm) 
METHODS
   UltimateHook *UltimateHookCtor(UltimateHook *me);
   void UltimateHook_initial(UltimateHook *me, QEvent const *e);
   QSTATE UltimateHook_generic(UltimateHook *me, QEvent const *e);
     QSTATE UltimateHook_specific(UltimateHook *me, QEvent const *e);
   QSTATE UltimateHook_final(UltimateHook *me, QEvent const *e);
END_CLASS
/*.................................................................*/
enum UltimateHookSignals {
   A_SIG = Q_USER_SIG, B_SIG, C_SIG, D_SIG
};
/*.................................................................*/
UltimateHook *UltimateHookCtor(UltimateHook *me) {
   QHsmCtor_(&me->super_,(QPseudoState)&UltimateHook_initial);
   return me;
}
/*.................................................................*/
void UltimateHook_initial(UltimateHook *me, QEvent const *e) {
   Q_INIT(&UltimateHook_generic);
}
/*.................................................................*/
QSTATE UltimateHook_final(UltimateHook *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG: exit(0); return 0;
   }
   return (QSTATE)&QHsm_top;   
}
/*.................................................................*/
QSTATE UltimateHook_generic(UltimateHook *me, QEvent const *e) {
   switch (e->sig) {
   case Q_INIT_SIG:
      printf("generic:init;");
      Q_INIT(&UltimateHook_specific);
      return 0;
   case A_SIG: printf("generic:A;");   return 0;
   case B_SIG: printf("generic:B;");   return 0;
   case C_SIG:
      printf("generic:C(reset);");
      Q_TRAN(&UltimateHook_generic);
      return 0;
   case D_SIG: Q_TRAN(&UltimateHook_final); return 0;
   }
   return (QSTATE)&QHsm_top;
}
/*.................................................................*/
QSTATE UltimateHook_specific(UltimateHook *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG: printf("specific:entry;"); return 0;
   case Q_EXIT_SIG:  printf("specific:exit;");  return 0;
   case A_SIG:       printf("specific:A;");     return 0;
   }
   return (QSTATE)&UltimateHook_generic;
}
/*-----------------------------------------------------------------*/
static UltimateHook test;         

static const QEvent testQEvt[] = { 
   { A_SIG, 0, 0 }, { B_SIG, 0, 0 }, { C_SIG, 0, 0 }, { D_SIG, 0, 0 } 
};
/*.................................................................*/
void onAssert__(char const *file, unsigned line) {
   fprintf(stderr, "Assertion failed in %s, line %d", file, line);
   exit(-1); 
}
/*.................................................................*/
int main() {
   printf("Ultimate Hook pattern, version 1.00, libraries: %s\n", 
           QHsmGetVersion());
   UltimateHookCtor(&test);                  /* explicit Ctor call */
   QHsmInit((QHsm *)&test, 0);      /* take the initial transition */
   for (;;) {
      char c;
      printf("\nSignal<-");
      c = getc(stdin); 
      getc(stdin); /* discard '\n' */
      if (c < 'a' || 'd' < c) {
         c = 'd'; /* exit */
      }
      QHsmDispatch((QHsm *)&test, &testQEvt[c - 'a']);
   }
   return 0;
}
