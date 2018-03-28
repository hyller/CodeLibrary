// MergFileDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MergFileDemo.h"
#include "MergFileDemoDlg.h"

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
// CMergFileDemoDlg dialog

CMergFileDemoDlg::CMergFileDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMergFileDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMergFileDemoDlg)
	m_strpath = _T("");
	m_strfile = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMergFileDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMergFileDemoDlg)
	DDX_Text(pDX, IDC_EDIT2, m_strpath);
	DDX_Text(pDX, IDC_EDIT1, m_strfile);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMergFileDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CMergFileDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_FILE, OnFile)
	ON_BN_CLICKED(IDC_MERG, OnMerg)
	ON_BN_CLICKED(IDC_PATH, OnPath)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMergFileDemoDlg message handlers

BOOL CMergFileDemoDlg::OnInitDialog()
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

void CMergFileDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMergFileDemoDlg::OnPaint() 
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
HCURSOR CMergFileDemoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMergFileDemoDlg::OnFile() 
{
	// TODO: Add your control notification handler code here
	CString strFilter;
	strFilter="All Files (s1_*.*)|s1_*.*||";	
	CFileDialog dlg(TRUE, NULL, NULL, OFN_EXPLORER|OFN_HIDEREADONLY|OFN_ENABLESIZING|OFN_FILEMUSTEXIST,strFilter);
	if(dlg.DoModal() == IDOK )								//显示打开文件对话框
	{
		m_strfile=dlg.GetPathName();
		UpdateData(false);
	}
	
}

void CMergFileDemoDlg::OnMerg() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CFile m_SourceFile,m_destFile;
	if(!m_strfile.IsEmpty())//文件名编辑框不为空
	{
		//打开文件
		if (!m_SourceFile.Open(m_strfile, CFile::modeRead|CFile::shareDenyNone|CFile::typeBinary)) 
		{
			return;
		}	
		m_SourceFile.Close();
	}
	else
	{	
		AfxMessageBox("请选择要合并的文件！");
		return;
	}
	if(m_strpath.IsEmpty())
	{
		AfxMessageBox("请选择一个用来存放合并后文件的目录");
		return;
	}
	CString m_filename = m_strfile.Right((m_strfile.GetLength() - m_strfile.ReverseFind('\\')) - 1);
	if(m_filename.Left(3) != _T("s1_"))
	{
		AfxMessageBox("合并的文件格式不正确！");
		return;
	}
	m_filename = m_filename.Right(m_filename.GetLength() - 3);
	m_strpath = m_strpath + _T("\\") + m_filename;
	//创建合并后的文件
	if (!m_destFile.Open(m_strpath, CFile::modeWrite|CFile::shareExclusive|CFile::typeBinary|CFile::modeCreate)) 
	{
		return;
	}
	int i = 1;
	BYTE buffer[1000000];
	UINT nCount = 1000000;
	CString name;
	//获取要合并的小文件的路径
	CString m_emergfilepath = m_strfile.Left(m_strfile.ReverseFind('\\')+1);
	DWORD dwRead;
	do {
		//自动定位分割文件名前的数字信息
		name.Format("s%d_",i);
		//打开源文件
		if (!m_SourceFile.Open(m_emergfilepath+name+m_filename,  
			CFile::modeRead|CFile::shareExclusive|CFile::typeBinary))
		{
			return;
		}
		dwRead = m_SourceFile.Read(buffer, nCount);//从源文件读数据
		m_destFile.Write(buffer, dwRead);//写入合并后的文件
		i++;
		m_SourceFile.Close();
	}
	while (dwRead > 0);
	CString str="文件合并完成！";
	AfxMessageBox(str);
	m_destFile.Close();
	
}

void CMergFileDemoDlg::OnPath() 
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
