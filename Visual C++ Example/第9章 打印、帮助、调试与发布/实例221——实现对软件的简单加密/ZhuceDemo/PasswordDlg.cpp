// PasswordDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ZhuceDemo.h"
#include "PasswordDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPasswordDlg dialog


CPasswordDlg::CPasswordDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPasswordDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPasswordDlg)
	m_usernum = 0;
	m_serialnum = 0;
	//}}AFX_DATA_INIT
}


void CPasswordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPasswordDlg)
	DDX_Text(pDX, IDC_EDIT1, m_usernum);
	DDX_Text(pDX, IDC_EDIT2, m_serialnum);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPasswordDlg, CDialog)
	//{{AFX_MSG_MAP(CPasswordDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPasswordDlg message handlers

BOOL CPasswordDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//获得c盘序列号
	DWORD VolumeSerialNumber;
	GetVolumeInformation("c:\\",NULL,12,&VolumeSerialNumber,NULL,NULL,NULL,10);
	VolumeSerialNumber^=0x12345678;//本机c盘序列号简单运算
	m_usernum=VolumeSerialNumber;
	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPasswordDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(true);
	DWORD num;
	num=m_usernum;
	num^=0x1999aa98+12;//加密算法
	if(!(num==m_serialnum))
	{
		AfxMessageBox("输入的序列号不正确！");
			return;
	}
	CDialog::OnOK();
}
