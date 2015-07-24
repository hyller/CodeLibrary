/********************************************************************
 * QP C-comment parser example
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
 * All Rights Reserved.
 *******************************************************************/
#ifndef cparser3_h
#define cparser3_h

#include "cplus.h"

struct CParser3;             /* Context class, forward declaration */
SUBCLASS(CParserState, Object)                   /* abstract State */
VTABLE(CParserState, Object)
   void (*onCHAR)(CParserState *me, struct CParser3 *ctxt, char ch);
   void (*onSTAR)(CParserState *me, struct CParser3 *ctxt);
   void (*onSLASH)(CParserState *me, struct CParser3 *ctxt);
METHODS
   CParserState *CParserStateCtor(CParserState *me);
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

CLASS(CParser3)                                   /* Context class */
   CParserState *state_;
   long commentCtr__;
METHODS
   CParser3 *CParser3Ctor(CParser3 *me);
   void CParser3Init(CParser3 *me);
   #define CParser3Tran(me_, target_) \
      ((me_)->state_ = (CParserState *)(target_))
   #define CParser3GetCommentCtr(me_) ((me_)->commentCtr__)
   #define CParser3onCHAR(me_, ch_) \
      (VCALL(CParserState, onCHAR, (me_)->state_), me_, ch_ END_CALL)
   #define CParser3onSTAR(me_) \
      (VCALL(CParserState, onSTAR, (me_)->state_), me_ END_CALL)
   #define CParser3onSLASH(me_) \
      (VCALL(CParserState, onSLASH, (me_)->state_), me_ END_CALL)
END_CLASS

#endif                                               /* cparser3_h */