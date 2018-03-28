// HollowFontDemoView.cpp : implementation of the CHollowFontDemoView class
//

#include "stdafx.h"
#include "HollowFontDemo.h"

#include "HollowFontDemoDoc.h"
#include "HollowFontDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHollowFontDemoView

IMPLEMENT_DYNCREATE(CHollowFontDemoView, CView)

BEGIN_MESSAGE_MAP(CHollowFontDemoView, CView)
	//{{AFX_MSG_MAP(CHollowFontDemoView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHollowFontDemoView construction/destruction

CHollowFontDemoView::CHollowFontDemoView()
{
	// TODO: add construction code here
	LOGFONT font;
	memset(&font,0,sizeof(LOGFONT));				//为字体结构赋初值，默认值
	font.lfHeight=80;								//字体高度为50
	font.lfWeight=600;
	font.lfItalic=TRUE;							//采用斜体
	font.lfCharSet=GB2312_CHARSET;//中文字符集
	strcpy(font.lfFaceName,"楷体_GB2312");		//字符集
	m_font.CreateFontIndirect(&font); 			//创建新字体
}

CHollowFontDemoView::~CHollowFontDemoView()
{
}

BOOL CHollowFontDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CHollowFontDemoView drawing

void CHollowFontDemoView::OnDraw(CDC* pDC)
{
	CHollowFontDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CString str="空心立体字";
	int cx=50,cy=50;//输出文本位置
	CFont* oldfont=pDC->SelectObject(&m_font);				//将新字体选入设备环境
	pDC->SetBkMode(TRANSPARENT);				//文本采用透明背景色
	pDC->SetTextColor(::GetSysColor(COLOR_3DSHADOW));
	pDC->TextOut(cx+2,cy-2,str);
	pDC->TextOut(cx-2,cy+2,str);
	pDC->SetTextColor(::GetSysColor(COLOR_3DHILIGHT));
	pDC->TextOut(cx+1,cy-1,str);
	pDC->TextOut(cx-1,cy+1,str);
	//创建路径对象，输出文本
	pDC->BeginPath();
	pDC->TextOut(cx,cy,str);
	pDC->EndPath();
	pDC->SetPolyFillMode(WINDING);//设置填充模式
	pDC->StrokeAndFillPath();//绘制路径外观
	pDC->SelectObject(oldfont);//恢复字体

}

/////////////////////////////////////////////////////////////////////////////
// CHollowFontDemoView printing

BOOL CHollowFontDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CHollowFontDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CHollowFontDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CHollowFontDemoView diagnostics

#ifdef _DEBUG
void CHollowFontDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CHollowFontDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHollowFontDemoDoc* CHollowFontDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHollowFontDemoDoc)));
	return (CHollowFontDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHollowFontDemoView message handlers
