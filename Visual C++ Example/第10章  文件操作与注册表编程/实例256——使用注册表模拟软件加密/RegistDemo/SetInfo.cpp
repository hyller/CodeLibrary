// SetInfo.cpp : implementation file
//

#include "stdafx.h"
#include "RegistDemo.h"
#include "SetInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetInfo dialog


CSetInfo::CSetInfo(CWnd* pParent /*=NULL*/)
	: CDialog(CSetInfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetInfo)
	m_conpass = _T("");
	m_password = _T("");
	m_user = _T("");
	//}}AFX_DATA_INIT
	bSetInfo=false;
}


void CSetInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetInfo)
	DDX_Text(pDX, IDC_CONPASS, m_conpass);
	DDX_Text(pDX, IDC_PASS, m_password);
	DDX_Text(pDX, IDC_USER, m_user);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetInfo, CDialog)
	//{{AFX_MSG_MAP(CSetInfo)
	ON_BN_CLICKED(ID_APPLY, OnApply)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetInfo message handlers

void CSetInfo::OnApply() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);//获取对话框数据
	if(m_conpass!=m_password)//校验两次输入的密码
	{
		AfxMessageBox("请重新输入密码！");
		m_conpass = _T("");
		m_password = _T("");
		UpdateData(false);
			return;
	}
	bSetInfo=true;//用户设置密码成功
	CDialog::OnOK();
}
