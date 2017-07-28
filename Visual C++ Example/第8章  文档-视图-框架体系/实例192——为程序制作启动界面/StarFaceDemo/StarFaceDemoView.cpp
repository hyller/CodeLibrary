// StarFaceDemoView.cpp : implementation of the CStarFaceDemoView class
//

#include "stdafx.h"
#include "StarFaceDemo.h"

#include "StarFaceDemoDoc.h"
#include "StarFaceDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStarFaceDemoView

IMPLEMENT_DYNCREATE(CStarFaceDemoView, CView)

BEGIN_MESSAGE_MAP(CStarFaceDemoView, CView)
	//{{AFX_MSG_MAP(CStarFaceDemoView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStarFaceDemoView construction/destruction

CStarFaceDemoView::CStarFaceDemoView()
{
	// TODO: add construction code here

}

CStarFaceDemoView::~CStarFaceDemoView()
{
}

BOOL CStarFaceDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CStarFaceDemoView drawing

void CStarFaceDemoView::OnDraw(CDC* pDC)
{
	CStarFaceDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CStarFaceDemoView printing

BOOL CStarFaceDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CStarFaceDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CStarFaceDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CStarFaceDemoView diagnostics

#ifdef _DEBUG
void CStarFaceDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CStarFaceDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CStarFaceDemoDoc* CStarFaceDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStarFaceDemoDoc)));
	return (CStarFaceDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStarFaceDemoView message handlers
