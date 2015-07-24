/////////////////////////////////////////////////////////////////////
// Quantum Finite State Machine declarations (C++ version)
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#ifndef qfsm_h
#define qfsm_h

#ifndef qevent_h
   #include "qevent.h"
#endif

class QFsm {                       // Finite State Machine base class
public:
   typedef void (QFsm::*QFsmState)(QEvent const *);
   QFsm(QFsmState initial) { myState = initial; }             // Ctor
   void init() { (this->*myState)(0); }
   void dispatch(QEvent const *e) { (this->*myState)(e); }
   QFsmState getState() const { return myState; }
   static char const *getVersion();
protected:
   void tran(QFsmState target) { myState = target; }
   #define QFSM_TRAN(target_) tran((QFsmState)target_)
private:
   QFsmState myState;                             // the active state
}; 

#endif                                                      // qfsm_h
