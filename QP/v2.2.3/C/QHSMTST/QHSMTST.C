/********************************************************************
 * QHsmTst Example definition
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
 * All Rights Reserved.
 *******************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "qhsm.h"

enum QHsmTstSignals {
   A_SIG = Q_USER_SIG, 
   B_SIG, C_SIG, D_SIG, E_SIG, F_SIG, G_SIG, H_SIG
};
/*.................................................................*/
SUBCLASS(QHsmTst, QHsm)
   int foo__;                   /* private extended state variable */
METHODS
   QHsmTst *QHsmTstCtor(QHsmTst *me);

   void QHsmTst_initial(QHsmTst *me, QEvent const *e);
   QSTATE QHsmTst_s0(QHsmTst*me, QEvent const *e);  
      QSTATE QHsmTst_s1(QHsmTst*me, QEvent const *e);  
         QSTATE QHsmTst_s11(QHsmTst*me, QEvent const *e);  
      QSTATE QHsmTst_s2(QHsmTst*me, QEvent const *e);  
         QSTATE QHsmTst_s21(QHsmTst*me, QEvent const *e);  
            QSTATE QHsmTst_s211(QHsmTst*me, QEvent const *e);  
END_CLASS
/*.................................................................*/
QHsmTst *QHsmTstCtor(QHsmTst *me) {
   QHsmCtor_(&me->super_, (QPseudoState)QHsmTst_initial);
   return me;
}
/*.................................................................*/
void QHsmTst_initial(QHsmTst *me, QEvent const *e) {
   printf("top-INIT;");
   me->foo__ = 0;            /* initialize extended state variable */
   Q_INIT(QHsmTst_s0);
}
/*.................................................................*/
QSTATE QHsmTst_s0(QHsmTst *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG: printf("s0-ENTRY;"); return 0;
   case Q_EXIT_SIG: printf("s0-EXIT;");  return 0;
   case Q_INIT_SIG: printf("s0-INIT;"); Q_INIT(QHsmTst_s1); return 0;
   case E_SIG:      printf("s0-E;"); Q_TRAN(QHsmTst_s211);  return 0;
   }
   return (QSTATE)QHsm_top;
}
/*.................................................................*/
QSTATE QHsmTst_s1(QHsmTst *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG: printf("s1-ENTRY;"); return 0;
   case Q_EXIT_SIG: printf("s1-EXIT;");   return 0;
   case Q_INIT_SIG: printf("s1-INIT;");Q_INIT(QHsmTst_s11); return 0;
   case A_SIG:      printf("s1-A;");   Q_TRAN(QHsmTst_s1);  return 0;
   case B_SIG:      printf("s1-B;");   Q_TRAN(QHsmTst_s11); return 0;
   case C_SIG:      printf("s1-C;");   Q_TRAN(QHsmTst_s2);  return 0;
   case D_SIG:      printf("s1-D;");   Q_TRAN(QHsmTst_s0);  return 0;
   case F_SIG:      printf("s1-F;");   Q_TRAN(QHsmTst_s211);return 0;
   } 
   return (QSTATE)QHsmTst_s0;
}
/*.................................................................*/
QSTATE QHsmTst_s11(QHsmTst *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG: printf("s11-ENTRY;"); return 0;
   case Q_EXIT_SIG:  printf("s11-EXIT;");  return 0;
   case G_SIG:  printf("s11-G;"); Q_TRAN(QHsmTst_s211); return 0;
   case H_SIG:                 /* internal transition with a guard */
      if (me->foo__) {                 /* test the guard condition */
         printf("s11-H;");
         me->foo__ = 0;
         return 0;
      }
      break;
   } 
   return (QSTATE)QHsmTst_s1;
}
/*.................................................................*/
QSTATE QHsmTst_s2(QHsmTst *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG: printf("s2-ENTRY;"); return 0;
   case Q_EXIT_SIG: printf("s2-EXIT;");   return 0;
   case Q_INIT_SIG: printf("s2-INIT;");Q_INIT(QHsmTst_s21); return 0;
   case C_SIG:      printf("s2-C;");   Q_TRAN(QHsmTst_s1);  return 0;
   case F_SIG:      printf("s2-F;");   Q_TRAN(QHsmTst_s11); return 0;
   } 
   return (QSTATE)QHsmTst_s0;
}
/*.................................................................*/
QSTATE QHsmTst_s21(QHsmTst *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG: printf("s21-ENTRY;"); return 0;
   case Q_EXIT_SIG: printf("s21-EXIT;");   return 0;
   case Q_INIT_SIG:printf("s21-INIT;");Q_INIT(QHsmTst_s211);return 0;
   case B_SIG:     printf("s21-C;");   Q_TRAN(QHsmTst_s211);return 0;
   case H_SIG:                     /* self transition with a guard */
      if (!me->foo__) {                /* test the guard condition */
         printf("s21-H;");
         me->foo__ = !0;
         Q_TRAN(QHsmTst_s21);                   /* self transition */
         return 0;
      }
      break;                     /* break to return the superstate */
   } 
   return (QSTATE)QHsmTst_s2;
}
/*.................................................................*/
QSTATE QHsmTst_s211(QHsmTst *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG: printf("s211-ENTRY;"); return 0;
   case Q_EXIT_SIG:  printf("s211-EXIT;");  return 0;
   case D_SIG: printf("s211-D;"); Q_TRAN(QHsmTst_s21); return 0;
   case G_SIG: printf("s211-G;"); Q_TRAN(QHsmTst_s0);  return 0;
   } 
   return (QSTATE)QHsmTst_s21;
}
/*.................................................................*/
static const QEvent testQEvt[] = { 
   {A_SIG, 0, 0}, {B_SIG, 0, 0}, {C_SIG, 0, 0}, {D_SIG, 0, 0}, 
   {E_SIG, 0, 0}, {F_SIG, 0, 0}, {G_SIG, 0, 0}, {H_SIG, 0, 0} 
};
static QHsmTst test;         
/*.................................................................*/
int main() {
   printf("QHsmTst example, version 1.00, libraries: %s\n", 
           QHsmGetVersion());
   QHsmTstCtor(&test);
   QHsmInit((QHsm *)&test, 0);       /* trigger initial transition */
   for (;;) {
      char c;
      printf("\nSignal<-");
      c = getc(stdin); 
      getc(stdin);                                 /* discard '\n' */
      if (c < 'a' || 'h' < c) {
         return 0; 
      }
      QHsmDispatch((QHsm *)&test, &testQEvt[c - 'a']); /* dispatch */
   }
   return 0;
}
/*.................................................................*/
void onAssert__(char const *file, unsigned line) {
   fprintf(stderr, "Assertion failed in %s, line %d", file, line);
   exit(-1); 
}
