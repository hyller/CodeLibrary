// ShowDirectoryDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ShowDirectory.h"
#include "ShowDirectoryDlg.h"

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
// CShowDirectoryDlg dialog

CShowDirectoryDlg::CShowDirectoryDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CShowDirectoryDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CShowDirectoryDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CShowDirectoryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CShowDirectoryDlg)
	DDX_Control(pDX, IDC_TREE1, m_ctlTree);
	DDX_Control(pDX, IDC_LIST1, m_ctlList);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CShowDirectoryDlg, CDialog)
	//{{AFX_MSG_MAP(CShowDirectoryDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TVN_ITEMEXPANDED, IDC_TREE1, OnItemexpandedTree1)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, OnSelchangedTree1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowDirectoryDlg message handlers

BOOL CShowDirectoryDlg::OnInitDialog()
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
	m_ImageList.Create(32,32,ILC_COLOR32,10,30);//创建图像列表
	m_ctlList.SetImageList(&m_ImageList,LVSIL_NORMAL);
	m_ctlList.SetBkColor(RGB(200,200,255));
	DWORD dwStyle = GetWindowLong(m_ctlTree.m_hWnd,GWL_STYLE);
	dwStyle |= TVS_HASBUTTONS | TVS_HASLINES | TVS_LINESATROOT;
	SetWindowLong(m_ctlTree.m_hWnd,GWL_STYLE,dwStyle);//设置树形控件的风格
    m_hRoot = m_ctlTree.InsertItem("我的电脑");//根节点
	GetLogicalDrives(m_hRoot);//获取驱动器作为一级子节点
	GetDriveDir(m_hRoot);//获取驱动器下的文件，作为二级子节点
	m_ctlTree.Expand(m_hRoot,TVE_EXPAND);//只展开一级子节点
	m_ctlTree.SetBkColor(RGB(200,200,255));//设置树形控件的背景色
	m_ctlTree.SetTextColor(RGB(127,0,0));//设置文本颜色

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CShowDirectoryDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CShowDirectoryDlg::OnPaint() 
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
HCURSOR CShowDirectoryDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CShowDirectoryDlg::GetLogicalDrives(HTREEITEM hParent)//获取驱动器作为一级子节点
{
    size_t szAllDriveStrings = GetLogicalDriveStrings(0,NULL);
	char *pDriveStrings = new char[szAllDriveStrings + sizeof(_T(""))];
	GetLogicalDriveStrings(szAllDriveStrings,pDriveStrings);//第一个驱动器
	size_t szDriveString = strlen(pDriveStrings);
	while(szDriveString > 0)//递归搜索驱动器
	{
		m_ctlTree.InsertItem(pDriveStrings,hParent);//向树形控件添加节点
		pDriveStrings += szDriveString + 1;//下一个驱动器
		szDriveString = strlen(pDriveStrings);
	}
}

void CShowDirectoryDlg::GetDriveDir(HTREEITEM hParent)//驱动器下的子目录作为子项
{
    HTREEITEM hChild = m_ctlTree.GetChildItem(hParent);
	while(hChild)//递归搜索各驱动器
	{
        CString strText = m_ctlTree.GetItemText(hChild);
		if(strText.Right(1) != "\\")
			strText += _T("\\");
		strText += "*.*";
		CFileFind file;
	    BOOL bContinue = file.FindFile(strText);
		while(bContinue)//递归搜索驱动器下的文件
		{
            bContinue = file.FindNextFile();
			if(file.IsDirectory() && !file.IsDots())//如果是目录
		        m_ctlTree.InsertItem(file.GetFileName(),hChild);//添加驱动器下的一级子项
		}
		GetDriveDir(hChild);//递归
		hChild = m_ctlTree.GetNextItem(hChild,TVGN_NEXT);
	}	
}


void CShowDirectoryDlg::AddSubItem(HTREEITEM hParent)//添加子项
{
    CString strPath = GetFullPath(hParent);
	if(strPath.Right(1) != "\\")
		strPath += "\\";
	strPath += "*.*";
	CFileFind file;
	BOOL bContinue = file.FindFile(strPath);
	while(bContinue)//递归搜索该目录下的所有文件和目录，并将目录添加到树控件
	{
		bContinue = file.FindNextFile();
		if(file.IsDirectory() && !file.IsDots())//为目录
		    m_ctlTree.InsertItem(file.GetFileName(),hParent);
	}
}
//函数功能:获取树项目全跟路径
CString CShowDirectoryDlg::GetFullPath(HTREEITEM hCurrent)
{
    CString strTemp;
	CString strReturn = "";
	while(hCurrent != m_hRoot)//循环递归，直至找到根目录
	{
		strTemp = m_ctlTree.GetItemText(hCurrent);
		if(strTemp.Right(1) != "\\")
			strTemp += "\\";
		strReturn = strTemp  + strReturn;
		hCurrent = m_ctlTree.GetParentItem(hCurrent);//获取父节点
	}
	return strReturn;
}

void CShowDirectoryDlg::OnItemexpandedTree1(NMHDR* pNMHDR, LRESULT* pResult) //展开子项函数
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;

	// TODO: Add your control notification handler code here
	TVITEM item = pNMTreeView->itemNew;
	if(item.hItem == m_hRoot)//如果是根节点则返回
		return;
    HTREEITEM hChild = m_ctlTree.GetChildItem(item.hItem);
	while(hChild)
	{
		AddSubItem(hChild);//搜索子目录，添加子项
		hChild = m_ctlTree.GetNextItem(hChild,TVGN_NEXT);//获取下一个子项
	}
	
	*pResult = 0;
}

void CShowDirectoryDlg::OnSelchangedTree1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	m_ctlList.DeleteAllItems();//清空列表控件
	TVITEM item = pNMTreeView->itemNew;
	if(item.hItem == m_hRoot)//如果是根目录，返回
		return;
	CString str = GetFullPath(item.hItem);//获取子项的全目录
    if(str.Right(1) != "\\")
	   str += "\\";
	str += "*.*";
	CFileFind file;
	BOOL bContinue = file.FindFile(str);
	while(bContinue)//递归搜索
	{
		bContinue = file.FindNextFile();
		if(!file.IsDirectory() && !file.IsDots())//如果是文件，在列表框显示
		{
		    SHFILEINFO info;
			CString temp = str;
			int index = temp.Find("*.*");
			temp.Delete(index,3);
		    SHGetFileInfo(temp + file.GetFileName(),0,&info,sizeof(&info),SHGFI_DISPLAYNAME | SHGFI_ICON);//获取文件信息
		    int i = m_ImageList.Add(info.hIcon);//文件图标
		    m_ctlList.InsertItem(i,info.szDisplayName,i);//添加到列表框
		}
	}
	
	*pResult = 0;
}
