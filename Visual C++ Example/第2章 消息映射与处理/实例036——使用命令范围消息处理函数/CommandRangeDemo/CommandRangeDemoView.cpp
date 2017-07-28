// CommandRangeDemoView.cpp : implementation of the CCommandRangeDemoView class
//

#include "stdafx.h"
#include "CommandRangeDemo.h"

#include "CommandRangeDemoDoc.h"
#include "CommandRangeDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCommandRangeDemoView

IMPLEMENT_DYNCREATE(CCommandRangeDemoView, CView)

BEGIN_MESSAGE_MAP(CCommandRangeDemoView, CView)
	//{{AFX_MSG_MAP(CCommandRangeDemoView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	ON_COMMAND_RANGE(ID_MENUITEM1,ID_MENUITEM4,OnMenuItemCommandRange)//命令消息映射
	ON_UPDATE_COMMAND_UI_RANGE(ID_MENUITEM1,ID_MENUITEM4,OnUpdateMenuItemCommandRange)//界面消息映射
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCommandRangeDemoView construction/destruction

CCommandRangeDemoView::CCommandRangeDemoView()
{
	// TODO: add construction code here

}

CCommandRangeDemoView::~CCommandRangeDemoView()
{
}

BOOL CCommandRangeDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCommandRangeDemoView drawing

void CCommandRangeDemoView::OnDraw(CDC* pDC)
{
	CCommandRangeDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->TextOut(5,5,"使用范围消息映射宏，将一组菜单命令映射到同一个消息处理函数！");
}

/////////////////////////////////////////////////////////////////////////////
// CCommandRangeDemoView printing

BOOL CCommandRangeDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCommandRangeDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCommandRangeDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCommandRangeDemoView diagnostics

#ifdef _DEBUG
void CCommandRangeDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CCommandRangeDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCommandRangeDemoDoc* CCommandRangeDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCommandRangeDemoDoc)));
	return (CCommandRangeDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCommandRangeDemoView message handlers
void CCommandRangeDemoView::OnMenuItemCommandRange(UINT nID)
{
	switch(nID)
	{
		case ID_MENUITEM1:
			m_radio=1;
			AfxMessageBox("命令1菜单项执行成功！");
			break;
		case ID_MENUITEM2:
			m_radio=2;
			AfxMessageBox("命令2菜单项执行成功！");
			break;
		case ID_MENUITEM3:
			m_radio=3;
			AfxMessageBox("命令3菜单项执行成功！");
			break;
		case ID_MENUITEM4:
			m_radio=4;
			AfxMessageBox("命令4菜单项执行成功！");
			break;
	}
}
void CCommandRangeDemoView::OnUpdateMenuItemCommandRange(CCmdUI* pCCmdUI)
{
	switch(pCCmdUI->m_nID)
	{
		case ID_MENUITEM1:
			pCCmdUI->SetRadio(m_radio==1);
			break;
		case ID_MENUITEM2:
			pCCmdUI->SetRadio(m_radio==2);
			break;
		case ID_MENUITEM3:
			pCCmdUI->SetRadio(m_radio==3);
			break;
		case ID_MENUITEM4:
			pCCmdUI->SetRadio(m_radio==4);
			break;
	}
}