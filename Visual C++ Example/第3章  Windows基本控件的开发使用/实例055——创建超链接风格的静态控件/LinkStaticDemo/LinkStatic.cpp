// LinkStatic.cpp : implementation file
//

#include "stdafx.h"
#include "LinkStaticDemo.h"
#include "LinkStatic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLinkStatic

CLinkStatic::CLinkStatic()
{
	m_crText = GetSysColor(COLOR_WINDOWTEXT);//系统文本颜色
	m_bLink = TRUE;
	m_hBrush = ::CreateSolidBrush(GetSysColor(COLOR_3DFACE));//系统画刷
	::GetObject((HFONT)GetStockObject(DEFAULT_GUI_FONT),sizeof(m_lf),&m_lf);//默认字体
	m_font.CreateFontIndirect(&m_lf);
}

CLinkStatic::~CLinkStatic()
{
}


BEGIN_MESSAGE_MAP(CLinkStatic, CStatic)
	//{{AFX_MSG_MAP(CLinkStatic)
	ON_WM_LBUTTONDOWN()
	ON_WM_CTLCOLOR_REFLECT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLinkStatic message handlers
void CLinkStatic::SetTextColor(COLORREF crText)
{
	m_crText = crText;
	RedrawWindow();
}

void CLinkStatic::SetLink(BOOL bLink)
{
	m_bLink = bLink;

	if (bLink)
		ModifyStyle(0,SS_NOTIFY);
	else
		ModifyStyle(SS_NOTIFY,0);
}
void CLinkStatic::SetFontUnderline(BOOL bSet)
{	
	m_lf.lfUnderline = bSet;
	m_font.DeleteObject();
	m_font.CreateFontIndirect(&m_lf);
	RedrawWindow();
}

void CLinkStatic::SetFontSize(int nSize)
{
	nSize*=-1;
	m_lf.lfHeight = nSize;
	m_font.DeleteObject();
	m_font.CreateFontIndirect(&m_lf);
	RedrawWindow();
}

void CLinkStatic::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CString strLink;
	GetWindowText(strLink);
	ShellExecute(NULL,"open",strLink,NULL,NULL,SW_SHOWNORMAL);
	CStatic::OnLButtonDown(nFlags, point);
}

HBRUSH CLinkStatic::CtlColor(CDC* pDC, UINT nCtlColor) 
{
	// TODO: Change any attributes of the DC here
	
	// TODO: Return a non-NULL brush if the parent's handler should not be called
	if (CTLCOLOR_STATIC == nCtlColor)
	{
		pDC->SelectObject(&m_font);
		pDC->SetTextColor(m_crText);
		pDC->SetBkMode(TRANSPARENT);
	}
	return m_hBrush;
}


