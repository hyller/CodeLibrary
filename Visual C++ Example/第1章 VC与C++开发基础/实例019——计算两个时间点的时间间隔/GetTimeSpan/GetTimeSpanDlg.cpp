// GetTimeSpanDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GetTimeSpan.h"
#include "GetTimeSpanDlg.h"

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
// CGetTimeSpanDlg dialog

CGetTimeSpanDlg::CGetTimeSpanDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGetTimeSpanDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGetTimeSpanDlg)
	m_strTime = _T("");
	m_Days = 0;
	m_Hours = 0;
	m_Minutes = 0;
	m_Seconds = 0;
	m_TotalMinutes = 0;
	m_TotalHours = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGetTimeSpanDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGetTimeSpanDlg)
	DDX_Text(pDX, IDC_EDIT1, m_strTime);
	DDX_Text(pDX, IDC_EDIT4, m_Days);
	DDX_Text(pDX, IDC_EDIT5, m_Hours);
	DDX_Text(pDX, IDC_EDIT6, m_Minutes);
	DDX_Text(pDX, IDC_EDIT7, m_Seconds);
	DDX_Text(pDX, IDC_EDIT11, m_TotalMinutes);
	DDX_Text(pDX, IDC_EDIT10, m_TotalHours);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CGetTimeSpanDlg, CDialog)
	//{{AFX_MSG_MAP(CGetTimeSpanDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGetTimeSpanDlg message handlers

BOOL CGetTimeSpanDlg::OnInitDialog()
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
	SetTimer(1,1000,NULL);								//设置定时器，每秒触发一次
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGetTimeSpanDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CGetTimeSpanDlg::OnPaint() 
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
HCURSOR CGetTimeSpanDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CGetTimeSpanDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CTime m_time1=CTime::GetCurrentTime();							//获取当前时间
	m_strTime=m_time1.Format("%Y年%m月%d日 %H时%M分%S秒");
	CTime m_time2(2010,1,1,0,0,0);									//2010年元旦
	CTimeSpan m_timespan=m_time2-m_time1;							//获取时间间隔
	m_Days=m_timespan.GetDays();//天数
	m_Hours=m_timespan.GetHours();//小时数
	m_Minutes=m_timespan.GetMinutes();//分钟数
	m_Seconds=m_timespan.GetSeconds();//秒数
	m_TotalHours=m_timespan.GetTotalHours();//合计小时数
	m_TotalMinutes=m_timespan.GetTotalMinutes();//合计分钟数
	UpdateData(false);
	CDialog::OnTimer(nIDEvent);
}
