/******************************************************************** 
 * Quantum Finite State Machine declarations ("C+" version)
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA.
 * All Rights Reserved.
 *******************************************************************/
#ifndef qfsm_h
#define qfsm_h

#ifndef qevent_h
   #include "qevent.h"
#endif

typedef void (*QFsmState)(struct QFsm *, QEvent const *);

SUBCLASS(QFsm, Object)  /* Quantum Finite State Machine base class */
   QFsmState state__;                          /* the active state */
VTABLE(QFsm, Object)
METHODS
/* public methods */
   #define QFsmInit(me_, e_) ((*(me_)->state__)((me_), (e_))) 
                                               /* "inline" methods */
   #define QFsmDispatch(me_, e_) (*(me_)->state__)((me_), (e_))
   #define QFsmGetState(me_) ((me_)->state__)

/* protected methods */
   QFsm *QFsmCtor_(QFsm *me, QFsmState initial);           /* Ctor */
   void QFsmXtor_(QFsm *me);                               /* Xtor */
   #define QFSM_TRAN(target_) \
      (((QFsm *)me)->state__ = (QFsmState)(target_))
                               /* static methods (no "me" pointer) */
   char const *QFsmGetVersion(void);
END_CLASS 

#endif                                                   /* qfsm_h */
