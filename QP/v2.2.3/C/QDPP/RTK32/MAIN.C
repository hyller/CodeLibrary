/******************************************************************** 
 * Quantum Dining Philosophers RTK32 port ("C+" version)
 * (c) Copyright 2001, Miro Samek, Palo Alto, CA
 * All Rights Reserved
 *******************************************************************/
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include "qassert.h"
#include "port.h"

DEFINE_THIS_FILE;

/* RTK configuration ..............................................*/
RTK32Config RTKConfig = {
    sizeof(RTK32Config),                          /* StructureSize */
    0,                                             /* Driver flags */
    0,                                        /* User driver flags */
    RF_PREEMPTIVE | RF_STACKCHECKS | RF_FPCONTEXT,        /* Flags */
    4*1024,                                /* DefaultTaskStackSize */
    1024,                                   /* DefaultIntStackSize */
    RTK_MAX_PRIO,                                  /* MainPriority */
    0,                                          /* DefaultPriority */
    0x00000003,                  /* HookedInterrupts (IRQ 0 and 1) */
    256,                                      /* TaskStackOverhead */
    0                                       /* Time slice (0==off) */
};

enum { TIMER_IRQ = 0, TICKS_PER_SEC = 20};

static RTKIRQDescriptor rtk32ISR;
static QSubscrList subscrSto[MAX_SIG];
static Table aTable;
static Philosopher aPhil[N];
/*.................................................................*/
static void RTKAPI ISR(void) {   /* tick Interrupt Service Routine */
   QFtick();
   RTKCallIRQHandlerFar(&rtk32ISR);          /* chain to RTK32 ISR */
}
/*.................................................................*/
void onAssert__(char const *file, unsigned line) {
   fprintf(stderr, "Assertion failed in %s, line %d", file, line);
   exit(-1); 
}
/*.................................................................*/
int main() {
   unsigned n;
   printf("Quantum DPP, built on %s at %s, libraries: %s\n", 
           __DATE__, __TIME__, QFgetVersion());

   RTKernelInit(RTK_MIN_PRIO /* this task priority */);
   KBInit();

   RTKDisableIRQ(TIMER_IRQ);
   RTKSaveIRQHandlerFar(TIMER_IRQ, &rtk32ISR);
   RTKSetIRQHandler(TIMER_IRQ, ISR);     /* hook up the custom ISR */
   RTKEnableIRQ(TIMER_IRQ);

   CLKSetTimerIntVal((unsigned)(1e6/TICKS_PER_SEC + 0.5));
   RTKDelay(1);               /* wait for the value to take effect */

   QFinit(subscrSto, MAX_SIG);
   QFpoolInit(0, 20, sizeof(TableEvt));
   TableCtor(&aTable);
   QActiveStart((QActive *)&aTable, N + 1, 
                0, 10,  
                0, 4*1024); 
   for (n = 0; n < N; ++n) {
      PhilosopherCtor(&aPhil[n], n);
      QActiveStart((QActive *)&aPhil[n], n + 1, 
                   0, 10, 
                   0, 4*1024);
   }

   printf("Hit ENTER to stop\n");
   getc(stdin);
   printf("Bye! Bye!\n");

   QFcleanup();
   return 0;
}
