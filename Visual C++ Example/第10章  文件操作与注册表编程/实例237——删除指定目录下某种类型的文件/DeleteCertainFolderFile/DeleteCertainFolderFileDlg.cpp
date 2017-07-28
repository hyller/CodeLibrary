// DeleteCertainFolderFileDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DeleteCertainFolderFile.h"
#include "DeleteCertainFolderFileDlg.h"

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
// CDeleteCertainFolderFileDlg dialog

CDeleteCertainFolderFileDlg::CDeleteCertainFolderFileDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDeleteCertainFolderFileDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDeleteCertainFolderFileDlg)
	m_strFolder = _T("");
	m_radio = -1;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDeleteCertainFolderFileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDeleteCertainFolderFileDlg)
	DDX_Text(pDX, IDC_EDIT1, m_strFolder);
	DDX_Radio(pDX, IDC_RADIO1, m_radio);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDeleteCertainFolderFileDlg, CDialog)
	//{{AFX_MSG_MAP(CDeleteCertainFolderFileDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_FOLDER, OnFolder)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_RADIO3, OnRadio3)
	ON_BN_CLICKED(IDC_RADIO4, OnRadio4)
	ON_BN_CLICKED(IDC_RADIO5, OnRadio5)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDeleteCertainFolderFileDlg message handlers

BOOL CDeleteCertainFolderFileDlg::OnInitDialog()
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

void CDeleteCertainFolderFileDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDeleteCertainFolderFileDlg::OnPaint() 
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
HCURSOR CDeleteCertainFolderFileDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDeleteCertainFolderFileDlg::OnFolder() 
{
	// TODO: Add your control notification handler code here
	//定义指向IMalloc的指针
    LPMALLOC  pMalloc;  
    if (::SHGetMalloc(&pMalloc) != NOERROR)
        return; // failed to get allocator
    char szDisplayName[_MAX_PATH];
    char szBuffer[_MAX_PATH];
    BROWSEINFO browseInfo;							//构造对话框结构
    browseInfo.hwndOwner = this->m_hWnd;
    browseInfo.pidlRoot = NULL;						//设置根目录为桌面
    browseInfo.pszDisplayName = szDisplayName;
    browseInfo.lpszTitle = "选择删除文件的目录";  				//对话框标题
    browseInfo.ulFlags = BIF_RETURNFSANCESTORS|BIF_RETURNONLYFSDIRS;
    browseInfo.lpfn = NULL;     						//未用
    browseInfo.lParam = 0;      						//未用
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
	DisplayFileList(m_strFolder);
}

void CDeleteCertainFolderFileDlg::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	
}

void CDeleteCertainFolderFileDlg::OnRadio2() 
{
	// TODO: Add your control notification handler code here
	
}

void CDeleteCertainFolderFileDlg::OnRadio3() 
{
	// TODO: Add your control notification handler code here
	
}

void CDeleteCertainFolderFileDlg::OnRadio4() 
{
	// TODO: Add your control notification handler code here
	
}

void CDeleteCertainFolderFileDlg::OnRadio5() 
{
	// TODO: Add your control notification handler code here
	
}

void CDeleteCertainFolderFileDlg::OnDelete() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CString m_extern;
	switch (m_radio)			//获取要删除文件类型的后缀名
	{
	case 0:
		GetDlgItem(IDC_RADIO1)->GetWindowText(m_extern);
		break;
	case 1:
		GetDlgItem(IDC_RADIO2)->GetWindowText(m_extern);
		break;
	case 2:
		GetDlgItem(IDC_RADIO3)->GetWindowText(m_extern);
		break;
	case 3:
		GetDlgItem(IDC_RADIO4)->GetWindowText(m_extern);
		break;
	case 4:
		GetDlgItem(IDC_RADIO5)->GetWindowText(m_extern);
		break;
	}
	if(m_strFolder!="" && m_extern!="")//当前目录和文件类型不为空
	{
		CString str,strdel;	
		//构造类似"C:\\My Documents\\*.txt"的类型
		char string[60];
		strcpy( string, m_strFolder);
		strcat( string, "\\*" );
		strcat( string, m_extern );	
		CFileFind filefind;
		if(filefind.FindFile(string,0)!=0)//遍历搜索文件
		{
			while(filefind.FindNextFile()!=0)
			{
				strdel=filefind.GetFilePath();//获取文件名
				CFile::Remove(strdel);//删除文件
			}
			strdel=filefind.GetFilePath();
			CFile::Remove(strdel);
			AfxMessageBox("文件删除完成！");
			DisplayFileList(m_strFolder);//更新显示列表框
		}
		else
		{
			AfxMessageBox("当前目录下，没有这种类型的文件！");
		}
	}
	else
		AfxMessageBox("请选择目录！");
}

void CDeleteCertainFolderFileDlg::DisplayFileList(CString strdir) 
{
	TCHAR szPath [MAX_PATH];
	strcpy(szPath,strdir);
	//DlgDirList函数用于向ListBox中加入某路径下的文件
	int nReslt = DlgDirList(
		szPath,//目录
		IDC_LIST1,//ListBox的资源ID
		0,//当前选择的驱动器和路径的静态控件ID，如果不用显示这些驱动器和路径，置为0
		DDL_READWRITE|DDL_READONLY|DDL_HIDDEN|DDL_SYSTEM|DDL_ARCHIVE);
}

void CDeleteCertainFolderFileDlg::OnChangeEdit1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	DisplayFileList(m_strFolder);
}
