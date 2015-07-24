/********************************************************************
 * QP C-comment parser example
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
 * All Rights Reserved.
 *******************************************************************/
#include "cparser1.h"
#include "qassert.h"

DEFINE_THIS_FILE;

void CParser1Dispatch(CParser1 *me, unsigned const sig) {
   switch (me->state__) {
   case CODE:
      switch (sig) {
      case SLASH_SIG:
         CParser1Tran(me, SLASH);         /* transition to "slash" */
         break;
      }
      break;
   case SLASH:
      switch (sig) {
      case STAR_SIG:
         me->commentCtr__ += 2;     /* SLASH-STAR count as comment */
         CParser1Tran(me, COMMENT);     /* transition to "comment" */
         break;
      case CHAR_SIG:
      case SLASH_SIG:
         CParser1Tran(me, CODE);              /* go back to "code" */
         break;
      }
      break;
   case COMMENT:
      switch (sig) {
      case STAR_SIG:
         CParser1Tran(me, STAR);           /* transition to "star" */
         break;
      case CHAR_SIG:
      case SLASH_SIG:
         ++me->commentCtr__;             /* count the comment char */
         break; 
      }
      break;
   case STAR:
      switch (sig) {
      case STAR_SIG:
         ++me->commentCtr__;              /* count STAR as comment */
         break;
      case SLASH_SIG:
         me->commentCtr__ += 2;     /* count STAR-SLASH as comment */
         CParser1Tran(me, CODE);           /* transition to "code" */
         break;
      case CHAR_SIG:
         me->commentCtr__ += 2;         /* count STAR-? as comment */
         CParser1Tran(me, COMMENT);        /* go back to "comment" */
         break;
      }
      break;
   }
}
