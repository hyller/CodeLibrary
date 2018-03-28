// RegisterUserDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MedicAdmin.h"
#include "RegisterUserDlg.h"
#include "medicAdminDoc.h"
#include "mainfrm.h"
#include "UserTreeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRegisterUserDlg dialog


CRegisterUserDlg::CRegisterUserDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRegisterUserDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRegisterUserDlg)
	m_registerUserAccount = _T("");
	m_registerUserName = _T("");
	m_registerUserPassword = _T("");
	m_registerUserPassword2 = _T("");
	m_registerUserType = _T("");
	//}}AFX_DATA_INIT
}


void CRegisterUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRegisterUserDlg)
	DDX_Control(pDX, IDC_LIST1, m_registerUserList);
	DDX_Text(pDX, IDC_NEWUSER_ACCOUNT_EDIT, m_registerUserAccount);
	DDX_Text(pDX, IDC_NEWUSER_NAME_EDIT, m_registerUserName);
	DDX_Text(pDX, IDC_NEWUSER_PASSWORD1_EDIT, m_registerUserPassword);
	DDX_Text(pDX, IDC_NEWUSER_PASSWORD2_EDIT, m_registerUserPassword2);
	DDX_CBString(pDX, IDC_NEWUSER_TYPE_COMBO, m_registerUserType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRegisterUserDlg, CDialog)
	//{{AFX_MSG_MAP(CRegisterUserDlg)
	ON_BN_CLICKED(IDOK2, OnOk2)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRegisterUserDlg message handlers

BOOL CRegisterUserDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CMedicAdminDoc* pDoc=(CMedicAdminDoc*)((CMainFrame*)AfxGetMainWnd())->GetActiveDocument();
	theSet=&pDoc->theUserSet;
	theSet->m_strFilter="";
	theSet->Requery();
	
	// TODO: Add extra initialization here
	CString userColumn[]={"用户账号","用户密码","用户类别","用户姓名"};
	for(int i=0;i<4;i++){
		m_registerUserList.InsertColumn(i,userColumn[i],LVCFMT_LEFT,100,i);
	}
	for(int j=0;;j++)
	{
		if(theSet->IsEOF())
		{
			break;
		}
		m_registerUserList.InsertItem(j,theSet->m_UserAccount);
		m_registerUserList.SetItemText(j,1,theSet->m_UserPassword);
		m_registerUserList.SetItemText(j,2,theSet->m_UserClassification);
		m_registerUserList.SetItemText(j,3,theSet->m_UserName);
		theSet->MoveNext();
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CRegisterUserDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	if(m_registerUserAccount=="")
	{
		AfxMessageBox("用户账号不能为空");
	}
	else if(m_registerUserPassword != m_registerUserPassword2)
	{
		AfxMessageBox("两次输入的密码不匹配");
	}
	else if(m_registerUserPassword == "")
	{
		AfxMessageBox("为保密起见,请输入密码");
	}
	else if(m_registerUserType=="")
	{
		AfxMessageBox("请选择用户的类别");
	}
	else
	{
		CUser* newUser=new CUser;
		newUser->SetAllMember(m_registerUserAccount,m_registerUserPassword,m_registerUserType,m_registerUserName);
		CMedicAdminDoc* pDoc=(CMedicAdminDoc*)((CMainFrame*)AfxGetMainWnd())->GetActiveDocument();
		CUser* theUser=&pDoc->theUser;
		if(theUser->AddNewUser(newUser,theSet))
		{
			int number=m_registerUserList.GetItemCount();
			m_registerUserList.InsertItem(number,m_registerUserAccount);
			m_registerUserList.SetItemText(number,1,m_registerUserPassword);
			m_registerUserList.SetItemText(number,2,m_registerUserType);
			m_registerUserList.SetItemText(number,3,m_registerUserName);
		}
		m_registerUserAccount="";
		m_registerUserPassword="";
		m_registerUserPassword2="";
		m_registerUserType="";
		m_registerUserName="";
		UpdateData(FALSE);
	}
	//CDialog::OnOK();
}

void CRegisterUserDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	m_registerUserAccount="";
	m_registerUserName="";
	m_registerUserPassword="";
	m_registerUserPassword2="";
	m_registerUserType="";
	UpdateData(FALSE);
	//CDialog::OnCancel();
}

void CRegisterUserDlg::OnOk2() 
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

void CRegisterUserDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	//DestroyWindow();
	//CDialog::OnClose();
	CDialog::OnOK();
}
