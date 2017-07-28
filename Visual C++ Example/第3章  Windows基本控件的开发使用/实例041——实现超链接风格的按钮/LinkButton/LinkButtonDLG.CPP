// LinkButtonDlg.cpp : implementation file
//

#include "stdafx.h"
#include "LinkButton.h"
#include "LinkButtonDlg.h"

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
// CLinkButtonDlg dialog

CLinkButtonDlg::CLinkButtonDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLinkButtonDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLinkButtonDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLinkButtonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLinkButtonDlg)
	DDX_Control(pDX, IDC_HOMEPAGE, m_ctlHomePage);
	DDX_Control(pDX, IDC_EMAIL, m_ctlMail);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLinkButtonDlg, CDialog)
	//{{AFX_MSG_MAP(CLinkButtonDlg)
	ON_BN_CLICKED(IDC_EMAIL, OnEmail)
	ON_BN_CLICKED(IDC_HOMEPAGE, OnHomepage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLinkButtonDlg message handlers

BOOL CLinkButtonDlg::OnInitDialog()
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




void CLinkButtonDlg::OnEmail() //发送邮件
{
	CString str;
	m_ctlMail.GetWindowText(str);//获取控件标题文本
	str="mailto:"+str;
	char MailAddress[40];
	strcpy(MailAddress,str);
	ShellExecute(NULL, 
				"open", 
				 MailAddress, 
				 NULL, 
				 NULL, 
				 SW_SHOWNORMAL);
}

void CLinkButtonDlg::OnHomepage() //打开网页
{
	CString str;
	m_ctlHomePage.GetWindowText(str);//获取控件标题文本
	char URL[40];
	strcpy(URL,str);
	ShellExecute(NULL, 
				"open", 
				 URL, 
				 NULL, 
				 NULL, 
				 SW_SHOWNORMAL);
}


