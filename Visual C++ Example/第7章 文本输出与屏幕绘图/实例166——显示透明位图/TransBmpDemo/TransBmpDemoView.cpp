// TransBmpDemoView.cpp : implementation of the CTransBmpDemoView class
//

#include "stdafx.h"
#include "TransBmpDemo.h"

#include "TransBmpDemoDoc.h"
#include "TransBmpDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTransBmpDemoView

IMPLEMENT_DYNCREATE(CTransBmpDemoView, CView)

BEGIN_MESSAGE_MAP(CTransBmpDemoView, CView)
	//{{AFX_MSG_MAP(CTransBmpDemoView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTransBmpDemoView construction/destruction

CTransBmpDemoView::CTransBmpDemoView()
{
	// TODO: add construction code here

}

CTransBmpDemoView::~CTransBmpDemoView()
{
}

BOOL CTransBmpDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTransBmpDemoView drawing

void CTransBmpDemoView::OnDraw(CDC* pDC)
{
	CTransBmpDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	//显示底层位图
	CBitmap bmp;
	bmp.LoadBitmap(IDB_BITMAP1);
	BITMAP bm;
	bmp.GetBitmap(&bm);
	//获取位图的大小
	int nWidth,nHeight;
	nWidth=bm.bmWidth;
	nHeight=bm.bmHeight;
	CDC MemDC;
	MemDC.CreateCompatibleDC(pDC);//创建兼容内存DC
	CBitmap* pOldBmp = MemDC.SelectObject(&bmp);
	pDC->BitBlt(20,20,nWidth,nHeight,&MemDC,0,0,SRCCOPY);//显示位图
	MemDC.SelectObject(pOldBmp);
	MemDC.DeleteDC();
	//显示上层透明位图
	DrawTransparent(pDC,20,20,RGB(0,0,0));
	pDC->TextOut(40,250,"实现显示透明位图");
}

/////////////////////////////////////////////////////////////////////////////
// CTransBmpDemoView printing

BOOL CTransBmpDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTransBmpDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTransBmpDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTransBmpDemoView diagnostics

#ifdef _DEBUG
void CTransBmpDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CTransBmpDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTransBmpDemoDoc* CTransBmpDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTransBmpDemoDoc)));
	return (CTransBmpDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTransBmpDemoView message handlers
void CTransBmpDemoView::DrawTransparent(CDC *pDC, int x, int y, COLORREF crColour)
{
	CDC dcImage, dcMask;
	CBitmap bmp;
	bmp.LoadBitmap(IDB_BITMAP2);//IDB_BITMAP2是待显示顶层图的资源ID
	BITMAP bm;
	bmp.GetBitmap(&bm);
	//获取位图的大小
	int nWidth,nHeight;
	nWidth=bm.bmWidth;
	nHeight=bm.bmHeight;
	//为图像及mask各创建一个DC
	dcImage.CreateCompatibleDC(pDC);
	dcMask.CreateCompatibleDC(pDC);
	//把图像装入image DC
	CBitmap* pOldBitmapImage=dcImage.SelectObject(&bmp);
	//为“掩码”位图创建一个单色bitmap
	CBitmap bitmapMask;
	bitmapMask.CreateBitmap(nWidth, nHeight, 1, 1, NULL); //把mask位图装入mask DC
	CBitmap* pOldBitmapMask = dcMask.SelectObject(&bitmapMask); //用透明色创建“掩码”位图
	dcImage.SetBkColor(crColour);//crColor是位图中的透明色，为黑色
	dcMask.BitBlt(0, 0, nWidth, nHeight, &dcImage, 0, 0, SRCCOPY);//分3步进行实际的绘制
	pDC->BitBlt(x, y, nWidth, nHeight, &dcImage, 0, 0, SRCINVERT);
	pDC->BitBlt(x, y, nWidth, nHeight, &dcMask, 0, 0, SRCAND);
	pDC->BitBlt(x, y, nWidth, nHeight, &dcImage, 0, 0, SRCINVERT); //恢复原先设置
	dcImage.SelectObject(pOldBitmapImage);
	dcMask.SelectObject(pOldBitmapMask);
}
