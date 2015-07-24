/******************************************************************** 
 * Quantum Dining Philosophers Win32 version (C version)
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA.
 * All Rights Reserved.
 *******************************************************************/
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include "qassert.h"
#include "port.h"

DEFINE_THIS_FILE;

static Table aTable;
static Philosopher aPhil[N];
static QEvent *tableQueueSto[N];
static QEvent *philQueueSto[N][N];
static TableEvt regPoolSto[N*N];
static QSubscrList subscrSto[MAX_SIG];

/*.................................................................*/
void onAssert__(char const *file, unsigned line) {
   fprintf(stderr, "Assertion failed in %s, line %d", file, line);
   exit(-1); 
}
/*.................................................................*/
int main() {
   unsigned n;
   printf("Quantum DPP, version 1.00, libraries: %s\n", 
           QFgetVersion());
   QFinit(subscrSto, MAX_SIG);
   QFpoolInit((QEvent *)regPoolSto, 
              DIM(regPoolSto), sizeof(TableEvt));
   for (n = 0; n < N; ++n) {
      PhilosopherCtor(&aPhil[n], n);
      QActiveStart((QActive *)&aPhil[n], n + 1, 
                   philQueueSto[n], DIM(philQueueSto[n]), 
                   0, 1024);
   }
   TableCtor(&aTable);
   QActiveStart((QActive *)&aTable, N + 1, 
                tableQueueSto, DIM(tableQueueSto), 
                0, 1024); 
   SetThreadPriority(GetCurrentThread(),
                     THREAD_PRIORITY_TIME_CRITICAL);
   for (;;) {
      Sleep(10);
      QFtick();
      if (_kbhit()) {
         break;
      }
   }
   QFcleanup();
   return 0;
}
