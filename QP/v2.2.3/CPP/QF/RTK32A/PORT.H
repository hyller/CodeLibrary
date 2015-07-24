/////////////////////////////////////////////////////////////////////
// Quantum Framework RTK32 port (C++ version)
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#ifndef port_h
#define port_h

#include "qf_rtk32a.h"
#include "qfpkg.h"

// RTK-32A-specific critical section operations
//#define QF_PROTECT()          RTKDisableInterrupts()
//#define QF_UNPROTECT()        RTKEnableInterrupts()
#define QF_PROTECT()          __asm{cli}
#define QF_UNPROTECT()        __asm{sti}
#define QF_ISR_PROTECT()
#define QF_ISR_UNPROTECT()

// RTK-32A-compiler-specific cast
#define Q_STATE_CAST(x_)      reinterpret_cast<QState>(x_)

// RTK-32A-specific event queue operations
#define QF_EQUEUE_INIT(q_) \
   ((q_)->myOsEvent = RTKCreateSemaphore(ST_BINARY, 0, ""))
#define QF_EQUEUE_CLEANUP(q_) RTKDeleteSemaphore(&(q_)->myOsEvent)
#define QF_EQUEUE_WAIT(q_) \
   QF_UNPROTECT(); \
   do { \
      RTKWait((q_)->myOsEvent); \
   } while ((q_)->myFrontEvt == 0);\
   QF_PROTECT()
#define QF_EQUEUE_SIGNAL(q_) \
   QF_UNPROTECT(); \
   RTKSignal((q_)->myOsEvent)
#define QF_EQUEUE_ONEMPTY(q_)

// RTK-32A-specific event pool operations
#define QF_EPOOL              QEPool
#define QF_EPOOL_INIT(p_, poolSto_, nEvts_, evtSize_) \
   (p_)->init(poolSto_, nEvts_, evtSize_); 
#define QF_EPOOL_GET(p_, e_)  ((e_) = (p_)->get())
#define QF_EPOOL_PUT(p_, e_)  ((p_)->put(e_))

         // the following constant may be bumped up to 15 (inclusive)
         // before redesign of algorithms is necessary 
enum { QF_MAX_ACTIVE = 15 };

#endif                                                      // port_h

