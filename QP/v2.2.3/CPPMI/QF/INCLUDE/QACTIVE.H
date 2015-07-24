/////////////////////////////////////////////////////////////////////
// Quantum Active Object declaration (C++ version)
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#ifndef qactive_h
#define qactive_h

#ifndef qhsm_h
   #include "qhsm.h"
#endif

class QActive : public QHsm {     // Quantum Active Object base class
public:
   int start(unsigned prio, QEvent *qSto[], unsigned qLen,
             int stkSto[], unsigned stkLen);
   void postFIFO(QEvent *e);  // post event directly (FIFO enqueuing)
   void postLIFO(QEvent *e);  // post event directly (LIFO enqueuing)
   void run();   // run() is active throughout lifetime of the object
protected:
   Q_DEFINE_CALL_MEMBER_FN(QActive)          // Define callMemberFn()
   QActive(CQState::QState initial);                // protected ctor
   virtual ~QActive();                                // virtual xtor
   void stop();     // stopps the thread; nothing happens thereafter!
private:
   int enqueue(QEvent *e); // intended to use only by friend class QF
private:                                           // data members...
   QF_EQUEUE(myEqueue)          // OS-dependent event-queue primitive
   QF_THREAD(myThread)               // OS-dependent thread primitive
   unsigned char myPrio;             // priority of the active object
   friend class QF;
};

#endif                                                   // qactive_h
