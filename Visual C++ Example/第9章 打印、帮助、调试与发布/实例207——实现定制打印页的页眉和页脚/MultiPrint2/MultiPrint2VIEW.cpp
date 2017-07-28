// MultiPrint2View.cpp : implementation of the CMultiPrint2View class
//

#include "stdafx.h"
#include "MultiPrint2.h"

#include "MultiPrint2Doc.h"
#include "MultiPrint2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMultiPrint2View

IMPLEMENT_DYNCREATE(CMultiPrint2View, CScrollView)

BEGIN_MESSAGE_MAP(CMultiPrint2View, CScrollView)
	//{{AFX_MSG_MAP(CMultiPrint2View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMultiPrint2View construction/destruction

CMultiPrint2View::CMultiPrint2View():m_rectPrint(0,0,1440*6,-1440*10)
{
	// TODO: add construction code here
}

CMultiPrint2View::~CMultiPrint2View()
{
}

BOOL CMultiPrint2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMultiPrint2View drawing

void CMultiPrint2View::OnDraw(CDC* pDC)
{
	CMultiPrint2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->Rectangle(m_rectPrint+CRect(-1600,700,1600,-700));//绘制显示区域边框
	CFont font;
	LOGFONT ft;
	memset(&ft,0,sizeof(LOGFONT));					//为字体结构赋初值，默认值
	ft.lfHeight=450;									//字体高度
	ft.lfCharSet=GB2312_CHARSET;						//中文字符集
	strcpy(ft.lfFaceName,"楷体_GB2312");					//字符集
	font.CreateFontIndirect(&ft);
	CFont* pOldFont=pDC ->SelectObject(&font);
	int j=pDoc->m_stringArray.GetSize();
	int nHeight=(m_rectPrint.Height()-1200)/(j+2);//每行的间距
	for(int i=0;i<j;i++)
	{
		pDC->TextOut(3000,i*nHeight-1000,pDoc->m_stringArray[i]);//输出文本
	}
	pDC->SelectObject(pOldFont);
}

void CMultiPrint2View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();
	CSize sizeTotal(m_rectPrint.Width(),-m_rectPrint.Height()+700);//滚动区域
	CSize sizePage(sizeTotal.cx/2,sizeTotal.cy/2);
	CSize sizeLine(sizeTotal.cx/50,sizeTotal.cy/50);
	SetScrollSizes(MM_TWIPS, sizeTotal,sizePage,sizeLine);
}

/////////////////////////////////////////////////////////////////////////////
// CMultiPrint2View printing

BOOL CMultiPrint2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	CMultiPrint2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pInfo->SetMaxPage(pDoc->m_stringArray.GetUpperBound()/pDoc->m_LinePerPage+1);//根据每页显示行数，设置打印页数
	return DoPreparePrinting(pInfo);
}

void CMultiPrint2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMultiPrint2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMultiPrint2View diagnostics

#ifdef _DEBUG
void CMultiPrint2View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CMultiPrint2View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CMultiPrint2Doc* CMultiPrint2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMultiPrint2Doc)));
	return (CMultiPrint2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMultiPrint2View message handlers

void CMultiPrint2View::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
	CMultiPrint2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	int i,nStar,nEnd,nHeight;
	pDC->SetMapMode(MM_TWIPS);//设置映射模式
	PrintHeader(pDC);
	pDC->Rectangle(m_rectPrint+CRect(-1600,700,1600,-700));//绘制打印区域边框
	CFont font;
	LOGFONT ft;
	memset(&ft,0,sizeof(LOGFONT));					//为字体结构赋初值，默认值
	ft.lfHeight=700;									//字体高度
	ft.lfCharSet=GB2312_CHARSET;						//中文字符集
	strcpy(ft.lfFaceName,"楷体_GB2312");					//字符集
	font.CreateFontIndirect(&ft);
	CFont* pOldFont=pDC ->SelectObject(&font);//载入字体
	m_nPage=pInfo->m_nCurPage;
	nStar=(m_nPage-1)*(pDoc->m_LinePerPage);
	nEnd=nStar+(pDoc->m_LinePerPage);
	nHeight=(m_rectPrint.Height())/(pDoc->m_LinePerPage+1);//每行的间距
	for( i=nStar;i<nEnd;i++)
	{
		if(i>pDoc->m_stringArray.GetUpperBound())//超过数组边界
			break;
		pDC->TextOut(3000,(i-nStar)*nHeight-2000,pDoc->m_stringArray[i]);//输出文本
	}
	pDC->SelectObject(pOldFont);
	PrintFooter(pDC);
//	CScrollView::OnPrint(pDC, pInfo);//屏蔽默认函数对OnDraw的调用
}

void CMultiPrint2View::PrintHeader(CDC *pDC)//定制页眉
{
	pDC->TextOut(0,0,"再别康桥——徐志摩");

}

void CMultiPrint2View::PrintFooter(CDC *pDC)//定制页角
{
	CMultiPrint2Doc* pDoc = GetDocument();//获取文档指针
	ASSERT_VALID(pDoc);
	CString str;
	CPoint point(0,-1440*10-1000);
	str.Format("当前文档：%s",(LPCSTR)pDoc->GetTitle());//获取当前文档名
	pDC->TextOut(point.x,point.y,str);
	str.Format("第%d页，共%d页",m_nPage,(pDoc->m_stringArray.GetUpperBound()/pDoc->m_LinePerPage+1));
	CSize size=pDC->GetTextExtent(str);//获取输出文本宽度
	point.x+=1440*6+1600-size.cx;
	pDC->TextOut(point.x,point.y,str);
}
