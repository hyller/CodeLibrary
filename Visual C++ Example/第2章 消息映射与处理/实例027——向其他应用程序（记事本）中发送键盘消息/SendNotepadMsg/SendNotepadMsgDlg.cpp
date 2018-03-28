// SendNotepadMsgDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SendNotepadMsg.h"
#include "SendNotepadMsgDlg.h"

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
// CSendNotepadMsgDlg dialog

CSendNotepadMsgDlg::CSendNotepadMsgDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSendNotepadMsgDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSendNotepadMsgDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSendNotepadMsgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSendNotepadMsgDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSendNotepadMsgDlg, CDialog)
	//{{AFX_MSG_MAP(CSendNotepadMsgDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SEND, OnSend)
	ON_BN_CLICKED(IDC_SAVE, OnSave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSendNotepadMsgDlg message handlers

BOOL CSendNotepadMsgDlg::OnInitDialog()
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

void CSendNotepadMsgDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSendNotepadMsgDlg::OnPaint() 
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
HCURSOR CSendNotepadMsgDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSendNotepadMsgDlg::OnSend() //发送字符串
{
	// TODO: Add your control notification handler code here
	HWND hWnd = ::FindWindow("Notepad", NULL);
	if(hWnd)
	{
		HWND hEdit = FindWindowEx(hWnd, NULL, "Edit", NULL);
		if(hEdit)
		::PostMessage(hEdit, WM_CHAR, 0x48, 0);//发送‘H’到notepad
		::PostMessage(hEdit, WM_CHAR, 0x45, 0);//发送‘E’到notepad
		::PostMessage(hEdit, WM_CHAR, 0x4C, 0);//发送‘L’到notepad
		::PostMessage(hEdit, WM_CHAR, 0x4C, 0);//发送‘L’到notepad
		::PostMessage(hEdit, WM_CHAR, 0x4F, 0);//发送‘O’到notepad
	} 
	else
	{
		AfxMessageBox("请打开记事本文件！");
		return;
	}	
}

void CSendNotepadMsgDlg::OnSave() //保存文件
{
	// TODO: Add your control notification handler code here
	
	CWnd* pWnd =FindWindow("Notepad", NULL);
	if (pWnd->GetSafeHwnd())
	{
		pWnd->ShowWindow(SW_NORMAL);
		pWnd->SetForegroundWindow();
		keybd_event(VK_CONTROL, 0, 0, 0);//按下Ctrl键
		keybd_event('S', 0, 0, 0);//按下S键
		keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);//释放Ctrl键
		keybd_event('S', 0, KEYEVENTF_KEYUP, 0);//释放S键
	}
	else
	{
		AfxMessageBox("未找到打开的记事本文件！");
		return;
	}	
}
