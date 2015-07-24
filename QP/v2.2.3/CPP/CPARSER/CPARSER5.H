/////////////////////////////////////////////////////////////////////
// QP C-comment parser example
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#ifndef cparser5_h
#define cparser5_h

#include "qf_win32.h"

enum Event {                        // enumeration for CParser events
   CHAR_SIG = Q_USER_SIG, STAR_SIG, SLASH_SIG
};

class CParser5 : public QFsm {
   long myCommentCtr;                    // comment character counter
   void initial(QEvent const *e);              // initial pseudostate
   void code(QEvent const *e);                          // code state
   void slash(QEvent const *e);                        // slash state
   void comment(QEvent const *e);                    // comment state
   void star(QEvent const *e);                          // star state
public:
   CParser5() : QFsm((QFsmState)initial) {}                   // ctor
   long getCommentCtr() const { return myCommentCtr; }
};

#endif                                                  // cparser5_h