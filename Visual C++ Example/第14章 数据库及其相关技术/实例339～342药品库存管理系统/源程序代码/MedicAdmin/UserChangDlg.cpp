// UserChangDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MedicAdmin.h"
#include "UserChangDlg.h"
#include "mainFrm.h"
#include "MedicAdminDoc.h"
#include "UserTreeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUserChangDlg dialog


CUserChangDlg::CUserChangDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUserChangDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUserChangDlg)
	m_account = _T("");
	m_password = _T("");
	m_type = _T("");
	//}}AFX_DATA_INIT
}


void CUserChangDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUserChangDlg)
	DDX_Text(pDX, IDC_ACCOUNT_EDIT, m_account);
	DDX_Text(pDX, IDC_PASSWORD_EDIT, m_password);
	DDX_CBString(pDX, IDC_TYPE_COMBO, m_type);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUserChangDlg, CDialog)
	//{{AFX_MSG_MAP(CUserChangDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUserChangDlg message handlers

void CUserChangDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	CMainFrame* theFrm=(CMainFrame*)AfxGetMainWnd();
	CMedicAdminDoc* pDoc=(CMedicAdminDoc*)theFrm->GetActiveDocument();
	CUser* theUser=&pDoc->theUser;
	CUserSet* theUserSet=&pDoc->theUserSet;
	theUserSet->m_strFilter="UserAccount='"+m_account+"' and UserPassword='"
		+m_password+"' and UserClassification='"+m_type+"'";
	theUserSet->Requery();
	if(theUserSet->GetRecordCount())
	{	
		theUser->SetAllMember(m_account,m_password,m_type,"");
		AfxMessageBox("更改用户成功!");
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
	else
	{
		AfxMessageBox("更改用户失败!");
	}
	
	//CUserTreeView* pTreeView=(CUserTreeView*)
	//CDialog::OnOK();
}
