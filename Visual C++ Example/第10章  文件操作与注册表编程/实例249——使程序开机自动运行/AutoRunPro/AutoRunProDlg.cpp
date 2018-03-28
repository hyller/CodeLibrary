// AutoRunProDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AutoRunPro.h"
#include "AutoRunProDlg.h"

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
// CAutoRunProDlg dialog

CAutoRunProDlg::CAutoRunProDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAutoRunProDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAutoRunProDlg)
	m_strExe = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAutoRunProDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAutoRunProDlg)
	DDX_Text(pDX, IDC_EDIT1, m_strExe);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAutoRunProDlg, CDialog)
	//{{AFX_MSG_MAP(CAutoRunProDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SET, OnSet)
	ON_BN_CLICKED(IDC_OPEN, OnOpen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAutoRunProDlg message handlers

BOOL CAutoRunProDlg::OnInitDialog()
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

void CAutoRunProDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAutoRunProDlg::OnPaint() 
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
HCURSOR CAutoRunProDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CAutoRunProDlg::OnSet() 
{
	// TODO: Add your control notification handler code here
	//判断操作系统，若不是Win2000、WinXP或Win2003，则程序退出
	OSVERSIONINFO os;
	os.dwOSVersionInfoSize=sizeof(OSVERSIONINFO);
	GetVersionEx(&os);
	if(os.dwPlatformId!=VER_PLATFORM_WIN32_NT)
	{
		AfxMessageBox("本操作系统不是Win2000、WinXP或Win2003，本程序不适合运行！");
		return;//程序退出
	}
	UpdateData(true);
	if(m_strExe.IsEmpty())
	{
		AfxMessageBox("加载的应用程序为空！");
		return;
	}
	HKEY hKey;
	CString sKeyName;
	unsigned char szFilePath[100];
	//打开注册表
	LONG lnRes = RegOpenKeyEx( 
						
 						HKEY_LOCAL_MACHINE,  //要打开的目录在HKEY_LOCAL_MACHINE下	
						"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", //子目录
						0L,//必须取0
						//KEY_WRITE是STANDARD_RIGHTS_WRITE, KEY_SET_VALUE, 和 KEY_CREATE_SUB_KEY 访问权限的组合
						KEY_WRITE,
						&hKey      
						); 
	lstrcpy( (char *) szFilePath , LPCTSTR(m_strExe) );
	//假如RegOpenKeyEx成功，返回值为ERROR_SUCCESS
	if( ERROR_SUCCESS == lnRes )
	{
		//把应用程序路径加入到RUN键下面
		lnRes = RegSetValueEx(hKey,
				LPCTSTR(sKeyName),   
				0,      
				REG_SZ,    
				szFilePath,   //value data
				REG_SZ ); 
		//假如RegSetValueEx成功，返回值为ERROR_SUCCESS
		if( ERROR_SUCCESS == lnRes )
		{
			AfxMessageBox("已经成功加载此应用程序！");
			RegCloseKey(hKey);											//关闭hKey
		}

		else
			AfxMessageBox("不能加载此应用程序！");
	}
	else
	{
		AfxMessageBox("不能加载此应用程序！");
	}	
	
}

void CAutoRunProDlg::OnOpen() 
{
	// TODO: Add your control notification handler code here
	//只能选择exe文件
	static char szFilter[] = "(*.exe)|*.exe";
	CFileDialog OpenFileDlg(true,"*.tpe",NULL,OFN_HIDEREADONLY ,szFilter);	
	if( OpenFileDlg.DoModal() == IDOK )
	{
		m_strExe=OpenFileDlg.GetPathName();
		UpdateData(false);
	}
}
