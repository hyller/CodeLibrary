/////////////////////////////////////////////////////////////////////
// Quantum Calculator example (C++ version)
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#include "calc2.h"

Calc1 *Calc1::instance() {
   static Calc2 inst;
   return &inst;
}
