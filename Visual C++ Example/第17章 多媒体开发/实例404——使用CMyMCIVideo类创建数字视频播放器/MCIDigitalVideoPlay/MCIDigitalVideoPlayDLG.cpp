// MCIDigitalVideoPlayDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MCIDigitalVideoPlay.h"
#include "MCIDigitalVideoPlayDlg.h"

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
// CMCIDigitalVideoPlayDlg dialog

CMCIDigitalVideoPlayDlg::CMCIDigitalVideoPlayDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMCIDigitalVideoPlayDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMCIDigitalVideoPlayDlg)
	m_strfile = _T("");
	m_strspeed = _T("");
	m_strframenum = _T("");
	m_framesize = _T("");
	//}}AFX_DATA_INIT
	m_bOpen = FALSE;
	m_bLoop = FALSE;
	m_bFullScreen = FALSE;
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMCIDigitalVideoPlayDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMCIDigitalVideoPlayDlg)
	DDX_Control(pDX, IDC_CHECKLOOP, m_ctlCheckLoop);
	DDX_Control(pDX, IDC_CHECKFULL, m_ctlCheckFull);
	DDX_Text(pDX, IDC_FILE, m_strfile);
	DDX_Text(pDX, IDC_SPEED, m_strspeed);
	DDX_Text(pDX, IDC_FRAMENUM, m_strframenum);
	DDX_Text(pDX, IDC_FRAMESIZE, m_framesize);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMCIDigitalVideoPlayDlg, CDialog)
	//{{AFX_MSG_MAP(CMCIDigitalVideoPlayDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BACKAVI, OnBackavi)
	ON_BN_CLICKED(IDC_FORWARDAVI, OnForwardavi)
	ON_BN_CLICKED(IDC_OPENAVI, OnOpenavi)
	ON_BN_CLICKED(IDC_PAUSEAVI, OnPauseavi)
	ON_BN_CLICKED(IDC_PLAYAVI, OnPlayavi)
	ON_BN_CLICKED(IDC_STOPAVI, OnStopavi)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMCIDigitalVideoPlayDlg message handlers

BOOL CMCIDigitalVideoPlayDlg::OnInitDialog()
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
	GetDlgItem(IDC_BACKAVI)->EnableWindow(false);//“上一帧”按钮无效
	GetDlgItem(IDC_FORWARDAVI)->EnableWindow(false);//“下一帧”按钮无效
	GetDlgItem(IDC_PLAYAVI)->EnableWindow(false);//“播放”按钮无效
	GetDlgItem(IDC_PAUSEAVI)->EnableWindow(false);//“暂停”按钮无效
	GetDlgItem(IDC_STOPAVI)->EnableWindow(false);//“停止”按钮无效
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMCIDigitalVideoPlayDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMCIDigitalVideoPlayDlg::OnPaint() 
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
HCURSOR CMCIDigitalVideoPlayDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMCIDigitalVideoPlayDlg::OnBackavi() //上一帧
{
	// TODO: Add your control notification handler code here
	m_avi.Backward(1);//后退一帧	
}

void CMCIDigitalVideoPlayDlg::OnForwardavi() //下一帧
{
	// TODO: Add your control notification handler code here
	m_avi.Forward(1);//前进一帧
}

void CMCIDigitalVideoPlayDlg::OnOpenavi() 
{
	// TODO: Add your control notification handler code here
	if (m_bOpen)//已有文件打开
	{
		m_avi.Close();//关闭文件
		m_bOpen = FALSE;
	}
	CString Filter, str;
	Filter = "视频文件(*.AVI)|*.AVI||";//过滤字符串
	CRect rect;
	CFileDialog fileDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, Filter);//打开文件对话框
	if (fileDlg.DoModal() == IDOK)
	{
		CWnd *pWnd = GetDlgItem(IDC_AVIRECT);    // 获得视频窗口的指针
		pWnd->GetWindowRect(rect);                   // 获得视频窗口的大小
		if (!m_avi.OpenAvi(fileDlg.GetPathName(), pWnd, 0, 0, rect.Width(), rect.Height()))
		{
			MessageBox("无法打开该文件", "Error", MB_OK | MB_ICONSTOP);
			return;
		}
		GetDlgItem(IDC_PLAYAVI)->EnableWindow(true);//“播放”按钮生效
		GetDlgItem(IDC_PAUSEAVI)->EnableWindow(false);//“暂停”按钮无效
		GetDlgItem(IDC_STOPAVI)->EnableWindow(false);//“停止”按钮无效
		GetDlgItem(IDC_OPENAVI)->EnableWindow(false);//“打开”按钮无效

		m_strfile = fileDlg.GetFileName();//文件名
		m_avi.SetSpeed(400);                       // 设置播放速度
		m_bOpen = TRUE;
		m_strspeed.Format("%d帧/分", m_avi.GetSpeed());//播放速度
		m_framesize.Format("宽:%d  高:%d", m_avi.GetWidth(), m_avi.GetHeight());//尺寸
		m_strframenum.Format("共有%d帧", m_avi.GetFrames());//所有帧数
		UpdateData(false);
	}
}

void CMCIDigitalVideoPlayDlg::OnPauseavi() //暂停
{
	// TODO: Add your control notification handler code here
	m_avi.Pause();               // 暂停视频的播放
	GetDlgItem(IDC_BACKAVI)->EnableWindow(true);//上一帧按钮生效
	GetDlgItem(IDC_FORWARDAVI)->EnableWindow(true);//下一帧按钮生效
}

void CMCIDigitalVideoPlayDlg::OnPlayavi() //播放
{
	// TODO: Add your control notification handler code here
	if(m_ctlCheckFull.GetCheck()==1)							//全屏复选框被选中
		m_bFullScreen=true;
	else 
		m_bFullScreen=false;

	if(m_ctlCheckLoop.GetCheck()==1)							//全屏复选框被选中
		m_bLoop=true;
	else
		m_bLoop=false;
	m_avi.PlayAvi(m_bLoop, m_bFullScreen);               // 播放视频
	m_ctlCheckFull.EnableWindow(false);//复选框无效
	m_ctlCheckLoop.EnableWindow(false);
	GetDlgItem(IDC_PLAYAVI)->EnableWindow(false);//播放按钮无效
	GetDlgItem(IDC_PAUSEAVI)->EnableWindow(true);//暂停按钮生效
	GetDlgItem(IDC_STOPAVI)->EnableWindow(true);//停止按钮生效
}

void CMCIDigitalVideoPlayDlg::OnStopavi() //停止
{
	// TODO: Add your control notification handler code here
	m_avi.Stop();               // 停止视频的播放
	m_ctlCheckFull.EnableWindow(true);//复选框无效
	m_ctlCheckLoop.EnableWindow(true);
	GetDlgItem(IDC_PLAYAVI)->EnableWindow(true);//播放按钮生效
	GetDlgItem(IDC_OPENAVI)->EnableWindow(true);//打开按钮生效
	GetDlgItem(IDC_BACKAVI)->EnableWindow(false);//上一帧按钮无效
	GetDlgItem(IDC_FORWARDAVI)->EnableWindow(false);//下一帧按钮无效
	GetDlgItem(IDC_PAUSEAVI)->EnableWindow(false);//暂停按钮无效
	GetDlgItem(IDC_STOPAVI)->EnableWindow(false);//停止按钮无效
}
