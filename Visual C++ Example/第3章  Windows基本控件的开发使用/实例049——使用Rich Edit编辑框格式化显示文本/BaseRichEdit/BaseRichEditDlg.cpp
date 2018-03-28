// BaseRichEditDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BaseRichEdit.h"
#include "BaseRichEditDlg.h"

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
// CBaseRichEditDlg dialog

CBaseRichEditDlg::CBaseRichEditDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBaseRichEditDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBaseRichEditDlg)
	m_bold = FALSE;
	m_italic = FALSE;
	m_underline = FALSE;
	m_radio = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBaseRichEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBaseRichEditDlg)
	DDX_Control(pDX, IDC_UNDERLINE, m_ctlUnderline);
	DDX_Control(pDX, IDC_ITALIC, m_ctlItalic);
	DDX_Control(pDX, IDC_BOLD, m_ctlBold);
	DDX_Control(pDX, IDC_RICH_EDIT, m_RichSample);
	DDX_Check(pDX, IDC_BOLD, m_bold);
	DDX_Check(pDX, IDC_ITALIC, m_italic);
	DDX_Check(pDX, IDC_UNDERLINE, m_underline);
	DDX_Radio(pDX, IDC_LETT, m_radio);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBaseRichEditDlg, CDialog)
	//{{AFX_MSG_MAP(CBaseRichEditDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BOLD, OnBold)
	ON_BN_CLICKED(IDC_ITALIC, OnItalic)
	ON_BN_CLICKED(IDC_UNDERLINE, OnUnderline)
	ON_BN_CLICKED(IDC_LETT, OnLett)
	ON_BN_CLICKED(IDC_RIGHT, OnRight)
	ON_BN_CLICKED(IDC_CENTER, OnCenter)
	ON_BN_CLICKED(IDC_TextColor, OnTextColor)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBaseRichEditDlg message handlers

BOOL CBaseRichEditDlg::OnInitDialog()
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

void CBaseRichEditDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CBaseRichEditDlg::OnPaint() 
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
HCURSOR CBaseRichEditDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CBaseRichEditDlg::OnBold() //设置粗体复选框
{
	// TODO: Add your control notification handler code here
	CHARFORMAT cf;//结构体
	m_RichSample.GetSelectionCharFormat (cf);
	cf.dwMask |= CFM_BOLD;
	cf.dwEffects ^= CFE_BOLD;
	m_RichSample.SetSelectionCharFormat (cf);
	if (cf.dwEffects & CFE_BOLD)//当前为粗体
		m_ctlBold.SetCheck (1);//设置按钮被选中
	else//当前不为粗体
		m_ctlBold.SetCheck (0);//设置按钮未被选中
	m_RichSample.SetFocus ();
	
}

void CBaseRichEditDlg::OnItalic() //设置斜体复选框
{
	// TODO: Add your control notification handler code here
	CHARFORMAT cf;
	m_RichSample.GetSelectionCharFormat (cf);
	cf.dwMask |= CFM_ITALIC;
	cf.dwEffects ^= CFE_ITALIC;
	m_RichSample.SetSelectionCharFormat (cf);
	if (cf.dwEffects & CFM_ITALIC)//当前为斜体
		m_ctlItalic.SetCheck (1);//设置按钮被选中
	else//当前不为斜体
		m_ctlItalic.SetCheck (0);//设置按钮未被选中
	m_RichSample.SetFocus ();
	
}
void CBaseRichEditDlg::OnUnderline() //设置下划线复选框
{
	// TODO: Add your control notification handler code here
	CHARFORMAT cf;
	m_RichSample.GetSelectionCharFormat (cf);
	cf.dwMask |= CFM_UNDERLINE;
	cf.dwEffects ^= CFE_UNDERLINE;
	m_RichSample.SetSelectionCharFormat (cf);
	if (cf.dwEffects & CFM_UNDERLINE)//当前带有下划线
		m_ctlUnderline.SetCheck (1);//设置按钮被选中
	else//当前不带有下划线
		m_ctlUnderline.SetCheck (0);//设置按钮未被选中
	m_RichSample.SetFocus ();
}


void CBaseRichEditDlg::OnLett() 
{
	// TODO: Add your control notification handler code here
	PARAFORMAT pf;
	m_RichSample.GetParaFormat(pf);
	pf.dwMask = PFM_ALIGNMENT;
	pf.wAlignment = PFA_LEFT;
	m_RichSample.SetParaFormat(pf);
	m_RichSample.SetFocus ();
	
}

void CBaseRichEditDlg::OnRight() 
{
	// TODO: Add your control notification handler code here
	PARAFORMAT pf;
	m_RichSample.GetParaFormat(pf);
	pf.dwMask = PFM_ALIGNMENT;
	pf.wAlignment = PFA_RIGHT;
	m_RichSample.SetParaFormat(pf);
	m_RichSample.SetFocus ();
	
}

void CBaseRichEditDlg::OnCenter() 
{
	// TODO: Add your control notification handler code here
	PARAFORMAT pf;
	m_RichSample.GetParaFormat(pf);
	pf.dwMask = PFM_ALIGNMENT;
	pf.wAlignment = PFA_CENTER;
	m_RichSample.SetParaFormat(pf);
	m_RichSample.SetFocus ();
	
}


void CBaseRichEditDlg::OnTextColor() 
{
	// TODO: Add your control notification handler code here
	CHARFORMAT cf;
	memset (&cf, '\0', sizeof (CHARFORMAT));
	cf.dwMask = CFM_COLOR;
	m_RichSample.GetSelectionCharFormat (cf);
	CColorDialog cc (cf.crTextColor);
//	cc.m_cc.lpCustColors = m_clrCustom;
	if (cc.DoModal () == IDCANCEL)
		return;
	cf.dwMask = CFM_COLOR;
	cf.dwEffects &= ~CFE_AUTOCOLOR;
	cf.crTextColor  = cc.GetColor ();
	m_RichSample.SetSelectionCharFormat (cf);
	m_RichSample.SetFocus ();
	
}
