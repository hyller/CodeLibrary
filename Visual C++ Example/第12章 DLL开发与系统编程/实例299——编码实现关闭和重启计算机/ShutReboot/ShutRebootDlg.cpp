// ShutRebootDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ShutReboot.h"
#include "ShutRebootDlg.h"

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
// CShutRebootDlg dialog

CShutRebootDlg::CShutRebootDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CShutRebootDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CShutRebootDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CShutRebootDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CShutRebootDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CShutRebootDlg, CDialog)
	//{{AFX_MSG_MAP(CShutRebootDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SHUTDOWN, OnShutdown)
	ON_BN_CLICKED(IDC_REBOOT, OnReboot)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShutRebootDlg message handlers

BOOL CShutRebootDlg::OnInitDialog()
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

void CShutRebootDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CShutRebootDlg::OnPaint() 
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
HCURSOR CShutRebootDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CShutRebootDlg::OnShutdown() 
{
	// TODO: Add your control notification handler code here
	int nvalue= AfxMessageBox("是否真的要关闭计算机？",4+32+256);
	if(nvalue==IDYES)									//用户按下了"是"按钮
	{
	OSVERSIONINFO osv;
    osv.dwOSVersionInfoSize = sizeof OSVERSIONINFO;
    GetVersionEx(&osv);//获取操作系统的版本
    if(VER_PLATFORM_WIN32_NT == osv.dwPlatformId)
    {
        // 如果运行在NT/XP平台，必须先取得权限
        HANDLE hProcess, hToken;
        TOKEN_PRIVILEGES Privileges;
        LUID luid;
        hProcess=GetCurrentProcess();
        OpenProcessToken(hProcess, TOKEN_ADJUST_PRIVILEGES, &hToken);
        Privileges.PrivilegeCount = 1;
        LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &luid);
        Privileges.Privileges[0].Luid = luid;
        Privileges.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
        AdjustTokenPrivileges(hToken, FALSE, &Privileges, NULL, NULL, NULL);
    }
	ExitWindowsEx(EWX_SHUTDOWN,0);//关闭计算机
	}
}

void CShutRebootDlg::OnReboot() 
{
	// TODO: Add your control notification handler code here
	int nvalue= AfxMessageBox("是否真的要重启计算机？",4+32+256);
	if(nvalue==IDYES)									//用户按下了"是"按钮
	{
	OSVERSIONINFO osv;
    osv.dwOSVersionInfoSize = sizeof OSVERSIONINFO;
    GetVersionEx(&osv);//获取操作系统的版本
    if(VER_PLATFORM_WIN32_NT == osv.dwPlatformId)
    {
        // 如果运行在NT/XP平台，必须先取得权限
        HANDLE hProcess, hToken;
        TOKEN_PRIVILEGES Privileges;
        LUID luid;
        hProcess=GetCurrentProcess();
        OpenProcessToken(hProcess, TOKEN_ADJUST_PRIVILEGES, &hToken);
        Privileges.PrivilegeCount = 1;
        LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &luid);
        Privileges.Privileges[0].Luid = luid;
        Privileges.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
        AdjustTokenPrivileges(hToken, FALSE, &Privileges, NULL, NULL, NULL);
    }
	ExitWindowsEx(EWX_REBOOT,0);//重新启动计算机
	}
	
}
