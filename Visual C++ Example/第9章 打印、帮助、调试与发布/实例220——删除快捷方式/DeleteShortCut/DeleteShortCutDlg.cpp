// DeleteShortCutDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DeleteShortCut.h"
#include "DeleteShortCutDlg.h"


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
// CDeleteShortCutDlg dialog

CDeleteShortCutDlg::CDeleteShortCutDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDeleteShortCutDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDeleteShortCutDlg)
	m_radio = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDeleteShortCutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDeleteShortCutDlg)
	DDX_Radio(pDX, IDC_RADIO1, m_radio);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDeleteShortCutDlg, CDialog)
	//{{AFX_MSG_MAP(CDeleteShortCutDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDeleteShortCutDlg message handlers

BOOL CDeleteShortCutDlg::OnInitDialog()
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

void CDeleteShortCutDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDeleteShortCutDlg::OnPaint() 
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
HCURSOR CDeleteShortCutDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


// 通知shell有关变化
void CDeleteShortCutDlg::NotifyShell(LONG wEventId,LPSTR szPath)
{    
    SHChangeNotify( wEventId,SHCNF_FLUSH | SHCNF_PATH,szPath,0);
    //取得szPath的父目录
    char* p;
    for( p=szPath+lstrlen(szPath)-1;*p != '\\'; p--);
    *p='\0';
    SHChangeNotify(SHCNE_UPDATEDIR|SHCNE_INTERRUPT,SHCNF_FLUSH | SHCNF_PATH,szPath,0);
}

void CDeleteShortCutDlg::OnDelete() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_radio==0)
	{	
		nBeginAt=CSIDL_DESKTOPDIRECTORY ;//设置起始文件夹为桌面    
	}
	else
	{
		nBeginAt=CSIDL_STARTMENU;//设置起始文件夹为“开始”菜单
	}
	LPITEMIDLIST pidlBeginAt ;
    char szShortcut[ MAX_PATH]="",
        szPath[ MAX_PATH]="";
    // 取得开始菜单或桌面的PIDL
    SHGetSpecialFolderLocation( HWND_DESKTOP, nBeginAt, &pidlBeginAt) ;
    // 把PIDL转化为路径名
    SHGetPathFromIDList( pidlBeginAt, szPath) ;
    // 取得要删除的快捷方式
    if( !GetShortcutDel( szPath, szShortcut))
        return ;
    // 删除快捷方式
    if( !DeleteLink(szShortcut))
        return ;
    // 通知SHELL有关改变
    NotifyShell( SHCNE_DELETE|SHCNE_INTERRUPT, szShortcut) ;
}
//取得要删除的快捷方式
BOOL CDeleteShortCutDlg::GetShortcutDel (LPSTR lpszInitDir,LPSTR lpszShortcut)
{
	//构造浏览对话框
    OPENFILENAME ofn ;
    char szFilter[] = "Shortcuts\0*.lnk\0" ;
    ZeroMemory(&ofn,sizeof( OPENFILENAME));
    ofn.lStructSize = sizeof( OPENFILENAME) ;
    ofn.hwndOwner = HWND_DESKTOP ;
    ofn.lpstrFilter = szFilter ;
    ofn.nFilterIndex = 0 ;
    ofn.nMaxFile = MAX_PATH ;
    ofn.lpstrTitle = "请选择要删除的快捷方式：" ;
    ofn.lpstrFile = lpszShortcut;
    ofn.lpstrInitialDir = lpszInitDir ;
    ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_EXPLORER |OFN_NODEREFERENCELINKS ;
    if(! GetOpenFileName( &ofn))//选择了取消按钮
        return FALSE ;
    return TRUE ;
}
//删除快捷方式的数据文件 (*.lnk)
BOOL CDeleteShortCutDlg::DeleteLink( LPSTR lpszShortcut)
{
    SHFILEOPSTRUCT fos ;
    ZeroMemory( &fos, sizeof(fos)) ;
    fos.hwnd = HWND_DESKTOP ;
    fos.wFunc = FO_DELETE ;
    fos.pFrom = lpszShortcut;
    fos.pTo = NULL ;
    fos.fFlags = FOF_SILENT | FOF_ALLOWUNDO ;
    if( 0 != SHFileOperation( &fos))//删除快捷方式(*.lnk)
        return FALSE ;
    return TRUE ;
}