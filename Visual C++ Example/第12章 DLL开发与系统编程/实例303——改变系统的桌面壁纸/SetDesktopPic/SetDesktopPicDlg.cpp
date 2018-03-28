// SetDesktopPicDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SetDesktopPic.h"
#include "SetDesktopPicDlg.h"
#include "shlobj.h"
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
// CSetDesktopPicDlg dialog

CSetDesktopPicDlg::CSetDesktopPicDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetDesktopPicDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetDesktopPicDlg)
	m_strPicFile = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSetDesktopPicDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetDesktopPicDlg)
	DDX_Text(pDX, IDC_EDIT1, m_strPicFile);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSetDesktopPicDlg, CDialog)
	//{{AFX_MSG_MAP(CSetDesktopPicDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SET, OnSet)
	ON_BN_CLICKED(IDC_OPEN, OnOpen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetDesktopPicDlg message handlers

BOOL CSetDesktopPicDlg::OnInitDialog()
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

void CSetDesktopPicDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSetDesktopPicDlg::OnPaint() 
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
HCURSOR CSetDesktopPicDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSetDesktopPicDlg::OnSet() 
{
	// TODO: Add your control notification handler code here
	HRESULT hr;
	IActiveDesktop *pActiveDesktop;
	//Create an instance of the Active Desktop
	hr = CoCreateInstance(CLSID_ActiveDesktop, NULL, CLSCTX_INPROC_SERVER,
                      IID_IActiveDesktop, (void**)&pActiveDesktop);
	if (!SUCCEEDED(hr))
        return ;
	//设置墙纸前先打开活动桌面开关
      COMPONENTSOPT co = {0};
      co.dwSize = sizeof(COMPONENTSOPT);
      co.fEnableComponents = TRUE;
      co.fActiveDesktop = TRUE;
      hr = pActiveDesktop->SetDesktopItemOptions(&co, 0);
      if ( !SUCCEEDED(hr) ) 
        return ;
	  UpdateData(false);
	//做以下宽字符的转换是因为SetWallpaper的参数是用的LPCWSTR
    WCHAR wszPath[MAX_PATH];
    LPTSTR lpStr = m_strPicFile.GetBuffer(m_strPicFile.GetLength());
    MultiByteToWideChar(CP_ACP, 0, lpStr, -1, wszPath, MAX_PATH);
    m_strPicFile.ReleaseBuffer();
    hr = pActiveDesktop->SetWallpaper(wszPath, 0);// 设置墙纸
    if ( !SUCCEEDED(hr) )
        return ;

    //设置墙纸风格
    WALLPAPEROPT wp = {0};
    wp.dwSize = sizeof(WALLPAPEROPT);
    wp.dwStyle |= WPSTYLE_CENTER;//居中显示
    hr = pActiveDesktop->SetWallpaperOptions(&wp, 0);
    if ( !SUCCEEDED(hr) )
        return;  
    hr = pActiveDesktop->ApplyChanges(AD_APPLY_ALL);// 应用改变
    if ( !SUCCEEDED(hr) )
        return;
    // 最后释放接口
    pActiveDesktop->Release(); 
   
}


void CSetDesktopPicDlg::OnOpen() 
{
	// TODO: Add your control notification handler code here
	CString strFilter,fileName;
	strFilter="Pic Files(*.jpg)|*.jpg||";	
	CFileDialog dlg(TRUE, NULL, NULL, OFN_EXPLORER|OFN_HIDEREADONLY|OFN_ENABLESIZING|OFN_FILEMUSTEXIST,strFilter);
	if(dlg.DoModal() == IDOK )								//显示打开文件对话框
	{
		m_strPicFile=dlg.GetPathName();
		UpdateData(false);
	}

	
}
