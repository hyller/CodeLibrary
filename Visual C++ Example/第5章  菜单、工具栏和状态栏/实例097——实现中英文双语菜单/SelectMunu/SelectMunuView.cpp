// SelectMunuView.cpp : implementation of the CSelectMunuView class
//

#include "stdafx.h"
#include "SelectMunu.h"

#include "SelectMunuDoc.h"
#include "SelectMunuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSelectMunuView

IMPLEMENT_DYNCREATE(CSelectMunuView, CView)

BEGIN_MESSAGE_MAP(CSelectMunuView, CView)
	//{{AFX_MSG_MAP(CSelectMunuView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSelectMunuView construction/destruction

CSelectMunuView::CSelectMunuView()
{
	// TODO: add construction code here

}

CSelectMunuView::~CSelectMunuView()
{
}

BOOL CSelectMunuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSelectMunuView drawing

void CSelectMunuView::OnDraw(CDC* pDC)
{
	CSelectMunuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->TextOut(30,30,"在查看下拉菜单下可以实现中英文菜单的切换！");
}

/////////////////////////////////////////////////////////////////////////////
// CSelectMunuView printing

BOOL CSelectMunuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSelectMunuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSelectMunuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSelectMunuView diagnostics

#ifdef _DEBUG
void CSelectMunuView::AssertValid() const
{
	CView::AssertValid();
}

void CSelectMunuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSelectMunuDoc* CSelectMunuView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSelectMunuDoc)));
	return (CSelectMunuDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSelectMunuView message handlers
