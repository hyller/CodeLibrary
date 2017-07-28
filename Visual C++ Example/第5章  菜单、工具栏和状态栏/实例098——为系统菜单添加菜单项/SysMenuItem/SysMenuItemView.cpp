// SysMenuItemView.cpp : implementation of the CSysMenuItemView class
//

#include "stdafx.h"
#include "SysMenuItem.h"

#include "SysMenuItemDoc.h"
#include "SysMenuItemView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSysMenuItemView

IMPLEMENT_DYNCREATE(CSysMenuItemView, CView)

BEGIN_MESSAGE_MAP(CSysMenuItemView, CView)
	//{{AFX_MSG_MAP(CSysMenuItemView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSysMenuItemView construction/destruction

CSysMenuItemView::CSysMenuItemView()
{
	// TODO: add construction code here

}

CSysMenuItemView::~CSysMenuItemView()
{
}

BOOL CSysMenuItemView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSysMenuItemView drawing

void CSysMenuItemView::OnDraw(CDC* pDC)
{
	CSysMenuItemDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CSysMenuItemView printing

BOOL CSysMenuItemView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSysMenuItemView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSysMenuItemView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSysMenuItemView diagnostics

#ifdef _DEBUG
void CSysMenuItemView::AssertValid() const
{
	CView::AssertValid();
}

void CSysMenuItemView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSysMenuItemDoc* CSysMenuItemView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSysMenuItemDoc)));
	return (CSysMenuItemDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSysMenuItemView message handlers
