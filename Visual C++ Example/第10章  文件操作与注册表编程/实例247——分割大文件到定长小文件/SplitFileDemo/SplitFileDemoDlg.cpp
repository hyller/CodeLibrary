// SplitFileDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SplitFileDemo.h"
#include "SplitFileDemoDlg.h"

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
// CSplitFileDemoDlg dialog

CSplitFileDemoDlg::CSplitFileDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSplitFileDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSplitFileDemoDlg)
	m_strfile = _T("");
	m_strpath = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSplitFileDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSplitFileDemoDlg)
	DDX_Text(pDX, IDC_EDIT1, m_strfile);
	DDX_Text(pDX, IDC_EDIT2, m_strpath);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSplitFileDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CSplitFileDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_GETFILE, OnGetfile)
	ON_BN_CLICKED(IDC_GETPATH, OnGetpath)
	ON_BN_CLICKED(IDC_SPLIT, OnSplit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSplitFileDemoDlg message handlers

BOOL CSplitFileDemoDlg::OnInitDialog()
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

void CSplitFileDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSplitFileDemoDlg::OnPaint() 
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
HCURSOR CSplitFileDemoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSplitFileDemoDlg::OnGetfile() 
{
	// TODO: Add your control notification handler code here
	CString strFilter;
	strFilter="All Files (*.*)|*.*||";	
	CFileDialog dlg(TRUE, NULL, NULL, OFN_EXPLORER|OFN_HIDEREADONLY|OFN_ENABLESIZING|OFN_FILEMUSTEXIST,strFilter);
	if(dlg.DoModal() == IDOK )								//显示打开文件对话框
	{
		m_strfile=dlg.GetPathName();
		UpdateData(false);
	}

	
}

void CSplitFileDemoDlg::OnGetpath() 
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
            m_strpath = szBuffer;
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

void CSplitFileDemoDlg::OnSplit() 
{
	// TODO: Add your control notification handler code here
	CFile m_SourceFile,destFile;
	int len;
	if(!m_strfile.IsEmpty())//文件名编辑框不为空
	{
		//打开文件
		if (!m_SourceFile.Open(m_strfile, CFile::modeRead|CFile::shareDenyNone|CFile::typeBinary)) 
		{
			return;
		}
		len=m_SourceFile.GetLength();//获取文件的长度
	}
	else
	{	
		AfxMessageBox("请选择一个要分割的文件！");
		return;
	}
	if(m_strpath.IsEmpty())
	{
		AfxMessageBox("请选择一个用来存放分割后文件的目录");
		return;
	}
	DWORD dwRead;
	int nCount = 1000000;//分割文件的大小为1M
	BYTE buffer[1000000];
	int i=1;
	CString name;
	if(len<=nCount)
	{
		AfxMessageBox("文件大小小于1M，不用分割！");
		return;
	}
	//分割文件
	do {
			dwRead = m_SourceFile.Read(buffer, nCount);
			if(dwRead!=0)
			//动态建立一个新建文件名的前的数字
			{	
				name.Format("s%d_",i);
				CString newpath; 
				//判断选择目录未尾是否已有"\"符
				if(m_strpath.Right(1)=='\\')
					newpath = m_strpath;
				else
				newpath = m_strpath + _T("\\");
				//创建分割文件
				if (!destFile.Open(newpath+name+m_SourceFile.GetFileName(),  
				CFile::modeWrite|CFile::shareExclusive| CFile::typeBinary|CFile::modeCreate)) 
				{
			
					m_SourceFile.Close();
					return;
				}
				destFile.Write(buffer, dwRead);//写入源文件数据到分割文件
				destFile.Close();//关闭分割文件
				i++;
				}
			}
	while (dwRead>0); 
	CString str;
	str.Format("分割完成，共分割为%d个文件",i);
	AfxMessageBox(str);
	m_SourceFile.Close();
}
