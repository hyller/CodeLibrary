// MyHtmlCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "MyHtmlDlg.h"
#include "MyHtmlCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyHtmlCtrl

IMPLEMENT_DYNCREATE(CMyHtmlCtrl, CHtmlView)

CMyHtmlCtrl::CMyHtmlCtrl()
{
	//{{AFX_DATA_INIT(CMyHtmlCtrl)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CMyHtmlCtrl::~CMyHtmlCtrl()
{
}

void CMyHtmlCtrl::DoDataExchange(CDataExchange* pDX)
{
	CHtmlView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyHtmlCtrl)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMyHtmlCtrl, CHtmlView)
	//{{AFX_MSG_MAP(CMyHtmlCtrl)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyHtmlCtrl diagnostics
BOOL CMyHtmlCtrl::CreateFromStatic(UINT nID, CWnd* pParent)
{
	CStatic wndStatic;//静态控件
	if (!wndStatic.SubclassDlgItem(nID, pParent))//子类化
		return FALSE;
	CRect rc;
	wndStatic.GetWindowRect(&rc);//静态控件区域
	pParent->ScreenToClient(&rc);//转换为屏幕坐标
	wndStatic.DestroyWindow();
	// 创建HTML控件(CHtmlView)
	return Create(NULL,						 // 类名
		NULL,								//标题
		(WS_CHILD | WS_VISIBLE ),			 // 风格
		rc,										 // 区域
		pParent,									 // 父类
		nID,										 //  ID
		NULL);	                                    //扩展风格
}

#ifdef _DEBUG
void CMyHtmlCtrl::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CMyHtmlCtrl::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyHtmlCtrl message handlers

void CMyHtmlCtrl::OnDestroy() 
{	
	if (m_pBrowserApp) {
		m_pBrowserApp->Release();
		m_pBrowserApp = NULL;
	}
	CWnd::OnDestroy(); // bypass CView doc/frame stuff
	
}

void CMyHtmlCtrl::PostNcDestroy() 
{
	// TODO: Add your specialized code here and/or call the base class	
	//CHtmlView::PostNcDestroy();
}
