// PPClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PPClient.h"
#include "PPClientDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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
// CPPClientDlg dialog

CPPClientDlg::CPPClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPPClientDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPPClientDlg)
	m_strMsg = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_hSocket = NULL;
}

void CPPClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPPClientDlg)
	DDX_Control(pDX, ID_SERVER, m_ctrlServer);
	DDX_Text(pDX, IDC_MSG, m_strMsg);
	DDV_MaxChars(pDX, m_strMsg, 256);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPPClientDlg, CDialog)
	//{{AFX_MSG_MAP(CPPClientDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SEND, OnSend)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPPClientDlg message handlers

BOOL CPPClientDlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPPClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPPClientDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in PPClient rectangle
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
HCURSOR CPPClientDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPPClientDlg::OnSend() 
{
	UpdateData(TRUE);
	//得到服务器IP地址
	BYTE b1,b2,b3,b4;
	m_ctrlServer.GetAddress(b1,b2,b3,b4);
    char strServer[256];
	memset(strServer,0,256);
	sprintf(strServer,"%d.%d.%d.%d",b1,b2,b3,b4);
	//设置客户端要同步的服务器的sockaddr_in结构
	m_ServerAddr.sin_family = AF_INET;
	m_ServerAddr.sin_port = htons(CONNECE_PORT);
    m_ServerAddr.sin_addr.s_addr = inet_addr(strServer); 
	m_hSocket = NULL;	
	ContactServer();//连接服务器	
	m_strMsg.Empty();//清空m_strMsg的值
	UpdateData(FALSE);
}

void CPPClientDlg::ContactServer()
{
	ASSERT(m_hSocket == NULL);
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
	if((m_hSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) 
	{
		AfxMessageBox("创建Socket失败");
		return;
	}	
	//连接服务器
	ASSERT(m_hSocket != NULL);
	if(connect(m_hSocket, (sockaddr*)&m_ServerAddr, sizeof(SOCKADDR)) == SOCKET_ERROR)
	{
		AfxMessageBox("连接服务器失败");
		return;
	}
	//构造消息命令串，此处的消息命令串比较简单，
	//只有SEND MSG八个字符
	CString strMsg = "SEND MSG";
	strMsg += m_strMsg;
	int nLen = strMsg.GetLength();
	//向服务器端发送消息请求
	FD_SET fd = {1, m_hSocket};
	TIMEVAL tv = {TIME_OUT,0};
	if(select(0, NULL, &fd, NULL, &tv) == 0) 
	{
		AfxMessageBox("发送超时");
		return;
	}
	int nBytesSent;
	if((nBytesSent = send(m_hSocket, strMsg, nLen, 0)) == SOCKET_ERROR) 
	{
		AfxMessageBox("发送数据失败");
		return;
	}
	if (nBytesSent == nLen)          // 发送成功
	{
		AfxMessageBox("发送数据成功");
		char m_pReadBuf[256];
		//循环等待服务器的相应消息
		while(1)
		{			//给接受数据缓冲区清零
			memset(m_pReadBuf,0,256);
			if(select(0, &fd, NULL, NULL, &tv) == 0) 
			{
				AfxMessageBox("接受超时");
				return;
			}
			//接收数据
			int nBytesReceived;
			if((nBytesReceived = recv(m_hSocket, m_pReadBuf, 255, 0)) == SOCKET_ERROR)
			{
				AfxMessageBox("接受数据失败");
				return;
			}  
			//如果接受到的数据长度大于0，则退出循环，否则循环等待
			if (nBytesReceived > 0)
				break;
		};
		char strCommand[9];
		memset(strCommand,0,9);
		strncpy(strCommand,m_pReadBuf,7);
		if (strcmp(strCommand,"ACK MSG") == 0)   //只处理服务器端对原消息的应答数据
		{      
			CString strAckMsg;
			char szTempBuff[256];
			memset(szTempBuff,0,256);
			strcpy(szTempBuff,m_pReadBuf+7);
			strAckMsg = "服务器端返回的应答数据是：\n";
			strAckMsg += szTempBuff;

			AfxMessageBox(strAckMsg);			
		}	
		if (strcmp(strCommand,"IGNORED")== 0)
		{
			AfxMessageBox("服务器端忽略了该消息");
		}
	}
	// 关闭Socket
	if(closesocket(m_hSocket) == SOCKET_ERROR)
	{
		AfxMessageBox("关闭连接失败");
		m_hSocket = NULL;
		return;
	}
	
}


