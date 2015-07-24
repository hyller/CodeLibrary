/////////////////////////////////////////////////////////////////////
// QP C-comment parser example
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#ifndef cparser7_h
#define cparser7_h

// generic "event processor" ...
class StateTable {
public:
   typedef void (StateTable::*Action)();
   StateTable(Action const *table, unsigned nStates, unsigned nSignals)
      : myTable(table), myNsignals(nSignals), myNstates(nStates) {}
   void dispatch(unsigned const sig) {
      register Action const a = *(myTable + myState*myNsignals + sig); 
      (this->*(a))();
   }
   void doNothing() {}
protected:
   void tran(unsigned target) { myState = target; }
protected:
   unsigned myState;
private:
   Action const *myTable;
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
class CParser7 : public StateTable {        // CParser2 state machine
public:
   CParser7() : StateTable(&myTable[0][0], MAX_STATE, MAX_SIG) {}
   void init() { myCommentCtr = 0; myState = CODE; } // initial tran.
   long getCommentCtr() const { return myCommentCtr; }
private:                                         // action methods...
   void codeOnSLASH()    { tran(SLASH); } 
   void slashOnCHAR()    { tran(CODE);  }
   void slashOnSTAR()    { myCommentCtr += 2; tran(COMMENT); }
   void slashOnSLASH()   { tran(CODE);  }
   void commentOnCHAR()  { myCommentCtr += 1; }
   void commentOnSTAR()  { tran(STAR); }
   void commentOnSLASH() { myCommentCtr += 1; }
   void starOnCHAR()     { myCommentCtr += 2; tran(COMMENT); }
   void starOnSTAR()     { myCommentCtr += 1; }
   void starOnSLASH()    { myCommentCtr += 2; tran(CODE); }
private:
   static Action const myTable[MAX_STATE][MAX_SIG];
   long myCommentCtr;                    // comment character counter
};

#endif                                                  // cparser7_h