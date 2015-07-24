/******************************************************************** 
 * Quantum Finite State Machine declarations (C version)
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA.
 * All Rights Reserved.
 *******************************************************************/
#include "qfsm.h"

char const *QFsmGetVersion() { 
   return "QFSM 1.0.0";
}
/*.................................................................*/
BEGIN_VTABLE(QFsm, Object)       /* declare v-table for QFsm class */
   VMETHOD(Object, xtor) = (void (*)(Object *))QFsmXtor_;
END_VTABLE
/*.................................................................*/
QFsm *QFsmCtor_(QFsm *me, QFsmState initial) {
   ObjectCtor_(&me->super_);              /* construct superclass  */
   VHOOK(QFsm);          /* hook the v-pointer to the QFsm v-table */
   me->state__ = initial;
   return me;
} 
/*.................................................................*/
void QFsmXtor_(QFsm *me) {
   ObjectXtor_(&me->super_);                /* destroy superclass  */
}