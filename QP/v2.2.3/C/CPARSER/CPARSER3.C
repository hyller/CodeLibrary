/********************************************************************
 * QP C-comment parser example
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
 * All Rights Reserved.
 *******************************************************************/
#include "cparser3.h"
#include "qassert.h"

DEFINE_THIS_FILE;

static CodeState    locCodeState;
static SlashState   locSlashState;
static CommentState locCommentState;
static StarState    locStarState;

CParser3 *CParser3Ctor(CParser3 *me) {
   CodeStateCtor(&locCodeState);  
   SlashStateCtor(&locSlashState);  
   CommentStateCtor(&locCommentState);  
   StarStateCtor(&locStarState);
   return me;  
}
void CParser3Init(CParser3 *me) {
   me->commentCtr__ = 0; 
   CParser3Tran(me, &locCodeState); 
}

static void CParserStateOnCHAR__(CParserState *me, 
                                 CParser3 *ctxt, char ch) {}
static void CParserStateOnSTAR__(CParserState *me, CParser3 *ctxt) {}
static void CParserStateOnSLASH__(CParserState *me, CParser3 *ctxt) {}

static void CodeStateOnSLASH__(CodeState *me, CParser3 *ctxt) {
   CParser3Tran(ctxt, &locSlashState);
}
static void SlashStateOnCHAR__(SlashState *me, 
                               CParser3 *ctxt, char ch) {
   CParser3Tran(ctxt, &locCodeState);
}
static void SlashStateOnSTAR__(SlashState *me, CParser3 *ctxt) {
   ctxt->commentCtr__ += 2;
   CParser3Tran(ctxt, &locCommentState);
}
static void CommentStateOnCHAR__(CommentState *me, 
                                 CParser3 *ctxt, char c) {
   ctxt->commentCtr__++;
}
static void CommentStateOnSTAR__(CommentState *me, CParser3 *ctxt) {
   CParser3Tran(ctxt, &locStarState);
}
static void CommentStateOnSLASH__(CParser3 *ctxt) {
   ctxt->commentCtr__++;
}
static void StarStateOnCHAR__(StarState *me, 
                              CParser3 *ctxt, char ch) {
   ctxt->commentCtr__ += 2;
   CParser3Tran(ctxt, &locCommentState);
}
static void StarStateOnSTAR__(StarState *me, CParser3 *ctxt) {
   ctxt->commentCtr__++;
}
static void StarStateOnSLASH__(StarState *me, CParser3 *ctxt) {
   ctxt->commentCtr__ += 2;
   CParser3Tran(ctxt, &locCodeState);
}

BEGIN_VTABLE(CParserState, Object)
   VMETHOD(CParserState, onCHAR) = CParserStateOnCHAR__;
   VMETHOD(CParserState, onSTAR) = CParserStateOnSTAR__;
   VMETHOD(CParserState, onSLASH) = CParserStateOnSLASH__;
END_VTABLE

CParserState *CParserStateCtor(CParserState *me) {
   ObjectCtor_(&me->super_);               /* construct superclass */
   VHOOK(CParserState);          /* hook on the CParserState class */
   return me;
}

BEGIN_VTABLE(CodeState, CParserState)
   VMETHOD(CParserState, onSLASH) = 
      (void (*)(CParserState *, CParser3 *))CodeStateOnSLASH__;
END_VTABLE

CodeState *CodeStateCtor(CodeState *me) {
   CParserStateCtor(&me->super_);          /* construct superclass */
   VHOOK(CodeState);                /* hook on the CodeState class */
   return me;
}

BEGIN_VTABLE(SlashState, CParserState)
   VMETHOD(CParserState, onCHAR) =
      (void (*)(CParserState *, CParser3 *, char))SlashStateOnCHAR__;
   VMETHOD(CParserState, onSTAR) =
      (void (*)(CParserState *, CParser3 *))SlashStateOnSTAR__;
END_VTABLE

SlashState *SlashStateCtor(SlashState *me) {
   CParserStateCtor(&me->super_);          /* construct superclass */
   VHOOK(SlashState);              /* hook on the SlashState class */
   return me;
}

BEGIN_VTABLE(CommentState, CParserState)
   VMETHOD(CParserState, onCHAR) =
    (void (*)(CParserState *, CParser3 *, char))CommentStateOnCHAR__;
   VMETHOD(CParserState, onSTAR) =
      (void (*)(CParserState *, CParser3 *))CommentStateOnSTAR__;
   VMETHOD(CParserState, onSLASH) =
      (void (*)(CParserState *, CParser3 *))CommentStateOnSLASH__;
END_VTABLE

CommentState *CommentStateCtor(CommentState *me) {
   CParserStateCtor(&me->super_);          /* construct superclass */
   VHOOK(CommentState);          /* hook on the CommentState class */
   return me;
}

BEGIN_VTABLE(StarState, CParserState)
   VMETHOD(CParserState, onCHAR) =
      (void (*)(CParserState *, CParser3 *, char))StarStateOnCHAR__;
   VMETHOD(CParserState, onSTAR) =
      (void (*)(CParserState *, CParser3 *))StarStateOnSTAR__;
   VMETHOD(CParserState, onSLASH) =
      (void (*)(CParserState *, CParser3 *))StarStateOnSLASH__;
END_VTABLE

StarState *StarStateCtor(StarState *me) {
   CParserStateCtor(&me->super_);          /* construct superclass */
   VHOOK(StarState);                /* hook on the StarState class */
   return me;
}
