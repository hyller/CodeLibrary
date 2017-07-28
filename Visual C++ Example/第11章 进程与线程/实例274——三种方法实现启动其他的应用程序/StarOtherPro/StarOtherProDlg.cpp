// StarOtherProDlg.cpp : implementation file
//

#include "stdafx.h"
#include "StarOtherPro.h"
#include "StarOtherProDlg.h"

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
// CStarOtherProDlg dialog

CStarOtherProDlg::CStarOtherProDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStarOtherProDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStarOtherProDlg)
	m_radio = -1;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStarOtherProDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStarOtherProDlg)
	DDX_Radio(pDX, IDC_RADIO1, m_radio);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CStarOtherProDlg, CDialog)
	//{{AFX_MSG_MAP(CStarOtherProDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_STAR, OnStar)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStarOtherProDlg message handlers

BOOL CStarOtherProDlg::OnInitDialog()
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

void CStarOtherProDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CStarOtherProDlg::OnPaint() 
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
HCURSOR CStarOtherProDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CStarOtherProDlg::OnStar() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	TCHAR szDir[_MAX_PATH];
	GetWindowsDirectory (szDir, _MAX_PATH);//获取Windows目录
	CString strProgPath, strProgParms;
	strProgPath.Format ("%s\\NotePad.exe", szDir);//记事本应用程序的路径
	GetCurrentDirectory (_MAX_PATH, szDir);
	strProgParms.Format ("notepad %s\\readme.txt", szDir);//当前工程的"readme.txt"文件路径
	switch (m_radio)
	{
	case 0://使用WinExec打开记事本文件"readme.txt"
		WinExec(strProgParms,SW_NORMAL);
		break;
	case 1://使用ShellExecute打开记事本文件"readme.txt"
		ShellExecute(NULL, NULL, _T("readme.txt"), NULL,szDir,SW_SHOWNORMAL);
		break;
	case 2://使用CreateProcess打开记事本文件"readme.txt"
		PROCESS_INFORMATION pi;
		STARTUPINFO si;
		//初始化变量
		memset(&si,0,sizeof(si));
		si.cb=sizeof(si);
		si.wShowWindow=SW_SHOW;
		si.dwFlags=STARTF_USESHOWWINDOW;
		CreateProcess((LPCTSTR) strProgPath,
				(char *)(LPCSTR) strProgParms, 
				(LPSECURITY_ATTRIBUTES) NULL,
				(LPSECURITY_ATTRIBUTES) NULL,
				false,
				DETACHED_PROCESS,
				(LPVOID) NULL,
				szDir,
				(LPSTARTUPINFO) &si,
				(LPPROCESS_INFORMATION) &pi);
		break;
	}
}
