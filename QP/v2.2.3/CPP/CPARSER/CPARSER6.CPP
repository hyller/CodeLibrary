/////////////////////////////////////////////////////////////////////
// QP C-comment parser example
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#include "cparser6.h"
#include "qassert.h"

DEFINE_THIS_FILE;

void CParser6::initial(QEvent const *) {       // initial pseudostate
   myCommentCtr = 0;
   myCommBlkCtr = 0;
   Q_INIT(&CParser6::code);            // take the default transition
}
QSTATE CParser6::code(QEvent const *e) {
   switch (e->sig) {
   case SLASH_SIG:
      Q_TRAN(&CParser6::slash);              // transition to "slash"
      return 0;
   }
   return (QSTATE)&CParser6::top;
}
QSTATE CParser6::slash(QEvent const *e) {
   switch (e->sig) {
   case STAR_SIG:
      myCommentCtr += 2;    // SLASH-STAR characters count as comment
      Q_TRAN(&CParser6::comment);          // transition to "comment"
      return 0;
   case CHAR_SIG:
      Q_TRAN(&CParser6::code);                   // go back to "code"
      return 0;
   }
   return (QSTATE)&CParser6::code;
}
QSTATE CParser6::comment(QEvent const *e) {
   switch (e->sig) {
   case Q_ENTRY_SIG:
      ++myCommBlkCtr;                      // count number of entries
      return 0;
   case STAR_SIG:
      Q_TRAN(&CParser6::star);                // transition to "star"
      return 0;
   case CHAR_SIG:
   case SLASH_SIG:
      ++myCommentCtr;                  // count the comment character
      return 0; 
   }
   return (QSTATE)&CParser6::top;
}
QSTATE CParser6::star(QEvent const *e) {
   switch (e->sig) {
   case STAR_SIG:
      ++myCommentCtr;               // count '*' as comment character
      return 0;
   case CHAR_SIG:
      myCommentCtr += 2;                   // count STAR-? as comment
      Q_TRAN(&CParser6::comment);             // go back to "comment"
      return 0;
   case SLASH_SIG:
      myCommentCtr += 2;               // count STAR-SLASH as comment
      Q_TRAN(&CParser6::code);                // transition to "code"
      return 0;
   }
   return (QSTATE)&CParser6::comment;
}
