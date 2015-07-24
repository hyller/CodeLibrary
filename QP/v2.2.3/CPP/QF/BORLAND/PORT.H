/////////////////////////////////////////////////////////////////////
// Quantum Framework DOS port declarations (C++ version)
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#ifndef port_h
#define port_h

#include "qf_dos.h"
#include "qfpkg.h"

// DOS-specific critical section operations
//#define QF_PROTECT()          __asm{cli}
//#define QF_UNPROTECT()        __asm{sti}
#define QF_PROTECT()          _disable()
#define QF_UNPROTECT()        _enable()
#define QF_ISR_PROTECT()
#define QF_ISR_UNPROTECT()

// DOS-compiler-specific cast
#define Q_STATE_CAST(x_)      (QState)(x_)

// DOS-specific event queue operations
#define QF_EQUEUE_INIT(q_)    (1)
#define QF_EQUEUE_CLEANUP(q_) 
#define QF_EQUEUE_WAIT(q_)    ASSERT(0)
#define QF_EQUEUE_SIGNAL(q_)  \
   pkgReadyList |= (q_)->myOsEvent; \
   QF_UNPROTECT()
#define QF_EQUEUE_ONEMPTY(q_) (pkgReadyList &= ~(q_)->myOsEvent)

// DOS-specific event pool operations
#define QF_EPOOL              QEPool
#define QF_EPOOL_INIT(p_, poolSto_, nEvts_, evtSize_) \
   (p_)->init(poolSto_, nEvts_, evtSize_); 
#define QF_EPOOL_GET(p_, e_)  ((e_) = (QEvent *)(p_)->get())
#define QF_EPOOL_PUT(p_, e_)  ((p_)->put(e_))

         // the following constant may be bumped up to 15 (inclusive)
         // before redesign of algorithms is necessary 
enum { QF_MAX_ACTIVE = 8 };

// platform-dependent package-scope variables
extern unsigned char pkgReadyList;

#endif                                                      // port_h

