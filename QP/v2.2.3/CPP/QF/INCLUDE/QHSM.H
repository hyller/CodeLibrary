/////////////////////////////////////////////////////////////////////
// Quantum Hierarchical State Machine declaration (C++ version)
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#ifndef qhsm_h
#define qhsm_h

#ifndef qevent_h
   #include "qevent.h"
#endif

class QHsm {                    // Quantum Hierarchical State Machine
public:
   typedef void (QHsm::*QPseudoState)(QEvent const*);  // pseudostate
   typedef QPseudoState (QHsm::*QState)(QEvent const*);      // state

   void init(QEvent const *e = 0);      // execute initial transition
   void dispatch(QEvent const *e);                  // dispatch event
   int isIn(QState state);                     // "is-in-state" query
   static char const *getVersion();

protected:
   struct Tran {                        // protected inner class Tran
      QState myChain[8];
      unsigned short myActions;    // action mask (2-bits for action)
   };
   QHsm(QPseudoState initial);                                // ctor
   virtual ~QHsm();                                   // virtual xtor
   QPseudoState top(QEvent const*) { return 0; }   // the "top" state
   QState getState() const { return myState; }
   void tran(QState target);              // dynamic state transition
   void tranStat(Tran *t, QState target);  // static state transition
   void init_(QState target) { myState = target; }
   #define Q_INIT(target_) init_(Q_STATIC_CAST(QState, target_))
   #define Q_TRAN(target_) if (1) { \
      static Tran t_; \
      tranStat(&t_, Q_STATIC_CAST(QState, target_));\
   } else ((void)0)
   #define Q_TRAN_DYN(target_) tran(Q_STATIC_CAST(QState, target_))

private:
   void tranSetup(Tran *t, QState target);

private:
   QState myState;                                // the active state
   QState mySource;               // source state during a transition
};
typedef QHsm::QPseudoState QSTATE;       // state-handler return type

       // helper macro to calculate static dimension of a 1-dim array
#define DIM(array_) (sizeof(array_)/sizeof(*(array_)))

#endif                                                      // qhsm_h
