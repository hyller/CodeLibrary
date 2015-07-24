/////////////////////////////////////////////////////////////////////
// QP C-comment parser example
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#ifndef cparser1_h
#define cparser1_h

enum Signal {                      // enumeration for CParser signals
   CHAR_SIG, STAR_SIG, SLASH_SIG
};
enum State {                        // enumeration for CParser states 
   CODE, SLASH, COMMENT, STAR
};  
class CParser1 {
private:
   State myState;                        // the scalar state-variable
   long myCommentCtr;                    // comment character counter
   /* ... */                             // other CParser1 attributes
public: 
   void init() { myCommentCtr = 0; tran(CODE); } // default transiton
   void dispatch(unsigned const sig);
   void tran(State target) { myState = target; }
   long getCommentCtr() const { return myCommentCtr; }
};

#endif                                                  // cparser1_h
