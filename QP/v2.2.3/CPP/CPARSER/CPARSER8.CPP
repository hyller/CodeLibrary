/////////////////////////////////////////////////////////////////////
// QP C-comment parser example
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#include "cparser8.h"
#include "qassert.h"

DEFINE_THIS_FILE;

CodeState    CParser8::myCodeState;
SlashState   CParser8::mySlashState;
CommentState CParser8::myCommentState;
StarState    CParser8::myStarState;

void CodeState::dispatch(CParser8 *context, unsigned sig, char ch) {
   switch (sig) {
   case SLASH_SIG: context->tran(&CParser8::mySlashState); break;
   }
}

void SlashState::dispatch(CParser8 *context, unsigned sig, char ch) {
   switch (sig) {
   case CHAR_SIG: context->tran(&CParser8::myCodeState); break;
   case STAR_SIG: 
      context->myCommentCtr += 2; 
      context->tran(&CParser8::myCommentState);
      break;
   case SLASH_SIG: context->tran(&CParser8::myCodeState); break;
   }
}

void CommentState::dispatch(CParser8 *context, 
                            unsigned sig, char ch)
{
   switch (sig) {
   case CHAR_SIG: context->myCommentCtr++; break;
   case STAR_SIG: context->tran(&CParser8::myStarState); break;
   case SLASH_SIG: context->myCommentCtr++; break;
   }
}

void StarState::dispatch(CParser8 *context, unsigned sig, char ch) {
   switch (sig) {
   case CHAR_SIG:
      context->myCommentCtr += 2;
      context->tran(&CParser8::myCommentState);
      break;
   case STAR_SIG: context->myCommentCtr++; break;
   case SLASH_SIG:
      context->myCommentCtr += 2;
      context->tran(&CParser8::myCodeState); 
      break;
   }
}
