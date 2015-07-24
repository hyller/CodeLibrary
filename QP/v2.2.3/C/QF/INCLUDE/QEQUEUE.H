/******************************************************************** 
 * Quantum Event Queue declaration ("C+" version)
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA.
 * All Rights Reserved.
 *******************************************************************/
#ifndef qequeue_h
#define qequeue_h

CLASS(QEQueue)                         /* event queue facility ... */
       /* OS-dependent event to block active object on empty queue */
   QF_OS_EVENT(osEvent__)    
   QEvent *frontEvt__; /*pointer to event at the front of the queue*/ 
   QEvent **start__;    /* pointer to the start of the ring buffer */
   QEvent **end__;        /* pointer to the end of the ring buffer */
   QEvent **head__;/* pointer to where next event will be inserted */
   QEvent **tail__;/* pointer to where next event will be extracted*/
   unsigned short nTot__;      /* total # of entries in the buffer */
   unsigned short nUsed__;     /* # of elements used in the buffer */
   unsigned short nMax__;/* maximum # of events ever in the buffer */
   /* friend class QF */
   /* friend class QActive */
METHODS
   QEQueue *QEQueueCtor(QEQueue *me, QEvent *qSto[], unsigned qLen);
   void QEQueueXtor(QEQueue *me);
   QEvent *QEQueueGet(QEQueue *me);
   int QEQueuePutFIFO(QEQueue *me, QEvent *e);
   int QEQueuePutLIFO(QEQueue *me, QEvent *e);
END_CLASS   

#endif                                                /* qequeue_h */

