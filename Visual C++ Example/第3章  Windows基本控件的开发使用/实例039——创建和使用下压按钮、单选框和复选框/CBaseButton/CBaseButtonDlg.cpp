// CBaseButtonDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CBaseButton.h"
#include "CBaseButtonDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCBaseButtonDlg dialog

CCBaseButtonDlg::CCBaseButtonDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCBaseButtonDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCBaseButtonDlg)
	m_radio = 1;							//默认选择为1G
	m_show = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCBaseButtonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCBaseButtonDlg)
	DDX_Control(pDX, IDC_CHECK4, m_check4);
	DDX_Control(pDX, IDC_CHECK3, m_check3);
	DDX_Control(pDX, IDC_CHECK2, m_check2);
	DDX_Control(pDX, IDC_CHECK1, m_check1);
	DDX_Radio(pDX, IDC_RADIO1, m_radio);
	DDX_Text(pDX, IDC_STATICSHOW, m_show);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCBaseButtonDlg, CDialog)
	//{{AFX_MSG_MAP(CCBaseButtonDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_CHECKIN, OnCheckin)
	ON_BN_CLICKED(ID_RESET, OnReset)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCBaseButtonDlg message handlers

BOOL CCBaseButtonDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	GetDlgItem(ID_RESET)->EnableWindow(false);				//重新选择按钮无效
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCBaseButtonDlg::OnPaint() 
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
HCURSOR CCBaseButtonDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCBaseButtonDlg::OnCheckin() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(ID_RESET)->EnableWindow(true);				//重新选择有效
	GetDlgItem(ID_CHECKIN)->EnableWindow(false);				//提交按钮无效
	UpdateData(true);
	m_show="内存: "; 								//保存输出消息字符串
	CString str;
	switch(m_radio)
	{
		case 0:											//该组第一个单选项被选中
			GetDlgItemText(IDC_RADIO1,str);
			m_show=m_show+str;
			break;
		case 1:											//该组第二个单选项被选中
			GetDlgItemText(IDC_RADIO2,str);
			m_show=m_show+str;
			break;
		case 2:											//该组第三个单选项被选中
			GetDlgItemText(IDC_RADIO3,str);
			m_show=m_show+str;
			break;
		
	}
	if(m_check1.GetCheck()==1)							//复选框1被选中
	{
		GetDlgItemText(IDC_CHECK1,str);
		m_show=m_show+str;

	}

	if(m_check2.GetCheck()==1)							//复选框2被选中
	{
		GetDlgItemText(IDC_CHECK2,str);
		m_show=m_show+str;
	}
	if(m_check3.GetCheck()==1)							//复选框3被选中
	{
		GetDlgItemText(IDC_CHECK3,str);
		m_show=m_show+str;
	}
	if(m_check4.GetCheck()==1)							//复选框4被选中
	{
		GetDlgItemText(IDC_CHECK4,str);
		m_show=m_show+str;
	}
	UpdateData(false);

	
}

void CCBaseButtonDlg::OnReset() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(ID_RESET)->EnableWindow(false);				//重新选择按钮无效
	GetDlgItem(ID_CHECKIN)->EnableWindow(true);				//提交选择按钮有效
	m_radio=1;											//单选框的默认值
	m_check1.SetCheck(0);								//复选框1不选中
	m_check2.SetCheck(0);								//复选框2不选中
	m_check3.SetCheck(0);								//复选框3不选中
	m_check4.SetCheck(0);								//复选框4不选中
	m_show="";
	UpdateData(false);

	
}
