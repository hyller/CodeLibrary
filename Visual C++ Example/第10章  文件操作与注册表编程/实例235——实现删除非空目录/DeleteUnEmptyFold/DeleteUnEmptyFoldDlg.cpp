// DeleteUnEmptyFoldDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DeleteUnEmptyFold.h"
#include "DeleteUnEmptyFoldDlg.h"

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
// CDeleteUnEmptyFoldDlg dialog

CDeleteUnEmptyFoldDlg::CDeleteUnEmptyFoldDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDeleteUnEmptyFoldDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDeleteUnEmptyFoldDlg)
	m_strFold = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDeleteUnEmptyFoldDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDeleteUnEmptyFoldDlg)
	DDX_Text(pDX, IDC_EDIT1, m_strFold);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDeleteUnEmptyFoldDlg, CDialog)
	//{{AFX_MSG_MAP(CDeleteUnEmptyFoldDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_GETFOLD, OnGetfold)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDeleteUnEmptyFoldDlg message handlers

BOOL CDeleteUnEmptyFoldDlg::OnInitDialog()
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

void CDeleteUnEmptyFoldDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDeleteUnEmptyFoldDlg::OnPaint() 
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
HCURSOR CDeleteUnEmptyFoldDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDeleteUnEmptyFoldDlg::OnGetfold() //弹出目录对话框，选择目录
{
	// TODO: Add your control notification handler code here
	//定义指向IMalloc的指针
    LPMALLOC  pMalloc;  
    if (::SHGetMalloc(&pMalloc) != NOERROR)
        return; // failed to get allocator
    char szDisplayName[_MAX_PATH];
    char szBuffer[_MAX_PATH];
    BROWSEINFO browseInfo;//构造对话框结构
    browseInfo.hwndOwner = this->m_hWnd;
    browseInfo.pidlRoot = NULL;// 设置根目录为桌面
    browseInfo.pszDisplayName = szDisplayName;
    browseInfo.lpszTitle = "选择删除的目录";  //对话框标题
    browseInfo.ulFlags = BIF_RETURNFSANCESTORS|BIF_RETURNONLYFSDIRS;
    browseInfo.lpfn = NULL;      // 未用
    browseInfo.lParam = 0;      // 未用
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
            m_strFold = szBuffer;
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

void CDeleteUnEmptyFoldDlg::OnDelete() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	RecursiveDelete(m_strFold);	
		//最终目录被清空了，于是删除该目录
	if(RemoveDirectory((LPCTSTR)m_strFold))
	{
		AfxMessageBox("删除成功！");
	}
}

void CDeleteUnEmptyFoldDlg::RecursiveDelete(CString szPath)
{
	CFileFind filefind;
	CString path = szPath;	
	if(path.Right(1) != "\\")//目录的最右边需要“\”字符
		path += "\\";
	path += "*.*";
	BOOL res = filefind.FindFile(path);
	while(res)
	{
		res = filefind.FindNextFile();
		//是文件时直接删除
		if (!filefind.IsDots() && !filefind.IsDirectory())
			DeleteFile(filefind.GetFilePath());//删除文件
		else if (filefind.IsDots())
			continue;
		else if (filefind.IsDirectory())//为目录
		{
			path = filefind.GetFilePath();
			//是目录时继续递归，删除该目录下的文件
			RecursiveDelete(path);
			//目录为空后删除目录
			RemoveDirectory((LPCTSTR)path);
		}
	}
}