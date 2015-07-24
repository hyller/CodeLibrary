/********************************************************************
 * QP C-comment parser example
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
 * All Rights Reserved.
 *******************************************************************/
#ifndef cparser8_h
#define cparser8_h

#include "cplus.h"

struct CParser8;             /* Context class, forward declaration */
SUBCLASS(CParserState, Object)                   /* abstract State */
VTABLE(CParserState, Object)
   void (*dispatch)(CParserState *me, 
                    struct CParser8 *ctxt, unsigned sig, char ch);
METHODS
END_CLASS

SUBCLASS(CodeState, CParserState)         /* concrete State "code" */
VTABLE(CodeState, CParserState)
METHODS
   CodeState *CodeStateCtor(CodeState *me);  
END_CLASS

SUBCLASS(SlashState, CParserState)       /* concrete State "slash" */
VTABLE(SlashState, CParserState)
METHODS
   SlashState *SlashStateCtor(SlashState *me);  
END_CLASS

SUBCLASS(CommentState, CParserState)   /* concrete State "comment" */
VTABLE(CommentState, CParserState)
METHODS
   CommentState *CommentStateCtor(CommentState *me);  
END_CLASS

SUBCLASS(StarState, CParserState)         /* concrete State "star" */
VTABLE(StarState, CParserState)
METHODS
   StarState *StarStateCtor(StarState *me);  
END_CLASS

enum Event {                     /* enumeration for CParser events */
   CHAR_SIG, STAR_SIG, SLASH_SIG, MAX_SIG
};

CLASS(CParser8)                                   /* Context class */
   CParserState *state_;
   long commentCtr__;
METHODS
   CParser8 *CParser8Ctor(CParser8 *me);
   void CParser8Init(CParser8 *me);
   #define CParser8Tran(me_, target_) \
      ((me_)->state_ = (CParserState *)(target_))
   #define CParser8GetCommentCtr(me_) ((me_)->commentCtr__)
   #define CParser8dispatch(me_, sig_, ch_) \
      (VCALL(CParserState, dispatch, (me_)->state_), \
             me_, sig_, ch_ END_CALL)
END_CLASS

#endif                                               /* cparser8_h */