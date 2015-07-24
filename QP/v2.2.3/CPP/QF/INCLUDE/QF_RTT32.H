/////////////////////////////////////////////////////////////////////
// Quantum Framework RTT-32-specific declarations (C++ version)
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#ifndef qf_rtt32_h
#define qf_rtt32_h

#include <rttarget.h>

// RTT-32-specific event queue and thread types
#define QF_OS_EVENT(x_)  unsigned x_;
#define QF_EQUEUE(x_)    QEQueue  x_; 
#define QF_THREAD(x_)
#define Q_STATIC_CAST(type_, expr_) static_cast<type_>(expr_)

#include "qevent.h"
#include "qhsm.h"
#include "qequeue.h"                      // RTT-32 needs event-queue
#include "qepool.h"                        // RTT-32 needs event-pool
#include "qactive.h"
#include "qtimer.h"
#include "qf.h"

#endif                                                  // qf_rtt32_h
