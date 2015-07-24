/////////////////////////////////////////////////////////////////////
// QP C-comment parser example
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#include "cparser8.h"
#include "qassert.h"

DEFINE_THIS_FILE;

static CodeState    locCodeState;
static SlashState   locSlashState;
static CommentState locCommentState;
static StarState    locStarState;

CParser8 *CParser8Ctor(CParser8 *me) {
   CodeStateCtor(&locCodeState);  
   SlashStateCtor(&locSlashState);  
   CommentStateCtor(&locCommentState);  
   StarStateCtor(&locStarState);
   return me;  
}
void CParser8Init(CParser8 *me) {
   me->commentCtr__ = 0; 
   CParser8Tran(me, &locCodeState); 
}

static void CParserStateDispatch__(CParserState *me, 
                      CParser8 *ctxt, unsigned sig, char ch) {}

static void CodeStateDispatch__(CodeState *me, 
                       CParser8 *ctxt, unsigned sig, char ch) {
   switch (sig) {
   case SLASH_SIG: CParser8Tran(ctxt, &locSlashState); break;
   }
}
static void SlashStateDispatch__(SlashState *me,
                          CParser8 *ctxt, unsigned sig, char ch) {
   switch (sig) {
   case CHAR_SIG: CParser8Tran(ctxt, &locCodeState); break;
   case STAR_SIG: 
      ctxt->commentCtr__ += 2; 
      CParser8Tran(ctxt, &locCommentState);
      break;
   case SLASH_SIG: CParser8Tran(ctxt, &locCodeState); break;
   }
}
static void CommentStateDispatch__(CommentState *me, 
                            CParser8 *ctxt, unsigned sig, char ch)
{
   switch (sig) {
   case CHAR_SIG: ctxt->commentCtr__++; break;
   case STAR_SIG: CParser8Tran(ctxt, &locStarState); break;
   case SLASH_SIG: ctxt->commentCtr__++; break;
   }
}
static void StarStateDispatch__(StarState *me,
                         CParser8 *ctxt, unsigned sig, char ch) {
   switch (sig) {
   case CHAR_SIG:
      ctxt->commentCtr__ += 2;
      CParser8Tran(ctxt, &locCommentState);
      break;
   case STAR_SIG: ctxt->commentCtr__++; break;
   case SLASH_SIG:
      ctxt->commentCtr__ += 2;
      CParser8Tran(ctxt, &locCodeState); 
      break;
   }
}

BEGIN_VTABLE(CParserState, Object)
   VMETHOD(CParserState, dispatch) = CParserStateDispatch__;
END_VTABLE

CParserState *CParserStateCtor(CParserState *me) {
   ObjectCtor_(&me->super_);               /* construct superclass */
   VHOOK(CParserState);          /* hook on the CParserState class */
   return me;
}

BEGIN_VTABLE(CodeState, CParserState)
   VMETHOD(CParserState, dispatch) = 
      (void (*)(CParserState *, CParser8 *, unsigned, char))
         CodeStateDispatch__;
END_VTABLE

CodeState *CodeStateCtor(CodeState *me) {
   CParserStateCtor(&me->super_);          /* construct superclass */
   VHOOK(CodeState);                /* hook on the CodeState class */
   return me;
}

BEGIN_VTABLE(SlashState, CParserState)
   VMETHOD(CParserState, dispatch) = 
      (void (*)(CParserState *, CParser8 *, unsigned, char))
          SlashStateDispatch__;
END_VTABLE

SlashState *SlashStateCtor(SlashState *me) {
   CParserStateCtor(&me->super_);          /* construct superclass */
   VHOOK(SlashState);              /* hook on the SlashState class */
   return me;
}

BEGIN_VTABLE(CommentState, CParserState)
   VMETHOD(CParserState, dispatch) =
      (void (*)(CParserState *, CParser8 *, unsigned, char))
         CommentStateDispatch__;
END_VTABLE

CommentState *CommentStateCtor(CommentState *me) {
   CParserStateCtor(&me->super_);          /* construct superclass */
   VHOOK(CommentState);          /* hook on the CommentState class */
   return me;
}

BEGIN_VTABLE(StarState, CParserState)
   VMETHOD(CParserState, dispatch) =
      (void (*)(CParserState *, CParser8 *, unsigned, char))
         StarStateDispatch__;
END_VTABLE

StarState *StarStateCtor(StarState *me) {
   CParserStateCtor(&me->super_);          /* construct superclass */
   VHOOK(StarState);                /* hook on the StarState class */
   return me;
}
