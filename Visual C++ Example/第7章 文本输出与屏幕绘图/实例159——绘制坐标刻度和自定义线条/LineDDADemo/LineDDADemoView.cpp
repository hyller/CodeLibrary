// LineDDADemoView.cpp : implementation of the CLineDDADemoView class
//

#include "stdafx.h"
#include "LineDDADemo.h"

#include "LineDDADemoDoc.h"
#include "LineDDADemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLineDDADemoView

void CALLBACK DrawChar(int X,int Y,LPARAM lpData)//绘制*号
{
	CDC* pDC;
	pDC=(CDC*)lpData;
	if(X%15==0)
	{
		pDC->SetTextColor(RGB(0,0,255));
		pDC->TextOut(X,Y,"*");
	}
}

void CALLBACK DrawMark(int X,int Y,LPARAM lpData)//绘制刻度线和刻度值
{
	CDC* pDC;
	pDC=(CDC*)lpData;
	if((X-50)%30==0)
	{
		CPen pen,*pOldPen;
		pen.CreatePen(PS_SOLID, 2, RGB(255, 0, 0)); 					//创建实线画笔
		pOldPen=pDC->SelectObject(&pen);
		//绘制刻度线
		pDC->MoveTo(X,Y);
		pDC->LineTo(X,Y-4);
		//恢复设备上下文的原有画笔
		pDC->SelectObject(pOldPen);
		//删除所创建的画笔资源
		pen.DeleteObject();
		int mark=(X-50)/30;
		CString str;
		str.Format("%d",mark);
		pDC->SetTextColor(RGB(0,0,255));
		pDC->TextOut(X-3,Y+2,str);//输出刻度值
	}
}

IMPLEMENT_DYNCREATE(CLineDDADemoView, CView)

BEGIN_MESSAGE_MAP(CLineDDADemoView, CView)
	//{{AFX_MSG_MAP(CLineDDADemoView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLineDDADemoView construction/destruction

CLineDDADemoView::CLineDDADemoView()
{
	// TODO: add construction code here

}

CLineDDADemoView::~CLineDDADemoView()
{
}

BOOL CLineDDADemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CLineDDADemoView drawing

void CLineDDADemoView::OnDraw(CDC* pDC)
{
	CLineDDADemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	//绘制自定义线条
	pDC->MoveTo(15,15);
	pDC->LineTo(100,200);
	::LineDDA(15,15,100,200,(LINEDDAPROC)DrawChar,(long)pDC);
	//绘制刻度线
	pDC->MoveTo(50,30);
	pDC->LineTo(300,30);
	::LineDDA(50,30,300,30,(LINEDDAPROC)DrawMark,(long)pDC);
}



/////////////////////////////////////////////////////////////////////////////
// CLineDDADemoView printing

BOOL CLineDDADemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLineDDADemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLineDDADemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CLineDDADemoView diagnostics

#ifdef _DEBUG
void CLineDDADemoView::AssertValid() const
{
	CView::AssertValid();
}

void CLineDDADemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLineDDADemoDoc* CLineDDADemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLineDDADemoDoc)));
	return (CLineDDADemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLineDDADemoView message handlers
