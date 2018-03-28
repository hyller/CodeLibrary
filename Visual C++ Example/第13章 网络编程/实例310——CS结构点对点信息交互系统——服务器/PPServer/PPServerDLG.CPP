// PPServerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PPServer.h"
#include "PPServerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

SOCKET g_hSocket = NULL;//监听Socket对象
SOCKET g_hAcceptSocket = NULL;//通信socket对象
HWND  g_hWnd = NULL;
UINT PPServerThreadProc(LPVOID pParam)//线程入口函数
{
	sockaddr_in saClient;//套接字地址协议簇
	ASSERT(g_hSocket != NULL);
	int nLengthAddr = sizeof(SOCKADDR);
	//成功连接后返回实际连接的SOCKET句柄
	g_hAcceptSocket = accept(g_hSocket, (sockaddr*)&saClient, &nLengthAddr);
	if(g_hAcceptSocket == INVALID_SOCKET )
	{
		if(WSAGetLastError() != WSAEINTR)
		{
			AfxMessageBox("调用Accept函数失败");
		}
		return 1;
	}

	// 接受了客户端的连接请求后，立即启动一线程重新开始监听
	AfxBeginThread(PPServerThreadProc,pParam);	
	char sCommand[2048];
	memset(sCommand,0,2048);
	int nBytesReceived;
	//接收客户端发送的数据
	if((nBytesReceived = recv(g_hAcceptSocket, sCommand, 300, 0)) == SOCKET_ERROR)
	{
		AfxMessageBox("接受数据失败");
		return 1 ;
	}	
	if (nBytesReceived == 0)
		return 1;
	//查找是否含有目标命令串
	char sTempCommand[9];
	memset(sTempCommand,0,9);
	strncpy(sTempCommand,sCommand,8);
    if (strcmp(sTempCommand,"SEND MSG") == 0)
	{
		CString strTemp ;
		char szTempBuff[2048];
		memset(szTempBuff,0,2048);
		strcpy(szTempBuff,sCommand+8);
		strTemp = "收到一条客户端消息：\n";
		strTemp += szTempBuff;
		strTemp +="\n\n";
		strTemp += "是否要回复该消息？";
		int nRet = AfxMessageBox(strTemp,MB_OKCANCEL|MB_ICONQUESTION);
		//用户选择回复该短消息，使发送按钮和发送编辑框有效
		if (nRet == IDOK)
		{
			if (g_hWnd)
			{
				EnableWindow(GetDlgItem(g_hWnd,IDC_MSG),TRUE);
				EnableWindow(GetDlgItem(g_hWnd,IDC_SEND),TRUE);
			}
		}
		else
		{
			char sBuff[11];
			memset(sBuff,0,11);
			strcpy(sBuff,"IGNORED");//发送拒绝字符串
			//通知客户端，服务器不对客户消息进行答复
			int nBytesSent;
			if((nBytesSent = send(g_hAcceptSocket, sBuff, strlen(sBuff), 0)) == SOCKET_ERROR) 
			{
				AfxMessageBox("发送数据失败");
			}
			//用户忽略该消息，直接关闭该SOCKET即可
			if(closesocket(g_hAcceptSocket) == SOCKET_ERROR)
			{
				AfxMessageBox("关闭连接失败");
				g_hAcceptSocket = NULL;
				return 1;
			}
		}
	}
	else
	{
		//关闭SOCKET
		if(closesocket(g_hAcceptSocket) == SOCKET_ERROR)
		{
			AfxMessageBox("关闭连接失败");
			g_hAcceptSocket = NULL;
			return 1;
		}
	}
	return 0;
}
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPPServerDlg dialog

CPPServerDlg::CPPServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPPServerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPPServerDlg)
	m_strMsg = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPPServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPPServerDlg)
	DDX_Text(pDX, IDC_MSG, m_strMsg);
	DDV_MaxChars(pDX, m_strMsg, 256);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPPServerDlg, CDialog)
	//{{AFX_MSG_MAP(CPPServerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START, OnStart)
	ON_BN_CLICKED(IDC_END, OnEnd)
	ON_BN_CLICKED(IDC_SEND, OnSend)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPPServerDlg message handlers

BOOL CPPServerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	//保存窗口句柄
	g_hWnd = m_hWnd;

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPPServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPPServerDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPPServerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPPServerDlg::OnStart() 
{
	sockaddr_in saPPServer;
	saPPServer.sin_family = AF_INET;
	saPPServer.sin_port = htons(CONNECE_PORT);
	saPPServer.sin_addr.s_addr = htonl(INADDR_ANY); 	
    ASSERT(g_hSocket == NULL);
	WORD wVersionRequested;
	WSADATA wsaData;
	int nErr;
	wVersionRequested = MAKEWORD( 2, 0 );
	//加载所需的Winsock dll版本
	nErr = WSAStartup( wVersionRequested, &wsaData );
	if(nErr)
	{
		AfxMessageBox("加载Winsock DLL 出错");
		return;
	}
	if((g_hSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) 
	{
		AfxMessageBox("创建Socket失败");
		return;
	}	
	//绑定地址
	if(bind(g_hSocket, (sockaddr*)&saPPServer, sizeof(SOCKADDR)) == SOCKET_ERROR)
	{
		AfxMessageBox("绑定地址失败");
		return;
	}	
	if(listen(g_hSocket, 5) == SOCKET_ERROR) 	//监听客户端请求
	{
		AfxMessageBox("监听客户端请求失败");
		return;
	}	
	//启动一线程来处理客户端请求
	AfxBeginThread(PPServerThreadProc,0);
	GetDlgItem(IDC_START)->EnableWindow(FALSE);//使开始按钮无效
	
}

void CPPServerDlg::OnEnd() 
{
	//关闭Socket
	if(g_hSocket == NULL) return;
	VERIFY(closesocket(g_hSocket) != SOCKET_ERROR);
	g_hSocket = NULL;	
	//使[开启服务器]按钮有效
	GetDlgItem(IDC_START)->EnableWindow(TRUE);
}

void CPPServerDlg::OnSend() 
{
	//获取所需信息
	UpdateData(TRUE);
	//使发送按钮和发送消息编辑框无效
	GetDlgItem(IDC_MSG)->EnableWindow(FALSE);
	GetDlgItem(IDC_SEND)->EnableWindow(FALSE);
	CString strTemp;
	strTemp = "ACK MSG";//应答消息标志
	strTemp += m_strMsg;
	SendMsg(g_hAcceptSocket,strTemp);
}

void CPPServerDlg::SendMsg(SOCKET socket,LPCTSTR sBuff)
{
	int nBytesSent;
	if((nBytesSent=send(socket, sBuff, strlen(sBuff), 0))==SOCKET_ERROR) //发送数据
	{
		AfxMessageBox("发送数据失败");
		return ;
	}
	if(closesocket(socket) == SOCKET_ERROR)//关闭SOCKET
	{
		AfxMessageBox("关闭连接失败");
		g_hAcceptSocket = NULL;
		return ;
	}
	g_hAcceptSocket = INVALID_SOCKET;//重置g_hAcceptSocket的值
	m_strMsg.Empty();//清空m_strMsg的值
	UpdateData(FALSE);
}