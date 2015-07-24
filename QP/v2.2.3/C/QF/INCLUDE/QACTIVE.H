/******************************************************************** 
 * Quantum Active Object declaration (C version)
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA.
 * All Rights Reserved.
 *******************************************************************/
#ifndef qactive_h
#define qactive_h

#ifndef qhsm_h
   #include "qhsm.h"
#endif

SUBCLASS(QActive, QHsm)
   QF_EQUEUE(eQueue__)       /* OS-dependent event-queue primitive */
   QF_THREAD(thread__)            /* OS-dependent thread primitive */
   unsigned char prio__;          /* priority of the active object */
   /* friend class QF */
VTABLE(QActive, QHsm)
METHODS
/* public methods */
   int QActiveStart(QActive *me, unsigned prio, 
                    QEvent *qSto[], unsigned qLen,
                    int stkSto[], unsigned stkLen);
   void QActivePostFIFO(QActive *me, QEvent *e);
   void QActivePostLIFO(QActive *me, QEvent *e);
/* protected methods ...*/
   QActive *QActiveCtor_(QActive *me, QPseudoState initial); 
   void QActiveXtor_(QActive *me); 
   void QActiveStop_(QActive *me);            /* stopps the thread */
/* private methods ... */
   int QActiveEnqueue__(QActive *me, QEvent *e);
   /* friend class QF; */
END_CLASS

#endif                                                /* qactive_h */
