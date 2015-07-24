/////////////////////////////////////////////////////////////////////
// Quantum Dining Philosophers RTT32 version
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
enum { TIMER_IRQ = 0 };

static RTInterruptGate rtt32ISR;           // to save original vector
static Table aTable;
static Philosopher aPhil[N] = { 0, 1, 2, 3, 4 };
static QEvent *tableQueueSto[N];
static QEvent *philQueueSto[N][N];
static TableEvt regPoolSto[N*N];
static QSubscrList subscrSto[MAX_SIG];

//...................................................................
extern "C" void onAssert__(char const *file, unsigned line) {
   fprintf(stderr, "Assertion failed in %s, line %d", file, line);
   exit(-1); 
}

//...................................................................
static void __cdecl ISR(void) {//high-level Interrupt Service Routine
   QF::tick();
   RTIRQEnd(TIMER_IRQ);                  // tell PIC that we are done
}

__declspec(naked) void asmISR(void) {  // low-level interrupt handler
   __asm {
      push  eax            ; save all registers which may be changed
      push  edx            ; by C/C++ code
      push  ecx
      push  ds
      push  es
      cld                  ; required by C/C++ run-time system
      mov   ax, cs         ; data selector comes right after
      lea   eax, [eax+8]   ; code selector (ES = DS = CS + 8)
      mov   ds, ax         ; initialize default data segment
      mov   es, ax
      call  ISR            ; call 'C' Handler
      pop   es             ; restore registers
      pop   ds
      pop   ecx
      pop   edx
      pop   eax
      iretd                ; interrupt return
   }
}

//...................................................................
int main() {
   printf("Quantum DPP, built on %s at %s, libraries: %s\n", 
           __DATE__, __TIME__, QF::getVersion());
   RTSaveVector(RTIRQ0Vector + TIMER_IRQ, &rtt32ISR);
   RTSetIntVector(RTIRQ0Vector + TIMER_IRQ, asmISR);
   RTEnableIRQ(TIMER_IRQ);             // tell PIC to enable this IRQ

   QF::init(subscrSto, MAX_SIG);
   QF::poolInit(regPoolSto, DIM(regPoolSto), sizeof(TableEvt));
   for (unsigned n = 0; n < N; ++n) {
      aPhil[n].start(n + 1, philQueueSto[n], DIM(philQueueSto[n]), 
                     0, 0);
   }
   aTable.start(N + 1, tableQueueSto, DIM(tableQueueSto), 0, 0); 
   for (;;) {
      QF::background();
      if (_kbhit()) {
         break;
      }
   }
   QF::cleanup();

   RTDisableIRQ(TIMER_IRQ);
   RTRestoreVector(RTIRQ0Vector + TIMER_IRQ, &rtt32ISR);

   return 0;
}
