// FullScreenDlgDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FullScreenDlgDemo.h"
#include "FullScreenDlgDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

void GoFullScreen(HWND hwnd,BOOL bFullScreen, RECT *sizerect); 


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
// CFullScreenDlgDemoDlg dialog

CFullScreenDlgDemoDlg::CFullScreenDlgDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFullScreenDlgDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFullScreenDlgDemoDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_bFullScreen = FALSE;
}

void CFullScreenDlgDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFullScreenDlgDemoDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFullScreenDlgDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CFullScreenDlgDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_GOTOFULLSCREEN, OnGotofullscreen)
	ON_BN_CLICKED(ID_EXIT, OnExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFullScreenDlgDemoDlg message handlers

BOOL CFullScreenDlgDemoDlg::OnInitDialog()
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

void CFullScreenDlgDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFullScreenDlgDemoDlg::OnPaint() 
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
HCURSOR CFullScreenDlgDemoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


void CFullScreenDlgDemoDlg::GoFullScreen(HWND hwnd,BOOL bFullScreen, RECT *sizerect) 
{ 
	int cx, cy; 
	HDC DC = ::GetDC(0); 
	cx = GetDeviceCaps(DC,HORZRES)+GetSystemMetrics(SM_CXBORDER)+1; //
	cy = GetDeviceCaps(DC,VERTRES)+GetSystemMetrics(SM_CYBORDER)+1; 
	::ReleaseDC(0,DC); 
	
	if (bFullScreen) 
	{ 
		::GetWindowRect(hwnd, sizerect); //存储原来的窗口位置
		// 设置窗口样式，无标题栏和框架 
		SetWindowLong(hwnd, GWL_STYLE, 
			GetWindowLong(hwnd, GWL_STYLE) & (~WS_CAPTION | WS_BORDER)); 
		// 全屏显示 
		::	SetWindowPos(hwnd, HWND_TOPMOST, -GetSystemMetrics(SM_CXBORDER)-1, 
			-GetSystemMetrics(SM_CYBORDER)-1, cx+1,cy+1, SWP_NOZORDER); 
	} 
	else 
	{ 
		
		SetWindowLong(hwnd, GWL_STYLE, 
			GetWindowLong(hwnd, GWL_STYLE) | WS_CAPTION | WS_BORDER); 
		//恢复到原来的窗口大小
		::SetWindowPos( hwnd, HWND_NOTOPMOST, 
			sizerect->left, 
			sizerect->top, 
			sizerect->right-sizerect->left, 
			sizerect->bottom-sizerect->top, 
			SWP_SHOWWINDOW); 
	} 
} 

void CFullScreenDlgDemoDlg::OnGotofullscreen() 
{
	static RECT rect;
	m_bFullScreen = !m_bFullScreen; 
	GoFullScreen(m_hWnd, m_bFullScreen, &rect); //模式切换
	if (m_bFullScreen)//目前是全屏模式
		GetDlgItem(ID_GOTOFULLSCREEN)->SetWindowText("切换到普通模式");
	else//目前是普通模式
		GetDlgItem(ID_GOTOFULLSCREEN)->SetWindowText("切换到全屏模式");	
}

void CFullScreenDlgDemoDlg::OnExit() 
{
	CDialog::OnOK();
}
