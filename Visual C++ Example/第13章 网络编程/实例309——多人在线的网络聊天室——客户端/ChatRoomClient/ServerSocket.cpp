// ServerSocket.cpp : implementation file
//

#include "stdafx.h"
#include "ChatRoomClient.h"
#include "ServerSocket.h"
#include "ChatRoomClientDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CServerSocket

CServerSocket::CServerSocket()
{
	NikeName="";
	myDlg=0;
}

CServerSocket::~CServerSocket()
{
}

BOOL CServerSocket::SetDlg(CChatRoomClientDlg *tmp)
{
	myDlg=tmp;
	return true;
}
// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CServerSocket, CSocket)
	//{{AFX_MSG_MAP(CServerSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CServerSocket member functions

void CServerSocket::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	myDlg->GetMessage();
	CSocket::OnReceive(nErrorCode);	
}
