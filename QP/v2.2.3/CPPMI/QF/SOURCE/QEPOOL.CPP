/////////////////////////////////////////////////////////////////////
// Quantum Event Pool class implementation (C++ version)
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#include "qassert.h"
#include "port.h"

DEFINE_THIS_FILE;

//...................................................................
void QEPool::init(QEvent *poolSto, unsigned nEvts, unsigned evtSize){
   REQUIRE(nEvts > 0 && evtSize >= sizeof(QEvent));
   myFree =  poolSto;       // set head of linked-list of free events
   myEvtSize = evtSize;           // store maximum size of each event
   myNtot = nEvts;                    // store total number of events
   myNfree = nEvts;                    // store number of free events
   myNmin = nEvts;    // initialize the minimum number of free events
   register char *block = (char *)poolSto;
   while (--nEvts) {          // chain all blocks in the free-list...
      *(void **)block = (void *)(block + evtSize);    // set the link
      block += evtSize;                      // advance to next block
   }
   *(void **)block = 0;                      // last link points to 0
}
//...................................................................
QEvent *QEPool::get() {
   register QEvent *e;
   QF_PROTECT();
   if (myNfree > 0) {                       // free events available?
      e = (QEvent *)myFree;                         // get free event
      myFree = *(void **)e;        // adjust pointer to new free list
      if (--myNfree < myNmin) {        // one less event in this pool
          myNmin = myNfree;            // remember the minimum so far
      }
   }
   else {
      e = 0;
   }
   QF_UNPROTECT();
   return e;            // return event or NULL pointer to the caller
}
//...................................................................
void QEPool::put(QEvent *e) {
   QF_PROTECT();
   REQUIRE(myNfree < myNtot);     // # of free events must be < total
   *(void **)e = myFree;      // insert released event into free list
   myFree = e;                    // set as new head of the free list
   ++myNfree;                          // one more event in this pool
   QF_UNPROTECT();
}
