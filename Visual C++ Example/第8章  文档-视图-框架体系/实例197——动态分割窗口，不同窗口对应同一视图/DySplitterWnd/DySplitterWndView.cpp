// DySplitterWndView.cpp : implementation of the CDySplitterWndView class
//

#include "stdafx.h"
#include "DySplitterWnd.h"

#include "DySplitterWndDoc.h"
#include "DySplitterWndView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDySplitterWndView

IMPLEMENT_DYNCREATE(CDySplitterWndView, CScrollView)

BEGIN_MESSAGE_MAP(CDySplitterWndView, CScrollView)
	//{{AFX_MSG_MAP(CDySplitterWndView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDySplitterWndView construction/destruction

CDySplitterWndView::CDySplitterWndView()
{
	// TODO: add construction code here

}

CDySplitterWndView::~CDySplitterWndView()
{
}

BOOL CDySplitterWndView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDySplitterWndView drawing

void CDySplitterWndView::OnDraw(CDC* pDC)
{
	CDySplitterWndDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->TextOut(10,10,"动态分割窗口，各个窗口对应同一个视图！");
}

/////////////////////////////////////////////////////////////////////////////
// CDySplitterWndView printing

BOOL CDySplitterWndView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDySplitterWndView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDySplitterWndView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDySplitterWndView diagnostics

#ifdef _DEBUG
void CDySplitterWndView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CDySplitterWndView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CDySplitterWndDoc* CDySplitterWndView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDySplitterWndDoc)));
	return (CDySplitterWndDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDySplitterWndView message handlers

void CDySplitterWndView::OnInitialUpdate() 
{
	CScrollView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	SIZE size={800,600};
	SetScrollSizes(MM_TEXT,size);								//滚动窗口的最大区域

	
}
