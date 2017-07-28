// DynaMemuView.cpp : implementation of the CDynaMemuView class
//

#include "stdafx.h"
#include "DynaMemu.h"

#include "DynaMemuDoc.h"
#include "DynaMemuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDynaMemuView

IMPLEMENT_DYNCREATE(CDynaMemuView, CView)

BEGIN_MESSAGE_MAP(CDynaMemuView, CView)
	//{{AFX_MSG_MAP(CDynaMemuView)
	ON_COMMAND(ID_MENUCREATE, OnMenucreate)
	ON_UPDATE_COMMAND_UI(ID_MENUCREATE, OnUpdateMenucreate)
	ON_COMMAND(IDS_MENUNEW, OnMenunew)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDynaMemuView construction/destruction

CDynaMemuView::CDynaMemuView()
{
	// TODO: add construction code here
	m_bcreate=true;

}

CDynaMemuView::~CDynaMemuView()
{
}

BOOL CDynaMemuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDynaMemuView drawing

void CDynaMemuView::OnDraw(CDC* pDC)
{
	CDynaMemuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDynaMemuView printing

BOOL CDynaMemuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDynaMemuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDynaMemuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDynaMemuView diagnostics

#ifdef _DEBUG
void CDynaMemuView::AssertValid() const
{
	CView::AssertValid();
}

void CDynaMemuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDynaMemuDoc* CDynaMemuView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDynaMemuDoc)));
	return (CDynaMemuDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDynaMemuView message handlers

void CDynaMemuView::OnMenucreate() 
{
	// TODO: Add your command handler code here
	CClientDC dc(this);											//获得DC
	dc.TextOut(30,40,"添加新项菜单命令响应成功，已经添加了新菜单项!");				//输出文本
	CWnd *pWnd=AfxGetApp()->GetMainWnd( );					//获得窗口指针
	CMenu * pMenu=pWnd->GetMenu( );							//获得menu指针
	pMenu=pMenu->GetSubMenu(4);							//获得菜单项("控制"项)
	pMenu->AppendMenu(MF_SEPARATOR);						//增加分隔符
	//增加菜单项"停止程序(&S)"
	pMenu->AppendMenu(MF_STRING,IDS_MENUNEW,"新菜单项(&N)"); 										//改变条件变量
	m_bcreate=false;
}

void CDynaMemuView::OnUpdateMenucreate(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_bcreate);
}
void CDynaMemuView::OnMenunew() 
{
	// TODO: Add your command handler code here
	CClientDC dc(this);											//获得DC
	dc.TextOut(30,40,"新添加的菜单项响应成功，已删除添加的新菜单项!");				//输出文本
	CWnd *pWnd=AfxGetApp()->GetMainWnd( );					//获得窗口指针
	CMenu * pMenu=pWnd->GetMenu( );							//获得menu指针
	pMenu=pMenu->GetSubMenu(4);							//获得菜单项("控制"项)
	pMenu->RemoveMenu(2, MF_BYPOSITION);				//将"停止程序"菜单项删除
	pMenu->RemoveMenu(1, MF_BYPOSITION);					//将分隔符删除
	m_bcreate=true;
}