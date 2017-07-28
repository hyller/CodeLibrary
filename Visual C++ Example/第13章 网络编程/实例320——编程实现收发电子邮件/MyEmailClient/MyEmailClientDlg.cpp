// MyEmailClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyEmailClient.h"
#include "MyEmailClientDlg.h"
#include "MailMessage.h"
#include "POP3.h"
#include "SMTP.h"

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
// CMyEmailClientDlg dialog

CMyEmailClientDlg::CMyEmailClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyEmailClientDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyEmailClientDlg)
	m_Body = _T("");
	m_From = _T("");
	m_Password = _T("");
	m_POP3 = _T("");
	m_SMTP = _T("");
	m_To = _T("");
	m_User = _T("");
	m_Subject = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyEmailClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyEmailClientDlg)
	DDX_Text(pDX, IDC_BODY, m_Body);
	DDX_Text(pDX, IDC_FROM, m_From);
	DDX_Text(pDX, IDC_PASSWORD, m_Password);
	DDX_Text(pDX, IDC_POP3, m_POP3);
	DDX_Text(pDX, IDC_SMTP, m_SMTP);
	DDX_Text(pDX, IDC_TO, m_To);
	DDX_Text(pDX, IDC_USER, m_User);
	DDX_Text(pDX, IDC_SUBJECT, m_Subject);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyEmailClientDlg, CDialog)
	//{{AFX_MSG_MAP(CMyEmailClientDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SEND, OnSend)
	ON_BN_CLICKED(IDC_RETR, OnRetr)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyEmailClientDlg message handlers

BOOL CMyEmailClientDlg::OnInitDialog()
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

void CMyEmailClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMyEmailClientDlg::OnPaint() 
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
HCURSOR CMyEmailClientDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyEmailClientDlg::OnSend() //发信
{
	UpdateData( TRUE );
	CSMTP smtp( m_SMTP );//建立CSMTP对象
	//新建CMailMessage对象，并初始化
	CMailMessage msg;
	msg.m_sFrom = m_From;
	msg.AddMultipleRecipients(m_To );
	msg.m_sSubject = m_Subject;
	msg.m_sBody = m_Body;
	if(!smtp.Connect())//连接SMTP服务器
	{
		AfxMessageBox(smtp.GetLastError());
		return;
	}	
	if( !smtp.SendMessage(&msg ))//发信
	{
		AfxMessageBox(smtp.GetLastError());
		return;
	}
	if( !smtp.Disconnect() )//断开连接
	{
		AfxMessageBox( smtp.GetLastError() );
		return;
	}
	AfxMessageBox("邮件成功发送！");
}

void CMyEmailClientDlg::OnRetr() //收信
{
	UpdateData( TRUE );
	//新建CPOP3对象
	CPOP3 pop3( m_POP3 );
	pop3.SetUserProperties(m_User,m_Password);
	if (!pop3.Connect())//连接POP3服务器
	{
		AfxMessageBox(pop3.GetLastError());
		return;
	}
	CMailMessage msg;
	if (!pop3.GetMessage(1,&msg))//收取信件
	{
		AfxMessageBox(pop3.GetLastError());
		return;
	}
	//显示信件
	m_Body=msg.m_sBody;
	m_Subject=msg.m_sSubject;
	m_From=msg.m_sFrom;
	m_To="";
	for (int a=0; a<msg.GetNumRecipients(); a++)
	{
		CString sEmail;
		CString sFriendly;
		msg.GetRecipient(sEmail,sFriendly,a);
		m_To+=sEmail;
		m_To+=" ";
	}
	m_To.TrimRight();
	if( !pop3.Disconnect())//断开连接
	{
		AfxMessageBox( pop3.GetLastError() );
		return;
	}
	UpdateData(FALSE);
}
