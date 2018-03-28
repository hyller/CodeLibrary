// DrawArrowDemoView.cpp : implementation of the CDrawArrowDemoView class
//



#include "stdafx.h"
#include "DrawArrowDemo.h"

#include "DrawArrowDemoDoc.h"
#include "DrawArrowDemoView.h"

#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDrawArrowDemoView

IMPLEMENT_DYNCREATE(CDrawArrowDemoView, CView)

BEGIN_MESSAGE_MAP(CDrawArrowDemoView, CView)
	//{{AFX_MSG_MAP(CDrawArrowDemoView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawArrowDemoView construction/destruction

CDrawArrowDemoView::CDrawArrowDemoView()
{
	// TODO: add construction code here

}

CDrawArrowDemoView::~CDrawArrowDemoView()
{
}

BOOL CDrawArrowDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDrawArrowDemoView drawing

void CDrawArrowDemoView::OnDraw(CDC* pDC)
{
	CDrawArrowDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CPoint p1(20,20),p2(120,180);
	DrawArrow(p1,p2,30,12);
	CPoint p3(20,12),p4(220,12);
	DrawArrow(p3,p4,20,16);//绘制
	pDC->TextOut(50,50,"绘制带有箭头的线段，可以定制箭头的方向和长度");
}

/////////////////////////////////////////////////////////////////////////////
// CDrawArrowDemoView printing

BOOL CDrawArrowDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDrawArrowDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDrawArrowDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDrawArrowDemoView diagnostics

#ifdef _DEBUG
void CDrawArrowDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawArrowDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

void CDrawArrowDemoView::DrawArrow(CPoint p1,CPoint p2,double theta,int length)
{
	theta=3.1415926*theta/180;//转换为弧度
	double Px,Py,P1x,P1y,P2x,P2y;
	//以P2为原点得到向量P2P1（P）
	Px=p1.x-p2.x;
	Py=p1.y-p2.y;
	//向量P旋转theta角得到向量P1
	P1x=Px*cos(theta)-Py*sin(theta);
	P1y=Px*sin(theta)+Py*cos(theta);
	//向量P旋转-theta角得到向量P2
	P2x=Px*cos(-theta)-Py*sin(-theta);
	P2y=Px*sin(-theta)+Py*cos(-theta);
	//伸缩向量至制定长度
	double x1,x2;
	x1=sqrt(P1x*P1x+P1y*P1y);
	P1x=P1x*length/x1;
	P1y=P1y*length/x1;
	x2=sqrt(P2x*P2x+P2y*P2y);
	P2x=P2x*length/x2;
	P2y=P2y*length/x2;
	//平移变量到直线的末端
	P1x=P1x+p2.x;
	P1y=P1y+p2.y;
	P2x=P2x+p2.x;
	P2y=P2y+p2.y;
	CClientDC dc(this);//获取客户窗口DC
	CPen pen,pen1,*oldpen;
	pen.CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	pen1.CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	oldpen=dc.SelectObject(&pen);
	dc.MoveTo(p1.x,p1.y);
	dc.LineTo(p2.x,p2.y);
	dc.SelectObject(&pen1);
	dc.MoveTo(p2.x,p2.y);
	dc.LineTo(P1x,P1y);
	dc.MoveTo(p2.x,p2.y);
	dc.LineTo(P2x,P2y);
	dc.SelectObject(oldpen);
}


CDrawArrowDemoDoc* CDrawArrowDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawArrowDemoDoc)));
	return (CDrawArrowDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDrawArrowDemoView message handlers
