// EnumDeviceInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "EnumDeviceInfo.h"
#include "EnumDeviceInfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include <setupapi.h>
#pragma comment(lib,"Setupapi.lib")
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
// CEnumDeviceInfoDlg dialog

CEnumDeviceInfoDlg::CEnumDeviceInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEnumDeviceInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEnumDeviceInfoDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEnumDeviceInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEnumDeviceInfoDlg)
	DDX_Control(pDX, IDC_LIST1, m_ctlList);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CEnumDeviceInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CEnumDeviceInfoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_GETDEVICE, OnGetdevice)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEnumDeviceInfoDlg message handlers

BOOL CEnumDeviceInfoDlg::OnInitDialog()
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

void CEnumDeviceInfoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CEnumDeviceInfoDlg::OnPaint() 
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
HCURSOR CEnumDeviceInfoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CEnumDeviceInfoDlg::OnGetdevice() 
{
	// TODO: Add your control notification handler code here
	m_ctlList.ResetContent();	
    HDEVINFO hDevInfo;
    SP_DEVINFO_DATA DeviceInfoData;
    DWORD i;	
    // 获取系统当前所有的硬件设备集
    hDevInfo = SetupDiGetClassDevs(	NULL,  
									0, // HKLM\SYSTEM\CurrentControlSet\Enum
									0,
									DIGCF_PRESENT | DIGCF_ALLCLASSES );
    
    if (hDevInfo == INVALID_HANDLE_VALUE)
    {
        AfxMessageBox("获取设备失败！");
        return ;
    } 
    //枚举所有的硬件设备
    DeviceInfoData.cbSize = sizeof(SP_DEVINFO_DATA);
    for (i=0;SetupDiEnumDeviceInfo(hDevInfo,i,  &DeviceInfoData);i++)
    {
        DWORD DataT;
        LPTSTR buffer = NULL;
        DWORD buffersize = 0;   
        while (!SetupDiGetDeviceRegistryProperty(   hDevInfo,
													&DeviceInfoData,
													SPDRP_DEVICEDESC,
													&DataT,
													(PBYTE)buffer,
													buffersize,
													&buffersize))
        {
            if (GetLastError() ==  ERROR_INSUFFICIENT_BUFFER)
            {
                //改变缓冲区大小
                if (buffer) 
					LocalFree(buffer);
                buffer = (char*)LocalAlloc(LPTR,buffersize);
            }
        }	
		m_ctlList.AddString(buffer);//添加到列表框
        if (buffer) 
			LocalFree(buffer);
    }
    SetupDiDestroyDeviceInfoList(hDevInfo);  // 清理	
}
