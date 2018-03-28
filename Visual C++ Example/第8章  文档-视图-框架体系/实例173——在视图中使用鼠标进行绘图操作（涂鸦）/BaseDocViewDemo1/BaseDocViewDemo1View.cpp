// BaseDocViewDemo1View.cpp : implementation of the CBaseDocViewDemo1View class
//

#include "stdafx.h"
#include "BaseDocViewDemo1.h"

#include "BaseDocViewDemo1Doc.h"
#include "BaseDocViewDemo1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBaseDocViewDemo1View

IMPLEMENT_DYNCREATE(CBaseDocViewDemo1View, CView)

BEGIN_MESSAGE_MAP(CBaseDocViewDemo1View, CView)
	//{{AFX_MSG_MAP(CBaseDocViewDemo1View)
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
// CBaseDocViewDemo1View construction/destruction

CBaseDocViewDemo1View::CBaseDocViewDemo1View()
{
	// TODO: add construction code here
	m_bDraw=FALSE;
	m_Hcursor=AfxGetApp()->LoadStandardCursor(IDC_CROSS);	//载入"十字"光标
}

CBaseDocViewDemo1View::~CBaseDocViewDemo1View()
{
}

BOOL CBaseDocViewDemo1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBaseDocViewDemo1View drawing

void CBaseDocViewDemo1View::OnDraw(CDC* pDC)
{
	CBaseDocViewDemo1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->TextOut(20,20,"按下鼠标左键，移动鼠标即可实现绘制图形，但窗口不能自动重绘");
}

/////////////////////////////////////////////////////////////////////////////
// CBaseDocViewDemo1View printing

BOOL CBaseDocViewDemo1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CBaseDocViewDemo1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CBaseDocViewDemo1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CBaseDocViewDemo1View diagnostics

#ifdef _DEBUG
void CBaseDocViewDemo1View::AssertValid() const
{
	CView::AssertValid();
}

void CBaseDocViewDemo1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBaseDocViewDemo1Doc* CBaseDocViewDemo1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBaseDocViewDemo1Doc)));
	return (CBaseDocViewDemo1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBaseDocViewDemo1View message handlers

void CBaseDocViewDemo1View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	SetCursor(m_Hcursor);									//使用新光标
	m_bDraw=TRUE;											//进入绘图状态
	m_pOld=point;
	SetCapture();											//捕捉鼠标
	CRect rect;
	GetClientRect(&rect);										//获取客户窗口矩形区域
	ClientToScreen(&rect);									//转换为屏幕坐标
	ClipCursor(rect);										//限定鼠标不能移出客户窗口
	
	CView::OnLButtonDown(nFlags, point);
}

void CBaseDocViewDemo1View::OnLButtonUp(UINT nFlags, CPoint point) 
{
	m_bDraw=FALSE;											//取消绘图状态
	ReleaseCapture();										//释放鼠标捕捉
	ClipCursor(NULL);										//取消鼠标区域的限制
	CView::OnLButtonUp(nFlags, point);
}

void CBaseDocViewDemo1View::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
		// TODO: Add your message handler code here and/or call default
	if(m_bDraw)
	{
		CClientDC dc(this);										//获取客户窗口DC
		dc.MoveTo(m_pOld);										//绘图
		dc.LineTo(point);
		m_pOld=point;		
	}
	CView::OnMouseMove(nFlags, point);
}
