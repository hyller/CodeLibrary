/******************************************************************** 
 * Quantum DPP package-scope declarations (C version)
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA.
 * All Rights Reserved.
 *******************************************************************/
#ifndef qdpp_h
#define qdpp_h

enum DPPSignals {
   HUNGRY_SIG = Q_USER_SIG, /* sent when philosopher becomes hungry */
   DONE_SIG,                /* sent by philosopher when done eating */
   EAT_SIG,               /* sent by Table to let a philosopher eat */
   TIMEOUT_SIG, /*timeout philosophers use to end thinking or eating*/
   MAX_SIG
};

SUBCLASS(TableEvt, QEvent)
   int philNum;                               /* philosopher number */
METHODS
END_CLASS

SUBCLASS(Philosopher, QActive)
   int num__;                         /* number of this philosopher */
   QTimer timer__;                  /* to timeout thining or eating */
METHODS
   Philosopher *PhilosopherCtor(Philosopher *me, int n);
   void Philosopher_initial(Philosopher *me, QEvent const *e);
   QSTATE Philosopher_thinking(Philosopher *me, QEvent const *e);  
   QSTATE Philosopher_hungry(Philosopher *me, QEvent const *e);  
   QSTATE Philosopher_eating(Philosopher *me, QEvent const *e);  
END_CLASS

enum { N = 5 };

SUBCLASS(Table, QActive)
   int fork__[N];
   int isHungry__[N];
METHODS
   Table *TableCtor(Table *me);
   void Table_initial(Table *me, QEvent const *e);
   QSTATE Table_serving(Table *me, QEvent const *e);  
END_CLASS

#endif                                                    /* qdpp_h */
