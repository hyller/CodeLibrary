// DyScrollRectView.cpp : implementation of the CDyScrollRectView class
//

#include "stdafx.h"
#include "DyScrollRect.h"

#include "DyScrollRectDoc.h"
#include "DyScrollRectView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDyScrollRectView

IMPLEMENT_DYNCREATE(CDyScrollRectView, CScrollView)

BEGIN_MESSAGE_MAP(CDyScrollRectView, CScrollView)
	//{{AFX_MSG_MAP(CDyScrollRectView)
	ON_COMMAND(ID_MENURECT1, OnMenurect1)
	ON_COMMAND(ID_MENURECT2, OnMenurect2)
	ON_COMMAND(ID_MENURECT3, OnMenurect3)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDyScrollRectView construction/destruction

CDyScrollRectView::CDyScrollRectView()
{
	// TODO: add construction code here
	lable=0;
	sizetemp.cx=sizetemp.cy=0;
}

CDyScrollRectView::~CDyScrollRectView()
{
}

BOOL CDyScrollRectView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDyScrollRectView drawing

void CDyScrollRectView::OnDraw(CDC* pDC)
{
	CDyScrollRectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CBrush brush,*oldbrush;
	switch(lable)
	{
	case 1:	//矩形1
		brush.CreateSolidBrush(RGB(128,0,0));//红色画刷
		oldbrush=pDC->SelectObject(&brush);//载入画刷
		pDC->Rectangle(100,100,400,400);
		pDC->SelectObject(oldbrush);//恢复画刷
		brush.DeleteObject();
		break;
	case 2://矩形2
		brush.CreateSolidBrush(RGB(0,128,0));//绿色画刷
		oldbrush=pDC->SelectObject(&brush);//载入画刷
		pDC->Rectangle(600,100,900,300);
		pDC->SelectObject(oldbrush);//恢复画刷
		brush.DeleteObject();
		break;
	case 3://矩形3
		brush.CreateSolidBrush(RGB(0,0,128));//蓝色画刷
		oldbrush=pDC->SelectObject(&brush);//载入画刷
		pDC->Rectangle(400,400,800,1100);
		pDC->SelectObject(oldbrush);//恢复画刷
		brush.DeleteObject();
		break;
	default:
		break;		
	}
}

void CDyScrollRectView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

/////////////////////////////////////////////////////////////////////////////
// CDyScrollRectView printing

BOOL CDyScrollRectView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDyScrollRectView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDyScrollRectView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDyScrollRectView diagnostics

#ifdef _DEBUG
void CDyScrollRectView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CDyScrollRectView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CDyScrollRectDoc* CDyScrollRectView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDyScrollRectDoc)));
	return (CDyScrollRectDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDyScrollRectView message handlers

void CDyScrollRectView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// TODO: Add your specialized code here and/or call the base class
	CSize size;
	size=sizetemp;
	SetScrollSizes(MM_TEXT, size);//设置滚动窗口区域
	CScrollView::OnUpdate(pSender,lHint, pHint);	
}

void CDyScrollRectView::OnMenurect1() //矩形1
{
	// TODO: Add your command handler code here
	CClientDC dc(this);//获取客户窗口DC
	lable=1;
	sizetemp.cx=sizetemp.cy=400;//设定滚动窗口区域
	OnUpdate(NULL,NULL,NULL);
	OnDraw(&dc);//绘图
}

void CDyScrollRectView::OnMenurect2() //矩形2
{
	// TODO: Add your command handler code here
	CClientDC dc(this);//获取客户窗口DC
	lable=2;
	sizetemp.cx=1000;//设定滚动窗口区域
	sizetemp.cy=400;
	OnUpdate(NULL,NULL,NULL);
	OnDraw(&dc);//绘图	
}

void CDyScrollRectView::OnMenurect3() //矩形3
{
	// TODO: Add your command handler code here
	CClientDC dc(this);//获取客户窗口DC
	lable=3;
	sizetemp.cx=1000;//设定滚动窗口区域
	sizetemp.cy=1200;
	OnUpdate(NULL,NULL,NULL);
	OnDraw(&dc);//绘图
}
