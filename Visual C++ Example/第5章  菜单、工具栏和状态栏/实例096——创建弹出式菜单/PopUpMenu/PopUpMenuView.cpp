// PopUpMenuView.cpp : implementation of the CPopUpMenuView class
//

#include "stdafx.h"
#include "PopUpMenu.h"

#include "PopUpMenuDoc.h"
#include "PopUpMenuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPopUpMenuView

IMPLEMENT_DYNCREATE(CPopUpMenuView, CView)

BEGIN_MESSAGE_MAP(CPopUpMenuView, CView)
	//{{AFX_MSG_MAP(CPopUpMenuView)
	ON_COMMAND(ID_MENURED, OnMenured)
	ON_UPDATE_COMMAND_UI(ID_MENURED, OnUpdateMenured)
	ON_COMMAND(ID_MENUGREEN, OnMenugreen)
	ON_UPDATE_COMMAND_UI(ID_MENUGREEN, OnUpdateMenugreen)
	ON_COMMAND(ID_MENUBLUE, OnMenublue)
	ON_UPDATE_COMMAND_UI(ID_MENUBLUE, OnUpdateMenublue)
	ON_WM_RBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPopUpMenuView construction/destruction

CPopUpMenuView::CPopUpMenuView()
{
	// TODO: add construction code here

}

CPopUpMenuView::~CPopUpMenuView()
{
}

BOOL CPopUpMenuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPopUpMenuView drawing

void CPopUpMenuView::OnDraw(CDC* pDC)
{
	CPopUpMenuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CPopUpMenuView printing

BOOL CPopUpMenuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPopUpMenuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPopUpMenuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CPopUpMenuView diagnostics

#ifdef _DEBUG
void CPopUpMenuView::AssertValid() const
{
	CView::AssertValid();
}

void CPopUpMenuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPopUpMenuDoc* CPopUpMenuView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPopUpMenuDoc)));
	return (CPopUpMenuDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPopUpMenuView message handlers

void CPopUpMenuView::OnMenured() 
{
	// TODO: Add your command handler code here
	CClientDC dc(this);											//获得DC
	CBrush brush;
	brush.CreateSolidBrush(RGB(255,0,0));//创建画刷
	CRect rect;
	GetClientRect(&rect);//获取客户区区域
	dc.FillRect(rect,&brush);//填充客户区
	brush.DeleteObject();//删除画刷
	m_menuradio=0;
}

void CPopUpMenuView::OnUpdateMenured(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CPopUpMenuView::OnMenugreen() 
{
	// TODO: Add your command handler code here
	CClientDC dc(this);											//获得DC
	CBrush brush;
	brush.CreateSolidBrush(RGB(0,255,0));//创建画刷
	CRect rect;
	GetClientRect(&rect);//获取客户区区域
	dc.FillRect(rect,&brush);//填充客户区
	brush.DeleteObject();//删除画刷
	m_menuradio=1;
	
}

void CPopUpMenuView::OnUpdateMenugreen(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code her
	
}

void CPopUpMenuView::OnMenublue() 
{

	// TODO: Add your command handler code here
	CClientDC dc(this);											//获得DC
	CBrush brush;
	brush.CreateSolidBrush(RGB(0,0,255));//创建画刷
	CRect rect;
	GetClientRect(&rect);//获取客户区区域
	dc.FillRect(rect,&brush);//填充客户区
	brush.DeleteObject();//删除画刷
	m_menuradio=2;

	
}

void CPopUpMenuView::OnUpdateMenublue(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio(m_menuradio==3);
	
}

void CPopUpMenuView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CMenu menu;
	menu.LoadMenu(IDR_MENU1);
	CMenu* pPop=menu.GetSubMenu(0);//加载下拉菜单
	pPop->CheckMenuRadioItem(0,2,m_menuradio,MF_BYPOSITION);//设置单选标记
	CPoint pt;
	GetCursorPos(&pt);											//获得鼠标位置
	pPop->TrackPopupMenu(TPM_LEFTALIGN,pt.x,pt.y,this);			//弹出浮动菜单	
	CView::OnRButtonDown(nFlags, point);
}
