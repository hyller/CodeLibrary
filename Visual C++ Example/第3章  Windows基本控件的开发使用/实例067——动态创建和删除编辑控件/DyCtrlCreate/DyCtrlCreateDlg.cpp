// DyCtrlCreateDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DyCtrlCreate.h"
#include "DyCtrlCreateDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#define ID_MYEDITBOX 1850//为编辑框设定ID为1850

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
// CDyCtrlCreateDlg dialog

CDyCtrlCreateDlg::CDyCtrlCreateDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDyCtrlCreateDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDyCtrlCreateDlg)
	m_showmsg = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDyCtrlCreateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDyCtrlCreateDlg)
	DDX_Text(pDX, IDC_STATIC2, m_showmsg);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDyCtrlCreateDlg, CDialog)
	//{{AFX_MSG_MAP(CDyCtrlCreateDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CREATE, OnButtonCreate)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_EN_CHANGE(ID_MYEDITBOX, OnChangeEdit)//添加消息映射

	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDyCtrlCreateDlg message handlers

BOOL CDyCtrlCreateDlg::OnInitDialog()
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

void CDyCtrlCreateDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDyCtrlCreateDlg::OnPaint() 
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
HCURSOR CDyCtrlCreateDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDyCtrlCreateDlg::OnButtonCreate() //动态生成编辑控件
{
	// TODO: Add your control notification handler code here
	CWnd *wnd;
	CRect rect;//编辑框控件的位置尺寸
	rect.left = 20;
	rect.right = rect.left + 110;
	rect.top = 20;
	rect.bottom = rect.top + 30;

	if (!(wnd =GetDlgItem(ID_MYEDITBOX)))
	{
   		m_MyEdit.CreateEx(WS_EX_CLIENTEDGE, // Make a 3D-border
						_T("EDIT"), 
						NULL,
						ES_AUTOHSCROLL|
						ES_LEFT|ES_NOHIDESEL|
						WS_CHILD,
						rect, this,
						ID_MYEDITBOX);//生成edit控件
		m_MyEdit.ShowWindow(SW_SHOW);//显示编辑框
		m_MyEdit.SetFocus();//设置输入焦点
	}
	
	
}

void CDyCtrlCreateDlg::OnButtonDelete() //删除编辑控件
{
	// TODO: Add your control notification handler code here
	CWnd *wnd;
	if (wnd =GetDlgItem(ID_MYEDITBOX))
		wnd->DestroyWindow() ;
	
}

void CDyCtrlCreateDlg::OnChangeEdit()
{

  GetDlgItem(ID_MYEDITBOX)->GetWindowText(m_showmsg);//将编辑框中的文本赋予静态文本控件
  UpdateData(FALSE);//更新显示
}
