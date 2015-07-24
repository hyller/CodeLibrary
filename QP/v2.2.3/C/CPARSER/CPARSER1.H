/********************************************************************
 * QP C-comment parser example
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
 * All Rights Reserved.
 *******************************************************************/
#ifndef cparser1_h
#define cparser1_h

enum Signal {                   /* enumeration for CParser signals */
   CHAR_SIG, STAR_SIG, SLASH_SIG
};
enum State {                     /* enumeration for CParser states */
   CODE, SLASH, COMMENT, STAR
};
typedef struct CParser1 CParser1;  
struct CParser1 {
   enum State state__;                /* the scalar state-variable */
   long commentCtr__;                 /* comment character counter */
   /* ... */                          /* other CParser1 attributes */
};

#define CParser1Init(me_) \
   ((me_)->commentCtr__ = 0, CParser1Tran(me_, CODE)) 
void CParser1Dispatch(CParser1 *me, unsigned const sig);
#define CParser1Tran(me_, target_) ((me_)->state__ = target_)
#define CParser1GetCommentCtr(me_) ((me_)->commentCtr__)

#endif                                               /* cparser1_h */
