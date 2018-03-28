// ComboToolbarView.cpp : implementation of the CComboToolbarView class
//

#include "stdafx.h"
#include "ComboToolbar.h"

#include "ComboToolbarDoc.h"
#include "ComboToolbarView.h"

#include "MainFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CComboToolbarView

IMPLEMENT_DYNCREATE(CComboToolbarView, CView)

BEGIN_MESSAGE_MAP(CComboToolbarView, CView)
	//{{AFX_MSG_MAP(CComboToolbarView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	
	ON_CBN_SELCHANGE(IDC_COMBO, OnSelchangeCombo)	
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CComboToolbarView construction/destruction

CComboToolbarView::CComboToolbarView()
{
	// TODO: add construction code here

}

CComboToolbarView::~CComboToolbarView()
{
}

BOOL CComboToolbarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CComboToolbarView drawing

void CComboToolbarView::OnDraw(CDC* pDC)
{
	CComboToolbarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CComboToolbarView printing

BOOL CComboToolbarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CComboToolbarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CComboToolbarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CComboToolbarView diagnostics

#ifdef _DEBUG
void CComboToolbarView::AssertValid() const
{
	CView::AssertValid();
}

void CComboToolbarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CComboToolbarDoc* CComboToolbarView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CComboToolbarDoc)));
	return (CComboToolbarDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CComboToolbarView message handlers
void CComboToolbarView::OnSelchangeCombo() 
{
	CString m_text;
	CMainFrame* fram=(CMainFrame*)AfxGetMainWnd();				//获取主窗口指针
	//获取组合框选择条目的字符
	fram->m_pCombo.GetLBText(fram->m_pCombo.GetCurSel(),m_text);	
	CClientDC dc(this);											//获得DC
	CBrush brush;
	if(m_text=="红色背景")
	{
		brush.CreateSolidBrush(RGB(255,0,0));								//创建画刷
	}
	else if(m_text=="绿色背景")
	{
		brush.CreateSolidBrush(RGB(0,255,0));								//创建画刷
	}
	else if(m_text=="蓝色背景")
	{
		brush.CreateSolidBrush(RGB(0,0,255));								//创建画刷
	}
	CRect rect;
	GetClientRect(&rect);											//获取客户区区域
	dc.FillRect(rect,&brush);										//填充客户区
	brush.DeleteObject();											//删除画刷
}

