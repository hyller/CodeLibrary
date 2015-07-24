/////////////////////////////////////////////////////////////////////
// Quantum Dining Philosophers Win32 version
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include "qassert.h"
#include "port.h"

DEFINE_THIS_FILE;

static Table aTable;
static Philosopher aPhil[N] = { 0, 1, 2, 3, 4 };
static QEvent *tableQueueSto[N];
static QEvent *philQueueSto[N][N];
static TableEvt regPoolSto[N*N];
static QSubscrList subscrSto[MAX_SIG];

extern "C" void onAssert__(char const *file, unsigned line) {
   fprintf(stderr, "Assertion failed in %s, line %d", file, line);
   exit(-1); 
}

int main() {
   printf("Quantum DPP, built on %s at %s, libraries: %s\n", 
           __DATE__, __TIME__, QF::getVersion());
   QF::init(subscrSto, MAX_SIG);
   QF::poolInit(regPoolSto, DIM(regPoolSto), sizeof(TableEvt));
   for (unsigned n = 0; n < N; ++n) {
      aPhil[n].start(n + 1, philQueueSto[n], DIM(philQueueSto[n]), 
                     0, 1024);
   }
   aTable.start(N + 1, tableQueueSto, DIM(tableQueueSto), 0, 1024);

   SetThreadPriority(GetCurrentThread(),
                     THREAD_PRIORITY_TIME_CRITICAL);
   for (;;) {
      Sleep(10);
      QF::tick();
      if (_kbhit()) {
         break;
      }
   }
   QF::cleanup();
   return 0;
}
