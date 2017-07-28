// StatusTimeView.cpp : implementation of the CStatusTimeView class
//

#include "stdafx.h"
#include "StatusTime.h"

#include "StatusTimeDoc.h"
#include "StatusTimeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStatusTimeView

IMPLEMENT_DYNCREATE(CStatusTimeView, CView)

BEGIN_MESSAGE_MAP(CStatusTimeView, CView)
	//{{AFX_MSG_MAP(CStatusTimeView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStatusTimeView construction/destruction

CStatusTimeView::CStatusTimeView()
{
	// TODO: add construction code here

}

CStatusTimeView::~CStatusTimeView()
{
}

BOOL CStatusTimeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CStatusTimeView drawing

void CStatusTimeView::OnDraw(CDC* pDC)
{
	CStatusTimeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CStatusTimeView printing

BOOL CStatusTimeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CStatusTimeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CStatusTimeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CStatusTimeView diagnostics

#ifdef _DEBUG
void CStatusTimeView::AssertValid() const
{
	CView::AssertValid();
}

void CStatusTimeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CStatusTimeDoc* CStatusTimeView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStatusTimeDoc)));
	return (CStatusTimeDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStatusTimeView message handlers
