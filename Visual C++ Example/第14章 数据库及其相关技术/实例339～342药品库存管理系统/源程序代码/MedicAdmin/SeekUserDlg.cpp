// SeekUserDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MedicAdmin.h"
#include "SeekUserDlg.h"
#include "MedicAdminDoc.h"
#include "mainfrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSeekUserDlg dialog


CSeekUserDlg::CSeekUserDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSeekUserDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSeekUserDlg)
	m_account = _T("");
	m_type = _T("");
	m_typeRadio = -1;
	//}}AFX_DATA_INIT
}


void CSeekUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSeekUserDlg)
	DDX_Control(pDX, IDC_LIST1, m_seekList);
	DDX_Text(pDX, IDC_SEEKUSER_ACCOUNT_EDIT, m_account);
	DDX_CBString(pDX, IDC_SEEKUSER_TYPE_COMBO, m_type);
	DDX_Radio(pDX, IDC_TYPE_RADIO, m_typeRadio);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSeekUserDlg, CDialog)
	//{{AFX_MSG_MAP(CSeekUserDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSeekUserDlg message handlers

BOOL CSeekUserDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_typeRadio=0;
	UpdateData(FALSE);
	
	// TODO: Add extra initialization here
	CMedicAdminDoc* pDoc=(CMedicAdminDoc*)((CMainFrame*)AfxGetMainWnd())->GetActiveDocument();
	theSet=&pDoc->theUserSet;
	theSet->m_strFilter="";
	theSet->Requery();
	CString userColumn[]={"用户账号","用户密码","用户类别","用户姓名"};
	for(int i=0;i<4;i++){
		m_seekList.InsertColumn(i,userColumn[i],LVCFMT_LEFT,100,i);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSeekUserDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	CMedicAdminDoc* pDoc=(CMedicAdminDoc*)((CMainFrame*)AfxGetMainWnd())->GetActiveDocument();
	CUser* theUser=&pDoc->theUser;
	CString str;
	if(m_typeRadio==0)
	{
		str=m_type;
	}
	else
	{
		str=m_account;
	}
	theUser->SeekUserInfo(m_typeRadio,str,theSet);
	m_seekList.DeleteAllItems();
	for(int j=0;;j++)
	{
		if(theSet->IsEOF())
		{
			break;
		}
		m_seekList.InsertItem(j,theSet->m_UserAccount);
		m_seekList.SetItemText(j,1,"*****");
		m_seekList.SetItemText(j,2,theSet->m_UserClassification);
		m_seekList.SetItemText(j,3,theSet->m_UserName);
		theSet->MoveNext();
	}
	//CDialog::OnOK();
}
