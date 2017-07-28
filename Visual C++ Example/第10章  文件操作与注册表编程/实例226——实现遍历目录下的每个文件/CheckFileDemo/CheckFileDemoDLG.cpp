// CheckFileDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CheckFileDemo.h"
#include "CheckFileDemoDlg.h"

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
// CCheckFileDemoDlg dialog

CCheckFileDemoDlg::CCheckFileDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCheckFileDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCheckFileDemoDlg)
	m_folder = _T("");
	m_filenum = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCheckFileDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCheckFileDemoDlg)
	DDX_Control(pDX, IDC_LIST1, m_fileList);
	DDX_Text(pDX, IDC_EDIT1, m_folder);
	DDX_Text(pDX, IDC_EDIT2, m_filenum);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCheckFileDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CCheckFileDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SEARCH, OnSearch)
	ON_BN_CLICKED(IDC_FOLDER, OnFolder)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCheckFileDemoDlg message handlers

BOOL CCheckFileDemoDlg::OnInitDialog()
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

void CCheckFileDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCheckFileDemoDlg::OnPaint() 
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
HCURSOR CCheckFileDemoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCheckFileDemoDlg::OnSearch() //遍历当前目录下的文件
{
	// TODO: Add your control notification handler code here
	CString oldDir;//保存原始的当前路径
	UpdateData(true);//获取输入数据
	GetCurrentDirectory(50,(LPTSTR)(LPCTSTR)oldDir);//获取当前路径
	if(!SetCurrentDirectory((LPCTSTR)m_folder)||m_folder.IsEmpty())//如果有输入
	{
		m_folder=(LPCTSTR)oldDir;
		UpdateData(false);
	}
	while(m_fileList.GetCount()!=0)//清空列表框
	{
		int index=m_fileList.GetTopIndex();
		m_fileList.DeleteString(index);
	}
	FindFile(CString(m_folder));//开始查找
	m_filenum=m_fileList.GetCount();//获取文件数目
	UpdateData(false);//编辑框显示
	SetCurrentDirectory((LPCTSTR)oldDir);//恢复当前目录
	
}

void CCheckFileDemoDlg::OnFolder() 
{
	// TODO: Add your control notification handler code here
	CString strFilter;
	strFilter="All Files(*.*)|*.*||";
	CFileDialog dlg(TRUE, NULL, NULL, OFN_EXPLORER|OFN_HIDEREADONLY|
		OFN_ENABLESIZING|OFN_FILEMUSTEXIST,strFilter);
	if(dlg.DoModal() == IDOK )								//显示打开文件对话框
	{
		m_folder=dlg.GetPathName();
		UpdateData(false);
	}	
}

void CCheckFileDemoDlg::FindFile(CString Curdir)
{
	HANDLE hfile;//查找文件句柄
	WIN32_FIND_DATA wfdata;//文件信息结构
	BOOL IsOver=false;//查找过程结束标志
	CString strname;//文件名
	CString strfull;//全路径
	hfile=FindFirstFile((LPCTSTR)("*.*"),&wfdata);//查找第一个文件
	if(hfile==INVALID_HANDLE_VALUE)
		IsOver=true;//查找过程结束
	while(!IsOver)
	{
		strname.Format("%s",wfdata.cFileName);//获取找到的文件名
		strfull=Curdir+"\\"+strname;//全路径
		if((wfdata.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY)&&(wfdata.cFileName[0]!=_TEXT('.')))//
		{
			SetCurrentDirectory(wfdata.cFileName);
			FindFile(strfull);//递归调用
			SetCurrentDirectory("..");//返回当前目录
		}
		else if(wfdata.cFileName[0]!=_TEXT('.'))
			m_fileList.AddString(strfull);
		IsOver=!FindNextFile(hfile,&wfdata);//查找下一个文件
	}
	FindClose(hfile);//关闭句柄
}
