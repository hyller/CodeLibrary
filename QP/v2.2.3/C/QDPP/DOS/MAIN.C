/******************************************************************** 
 * Quantum Dining Philosophers DOS port (C version)
 * (c) Copyright 2001, Miro Samek, Palo Alto, CA
 * All Rights Reserved
 *******************************************************************/
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include "qassert.h"
#include "port.h"

DEFINE_THIS_FILE;

/*.................................................................*/
enum { TICK_VECTOR = 0x08 };

static void (__cdecl __interrupt __far *dosISR)();
static QSubscrList subscrSto[MAX_SIG];
static TableEvt regPoolSto[20];
static Table aTable;
static Philosopher aPhil[N];
static QEvent *tableQueueSto[10];
static QEvent *philQueueSto[N][10];

/*.................................................................*/
void onAssert__(char const *file, unsigned line) {
   fprintf(stderr, "Assertion failed in %s, line %d", file, line);
   exit(-1); 
}
/*.................................................................*/
void __cdecl __interrupt __far ISR(void) {
   QFtick();
   _chain_intr(dosISR); 
}
/*.................................................................*/
int main() {
   unsigned n;
   printf("Quantum DPP, version 1.00, libraries: %s\n", 
           QFgetVersion());
   QFinit(subscrSto, MAX_SIG);
   QFpoolInit((QEvent *)regPoolSto, 
              DIM(regPoolSto), sizeof(TableEvt));
   TableCtor(&aTable);
   QActiveStart((QActive *)&aTable, N + 1, 
                tableQueueSto, DIM(tableQueueSto), 
                0, 0); 
   for (n = 0; n < N; ++n) {
      PhilosopherCtor(&aPhil[n], n);
      QActiveStart((QActive *)&aPhil[n], n + 1, 
                   philQueueSto[n], DIM(philQueueSto[n]), 
                   0, 0);
   }

   dosISR = _dos_getvect(TICK_VECTOR);
   _disable();
   _dos_setvect(TICK_VECTOR, ISR);
   _enable();

   for (;;) {
      QFbackground();
      if (_kbhit()) {
         break;
      }
   }
   QFcleanup();

   _disable();
   _dos_setvect(TICK_VECTOR, dosISR);
   _enable();
   return 0;
}
