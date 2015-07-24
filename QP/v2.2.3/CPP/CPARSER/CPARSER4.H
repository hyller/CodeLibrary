/////////////////////////////////////////////////////////////////////
// QP C-comment parser example
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#ifndef cparser4_h
#define cparser4_h

class Fsm {
public:
   typedef void                                       // return value
           (Fsm::*       // class the function pointer is a member of
               State)                       // pointer-to-member name
           (unsigned const sig);                     // argument list
   Fsm(State initial) : myState(initial) {}                   // ctor
   virtual ~Fsm() {}                                  // virtual xtor
   void init() { (this->*myState)(0); }         // initial transition
   void dispatch(unsigned const sig) { (this->*myState)(sig); }
protected:
   void tran(State target) { myState = target; }
   #define TRAN(target_) tran(static_cast<State>(target_))
protected:   
   State myState;
};

enum Event {                        // enumeration for CParser events
   CHAR_SIG, STAR_SIG, SLASH_SIG
};

class CParser4 : public Fsm {
public:
   CParser4() : Fsm((State)initial) {}                        // ctor
   long getCommentCtr() const { return myCommentCtr; }
private:
   long myCommentCtr;                    // comment character counter
   void initial(unsigned const);                     // state-handler
   void code(unsigned const sig);                    // state-handler
   void slash(unsigned const sig);                   // state-handler
   virtual void comment(unsigned const sig);                 // state-handler
   void star(unsigned const sig);                    // state-handler
};

#endif                                                  // cparser4_h