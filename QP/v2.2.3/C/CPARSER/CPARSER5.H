/********************************************************************
 * QP C-comment parser example
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
 * All Rights Reserved.
 *******************************************************************/
#ifndef cparser5_h
#define cparser5_h

#include "qfsm.h"

enum Event {                     /* enumeration for CParser events */
   CHAR_SIG = Q_USER_SIG, STAR_SIG, SLASH_SIG
};

SUBCLASS(CParser5, QFsm)
   long commentCtr__;                 /* comment character counter */
METHODS
   CParser5 *CParser5Ctor(CParser5 *me);                   /* Ctor */
   void CParser5initial(CParser5 *me, QEvent const *e);
   void CParser5code(CParser5 *me, QEvent const *e);
   void CParser5slash(CParser5 *me, QEvent const *e);
   void CParser5comment(CParser5 *me, QEvent const *e);
   void CParser5star(CParser5 *me, QEvent const *e);
   #define CParser5GetCommentCtr(me_) ((me_)->commentCtr__)
END_CLASS

#endif                                               /* cparser5_h */