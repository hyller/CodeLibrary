// ActiveXAutoRegDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ActiveXAutoReg.h"
#include "ActiveXAutoRegDlg.h"

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
// CActiveXAutoRegDlg dialog

CActiveXAutoRegDlg::CActiveXAutoRegDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CActiveXAutoRegDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CActiveXAutoRegDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CActiveXAutoRegDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CActiveXAutoRegDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CActiveXAutoRegDlg, CDialog)
	//{{AFX_MSG_MAP(CActiveXAutoRegDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_REGISTER, OnRegister)
	ON_BN_CLICKED(IDC_UNREGISTER, OnUnregister)
	ON_BN_CLICKED(IDC_BROWSE, OnBrowse)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CActiveXAutoRegDlg message handlers

BOOL CActiveXAutoRegDlg::OnInitDialog()
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

void CActiveXAutoRegDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CActiveXAutoRegDlg::OnPaint() 
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
HCURSOR CActiveXAutoRegDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CActiveXAutoRegDlg::OnRegister() //注册
{
	CString strFileName;
    GetDlgItem(IDC_PATH)->GetWindowText(strFileName);	//获取文件路径
	if (strFileName.IsEmpty())
		return;

	//装载ActiveX控件  
	HINSTANCE hInstance = LoadLibrary(strFileName); 
	if (hInstance == NULL)  
	{     
		AfxMessageBox("不能载入Dll/OCX文件!");     
		return; 
	} 
	//取得注册函数DllRegisterServer地址 
	FARPROC lpFunc;  
	lpFunc = GetProcAddress(hInstance,_T("DllRegisterServer"));  
	//调用注册函数DllRegisterServer 
	if(lpFunc!=NULL)  
	{       
		if(FAILED((*lpFunc)()))   
		{       
			AfxMessageBox("调用DllRegisterServer 失败!");  
			FreeLibrary(hInstance);   //释放资源       
			return;     
		}     
		AfxMessageBox("注册成功");  
	}
	else  
	{
		AfxMessageBox("调用DllRegisterServer失败!");
	}
}

void CActiveXAutoRegDlg::OnUnregister() //注销
{
	CString strFileName;
    GetDlgItem(IDC_PATH)->GetWindowText(strFileName);//获取文件路径	
	if (strFileName.IsEmpty())
		return;
	//装载ActiveX控件  
	HINSTANCE hInstance = LoadLibrary(strFileName); 
	if (hInstance < (HINSTANCE)HINSTANCE_ERROR)  
	{     
		AfxMessageBox("不能载入Dll/OCX文件!");     
		return; 
	} 
	//获取注销函数DllUnregisterServer地址 
	FARPROC lpFunc;  
	lpFunc = GetProcAddress(hInstance,_T("DllUnregisterServer"));  
	//调用注册函数DllUnregisterServer 
	if(lpFunc!=NULL)  
	{       
		if(FAILED((*lpFunc)()))   
		{       
			AfxMessageBox("调用DllUnregisterServer失败!");  
			FreeLibrary(hInstance);      //释放资源    
			return;     
		}    	
		AfxMessageBox("注销成功");  		
	}
	else
	{
		AfxMessageBox("调用DllUnregisterServer失败!");
	}

}

void CActiveXAutoRegDlg::OnBrowse() //浏览文件
{
	CString strFilter = _T("DLL/OCX files(*.dll;*.ocx)|*.dll;*.ocx|DLL Files(*.dll)|*.dll|OCX Files(*.ocx)|*.ocx|All Files (*.*)|*.*||");
	CFileDialog dlgOpen(TRUE,NULL,NULL,OFN_HIDEREADONLY|OFN_FILEMUSTEXIST,(LPCTSTR)strFilter,NULL);
    if (dlgOpen.DoModal()!=IDOK)//打开文件对话框
		return;
	CString strFileName = dlgOpen.GetPathName();
    GetDlgItem(IDC_PATH)->SetWindowText(strFileName);	//将文件路径显示在编辑框
}
