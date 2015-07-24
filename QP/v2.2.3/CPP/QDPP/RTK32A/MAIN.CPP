/////////////////////////////////////////////////////////////////////
// Quantum Dining Philosophers RTK-32A port
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#include "qassert.h"
#include "port.h"
#include <stdlib.h>
#include <stdio.h>
#include <rtkeybrd.h>
#include <clock.h>

DEFINE_THIS_FILE;

// RTK-32 configuration .............................................
RTK32Config RTKConfig = {
    sizeof(RTK32Config),                             // StructureSize
    0,                                                // Driver flags
    0,                                           // User driver flags
    RF_PREEMPTIVE | RF_STACKCHECKS | RF_FPCONTEXT,           // Flags
    4*1024,                                   // DefaultTaskStackSize
    512,                                       // DefaultIntStackSize
    RTK_MIN_PRIO,                                     // MainPriority
    0,                                             // DefaultPriority
    0x00000003,                     // HookedInterrupts (IRQ 0 and 1)
    256,                                         // TaskStackOverhead
    0                                          // Time slice (0==off)
};

//...................................................................
enum { TIMER_IRQ = 0, TICKS_PER_SEC = 20};

static RTKIRQDescriptor rtk32ISR;
static void RTKAPI ISR(void) { //high-level Interrupt Service Routine
   QF::tick();
   RTKCallIRQHandlerFar(&rtk32ISR);            // chain to RTK-32 ISR
}

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

                      // Initialize the kernel and keyboard driver...
   RTKernelInit(RTK_MIN_PRIO /* this task priority */);
   KBInit();

   RTKDisableIRQ(TIMER_IRQ);
   RTKSaveIRQHandlerFar(TIMER_IRQ, &rtk32ISR);
   RTKSetIRQHandler(TIMER_IRQ, ISR);        // hook up the custom ISR
   RTKEnableIRQ(TIMER_IRQ);

             // set up the ticking rate consistent with TICKS_PER_SEC
   CLKSetTimerIntVal((unsigned)(1e6/TICKS_PER_SEC + 0.5));
   RTKDelay(1);                  // wait for the value to take effect

   QF::init(subscrSto, MAX_SIG);
   QF::poolInit(regPoolSto, DIM(regPoolSto), sizeof(TableEvt));
   for (unsigned n = 0; n < N; ++n) {
      aPhil[n].start(n + 1, philQueueSto[n], DIM(philQueueSto[n]), 
                     0, 4*1024);
   }
   aTable.start(N + 1, tableQueueSto, DIM(tableQueueSto), 
                0, 4*1024); 

   printf("Hit ENTER to stop\n");
   getc(stdin);
   printf("Bye! Bye!\n");

   QF::cleanup();
   return 0;
}
