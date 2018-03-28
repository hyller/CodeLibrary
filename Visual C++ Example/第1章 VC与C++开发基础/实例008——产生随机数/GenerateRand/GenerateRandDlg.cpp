// GenerateRandDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GenerateRand.h"
#include "GenerateRandDlg.h"

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
// CGenerateRandDlg dialog

CGenerateRandDlg::CGenerateRandDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGenerateRandDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGenerateRandDlg)
	m_Min = 0.0;
	m_Max = 0.0;
	m_Rand1 = 0.0;
	m_Rand2 = 0.0;
	m_Rand3 = 0.0;
	m_Rand4 = 0.0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGenerateRandDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGenerateRandDlg)
	DDX_Text(pDX, IDC_EDIT1, m_Min);
	DDX_Text(pDX, IDC_EDIT2, m_Max);
	DDX_Text(pDX, IDC_EDIT3, m_Rand1);
	DDX_Text(pDX, IDC_EDIT4, m_Rand2);
	DDX_Text(pDX, IDC_EDIT5, m_Rand3);
	DDX_Text(pDX, IDC_EDIT6, m_Rand4);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CGenerateRandDlg, CDialog)
	//{{AFX_MSG_MAP(CGenerateRandDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_GENERATE, OnGenerate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGenerateRandDlg message handlers

BOOL CGenerateRandDlg::OnInitDialog()
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

void CGenerateRandDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CGenerateRandDlg::OnPaint() 
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
HCURSOR CGenerateRandDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CGenerateRandDlg::OnGenerate() 
{
	// TODO: Add your control notification handler code herein
	UpdateData(true);
	if(m_Min>=m_Max)
	{
		AfxMessageBox("最大值、最小值设置错误！");
		return;
	}
	srand((unsigned)time(NULL));    //随机数计时开始
	m_Rand1=GetRand(m_Min,m_Max);
	m_Rand2=GetRand(m_Min,m_Max);
	m_Rand3=GetRand(m_Min,m_Max);
	m_Rand4=GetRand(m_Min,m_Max);
	UpdateData(false);
}

double CGenerateRandDlg::GetRand(double MIN, double MAX)//产生随机数
{
     double max;
     max=RAND_MAX;//rand()函数随机数的最大值
     return (double)(rand()*(MAX-MIN)/max+MIN);
}
