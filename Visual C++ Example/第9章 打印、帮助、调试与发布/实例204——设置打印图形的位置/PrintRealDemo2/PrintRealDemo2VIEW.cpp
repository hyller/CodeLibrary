// PrintRealDemo2View.cpp : implementation of the CPrintRealDemo2View class
//

#include "stdafx.h"
#include "PrintRealDemo2.h"

#include "PrintRealDemo2Doc.h"
#include "PrintRealDemo2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPrintRealDemo2View

IMPLEMENT_DYNCREATE(CPrintRealDemo2View, CView)

BEGIN_MESSAGE_MAP(CPrintRealDemo2View, CView)
	//{{AFX_MSG_MAP(CPrintRealDemo2View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrintRealDemo2View construction/destruction

CPrintRealDemo2View::CPrintRealDemo2View()
{
	// TODO: add construction code here

}

CPrintRealDemo2View::~CPrintRealDemo2View()
{
}

BOOL CPrintRealDemo2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPrintRealDemo2View drawing

void CPrintRealDemo2View::OnDraw(CDC* pDC)
{
	CPrintRealDemo2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here	
	if(pDC->IsPrinting())//判断是否因打印或打印预览而调用OnPrepareDC()函数
	{
		pDC->SetViewportOrg(250,400);//设置视口坐标原点
	}
	//以下为显示和打印的内容
	pDC->TextOut(10,10,"实现所见即所得的打印");
	pDC->SetBkMode(TRANSPARENT);
	pDC->Rectangle(10,40,310,350);
	pDC->Ellipse(50,50,210,220);
	pDC->Ellipse(70,240,280,320);
}

/////////////////////////////////////////////////////////////////////////////
// CPrintRealDemo2View printing

BOOL CPrintRealDemo2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPrintRealDemo2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPrintRealDemo2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CPrintRealDemo2View diagnostics

#ifdef _DEBUG
void CPrintRealDemo2View::AssertValid() const
{
	CView::AssertValid();
}

void CPrintRealDemo2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPrintRealDemo2Doc* CPrintRealDemo2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPrintRealDemo2Doc)));
	return (CPrintRealDemo2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPrintRealDemo2View message handlers

void CPrintRealDemo2View::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CView::OnPrepareDC(pDC, pInfo);
	//设置映射模式
	pDC->SetMapMode(MM_ANISOTROPIC); 
	CSize winSize = CSize(1024,768);
	pDC->SetWindowExt(winSize); 								//设定窗口大小
	//得到实际设备每逻辑英寸的像素数量
	int xLogPixPerInch,yLogPixPerInch;
	xLogPixPerInch=pDC->GetDeviceCaps(LOGPIXELSX); 
	yLogPixPerInch=pDC->GetDeviceCaps(LOGPIXELSY);
	//得到设备坐标和逻辑坐标的比例 
	
	if(pDC->IsPrinting())//打印
	{		
		int xExt,yExt;
		xExt=winSize.cx*600/xLogPixPerInch;					//按照打印机扩大视口
		yExt=winSize.cy*600/yLogPixPerInch;
		pDC->SetViewportExt(xExt,yExt);						//设定视口大小
	}
	else//在屏幕显示
		pDC->SetViewportExt(winSize.cx,winSize.cy);	

}
