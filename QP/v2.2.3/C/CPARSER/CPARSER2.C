/********************************************************************
 * QP C-comment parser example
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
 * All Rights Reserved.
 *******************************************************************/
#include "cparser2.h"
#include "qassert.h"

DEFINE_THIS_FILE;

StateTable *StateTableCtor(StateTable *me, Tran const *table, 
                           unsigned nStates, unsigned nSignals)
{
   me->table__ = table;
   me->nStates__ = nStates;
   me->nSignals__ = nSignals;
   return me;   
}
void StateTableDispatch(StateTable *me, unsigned const sig) {
   register Tran const *t = me->table__ + 
                            me->state__*me->nSignals__ + sig; 
   (t->action)(me);
   me->state__ = t->nextState;
}
void StateTableDoNothing(StateTable *me) {}
 
static Tran const locTable[MAX_STATE][MAX_SIG] = {
   {{StateTableDoNothing, CODE },
    {StateTableDoNothing, CODE },
    {StateTableDoNothing, SLASH}},
   {{StateTableDoNothing, CODE },
    {(Action)CParser2A2, COMMENT },
    {StateTableDoNothing, CODE }},
   {{(Action)CParser2A1, COMMENT },
    {StateTableDoNothing,STAR  },
    {(Action)CParser2A1, COMMENT }},
   {{(Action)CParser2A2, COMMENT },
    {(Action)CParser2A1, STAR },
    {(Action)CParser2A2, CODE }}

}; 
CParser2 *CParser2Ctor(CParser2 *me) {
   if (!StateTableCtor(&me->super_, 
                       &locTable[0][0], MAX_STATE, MAX_SIG)) 
   {
      return 0;
   }
   return me; 
}
void CParser2Init(CParser2 *me) {
   me->commentCtr__ = 0; 
   me->super_.state__ = CODE;
}
void CParser2A1(CParser2 *me) { me->commentCtr__ += 1; }
void CParser2A2(CParser2 *me) { me->commentCtr__ += 2; }
