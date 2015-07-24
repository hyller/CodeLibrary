/********************************************************************
 * QP history.c -- History state pattern example
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
 * All Rights Reserved.
 *******************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "qassert.h"

DEFINE_THIS_FILE;

#include "qf_win32.h"

/*.................................................................*/
enum ToasterOvenSignals {
   OPEN_SIG = Q_USER_SIG, 
   CLOSE_SIG, TOAST_SIG, BAKE_SIG, OFF_SIG, END_SIG
};
/*.................................................................*/
SUBCLASS(ToasterOven, QHsm)
   QState doorClosedHistory__;
METHODS
   ToasterOven *ToasterOvenCtor(ToasterOven *me);
   void ToasterOven_initial(ToasterOven *me, QEvent const *e);
   QSTATE ToasterOven_doorClosed(ToasterOven *me, QEvent const *e);
      QSTATE ToasterOven_off(ToasterOven *me, QEvent const *e);
      QSTATE ToasterOven_heating(ToasterOven *me, QEvent const *e);
         QSTATE ToasterOven_toasting(ToasterOven *me, QEvent const *e);
         QSTATE ToasterOven_baking(ToasterOven *me, QEvent const *e);
   QSTATE ToasterOven_doorOpen(ToasterOven *me, QEvent const *e);
   QSTATE ToasterOven_final(ToasterOven *me, QEvent const *e);
END_CLASS
/*.................................................................*/
ToasterOven *ToasterOvenCtor(ToasterOven *me) {
   if (!QHsmCtor_(&me->super_, (QPseudoState)&ToasterOven_initial)) {
      return 0;
   }
   return me;
}
/*.................................................................*/
void ToasterOven_initial(ToasterOven *me, QEvent const *e) {
   me->doorClosedHistory__ = (QState)&ToasterOven_off;
   Q_INIT(&ToasterOven_doorClosed);
}
/*.................................................................*/
QSTATE ToasterOven_final(ToasterOven *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG: exit(0); return 0;
   }
   return (QSTATE)&QHsm_top;   
}
/*.................................................................*/
QSTATE ToasterOven_doorClosed(ToasterOven *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG: printf("door-Closed;");          return 0;
   case Q_EXIT_SIG:  
      me->doorClosedHistory__ = QHsmGetState_((QHsm *)me);
      return 0;
   case Q_INIT_SIG:  Q_INIT(&ToasterOven_off);        return 0;
   case OPEN_SIG:    Q_TRAN(&ToasterOven_doorOpen);   return 0;
   case TOAST_SIG:   Q_TRAN(&ToasterOven_toasting);   return 0;
   case BAKE_SIG:    Q_TRAN(&ToasterOven_baking);     return 0;
   case OFF_SIG:     Q_TRAN(&ToasterOven_off);        return 0;
   case END_SIG:     Q_TRAN(&ToasterOven_final);      return 0;
   }
   return (QSTATE)&QHsm_top;   
}
/*.................................................................*/
QSTATE ToasterOven_off(ToasterOven *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG: printf("toaster-Off;");          return 0;
   }
   return (QSTATE)&ToasterOven_doorClosed;
}
/*.................................................................*/
QSTATE ToasterOven_heating(ToasterOven *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG: printf("heater-On;");            return 0;
   case Q_EXIT_SIG:  printf("heater-Off;");           return 0;
   }
   return (QSTATE)&ToasterOven_doorClosed;
}
/*.................................................................*/
QSTATE ToasterOven_toasting(ToasterOven *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG: printf("toasting;");              return 0;
   }
   return (QSTATE)&ToasterOven_heating;
}
/*.................................................................*/
QSTATE ToasterOven_baking(ToasterOven *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG: printf("baking;");                return 0;
   }
   return (QSTATE)&ToasterOven_heating;
}
/*.................................................................*/
QSTATE ToasterOven_doorOpen(ToasterOven *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG: printf("door-Open,lamp-On;");     return 0;
   case Q_EXIT_SIG:  printf("lamp-Off;");              return 0;
   case CLOSE_SIG: 
      Q_TRAN_DYN(me->doorClosedHistory__);
      return 0;
   }
   return (QSTATE)&QHsm_top;
}
/*-----------------------------------------------------------------*/
void onAssert__(char const *file, unsigned line) {
   fprintf(stderr, "Assertion failed in %s, line %d", file, line);
   exit(-1); 
}
/*.................................................................*/
int main() {
   static ToasterOven test;         
   printf("Ultimate Hook pattern, version 1.00, libraries: %s\n", 
           QHsmGetVersion());
   ToasterOvenCtor(&test);                   /* explicit Ctor call */
   QHsmInit((QHsm *)&test, 0);      /* take the initial transition */
   for (;;) {
      char c;
      QEvent e;
      printf("\nSignal<-");
      c = getc(stdin); 
      getc(stdin); /* discard '\n' */
      switch (c) {
      case 'o': e.sig = OPEN_SIG;  break;
      case 'c': e.sig = CLOSE_SIG; break;
      case 't': e.sig = TOAST_SIG; break;
      case 'b': e.sig = BAKE_SIG;  break;
      case 'f': e.sig = OFF_SIG;   break;
      default:  e.sig = END_SIG;   break;
      }
      QHsmDispatch((QHsm *)&test, &e);
   }
   return 0;
}
