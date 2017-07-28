// UserTreeView.cpp : implementation file
//

#include "stdafx.h"
#include "MedicAdmin.h"
#include "UserTreeView.h"
#include "MedicAdminDoc.h"
#include "LogInDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUserTreeView

IMPLEMENT_DYNCREATE(CUserTreeView, CTreeView)

CUserTreeView::CUserTreeView()
{
}

CUserTreeView::~CUserTreeView()
{
}


BEGIN_MESSAGE_MAP(CUserTreeView, CTreeView)
	//{{AFX_MSG_MAP(CUserTreeView)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUserTreeView drawing

void CUserTreeView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CUserTreeView diagnostics

#ifdef _DEBUG
void CUserTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CUserTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CUserTreeView message handlers

BOOL CUserTreeView::PreCreateWindow(CREATESTRUCT& cs) 
{
	// TODO: Add your specialized code here and/or call the base class
	cs.style |= TVS_HASBUTTONS | TVS_HASLINES | TVS_LINESATROOT;
	return CTreeView::PreCreateWindow(cs);
}

int CUserTreeView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CTreeView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	
	
	
	return 0;
}

void CUserTreeView::OnInitialUpdate() 
{
	CTreeView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	m_theTreeCtrl=&GetTreeCtrl();
	m_theImageList.Create(IDB_TREE_BITMAP,16,1,RGB(0,255,0));
	m_theTreeCtrl->SetImageList(&m_theImageList,TVSIL_NORMAL);
	CString userTreeHeader[3]={"医生","售药员","管理员"};
	HTREEITEM userItem[3];
	for(int i=0;i<3;i++)
	{
		userItem[i]=m_theTreeCtrl->InsertItem(userTreeHeader[i],0,0,TVI_ROOT);
		m_theTreeCtrl->SetItemData(userItem[i],(DWORD)i);
	}
	CMedicAdminDoc* pDoc=(CMedicAdminDoc*)GetDocument();
	CUserSet* userSet=&pDoc->theUserSet;
	if(userSet->IsOpen())
	{
		userSet->Close();
	}
	userSet->Open();
	
	CLogInDlg logInDlg;//登录对话框
	logInDlg.DoModal();
	
	CUser* theUser=&pDoc->theUser;
	HTREEITEM thePoint;
	for(i=0;i<3;i++)
	{
		userSet->m_strFilter="UserClassification='"+userTreeHeader[i]+"'";
		userSet->Requery();
		for(int j=0;;j++)
		{
			if(userSet->IsEOF())
			{
				break;
			}	
			if(userSet->m_UserAccount==theUser->GetAccount())
			{
				HTREEITEM userSpecifics=m_theTreeCtrl->InsertItem(userSet->m_UserAccount+"(当前用户)",2,2,userItem[i]);
				m_theTreeCtrl->SetItemData(userSpecifics,(DWORD)j);
				thePoint=userSpecifics;
			}
			else
			{
				HTREEITEM userSpecifics=m_theTreeCtrl->InsertItem(userSet->m_UserAccount,3,3,userItem[i]);
				m_theTreeCtrl->SetItemData(userSpecifics,(DWORD)j);
			}
			userSet->MoveNext();
		}
	}
	m_theTreeCtrl->Select(thePoint,TVGN_CARET);
}
