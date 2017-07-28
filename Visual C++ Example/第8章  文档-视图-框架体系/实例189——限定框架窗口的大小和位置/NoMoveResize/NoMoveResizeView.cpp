// NoMoveResizeView.cpp : implementation of the CNoMoveResizeView class
//

#include "stdafx.h"
#include "NoMoveResize.h"

#include "NoMoveResizeDoc.h"
#include "NoMoveResizeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNoMoveResizeView

IMPLEMENT_DYNCREATE(CNoMoveResizeView, CView)

BEGIN_MESSAGE_MAP(CNoMoveResizeView, CView)
	//{{AFX_MSG_MAP(CNoMoveResizeView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNoMoveResizeView construction/destruction

CNoMoveResizeView::CNoMoveResizeView()
{
	// TODO: add construction code here

}

CNoMoveResizeView::~CNoMoveResizeView()
{
}

BOOL CNoMoveResizeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CNoMoveResizeView drawing

void CNoMoveResizeView::OnDraw(CDC* pDC)
{
	CNoMoveResizeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->TextOut(10,10,"无法移动且固定大小的SDI");
}

/////////////////////////////////////////////////////////////////////////////
// CNoMoveResizeView printing

BOOL CNoMoveResizeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CNoMoveResizeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CNoMoveResizeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CNoMoveResizeView diagnostics

#ifdef _DEBUG
void CNoMoveResizeView::AssertValid() const
{
	CView::AssertValid();
}

void CNoMoveResizeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CNoMoveResizeDoc* CNoMoveResizeView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNoMoveResizeDoc)));
	return (CNoMoveResizeDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CNoMoveResizeView message handlers
