/////////////////////////////////////////////////////////////////////
// Quantum Calculator example (C++ version)
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#include "calc1.h"

Calc1 *Calc1::instance() {
   static Calc1 inst;
   return &inst;
}
