// RgnDemoView.cpp : implementation of the CRgnDemoView class
//

#include "stdafx.h"
#include "RgnDemo.h"

#include "RgnDemoDoc.h"
#include "RgnDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRgnDemoView

IMPLEMENT_DYNCREATE(CRgnDemoView, CView)

BEGIN_MESSAGE_MAP(CRgnDemoView, CView)
	//{{AFX_MSG_MAP(CRgnDemoView)
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRgnDemoView construction/destruction

CRgnDemoView::CRgnDemoView()
{
	// TODO: add construction code here
	rgnA.CreateRectRgn(0,0,0,0);						//创建初始对象，任意值均可
	rgnB.CreateRectRgn(0,0,0,0);						//创建初始对象，任意值均可
	str="";
}

CRgnDemoView::~CRgnDemoView()
{
}

BOOL CRgnDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CRgnDemoView drawing

void CRgnDemoView::OnDraw(CDC* pDC)
{
	CRgnDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->TextOut(10,270,str);						//输出文本
	CRgn rgn1,rgn2; 								//构造CRgn对象
	rgn1.CreateRectRgn(20,70,200,120);	 				//矩形区域
	rgn2.CreateEllipticRgn(50,25,150,250); 				//椭圆区域
	rgnA.CombineRgn(&rgn1,&rgn2,RGN_AND); 			//两个区域的交集
	rgnB.CombineRgn(&rgn1,&rgn2,RGN_XOR); 			//交集以外的区域
	pDC->SelectClipRgn(&rgnA);						//将rgnA设置为剪切区域 
	CRect rect(0,0,400,400); 
	CBrush brush,brush2; 
	brush.CreateSolidBrush(RGB(255,0,0)); 
	CBrush *poldBrush = pDC->SelectObject(&brush); 		//选择自定义画刷 
	pDC->Rectangle(&rect); 							//绘制区域
	pDC->SelectObject(poldBrush); 						//画刷恢复原值 
	pDC->SelectClipRgn(&rgnB);						//将rgnB设置为剪切区域 
	brush2.CreateHatchBrush(HS_DIAGCROSS, RGB(0, 128, 128)); 	//选择自定义画刷
	poldBrush = pDC->SelectObject(&brush2);	 			//选择自定义画刷 
	pDC->Rectangle(&rect); 							//绘制区域
	pDC->SelectObject(poldBrush); 						//画刷恢复原值 
	brush.DeleteObject();
	brush2.DeleteObject();
}

/////////////////////////////////////////////////////////////////////////////
// CRgnDemoView printing

BOOL CRgnDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CRgnDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CRgnDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CRgnDemoView diagnostics

#ifdef _DEBUG
void CRgnDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CRgnDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRgnDemoDoc* CRgnDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRgnDemoDoc)));
	return (CRgnDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRgnDemoView message handlers

void CRgnDemoView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (rgnA.PtInRegion(point))							//鼠标位置在区域A中
	{
			str="光标位于两个图形的交集区域";
	}
	else if (rgnB.PtInRegion(point))					//鼠标位置在区域B中
	{
			str="光标位于两个图形的交集以外区域";;
	}
	else
	{
		str="光标不在两个图形的区域中";
	}
	CRect rect(0,250,400,300);//设定更新区域，即文本区域
	InvalidateRect(&rect);//更新窗口
	CView::OnMouseMove(nFlags, point);
}
