/********************************************************************
 * QP C-comment parser example
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
 * All Rights Reserved.
 *******************************************************************/
#include "cparser7.h"
#include "qassert.h"

DEFINE_THIS_FILE;

StateTable *StateTableCtor(StateTable *me, Action const *table, 
                           unsigned nStates, unsigned nSignals)
{
   me->table__ = table;
   me->nStates__ = nStates;
   me->nSignals__ = nSignals;
   return me;   
}
void StateTableDispatch(StateTable *me, unsigned const sig) {
   register Action const a = *(me->table__ + 
                             me->state__*me->nSignals__ + sig); 
   (*a)(me);   
}
void StateTableDoNothing(StateTable *me) {}

void CParser7Init(CParser7 *me) {
   me->commentCtr__ = 0; 
   StateTableTran(me, CODE);
}
static void CParser7codeOnSLASH(CParser7 *me) { 
   StateTableTran(me, SLASH);
}
static void CParser7slashOnCHAR(CParser7 *me) { 
   StateTableTran(me, CODE);
}   
static void CParser7slashOnSTAR(CParser7 *me) {   
   me->commentCtr__ += 2; 
   StateTableTran(me, COMMENT);
}  
static void CParser7slashOnSLASH(CParser7 *me) {  
   StateTableTran(me, CODE);
}  
static void CParser7commentOnCHAR(CParser7 *me) { 
   me->commentCtr__ += 1;
}  
static void CParser7commentOnSTAR(CParser7 *me) { 
   StateTableTran(me, STAR);
}  
static void CParser7commentOnSLASH(CParser7 *me) {
   me->commentCtr__ += 1;
}  
static void CParser7starOnCHAR(CParser7 *me) {    
   me->commentCtr__ += 2; 
   StateTableTran(me, COMMENT);
}  
static void CParser7starOnSTAR(CParser7 *me) {    
   me->commentCtr__ += 1;
}  
static void CParser7starOnSLASH(CParser7 *me) {   
   me->commentCtr__ += 2; 
   StateTableTran(me, CODE);
}  

static Action const locTable[MAX_STATE][MAX_SIG] = {
   {StateTableDoNothing, 
    StateTableDoNothing, 
    (Action)CParser7codeOnSLASH},
   {(Action)CParser7slashOnCHAR, 
    (Action)CParser7slashOnSTAR, 
    (Action)CParser7slashOnSLASH},
   {(Action)CParser7commentOnCHAR,
    (Action)CParser7commentOnSTAR, 
    (Action)CParser7commentOnSLASH},
   {(Action)CParser7starOnCHAR, 
    (Action)CParser7starOnSTAR,
    (Action)CParser7starOnSLASH}
}; 

CParser7 *CParser7Ctor(CParser7 *me) {
   if (!StateTableCtor(&me->super_, 
                       &locTable[0][0], MAX_STATE, MAX_SIG)) 
   {
      return 0;
   }
   return me; 
}
