// BaseMenuDemoView.cpp : implementation of the CBaseMenuDemoView class
//

#include "stdafx.h"
#include "BaseMenuDemo.h"

#include "BaseMenuDemoDoc.h"
#include "BaseMenuDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBaseMenuDemoView

IMPLEMENT_DYNCREATE(CBaseMenuDemoView, CView)

BEGIN_MESSAGE_MAP(CBaseMenuDemoView, CView)
	//{{AFX_MSG_MAP(CBaseMenuDemoView)
	ON_COMMAND(ID_MENURUN, OnMenurun)
	ON_COMMAND(ID_MENUPAUSE, OnMenupause)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBaseMenuDemoView construction/destruction

CBaseMenuDemoView::CBaseMenuDemoView()
{
	// TODO: add construction code here

}

CBaseMenuDemoView::~CBaseMenuDemoView()
{
}

BOOL CBaseMenuDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBaseMenuDemoView drawing

void CBaseMenuDemoView::OnDraw(CDC* pDC)
{
	CBaseMenuDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CBaseMenuDemoView printing

BOOL CBaseMenuDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CBaseMenuDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CBaseMenuDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CBaseMenuDemoView diagnostics

#ifdef _DEBUG
void CBaseMenuDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CBaseMenuDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBaseMenuDemoDoc* CBaseMenuDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBaseMenuDemoDoc)));
	return (CBaseMenuDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBaseMenuDemoView message handlers

void CBaseMenuDemoView::OnMenurun() //执行菜单命令
{
	// TODO: Add your command handler code here
	CClientDC dc(this);												//获得DC
	dc.TextOut(30,40,"执行菜单项响应成功!");//输出文本

	
}

void CBaseMenuDemoView::OnMenupause() //暂停菜单命令
{
	// TODO: Add your command handler code here
	CClientDC dc(this);												//获得DC
	dc.TextOut(30,40,"暂停菜单项响应成功!");//输出文本
	
}
