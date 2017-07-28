// ClientSocket.cpp : implementation file
//

#include "stdafx.h"
#include "TransClient.h"
#include "ClientSocket.h"
#include "TransClientDlg.h "
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClientSocket

CClientSocket::CClientSocket()
{
	//初始化变量
	m_nLength=0;
	memset(m_szBuffer,0,sizeof(m_szBuffer));
	m_bConnected=FALSE;
}

CClientSocket::~CClientSocket()
{
	//如果套接字有效，则关闭套接字
	if(m_hSocket!=INVALID_SOCKET)
	Close();
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CClientSocket, CAsyncSocket)
	//{{AFX_MSG_MAP(CClientSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CClientSocket member functions

void CClientSocket::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	m_nLength=Receive(m_szBuffer,sizeof(m_szBuffer),0);
	//下面两行代码用来获取对话框指针
	CTransClientApp* pApp=(CTransClientApp*)AfxGetApp();
	CTransClientDlg* pDlg=(CTransClientDlg*)pApp->m_pMainWnd;
	pDlg->m_MsgR.InsertString(0,m_szBuffer);//列表框添加接收的数据
	memset(m_szBuffer,0,sizeof(m_szBuffer));//清除缓冲区数据
	CAsyncSocket::OnReceive(nErrorCode);
}

void CClientSocket::OnSend(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	Send(m_szBuffer,m_nLength,0);//发送数据
	m_nLength=0;
	memset(m_szBuffer,0,sizeof(m_szBuffer));//清除缓冲区数据
	//继续提请一个"读"的网络事件，接收Server消息
	AsyncSelect(FD_READ);
	CAsyncSocket::OnSend(nErrorCode);
}

void CClientSocket::OnConnect(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	if (nErrorCode==0)//连接成功
	{
		m_bConnected=TRUE;
		//下面两行代码用来获取对话框指针
		CTransClientApp* pApp=(CTransClientApp*)AfxGetApp();
		CTransClientDlg* pDlg=(CTransClientDlg*)pApp->m_pMainWnd;
		memcpy(m_szBuffer,"连接到： ",13);
		strncat(m_szBuffer,pDlg->m_szServerAdr,sizeof(pDlg->m_szServerAdr));
		pDlg->m_MsgR.InsertString(0,m_szBuffer);
		pDlg->GetDlgItem(IDC_SEND)->EnableWindow(true);
		AsyncSelect(FD_READ);  //提请一个"读"的网络事件，准备接收
	}
	CAsyncSocket::OnConnect(nErrorCode);
}
