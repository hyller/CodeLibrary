/********************************************************************
 * QP C-comment parser example
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
 * All Rights Reserved.
 *******************************************************************/
#ifndef cparser6_h
#define cparser6_h

#include "qhsm.h"

enum Event {                     /* enumeration for CParser events */
   CHAR_SIG = Q_USER_SIG, STAR_SIG, SLASH_SIG
};

SUBCLASS(CParser6, QHsm)
   long commentCtr__;                 /* comment character counter */
   long commBlkCtr__;                     /* comment block counter */
METHODS
   CParser6 *CParser6Ctor(CParser6 *me);                   /* ctor */
   #define CParser6GetCommentCtr(me_) ((me_)->commentCtr__)
   #define CParser6GetCommBlkCtr(me_) ((me_)->commBlkCtr__)

   void CParser6initial(CParser6 *me, QEvent const *e);
   QSTATE CParser6code(CParser6 *me, QEvent const *e);
      QSTATE CParser6slash(CParser6 *me, QEvent const *e);
   QSTATE CParser6comment(CParser6 *me, QEvent const *e);
      QSTATE CParser6star(CParser6 *me, QEvent const *e);
END_CLASS

#endif                                               /* cparser6_h */
