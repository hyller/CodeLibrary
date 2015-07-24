/////////////////////////////////////////////////////////////////////
// Quantum Dining Philosophers DOS version
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include "qassert.h"
#include "port.h"

DEFINE_THIS_FILE;

//...................................................................
enum { TICK_VECTOR = 0x08 };

#ifdef __cplusplus
    #define __CPPARGS ...
#else
    #define __CPPARGS
#endif

typedef void interrupt (*isr_ptr)(__CPPARGS);


static isr_ptr dosISR;
static Table aTable;
static Philosopher aPhil[N] = { 0, 1, 2, 3, 4 };
static QEvent *tableQueueSto[N];
static QEvent *philQueueSto[N][N];
static QSubscrList subscrSto[MAX_SIG];
static TableEvt regPoolSto[N*N];

//...................................................................
extern "C" void onAssert__(char const *file, unsigned line) {
   fprintf(stderr, "Assertion failed in %s, line %d", file, line);
   exit(-1);
}

//...................................................................
void interrupt ISR(__CPPARGS) {
   QF::tick();
   _chain_intr(dosISR);
}

//...................................................................
int main() {
   printf("Quantum DPP, built on %s at %s, libraries: %s\n", 
           __DATE__, __TIME__, QF::getVersion());
   QF::init(subscrSto, MAX_SIG);
   QF::poolInit(regPoolSto, DIM(regPoolSto), sizeof(TableEvt));
   for (unsigned n = 0; n < N; ++n) {
      aPhil[n].start(n + 1, philQueueSto[n], DIM(philQueueSto[n]), 
                     0, 0);
   }
   aTable.start(N + 1, tableQueueSto, 
                DIM(tableQueueSto), 0, 0); 

   dosISR = _dos_getvect(TICK_VECTOR);
   _disable();
   _dos_setvect(TICK_VECTOR, ISR);
   _enable();

   for (;;) {
      QF::background();
      if (kbhit()) {
         break;
      }
   }
   QF::cleanup();

   _disable();
   _dos_setvect(TICK_VECTOR, dosISR);
   _enable();
   return 0;
}
