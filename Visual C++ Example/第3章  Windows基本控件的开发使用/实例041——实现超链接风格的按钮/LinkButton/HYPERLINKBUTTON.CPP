// HyperLinkButton.cpp : implementation file
//

#include "stdafx.h"
#include "LinkButton.h"
#include "HyperLinkButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHyperLinkButton

CHyperLinkButton::CHyperLinkButton()
{
	//初始化鼠标左键没有按下
	//鼠标指针也不在按钮上
	m_bMouseOver = m_bLBtnDown = FALSE;
	//加载所需光标
	m_hCurHand = AfxGetApp()->LoadCursor(IDC_HANDCUR);
}

CHyperLinkButton::~CHyperLinkButton()
{
}

BEGIN_MESSAGE_MAP(CHyperLinkButton, CButton)
	//{{AFX_MSG_MAP(CHyperLinkButton)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
	ON_WM_SETCURSOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHyperLinkButton message handlers

void CHyperLinkButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	
	CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);// 获取DC指针
	CRect rect(lpDrawItemStruct->rcItem);//定义按钮区域并初始化	
	pDC->SetBkMode(TRANSPARENT);//设置背景为透明
	UINT nBtnState = lpDrawItemStruct->itemState;//取得按钮状态
	CFont * pOldFont = NULL;
	CString strText;
	GetWindowText(strText);	//获得按钮文本
	if (m_bMouseOver)//光标在按钮上
		{
			if (nBtnState&ODS_SELECTED)//按下按钮,绘制反向矩形框
			{	
				pDC->Draw3dRect(rect,GetSysColor(COLOR_3DSHADOW), GetSysColor(COLOR_3DHILIGHT));
			}
			else//未按下按钮，绘制正常矩形框
			{
				pDC->Draw3dRect(rect,GetSysColor(COLOR_3DHILIGHT),GetSysColor(COLOR_3DSHADOW));
			}
		
			pDC->SetTextColor(RGB(0,0,255));	//字体颜色设置为蓝色

			if (m_fontUnderline.GetSafeHandle() == NULL)
			{
				CFont * pFont = GetFont();
				ASSERT(pFont);
				LOGFONT lf;
				pFont->GetLogFont(&lf);
				lf.lfUnderline = TRUE;	//加下画线
				m_fontUnderline.CreateFontIndirect(&lf);		
			}
			pOldFont = pDC->SelectObject(&m_fontUnderline);
		}
	else pDC->SetTextColor(GetSysColor(COLOR_BTNTEXT));//采用系统字体
		pDC->DrawText(strText, rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//显示按钮文本
	if (pOldFont) 
		pDC->SelectObject(pOldFont);
}


void CHyperLinkButton::OnLButtonDown(UINT nFlags, CPoint point) 
{
	m_bLBtnDown = TRUE;//鼠标左键按下
	CButton::OnLButtonDown(nFlags, point);
}

void CHyperLinkButton::OnLButtonUp(UINT nFlags, CPoint point) 
{
	m_bLBtnDown = FALSE;//鼠标左键没有按下
	if (m_bMouseOver)	
	{
		m_bMouseOver = FALSE;
		InvalidateRect(NULL);//重绘按钮
	}
	CButton::OnLButtonUp(nFlags, point);
}

void CHyperLinkButton::OnMouseMove(UINT nFlags, CPoint point) 
{
	SetTimer(1,10,NULL);//设置一个定时器，调用OnTimer
	CButton::OnMouseMove(nFlags, point);
}

void CHyperLinkButton::OnTimer(UINT nIDEvent) 
{
	static BOOL bPainted = FALSE;
	POINT pt;
	GetCursorPos(&pt);//获得光标的当前位置
	CRect rect;	
	GetWindowRect (rect);//获得按钮的窗口矩形大小	
	if (m_bLBtnDown)	    //左键按下
	{		
		KillTimer (1);//取消定时器
		if (bPainted) 
		InvalidateRect (NULL);	//重绘按钮	
		bPainted = FALSE;		
		return;	
	}
	if (!rect.PtInRect (pt))	 //当前光标不在按钮区域内
	{		
		m_bMouseOver = FALSE;
		KillTimer (1);//取消定时器
		if (bPainted)			
			InvalidateRect(NULL);
		bPainted = FALSE;
		return;	
	}
	else//光标在按钮区域，且左键并没有按下
	{
		m_bMouseOver = TRUE;
		if (!bPainted)
		{
			bPainted = TRUE;
			InvalidateRect(NULL);//重绘窗口
		}
	}
	CButton::OnTimer(nIDEvent);
}

BOOL CHyperLinkButton::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{		
	if (m_bMouseOver)   //如果光标在按钮上方则更改光标形状 
	{
		::SetCursor(m_hCurHand);
		return true;
	}	
	return CButton::OnSetCursor(pWnd, nHitTest, message);
}
