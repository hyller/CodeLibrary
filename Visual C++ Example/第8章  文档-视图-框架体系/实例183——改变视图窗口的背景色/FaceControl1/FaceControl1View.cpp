// FaceControl1View.cpp : implementation of the CFaceControl1View class
//

#include "stdafx.h"
#include "FaceControl1.h"

#include "FaceControl1Doc.h"
#include "FaceControl1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFaceControl1View

IMPLEMENT_DYNCREATE(CFaceControl1View, CView)

BEGIN_MESSAGE_MAP(CFaceControl1View, CView)
	//{{AFX_MSG_MAP(CFaceControl1View)
	ON_COMMAND(ID_CHAGEVIEWBK, OnChageviewbk)
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFaceControl1View construction/destruction

CFaceControl1View::CFaceControl1View()
{
	// TODO: add construction code here
	m_rgbBack = RGB(128 , 128 , 128);

}

CFaceControl1View::~CFaceControl1View()
{
}

BOOL CFaceControl1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CFaceControl1View drawing

void CFaceControl1View::OnDraw(CDC* pDC)
{
	CFaceControl1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CFaceControl1View printing

BOOL CFaceControl1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFaceControl1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFaceControl1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CFaceControl1View diagnostics

#ifdef _DEBUG
void CFaceControl1View::AssertValid() const
{
	CView::AssertValid();
}

void CFaceControl1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFaceControl1Doc* CFaceControl1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFaceControl1Doc)));
	return (CFaceControl1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFaceControl1View message handlers

void CFaceControl1View::OnChageviewbk() //改变背景色
{
	// TODO: Add your command handler code here
	m_rgbBack=RGB(0,128,128);
	Invalidate(true);
}

BOOL CFaceControl1View::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	CBrush Brush (m_rgbBack);	// 创建一个新的刷子
	CBrush* pOldBrush = pDC->SelectObject (&Brush);	// 把刷子选入设备环境
	//获得需要檫除背景的区域
	CRect reClip;
	GetClientRect(&reClip);
	//重绘该区域
	pDC->PatBlt(reClip.left , reClip.top , reClip.Width () , reClip.Height() , PATCOPY);
	//释放刷子
	pDC->SelectObject (pOldBrush);
	return TRUE;//必须返回TURE
	//return CView::OnEraseBkgnd(pDC);
}
