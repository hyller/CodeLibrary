/////////////////////////////////////////////////////////////////////
// QP C-comment parser example
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#include "cparser7.h"
#include "qassert.h"

DEFINE_THIS_FILE;

StateTable::Action const CParser7::myTable[MAX_STATE][MAX_SIG] = {
   {&StateTable::doNothing, 
    &StateTable::doNothing, 
    static_cast<StateTable::Action>(&CParser7::codeOnSLASH) },
   {static_cast<StateTable::Action>(&CParser7::slashOnCHAR), 
    static_cast<StateTable::Action>(&CParser7::slashOnSTAR), 
    static_cast<StateTable::Action>(&CParser7::slashOnSLASH) },
   {static_cast<StateTable::Action>(&CParser7::commentOnCHAR),
    static_cast<StateTable::Action>(&CParser7::commentOnSTAR), 
    static_cast<StateTable::Action>(&CParser7::commentOnSLASH)},
   {static_cast<StateTable::Action>(&CParser7::starOnCHAR), 
    static_cast<StateTable::Action>(&CParser7::starOnSTAR),
    static_cast<StateTable::Action>(&CParser7::starOnSLASH) }
};

