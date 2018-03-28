// NoFileSizedMDIView.cpp : implementation of the CNoFileSizedMDIView class
//

#include "stdafx.h"
#include "NoFileSizedMDI.h"

#include "NoFileSizedMDIDoc.h"
#include "NoFileSizedMDIView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNoFileSizedMDIView

IMPLEMENT_DYNCREATE(CNoFileSizedMDIView, CView)

BEGIN_MESSAGE_MAP(CNoFileSizedMDIView, CView)
	//{{AFX_MSG_MAP(CNoFileSizedMDIView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNoFileSizedMDIView construction/destruction

CNoFileSizedMDIView::CNoFileSizedMDIView()
{
	// TODO: add construction code here

}

CNoFileSizedMDIView::~CNoFileSizedMDIView()
{
}

BOOL CNoFileSizedMDIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CNoFileSizedMDIView drawing

void CNoFileSizedMDIView::OnDraw(CDC* pDC)
{
	CNoFileSizedMDIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CNoFileSizedMDIView printing

BOOL CNoFileSizedMDIView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CNoFileSizedMDIView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CNoFileSizedMDIView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CNoFileSizedMDIView diagnostics

#ifdef _DEBUG
void CNoFileSizedMDIView::AssertValid() const
{
	CView::AssertValid();
}

void CNoFileSizedMDIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CNoFileSizedMDIDoc* CNoFileSizedMDIView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNoFileSizedMDIDoc)));
	return (CNoFileSizedMDIDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CNoFileSizedMDIView message handlers
