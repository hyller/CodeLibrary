// StatusComboView.cpp : implementation of the CStatusComboView class
//

#include "stdafx.h"
#include "StatusCombo.h"

#include "StatusComboDoc.h"
#include "StatusComboView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStatusComboView

IMPLEMENT_DYNCREATE(CStatusComboView, CView)

BEGIN_MESSAGE_MAP(CStatusComboView, CView)
	//{{AFX_MSG_MAP(CStatusComboView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStatusComboView construction/destruction

CStatusComboView::CStatusComboView()
{
	// TODO: add construction code here

}

CStatusComboView::~CStatusComboView()
{
}

BOOL CStatusComboView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CStatusComboView drawing

void CStatusComboView::OnDraw(CDC* pDC)
{
	CStatusComboDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CStatusComboView printing

BOOL CStatusComboView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CStatusComboView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CStatusComboView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CStatusComboView diagnostics

#ifdef _DEBUG
void CStatusComboView::AssertValid() const
{
	CView::AssertValid();
}

void CStatusComboView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CStatusComboDoc* CStatusComboView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStatusComboDoc)));
	return (CStatusComboDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStatusComboView message handlers
