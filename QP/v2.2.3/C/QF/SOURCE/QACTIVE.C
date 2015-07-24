/******************************************************************** 
 * Quantum Active Object implemenatation ("C+" version)
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA.
 * All Rights Reserved.
 *******************************************************************/
#include "qassert.h"
#include "port.h"

DEFINE_THIS_FILE;

/*.................................................................*/
BEGIN_VTABLE(QActive, QHsm)    /* declare v-table for QActor class */
   VMETHOD(Object, xtor) = (void (*)(Object *))QActiveXtor_;
END_VTABLE
/*.................................................................*/
QActive *QActiveCtor_(QActive *me, QPseudoState initial) {
   if (!QHsmCtor_(&me->super_, (QPseudoState)initial)) {
      return 0;
   }
   VHOOK(QActive);    /* hook the v-pointer to the QActive v-table */
   return me;
} 
/*.................................................................*/
void QActiveXtor_(QActive *me) {
   QHsmXtor_(&me->super_);                   /* destroy superclass */
}
