// ListenSocket.cpp : implementation file
//

#include "stdafx.h"
#include "TransServer.h"
#include "ListenSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CListenSocket

CListenSocket::CListenSocket()
{
}

CListenSocket::~CListenSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CListenSocket, CAsyncSocket)
	//{{AFX_MSG_MAP(CListenSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CListenSocket member functions

void CListenSocket::OnAccept(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	//侦听到连接请求，调用Accept函数
	CNewSocket* pSocket = new CNewSocket();
	if(Accept(*pSocket))//接受连接
	{
		pSocket->AsyncSelect(FD_READ);//触发通信Socket的Read函数读数据
		m_pSocket=pSocket;//记录当前通信Socket
	}
	else
    delete pSocket;
	CAsyncSocket::OnAccept(nErrorCode);
}
