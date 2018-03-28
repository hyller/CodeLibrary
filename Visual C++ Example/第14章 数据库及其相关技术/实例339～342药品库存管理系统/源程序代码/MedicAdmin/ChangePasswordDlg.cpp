// ChangePasswordDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MedicAdmin.h"
#include "ChangePasswordDlg.h"
#include "MainFrm.h"
#include "MedicAdminDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChangePasswordDlg dialog


CChangePasswordDlg::CChangePasswordDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChangePasswordDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChangePasswordDlg)
	m_account = _T("");
	m_password = _T("");
	m_password2 = _T("");
	m_oldPassword = _T("");
	//}}AFX_DATA_INIT
}


void CChangePasswordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChangePasswordDlg)
	DDX_Text(pDX, IDC_ACCOUNT_EDIT, m_account);
	DDX_Text(pDX, IDC_NEW_PASSWORD_EDIT, m_password);
	DDX_Text(pDX, IDC_NEW_PASSWORD2_EDIT, m_password2);
	DDX_Text(pDX, IDC_OLD_PASSWORD_EDIT, m_oldPassword);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CChangePasswordDlg, CDialog)
	//{{AFX_MSG_MAP(CChangePasswordDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChangePasswordDlg message handlers

void CChangePasswordDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	CMainFrame* theFrm=(CMainFrame*)AfxGetMainWnd();
	CMedicAdminDoc* pDoc=(CMedicAdminDoc*)theFrm->GetActiveDocument();
	CUser* theUser=&pDoc->theUser;
	CUserSet* theSet=&pDoc->theUserSet;
	theSet->m_strFilter="UserAccount='"+theUser->GetAccount()+"'";
	theSet->Requery();
	if(m_oldPassword==theUser->GetPassword())
	{
		if((m_password==m_password2)&&(m_password != ""))
		{
			
			theUser->SetPassword(m_password);
			theUser->ModifyPassword(theSet);
			AfxMessageBox("修改密码成功!");
			CDialog::OnOK();
		}
		else if(m_password == "")
		{
			AfxMessageBox("请输入新密码!");
		}
		else
		{
			AfxMessageBox("两次输入的密码不匹配!");
			m_password="";
			m_password2="";
			UpdateData(FALSE);
		}
	}
	else
	{
		AfxMessageBox("输入的密码不正确，您无权修改密码!");
		m_oldPassword="";
		m_password="";
		m_password2="";
		UpdateData(FALSE);
	}
}
