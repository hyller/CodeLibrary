/////////////////////////////////////////////////////////////////////
// QF package-scope platform-independent declarations (C++ version)
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#ifndef qfpkg_h
#define qfpkg_h

enum { Q_EMPTY_SIG = 0 };

extern QActive *pkgActive[];       // array of started active objects
extern QEvent const pkgStdEvt[];      // preallocated standard events
extern QTimer *pkgTimerListHead;     // head of linked list of timers

#endif                                                     // qfpkg_h
