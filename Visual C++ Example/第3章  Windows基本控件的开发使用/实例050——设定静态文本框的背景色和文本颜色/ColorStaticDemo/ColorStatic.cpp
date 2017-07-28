// ColorStatic.cpp : implementation file
//

#include "stdafx.h"
#include "ColorStaticDemo.h"
#include "ColorStatic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CColorStatic

CColorStatic::CColorStatic()
{
	m_bBKColor=false;
}

CColorStatic::~CColorStatic()
{
}


BEGIN_MESSAGE_MAP(CColorStatic, CStatic)
	//{{AFX_MSG_MAP(CColorStatic)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColorStatic message handlers
void CColorStatic::SetBKColor()
{
	m_bBKColor=true;
}

HBRUSH CColorStatic::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CStatic::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	pDC->SetTextColor(RGB(85,180,224));//ÉèÖÃÇ°¾°É«
	if(m_bBKColor)
		pDC->SetBkColor(RGB(255,255,255));
	else
		pDC->SetBkMode(TRANSPARENT);
//	CBrush m_brBK(RGB(0,255,255));
//	return (HBRUSH)m_brBK;
	
	// TODO: Return a different brush if the default is not desired
	return hbr;

}
