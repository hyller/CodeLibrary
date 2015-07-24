/////////////////////////////////////////////////////////////////////
// QP C-comment parser example
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#include "cparser3.h"
#include "qassert.h"

DEFINE_THIS_FILE;

CodeState    CParser3::myCodeState;
SlashState   CParser3::mySlashState;
CommentState CParser3::myCommentState;
StarState    CParser3::myStarState;

void CodeState::onSLASH(CParser3 *context) {
   context->tran(&CParser3::mySlashState);
}
void SlashState::onCHAR(CParser3 *context, char ch) {
   context->tran(&CParser3::myCodeState);
}
void SlashState::onSTAR(CParser3 *context) {
   context->myCommentCtr += 2;
   context->tran(&CParser3::myCommentState);
}
void CommentState::onCHAR(CParser3 *context, char c) {
   context->myCommentCtr++;
}
void CommentState::onSTAR(CParser3 *context) {
   context->tran(&CParser3::myStarState);
}
void CommentState::onSLASH(CParser3 *context) {
   context->myCommentCtr++;
}
void StarState::onCHAR(CParser3 *context, char ch) {
   context->myCommentCtr += 2;
   context->tran(&CParser3::myCommentState);
}
void StarState::onSTAR(CParser3 *context) {
   context->myCommentCtr++;
}
void StarState::onSLASH(CParser3 *context) {
   context->myCommentCtr += 2;
   context->tran(&CParser3::myCodeState);
}
