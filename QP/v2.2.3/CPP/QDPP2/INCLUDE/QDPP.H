/////////////////////////////////////////////////////////////////////
// Quantum DPP package-scope declarations (C++ version)
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#ifndef qdpp_h
#define qdpp_h

enum DPPSignals {
   HUNGRY_SIG = Q_USER_SIG,//sent by philosopher when becoming hungry
   DONE_SIG,                  // sent by philosopher when done eating
   EAT0_SIG,                // sent by Table to let philosopher 0 eat
   EAT1_SIG,                // sent by Table to let philosopher 1 eat
   EAT2_SIG,                // sent by Table to let philosopher 2 eat
   EAT3_SIG,                // sent by Table to let philosopher 3 eat
   EAT4_SIG,                // sent by Table to let philosopher 4 eat
   TIMEOUT_SIG, // timeout philosophers use to end thinking or eating
   MAX_SIG
};

struct TableEvt : public QEvent {
   int philNum;                                 // philosopher number
};

class Philosopher : public QActive {
public:
   Philosopher(int n) : QActive((QPseudoState)initial), myNum(n) {}
protected:
   void initial(QEvent const *e);              // initial pseudostate
   QSTATE thinking(QEvent const *e);  
   QSTATE hungry(QEvent const *e);  
   QSTATE eating(QEvent const *e);
private:  
   int myNum;                           // number of this philosopher
   QTimer myTimer;                    // to timeout thining or eating
};

enum { N = 5 };  // NOTE: this is now coupled with the # EAT? signals

class Table : public QActive {
public:
   Table() : QActive((QPseudoState)initial) {}
private:
   void initial(QEvent const *e);              // initial pseudostate
   QSTATE serving(QEvent const *e);  
private:
   int myFork[N];
   int isHungry[N];
};

#endif                                                      // qdpp_h
