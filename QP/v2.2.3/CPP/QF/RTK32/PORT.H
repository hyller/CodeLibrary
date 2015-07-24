/////////////////////////////////////////////////////////////////////
// Quantum Framework RTK32 port (C++ version)
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#ifndef port_h
#define port_h

#include "qf_rtk32.h"
#include "qfpkg.h"

// RTK32-specific critical section operations
#define QF_PROTECT()          RTKDisableInterrupts()
#define QF_UNPROTECT()        RTKEnableInterrupts()
//#define QF_PROTECT()          __asm{cli}
//#define QF_UNPROTECT()        __asm{sti}
#define QF_ISR_PROTECT()
#define QF_ISR_UNPROTECT()

// RTK32-compiler-specific cast
#define Q_STATE_CAST(x_)      reinterpret_cast<QState>(x_)

// RTK32-specific event pool
class QEPool {                                // "Quantum" Event Pool
   friend class QF;
   RTKMemPool myRTKPool;                           // RTK memory pool
   unsigned short myEvtSize;         // maximum event size (in bytes)   
};

// RTK32-specific event pool operations
#define QF_EPOOL              QEPool
#define QF_EPOOL_INIT(p_, poolSto_, nEvts_, evtSize_) \
   if (1) { \
      ASSERT(poolSto_ == 0); \
      (p_)->myEvtSize = evtSize_; \
      RTKAllocMemPool(&(p_)->myRTKPool, evtSize_, nEvts_); \
   } else
#define QF_EPOOL_GET(p_, e_) \
   ((e_) = (QEvent *)RTKGetBuffer(&(p_)->myRTKPool))
#define QF_EPOOL_PUT(p_, e_) \
   RTKFreeBuffer(&(p_)->myRTKPool, e_);

         // the following constant may be bumped up to 15 (inclusive)
         // before redesign of algorithms is necessary 
enum { QF_MAX_ACTIVE = 15 };

#endif                                                      // port_h

