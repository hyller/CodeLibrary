/******************************************************************** 
 * Quantum Timer declarations ("C+" version)
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA.
 * All Rights Reserved.
 *******************************************************************/
#ifndef qtimer_h
#define qtimer_h

#ifndef qevent_h
   #include "qevent.h"
#endif

CLASS(QTimer)
    QTimer *next__;                  /* to link timers in the list */
    QEvent toutEvt__;            /* timeout event instance to send */
    QActive *active__;
    unsigned short ctr__;
    unsigned short interval__;
    /* friend class QF; */ 
METHODS
    void QTimerFireIn(QTimer *me, QActive *act, 
                      QSignal toutSig, unsigned nTicks);
    void QTimerFireEvery(QTimer *me, QActive *act, 
                         QSignal toutSig, unsigned nTicks);
    void QTimerDisarm(QTimer *me);    
    void QTimerRearm(QTimer *me, unsigned nTicks);
END_CLASS

#endif                                                 /* qtimer_h */
