// StaticSplitWnd3View.cpp : implementation of the CStaticSplitWnd3View class
//

#include "stdafx.h"
#include "StaticSplitWnd3.h"

#include "StaticSplitWnd3Doc.h"
#include "StaticSplitWnd3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitWnd3View

IMPLEMENT_DYNCREATE(CStaticSplitWnd3View, CView)

BEGIN_MESSAGE_MAP(CStaticSplitWnd3View, CView)
	//{{AFX_MSG_MAP(CStaticSplitWnd3View)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_SETCURSOR()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitWnd3View construction/destruction

CStaticSplitWnd3View::CStaticSplitWnd3View()
{
	// TODO: add construction code here

}

CStaticSplitWnd3View::~CStaticSplitWnd3View()
{
}

BOOL CStaticSplitWnd3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitWnd3View drawing

void CStaticSplitWnd3View::OnDraw(CDC* pDC)
{
//	CStaticSplitWnd3Doc* pDoc = GetDocument();
//	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->TextOut(10,10,"该窗格视图为CStaticSplitWnd3View,该窗格大小不能通过拖动改变");
	pDC->TextOut(10,30,"可通过菜单命令动态改变大小");
}

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitWnd3View printing

BOOL CStaticSplitWnd3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CStaticSplitWnd3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CStaticSplitWnd3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitWnd3View diagnostics

#ifdef _DEBUG
void CStaticSplitWnd3View::AssertValid() const
{
	CView::AssertValid();
}

void CStaticSplitWnd3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

/*CStaticSplitWnd3Doc* CStaticSplitWnd3View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStaticSplitWnd3Doc)));
	return (CStaticSplitWnd3Doc*)m_pDocument;
}*/
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitWnd3View message handlers

void CStaticSplitWnd3View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnLButtonDown(nFlags, point);
}

void CStaticSplitWnd3View::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnMouseMove(nFlags, point);
}

BOOL CStaticSplitWnd3View::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
	
	return CView::OnSetCursor(pWnd, nHitTest, message);
}
