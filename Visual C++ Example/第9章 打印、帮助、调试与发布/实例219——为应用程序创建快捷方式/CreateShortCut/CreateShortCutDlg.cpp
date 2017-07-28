// CreateShortCutDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CreateShortCut.h"
#include "CreateShortCutDlg.h"

#include "LinkNameDlg.h"

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
// CCreateShortCutDlg dialog

CCreateShortCutDlg::CCreateShortCutDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCreateShortCutDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCreateShortCutDlg)
	m_radio = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCreateShortCutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCreateShortCutDlg)
	DDX_Radio(pDX, IDC_RADIO1, m_radio);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCreateShortCutDlg, CDialog)
	//{{AFX_MSG_MAP(CCreateShortCutDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CREATE, OnCreate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCreateShortCutDlg message handlers

BOOL CCreateShortCutDlg::OnInitDialog()
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
	CoInitialize (NULL);//初始化Com
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCreateShortCutDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCreateShortCutDlg::OnPaint() 
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
HCURSOR CCreateShortCutDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//浏览文件夹
BOOL CCreateShortCutDlg::BrowseForFolder(LPITEMIDLIST pidlRoot,LPITEMIDLIST *ppidlDestination,LPCSTR lpszTitle)
{    
	BROWSEINFO BrInfo ;//定义结构体
    ZeroMemory( &BrInfo, sizeof(BrInfo)) ;
    BrInfo.hwndOwner = HWND_DESKTOP ;
    BrInfo.pidlRoot = pidlRoot ;
    BrInfo.lpszTitle = lpszTitle ;
    *ppidlDestination= SHBrowseForFolder(&BrInfo); //浏览文件夹
    if(NULL == *ppidlDestination)//用户选择了取消按钮
        return FALSE ;
    return TRUE ;
}

BOOL CCreateShortCutDlg::GetShortcutCrt(LPSTR szPath)//取得要创建的快捷方式的名字
{
    LPITEMIDLIST pidlBeginAt, pidlDestination ;   
    // 取得开始菜单或桌面的PIDL
    SHGetSpecialFolderLocation( HWND_DESKTOP, nBeginAt, &pidlBeginAt) ;
    // 取得要创建的快捷方式所在的位置
    if( !BrowseForFolder(pidlBeginAt,&pidlDestination, "请选择快捷方式所在的位置："))
        return FALSE ;
    // 把PIDL转换为路径名
    SHGetPathFromIDList( pidlDestination, szPath) ;
    // 取得快捷方式名称
    CLinkNameDlg name_dlg;
	if(name_dlg.DoModal() == IDCANCEL)    
        return FALSE ;
    //把快捷方式名和扩展名.LNK添加到路径名后，形成完整的快捷方式数据文件名
    wsprintf(szPath+lstrlen(szPath),"\\%s.lnk", name_dlg.m_linkname) ;
    return TRUE ;
}

//创建快捷方式
BOOL CCreateShortCutDlg::CreateLink (LPSTR szPath,LPSTR szLink)
{
	HRESULT hres ;
	IShellLink * psl ;
	IPersistFile* ppf ;
	WORD wsz[ MAX_PATH] ;
    //创建一个IShellLink实例
    hres = CoCreateInstance( CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER, IID_IShellLink,(void **)&psl) ;
	if( FAILED( hres))
        return FALSE ;
    psl -> SetPath( szPath) ;//设置目标应用程序
    //设置快捷键(此处设为Shift+Ctrl+'T')
    psl -> SetHotkey( MAKEWORD( 'T',HOTKEYF_SHIFT |HOTKEYF_CONTROL)) ;
    //从IShellLink获取其IPersistFile接口，用于保存快捷方式的数据文件 (*.lnk)
    hres = psl -> QueryInterface( IID_IPersistFile,(void**)&ppf) ;
	if( FAILED( hres))
        return FALSE ;
	// 确保数据文件名为ANSI格式
	MultiByteToWideChar( CP_ACP, 0, szLink, -1, wsz, MAX_PATH) ;
    //调用IPersistFile::Save，保存快捷方式的数据文件 (*.lnk)
	hres = ppf -> Save( wsz, STGM_READWRITE) ;
    //释放IPersistFile和IShellLink接口
	ppf -> Release( ) ;
	psl -> Release( ) ;
	return TRUE;
}

// 通知shell有关变化
void CCreateShortCutDlg::NotifyShell(LONG wEventId,LPSTR szPath)
{    
    SHChangeNotify( wEventId,SHCNF_FLUSH | SHCNF_PATH,szPath,0);
    //取得szPath的父目录
    char* p;
    for( p=szPath+lstrlen(szPath)-1;*p != '\\'; p--);
    *p='\0';
    SHChangeNotify(SHCNE_UPDATEDIR|SHCNE_INTERRUPT,SHCNF_FLUSH | SHCNF_PATH,szPath,0);
}

//取得快捷方式的目标应用程序名
BOOL CCreateShortCutDlg::SelectMenuItem( LPSTR szFileName)
{
    OPENFILENAME ofn ;
    static CHAR szFilter[] = "Programs\0*.exe\0" ;
    ZeroMemory(&ofn, sizeof( OPENFILENAME)) ;
    ofn.lStructSize = sizeof( OPENFILENAME) ;
    ofn.hwndOwner = HWND_DESKTOP;
    ofn.lpstrFilter = szFilter ;
    ofn.nFilterIndex = 0 ;
    ofn.nMaxFile = MAX_PATH ;
    ofn.lpstrTitle = "请选择目标应用程序:" ;
    ofn.lpstrFile = szFileName ;
    ofn.Flags = OFN_FILEMUSTEXIST |OFN_PATHMUSTEXIST | OFN_EXPLORER ;
    //文件浏览
    if(!GetOpenFileName( &ofn))//选择了取消按钮
        return FALSE ;
    return TRUE ;
}

void CCreateShortCutDlg::OnCreate() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_radio==0)//在桌面创建
	{
		nBeginAt=CSIDL_DESKTOPDIRECTORY ;   //设置起始文件夹为桌面 
	}
	else//在开始菜单创建
	{
		nBeginAt=CSIDL_STARTMENU;//设置起始文件夹为“开始”菜单
	}
	char szPath[MAX_PATH]="";//快捷方式的目标应用程序名
    char szLink[MAX_PATH]="";//快捷方式的数据文件名
    if( !SelectMenuItem( szPath))// 取得快捷方式的目标应用程序名
        return ;
    if( !GetShortcutCrt( szLink))// 取得新建快捷方式所在的文件夹，并形成其数据文件名
        return ;
    if(!CreateLink( szPath, szLink) )// 创建快捷方式
        return;
    NotifyShell( SHCNE_CREATE|SHCNE_INTERRUPT, szLink) ;// 通知shell有关变化
}
