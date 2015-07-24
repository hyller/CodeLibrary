/////////////////////////////////////////////////////////////////////
// QP C-comment parser example
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#include "cparser4.h"
#include "qassert.h"

DEFINE_THIS_FILE;

void CParser4::initial(unsigned const) {       // initial pseudostate
   myCommentCtr = 0;
   TRAN(&CParser4::code);              // take the default transition
}
void CParser4::code(unsigned const sig) {
   switch (sig) {
   case SLASH_SIG:
      TRAN(&CParser4::slash);                // transition to "slash"
      break;
   }
}
void CParser4::slash(unsigned const sig) {
   switch (sig) {
   case STAR_SIG:
      myCommentCtr += 2;    // SLASH-STAR characters count as comment
      TRAN(&CParser4::comment);            // transition to "comment"
      break;
   case CHAR_SIG:
      TRAN(&CParser4::code);                     // go back to "code"
      break;
   }
}
void CParser4::comment(unsigned const sig) {
   switch (sig) {
   case STAR_SIG:
      TRAN(&CParser4::star);                  // transition to "star"
      break;
   case CHAR_SIG:
   case SLASH_SIG:
      ++myCommentCtr;                  // count the comment character
      break; 
   }
}
void CParser4::star(unsigned const sig) {
   switch (sig) {
   case STAR_SIG:
      ++myCommentCtr;               // count '*' as comment character
      break;
   case CHAR_SIG:
      myCommentCtr += 2;                   // count STAR-? as comment
      TRAN(&CParser4::comment);               // go back to "comment"
      break;
   case SLASH_SIG:
      myCommentCtr += 2;               // count STAR-SLASH as comment
      TRAN(&CParser4::code);                  // transition to "code"
      break;
   }
}
