// ShowGraphicsView.cpp : implementation of the CShowGraphicsView class
//

#include "stdafx.h"
#include "ShowGraphics.h"

#include "ShowGraphicsDoc.h"
#include "ShowGraphicsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShowGraphicsView

IMPLEMENT_DYNCREATE(CShowGraphicsView, CScrollView)

BEGIN_MESSAGE_MAP(CShowGraphicsView, CScrollView)
	//{{AFX_MSG_MAP(CShowGraphicsView)
	ON_COMMAND(ID_NORMAL, OnNormal)
	ON_COMMAND(ID_ENLARGE, OnEnlarge)
	ON_COMMAND(ID_ENSMALL, OnEnsmall)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowGraphicsView construction/destruction

CShowGraphicsView::CShowGraphicsView()
{
	//初始化成员变量
	m_nScale = 100;
	m_lPciture = NULL;

}

CShowGraphicsView::~CShowGraphicsView()
{
}

BOOL CShowGraphicsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CShowGraphicsView drawing

void CShowGraphicsView::OnDraw(CDC* pDC)
{
	CShowGraphicsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	if (!m_lPciture)
		return;
	// 获取图像的长度和宽度
	long hmWidth;
	long hmHeight;
	m_lPciture->get_Width(&hmWidth);//图像的长度
	m_lPciture->get_Height(&hmHeight);//图像的宽度
	SIZE sz;
	sz.cx = hmWidth;
	sz.cy = hmHeight;
	pDC->HIMETRICtoDP (&sz);//从OLE对象尺寸转换为像素值 
	sz.cx = (sz.cx * m_nScale) / 100;
	sz.cy = (sz.cy * m_nScale) / 100;
	RECT rc;
	GetClientRect(&rc);
	SetScrollSizes(MM_TEXT, sz);//设置滚动窗口的尺寸
	// 显示图像
	m_lPciture->Render(pDC->m_hDC,
				  0,			//	水平坐标位置
				  0,			//	垂直坐标位置
				  sz.cx,		//	水平尺寸
				  sz.cy,		//	垂直尺寸
				  0,		//	源图像的水平偏移
				  hmHeight,	//	源图像的垂直偏移
				  hmWidth,		//复制源图像的水平长度
				  -hmHeight,	//复制源图像的垂直长度
				  &rc);			//显示图像的矩形区域
}

void CShowGraphicsView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

/////////////////////////////////////////////////////////////////////////////
// CShowGraphicsView printing

BOOL CShowGraphicsView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CShowGraphicsView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CShowGraphicsView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CShowGraphicsView diagnostics

#ifdef _DEBUG
void CShowGraphicsView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CShowGraphicsView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CShowGraphicsDoc* CShowGraphicsView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CShowGraphicsDoc)));
	return (CShowGraphicsDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CShowGraphicsView message handlers

void CShowGraphicsView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// TODO: Add your specialized code here and/or call the base class
	if (pSender == this)
		return;
	LPSTREAM pStream = NULL;
	DWORD dwSize = GetDocument()->GetGlobalSize();
	HGLOBAL hGlobal = GetDocument()->GetGlobalBuffer();
	if (m_lPciture)//如果已经存在图像，销毁它
	{
		m_lPciture->Release();
		m_lPciture = NULL;
		Invalidate ();
	}
	if (hGlobal == NULL)
		return;
	// 从全局内存中，创建IStream*
	HRESULT hr = CreateStreamOnHGlobal(hGlobal, TRUE, &pStream);
	_ASSERTE(SUCCEEDED(hr) && pStream);
	//从图像文件创建IPicture对象
	hr = ::OleLoadPicture(pStream, dwSize, FALSE, IID_IPicture, (LPVOID *)&m_lPciture);
	_ASSERTE(SUCCEEDED(hr) && m_lPciture);	
	pStream->Release();
	m_nScale = 100;//正常显示
	long hmWidth, hmHeight;
	m_lPciture->get_Width(&hmWidth);//图像的长度
	m_lPciture->get_Height(&hmHeight);//图像的宽度
	Invalidate ();
}

void CShowGraphicsView::OnNormal() //正常显示
{
	// TODO: Add your command handler code here
	if (m_nScale == 100)
		return;
	m_nScale = 100;
	ScrollToPosition (CPoint (0, 0));
	Invalidate ();
}

void CShowGraphicsView::OnEnlarge() //放大一倍
{
	// TODO: Add your command handler code here
	if (m_nScale == 200)
		return;
	m_nScale = 200;
	ScrollToPosition (CPoint (0, 0));
	Invalidate ();
}

void CShowGraphicsView::OnEnsmall() //缩小一倍
{
	// TODO: Add your command handler code here
	if (m_nScale == 50)
		return;
	m_nScale = 50;
	ScrollToPosition (CPoint (0, 0));
	Invalidate ();
}
