// CPUInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CPUInfo.h"
#include "CPUInfoDlg.h"

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
// CCPUInfoDlg dialog

CCPUInfoDlg::CCPUInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCPUInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCPUInfoDlg)
	m_strProcessorType = _T("");
	m_strProcessorNum = _T("");
	m_strCPUSpeed = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCPUInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCPUInfoDlg)
	DDX_Text(pDX, IDC_EDIT1, m_strProcessorType);
	DDX_Text(pDX, IDC_EDIT2, m_strProcessorNum);
	DDX_Text(pDX, IDC_EDIT5, m_strCPUSpeed);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCPUInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CCPUInfoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_GETCPUINFO, OnGetcpuinfo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCPUInfoDlg message handlers

BOOL CCPUInfoDlg::OnInitDialog()
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

void CCPUInfoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCPUInfoDlg::OnPaint() 
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
HCURSOR CCPUInfoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCPUInfoDlg::OnGetcpuinfo() 
{
	// TODO: Add your control notification handler code here
	SYSTEM_INFO sysInfo;		//获取硬件信息
	GetSystemInfo (&sysInfo);	//检查处理器的类型
	if (sysInfo.dwProcessorType==PROCESSOR_INTEL_386)
	{
		m_strProcessorType =_T("Intel 386");
	}
	else if (sysInfo.dwProcessorType==PROCESSOR_INTEL_486)
	{
		m_strProcessorType = _T("Intel 486");
	}
	else if	(sysInfo.dwProcessorType==PROCESSOR_INTEL_PENTIUM) 
	{
		m_strProcessorType =_T("Intel Pentium");
	}
	else 
	{
		m_strProcessorType = _T("Unknown");
	}
	//检查处理器的个数
	CString str;
	str.Format("%d",sysInfo.dwNumberOfProcessors);
	m_strProcessorNum = str;
	LONG result;
	HKEY hKey;
	DWORD data;
	DWORD dataSize;
	//打开注册表
	result = ::RegOpenKeyEx (HKEY_LOCAL_MACHINE,
		"Hardware\\Description\\System\\CentralProcessor\\0", 0, KEY_QUERY_VALUE, &hKey);
	// 获取CPU的处理速度
	if (result==ERROR_SUCCESS) 
	{
		result = ::RegQueryValueEx (hKey, _T("~MHz"), NULL, NULL,(LPBYTE)&data, &dataSize);
		m_strCPUSpeed.Format ("%d", data);
		m_strCPUSpeed += _T (" MHz");
	}
	RegCloseKey (hKey);//关闭注册表
	UpdateData(FALSE);
}
