/******************************************************************** 
 * Quantum Framework Win32-specific declarations ("C+" version) 
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA.
 * All Rights Reserved.
 *******************************************************************/
#ifndef qf_win32_h
#define qf_win32_h

#include <windows.h>

/* Win32-specific event pool, queue and thread types */
#define QF_OS_EVENT(x_)  HANDLE  x_;
#define QF_EQUEUE(x_)    QEQueue x_; 
#define QF_THREAD(x_)    HANDLE  x_;

#include "qevent.h"
#include "qfsm.h"
#include "qhsm.h"
#include "qequeue.h"                    /* Win32 needs event-queue */
#include "qepool.h"                      /* Win32 needs event-pool */
#include "qactive.h"
#include "qtimer.h"
#include "qf.h"

#endif                                               /* qf_win32_h */
