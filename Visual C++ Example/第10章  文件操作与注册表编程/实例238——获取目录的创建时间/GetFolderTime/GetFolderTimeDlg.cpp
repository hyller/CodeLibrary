// GetFolderTimeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GetFolderTime.h"
#include "GetFolderTimeDlg.h"

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
// CGetFolderTimeDlg dialog

CGetFolderTimeDlg::CGetFolderTimeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGetFolderTimeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGetFolderTimeDlg)
	m_strCreateTime = _T("");
	m_strFolder = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGetFolderTimeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGetFolderTimeDlg)
	DDX_Text(pDX, IDC_STATIC1, m_strCreateTime);
	DDX_Text(pDX, IDC_EDIT1, m_strFolder);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CGetFolderTimeDlg, CDialog)
	//{{AFX_MSG_MAP(CGetFolderTimeDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_FOLDER, OnFolder)
	ON_BN_CLICKED(IDC_GETTIME, OnGettime)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGetFolderTimeDlg message handlers

BOOL CGetFolderTimeDlg::OnInitDialog()
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

void CGetFolderTimeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CGetFolderTimeDlg::OnPaint() 
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
HCURSOR CGetFolderTimeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CGetFolderTimeDlg::OnFolder() 
{
	// TODO: Add your control notification handler code here
		//定义指向IMalloc的指针
    LPMALLOC  pMalloc;  
    if (::SHGetMalloc(&pMalloc) != NOERROR)
        return; // failed to get allocator
    char szDisplayName[_MAX_PATH];
    char szBuffer[_MAX_PATH];
    BROWSEINFO browseInfo;								//构造对话框结构
    browseInfo.hwndOwner = this->m_hWnd;
    browseInfo.pidlRoot = NULL;							//设置根目录为桌面
    browseInfo.pszDisplayName = szDisplayName;
    browseInfo.lpszTitle = "选择删除文件的目录";  				//对话框标题
    browseInfo.ulFlags = BIF_RETURNFSANCESTORS|BIF_RETURNONLYFSDIRS;
    browseInfo.lpfn = NULL;     							//未用
    browseInfo.lParam = 0;      							//未用
    LPITEMIDLIST lpItemIDList;
    if ((lpItemIDList = ::SHBrowseForFolder(&browseInfo))!= NULL)
    {
		//得到目录的路径
        if (::SHGetPathFromIDList(lpItemIDList, szBuffer))
        {
            if (szBuffer[0] == '\0')
            {
                return ;
            }
            m_strFolder = szBuffer;
			UpdateData(false);
        }
        else
        {
			AfxMessageBox("不能得到所选的文件夹！",MB_ICONSTOP|MB_OK);
			return;
        }
        pMalloc->Free(lpItemIDList);
        pMalloc->Release();
    }

	
}

void CGetFolderTimeDlg::OnGettime() 
{
	// TODO: Add your control notification handler code here
	HANDLE hDir;
	hDir=CreateFile(m_strFolder,
					GENERIC_READ,//只读方式打开即可
					FILE_SHARE_READ|FILE_SHARE_DELETE,
					NULL,
					OPEN_EXISTING,//打开现存目录
					FILE_FLAG_BACKUP_SEMANTICS,
					NULL);
	FILETIME lpCreateTime,lpAccessTime,lpWriteTime;
	if(GetFileTime(hDir,&lpCreateTime,&lpAccessTime,&lpWriteTime))
	{
		FILETIME fcreatetime;
		FileTimeToLocalFileTime(&lpCreateTime,&fcreatetime);//转换为本地时间
		SYSTEMTIME screatetime;
		FileTimeToSystemTime(&fcreatetime,&screatetime);//转换为系统时间
		m_strCreateTime.Format("%u/%u/%u  %u:%u:%u",
		screatetime.wYear, screatetime.wMonth, screatetime.wDay,
		screatetime.wHour, screatetime.wMinute, screatetime.wSecond);
		UpdateData(false);//更新显示
	}
	CloseHandle(hDir);//关闭文件句柄
}
