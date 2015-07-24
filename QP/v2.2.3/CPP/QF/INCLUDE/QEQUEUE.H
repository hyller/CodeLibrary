/////////////////////////////////////////////////////////////////////
// Quantum Framework event-queue declaration (C++ version)
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#ifndef qequeue_h
#define qequeue_h

class QEQueue {                           // event queue facility ...
private:   
   int init(QEvent *qSto[], unsigned qLen);
   QEvent *get();
   int putFIFO(QEvent *e);
   int putLIFO(QEvent *e);
   // OS-dependent event object to block active object on empty queue
   QF_OS_EVENT(myOsEvent)    
   QEvent *myFrontEvt;  // pointer to event at the front of the queue
   QEvent **myStart;       // pointer to the start of the ring buffer
   QEvent **myEnd;           // pointer to the end of the ring buffer
   QEvent **myHead;   // pointer to where next event will be inserted
   QEvent **myTail;  // pointer to where next event will be extracted
   unsigned short myNtot;         // total # of entries in the buffer
   unsigned short myNused;       // current # of events in the buffer
   unsigned short myNmax;   // maximum # of events ever in the buffer
   friend class QF;
   friend class QActive;
};

#endif                                                   // qequeue_h

