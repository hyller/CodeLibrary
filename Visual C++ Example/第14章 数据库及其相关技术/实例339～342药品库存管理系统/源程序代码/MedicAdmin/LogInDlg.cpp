// LogInDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MedicAdmin.h"
#include "LogInDlg.h"
#include "medicAdminDoc.h"
#include "mainfrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLogInDlg dialog


CLogInDlg::CLogInDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLogInDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLogInDlg)
	m_userAccount = _T("");
	m_userPassword = _T("");
	m_userType = _T("");
	//}}AFX_DATA_INIT
}


void CLogInDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLogInDlg)
	DDX_Text(pDX, IDC_ACCOUNT_EDIT, m_userAccount);
	DDX_Text(pDX, IDC_PASSWORD_EDIT, m_userPassword);
	DDX_CBString(pDX, IDC_TYPE_COMBO, m_userType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLogInDlg, CDialog)
	//{{AFX_MSG_MAP(CLogInDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLogInDlg message handlers

void CLogInDlg::OnOK() 
{
	// TODO: Add extra validation here
	CMedicAdminDoc* pDoc=(CMedicAdminDoc*)((CMainFrame*)AfxGetMainWnd())->GetActiveDocument();
	UpdateData(TRUE);
	pDoc->theUser.SetAllMember(m_userAccount,m_userPassword,m_userType,"");
	CUserSet* theUserSet=&pDoc->theUserSet;
	BOOL flag=pDoc->theUser.LogIn(theUserSet);
	if(flag)
	{
		CDialog::OnOK();
	}
	else
	{
		AfxMessageBox("您无权进入该系统");
		ExitProcess(1);
		//CDialog::OnOK();
	}
}

void CLogInDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	ExitProcess(2);
	//CDialog::OnCancel();
}
