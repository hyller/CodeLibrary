// PaletteDemoView.cpp : implementation of the CPaletteDemoView class
//

#include "stdafx.h"
#include "PaletteDemo.h"

#include "PaletteDemoDoc.h"
#include "PaletteDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPaletteDemoView

IMPLEMENT_DYNCREATE(CPaletteDemoView, CView)

BEGIN_MESSAGE_MAP(CPaletteDemoView, CView)
	//{{AFX_MSG_MAP(CPaletteDemoView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPaletteDemoView construction/destruction

CPaletteDemoView::CPaletteDemoView()
{
	// TODO: add construction code here
	LPLOGPALETTE pLogPal;							//定义LOGPALETTE结构
	pLogPal=(LPLOGPALETTE)malloc(sizeof(LOGPALETTE)+sizeof(PALETTEENTRY)*256);//为LOGPALETTE结构分配内存
	//分别设置LOGPALETTE结构各部分的参数
	pLogPal->palVersion=0x300;
	pLogPal->palNumEntries=256;
	for(int i=0;i<64;i++){
	pLogPal->palPalEntry[i].peRed=i*4; 					//初始化红色
	pLogPal->palPalEntry[i].peGreen=0;
	pLogPal->palPalEntry[i].peBlue=0;
	pLogPal->palPalEntry[i].peFlags=0;}
	for(i=64;i<128;i++){
	pLogPal->palPalEntry[i].peRed=0; 					//初始化绿色
	pLogPal->palPalEntry[i].peGreen=(i-64)*4;
	pLogPal->palPalEntry[i].peBlue=0;
	pLogPal->palPalEntry[i].peFlags=0;}
	for(i=128;i<192;i++){
	pLogPal->palPalEntry[i].peRed=0; 					//初始化蓝色
	pLogPal->palPalEntry[i].peGreen=0;
	pLogPal->palPalEntry[i].peBlue=(i-128)*4;
	pLogPal->palPalEntry[i].peFlags=0;}
	for(i=192;i<256;i++){
	pLogPal->palPalEntry[i].peRed=(i-192)*4; 					//初始化灰色
	pLogPal->palPalEntry[i].peGreen=(i-192)*4;
	pLogPal->palPalEntry[i].peBlue=(i-192)*4;
	pLogPal->palPalEntry[i].peFlags=0;}
	m_Palette.CreatePalette(pLogPal);							//创建逻辑调色板
}

CPaletteDemoView::~CPaletteDemoView()
{
}

BOOL CPaletteDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPaletteDemoView drawing

void CPaletteDemoView::OnDraw(CDC* pDC)
{
	CPaletteDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->SelectPalette(&m_Palette,FALSE);					//将调色板选入设备描述表
	pDC->RealizePalette();							//将逻辑调色板实现到系统调色板
	int x,y;											//存储方格的起始点坐标
	CPen mypen;
	CPen*oldpen;
	mypen.CreatePen(PS_SOLID,2,RGB(255,255,255));			//生成画笔
	oldpen=pDC->SelectObject(&mypen);						//把画笔选入设备环境	
	for(int i=0;i<64;i++)
	{
	CBrush mybrush(PALETTEINDEX(i*4));					//生成不同颜色刷子
	CBrush *oldbrush;									//生成刷子指针
	oldbrush=pDC->SelectObject(&mybrush);					//把刷子选入设备环境
	x=(i%8)*24+20;
	y=(i/8)*24+10;
	pDC->Rectangle(x,y,x+24,y+24);							//绘制方格
	pDC->SelectObject(oldbrush);							//恢复原有刷子
	}
	pDC->SelectObject(oldpen);								//恢复原有的笔
	pDC->TextOut(30,210,"创建和使用调色板");

}

/////////////////////////////////////////////////////////////////////////////
// CPaletteDemoView printing

BOOL CPaletteDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPaletteDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPaletteDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CPaletteDemoView diagnostics

#ifdef _DEBUG
void CPaletteDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CPaletteDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPaletteDemoDoc* CPaletteDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPaletteDemoDoc)));
	return (CPaletteDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPaletteDemoView message handlers
