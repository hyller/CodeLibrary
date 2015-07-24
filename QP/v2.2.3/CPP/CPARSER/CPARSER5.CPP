/////////////////////////////////////////////////////////////////////
// QP C-comment parser example
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#include "cparser5.h"
#include "qassert.h"

DEFINE_THIS_FILE;

void CParser5::initial(QEvent const *) {       // initial pseudostate
   myCommentCtr = 0;
   QFSM_TRAN(&CParser5::code);         // take the default transition
}
void CParser5::code(QEvent const *e) {
   switch (e->sig) {
   case SLASH_SIG:
      QFSM_TRAN(&CParser5::slash);           // transition to "slash"
      break;
   }
}
void CParser5::slash(QEvent const *e) {
   switch (e->sig) {
   case STAR_SIG:
      myCommentCtr += 2;    // SLASH-STAR characters count as comment
      QFSM_TRAN(&CParser5::comment);       // transition to "comment"
      break;
   case CHAR_SIG:
      QFSM_TRAN(&CParser5::code);                // go back to "code"
      break;
   }
}
void CParser5::comment(QEvent const *e) {
   switch (e->sig) {
   case STAR_SIG:
      QFSM_TRAN(&CParser5::star);             // transition to "star"
      break;
   case CHAR_SIG:
   case SLASH_SIG:
      ++myCommentCtr;                  // count the comment character
      break; 
   }
}
void CParser5::star(QEvent const *e) {
   switch (e->sig) {
   case STAR_SIG:
      ++myCommentCtr;               // count '*' as comment character
      break;
   case CHAR_SIG:
      myCommentCtr += 2;                   // count STAR-? as comment
      QFSM_TRAN(&CParser5::comment);          // go back to "comment"
      break;
   case SLASH_SIG:
      myCommentCtr += 2;               // count STAR-SLASH as comment
      QFSM_TRAN(&CParser5::code);             // transition to "code"
      break;
   }
}
