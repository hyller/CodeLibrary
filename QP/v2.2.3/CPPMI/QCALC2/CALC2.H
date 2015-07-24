/////////////////////////////////////////////////////////////////////
// QP Calc2.h -- application example
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#ifndef calc2_h
#define calc2_h

#include "calc1.h"

class TestBase {
public:
   virtual ~TestBase() {}
};

class Calc2 : public TestBase, public Calc1 {               // use MI
protected:
   Q_DEFINE_CALL_MEMBER_FN(Calc2)            // Define callMemberFn()
   virtual CQSTATE operand2(QEvent const *e);
};

#endif                                                     // calc2_h
