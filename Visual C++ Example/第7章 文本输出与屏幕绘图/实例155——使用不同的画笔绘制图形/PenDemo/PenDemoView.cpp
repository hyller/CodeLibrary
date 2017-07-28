// PenDemoView.cpp : implementation of the CPenDemoView class
//

#include "stdafx.h"
#include "PenDemo.h"

#include "PenDemoDoc.h"
#include "PenDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPenDemoView

IMPLEMENT_DYNCREATE(CPenDemoView, CView)

BEGIN_MESSAGE_MAP(CPenDemoView, CView)
	//{{AFX_MSG_MAP(CPenDemoView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPenDemoView construction/destruction

CPenDemoView::CPenDemoView()
{
	// TODO: add construction code here

}

CPenDemoView::~CPenDemoView()
{
}

BOOL CPenDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPenDemoView drawing

void CPenDemoView::OnDraw(CDC* pDC)
{
	CPenDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CPen pen[5];
	pen[0].CreatePen(PS_SOLID, 3, RGB(255, 0, 0)); 					//创建实线画笔
	pen[1].CreatePen(PS_DASH, 1, RGB(0, 255, 0));	 				//创建虚线画笔
	pen[2].CreatePen(PS_DOT, 1, RGB(0, 0, 255));					//创建点线画笔
	pen[3].CreatePen(PS_DASHDOT, 1, RGB(0, 255, 255));				//创建点划线画笔
	pen[4].CreatePen(PS_DASHDOTDOT, 1, RGB(255, 0, 255)); 			//创建双点划线画笔	
	// 保存指向设备上下文原有画笔的指针
	CPen *pOldPen;
	//以实线画笔绘制矩形
	pOldPen=pDC->SelectObject(&pen[0]);
	pDC->Rectangle(10, 10, 110, 110);
	pDC->TextOut(10, 115, "绘制矩形");
	//使用虚线画笔和函数Polyline输出多段折线
	pDC->SelectObject(&pen[1]);								//载入虚线画笔
	CPoint pts[]={CPoint(190, 20), CPoint(200, 60), CPoint(270, 40), CPoint(210, 80), 
	CPoint(250, 100), CPoint(300, 30), CPoint(310, 80)};
	pDC->Polyline(pts, 7);										//绘制多端折线
	pDC->TextOut(180, 115, "绘制多段折线");	
	// 使用Pie和Arc输出饼图和弧形
	pDC->SelectObject(&pen[2]);								//载入点线画笔
	pDC->Ellipse(10, 140, 160, 240);						//绘制椭圆
	pDC->SelectObject(&pen[3]);								//载入点划线画笔
	pDC->Pie(20, 150, 150, 230, 160, 160, 10, 160);
	pDC->SelectObject(&pen[4]);								//载入双点划线画笔
	pDC->Arc(20, 150, 150, 230, 10, 220, 160, 220);
	pDC->TextOut(10, 245, "绘制椭圆、弧形和饼图");
	pDC->SetTextColor(RGB(0,0,255));
	pDC->TextOut(220, 200, "使用不同的画笔绘制各种图形");
	//恢复设备上下文的原有画笔
	pDC->SelectObject(pOldPen);
	//删除所创建的画笔资源
	for (int i=0; i<5; i++)
	pen[i].DeleteObject();
}

/////////////////////////////////////////////////////////////////////////////
// CPenDemoView printing

BOOL CPenDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPenDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPenDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CPenDemoView diagnostics

#ifdef _DEBUG
void CPenDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CPenDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPenDemoDoc* CPenDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPenDemoDoc)));
	return (CPenDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPenDemoView message handlers
