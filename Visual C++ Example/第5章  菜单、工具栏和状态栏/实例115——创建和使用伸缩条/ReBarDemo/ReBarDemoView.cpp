// ReBarDemoView.cpp : implementation of the CReBarDemoView class
//

#include "stdafx.h"
#include "ReBarDemo.h"

#include "ReBarDemoDoc.h"
#include "ReBarDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CReBarDemoView

IMPLEMENT_DYNCREATE(CReBarDemoView, CView)

BEGIN_MESSAGE_MAP(CReBarDemoView, CView)
	//{{AFX_MSG_MAP(CReBarDemoView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReBarDemoView construction/destruction

CReBarDemoView::CReBarDemoView()
{
	// TODO: add construction code here

}

CReBarDemoView::~CReBarDemoView()
{
}

BOOL CReBarDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CReBarDemoView drawing

void CReBarDemoView::OnDraw(CDC* pDC)
{
	CReBarDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->TextOut(30,30,"创建伸缩条，包含对话条、工具栏和控件三个伸缩段！");
}

/////////////////////////////////////////////////////////////////////////////
// CReBarDemoView printing

BOOL CReBarDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CReBarDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CReBarDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CReBarDemoView diagnostics

#ifdef _DEBUG
void CReBarDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CReBarDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CReBarDemoDoc* CReBarDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CReBarDemoDoc)));
	return (CReBarDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CReBarDemoView message handlers
