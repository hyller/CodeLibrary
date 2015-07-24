/******************************************************************** 
 * Quantum Framework OS-independent declaration ("C+" version)
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA.
 * All Rights Reserved.
 *******************************************************************/
#ifndef qf_h
#define qf_h

         /* densly packet 32-bit "list" of subscriber active objects,
          * allocating 4-bits per active object-id allows to store 
          * up to 8 subscribers in this "list"
          */ 
typedef unsigned long QSubscrList;

/* class QF */
/* public methods */
void QFinit(QSubscrList subscr[], unsigned maxSignal);
void QFcleanup();
void QFpoolInit(QEvent *poolSto, 
                unsigned nEvts, unsigned evtSize);
void QFtick();
char const *QFgetVersion(); 
QEvent *QFcreate(unsigned evtSize, QSignal sig);
#define Q_NEW(evtT_, sig_) \
       ((evtT_ *)QFcreate(sizeof(evtT_), (sig_)))
void QFsubscribe(QActive *a, QSignal sig);
void QFunsubscribe(QActive *a, QSignal sig);
void QFpublish(QEvent *e);                        /* publish event */

void QFbackground();     /* for foreground/background systems only */

/* private methods (internal interface for QActive only) */
void QFosInit__();
void QFosCleanup__();
void QFadd__(QActive *a);
void QFremove__(QActive *a);
void QFpropagate__(QEvent *e);     /* propagate to next subsrciber */
void QFannihilate__(QEvent *e);

#endif                                                     /* qf_h */
