// HotKeyDemoView.cpp : implementation of the CHotKeyDemoView class
//

#include "stdafx.h"
#include "HotKeyDemo.h"

#include "HotKeyDemoDoc.h"
#include "HotKeyDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHotKeyDemoView

IMPLEMENT_DYNCREATE(CHotKeyDemoView, CView)

BEGIN_MESSAGE_MAP(CHotKeyDemoView, CView)
	//{{AFX_MSG_MAP(CHotKeyDemoView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHotKeyDemoView construction/destruction

CHotKeyDemoView::CHotKeyDemoView()
{
	// TODO: add construction code here

}

CHotKeyDemoView::~CHotKeyDemoView()
{
}

BOOL CHotKeyDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CHotKeyDemoView drawing

void CHotKeyDemoView::OnDraw(CDC* pDC)
{
	CHotKeyDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->TextOut(20,20,"本实例将演示使用热键控件设置热键，并在程序中响应热键。");
}

/////////////////////////////////////////////////////////////////////////////
// CHotKeyDemoView printing

BOOL CHotKeyDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CHotKeyDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CHotKeyDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CHotKeyDemoView diagnostics

#ifdef _DEBUG
void CHotKeyDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CHotKeyDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHotKeyDemoDoc* CHotKeyDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHotKeyDemoDoc)));
	return (CHotKeyDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHotKeyDemoView message handlers
