// MyFontDemoView.cpp : implementation of the CMyFontDemoView class
//

#include "stdafx.h"
#include "MyFontDemo.h"

#include "MyFontDemoDoc.h"
#include "MyFontDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyFontDemoView

IMPLEMENT_DYNCREATE(CMyFontDemoView, CView)

BEGIN_MESSAGE_MAP(CMyFontDemoView, CView)
	//{{AFX_MSG_MAP(CMyFontDemoView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyFontDemoView construction/destruction

CMyFontDemoView::CMyFontDemoView()
{
	// TODO: add construction code here

}

CMyFontDemoView::~CMyFontDemoView()
{
}

BOOL CMyFontDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyFontDemoView drawing

void CMyFontDemoView::OnDraw(CDC* pDC)
{
	CMyFontDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CFont myfont,*oldfont;	
	LOGFONT font;
	memset(&font,0,sizeof(LOGFONT));				//为字体结构赋初值，默认值
	font.lfHeight=50;								//字体高度为50
	font.lfWeight=600;
	font.lfItalic=TRUE;							//采用斜体
	font.lfUnderline=TRUE;							//带有下划线
	strcpy(font.lfFaceName,"Times New Roman");		//字符集
	myfont.CreateFontIndirect(&font); 				//创建新字体
	oldfont=pDC->SelectObject(&myfont);				//将新字体选入设备环境
	pDC->SetTextColor(RGB(100,10,210));				//文本颜色
	pDC->SetBkMode(TRANSPARENT);				//文本采用透明背景色
	pDC->TextOut(10,20,"使用CFont创建自己的字体！");	//用新字体输出"新字体"字符串
	TEXTMETRIC tm; 							//定义TEXTMETRIC结构tm
	pDC->GetTextMetrics(&tm);					//获取字体信息
	CString str1,str2,str3;
	str1.Format("字体高度为：%d个像素",tm.tmHeight);
	str2.Format("字体的平均字符宽度为：%d个像素",tm.tmAveCharWidth);
	pDC->SelectObject(oldfont);						//恢复设备环境中的旧字体
	pDC->SetTextColor(RGB(0,0,128));				//设定输出的文本所用的颜色
	pDC->TextOut(10,100,str1);						//用系统默认字体输出str1字符串
	pDC->TextOut(10,120,str2);						//用系统默认字体输出str2字符串
}

/////////////////////////////////////////////////////////////////////////////
// CMyFontDemoView printing

BOOL CMyFontDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyFontDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyFontDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMyFontDemoView diagnostics

#ifdef _DEBUG
void CMyFontDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CMyFontDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyFontDemoDoc* CMyFontDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyFontDemoDoc)));
	return (CMyFontDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyFontDemoView message handlers
