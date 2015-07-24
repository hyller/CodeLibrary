/////////////////////////////////////////////////////////////////////
// Quantum Framework RTK-32-specific declarations (C++ version)
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#ifndef qf_rtk32a_h
#define qf_rtk32a_h

#include <rtk32.h>

// RTK-32A-specific event queue and thread types
#define QF_OS_EVENT(x_)  RTKSemaphore  x_;
#define QF_EQUEUE(x_)    QEQueue       x_; 
#define QF_THREAD(x_)    RTKTaskHandle x_;
#define Q_STATIC_CAST(type_, expr_) static_cast<type_>(expr_)

#include "qevent.h"
#include "qhsm.h"
#include "qequeue.h"                     // RTK-32A needs event-queue
#include "qepool.h"                       // RTK-32A needs event-pool
#include "qactive.h"
#include "qtimer.h"
#include "qf.h"

#endif                                                 // qf_rtk32a_h
