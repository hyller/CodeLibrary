// ClipCursorMouseView.cpp : implementation of the CClipCursorMouseView class
//

#include "stdafx.h"
#include "ClipCursorMouse.h"

#include "ClipCursorMouseDoc.h"
#include "ClipCursorMouseView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClipCursorMouseView

IMPLEMENT_DYNCREATE(CClipCursorMouseView, CView)

BEGIN_MESSAGE_MAP(CClipCursorMouseView, CView)
	//{{AFX_MSG_MAP(CClipCursorMouseView)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClipCursorMouseView construction/destruction

CClipCursorMouseView::CClipCursorMouseView()
{
	// TODO: add construction code here

}

CClipCursorMouseView::~CClipCursorMouseView()
{
}

BOOL CClipCursorMouseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	GetClipCursor(&oldrect); 							//获取原鼠标活动的有效区域
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CClipCursorMouseView drawing

void CClipCursorMouseView::OnDraw(CDC* pDC)
{
	CClipCursorMouseDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->TextOut(5,5,"在客户窗口单击鼠标左键，将鼠标的活动区域限制在客户窗口！");
	pDC->TextOut(5,35,"在客户窗口双击鼠标左键，恢复鼠标的活动区域！");
}

/////////////////////////////////////////////////////////////////////////////
// CClipCursorMouseView printing

BOOL CClipCursorMouseView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CClipCursorMouseView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CClipCursorMouseView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CClipCursorMouseView diagnostics

#ifdef _DEBUG
void CClipCursorMouseView::AssertValid() const
{
	CView::AssertValid();
}

void CClipCursorMouseView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CClipCursorMouseDoc* CClipCursorMouseView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CClipCursorMouseDoc)));
	return (CClipCursorMouseDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CClipCursorMouseView message handlers

void CClipCursorMouseView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	ReleaseCapture();//释放鼠标
	ClipCursor(&oldrect);								//恢复鼠标的活动区域
	CView::OnLButtonDblClk(nFlags, point);
}

void CClipCursorMouseView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	SetCapture();									//捕捉鼠标
	CRect rect1;
	GetWindowRect(&rect1);							//获取客户区窗口区域
	ClipCursor(&rect1);								//将鼠标的活动区域限制在客户窗口	
	CView::OnLButtonDown(nFlags, point);
}
