// EnalbeMenuItemView.cpp : implementation of the CEnalbeMenuItemView class
//

#include "stdafx.h"
#include "EnalbeMenuItem.h"

#include "EnalbeMenuItemDoc.h"
#include "EnalbeMenuItemView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEnalbeMenuItemView

IMPLEMENT_DYNCREATE(CEnalbeMenuItemView, CView)

BEGIN_MESSAGE_MAP(CEnalbeMenuItemView, CView)
	//{{AFX_MSG_MAP(CEnalbeMenuItemView)
	ON_COMMAND(ID_MENURUN, OnMenurun)
	ON_COMMAND(ID_MENUPAUSE, OnMenupause)
	ON_UPDATE_COMMAND_UI(ID_MENUPAUSE, OnUpdateMenupause)
	ON_UPDATE_COMMAND_UI(ID_MENURUN, OnUpdateMenurun)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEnalbeMenuItemView construction/destruction

CEnalbeMenuItemView::CEnalbeMenuItemView()
{
	// TODO: add construction code here
	m_bvisible=true;

}

CEnalbeMenuItemView::~CEnalbeMenuItemView()
{
}

BOOL CEnalbeMenuItemView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEnalbeMenuItemView drawing

void CEnalbeMenuItemView::OnDraw(CDC* pDC)
{
	CEnalbeMenuItemDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CEnalbeMenuItemView printing

BOOL CEnalbeMenuItemView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEnalbeMenuItemView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEnalbeMenuItemView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEnalbeMenuItemView diagnostics

#ifdef _DEBUG
void CEnalbeMenuItemView::AssertValid() const
{
	CView::AssertValid();
}

void CEnalbeMenuItemView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEnalbeMenuItemDoc* CEnalbeMenuItemView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEnalbeMenuItemDoc)));
	return (CEnalbeMenuItemDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEnalbeMenuItemView message handlers

void CEnalbeMenuItemView::OnMenurun() //执行菜单命令
{
	// TODO: Add your command handler code here
	CClientDC dc(this);												//获得DC
	dc.TextOut(30,40,"执行菜单项响应成功!");//输出文本
	m_bvisible=false;

	
}

void CEnalbeMenuItemView::OnMenupause() //暂停菜单命令
{
	// TODO: Add your command handler code here
	CClientDC dc(this);												//获得DC
	dc.TextOut(30,40,"暂停菜单项响应成功!");//输出文本
	m_bvisible=true;
	
}

void CEnalbeMenuItemView::OnUpdateMenupause(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(!m_bvisible);
	
}

void CEnalbeMenuItemView::OnUpdateMenurun(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_bvisible);
	
}
