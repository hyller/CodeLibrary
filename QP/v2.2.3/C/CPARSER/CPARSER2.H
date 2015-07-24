/********************************************************************
 * QP C-comment parser example
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
 * All Rights Reserved.
 *******************************************************************/
#ifndef cparser2_h
#define cparser2_h

#include "cplus.h"

/* generic "event processor" ... */
struct StateTable;                          /* forward declaration */
typedef void (*Action)(struct StateTable *);
CLASS(Tran)
   Action action;
   unsigned nextState;
METHODS
END_CLASS

CLASS(StateTable)
   Tran const *table__;
   unsigned nSignals__;
   unsigned nStates__;
   unsigned state__;
METHODS
   StateTable *StateTableCtor(StateTable *me, Tran const *table, 
                              unsigned nStates, unsigned nSignals);
   void StateTableDispatch(StateTable *me, unsigned const sig);
   void StateTableDoNothing(StateTable *me);
END_CLASS

/* specific Comment Parser state machine ... */
enum Event {                     /* enumeration for CParser events */
   CHAR_SIG, STAR_SIG, SLASH_SIG, MAX_SIG
};
enum State {                     /* enumeration for CParser states */ 
   CODE, SLASH, COMMENT, STAR, MAX_STATE
};

SUBCLASS(CParser2, StateTable)           /* CParser2 state machine */
   long commentCtr__;                 /* comment character counter */
METHODS
   CParser2 *CParser2Ctor(CParser2 *me);
   void CParser2Init(CParser2 *me);               /* initial tran. */
   #define CParser2GetCommentCtr(me_) ((me_)->commentCtr__)
   void CParser2A1(CParser2 *me);                 /* action method */
   void CParser2A2(CParser2 *me);                 /* action method */
END_CLASS

#endif                                               /* cparser2_h */