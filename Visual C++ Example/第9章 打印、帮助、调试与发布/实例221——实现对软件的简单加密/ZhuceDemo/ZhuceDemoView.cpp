// ZhuceDemoView.cpp : implementation of the CZhuceDemoView class
//

#include "stdafx.h"
#include "ZhuceDemo.h"

#include "ZhuceDemoDoc.h"
#include "ZhuceDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CZhuceDemoView

IMPLEMENT_DYNCREATE(CZhuceDemoView, CView)

BEGIN_MESSAGE_MAP(CZhuceDemoView, CView)
	//{{AFX_MSG_MAP(CZhuceDemoView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZhuceDemoView construction/destruction

CZhuceDemoView::CZhuceDemoView()
{
	// TODO: add construction code here

}

CZhuceDemoView::~CZhuceDemoView()
{
}

BOOL CZhuceDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CZhuceDemoView drawing

void CZhuceDemoView::OnDraw(CDC* pDC)
{
	CZhuceDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CZhuceDemoView printing

BOOL CZhuceDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CZhuceDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CZhuceDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CZhuceDemoView diagnostics

#ifdef _DEBUG
void CZhuceDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CZhuceDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CZhuceDemoDoc* CZhuceDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CZhuceDemoDoc)));
	return (CZhuceDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CZhuceDemoView message handlers
