// TextProgressBar.cpp : implementation file
//

#include "stdafx.h"
#include "ColorTextProgressBar.h"
#include "TextProgressBar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTextProgressBar

CTextProgressBar::CTextProgressBar()
{
}

CTextProgressBar::~CTextProgressBar()
{
}


BEGIN_MESSAGE_MAP(CTextProgressBar, CProgressCtrl)
	//{{AFX_MSG_MAP(CTextProgressBar)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTextProgressBar message handlers
void CTextProgressBar::SetRange(int nLower, int nUpper)
{
	m_nLower = nLower;
	m_nUpper = nUpper;
	m_nCurrentPosition = nLower;
	CProgressCtrl::SetRange(nLower, nUpper);
}

int CTextProgressBar::SetPos(int nPos)
{
	m_nCurrentPosition = nPos;//获取当前进度条位置
	return (CProgressCtrl::SetPos(nPos));
}

void CTextProgressBar::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	CRect rectClient;
	GetClientRect(&rectClient);//获取进度条窗口
	CBrush brush;
	brush.CreateSolidBrush(::GetSysColor(COLOR_3DFACE));//获取系统画刷
	dc.FillRect(&rectClient, &brush);//填充进度条窗口
	VERIFY(brush.DeleteObject());//删除画刷
	if (m_nCurrentPosition <= m_nLower || m_nCurrentPosition >m_nUpper)//进度条没有运行
	{	
		return;
	}

	brush.CreateSolidBrush(RGB(0, 0,255));//创建蓝色画刷
	RECT rectFill;//定义填充区域
	float fillwidh=(float)((float)(m_nCurrentPosition-m_nLower)/(float)(m_nUpper-m_nLower))*rectClient.right;
	::SetRect(&rectFill,
					 0,       // 左上X坐标
					 0,									 //左上Y坐标
					(int)fillwidh,          //右下X坐标
					rectClient.bottom+1);			//右下Y坐标
	dc.FillRect(&rectFill,&brush);//填充进度条区域
	VERIFY(brush.DeleteObject());
	CString percent;
	percent.Format("已完成：%.0f%%", 100.0*(float)(m_nCurrentPosition-m_nLower)/(float)(m_nUpper-m_nLower));
	dc.SetTextColor(RGB(255,0,0));//设置文本颜色
	dc.SetBkMode(TRANSPARENT);//透明背景
	dc.DrawText(percent, &rectClient, DT_VCENTER|DT_CENTER|DT_SINGLELINE);//显示文本信息	
	// Do not call CProgressCtrl::OnPaint() for painting messages
}

BOOL CTextProgressBar::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
//	return TRUE;
	
	return CProgressCtrl::OnEraseBkgnd(pDC);
}
