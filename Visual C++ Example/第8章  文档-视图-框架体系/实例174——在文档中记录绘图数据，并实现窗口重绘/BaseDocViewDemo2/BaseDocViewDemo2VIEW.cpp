// BaseDocViewDemo2View.cpp : implementation of the CBaseDocViewDemo2View class
//

#include "stdafx.h"
#include "BaseDocViewDemo2.h"

#include "BaseDocViewDemo2Doc.h"
#include "BaseDocViewDemo2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBaseDocViewDemo2View

IMPLEMENT_DYNCREATE(CBaseDocViewDemo2View, CView)

BEGIN_MESSAGE_MAP(CBaseDocViewDemo2View, CView)
	//{{AFX_MSG_MAP(CBaseDocViewDemo2View)
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
// CBaseDocViewDemo2View construction/destruction

CBaseDocViewDemo2View::CBaseDocViewDemo2View()
{
	// TODO: add construction code here
	m_bDraw=FALSE;
	m_Hcursor=AfxGetApp()->LoadStandardCursor(IDC_CROSS);	//载入"十字"光标
}

CBaseDocViewDemo2View::~CBaseDocViewDemo2View()
{
}

BOOL CBaseDocViewDemo2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBaseDocViewDemo2View drawing

void CBaseDocViewDemo2View::OnDraw(CDC* pDC)
{
	CBaseDocViewDemo2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	int index;
	index=pDoc->GetTotalLine();								//获取线条数目
	while(index--)
	{
		pDoc->GetLine(index)->Draw(pDC);						//绘制线条
	}
	pDC->TextOut(20,20,"此时重绘窗口，图形始终显示！");
}

/////////////////////////////////////////////////////////////////////////////
// CBaseDocViewDemo2View printing

BOOL CBaseDocViewDemo2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CBaseDocViewDemo2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CBaseDocViewDemo2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CBaseDocViewDemo2View diagnostics

#ifdef _DEBUG
void CBaseDocViewDemo2View::AssertValid() const
{
	CView::AssertValid();
}

void CBaseDocViewDemo2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBaseDocViewDemo2Doc* CBaseDocViewDemo2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBaseDocViewDemo2Doc)));
	return (CBaseDocViewDemo2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBaseDocViewDemo2View message handlers

void CBaseDocViewDemo2View::OnLButtonDown(UINT nFlags, CPoint point) 
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

void CBaseDocViewDemo2View::OnLButtonUp(UINT nFlags, CPoint point) 
{
	m_bDraw=FALSE;											//取消绘图状态
	ReleaseCapture();										//释放鼠标捕捉
	ClipCursor(NULL);										//取消鼠标区域的限制
	CView::OnLButtonUp(nFlags, point);
}

void CBaseDocViewDemo2View::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_bDraw)
	{
		CBaseDocViewDemo2Doc *pDoc=GetDocument();						//获取文档指针
		CClientDC dc(this);										//获取客户窗口DC
		dc.MoveTo(m_pOld);										//绘图
		dc.LineTo(point);
		pDoc->AddLine(m_pOld,point);				//存储线条
		m_pOld=point;		
	}
	CView::OnMouseMove(nFlags, point);
}


