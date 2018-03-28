// CircleWaveView.cpp : implementation of the CCircleWaveView class
//

#include "stdafx.h"
#include "CircleWave.h"

#include "CircleWaveDoc.h"
#include "CircleWaveView.h"
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCircleWaveView

IMPLEMENT_DYNCREATE(CCircleWaveView, CView)

BEGIN_MESSAGE_MAP(CCircleWaveView, CView)
	//{{AFX_MSG_MAP(CCircleWaveView)
	ON_WM_LBUTTONDOWN()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCircleWaveView construction/destruction

CCircleWaveView::CCircleWaveView()
{
	// TODO: add construction code here
	rgb[0]=RGB(128,0,0);//红
	rgb[1]=RGB(0,128,0);//绿
	rgb[2]=RGB(0,0,128);//蓝
	rgb[3]=RGB(0,128,128);//青
	rgb[4]=RGB(128,0,128);//紫
	rgb[5]=RGB(128,128,128);//灰
	icolor=0;//从红色开始
}

CCircleWaveView::~CCircleWaveView()
{
}

BOOL CCircleWaveView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCircleWaveView drawing

void CCircleWaveView::OnDraw(CDC* pDC)
{
	CCircleWaveDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CPen pen;
	CRect rect2;
	int i,j,period,cl;
	double angle;
	COLORREF color;
	CBrush brush;
	brush.CreateSolidBrush(rgb[icolor-1]);
	pDC->FillRect(rect,&brush);
	pDC->SelectStockObject(NULL_BRUSH);//载入空画刷
	brush.DeleteObject();
	//确定最大圆的直径
	i=min(rect.right,rect.bottom);
	pDC->SetMapMode(MM_ISOTROPIC);			//设置映射方式,满足纵横的比例为1：1
	pDC->SetWindowExt(i,i);
	pDC->SetViewportExt(rect.right,-rect.bottom);
	pDC->SetViewportOrg(center.x,center.y);
	i=max(rect.right,rect.bottom)/2;
	rect2.SetRect(-i,-i,i,i);
	period=i/(2*6);//6表示绘制6个圆环
	angle=0.0;
	for(j=0;j<6;j++)//绘制6个圆环区域
	{
		for(i=1;i<period;i++)//在每个圆环区域使用由深到浅的画笔颜色绘制圆
		{
			angle+=PI/period;
			cl=128+(int)(128.0*sin(angle));//渐变的颜色
			if(color>255)
				color=255;
			switch(icolor)//构造各种颜色值
			{
				case RED:
					color=RGB(cl,0,0);
					break;
				case GREEN:
					color=RGB(0,cl,0);
					break;
				case BLUE:
					color=RGB(0,0,cl);
					break;
				case CYAN:
					color=RGB(0,cl,cl);
					break;
				case MAGENTA:
					color=RGB(cl,0,cl);
					break;
				case GRAY:
					color=RGB(cl,cl,cl);
					break;
			}
			rect2.InflateRect(-1,-1);//收缩圆区域
			pen.CreatePen(PS_SOLID,1,color);
			pDC->SelectObject(&pen);
			pDC->Ellipse(rect2);//绘制圆
			pDC->SelectStockObject(BLACK_PEN);
			pen.DeleteObject();
		}
		rect2.InflateRect(-period,-period);//收缩圆区域
	}
}

/////////////////////////////////////////////////////////////////////////////
// CCircleWaveView printing

BOOL CCircleWaveView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCircleWaveView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCircleWaveView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCircleWaveView diagnostics

#ifdef _DEBUG
void CCircleWaveView::AssertValid() const
{
	CView::AssertValid();
}

void CCircleWaveView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCircleWaveDoc* CCircleWaveView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCircleWaveDoc)));
	return (CCircleWaveDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCircleWaveView message handlers

void CCircleWaveView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	center=point;//当前鼠标点为圆心
	icolor=rand()%6;
	Invalidate(false);
	CView::OnLButtonDown(nFlags, point);
}

void CCircleWaveView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	rect.SetRect(0,0,cx,cy);
	center.x=cx/2;
	center.y=cy/2;
	
}
