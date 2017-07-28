// MCIWavPlayDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MCIWavPlay.h"
#include "MCIWavPlayDlg.h"

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
// CMCIWavPlayDlg dialog

CMCIWavPlayDlg::CMCIWavPlayDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMCIWavPlayDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMCIWavPlayDlg)
	m_strbits = _T("");
	m_strChannel = _T("");
	m_strname = _T("");
	m_strtime = _T("");
	m_strSample = _T("");
	m_strstatus = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMCIWavPlayDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMCIWavPlayDlg)
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Text(pDX, IDC_BITS, m_strbits);
	DDX_Text(pDX, IDC_CHANNEL, m_strChannel);
	DDX_Text(pDX, IDC_FILENAME, m_strname);
	DDX_Text(pDX, IDC_FILETIME, m_strtime);
	DDX_Text(pDX, IDC_SAMPLERATE, m_strSample);
	DDX_Text(pDX, IDC_STATUS, m_strstatus);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMCIWavPlayDlg, CDialog)
	//{{AFX_MSG_MAP(CMCIWavPlayDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OPENWAV, OnOpenwav)
	ON_BN_CLICKED(IDC_PLAYWAV, OnPlaywav)
	ON_BN_CLICKED(IDC_RECORDWAV, OnRecordwav)
	ON_BN_CLICKED(IDC_SAVEWAV, OnSavewav)
	ON_BN_CLICKED(IDC_STOPWAV, OnStopwav)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMCIWavPlayDlg message handlers

BOOL CMCIWavPlayDlg::OnInitDialog()
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
	GetDlgItem(IDC_PLAYWAV)->EnableWindow(FALSE);    // 使"播放"按钮操作无效
	GetDlgItem(IDC_SAVEWAV)->EnableWindow(FALSE);    // 使"保存"按钮操作无效
	GetDlgItem(IDC_STOPWAV)->EnableWindow(FALSE);    // 使"停止"按钮操作无效
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMCIWavPlayDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMCIWavPlayDlg::OnPaint() 
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
HCURSOR CMCIWavPlayDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMCIWavPlayDlg::OnOpenwav() //打开波形音频文件
{
	// TODO: Add your control notification handler code here
	CString Filter;
	char buf[128];
	DWORD dwFlag;
	Filter = "波形音频文件(*.WAV)|*.WAV||";
	CFileDialog fileDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, Filter);
	if (fileDlg.DoModal() ==IDOK)    // 显示打开文件的对话框
	{
   		m_strname = fileDlg.GetPathName();       // 获得打开的文件名
		dwFlag = m_MyMCIWave.OpenWave(m_strname);                    // 打开波形音频文件
		if (dwFlag)
		{
			mciGetErrorString(dwFlag, buf, strlen(buf));  // 获取错误信息
			AfxMessageBox(buf);                    // 显示错误信息
		}
		GetDlgItem(IDC_PLAYWAV)->EnableWindow(TRUE); // 使"播放"按钮有效
		m_strstatus = "打开文件："+m_strname;  // 构造信息字符串并显示
		CTime m_time;
		m_time=CTime::GetCurrentTime();							//获取当前时间日期
		CString str=m_time.Format("%H:%M:%S：");		//格式化
		str=str+m_strstatus;
		m_List.AddString(str);//添加到列表框
		m_strSample.Format("%5.3f kHZ", m_MyMCIWave.GetSampleRate()/1000.);//获取采样频率
		switch (m_MyMCIWave.GetChannel())//获取声道
		{
		case 1:
			m_strChannel = "单声道";
			break;
		case 2:
			m_strChannel = "立体声";
			break;
		}
		m_strbits.Format("%d位", m_MyMCIWave.GetBitLength());//数据位
		m_strtime.Format("%02.2fs",m_MyMCIWave.GetWaveLength()/1000.);//时长
   		UpdateData(FALSE);//显示信息
	}
}

void CMCIWavPlayDlg::OnPlaywav() //播放波形文件
{
	if (m_MyMCIWave.PlayWave())
	{
		AfxMessageBox("播放出错");
		return;
	}
	GetDlgItem(IDC_RECORDWAV)->EnableWindow(FALSE);    // 使"录音"按钮操作无效
	GetDlgItem(IDC_OPENWAV)->EnableWindow(FALSE);    // 使"打开"按钮操作无效
	GetDlgItem(IDC_PLAYWAV)->EnableWindow(FALSE);    // 使"播放"按钮操作无效
	GetDlgItem(IDC_STOPWAV)->EnableWindow(true);    // 使"停止"按钮操作生效
	m_MyMCIWave.m_bPlaying = TRUE;//设置播放标志
	m_strstatus = "正在播放……";//播放状态
	CTime m_time;
	m_time=CTime::GetCurrentTime();		//获取当前时间
	CString str=m_time.Format("%H:%M:%S：");		//格式化
	str=str+"开始播放";
	m_List.AddString(str);//添加到列表框
	UpdateData(FALSE);
}

void CMCIWavPlayDlg::OnRecordwav() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_PLAYWAV)->EnableWindow(FALSE);    // 使"播放"按钮操作无效
	GetDlgItem(IDC_OPENWAV)->EnableWindow(FALSE);    // 使"打开"按钮操作无效
	GetDlgItem(IDC_RECORDWAV)->EnableWindow(FALSE);    // 使"录音"按钮操作无效
	GetDlgItem(IDC_STOPWAV)->EnableWindow(true);    // 使"停止"按钮操作生效
	m_strstatus = "正在录音……";        // 构造信息字符串并显示
	CTime m_time;
	m_time=CTime::GetCurrentTime();		
	CString str=m_time.Format("%H:%M:%S：");		//格式化
	str=str+"开始录音";
	m_List.AddString(str);//添加到列表框
	m_strSample=m_strChannel=m_strname=m_strbits=m_strtime="";
	UpdateData(FALSE);
	m_MyMCIWave.RecordWave();                   // 开始录音
}

void CMCIWavPlayDlg::OnSavewav() //保存录制的波形文件
{
	// TODO: Add your control notification handler code here
	CString Filter;
	char buf[128];
	DWORD dwFlag;
	Filter = "Wave Files(*.WAV)|*.WAV||";//过滤器
	CFileDialog fileDlg(FALSE, NULL, NULL, OFN_OVERWRITEPROMPT, Filter);//保存文件对话框
	fileDlg.m_ofn.lpstrDefExt = "wav";
	if (fileDlg.DoModal() ==IDOK)
	{
		dwFlag =m_MyMCIWave.SaveWave(fileDlg.GetPathName());
		if (dwFlag)
		{
			mciGetErrorString(dwFlag, buf, strlen(buf));//获取错误信息
			AfxMessageBox(buf);
			return;
		}
	}
	m_strstatus = "保存结束……";
	CTime m_time;
	m_time=CTime::GetCurrentTime();		
	CString str=m_time.Format("%H:%M:%S：");		//格式化
	str=str+"保存录音文件";
	m_List.AddString(str);//添加到列表框
	UpdateData(FALSE);	
}

void CMCIWavPlayDlg::OnStopwav() //停止播放或录音
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_STOPWAV)->EnableWindow(FALSE);    // 使"停止"按钮操作无效
	GetDlgItem(IDC_PLAYWAV)->EnableWindow(true);    // 使"播放"按钮操作生效
	GetDlgItem(IDC_OPENWAV)->EnableWindow(true);    // 使"打开"按钮操作生效
	GetDlgItem(IDC_RECORDWAV)->EnableWindow(true);    // 使"录音"按钮操作生效
	CTime m_time;
	m_time=CTime::GetCurrentTime();		
	CString str=m_time.Format("%H:%M:%S：");		//格式化
	if (m_MyMCIWave.m_bRecord)//正在录音
	{
		GetDlgItem(IDC_SAVEWAV)->EnableWindow(true);    // 使"保存"按钮操作生效
		m_strstatus = "录音停止……";
		str=str+"录音停止";
		m_List.AddString(str);//添加到列表框
	}
	if (m_MyMCIWave.m_bPlaying)
	{
		m_strstatus = "播放停止……";
		str=str+"播放停止";
		m_List.AddString(str);//添加到列表框
	}
	UpdateData(FALSE);
	m_MyMCIWave.StopWave();//停止	
}
