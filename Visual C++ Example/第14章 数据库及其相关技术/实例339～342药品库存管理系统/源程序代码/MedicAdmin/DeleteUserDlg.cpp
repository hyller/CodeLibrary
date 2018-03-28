// DeleteUserDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MedicAdmin.h"
#include "DeleteUserDlg.h"
#include "medicadmindoc.h"
#include "mainFrm.h"
#include "userTreeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDeleteUserDlg dialog


CDeleteUserDlg::CDeleteUserDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDeleteUserDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDeleteUserDlg)
	m_deleteUserAccount = _T("");
	m_deleteUserType = _T("");
	//}}AFX_DATA_INIT
}


void CDeleteUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDeleteUserDlg)
	DDX_Control(pDX, IDC_DELETEUSER_TYPE_COMBO, m_deleteUserTypeCombo);
	DDX_Control(pDX, IDC_LIST1, m_deleteUserList);
	DDX_Text(pDX, IDC_DELETEUSER_ACCOUNT_EDIT, m_deleteUserAccount);
	DDX_CBString(pDX, IDC_DELETEUSER_TYPE_COMBO, m_deleteUserType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDeleteUserDlg, CDialog)
	//{{AFX_MSG_MAP(CDeleteUserDlg)
	ON_CBN_SELCHANGE(IDC_DELETEUSER_TYPE_COMBO, OnSelchangeDeleteuserTypeCombo)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_BN_CLICKED(IDCANCEL, OnExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDeleteUserDlg message handlers

void CDeleteUserDlg::OnSelchangeDeleteuserTypeCombo() 
{
	// TODO: Add your control notification handler code here
	int Item=m_deleteUserTypeCombo.GetCurSel();
	CString str;
	m_deleteUserTypeCombo.GetLBText(Item,str);
	if(str=="所有类型")
	{
		theSet->m_strFilter="";
	}
	else
	{
		theSet->m_strFilter="UserClassification='"+str+"'";
	}
	theSet->Requery();
	m_deleteUserList.DeleteAllItems();
	for(int j=0;;j++)
	{
		if(theSet->IsEOF())
		{
			break;
		}
		m_deleteUserList.InsertItem(j,theSet->m_UserAccount);
		m_deleteUserList.SetItemText(j,1,theSet->m_UserPassword);
		m_deleteUserList.SetItemText(j,2,theSet->m_UserClassification);
		m_deleteUserList.SetItemText(j,3,theSet->m_UserName);
		theSet->MoveNext();
	}

}

BOOL CDeleteUserDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CMedicAdminDoc* pDoc=(CMedicAdminDoc*)((CMainFrame*)AfxGetMainWnd())->GetActiveDocument();
	theSet=&pDoc->theUserSet;
	theSet->m_strFilter="";
	theSet->Requery();
	CString userColumn[]={"用户账号","用户密码","用户类别","用户姓名"};
	for(int i=0;i<4;i++){
		m_deleteUserList.InsertColumn(i,userColumn[i],LVCFMT_LEFT,100,i);
	}
	for(int j=0;;j++)
	{
		if(theSet->IsEOF())
		{
			break;
		}
		m_deleteUserList.InsertItem(j,theSet->m_UserAccount);
		m_deleteUserList.SetItemText(j,1,theSet->m_UserPassword);
		m_deleteUserList.SetItemText(j,2,theSet->m_UserClassification);
		m_deleteUserList.SetItemText(j,3,theSet->m_UserName);
		theSet->MoveNext();
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDeleteUserDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	if(m_deleteUserAccount=="")
	{
		AfxMessageBox("请输入要删除的用户账号");
	}
	else
	{
		int result=AfxMessageBox("确实要删除该用户吗?",MB_OKCANCEL);
		if(result==IDOK)
		{
			CString copyFilter=theSet->m_strFilter;
			CUser* user=new CUser;
			user->SetAccount(m_deleteUserAccount);
			CMedicAdminDoc* pDoc=(CMedicAdminDoc*)((CMainFrame*)AfxGetMainWnd())->GetActiveDocument();
			CUser* theUser=&pDoc->theUser;
			theUser->DeleteUser(user,theSet);
			theSet->m_strFilter=copyFilter;
			theSet->Requery();
			m_deleteUserList.DeleteAllItems();
			for(int j=0;;j++)
			{
				if(theSet->IsEOF())
				{
					break;
				}
				m_deleteUserList.InsertItem(j,theSet->m_UserAccount);
				m_deleteUserList.SetItemText(j,1,theSet->m_UserPassword);
				m_deleteUserList.SetItemText(j,2,theSet->m_UserClassification);
				m_deleteUserList.SetItemText(j,3,theSet->m_UserName);
				theSet->MoveNext();
			}
			m_deleteUserAccount="";
			UpdateData(FALSE);
		}
	}
	//CDialog::OnOK();
}

void CDeleteUserDlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	//AfxMessageBox("fool half");
	*pResult = 0;
}

void CDeleteUserDlg::OnExit() 
{
	// TODO: Add your control notification handler code here
	CMainFrame* theFrm=(CMainFrame*)AfxGetMainWnd();
	CMedicAdminDoc* pDoc=(CMedicAdminDoc*)theFrm->GetActiveDocument();
	CUser* theUser=&pDoc->theUser;
	CUserSet* theUserSet=&pDoc->theUserSet;
	POSITION pos=pDoc->GetFirstViewPosition();
	while(pos != NULL)
	{
		CView* pView=pDoc->GetNextView(pos);
		if(pView->IsKindOf(RUNTIME_CLASS(CUserTreeView)))
		{
			CUserTreeView* pTreeView=(CUserTreeView*)pView;
			CTreeCtrl* m_theTreeCtrl=pTreeView->m_theTreeCtrl;
			m_theTreeCtrl->DeleteAllItems();
			CString userTreeHeader[3]={"医生","售药员","管理员"};
			HTREEITEM userItem[3];
			for(int i=0;i<3;i++)
			{
				userItem[i]=m_theTreeCtrl->InsertItem(userTreeHeader[i],0,0,TVI_ROOT);
				m_theTreeCtrl->SetItemData(userItem[i],(DWORD)i);
			}
			HTREEITEM thePoint;
			for(i=0;i<3;i++)
			{
				theUserSet->m_strFilter="UserClassification='"+userTreeHeader[i]+"'";
				theUserSet->Requery();
				for(int j=0;;j++)
				{
					if(theUserSet->IsEOF())
					{
						break;
					}	
					if(theUserSet->m_UserAccount==theUser->GetAccount())
					{
						HTREEITEM userSpecifics=m_theTreeCtrl->InsertItem(theUserSet->m_UserAccount+"(当前用户)",2,2,userItem[i]);
						m_theTreeCtrl->SetItemData(userSpecifics,(DWORD)j);
						thePoint=userSpecifics;
					}
					else
					{
						HTREEITEM userSpecifics=m_theTreeCtrl->InsertItem(theUserSet->m_UserAccount,3,3,userItem[i]);
						m_theTreeCtrl->SetItemData(userSpecifics,(DWORD)j);
					}
					theUserSet->MoveNext();
				}
			}
			m_theTreeCtrl->Select(thePoint,TVGN_CARET);
			break;
		}
	}
	CDialog::OnOK();
}
