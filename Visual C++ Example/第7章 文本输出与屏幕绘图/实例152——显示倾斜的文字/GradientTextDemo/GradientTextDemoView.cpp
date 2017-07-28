// GradientTextDemoView.cpp : implementation of the CGradientTextDemoView class
//

#include "stdafx.h"
#include "GradientTextDemo.h"

#include "GradientTextDemoDoc.h"
#include "GradientTextDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGradientTextDemoView

IMPLEMENT_DYNCREATE(CGradientTextDemoView, CView)

BEGIN_MESSAGE_MAP(CGradientTextDemoView, CView)
	//{{AFX_MSG_MAP(CGradientTextDemoView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGradientTextDemoView construction/destruction

CGradientTextDemoView::CGradientTextDemoView()
{
	// TODO: add construction code here

}

CGradientTextDemoView::~CGradientTextDemoView()
{
}

BOOL CGradientTextDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CGradientTextDemoView drawing

void CGradientTextDemoView::OnDraw(CDC* pDC)
{
	CGradientTextDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	//得到客户区的大小
	CRect rcClient;
	GetClientRect (rcClient);	
	//创建输出字符串.
	CString str (_T ("－－旋转的文本!"));
	//输出透明背景
	pDC->SetBkMode (TRANSPARENT);
	CFont font;
	LOGFONT ft;
	memset(&ft,0,sizeof(LOGFONT));				//为字体结构赋初值，默认值
	ft.lfHeight=17;								//字体高度为80
	ft.lfWeight=600;
	ft.lfItalic=TRUE;							//采用斜体
	ft.lfCharSet=GB2312_CHARSET;				//中文字符集
	strcpy(ft.lfFaceName,"楷体_GB2312");			//字符集
	int r=10;
	int g=250;
	//每隔20度输出字符串
	for (int nAngle=0; nAngle<3600; nAngle+=200)
	{
		//设定新的旋转角度
		ft.lfEscapement=nAngle;
		
		//创建字体并选进设备场景
		font.CreateFontIndirect(&ft);
		CFont* pOldFont=pDC ->SelectObject(&font);
		pDC->SetTextColor (RGB (r,g,200));
		r+=12;
		g-=12;
		//输出字体
		pDC->TextOut(rcClient.left + rcClient.Width()/2,rcClient.top + rcClient.Height()/2,str);	
		//原来字体
		pDC->SelectObject(pOldFont);
		font.DeleteObject();
	}
}

/////////////////////////////////////////////////////////////////////////////
// CGradientTextDemoView printing

BOOL CGradientTextDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGradientTextDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGradientTextDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CGradientTextDemoView diagnostics

#ifdef _DEBUG
void CGradientTextDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CGradientTextDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGradientTextDemoDoc* CGradientTextDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGradientTextDemoDoc)));
	return (CGradientTextDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGradientTextDemoView message handlers
