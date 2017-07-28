// NewSocket.cpp : implementation file
//

#include "stdafx.h"
#include "TransServer.h"
#include "NewSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNewSocket

CNewSocket::CNewSocket()
{
	//成员变量初始化
	m_nLength=0;
	memset(m_szBuffer,0,sizeof(m_szBuffer));
}

CNewSocket::~CNewSocket()
{
	//关闭套接字
	if(m_hSocket!=INVALID_SOCKET)
    Close();
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CNewSocket, CAsyncSocket)
	//{{AFX_MSG_MAP(CNewSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CNewSocket member functions

void CNewSocket::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	m_nLength=Receive(m_szBuffer,sizeof(m_szBuffer),0);
	// 直接转发消息
	AsyncSelect(FD_WRITE);	//触发OnSend函数
	CAsyncSocket::OnReceive(nErrorCode);
}

void CNewSocket::OnSend(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	char m_sendBuffer[4096];  //消息缓冲区
	memcpy(m_sendBuffer,"服务器转发：",24);
	strncat(m_sendBuffer,m_szBuffer,m_nLength);
	Send(m_sendBuffer,sizeof(m_sendBuffer));//发送数据
	AsyncSelect(FD_READ);	//触发OnReceive函数
	CAsyncSocket::OnSend(nErrorCode);
}
