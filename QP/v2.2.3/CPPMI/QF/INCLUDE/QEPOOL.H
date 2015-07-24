/////////////////////////////////////////////////////////////////////
// Quantum Event Pool declarations (C++ version)
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#ifndef qepool_h
#define qepool_h

class QEPool {                                // "Quantum" event-pool
private:
   void init(QEvent *poolSto, unsigned nEvts, unsigned evtSize);
   QEvent *get();
   void put(QEvent *e);
   void *myFree;                // head of linked-list of free blocks
   unsigned short myEvtSize;         // maximum event size (in bytes)
   unsigned short myNtot;                   // total number of events
   unsigned short myNfree;         // number of free blocks remaining
   unsigned short myNmin;            // minimum number of free blocks
   friend class QF;
};

#endif                                                    // qepool_h
