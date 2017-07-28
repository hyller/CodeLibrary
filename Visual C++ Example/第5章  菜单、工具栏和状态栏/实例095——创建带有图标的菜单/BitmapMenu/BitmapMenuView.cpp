// BitmapMenuView.cpp : implementation of the CBitmapMenuView class
//

#include "stdafx.h"
#include "BitmapMenu.h"

#include "BitmapMenuDoc.h"
#include "BitmapMenuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBitmapMenuView

IMPLEMENT_DYNCREATE(CBitmapMenuView, CView)

BEGIN_MESSAGE_MAP(CBitmapMenuView, CView)
	//{{AFX_MSG_MAP(CBitmapMenuView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBitmapMenuView construction/destruction

CBitmapMenuView::CBitmapMenuView()
{
	// TODO: add construction code here

}

CBitmapMenuView::~CBitmapMenuView()
{
}

BOOL CBitmapMenuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBitmapMenuView drawing

void CBitmapMenuView::OnDraw(CDC* pDC)
{
	CBitmapMenuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CBitmapMenuView printing

BOOL CBitmapMenuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CBitmapMenuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CBitmapMenuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CBitmapMenuView diagnostics

#ifdef _DEBUG
void CBitmapMenuView::AssertValid() const
{
	CView::AssertValid();
}

void CBitmapMenuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBitmapMenuDoc* CBitmapMenuView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBitmapMenuDoc)));
	return (CBitmapMenuDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBitmapMenuView message handlers
