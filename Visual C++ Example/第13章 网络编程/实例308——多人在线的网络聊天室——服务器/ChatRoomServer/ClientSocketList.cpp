// ClientSocketList.cpp: implementation of the CClientSocketList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ChatRoomServer.h"
#include "ClientSocketList.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CClientSocketList::CClientSocketList()
{
	Head=0;
}

CClientSocketList::~CClientSocketList()
{

}

BOOL CClientSocketList::Add(CClientSocket *add)
{
	CClientSocket *tmp=Head;
	if (!Head)
	{
		Head=add;
		return true;
	}
	while (tmp->Next) tmp=tmp->Next;
	tmp->Next=add;
	return true;
}

BOOL CClientSocketList::Sends(CClientSocket *tmp)
{
	char buff[1000];
	int n;
	CClientSocket *curr=Head;
	n=tmp->Receive(buff,1000);
	buff[n]=0;
	while (curr)
	{
		curr->Send(buff,n);
		curr=curr->Next;
	}
	return true;
}
