// BaseDocViewDemo5View.cpp : implementation of the CBaseDocViewDemo5View class
//

#include "stdafx.h"
#include "BaseDocViewDemo5.h"

#include "BaseDocViewDemo5Doc.h"
#include "BaseDocViewDemo5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBaseDocViewDemo5View

IMPLEMENT_DYNCREATE(CBaseDocViewDemo5View, CScrollView)

BEGIN_MESSAGE_MAP(CBaseDocViewDemo5View, CScrollView)
	//{{AFX_MSG_MAP(CBaseDocViewDemo5View)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBaseDocViewDemo5View construction/destruction

CBaseDocViewDemo5View::CBaseDocViewDemo5View()
{
	// TODO: add construction code here
	m_bDraw=FALSE;
	m_Hcursor=AfxGetApp()->LoadStandardCursor(IDC_CROSS);	//载入"十字"光标
}

CBaseDocViewDemo5View::~CBaseDocViewDemo5View()
{
}

BOOL CBaseDocViewDemo5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBaseDocViewDemo5View drawing

void CBaseDocViewDemo5View::OnDraw(CDC* pDC)
{
	CBaseDocViewDemo5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	int index;
	index=pDoc->GetTotalLine();								//获取线条数目
	while(index--)
	{
		pDoc->GetLine(index)->Draw(pDC);						//绘制线条
	}

	pDC->TextOut(20,20,"实现在滚动视图窗口中绘图！");
}

/////////////////////////////////////////////////////////////////////////////
// CBaseDocViewDemo5View printing

BOOL CBaseDocViewDemo5View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CBaseDocViewDemo5View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CBaseDocViewDemo5View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CBaseDocViewDemo5View diagnostics

#ifdef _DEBUG
void CBaseDocViewDemo5View::AssertValid() const
{
	CView::AssertValid();
}

void CBaseDocViewDemo5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBaseDocViewDemo5Doc* CBaseDocViewDemo5View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBaseDocViewDemo5Doc)));
	return (CBaseDocViewDemo5Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBaseDocViewDemo5View message handlers

void CBaseDocViewDemo5View::OnLButtonDown(UINT nFlags, CPoint point) 
{

	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	OnPrepareDC(&dc);
	dc.DPtoLP(&point);									//屏幕坐标转换为逻辑坐标

	SetCursor(m_Hcursor);									//使用新光标
	m_bDraw=TRUE;											//进入绘图状态
	m_pOld=point;
	SetCapture();											//捕捉鼠标
	CRect rect;
	GetClientRect(&rect);										//获取客户窗口矩形区域
	ClientToScreen(&rect);									//转换为屏幕坐标
	ClipCursor(rect);										//限定鼠标不能移出客户窗口
	
	CScrollView::OnLButtonDown(nFlags, point);
}

void CBaseDocViewDemo5View::OnLButtonUp(UINT nFlags, CPoint point) 
{
	CClientDC dc(this);
	OnPrepareDC(&dc);
	dc.DPtoLP(&point);									//屏幕坐标转换为逻辑坐标
	m_bDraw=FALSE;											//取消绘图状态
	ReleaseCapture();										//释放鼠标捕捉
	ClipCursor(NULL);										//取消鼠标区域的限制
	CScrollView::OnLButtonUp(nFlags, point);
}

void CBaseDocViewDemo5View::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_bDraw)
	{
	
		CBaseDocViewDemo5Doc *pDoc=GetDocument();					//获取文档指针
		CClientDC dc(this);										//获取客户窗口DC
		OnPrepareDC(&dc);
		dc.DPtoLP(&point);									//屏幕坐标转换为逻辑坐标
		dc.MoveTo(m_pOld);										//绘图
		dc.LineTo(point);
		pDoc->AddLine(m_pOld,point);				//存储线条
		m_pOld=point;		
	}
	CScrollView::OnMouseMove(nFlags, point);
}



void CBaseDocViewDemo5View::OnInitialUpdate() 
{
	CScrollView::OnInitialUpdate();
	// TODO: Add your specialized code here and/or call the base class
	SIZE size={2000,1200};
	SetScrollSizes(MM_TEXT,size);								//滚动窗口的总区域
	CScrollView::OnInitialUpdate();
}
