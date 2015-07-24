/////////////////////////////////////////////////////////////////////
// QP C-comment parser example
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#ifndef cparser6_h
#define cparser6_h

#include "qf_win32.h"

enum Event {                        // enumeration for CParser events
   CHAR_SIG = Q_USER_SIG, STAR_SIG, SLASH_SIG
};

class CParser6 : public QHsm {
   long myCommentCtr;                    // comment character counter
   long myCommBlkCtr;                        // comment block counter
   void initial(QEvent const *e);              // initial pseudostate
   QSTATE code(QEvent const *e);                        // code state
      QSTATE slash(QEvent const *e);                   // slash state
   QSTATE comment(QEvent const *e);                  // comment state
      QSTATE star(QEvent const *e);                     // star state
public:
   CParser6() : QHsm((QPseudoState)initial) {}                // ctor
   long getCommentCtr() const { return myCommentCtr; }
   long getCommBlkCtr() const { return myCommBlkCtr; }
};

#endif                                                  // cparser6_h