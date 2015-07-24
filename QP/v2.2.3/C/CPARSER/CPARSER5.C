/********************************************************************
 * QP C-comment parser example
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
 * All Rights Reserved.
 *******************************************************************/
#include "cparser5.h"
#include "qassert.h"

DEFINE_THIS_FILE;

CParser5 *CParser5Ctor(CParser5 *me) {
   QFsmCtor_(&me->super_, (QFsmState)CParser5initial);
   return me;
}
void CParser5initial(CParser5 *me, QEvent const *e) {
   me->commentCtr__ = 0;
   QFSM_TRAN(CParser5code);         /* take the default transition */
}
void CParser5code(CParser5 *me, QEvent const *e) {
   switch (e->sig) {
   case SLASH_SIG:
      QFSM_TRAN(CParser5slash);           /* transition to "slash" */
      break;
   }
}
void CParser5slash(CParser5 *me, QEvent const *e) {
   switch (e->sig) {
   case STAR_SIG:
      me->commentCtr__ += 2;        /* SLASH-STAR count as comment */
      QFSM_TRAN(CParser5comment);       /* transition to "comment" */
      break;
   case CHAR_SIG:
      QFSM_TRAN(CParser5code);                /* go back to "code" */
      break;
   }
}

void CParser5comment(CParser5 *me, QEvent const *e) {
   switch (e->sig) {
   case STAR_SIG:
      QFSM_TRAN(CParser5star);             /* transition to "star" */
      break;
   case CHAR_SIG:
   case SLASH_SIG:
      ++me->commentCtr__;           /* count the comment character */
      break; 
   }
}
void CParser5star(CParser5 *me, QEvent const *e) {
   switch (e->sig) {
   case STAR_SIG:
      ++me->commentCtr__;        /* count '*' as comment character */
      break;
   case CHAR_SIG:
      me->commentCtr__ += 2;            /* count STAR-? as comment */
      QFSM_TRAN(CParser5comment);          /* go back to "comment" */
      break;
   case SLASH_SIG:
      me->commentCtr__ += 2;        /* count STAR-SLASH as comment */
      QFSM_TRAN(CParser5code);             /* transition to "code" */
      break;
   }
}
