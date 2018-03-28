// UserTree.cpp : implementation file
//

#include "stdafx.h"
#include "MedicAdmin.h"
#include "UserTreeView.h"
#include "MedicAdminDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUserTree

IMPLEMENT_DYNCREATE(CUserTree, CTreeView)

CUserTree::CUserTree()
{
}

CUserTree::~CUserTree()
{
}


BEGIN_MESSAGE_MAP(CUserTree, CTreeView)
	//{{AFX_MSG_MAP(CUserTree)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUserTree drawing

void CUserTree::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CUserTree diagnostics

#ifdef _DEBUG
void CUserTree::AssertValid() const
{
	CTreeView::AssertValid();
}

void CUserTree::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CUserTree message handlers

BOOL CUserTree::PreCreateWindow(CREATESTRUCT& cs) 
{
	// TODO: Add your specialized code here and/or call the base class
	cs.style |= TVS_HASBUTTONS | TVS_HASLINES | TVS_LINESATROOT;
	return CTreeView::PreCreateWindow(cs);
}

int CUserTree::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CTreeView::OnCreate(lpCreateStruct) == -1)
		return -1;
	m_theTreeCtrl=&GetTreeCtrl();
	//CMedicAdminDoc* pDoc=(CMedicAdminDoc*)GetDocument();
	//pDoc->SetData();
	CString userHeader[3]={"医生","售药员","管理员"};
	HTREEITEM user[3];
	for(int i=0;i<3;i++)
	{
		user[i]=m_theTreeCtrl->InsertItem(userHeader[i],0,0,TVI_ROOT);
		m_theTreeCtrl-
	}
	
	// TODO: Add your specialized creation code here*/
	
	return 0;
}


