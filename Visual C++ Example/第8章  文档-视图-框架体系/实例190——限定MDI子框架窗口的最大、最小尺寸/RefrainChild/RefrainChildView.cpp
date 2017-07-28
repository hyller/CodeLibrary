// RefrainChildView.cpp : implementation of the CRefrainChildView class
//

#include "stdafx.h"
#include "RefrainChild.h"

#include "RefrainChildDoc.h"
#include "RefrainChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRefrainChildView

IMPLEMENT_DYNCREATE(CRefrainChildView, CView)

BEGIN_MESSAGE_MAP(CRefrainChildView, CView)
	//{{AFX_MSG_MAP(CRefrainChildView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRefrainChildView construction/destruction

CRefrainChildView::CRefrainChildView()
{
	// TODO: add construction code here

}

CRefrainChildView::~CRefrainChildView()
{
}

BOOL CRefrainChildView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CRefrainChildView drawing

void CRefrainChildView::OnDraw(CDC* pDC)
{
	CRefrainChildDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->TextOut(10,10,"限定MDI子框架窗口的最大、最小尺寸");
}

/////////////////////////////////////////////////////////////////////////////
// CRefrainChildView printing

BOOL CRefrainChildView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CRefrainChildView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CRefrainChildView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CRefrainChildView diagnostics

#ifdef _DEBUG
void CRefrainChildView::AssertValid() const
{
	CView::AssertValid();
}

void CRefrainChildView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRefrainChildDoc* CRefrainChildView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRefrainChildDoc)));
	return (CRefrainChildDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRefrainChildView message handlers
