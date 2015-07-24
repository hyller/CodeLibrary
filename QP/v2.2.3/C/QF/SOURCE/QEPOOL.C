/******************************************************************** 
 * Quantum Event Pool class implementation (C version)
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA.
 * All Rights Reserved.
 *******************************************************************/
#include "qassert.h"
#include "port.h"

DEFINE_THIS_FILE;

/*.................................................................*/
QEPool *QEPoolCtor(QEPool *me, QEvent *poolSto, 
                   unsigned nEvts, unsigned evtSize)
{
   register char *block;
   REQUIRE(nEvts > 0 && evtSize >= sizeof(QEvent));
   me->free__ =  poolSto;/* set head of linked-list of free events */
   me->evtSize__ = evtSize;    /* store maximum size of each event */
   me->nTot__ = nEvts;             /* store total number of events */
   me->nFree__ = nEvts;             /* store number of free events */
   me->nMin__ = nEvts;        /* the minimum number of free events */
   block = (char *)poolSto;
   while (--nEvts) {       /* chain all blocks in the free-list... */
      *(void **)block = (void *)(block + evtSize); /* set the link */
      block += evtSize;                   /* advance to next block */
   }
   *(void **)block = 0;                   /* last link points to 0 */
   return me;
}
/*.................................................................*/
QEvent *QEPoolGet(QEPool *me) {
   register QEvent *e;
   QF_PROTECT();
   if (me->nFree__ > 0) {                 /* free block available? */
      e = (QEvent *)me->free__;                  /* get free block */
      me->free__ = *(void **)e;     /* adjust ptr to new free list */
      if (--me->nFree__ < me->nMin__) {          /* one less event */
          me->nMin__ = me->nFree__; /* remember the minimum so far */
      }
   }
   else {
      e = 0;
   }
   QF_UNPROTECT();
   return e;         /* return event or NULL pointer to the caller */
}
/*.................................................................*/
void QEPoolPut(QEPool *me, QEvent *e) {
   QF_PROTECT();
   REQUIRE(me->nFree__ <= me->nTot__);/*#of free blks must be<total*/
   *(void **)e = me->free__; /* insert released blk into free list */
   me->free__ = e;             /* set as new head of the free list */
   ++me->nFree__;                   /* one more block in this pool */
   QF_UNPROTECT();
}
