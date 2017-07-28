// MessageBoxDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MessageBoxDemo.h"
#include "MessageBoxDemoDlg.h"

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
// CMessageBoxDemoDlg dialog

CMessageBoxDemoDlg::CMessageBoxDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMessageBoxDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMessageBoxDemoDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMessageBoxDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMessageBoxDemoDlg)
	DDX_Control(pDX, IDC_STATIC1, m_ctlStatic);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMessageBoxDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CMessageBoxDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_QUIT, OnQuit)
	ON_BN_CLICKED(IDC_MSG, OnMsg)
	ON_BN_CLICKED(IDC_ERROR, OnError)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMessageBoxDemoDlg message handlers

BOOL CMessageBoxDemoDlg::OnInitDialog()
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

void CMessageBoxDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMessageBoxDemoDlg::OnPaint() 
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
HCURSOR CMessageBoxDemoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMessageBoxDemoDlg::OnQuit() //退出
{
	// TODO: Add your control notification handler code here
	int nvalue= MessageBox("是否真的要退出程序？","退出",4+32+256);
	if(nvalue==IDYES)//用户按下了"是"按钮
	{
		m_ctlStatic.SetWindowText("用户选择了退出程序");
	}
	else
	{
		m_ctlStatic.SetWindowText("用户取消了退出程序");
	}

}
void CMessageBoxDemoDlg::OnMsg() //提示
{
	// TODO: Add your control notification handler code here
	MessageBox("简单的消息提示框","提示",MB_ICONINFORMATION);
	m_ctlStatic.SetWindowText("信息提示");
}


void CMessageBoxDemoDlg::OnError() //错误
{
	// TODO: Add your control notification handler code here
	int nvalue=MessageBox("程序运行出现错误！","错误",MB_ABORTRETRYIGNORE|MB_ICONERROR);
	if(nvalue==IDABORT)//用户按下了"终止"按钮
	{
		m_ctlStatic.SetWindowText("用户选择了终止程序");
	}
	else if(nvalue==IDRETRY)//用户按下了"终止"按钮
	{
		m_ctlStatic.SetWindowText("用户选择了重试程序");
	}
	else//用户按下了"忽略"按钮
	{
		m_ctlStatic.SetWindowText("用户选择了忽略程序");
	}
	
}
