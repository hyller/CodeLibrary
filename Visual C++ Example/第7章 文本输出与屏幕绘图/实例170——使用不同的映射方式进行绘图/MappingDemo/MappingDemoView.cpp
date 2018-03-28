// MappingDemoView.cpp : implementation of the CMappingDemoView class
//

#include "stdafx.h"
#include "MappingDemo.h"

#include "MappingDemoDoc.h"
#include "MappingDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMappingDemoView

IMPLEMENT_DYNCREATE(CMappingDemoView, CView)

BEGIN_MESSAGE_MAP(CMappingDemoView, CView)
	//{{AFX_MSG_MAP(CMappingDemoView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMappingDemoView construction/destruction

CMappingDemoView::CMappingDemoView()
{
	// TODO: add construction code here

}

CMappingDemoView::~CMappingDemoView()
{
}

BOOL CMappingDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMappingDemoView drawing

void CMappingDemoView::OnDraw(CDC* pDC)
{
	CMappingDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CRect rect;
	GetClientRect(rect);								//获取客户区尺寸（像素）
	CPen mypen;
	CPen*oldpen;
	mypen.CreatePen(PS_SOLID,1,RGB(0,0,255));			//生成画笔
	oldpen=pDC->SelectObject(&mypen);						//把画笔选入设备环境
	pDC->SetMapMode(MM_ANISOTROPIC);//设置映射方式,X和Y可以独立地缩放
	pDC->SetWindowExt(100,100);					//设置与DC相关的窗口尺寸
	pDC->SetViewportExt(rect.right,-rect.bottom);	//设置视窗尺寸为整个客户区
	pDC->SetViewportOrg(rect.right/2, rect.bottom/2);//视窗坐标原点为客户区的中心点
	pDC->Ellipse(-50, -50, 50, 50);				//绘制椭圆
	pDC->SetMapMode(MM_ISOTROPIC);				//设置映射方式,满足纵横的比例为1：1
	pDC->SetWindowExt(100,100);					//设置与DC相关的窗口尺寸
	pDC->SetViewportExt(rect.right/2,-rect.bottom/2);//设置视窗尺寸为整个客户区的一半大小
	pDC->SetViewportOrg(rect.right/2, rect.bottom/2);//视窗坐标原点为客户区的中心点
	pDC->Ellipse(-50, -50, 50, 50);					//绘制圆

	pDC->TextOut(-80,0,"使用不同的映射方式进行绘图");
	pDC->SelectObject(oldpen);								//恢复原有的笔

}

/////////////////////////////////////////////////////////////////////////////
// CMappingDemoView printing

BOOL CMappingDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMappingDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMappingDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMappingDemoView diagnostics

#ifdef _DEBUG
void CMappingDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CMappingDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMappingDemoDoc* CMappingDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMappingDemoDoc)));
	return (CMappingDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMappingDemoView message handlers
