// StaticSplitWndView.cpp : implementation of the CStaticSplitWndView class
//

#include "stdafx.h"
#include "StaticSplitWnd.h"

#include "StaticSplitWndDoc.h"
#include "StaticSplitWndView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitWndView

IMPLEMENT_DYNCREATE(CStaticSplitWndView, CView)

BEGIN_MESSAGE_MAP(CStaticSplitWndView, CView)
	//{{AFX_MSG_MAP(CStaticSplitWndView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitWndView construction/destruction

CStaticSplitWndView::CStaticSplitWndView()
{
	// TODO: add construction code here

}

CStaticSplitWndView::~CStaticSplitWndView()
{
}

BOOL CStaticSplitWndView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitWndView drawing

void CStaticSplitWndView::OnDraw(CDC* pDC)
{
//	CStaticSplitWndDoc* pDoc = GetDocument();
//	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->TextOut(10,10,"该窗格视图为CStaticSplitWndView");
}

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitWndView printing

BOOL CStaticSplitWndView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CStaticSplitWndView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CStaticSplitWndView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitWndView diagnostics

#ifdef _DEBUG
void CStaticSplitWndView::AssertValid() const
{
	CView::AssertValid();
}

void CStaticSplitWndView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

/*CStaticSplitWndDoc* CStaticSplitWndView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStaticSplitWndDoc)));
	return (CStaticSplitWndDoc*)m_pDocument;
}*/
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitWndView message handlers
