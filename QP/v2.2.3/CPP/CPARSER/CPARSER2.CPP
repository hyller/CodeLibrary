/////////////////////////////////////////////////////////////////////
// QP C-comment parser example
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#include "cparser2.h"
#include "qassert.h"

DEFINE_THIS_FILE;

StateTable::Tran const CParser2::myTable[MAX_STATE][MAX_SIG] = {
   {{&StateTable::doNothing, CODE },
    {&StateTable::doNothing, CODE },
    {&StateTable::doNothing, SLASH}},
   {{&StateTable::doNothing, CODE },
    {static_cast<StateTable::Action>(&CParser2::a2), COMMENT },
    {&StateTable::doNothing, CODE }},
   {{static_cast<StateTable::Action>(&CParser2::a1), COMMENT },
    {&StateTable::doNothing,STAR  },
    {static_cast<StateTable::Action>(&CParser2::a1), COMMENT }},
   {{static_cast<StateTable::Action>(&CParser2::a2), COMMENT },
    {static_cast<StateTable::Action>(&CParser2::a1), STAR },
    {static_cast<StateTable::Action>(&CParser2::a2), CODE }}
};

