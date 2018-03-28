// CheckDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RegistDemo.h"
#include "CheckDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCheckDlg dialog


CCheckDlg::CCheckDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCheckDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCheckDlg)
	m_username = _T("");
	m_password = _T("");
	//}}AFX_DATA_INIT
}


void CCheckDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCheckDlg)
	DDX_Text(pDX, IDC_USER, m_username);
	DDX_Text(pDX, IDC_PASSWORD, m_password);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCheckDlg, CDialog)
	//{{AFX_MSG_MAP(CCheckDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCheckDlg message handlers

void CCheckDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(true);
	if(!((m_username==username)&&(m_password==password)))//判断用户名、密码
	{
		AfxMessageBox("用户名密码错误，请重新输入！");
		m_password=_T("");//密码清空
		UpdateData(false);
	}
	else
	{
		CDialog::OnOK();//退出对话框
	}	
	
}
void CCheckDlg::GetPassword(CString pass)//获取存储的密码
{
	password=pass;
}
void CCheckDlg::GetUsername(CString user)//获取存储的用户名
{
	username=user;
}
