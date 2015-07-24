/////////////////////////////////////////////////////////////////////
// QP Calc2.h -- application example
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#ifndef calc2_h
#define calc2_h

#include "calc1.h"

class Calc2 : public Calc1 {
protected:
   virtual QSTATE operand2(QEvent const *e);
};

#endif                                                     // calc2_h
