// AddIEButtonDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AddIEButton.h"
#include "AddIEButtonDlg.h"
#include <atlbase.h>
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
// CAddIEButtonDlg dialog

CAddIEButtonDlg::CAddIEButtonDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddIEButtonDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddIEButtonDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAddIEButtonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddIEButtonDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAddIEButtonDlg, CDialog)
	//{{AFX_MSG_MAP(CAddIEButtonDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADDICON, OnAddicon)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddIEButtonDlg message handlers

BOOL CAddIEButtonDlg::OnInitDialog()
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

void CAddIEButtonDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAddIEButtonDlg::OnPaint() 
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
HCURSOR CAddIEButtonDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CAddIEButtonDlg::OnAddicon() 
{
	CRegKey rk;
	char szSubKey[]="Software\\Microsoft\\Internet Explorer\\Extensions\\{EC08273E-7342-4adf-945E-AC50C2CFFD91}";
	char szPath[MAX_PATH];
	char szNormalIconPath[MAX_PATH];		//正常情况下的图标全路径
	char szHotIconPath[MAX_PATH];			//鼠标移动到其上时的图标全路径
	GetModuleFileName(0,szPath,MAX_PATH);	//获取的路径本应用程序的路径
	strcpy(szNormalIconPath,szPath);
	strcpy(szHotIconPath,szPath);
	strcat(szHotIconPath,",130");	//130是图标的ID
	strcat(szNormalIconPath,",130");
	if(rk.Create(HKEY_LOCAL_MACHINE,szSubKey)!=ERROR_SUCCESS)//创建子键
	{
		AfxMessageBox("创建注册表键失败");
		return;
	}
	rk.SetValue("{1FBA04EE-3024-11D2-8F1F-0000F87ABD16}","CLSID");  //创建IE的ClassID键
	rk.SetValue("Yes","Default Visible");     //缺省可见
	rk.SetValue("计算器程序","ButtonText");//显示文本
	rk.SetValue(szNormalIconPath,"Icon");
	rk.SetValue(szHotIconPath,"HotIcon");
	rk.SetValue("calc.exe","Exec");  //可执行文件为calc.exe	
	GetDlgItem(IDC_ADDICON)->EnableWindow(false);
}
