// HtmlVIEView.cpp : implementation of the CHtmlVIEView class
//

#include "stdafx.h"
#include "HtmlVIE.h"
#include "mainfrm.h"
#include "HtmlVIEDoc.h"
#include "HtmlVIEView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHtmlVIEView

IMPLEMENT_DYNCREATE(CHtmlVIEView, CHtmlView)

BEGIN_MESSAGE_MAP(CHtmlVIEView, CHtmlView)
	//{{AFX_MSG_MAP(CHtmlVIEView)
	ON_BN_CLICKED(IDC_GO, OnGo)
	ON_BN_CLICKED(IDC_REFLESH, OnReflesh)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	ON_BN_CLICKED(IDC_BACK, OnBack)
	ON_CBN_EDITCHANGE(IDC_COMBO1, OnEditchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CHtmlView::OnFilePrint)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHtmlVIEView construction/destruction

CHtmlVIEView::CHtmlVIEView()
{
	// TODO: add construction code here

}

CHtmlVIEView::~CHtmlVIEView()
{
}

BOOL CHtmlVIEView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CHtmlView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CHtmlVIEView drawing

void CHtmlVIEView::OnDraw(CDC* pDC)
{
	CHtmlVIEDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

void CHtmlVIEView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();
	// TODO: This code navigates to a popular spot on the web.
	//  change the code to go where you'd like.
	Navigate2(_T("http://www.microsoft.com/visualc/"),NULL,NULL);
}

/////////////////////////////////////////////////////////////////////////////
// CHtmlVIEView printing


/////////////////////////////////////////////////////////////////////////////
// CHtmlVIEView diagnostics

#ifdef _DEBUG
void CHtmlVIEView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CHtmlVIEView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CHtmlVIEDoc* CHtmlVIEView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHtmlVIEDoc)));
	return (CHtmlVIEDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHtmlVIEView message handlers

void CHtmlVIEView::OnGo() //连接
{
	// TODO: Add your control notification handler code here
	CClientDC dc(this);
	dc.TextOut(4,18,CString("正在连接<")+m_site+">...");					//显示信息
	Navigate2(m_site);								//打开网页
	Invalidate(FALSE);										//更新视图
	CMainFrame *pframe=(CMainFrame *)AfxGetMainWnd();			//获取主框架指针
	CDialogBar *pbar=pframe->GetDialogBar();						//获取对话条指针
	CComboBox *pcombobox;
	pcombobox=(CComboBox *)pbar->GetDlgItem(IDC_COMBO1);
	pcombobox->AddString(m_site);									//添加列表框	
}

void CHtmlVIEView::OnReflesh() //刷新
{
	// TODO: Add your control notification handler code here
	Refresh();												//刷新
	Invalidate(FALSE);										//更新视图
}

void CHtmlVIEView::OnStop() //停止
{
	// TODO: Add your control notification handler code here
	Stop();												//停止下载网页
	Invalidate(FALSE);										//更新视图

}
void CHtmlVIEView::OnBack() //返回
{
	// TODO: Add your control notification handler code here
	GoBack();
	Invalidate(FALSE);										//更新视图
}

void CHtmlVIEView::OnEditchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	CMainFrame *pframe=(CMainFrame *)AfxGetMainWnd();			//获取主框架指针
	CDialogBar *pbar=pframe->GetDialogBar();						//获取对话条指针
	pbar->GetDlgItemText(IDC_COMBO1,m_site);					//获取组合框中的数据	
}

void CHtmlVIEView::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	CMainFrame *pframe=(CMainFrame *)AfxGetMainWnd();			//获取主框架指针
	CDialogBar *pbar=pframe->GetDialogBar();						//获取对话条指针
	pbar->GetDlgItemText(IDC_COMBO1,m_site);					//获取组合框中的数据
	OnGo();												//执行打开网页		
}
