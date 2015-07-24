/********************************************************************
 * QP C-comment parser example
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
 * All Rights Reserved.
 *******************************************************************/
#include "cparser6.h"
#include "qassert.h"

DEFINE_THIS_FILE;

CParser6 *CParser6Ctor(CParser6 *me) {
   QHsmCtor_(&me->super_, (QPseudoState)CParser6initial);
   return me;
}

void CParser6initial(CParser6 *me, QEvent const *e) {
   me->commentCtr__ = 0;
   me->commBlkCtr__ = 0;
   Q_INIT(CParser6code);            /* take the default transition */
}
QSTATE CParser6code(CParser6 *me, QEvent const *e) {
   switch (e->sig) {
   case SLASH_SIG:
      Q_TRAN(CParser6slash);              /* transition to "slash" */
      return 0;
   }
   return (QSTATE)QHsm_top;
}
QSTATE CParser6slash(CParser6 *me, QEvent const *e) {
   switch (e->sig) {
   case STAR_SIG:
      me->commentCtr__ += 2;        /* SLASH-STAR count as comment */
      Q_TRAN(CParser6comment);          /* transition to "comment" */
      return 0;
   case CHAR_SIG:
      Q_TRAN(CParser6code);                   /* go back to "code" */
      return 0;
   }
   return (QSTATE)CParser6code;
}
QSTATE CParser6comment(CParser6 *me, QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      ++me->commBlkCtr__;               /* count number of entries */
      return 0;
   case STAR_SIG:
      Q_TRAN(CParser6star);                /* transition to "star" */
      return 0;
   case CHAR_SIG:
   case SLASH_SIG:
      ++me->commentCtr__;           /* count the comment character */
      return 0; 
   }
   return (QSTATE)QHsm_top;
}
QSTATE CParser6star(CParser6 *me, QEvent const *e) {
   switch (e->sig) {
   case STAR_SIG:
      ++me->commentCtr__;        /* count '*' as comment character */
      return 0;
   case CHAR_SIG:
      me->commentCtr__ += 2;            /* count STAR-? as comment */
      Q_TRAN(CParser6comment);             /* go back to "comment" */
      return 0;
   case SLASH_SIG:
      me->commentCtr__ += 2;        /* count STAR-SLASH as comment */
      Q_TRAN(CParser6code);                /* transition to "code" */
      return 0;
   }
   return (QSTATE)CParser6comment;
}
