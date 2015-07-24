/******************************************************************** 
 * Quantum Event-Queue implemenatation (C version)
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA.
 * All Rights Reserved.
 *******************************************************************/
#include "qassert.h"
#include "port.h"

DEFINE_THIS_FILE;

/*.................................................................*/
QEQueue *QEQueueCtor(QEQueue *me, QEvent *qSto[], unsigned qLen) {
   if (!QF_EQUEUE_INIT(me)) {
      return 0;
   }
   me->start__ = &qSto[0];
   me->end__ = &qSto[qLen];    /* qLen is in units sizeof(Event *) */
   me->head__ = &qSto[0];
   me->tail__ = &qSto[0];
   me->nTot__ = qLen;
   me->nUsed__ = 0;
   me->nMax__ = 0;
   me->frontEvt__ = 0;             /* no events in the ring buffer */
   return me;
}
/*.................................................................*/
void QEQueueXtor(QEQueue *me) {
    QF_EQUEUE_CLEANUP(me); 
}
/*.................................................................*/
QEvent *QEQueueGet(QEQueue *me) {
   register QEvent *e;
   QF_PROTECT();
   if (me->frontEvt__ == 0) {               /* is the queue empty? */
      QF_EQUEUE_WAIT(me);     /* wait for event to arrive directly */
   }
   e = me->frontEvt__;
   if (me->nUsed__) {                         /* buffer not empty? */
      --me->nUsed__;          /* one less event in the ring-buffer */
      me->frontEvt__ = *me->tail__;  /* remove event from the tail */
      if (++me->tail__ == me->end__) {
         me->tail__ = me->start__;
      }
   }
   else {
      me->frontEvt__ = 0;                           /* queue empty */
      QF_EQUEUE_ONEMPTY(me);
   }
   QF_UNPROTECT();
   ENSURE(e);
   return e;
}
/*.................................................................*/
int QEQueuePutFIFO(QEQueue *me, QEvent *e) {
   REQUIRE(e);
   QF_PROTECT();
   if (me->frontEvt__ == 0) {               /* is the queue empty? */
      me->frontEvt__ = e;                /* deliver event directly */
      QF_EQUEUE_SIGNAL(me);/* unblock thread waiting on this queue */
   }
   else {    /* queue is not empty, leave event in the ring-buffer */
      if (me->nUsed__ < me->nTot__) {  /* can we accept the event? */
         if (++me->nUsed__ > me->nMax__) {   /* update # of events */
            me->nMax__ = me->nUsed__; /* store maximum used so far */
         }
         *me->head__ = e;   /* insert event into the buffer (FIFO) */
         if (++me->head__ == me->end__) {              
            me->head__ = me->start__;             /* wrap the head */
         }
         QF_UNPROTECT();
      }
      else {                               /* ring-buffer overflow */
         QF_UNPROTECT();
         return 0;                               /* return failure */
      }        
   }
   return !0;                                    /* retrun success */
}
/*.................................................................*/
int QEQueuePutLIFO(QEQueue *me, QEvent *e) {
   REQUIRE(e);
   QF_PROTECT();
   if (me->frontEvt__ == 0) {               /* is the queue empty? */
      me->frontEvt__ = e;                /* deliver event directly */
      QF_EQUEUE_SIGNAL(me);/* unblock thread waiting on this queue */
   }
   else {    /* queue is not empty, leave event in the ring-buffer */
      if (me->nUsed__ < me->nTot__) {  /* can we accept the event? */
         if (++me->nUsed__ > me->nMax__) {   /* update # of events */
            me->nMax__ = me->nUsed__; /* store maximum used so far */
         }
         if (--me->tail__ < me->start__) {
            me->tail__ = me->end__ - 1;           /* wrap the tail */
         }
         *me->tail__ = me->frontEvt__;
         me->frontEvt__ = e;                 /* put event to front */
         QF_UNPROTECT();
      }
      else {                               /* ring-buffer overflow */
         QF_UNPROTECT();
         return 0;                               /* return failure */
      }        
   }
   return !0;                                    /* retrun success */
}
/******************************************************************** 
 * NOTE01:
 * NOTE02:
 */
