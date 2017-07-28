// MyTreeCtrl.cpp : implementation file
//

#include "StdAfx.h"
#include "BitmapTreeDemo.h"
#include "MyTreeCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyTreeCtrl

CMyTreeCtrl::CMyTreeCtrl()
{
}

CMyTreeCtrl::~CMyTreeCtrl()
{
}


BEGIN_MESSAGE_MAP(CMyTreeCtrl, CTreeCtrl)
	//{{AFX_MSG_MAP(CMyTreeCtrl)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_NOTIFY_REFLECT(TVN_ITEMEXPANDED, OnItemexpanded)
	ON_NOTIFY_REFLECT(TVN_ITEMEXPANDING, OnItemexpanding)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyTreeCtrl message handlers
BOOL CMyTreeCtrl::SetBKImage(LPCTSTR LpszResource)//加载背景位图
{

	// if this is not the first call then delete gdi objects
	if( m_bitmap.m_hObject != NULL )
		m_bitmap.DeleteObject();
	//加载位图
	HBITMAP hbmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), 
			LpszResource, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION|LR_LOADFROMFILE);
	if( hbmp == NULL ) 
		return FALSE;
	m_bitmap.Attach( hbmp );
	
	return TRUE;
}
void CMyTreeCtrl::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	CRect rcclient;
	GetClientRect(&rcclient);//获取控件客户窗口的大小

	CDC memdc;
	memdc.CreateCompatibleDC(&dc);	//创建内存DC
	CBitmap bitmap;
	bitmap.CreateCompatibleBitmap(&dc, rcclient.Width(), rcclient.Height());//创建内存位图
	memdc.SelectObject( &bitmap );
	CWnd::DefWindowProc(WM_PAINT, (WPARAM)memdc.m_hDC , 0);//在内存DC进行缺省绘图

	CBrush brush;
	brush.CreatePatternBrush(&m_bitmap);
	dc.FillRect(rcclient, &brush);	//使用位图填充客户区域DC
	//以下操作采用贴图的方式，把标准的TREEVIEW窗口贴在底图上
	CDC maskdc;
	maskdc.CreateCompatibleDC(&dc);
	CBitmap maskbitmap;
	maskbitmap.CreateBitmap(rcclient.Width(), rcclient.Height(), 1, 1, NULL);
	maskdc.SelectObject( &maskbitmap );
	maskdc.BitBlt( 0, 0, rcclient.Width(), rcclient.Height(), &memdc, 
		rcclient.left, rcclient.top, SRCCOPY);

	memdc.SetBkColor(RGB(0,0,0));          
	memdc.SetTextColor(RGB(255,255,255));  
	memdc.BitBlt(rcclient.left, rcclient.top, rcclient.Width(), rcclient.Height(), &maskdc, rcclient.left, rcclient.top, SRCAND);	
	dc.SetBkColor(RGB(255,255,255));
	dc.SetTextColor(RGB(0,0,0));
	dc.BitBlt(rcclient.left, rcclient.top, rcclient.Width(), rcclient.Height(), &maskdc, rcclient.left, rcclient.top, SRCAND);
	
	dc.BitBlt(rcclient.left, rcclient.top, rcclient.Width(), rcclient.Height(), &memdc, 
					rcclient.left, rcclient.top,SRCPAINT);
	brush.DeleteObject();//删除画刷
}


BOOL CMyTreeCtrl::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	return TRUE;
}

void CMyTreeCtrl::OnItemexpanded(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	Invalidate();//更新视图
	SetRedraw(TRUE);
	*pResult = 0;
}

void CMyTreeCtrl::OnItemexpanding(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	SetRedraw(FALSE);
	*pResult = 0;
}
