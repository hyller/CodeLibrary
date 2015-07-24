/////////////////////////////////////////////////////////////////////
// QP C-comment parser example
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#ifndef cparser3_h
#define cparser3_h

class CParser3;                 // Context class, forward declaration
class CParserState {                                // abstract State
public:
    virtual void onCHAR(CParser3 *context, char ch)  {}
    virtual void onSTAR(CParser3 *context) {}
    virtual void onSLASH(CParser3 *context) {}
};

class CodeState : public CParserState {      // concrete State "Code"
public:
    virtual void onSLASH(CParser3 *context);
};

class SlashState : public CParserState {    // concrete State "Slash"
public:
    virtual void onCHAR(CParser3 *context, char ch);
    virtual void onSTAR(CParser3 *context);
};

class CommentState : public CParserState { //concrete State "Comment"
public:
    virtual void onCHAR(CParser3 *context, char ch);
    virtual void onSTAR(CParser3 *context);
    virtual void onSLASH(CParser3 *context);
};

class StarState : public CParserState {      // concrete State "Star"
public:
    virtual void onCHAR(CParser3 *context, char ch);
    virtual void onSTAR(CParser3 *context);
    virtual void onSLASH(CParser3 *context);
};

class CParser3 {                                     // Context class
   friend class CodeState;
   friend class SlashState;
   friend class CommentState;
   friend class StarState;
   static CodeState    myCodeState;
   static SlashState   mySlashState;
   static CommentState myCommentState;
   static StarState    myStarState;

   CParserState *myState;
   long myCommentCtr;
public:
   void init() { myCommentCtr = 0; tran(&myCodeState); }
   void tran(CParserState *target) { myState = target; }
   long getCommentCtr() const { return myCommentCtr; }
   void onCHAR(char ch) { myState->onCHAR(this, ch); }
   void onSTAR() { myState->onSTAR(this);  }
   void onSLASH() { myState->onSLASH(this); }
};

#endif                                                  // cparser3_h