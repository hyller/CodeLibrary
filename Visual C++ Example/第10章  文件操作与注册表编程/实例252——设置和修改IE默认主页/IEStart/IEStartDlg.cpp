// IEStartDlg.cpp : implementation file
//

#include "stdafx.h"
#include "IEStart.h"
#include "IEStartDlg.h"

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
// CIEStartDlg dialog

CIEStartDlg::CIEStartDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CIEStartDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CIEStartDlg)
	m_startpage = _T("");
	m_location = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CIEStartDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CIEStartDlg)
	DDX_Control(pDX, IDC_QUERRY, m_bQuerry);
	DDX_Control(pDX, IDC_MODIFY, m_bModify);
	DDX_Control(pDX, IDC_APPLICATON, m_bApplication);
	DDX_Text(pDX, IDC_STARTPAGE, m_startpage);
	DDX_Text(pDX, IDC_LOCATION, m_location);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CIEStartDlg, CDialog)
	//{{AFX_MSG_MAP(CIEStartDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_APPLICATON, OnApplicaton)
	ON_BN_CLICKED(IDC_MODIFY, OnModify)
	ON_BN_CLICKED(IDC_QUERRY, OnQuerry)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIEStartDlg message handlers

BOOL CIEStartDlg::OnInitDialog()
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
	m_bApplication.EnableWindow(false);//应用按钮无效
	m_bModify.EnableWindow(false);//修改按钮无效
	GetDlgItem(IDC_STARTPAGE)->EnableWindow(false);	//主页编辑框不可输入

	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CIEStartDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CIEStartDlg::OnPaint() 
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
HCURSOR CIEStartDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CIEStartDlg::OnApplicaton() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);//获得编辑框数据
	if(m_startpage.IsEmpty())
	{
		m_startpage=_T("about:blank");
	}
	//定义有关的 hKEY, 在程序的最后要关闭。 
	HKEY hKEY;  
	//hKEY，KEY_WRITE表示以写的方式打开。 
	long ret=(::RegOpenKeyEx(HKEY_CURRENT_USER,m_location, 0, KEY_WRITE, &hKEY)); 
	if(ret!=ERROR_SUCCESS) 
	{ 
		MessageBox("错误: 无法打开有关注册表键!"); 
		return; 
	} 
	//修改有关数据，要先将CString型转换为LPBYTE
	LPBYTE owner_Set=new BYTE[m_startpage.GetLength()+1];  				//分配内存
	for(int i=0;i<m_startpage.GetLength();i++)
	{
		*(owner_Set+i) = m_startpage.GetAt(i);								//为每个元组赋值
	}
	DWORD type=REG_SZ; 
	DWORD cbData=m_startpage.GetLength()+1;  
	long ret1=::RegSetValueEx(hKEY, "Start Page", NULL, type, owner_Set, cbData); 
	if(ret1!=ERROR_SUCCESS) 
	{ 
		MessageBox("错误: 无法修改有关注册表信息!"); 
		return; 
	} 
	m_bApplication.EnableWindow(false);//应用按钮无效
	m_bModify.EnableWindow(false);//修改按钮无效
	GetDlgItem(IDC_STARTPAGE)->EnableWindow(false);	//主页编辑框不可输入
	m_bQuerry.EnableWindow(true);//查询按钮生效	
	// 程序结束前要关闭已经打开的 hKEY。 
	RegCloseKey(hKEY);
	AfxMessageBox("关注册表信息修改成功!"); 

}

void CIEStartDlg::OnModify() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_STARTPAGE)->EnableWindow(true);	//主页编辑框可输入
	m_bApplication.EnableWindow(true);//应用按钮生效
	m_bModify.EnableWindow(false);//修改按钮无效
	m_bQuerry.EnableWindow(true);//查询按钮生效	
}

void CIEStartDlg::OnQuerry() 
{	
	// TODO: Add your control notification handler code here
	m_bApplication.EnableWindow(false);//应用按钮无效
	m_bModify.EnableWindow(false);//修改按钮无效
	GetDlgItem(IDC_STARTPAGE)->EnableWindow(false);	//主页编辑框不可输入

	HKEY hKEY; 							//存储注册表键句柄
	HKEY hSubKEY; 						//存储注册表键句柄
	BYTE SubKey[50];					//存储子键名称
	BYTE StartPage[50];					//存储主页名称
	DWORD readSize;						//键值大小
	DWORD readType=REG_SZ;				//键值类型
	DWORD index;						//检索序号
	DWORD longth=50;
	FILETIME lastWriteTime;
	LPCTSTR data_Set="SOFTWARE\\MICROSOFT\\INTERNET EXPLORER\\"; 	//子键目录
	//打开注册表相关键
	if(RegOpenKeyEx(HKEY_CURRENT_USER,data_Set, 0, KEY_ALL_ACCESS, &hKEY)!=ERROR_SUCCESS)
	{
		//注册表键打开失败则返回
		MessageBox("错误: 无法打开有关的注册表键!"); 
		return;
	}
	index=0;						//赋初值
	//对注册表句柄hKEY下的子关键字进行枚举
	while(RegEnumKeyEx(hKEY,index++,(LPSTR)SubKey,&longth,NULL,NULL,NULL,&lastWriteTime)!=ERROR_NO_MORE_ITEMS)
	{
		longth=50;
		readSize=50;
		//打开注册表相关键
		if(RegOpenKeyEx(hKEY,(LPSTR)SubKey,0,KEY_READ,&hSubKEY)!=ERROR_SUCCESS)
		{
			//注册表键打开失败则返回
			MessageBox("错误: 无法打开有关的注册表键!"); 
			return;
		}
		//读取主页信息
		if(RegQueryValueEx(hSubKEY,"Start Page",NULL,&readType,StartPage,&readSize)==ERROR_SUCCESS)
		{
			m_startpage.Format("%s",StartPage);
			m_location.Format("%s%s",data_Set,SubKey);
			UpdateData(false);//显示信息
			// 程序结束前要关闭已经打开的 hKEY。 
			RegCloseKey(hKEY); 
			RegCloseKey(hSubKEY); 

			m_bModify.EnableWindow(true);//修改按钮生效
			m_bQuerry.EnableWindow(false);//查询按钮无效
			return;
		}
		else
			m_location.Empty();
	}
	if(m_location.IsEmpty())
	{
			MessageBox("未找到相应信息!"); 
			return;
	}
}
