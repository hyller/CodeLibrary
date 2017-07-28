// HideTaskBarDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HideTaskBar.h"
#include "HideTaskBarDlg.h"

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
// CHideTaskBarDlg dialog

CHideTaskBarDlg::CHideTaskBarDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHideTaskBarDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHideTaskBarDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	Flag=false;
}

void CHideTaskBarDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHideTaskBarDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CHideTaskBarDlg, CDialog)
	//{{AFX_MSG_MAP(CHideTaskBarDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_HIDESHOW, OnHideshow)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHideTaskBarDlg message handlers

BOOL CHideTaskBarDlg::OnInitDialog()
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

void CHideTaskBarDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CHideTaskBarDlg::OnPaint() 
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
HCURSOR CHideTaskBarDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CHideTaskBarDlg::OnHideshow() 
{
	// TODO: Add your control notification handler code here
	if(Flag)
	{
		GetDlgItem(IDC_HIDESHOW)->SetWindowText("隐藏系统任务条");
	}
	else
	{
		GetDlgItem(IDC_HIDESHOW)->SetWindowText("显示系统任务条");
	}
	Flag=!Flag;
	//定义系统工作区并初始化
	CRect rectWorkArea = CRect(0,0,0,0);
	//定义系统任务条并初始化
	CRect rectTaskBar = CRect(0,0,0,0);
	CWnd* pWnd = CWnd::FindWindow("Shell_TrayWnd", "");	
	// 隐藏系统任务条
	if(Flag)
	{
		//得到系统工作区（不包括系统任务条）
		SystemParametersInfo(SPI_GETWORKAREA,0,(LPVOID)&rectWorkArea,0);
		if( pWnd )
		{	
			pWnd->ShowWindow(SW_HIDE);//在整个工作区中隐藏系统任务条
			pWnd->GetWindowRect(rectTaskBar);//得到系统任务条区域
			//将系统任务条的区域添加到工作区
			rectWorkArea.bottom+= (rectTaskBar.Height()-2);
			SystemParametersInfo(SPI_SETWORKAREA,0,(LPVOID)&rectWorkArea,0);		
		}
	}
	// 显示系统任务条
	else
	{
		//得到系统工作区（不包括系统任务条）
		SystemParametersInfo(SPI_GETWORKAREA,0,(LPVOID)&rectWorkArea,0);
		if( pWnd )
		{
			pWnd->GetWindowRect(rectTaskBar);//得到系统任务条区域	
			rectWorkArea.bottom -= (rectTaskBar.Height()-2);//将系统任务条从工作区中去除
			SystemParametersInfo(SPI_SETWORKAREA,0,(LPVOID)&rectWorkArea,0);
			//显示系统任务条
			pWnd->ShowWindow(SW_SHOW);
		}
	}
}
