// MyMapDemoView.cpp : implementation of the CMyMapDemoView class
//

#include "stdafx.h"
#include "MyMapDemo.h"

#include "MyMapDemoDoc.h"
#include "MyMapDemoView.h"

#include <math.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyMapDemoView

IMPLEMENT_DYNCREATE(CMyMapDemoView, CView)

BEGIN_MESSAGE_MAP(CMyMapDemoView, CView)
	//{{AFX_MSG_MAP(CMyMapDemoView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyMapDemoView construction/destruction

CMyMapDemoView::CMyMapDemoView()
{
	// TODO: add construction code here

}

CMyMapDemoView::~CMyMapDemoView()
{
}

BOOL CMyMapDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyMapDemoView drawing

void CMyMapDemoView::OnDraw(CDC* pDC)
{
	CMyMapDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	//设置映射模式为 MM_ANISOTROPIC
	pDC->SetMapMode(MM_ANISOTROPIC);
	//设置窗口左上角的坐标（－4Л，2），放大100倍，下同
	pDC->SetWindowOrg(int(-400*3.14159), 200);
	//设置窗口度量
	pDC->SetWindowExt(int(800*3.14159), -400);
	//获得客户区矩形
	CRect rc;
	GetClientRect(rc);
	//设置视口的坐标原点
	pDC->SetViewportOrg(0, 0);
	//设置视口度量
	pDC->SetViewportExt(rc.Width(), rc.Height());
	//创建蓝色实线画笔
	CPen pen(PS_SOLID,1,RGB(0, 0, 255));
	CPen pen1(PS_DASH, 1, RGB(0,0, 0)), *pOldPen;
	pOldPen=pDC->SelectObject(&pen);				//载入蓝色实线画笔
	pDC->MoveTo(int(-4000*3.14159), 0);
	for (double x=(-4*3.14159);x<=0; x+=0.01)				//绘制负半轴正弦曲线
	{
		pDC->LineTo(int(100*x),int(100*sin(x)));
	}
	for (x=0; x<=4*3.14159; x+=0.01)					//绘制正半轴正弦曲线
	{
		pDC->LineTo(int(100*x), int(100*sin(x)));
	}
	pDC->SelectObject(&pen1);						//载入虚线画笔
	pDC->MoveTo(int(-400*3.14159),0);				//绘制X轴
	pDC->LineTo(int(400*3.14159), 0);
	pDC->MoveTo(0, -200);						//绘制Y轴
	pDC->LineTo(0, 200);
	// 恢复设备上下文原有的画笔
	pDC->SelectObject(pOldPen);
	pen.DeleteObject();
	pen1.DeleteObject();

}

/////////////////////////////////////////////////////////////////////////////
// CMyMapDemoView printing

BOOL CMyMapDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyMapDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyMapDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMyMapDemoView diagnostics

#ifdef _DEBUG
void CMyMapDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CMyMapDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyMapDemoDoc* CMyMapDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyMapDemoDoc)));
	return (CMyMapDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyMapDemoView message handlers
