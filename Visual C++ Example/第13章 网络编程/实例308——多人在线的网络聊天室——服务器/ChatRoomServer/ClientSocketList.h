// ClientSocketList.h: interface for the CClientSocketList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLIENTSOCKETLIST_H__E746355D_FA10_4D12_B544_2FF152C16414__INCLUDED_)
#define AFX_CLIENTSOCKETLIST_H__E746355D_FA10_4D12_B544_2FF152C16414__INCLUDED_
#include "ClientSocket.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CClientSocketList  
{
public:
	BOOL Sends(CClientSocket *);
	BOOL Add(CClientSocket *);
	CClientSocket * Head;
	CClientSocketList();
	virtual ~CClientSocketList();

};

#endif // !defined(AFX_CLIENTSOCKETLIST_H__E746355D_FA10_4D12_B544_2FF152C16414__INCLUDED_)
