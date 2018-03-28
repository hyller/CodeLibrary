// AviButton.cpp : implementation file
//

#include "stdafx.h"
#include "AviButtonDemo.h"
#include "AviButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAviButton

CAviButton::CAviButton()
{
	m_AviID = 0;
    m_bPlaying = FALSE;
}

CAviButton::~CAviButton()
{
}

BEGIN_MESSAGE_MAP(CAviButton, CButton)
	//{{AFX_MSG_MAP(CAviButton)
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAviButton message handlers

BOOL CAviButton::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

void CAviButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	// TODO: Add your code to draw the specified item
	CRect rect;
    GetClientRect(rect);//获取按钮的尺寸
    if (!::IsWindow(m_AnimateCtrl))
    {
       m_AnimateCtrl.Create(WS_CHILD |WS_VISIBLE,rect,this,0);//创建动画按钮控件
       m_AnimateCtrl.Open(m_AviID);
       m_AnimateCtrl.GetClientRect(rect);
   	   VERIFY(SetWindowPos(NULL, -1, -1, rect.Width()+4, rect.Height()+4,
		SWP_NOMOVE|SWP_NOZORDER|SWP_NOREDRAW|SWP_NOACTIVATE));
       rect.OffsetRect(2,2);  
       m_AnimateCtrl.MoveWindow(rect); //设置动画控件的位置
    }
    CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);//按钮控件DC
	UINT nState = lpDrawItemStruct->itemState;
    CRect buttonRect;
    GetClientRect(buttonRect);
  	if (IsWindowEnabled())
		nState &= ~ODS_DISABLED;
	else
		nState |= ODS_DISABLED;
    DrawButton(pDC, nState, buttonRect);//绘制按钮的边界	
}

void CAviButton::LoadAVI(UINT nAviID)
{
    m_AviID =nAviID;
}

void CAviButton::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	ClientToScreen(&point);
	CRect rcWindow;
	GetWindowRect(rcWindow);
	BOOL bNewMouseOverButton = rcWindow.PtInRect(point);//确定鼠标在按钮区域内
    unsigned long nROnly = ES_READONLY;
    BOOL bTest = (GetStyle() &  nROnly) != nROnly;
	if (bNewMouseOverButton && IsWindowEnabled() && bTest)
    {
        if (::IsWindow(m_AnimateCtrl) && !m_bPlaying)
        {
            m_AnimateCtrl.Play(0,-1,1);//播放动画
            m_bPlaying = TRUE;
            SetCapture();//捕捉鼠标
        }
		else
		{
			m_bPlaying = FALSE;
		}
    }
    else//为只读按钮
    {
        m_bPlaying = FALSE;
        ReleaseCapture();//释放鼠标
    }	
	CButton::OnMouseMove(nFlags, point);
}
//绘制按钮边界
void CAviButton::DrawButton(CDC* pDC, UINT nState, CRect rect)
{
    COLORREF upCol,downCol,edgeCol;
    edgeCol=RGB(0,0,0);
    BOOL bRevers = FALSE;
	if ((nState & ODS_SELECTED) == ODS_SELECTED)//按钮被按下
	{
		//  Pressed 
        upCol=RGB(0,0,0);
        edgeCol=RGB(128,128,128);
        downCol=RGB(0,0,0);
        bRevers = TRUE;
    }
	else
    {   // 正常状态
        upCol=RGB(255,255,255);
        downCol=RGB(128,128,128);
	}
    CPen* pOldPen = NULL;
    BOOL pen1Created;
    CPen pen1;
    BOOL pen2Created;
    CPen pen2;
    if (pen1Created = pen1.CreatePen(PS_SOLID, 1, upCol))  
        pOldPen = pDC->SelectObject( &pen1 );
    pDC->MoveTo(1,rect.Height()-1);
    pDC->LineTo(1,1);                                                             
    pDC->LineTo(rect.Width()-1,1);
    pDC->MoveTo(0,rect.Height()-1);
    pDC->LineTo(0,0);                                                             
    pDC->LineTo(rect.Width()-1,0);
    if (pen2Created = pen2.CreatePen(PS_SOLID, 1, downCol))  
    {
        pDC->SelectObject( &pen2 );
    } 
    if (pen1Created) pen1.DeleteObject();
        pen1Created = FALSE;
    pDC->MoveTo(rect.Width()-1,0);
    pDC->LineTo(rect.Width()-1,rect.Height()-1);
    pDC->LineTo(0,rect.Height()-1);
    pDC->MoveTo(rect.Width()-2,1);
    pDC->LineTo(rect.Width()-2,rect.Height()-2);
    pDC->LineTo(0,rect.Height()-2);
    if (pen2Created) pen2.DeleteObject();
        pen2Created = FALSE;
    if (pen1Created = pen1.CreatePen(PS_SOLID, 1, edgeCol)) 
        pOldPen = pDC->SelectObject( &pen1 );

    if (bRevers)
    {
        pDC->MoveTo(1,rect.Height()-2);
        pDC->LineTo(1,1);                                                             
        pDC->LineTo(rect.Width()-2,1);
    }
    else
    {
        pDC->MoveTo(rect.Width()-1,0);
        pDC->LineTo(rect.Width()-1,rect.Height()-1);
        pDC->LineTo(-1,rect.Height()-1);
    }

    if (pen1Created) pen1.DeleteObject();
        pen1Created = FALSE;

    if (pOldPen != NULL) pDC->SelectObject( pOldPen );

}