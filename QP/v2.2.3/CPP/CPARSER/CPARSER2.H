/////////////////////////////////////////////////////////////////////
// QP C-comment parser example
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#ifndef cparser2_h
#define cparser2_h

// generic "event processor" ...
class StateTable {
public:
   typedef void (StateTable::*Action)();
   struct Tran {
      Action action;
      unsigned nextState;
   };
   StateTable(Tran const *table, unsigned nStates, unsigned nSignals)
      : myTable(table), myNsignals(nSignals), myNstates(nStates) {}
   virtual ~StateTable() {}                          // virtual xctor
   void dispatch(unsigned const sig) {
      register Tran const *t = myTable + myState*myNsignals + sig; 
      (this->*(t->action))();
      myState = t->nextState;
   }
   void doNothing() {}
protected:
   unsigned myState;
private:
   Tran const *myTable;
   unsigned myNsignals;
   unsigned myNstates;
};

// specific Comment Parser state machine ...
enum Event {                        // enumeration for CParser events
   CHAR_SIG, STAR_SIG, SLASH_SIG, MAX_SIG
};
enum State {                        // enumeration for CParser states 
   CODE, SLASH, COMMENT, STAR, MAX_STATE
};
class CParser2 : public StateTable {        // CParser2 state machine
public:
   CParser2() : StateTable(&myTable[0][0], MAX_STATE, MAX_SIG) {}
   void init() { myCommentCtr = 0; myState = CODE; } // initial tran.
   long getCommentCtr() const { return myCommentCtr; }
private:
   void a1() { myCommentCtr += 1; }                  // action method
   void a2() { myCommentCtr += 2; }                  // action method
private:
   static StateTable::Tran const myTable[MAX_STATE][MAX_SIG];
   long myCommentCtr;                    // comment character counter
};

#endif                                                  // cparser2_h