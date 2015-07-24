/******************************************************************** 
 * Quantum Framework DOS-specific declarations ("C+" version)
 * Copyright (c) 2002 Miro Samek, Palo Alto, CA.
 * All Rights Reserved.
 *******************************************************************/ 
#ifndef qf_dos_h
#define qf_dos_h

#include <dos.h>

/* DOS-specific event queue and thread types */
#define QF_OS_EVENT(x_)  unsigned x_;
#define QF_EQUEUE(x_)    QEQueue  x_; 
#define QF_THREAD(x_)

#include "qevent.h"
#include "qhsm.h"
#include "qequeue.h"                      /* DOS needs event-queue */
#include "qepool.h"                        /* DOS needs event-pool */
#include "qactive.h"
#include "qtimer.h"
#include "qf.h"

#endif                                                 /* qf_dos_h */
