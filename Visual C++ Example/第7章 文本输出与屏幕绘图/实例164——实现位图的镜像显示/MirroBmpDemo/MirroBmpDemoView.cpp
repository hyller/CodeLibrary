// MirroBmpDemoView.cpp : implementation of the CMirroBmpDemoView class
//

#include "stdafx.h"
#include "MirroBmpDemo.h"

#include "MirroBmpDemoDoc.h"
#include "MirroBmpDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMirroBmpDemoView

IMPLEMENT_DYNCREATE(CMirroBmpDemoView, CView)

BEGIN_MESSAGE_MAP(CMirroBmpDemoView, CView)
	//{{AFX_MSG_MAP(CMirroBmpDemoView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMirroBmpDemoView construction/destruction

CMirroBmpDemoView::CMirroBmpDemoView()
{
	// TODO: add construction code here
	m_Bitmap.LoadBitmap(IDB_BITMAP1);//加载位图
}

CMirroBmpDemoView::~CMirroBmpDemoView()
{
}

BOOL CMirroBmpDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMirroBmpDemoView drawing

void CMirroBmpDemoView::OnDraw(CDC* pDC)
{
	CMirroBmpDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	int nWidth, nHeight;
	CDC *pMemDC = new CDC;
	pMemDC->CreateCompatibleDC(pDC);	//建立与显示设备兼容的内存设备场境
	//获取位图尺寸
	BITMAP bm;
	m_Bitmap.GetBitmap(&bm);
	nWidth = bm.bmWidth;
	nHeight = bm.bmHeight;	
	CBitmap *m_pBitmap = (CBitmap *) pMemDC->SelectObject(&m_Bitmap);	//将位图选入内存场境
	pDC->BitBlt(25,25,nWidth,nHeight,pMemDC,0,0,SRCCOPY);//显示位图
	CPen pen, *pOldPen;
	pen.CreatePen(PS_DASH, 1, RGB(0, 0, 255));	 				//创建虚线画笔
	pOldPen=pDC->SelectObject(&pen);
	//绘制Y轴
	pDC->MoveTo(25+nWidth+10,25);
	pDC->LineTo(25+nWidth+10,350);
	//沿Y轴镜像显示位图
	pDC->StretchBlt(25+nWidth+20 , 25, nWidth, nHeight, pMemDC, 
		nWidth-1, 0, -nWidth, nHeight, SRCCOPY );
	pDC->TextOut(25+nWidth+60, 25+nHeight+10, "Y轴镜像图像");
	//绘制X轴
	pDC->MoveTo(25,25+nHeight+10);
	pDC->LineTo(500,25+nHeight+10);
	//沿X轴镜像显示位图
	pDC->StretchBlt(25, 25+nHeight+20, nWidth, nHeight, pMemDC, 
		0, nHeight-1, nWidth, -nHeight, SRCCOPY );
	pDC->TextOut(80, 25+2*nHeight+20, "X轴镜像图像");
	//恢复设备上下文的原有画笔
	pDC->SelectObject(pOldPen);
	pen.DeleteObject();
	delete pMemDC;
}

/////////////////////////////////////////////////////////////////////////////
// CMirroBmpDemoView printing

BOOL CMirroBmpDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMirroBmpDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMirroBmpDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMirroBmpDemoView diagnostics

#ifdef _DEBUG
void CMirroBmpDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CMirroBmpDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMirroBmpDemoDoc* CMirroBmpDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMirroBmpDemoDoc)));
	return (CMirroBmpDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMirroBmpDemoView message handlers
