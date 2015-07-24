/********************************************************************
 * QP C-comment parser example
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
 * All Rights Reserved.
 *******************************************************************/
#include "cparser4.h"
#include "qassert.h"

DEFINE_THIS_FILE;

Fsm *FsmCtor(Fsm *me, State initial) {
   me->state_ = initial;
   return me;
}

CParser4 *CParser4Ctor(CParser4 *me) {
   FsmCtor(&me->super_, (State)CParser4initial);  
   return me;
}
void CParser4initial(CParser4 *me, unsigned const sig) {
   me->commentCtr__ = 0;
   TRAN(CParser4code);              /* take the default transition */
}
void CParser4code(CParser4 *me, unsigned const sig) {
   switch (sig) {
   case SLASH_SIG:
      TRAN(CParser4slash);                /* transition to "slash" */
      break;
   }
}
void CParser4slash(CParser4 *me, unsigned const sig) {
   switch (sig) {
   case STAR_SIG:
      me->commentCtr__ += 2;  /* SLASH-STAR chars count as comment */
      TRAN(CParser4comment);            /* transition to "comment" */
      break;
   case CHAR_SIG:
      TRAN(CParser4code);                     /* go back to "code" */
      break;
   }
}

/* alternative implementation of a state handler; see Exercise 3.8 */
static void CParser4commentOnCHAR(CParser4 *me) {
   ++me->commentCtr__;              /* count the comment character */
}
static void CParser4commentOnSTAR(CParser4 *me) {
   TRAN(CParser4star);                     /* transition to "star" */
}
static void CParser4commentOnSLASH(CParser4 *me) {
   ++me->commentCtr__;              /* count the comment character */
}
void CParser4comment(CParser4 *me, unsigned const sig) {
   static const void (*lookup[])(CParser4 *) = {
      CParser4commentOnCHAR,
      CParser4commentOnSTAR,
      CParser4commentOnSLASH
   };
   REQUIRE(sig <= SLASH_SIG);           /* signal must be in range */
   (*lookup[sig])(me);        /* rapidly dispatch without 'switch' */
}

#if 0
void CParser4comment(CParser4 *me, unsigned const sig) {
   switch (sig) {
   case STAR_SIG:
      TRAN(CParser4star);                  /* transition to "star" */
      break;
   case CHAR_SIG:
   case SLASH_SIG:
      ++me->commentCtr__;           /* count the comment character */
      break; 
   }
}
#endif

void CParser4star(CParser4 *me, unsigned const sig) {
   switch (sig) {
   case STAR_SIG:
      ++me->commentCtr__;        /* count '*' as comment character */
      break;
   case CHAR_SIG:
      me->commentCtr__ += 2;            /* count STAR-? as comment */
      TRAN(CParser4comment);               /* go back to "comment" */
      break;
   case SLASH_SIG:
      me->commentCtr__ += 2;        /* count STAR-SLASH as comment */
      TRAN(CParser4code);                  /* transition to "code" */
      break;
   }
}
