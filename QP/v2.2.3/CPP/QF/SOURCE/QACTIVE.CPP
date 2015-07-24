/////////////////////////////////////////////////////////////////////
// Quantum Active Object implemenatation
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#include "qassert.h"
#include "port.h"

DEFINE_THIS_FILE;

//...................................................................
QActive::QActive(QPseudoState initial) : QHsm(initial) {
}
//...................................................................
QActive::~QActive() {}
