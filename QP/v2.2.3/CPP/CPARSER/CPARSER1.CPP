/////////////////////////////////////////////////////////////////////
// QP C-comment parser example
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#include "cparser1.h"
#include "qassert.h"

DEFINE_THIS_FILE;

void CParser1::dispatch(unsigned const sig) {
   switch (myState) {
   case CODE:
      switch (sig) {
      case SLASH_SIG:
         tran(SLASH);                          // transition to SLASH
         break;
      }
      break;
   case SLASH:
      switch (sig) {
      case STAR_SIG:
         myCommentCtr += 2;            // SLASH-STAR count as comment
         tran(COMMENT);                      // transition to COMMENT
         break;
      case CHAR_SIG:
      case SLASH_SIG:
         tran(CODE);                               // go back to CODE
         break;
      }
      break;
   case COMMENT:
      switch (sig) {
      case STAR_SIG:
         tran(STAR);                            // transition to STAR
         break;
      case CHAR_SIG:
      case SLASH_SIG:
         ++myCommentCtr;                    // count the comment char
         break; 
      }
      break;
   case STAR:
      switch (sig) {
      case STAR_SIG:
         ++myCommentCtr;                     // count STAR as comment
         break;
      case SLASH_SIG:
         myCommentCtr += 2;            // count STAR-SLASH as comment
         tran(CODE);                            // transition to CODE
         break;
      case CHAR_SIG:
         myCommentCtr += 2;                // count STAR-? as comment
         tran(COMMENT);                         // go back to COMMENT
         break;
      }
      break;
   }
}
