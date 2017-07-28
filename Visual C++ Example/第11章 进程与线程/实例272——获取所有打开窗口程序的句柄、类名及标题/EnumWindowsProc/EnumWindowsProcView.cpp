// EnumWindowsProcView.cpp : implementation of the CEnumWindowsProcView class
//

#include "stdafx.h"
#include "EnumWindowsProc.h"

#include "EnumWindowsProcDoc.h"
#include "EnumWindowsProcView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEnumWindowsProcView

IMPLEMENT_DYNCREATE(CEnumWindowsProcView, CListView)

BEGIN_MESSAGE_MAP(CEnumWindowsProcView, CListView)
	//{{AFX_MSG_MAP(CEnumWindowsProcView)
	ON_COMMAND(ID_GET, OnGet)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CListView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEnumWindowsProcView construction/destruction

CEnumWindowsProcView::CEnumWindowsProcView()
{
	// TODO: add construction code here

}

CEnumWindowsProcView::~CEnumWindowsProcView()
{
}

BOOL CEnumWindowsProcView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.style |= LVS_REPORT | LVS_NOSORTHEADER;//设置列表视为报表格式
	return CListView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEnumWindowsProcView drawing

void CEnumWindowsProcView::OnDraw(CDC* pDC)
{
	CEnumWindowsProcDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

void CEnumWindowsProcView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();
	CListCtrl& lc = GetListCtrl();
	lc.InsertColumn(0, _T("窗口句柄"),LVCFMT_LEFT,180);
	lc.InsertColumn(1, _T("窗口类"),LVCFMT_LEFT,180,1);
	lc.InsertColumn(2, _T("窗口标题"),LVCFMT_LEFT,280,1);
	// TODO: You may populate your ListView with items by directly accessing
	//  its list control through a call to GetListCtrl().
}

/////////////////////////////////////////////////////////////////////////////
// CEnumWindowsProcView printing

BOOL CEnumWindowsProcView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEnumWindowsProcView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEnumWindowsProcView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEnumWindowsProcView diagnostics

#ifdef _DEBUG
void CEnumWindowsProcView::AssertValid() const
{
	CListView::AssertValid();
}

void CEnumWindowsProcView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CEnumWindowsProcDoc* CEnumWindowsProcView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEnumWindowsProcDoc)));
	return (CEnumWindowsProcDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEnumWindowsProcView message handlers

void CEnumWindowsProcView::OnGet() //获取窗口信息
{
	// TODO: Add your command handler code here
	CListCtrl& lc = GetListCtrl();
	lc.DeleteAllItems();
	EnumWindows(MyEnumWindowsProc, (LPARAM)this);//遍历窗口程序	
}
BOOL CALLBACK CEnumWindowsProcView::MyEnumWindowsProc(HWND hwnd, LPARAM lParam)
{
	CEnumWindowsProcView* pView = (CEnumWindowsProcView*)lParam;
	CListCtrl& lc =pView->GetListCtrl();
	int iItem=-1;
	if (hwnd!=pView->GetParentFrame()->GetSafeHwnd()) //不是本程序
	{
		DWORD dwStyle = GetWindowLong(hwnd, GWL_STYLE);
		if ((dwStyle & WS_OVERLAPPEDWINDOW) && (dwStyle & WS_VISIBLE))
		{
			// add window to list
			CString s;
			s.Format("主窗口(%04X)",hwnd);//窗口句柄
			iItem = lc.InsertItem(lc.GetItemCount(),s);
			CWnd* pWnd = CWnd::FromHandle(hwnd);
			// 窗口类名
			::GetClassName(hwnd, s.GetBuffer(256), 256);
			int iSubitem = 1;
			lc.SetItemText(iItem,iSubitem++,s);
			// 窗口标题
			pWnd->GetWindowText(s);
			lc.SetItemText(iItem,iSubitem++,s);
		}
	}
	return TRUE;
}
