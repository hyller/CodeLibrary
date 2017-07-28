// FixSplitterWnd.cpp: implementation of the CFixSplitterWnd class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "StaticSplitWnd2.h"
#include "FixSplitterWnd.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
BEGIN_MESSAGE_MAP(CFixSplitterWnd, CSplitterWnd)//消息映射
	//{{AFX_MSG_MAP(CStaticSplitWnd2View)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_SETCURSOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
CFixSplitterWnd::CFixSplitterWnd(BOOL b_lock)//构造函数
{
	m_block=b_lock;
}

CFixSplitterWnd::~CFixSplitterWnd()
{

}
void CFixSplitterWnd::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(!m_block)
		CSplitterWnd::OnLButtonDown(nFlags, point);
	else
		CWnd::OnLButtonDown(nFlags, point);
}

void CFixSplitterWnd::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(!m_block)
		CSplitterWnd::OnMouseMove(nFlags, point);
	else
		CWnd::OnMouseMove(nFlags, point);
}

BOOL CFixSplitterWnd::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
	if(!m_block)
		return CSplitterWnd::OnSetCursor(pWnd, nHitTest, message);
	else
		return CWnd::OnSetCursor(pWnd, nHitTest, message);
}