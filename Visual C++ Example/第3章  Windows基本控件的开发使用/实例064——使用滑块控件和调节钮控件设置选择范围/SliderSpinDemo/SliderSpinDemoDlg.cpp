// SliderSpinDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SliderSpinDemo.h"
#include "SliderSpinDemoDlg.h"

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
// CSliderSpinDemoDlg dialog

CSliderSpinDemoDlg::CSliderSpinDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSliderSpinDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSliderSpinDemoDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSliderSpinDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSliderSpinDemoDlg)
	DDX_Control(pDX, IDC_SLIDER1, m_ctlSlider);
	DDX_Control(pDX, IDC_SPIN1, m_ctlSpin);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSliderSpinDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CSliderSpinDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_HSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSliderSpinDemoDlg message handlers

BOOL CSliderSpinDemoDlg::OnInitDialog()
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
	
	m_ctlSpin.SetRange(0,100);	//设置调节钮控件的调节范围
	m_ctlSpin.SetPos(0);  //设置其伴随窗口的初始值
	m_ctlSlider.SetRange(0,100);  	//设置滑动控件的数据范围
	m_ctlSlider.SetPos(0);//设置滑动控件的初始值
	m_ctlSlider.SetTicFreq(10);								//设置刻度频度
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSliderSpinDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSliderSpinDemoDlg::OnPaint() 
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
HCURSOR CSliderSpinDemoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSliderSpinDemoDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	int ctrID=pScrollBar->GetDlgCtrlID();//获取控件ID
	int nPosition;
	switch(ctrID)
	{
		case IDC_SLIDER1:		//滑块控件产生
			nPosition=m_ctlSlider.GetPos();//获取滑块控件的位置
			m_ctlSpin.SetPos(nPosition);//设置调节钮到指定位置
			break;
		case IDC_SPIN1:		//调节钮控件产生
			nPosition=m_ctlSpin.GetPos();//获取滑块控件的位置
			m_ctlSlider.SetPos(nPosition);//设置调节钮到指定位置
			break;
	}
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}
