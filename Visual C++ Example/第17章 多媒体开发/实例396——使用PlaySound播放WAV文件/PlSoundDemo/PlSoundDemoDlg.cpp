// PlSoundDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PlSoundDemo.h"
#include "PlSoundDemoDlg.h"
#include<Mmsystem.h>   
  #pragma   comment(lib,   "Winmm.lib")   

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
// CPlSoundDemoDlg dialog

CPlSoundDemoDlg::CPlSoundDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPlSoundDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPlSoundDemoDlg)
	m_strStatus = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPlSoundDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPlSoundDemoDlg)
	DDX_Text(pDX, IDC_EDIT1, m_strStatus);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPlSoundDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CPlSoundDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_PLAYRESOURCE, OnPlayresource)
	ON_BN_CLICKED(IDC_PLAYSYSTEM, OnPlaysystem)
	ON_BN_CLICKED(IDC_PLAYWAVEFILE, OnPlaywavefile)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPlSoundDemoDlg message handlers

BOOL CPlSoundDemoDlg::OnInitDialog()
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

void CPlSoundDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPlSoundDemoDlg::OnPaint() 
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
HCURSOR CPlSoundDemoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPlSoundDemoDlg::OnPlayresource() 
{
	// TODO: Add your control notification handler code here
	PlaySound(MAKEINTRESOURCE(IDR_WAVE1),AfxGetResourceHandle(), SND_ASYNC| SND_RESOURCE);
	m_strStatus="播放波形资源IDR_WAVE1";
	UpdateData(false);
}

void CPlSoundDemoDlg::OnPlaysystem() 
{
	// TODO: Add your control notification handler code here
	PlaySound("SystemExclamation", NULL, SND_ASYNC);
	m_strStatus="播放系统声音——警告音";
	UpdateData(false);
}

void CPlSoundDemoDlg::OnPlaywavefile() 
{
	// TODO: Add your control notification handler code here
	CString WaveFile;//波形文件
	CString szFilters="WAV Files (*.wav)|*.wav|All Files (*.*)|*.*||";		//定义文件过滤器
   //创建打开文件对话框对象，默认的文件扩展名为 ".wav ".
   CFileDialog fileDlg (TRUE, "WAV", "*.wav",OFN_FILEMUSTEXIST| OFN_HIDEREADONLY, szFilters, this);
   //调用DoModal()函数显示打开文件对话框
   if( fileDlg.DoModal ()==IDOK )
   {
      WaveFile = fileDlg.GetPathName();
	  PlaySound(WaveFile, NULL, SND_ASYNC);//播放
	  m_strStatus="播放波形文件："+WaveFile;
	UpdateData(false);
   }
	
}
