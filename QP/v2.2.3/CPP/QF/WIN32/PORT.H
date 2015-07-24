/////////////////////////////////////////////////////////////////////
// Quantum Framework Win32 port declarations (C++ version)
// Copyright (c) 2002 Miro Samek, Palo Alto, CA.
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#ifndef port_h
#define port_h

#include "qf_win32.h"
#include "qfpkg.h"

// Win32-specific critical section operations
extern  CRITICAL_SECTION      pkgWin32CritSect;
#define QF_PROTECT()          EnterCriticalSection(&pkgWin32CritSect)
#define QF_UNPROTECT()        LeaveCriticalSection(&pkgWin32CritSect)
#define QF_ISR_PROTECT()      QF_PROTECT()
#define QF_ISR_UNPROTECT()    QF_UNPROTECT()

// Win32-compiler-specific cast
#define Q_STATE_CAST(x_)      reinterpret_cast<QState>(x_)

// Win32-specific event queue operations
#define QF_EQUEUE_INIT(q_) \
   ((q_)->myOsEvent = CreateEvent(NULL, FALSE, FALSE, NULL))
#define QF_EQUEUE_CLEANUP(q_) CloseHandle((q_)->myOsEvent)
#define QF_EQUEUE_WAIT(q_) \
   QF_UNPROTECT(); \
   do { \
      WaitForSingleObject((q_)->myOsEvent, INFINITE); \
   } while ((q_)->myFrontEvt == 0); \
   QF_PROTECT()
#define QF_EQUEUE_SIGNAL(q_) \
   QF_UNPROTECT(); \
   SetEvent((q_)->myOsEvent)
#define QF_EQUEUE_ONEMPTY(q_)

// Win32-specific event pool operations
#define QF_EPOOL              QEPool
#define QF_EPOOL_INIT(p_, poolSto_, nEvts_, evtSize_) \
   (p_)->init(poolSto_, nEvts_, evtSize_); 
#define QF_EPOOL_GET(p_, e_)  ((e_) = (p_)->get())
#define QF_EPOOL_PUT(p_, e_)  ((p_)->put(e_))

         // the following constant may be bumped up to 15 (inclusive)
         // before redesign of algorithms is necessary 
enum { QF_MAX_ACTIVE = 15 };


#endif                                                      // port_h

