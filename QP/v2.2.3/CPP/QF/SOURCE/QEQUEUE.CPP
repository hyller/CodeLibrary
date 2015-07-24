/////////////////////////////////////////////////////////////////////
// Quantum Event-Queue implemenatation
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#include "qassert.h"
#include "port.h"

DEFINE_THIS_FILE;

//...................................................................
int QEQueue::init(QEvent *qSto[], unsigned qLen) {
   if (!QF_EQUEUE_INIT(this)) {
      return 0;
   }
   myStart = &qSto[0];
   myEnd = &qSto[qLen];           // qLen is in units sizeof(Event *)
   myHead = &qSto[0];
   myTail = &qSto[0];
   myNtot = qLen;
   myNused = 0;
   myNmax = 0;
   myFrontEvt = 0;                               // clear front event
   return !0;
}
//...................................................................
QEvent *QEQueue::get() {
   register QEvent *e;
   QF_PROTECT();
   if (myFrontEvt == 0) {                      // is the queue empty?
      QF_EQUEUE_WAIT(this);      // wait for event to arrive directly
   }
   e = myFrontEvt;
   if (myNused) {                                // buffer not empty?
      --myNused;                 // one less event in the ring-buffer
      myFrontEvt = *myTail;             // remove event from the tail
      if (++myTail == myEnd) {
         myTail = myStart;
      }
   }
   else {
      myFrontEvt = 0;                                  // queue empty
      QF_EQUEUE_ONEMPTY(this);
   }
   QF_UNPROTECT();
   ENSURE(e);
   return e;
}
//...................................................................
int QEQueue::putFIFO(QEvent *e) {
   REQUIRE(e);
   QF_PROTECT();
   if (myFrontEvt == 0) {                      // is the queue empty?
      myFrontEvt = e;                       // deliver event directly
      QF_EQUEUE_SIGNAL(this); // unblock thread waiting on this queue
   }
   else {       // queue is not empty, leave event in the ring-buffer
      if (myNused < myNtot) {     // can the buffer accept the event?
         if (++myNused > myNmax) {              // update # of events
            myNmax = myNused;            // store maximum used so far
         }
         *myHead = e;          // insert event into the buffer (FIFO)
         if (++myHead == myEnd) {              
            myHead = myStart;                        // wrap the head
         }
         QF_UNPROTECT();
      }
      else {                                  // ring-buffer overflow
         QF_UNPROTECT();
         return 0;                                  // return failure
      }        
   }
   return !0;                                       // retrun success
}
//...................................................................
int QEQueue::putLIFO(QEvent *e) {
   REQUIRE(e);
   QF_PROTECT();
   if (myFrontEvt == 0) {                      // is the queue empty?
      myFrontEvt = e;                          // deliver it directly
      QF_EQUEUE_SIGNAL(this);
   }
   else {       // queue is not empty, leave event in the ring-buffer
      if (myNused < myNtot) {   // can the buffer accept the element?
         if (++myNused > myNmax) {              // update # of events
            myNmax = myNused;            // store maximum used so far
         }
         if (--myTail < myStart) {
            myTail = myEnd - 1;                      // wrap the tail
         }
         *myTail = myFrontEvt;//push front event back into the buffer
         myFrontEvt = e;                        // put event to front
         QF_UNPROTECT();
      }
      else {                                  // ring-buffer overflow
         QF_UNPROTECT();
         return 0;                                  // return failure
      }        
   }
   return !0;                                       // retrun success
}

/////////////////////////////////////////////////////////////////////
// NOTE01:
// NOTE02:
//
