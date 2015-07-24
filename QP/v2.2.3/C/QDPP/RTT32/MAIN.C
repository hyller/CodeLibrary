/******************************************************************** 
 * Quantum Dining Philosophers RTT32 port (C version)
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
enum { TIMER_IRQ = 0 };

static RTInterruptGate rtt32ISR;        /* to save original vector */
static QSubscrList subscrSto[MAX_SIG];
static TableEvt regPoolSto[N*N];
static Table aTable;
static Philosopher aPhil[N];
static QEvent *tableQueueSto[N];
static QEvent *philQueueSto[N][N];

/*.................................................................*/
void onAssert__(char const *file, unsigned line) {
   fprintf(stderr, "Assertion failed in %s, line %d", file, line);
   exit(-1); 
}
/*.................................................................*/
static void __cdecl ISR(void) {                  /* high-level ISR */
   QFtick();
   RTIRQEnd(TIMER_IRQ);               /* tell PIC that we are done */
}
/*.................................................................*/
__declspec(naked) void asmISR(void) { /*low-level interrupt handler*/
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
/*.................................................................*/
int main() {
   unsigned n;
   printf("Quantum DPP, version 1.00, libraries: %s\n", 
           QFgetVersion());
   RTSaveVector(RTIRQ0Vector + TIMER_IRQ, &rtt32ISR);
   RTSetTrapVector(RTIRQ0Vector + TIMER_IRQ, asmISR);
   RTEnableIRQ(TIMER_IRQ);          /* tell PIC to enable this IRQ */

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
   for (;;) {
      QFbackground();
      if (_kbhit()) {
         break;
      }
   }
   QFcleanup();

   RTDisableIRQ(TIMER_IRQ);
   RTRestoreVector(RTIRQ0Vector + TIMER_IRQ, &rtt32ISR);
   return 0;
}
