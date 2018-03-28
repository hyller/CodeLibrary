// ShowChangeFBLDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ShowChangeFBL.h"
#include "ShowChangeFBLDlg.h"

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
// CShowChangeFBLDlg dialog

CShowChangeFBLDlg::CShowChangeFBLDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CShowChangeFBLDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CShowChangeFBLDlg)
	m_strCurcolor = _T("");
	m_strCurdif = _T("");
	m_strCurrefresh = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CShowChangeFBLDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CShowChangeFBLDlg)
	DDX_Control(pDX, IDC_COMBO3, m_ctlCombo3);
	DDX_Control(pDX, IDC_COMBO2, m_ctlCombo2);
	DDX_Control(pDX, IDC_COMBO1, m_ctlCombo1);
	DDX_Text(pDX, IDC_EDIT1, m_strCurcolor);
	DDX_Text(pDX, IDC_EDIT2, m_strCurdif);
	DDX_Text(pDX, IDC_EDIT3, m_strCurrefresh);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CShowChangeFBLDlg, CDialog)
	//{{AFX_MSG_MAP(CShowChangeFBLDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SET, OnSet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowChangeFBLDlg message handlers

BOOL CShowChangeFBLDlg::OnInitDialog()
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
	LPDEVMODE gpCurrentMode; 
	gpCurrentMode = new DEVMODE; 
	EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, gpCurrentMode);//获取显示属性 
	gpCurrentMode->dmFields = DM_BITSPERPEL | DM_PELSWIDTH | 
		DM_PELSHEIGHT | DM_DISPLAYFLAGS | DM_DISPLAYFREQUENCY ; //设置屏蔽位
	//格式化字符串
	m_strCurcolor.Format("%d",gpCurrentMode->dmBitsPerPel);
	m_strCurdif.Format("%d * %d",gpCurrentMode->dmPelsWidth,gpCurrentMode->dmPelsHeight);
	m_strCurrefresh.Format("%d",gpCurrentMode->dmDisplayFrequency);
	UpdateData(false);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CShowChangeFBLDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CShowChangeFBLDlg::OnPaint() 
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
HCURSOR CShowChangeFBLDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CShowChangeFBLDlg::OnSet() 
{
	// TODO: Add your control notification handler code here
	CString newDifferency,newFrequency,newColorMode;
	m_ctlCombo1.GetWindowText(newColorMode);//获取颜色组合框的值
	m_ctlCombo2.GetWindowText(newDifferency);//获取分辨率组合框的值
	m_ctlCombo3.GetWindowText(newFrequency);//获取刷新频率组合框的值
	//判断组合框是否为空
	if(newColorMode=="" ||newDifferency==""||newFrequency=="")
	{
		AfxMessageBox("设置不正确，请确认！");
		return ;
	}
	int difwidth,difheight,colormode,frequency;
	int pos=newDifferency.Find("*",0);//将下拉框中的字符型分辨率装换为整型
	//取出*号后面的字符串，并且将字符串用atoi转换成整型
	difheight=atoi(newDifferency.Mid(pos+1));
	//在*号处结束字符串，以便得到*号前面的字符串
	newDifferency.SetAt(pos,'\0');
	difwidth=atoi(newDifferency);
	//将下拉框中的字符型颜色类型装换为整型
	int len=newColorMode.GetLength();
	char str[6];
	int j=0;
	for(int i=0;i<+len;i++)
	{
		char ctemp;
		ctemp=newColorMode.GetAt(i);
		if(ctemp>='0'&&ctemp<='9')//如果取出的字符是数字
		{
			str[j]=ctemp;
			j++;
		}
	}
	colormode=atoi(str);	
	frequency=atoi(newFrequency);//将下拉框中的刷新频率类型装换为整型
	LPDEVMODE gpCurrentMode,gpNewMode; 
	gpCurrentMode = new DEVMODE; 
	EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, gpCurrentMode); 
	gpCurrentMode->dmFields = DM_BITSPERPEL | DM_PELSWIDTH | 
		DM_PELSHEIGHT | DM_DISPLAYFLAGS | DM_DISPLAYFREQUENCY ; 
	gpCurrentMode->dmBitsPerPel = colormode;//颜色位 
	gpCurrentMode->dmPelsWidth = difwidth;//水平分辩率 
	gpCurrentMode->dmPelsHeight = difheight;//垂直分辨率
	gpCurrentMode->dmDisplayFrequency = frequency;//刷新频率
	if ((DM_BITSPERPEL & gpCurrentMode->dmFields || 
		DM_PELSWIDTH & gpCurrentMode->dmFields || 
		DM_PELSHEIGHT & gpCurrentMode->dmFields || 
		DM_DISPLAYFLAGS & gpCurrentMode->dmFields || 
		DM_DISPLAYFREQUENCY & gpCurrentMode->dmFields ) ) 
	{ 
		gpNewMode = gpCurrentMode; 
		LONG lResult = ChangeDisplaySettings ( gpNewMode, CDS_TEST ); 
		if (lResult == DISP_CHANGE_RESTART) 
		{ 
			AfxMessageBox("该模式需要重启计算机，本实例不支持！"); 
		} 
		if (DISP_CHANGE_SUCCESSFUL ==lResult) 
		{ 	
			lResult =ChangeDisplaySettings ( gpCurrentMode, 0 ); //改变显示
		}
		else
		{
		  AfxMessageBox("不能改变系统显示属性！");
		}
	}	
}
