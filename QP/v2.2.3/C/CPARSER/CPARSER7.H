/********************************************************************
 * QP C-comment parser example
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
 * All Rights Reserved.
 *******************************************************************/
#ifndef cparser7_h
#define cparser7_h

#include "cplus.h"

/* generic "event processor" ... */
struct StateTable;                          /* forward declaration */
typedef void (*Action)(struct StateTable *);

CLASS(StateTable)
   Action const *table__;
   unsigned nSignals__;
   unsigned nStates__;
   unsigned state__;
METHODS
   StateTable *StateTableCtor(StateTable *me, Action const *table, 
                              unsigned nStates, unsigned nSignals);
   void StateTableDispatch(StateTable *me, unsigned const sig);
   void StateTableDoNothing(StateTable *me);
   #define StateTableTran(me_, target_) \
      (((StateTable *)me_)->state__ = (target_))
END_CLASS

/* specific Comment Parser state machine ... */
enum Event {                     /* enumeration for CParser events */
   CHAR_SIG, STAR_SIG, SLASH_SIG, MAX_SIG
};
enum State {                     /* enumeration for CParser states */ 
   CODE, SLASH, COMMENT, STAR, MAX_STATE
};

SUBCLASS(CParser7, StateTable)           /* CParser7 state machine */
   long commentCtr__;                 /* comment character counter */
METHODS
   CParser7 *CParser7Ctor(CParser7 *me);
   void CParser7Init(CParser7 *me);
   #define CParser7GetCommentCtr(me_) ((me_)->commentCtr__)
   /* private action methods hidden inside the implementation file */
END_CLASS

#endif                                               /* cparser7_h */
