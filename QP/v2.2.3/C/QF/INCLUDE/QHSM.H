/******************************************************************** 
 * Quantum Hierarchical State Machine declarations ("C+" version)
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA.
 * All Rights Reserved.
 *******************************************************************/
#ifndef qhsm_h
#define qhsm_h

#ifndef qevent_h
   #include "qevent.h"
#endif

typedef void (*QPseudoState)(struct QHsm *, QEvent const *);
typedef QPseudoState (*QState)(struct QHsm *, QEvent const *);
typedef QPseudoState QSTATE;  /* return value from a state-handler */

SUBCLASS(QHsm, Object)    /* Hierarchical State Machine base class */
   QState state__;                             /* the active state */
   QState source__;             /* source state during a transiton */
VTABLE(QHsm, Object)
METHODS
/* public members */
   void QHsmInit(QHsm *me, QEvent const *e); /* initial transition */
   void QHsmDispatch(QHsm *me, QEvent const *e);  /* take RTC step */
   int QHsmIsIn(QHsm const *me,QState state);     /* "is-in" query */
                                /* static method (no "me" pointer) */
   char const *QHsmGetVersion(void);

/* protected members */
   CLASS(Tran_)                     /* protected inner class Tran_ */
      QState chain[8];
      unsigned short actions;   /* action mask (2-bits for action) */
   METHODS
   END_CLASS

   QHsm *QHsmCtor_(QHsm *me, QPseudoState initial);        /* Ctor */
   void QHsmXtor_(QHsm *me);                               /* Xtor */

   QSTATE QHsm_top(QHsm *me, QEvent const *);       /* "top" state */
   #define QHsmGetState_(me_) ((me_)->state__)
   void QHsmTran_(QHsm *me, QState target);  /* dynamic transition */
   void QHsmTranStat_(QHsm *me, Tran_ *t, QState target);
   #define Q_INIT(target_) (((QHsm*)me)->state__ = (QState)(target_))
   #define Q_TRAN(target_) if (1) { \
      static Tran_ t_;              \
      QHsmTranStat_((QHsm *)me, &t_, (QState)(target_));\
   } else
   #define Q_TRAN_DYN(target_) \
      QHsmTran_((QHsm *)me, (QState)(target_))
/* private methods */
   void QHsmTranSetup__(QHsm *me, Tran_ *t, QState target);
END_CLASS 


    /* helper macro to calculate static dimension of a 1-dim array */
#define DIM(array_) (sizeof(array_)/sizeof(*(array_)))

#endif                                                   /* qhsm_h */
