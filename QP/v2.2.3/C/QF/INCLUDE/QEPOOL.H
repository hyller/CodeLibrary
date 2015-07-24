/******************************************************************** 
 * Quantum Event Pool declaration ("C+" version)
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA.
 * All Rights Reserved.
 *******************************************************************/
#ifndef qepool_h
#define qepool_h

CLASS(QEPool)                       /* Fixed-block-size Event Pool */
   /* friend class QF; */
   void *free__;                     /* linked list of free blocks */
   unsigned short evtSize__;     /*  maximum event size (in bytes) */
   unsigned short nTot__;                /* total number of events */
   unsigned short nFree__;      /* number of free blocks remaining */
   unsigned short nMin__;         /* minimum number of free blocks */
METHODS
   QEPool *QEPoolCtor(QEPool *me, QEvent *poolSto, 
                      unsigned nEvts, unsigned evtSize);
   QEvent *QEPoolGet(QEPool *me);
   void QEPoolPut(QEPool *me, QEvent *e);
END_CLASS

#endif                                                 /* qepool_h */
