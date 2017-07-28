// StatusBmpView.cpp : implementation of the CStatusBmpView class
//

#include "stdafx.h"
#include "StatusBmp.h"

#include "StatusBmpDoc.h"
#include "StatusBmpView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStatusBmpView

IMPLEMENT_DYNCREATE(CStatusBmpView, CView)

BEGIN_MESSAGE_MAP(CStatusBmpView, CView)
	//{{AFX_MSG_MAP(CStatusBmpView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStatusBmpView construction/destruction

CStatusBmpView::CStatusBmpView()
{
	// TODO: add construction code here

}

CStatusBmpView::~CStatusBmpView()
{
}

BOOL CStatusBmpView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CStatusBmpView drawing

void CStatusBmpView::OnDraw(CDC* pDC)
{
	CStatusBmpDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CStatusBmpView printing

BOOL CStatusBmpView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CStatusBmpView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CStatusBmpView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CStatusBmpView diagnostics

#ifdef _DEBUG
void CStatusBmpView::AssertValid() const
{
	CView::AssertValid();
}

void CStatusBmpView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CStatusBmpDoc* CStatusBmpView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStatusBmpDoc)));
	return (CStatusBmpDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStatusBmpView message handlers
