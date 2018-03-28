// DyBMPMovieView.cpp : implementation of the CDyBMPMovieView class
//

#include "stdafx.h"
#include "DyBMPMovie.h"

#include "DyBMPMovieDoc.h"
#include "DyBMPMovieView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDyBMPMovieView

IMPLEMENT_DYNCREATE(CDyBMPMovieView, CView)

BEGIN_MESSAGE_MAP(CDyBMPMovieView, CView)
	//{{AFX_MSG_MAP(CDyBMPMovieView)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDyBMPMovieView construction/destruction

CDyBMPMovieView::CDyBMPMovieView()
{
	// TODO: add construction code here
	//创建所需的背景刷子
	CBitmap* pBitmap = new CBitmap;
	ASSERT(pBitmap);
	pBitmap->LoadBitmap(IDB_BACKGROUND);//加载位图
	m_BKBrush.CreatePatternBrush(pBitmap);//创建背景刷
	delete pBitmap;//释放内存
}

CDyBMPMovieView::~CDyBMPMovieView()
{
}

BOOL CDyBMPMovieView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDyBMPMovieView drawing

void CDyBMPMovieView::OnDraw(CDC* pDC)
{
	CDyBMPMovieDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDyBMPMovieView printing

BOOL CDyBMPMovieView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDyBMPMovieView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDyBMPMovieView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDyBMPMovieView diagnostics

#ifdef _DEBUG
void CDyBMPMovieView::AssertValid() const
{
	CView::AssertValid();
}

void CDyBMPMovieView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDyBMPMovieDoc* CDyBMPMovieView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDyBMPMovieDoc)));
	return (CDyBMPMovieDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDyBMPMovieView message handlers

int CDyBMPMovieView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	for (int i=0; i<6; ++i)//装载位图图象
		m_Bitmap[i].LoadBitmap(IDB_BITMAP1+i);
	BITMAP bm;//BITMAP结构
	m_Bitmap[0].GetBitmap(&bm);
	m_nFrameWidth  = bm.bmWidth;//获得图象的宽度
	m_nFrameHeight = bm.bmHeight;//获得图象的高度
	//设置水平和垂直方向的步进量
	m_nStepX = 20;
	m_nStepY = 15;
	m_ptCurPos = CPoint(0, 0);//当前的显示位置
	m_nCurFrameNo = 0;	//开始显示的图象编号
	SetTimer(1, 150, NULL);//设定定时器
	return 0;
}

void CDyBMPMovieView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	//获得上一次显示的图象的矩形区大小
	CRect rect(m_ptCurPos.x, m_ptCurPos.y, m_ptCurPos.x+m_nFrameWidth, m_ptCurPos.y+m_nFrameHeight);
	InvalidateRect(&rect);//使这个矩形区域无效	
	UpdateWindow();//更新窗口显示
	
	//获取客户区矩形大小
	CRect ClientRect;
	GetClientRect(&ClientRect);
	//计算新的显示位置
	if (m_ptCurPos.x+m_nFrameWidth+m_nStepX >= ClientRect.right ||
		m_ptCurPos.x+m_nStepX <= ClientRect.left)//超出左右边界
		m_nStepX = -m_nStepX;
	if (m_ptCurPos.y+m_nFrameHeight+m_nStepY >= ClientRect.bottom ||
		m_ptCurPos.y+m_nStepY <= ClientRect.top)//超出上下边界
		m_nStepY = -m_nStepY;
	m_ptCurPos.x += m_nStepX; 
	m_ptCurPos.y += m_nStepY;
	//下面开始显示一副图像
	CClientDC dc(this);//获取DC
	CDC MemDC;
	if (! MemDC.CreateCompatibleDC(&dc))//创建兼容DC
		return;
	CBitmap *pOldBitmap = (CBitmap *)MemDC.SelectObject(&m_Bitmap[m_nCurFrameNo]);
	dc.BitBlt(m_ptCurPos.x, m_ptCurPos.y,
			  m_nFrameWidth, m_nFrameHeight,
			  &MemDC,
			  0, 0,
			  SRCCOPY);
	MemDC.SelectObject(pOldBitmap);
	m_nCurFrameNo++;
	if (m_nCurFrameNo >=6)
		m_nCurFrameNo = 0;
	CView::OnTimer(nIDEvent);
}

BOOL CDyBMPMovieView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	// 保存原来的图象刷子
	CBrush* pOldBrush = pDC->SelectObject(&m_BKBrush);	
	//获得需要更新的剪裁区矩形
	CRect rect;
	pDC->GetClipBox(&rect);     	
	pDC->PatBlt(rect.left, rect.top, rect.Width(), rect.Height(),PATCOPY);
	pDC->SelectObject(pOldBrush);
	return TRUE;
//	return CView::OnEraseBkgnd(pDC);
}

void CDyBMPMovieView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	m_ptCurPos = CPoint(0, 0);
	m_nCurFrameNo = 0;
}

void CDyBMPMovieView::OnDestroy() 
{
	CView::OnDestroy();
	
	// TODO: Add your message handler code here
	//清除定时器
	KillTimer(1);	
}
