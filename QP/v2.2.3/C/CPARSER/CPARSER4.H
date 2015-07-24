/********************************************************************
 * QP C-comment parser example
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
 * All Rights Reserved.
 *******************************************************************/
#ifndef cparser4_h
#define cparser4_h

typedef struct Fsm Fsm;
typedef void                                       /* return value */
        (*State)                         /* pointer-to-member name */
           (Fsm *me,  /* class the function pointer is a member of */
            unsigned const sig);  /* the rest of the argument list */
struct Fsm {
   State state_;                        /* protected current state */
};
Fsm *FsmCtor(Fsm *me, State initial);                      /* ctor */
#define FsmInit(me_) ((*(me_)->state_)((me_), 0)) 
#define FsmDispatch(me_, sig_) ((*(me_)->state_)((me_), sig))
#define TRAN(target_) (((Fsm *)me)->state_ = (State)(target_))

enum Event {                     /* enumeration for CParser events */
   CHAR_SIG, STAR_SIG, SLASH_SIG
};

typedef struct CParser4 CParser4;
struct CParser4 {
   Fsm super_;                           /* inherit from Fsm class */
   long commentCtr__;                 /* comment character counter */
};

CParser4 *CParser4Ctor(CParser4 *me);                      /* ctor */
#define CParser4GetCommentCtr(me_) ((me_)->commentCtr__)
void CParser4initial(CParser4 *me, unsigned const); 
void CParser4code(CParser4 *me, unsigned const sig);
void CParser4slash(CParser4 *me, unsigned const sig);
void CParser4comment(CParser4 *me, unsigned const sig);
void CParser4star(CParser4 *me, unsigned const sig);

#endif                                               /* cparser4_h */