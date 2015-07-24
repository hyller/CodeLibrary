/////////////////////////////////////////////////////////////////////
// Quantum Hierarchical State Machine declarations (C++ version)
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#ifndef qhsm_h
#define qhsm_h

#ifndef qevent_h
   #include "qevent.h"
#endif

class QHsm {      // MI-compatible Quantum Hierarchical State Machine
public:
   class CQState {
   public:
      typedef CQState (QHsm::*QState)(QEvent const *);
      CQState(QState fn = 0) : myPtMF(fn) {}
      operator bool() const { return myPtMF != 0; }
      bool operator!=(CQState const &s) { return myPtMF != s.myPtMF;}
      bool operator==(CQState const &s) { return myPtMF == s.myPtMF;}
      CQState operator()(QHsm *hsm, QEvent const *e) { 
         return hsm->callMemberFn(myPtMF, e, hsm);
      }
      CQState operator()(QHsm const *hsm, QEvent const *e) const {
         QHsm *hsm_ = const_cast<QHsm*>(hsm);
         return hsm_->callMemberFn(myPtMF, e, hsm_);
      }
   private:
      QState myPtMF;          // pointer-to-member function attribute
   };
   friend class QHsm::CQState;

public:
   typedef QHsm::CQState CQSTATE;
   #define QSTATE_SC(fn) CQState(static_cast<CQState::QState>(fn))

      // the following macro should be placed in *each* derived class
   #define Q_DEFINE_CALL_MEMBER_FN(class_) \
      virtual CQState callMemberFn(CQState::QState fn, \
                                   QEvent const *e, QHsm *hsm)\
      {\
         class_ *c = static_cast<class_*>(hsm); \
         return (c->*fn)(e); \
      }
   void init();                         // execute initial transition
   void dispatch(QEvent const *e);                  // dispatch event
   int isIn(CQState state);              // "is-in-state" query
   static char const *getVersion();

protected:
   QHsm(CQState::QState initial);                             // Ctor
   virtual ~QHsm();                                   // virtual Xtor
   virtual CQState callMemberFn(CQState::QState fn,   // pure virtual
                                QEvent const *e, QHsm *hsm) = 0;
   struct Tran {                        // protected inner class Tran
      CQState myChain[8];
      unsigned short myActions;    // action mask (2-bits for action)
   };
   CQState top(QEvent const*) { return 0; } //the "top" state-handler
   CQState getState() const { return myState; }
   void tran(CQState target);             // dynamic state transition
   void tranStat(Tran *t,CQState target);  // static state transition
   void init_(CQState target) {
       myState = target;
   }
   #define Q_INIT(target_) \
      init_(CQState(static_cast<CQState::QState>(target_)))
   #define Q_TRAN(target_) if (1) { \
      static Tran t_; \
      tranStat(&t_, CQState(static_cast<CQState::QState>(target_)));\
   } else ((void)0)
   #define Q_TRAN_DYN(target_) tran((CQState)(target_))

private:
   void tranSetup(Tran *t, CQState target);

private:
   CQState myState;                               // the active state
   CQState mySource;              // source state during a transition
};

       // helper macro to calculate static dimension of a 1-dim array
#define DIM(array_) (sizeof(array_)/sizeof(*(array_)))

#endif                                                      // qhsm_h
