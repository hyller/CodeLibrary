/////////////////////////////////////////////////////////////////////
// QP history.cpp -- History state pattern example
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#include <stdlib.h>
#include <stdio.h>
#include "qassert.h"

DEFINE_THIS_FILE;

#include "qf_win32.h"

//...................................................................
enum ToasterOvenSignals {
   OPEN_SIG = Q_USER_SIG, 
   CLOSE_SIG, TOAST_SIG, BAKE_SIG, OFF_SIG, END_SIG
};
//...................................................................
class ToasterOven : public QHsm {
public:
   ToasterOven() : QHsm((QPseudoState)initial) {}
protected:
   void initial(QEvent const *e);
   QSTATE doorClosed(QEvent const *e);
      QSTATE off(QEvent const *e);
      QSTATE heating(QEvent const *e);
         QSTATE toasting(QEvent const *e);
         QSTATE baking(QEvent const *e);
   QSTATE doorOpen(QEvent const *e);
   QSTATE final(QEvent const *e);
private:
   QState myDoorClosedHistory;
};
//...................................................................
void ToasterOven::initial(QEvent const *) {
   myDoorClosedHistory = Q_STATIC_CAST(QState, &ToasterOven::off);
   Q_INIT(&ToasterOven::doorClosed);
}
//...................................................................
QSTATE ToasterOven::final(QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG: exit(0); return 0;
   }
   return (QSTATE)&ToasterOven::top;   
}
//...................................................................
QSTATE ToasterOven::doorClosed(QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG: printf("door-Closed;");           return 0;
   case Q_EXIT_SIG:  myDoorClosedHistory = getState(); return 0;
   case Q_INIT_SIG:  Q_INIT(&ToasterOven::off);        return 0;
   case OPEN_SIG:    Q_TRAN(&ToasterOven::doorOpen);   return 0;
   case TOAST_SIG:   Q_TRAN(&ToasterOven::toasting);   return 0;
   case BAKE_SIG:    Q_TRAN(&ToasterOven::baking);     return 0;
   case OFF_SIG:     Q_TRAN(&ToasterOven::off);        return 0;
   case END_SIG:     Q_TRAN(&ToasterOven::final);      return 0;
   }
   return (QSTATE)&ToasterOven::top;
}
//...................................................................
QSTATE ToasterOven::off(QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG: printf("toaster-Off;");           return 0;
   }
   return (QSTATE)&ToasterOven::doorClosed;
}
//...................................................................
QSTATE ToasterOven::heating(QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG: printf("heater-On;");             return 0;
   case Q_EXIT_SIG:  printf("heater-Off;");            return 0;
   }
   return (QSTATE)&ToasterOven::doorClosed;
}
//...................................................................
QSTATE ToasterOven::toasting(QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG: printf("toasting;");              return 0;
   }
   return (QSTATE)&ToasterOven::heating;
}
//...................................................................
QSTATE ToasterOven::baking(QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG: printf("baking;");                return 0;
   }
   return (QSTATE)&ToasterOven::heating;
}
//...................................................................
QSTATE ToasterOven::doorOpen(QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG: printf("door-Open,lamp-On;");     return 0;
   case Q_EXIT_SIG:  printf("lamp-Off;");              return 0;
   case CLOSE_SIG: 
      Q_TRAN_DYN(myDoorClosedHistory);
      return 0;
   }
   return (QSTATE)&ToasterOven::top;
}
//-------------------------------------------------------------------
extern "C" void onAssert__(char const *file, unsigned line) {
   fprintf(stderr, "Assertion failed in %s, line %d", file, line);
   exit(-1); 
}
//...................................................................
int main() {
   static ToasterOven test;         
   printf("Ultimate Hook pattern, version 1.00, libraries: %s\n", 
           QHsm::getVersion());
   test.init();
   for (;;) {
      char c;
      QEvent e;
      printf("\nSignal<-");
      c = getc(stdin); 
      getc(stdin); // discard '\n'
      switch (c) {
      case 'o': e.sig = OPEN_SIG;  break;
      case 'c': e.sig = CLOSE_SIG; break;
      case 't': e.sig = TOAST_SIG; break;
      case 'b': e.sig = BAKE_SIG;  break;
      case 'f': e.sig = OFF_SIG;   break;
      default:  e.sig = END_SIG;   break;
      }
      test.dispatch(&e); 
   }
   return 0;
}
