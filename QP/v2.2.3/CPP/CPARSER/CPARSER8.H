/////////////////////////////////////////////////////////////////////
// QP C-comment parser example
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#ifndef cparser8_h
#define cparser8_h

class CParser8;                 // Context class, forward declaration
class CParserState {                                // abstract State
public:
   virtual void dispatch(CParser8 *context, unsigned sig, char ch) {}
};

class CodeState : public CParserState {      // concrete State "code"
public:
   virtual void dispatch(CParser8 *context, unsigned sig, char ch);
};

class SlashState : public CParserState {    // concrete State "slash"
public:
   virtual void dispatch(CParser8 *context, unsigned sig, char ch);
};

class CommentState : public CParserState { //concrete State "comment"
public:
   virtual void dispatch(CParser8 *context, unsigned sig, char ch);
};

class StarState : public CParserState {      // concrete State "star"
public:
   virtual void dispatch(CParser8 *context, unsigned sig, char ch);
};

enum Event {                        // enumeration for CParser events
   CHAR_SIG, STAR_SIG, SLASH_SIG, MAX_SIG
};
class CParser8 {                                     // Context class
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
   void dispatch(unsigned sig, char ch) {
      myState->dispatch(this, sig, ch);
   }
   void tran(CParserState *target) { myState = target; }
   long getCommentCtr() const { return myCommentCtr; }
};

#endif                                                  // cparser8_h