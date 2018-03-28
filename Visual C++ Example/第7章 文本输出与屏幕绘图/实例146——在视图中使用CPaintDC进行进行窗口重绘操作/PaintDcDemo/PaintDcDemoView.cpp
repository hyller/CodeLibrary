// PaintDcDemoView.cpp : implementation of the CPaintDcDemoView class
//

#include "stdafx.h"
#include "PaintDcDemo.h"

#include "PaintDcDemoDoc.h"
#include "PaintDcDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPaintDcDemoView

IMPLEMENT_DYNCREATE(CPaintDcDemoView, CView)

BEGIN_MESSAGE_MAP(CPaintDcDemoView, CView)
	//{{AFX_MSG_MAP(CPaintDcDemoView)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPaintDcDemoView construction/destruction

CPaintDcDemoView::CPaintDcDemoView()
{
	// TODO: add construction code here

}

CPaintDcDemoView::~CPaintDcDemoView()
{
}

BOOL CPaintDcDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPaintDcDemoView drawing

void CPaintDcDemoView::OnDraw(CDC* pDC)
{
	CPaintDcDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CPaintDcDemoView printing

BOOL CPaintDcDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPaintDcDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPaintDcDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CPaintDcDemoView diagnostics

#ifdef _DEBUG
void CPaintDcDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CPaintDcDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPaintDcDemoDoc* CPaintDcDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPaintDcDemoDoc)));
	return (CPaintDcDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPaintDcDemoView message handlers

void CPaintDcDemoView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	dc.TextOut(5,5,"在客户窗口的正中间绘制矩形，大小为窗口的1/4");
	CRect rect;									//创建矩形区域，存储客户窗口区域
	GetClientRect(&rect);							//得到客户区的范围放到rect中
	//在客户窗口的正中间绘制矩形，大小为窗口的1/4
	dc.Rectangle(rect.Width()/4,rect.Height()/4,3*rect.Width()/4,3*rect.Height()/4); 
	// Do not call CView::OnPaint() for painting messages
}
