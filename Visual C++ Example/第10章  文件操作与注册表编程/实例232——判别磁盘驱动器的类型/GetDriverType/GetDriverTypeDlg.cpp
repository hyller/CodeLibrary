// GetDriverTypeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GetDriverType.h"
#include "GetDriverTypeDlg.h"

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
// CGetDriverTypeDlg dialog

CGetDriverTypeDlg::CGetDriverTypeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGetDriverTypeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGetDriverTypeDlg)
	m_DriverType = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGetDriverTypeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGetDriverTypeDlg)
	DDX_Control(pDX, IDC_COMBO1, m_ctlDriver);
	DDX_Text(pDX, IDC_EDIT1, m_DriverType);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CGetDriverTypeDlg, CDialog)
	//{{AFX_MSG_MAP(CGetDriverTypeDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGetDriverTypeDlg message handlers

BOOL CGetDriverTypeDlg::OnInitDialog()
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
	DWORD dwNum;//实际存储驱动器号的字符串长度
	HANDLE hHeap;
	LPSTR lp;
	CString strLogdrive;

	//获得实际存储驱动器号的字符串长度
	dwNum=GetLogicalDriveStrings(0,NULL)*sizeof(TCHAR);
	//如果字符串不为空，则表示有驱动器存在
	if (dwNum!=0) 
	{
		//分配字符串空间
		hHeap=GetProcessHeap();
		lp=(LPSTR)HeapAlloc(hHeap,HEAP_ZERO_MEMORY,dwNum);
		//获得标明所有驱动器的字符串
		GetLogicalDriveStrings(HeapSize(hHeap,0,lp),lp);
		//将驱动器一个个放到下拉框中
		while (*lp!=0) 
		{
			m_ctlDriver.AddString(lp);
			lp=_tcschr(lp,0)+1;
		}
	}
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGetDriverTypeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CGetDriverTypeDlg::OnPaint() 
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
HCURSOR CGetDriverTypeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CGetDriverTypeDlg::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	//获得当前选择的驱动器
	CString strRootPathName;
	int nselect=m_ctlDriver.GetCurSel();				//获取当前组合框选项的索引
	m_ctlDriver.GetLBText(nselect,strRootPathName);			//静态文本显示当前组合框选项的标题
	//获得驱动器类型
	UINT DrvType = GetDriveType(strRootPathName);
	switch(DrvType)
	{
	case DRIVE_CDROM:
		m_DriverType = "光驱";
		break;
	case DRIVE_FIXED:
		m_DriverType = "硬盘";
		break;
	case DRIVE_REMOVABLE:
		m_DriverType = "软驱";
		break;
	default:
		return;
		break;
	}
	UpdateData(false);
}
