// UseMagicBoxDlg.cpp : implementation file
//

#include "stdafx.h"
#include "UseMagicBox.h"
#include "UseMagicBoxDlg.h"

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
// CUseMagicBoxDlg dialog

CUseMagicBoxDlg::CUseMagicBoxDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUseMagicBoxDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUseMagicBoxDlg)
	m_radio = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CUseMagicBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUseMagicBoxDlg)
	DDX_Control(pDX, IDC_MAGICBOX1, m_ctlMagicBox);
	DDX_Radio(pDX, IDC_RADIO1, m_radio);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CUseMagicBoxDlg, CDialog)
	//{{AFX_MSG_MAP(CUseMagicBoxDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SET, OnSet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUseMagicBoxDlg message handlers

BOOL CUseMagicBoxDlg::OnInitDialog()
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
	m_ctlMagicBox.SetBackColor(RGB(255,0,0));
	m_ctlMagicBox.SetFillColor(RGB(0,0,255));
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CUseMagicBoxDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CUseMagicBoxDlg::OnPaint() 
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
HCURSOR CUseMagicBoxDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BEGIN_EVENTSINK_MAP(CUseMagicBoxDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CUseMagicBoxDlg)
	ON_EVENT(CUseMagicBoxDlg, IDC_MAGICBOX1, 1 /* ClickBox */, OnClickBoxMagicbox1, VTS_I4 VTS_I4)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CUseMagicBoxDlg::OnClickBoxMagicbox1(long x, long y) 
{
	// TODO: Add your control notification handler code here
	AfxMessageBox("clickbox事件响应成功！");
}

void CUseMagicBoxDlg::OnSet() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	switch (m_radio)
	{
	case 0://红蓝配色方案
		m_ctlMagicBox.SetBackColor(RGB(255,0,0));
		m_ctlMagicBox.SetFillColor(RGB(0,0,255));
		break;
	case 1://蓝绿配色方案
		m_ctlMagicBox.SetBackColor(RGB(0,0,255));
		m_ctlMagicBox.SetFillColor(RGB(0,255,0));
		break;
	case 2://红绿配色方案
		m_ctlMagicBox.SetBackColor(RGB(255,0,0));
		m_ctlMagicBox.SetFillColor(RGB(0,255,0));
		break;
	case 3://黑白配色方案
		m_ctlMagicBox.SetBackColor(RGB(0,0,0));
		m_ctlMagicBox.SetFillColor(RGB(255,255,255));
		break;
	}	
}
