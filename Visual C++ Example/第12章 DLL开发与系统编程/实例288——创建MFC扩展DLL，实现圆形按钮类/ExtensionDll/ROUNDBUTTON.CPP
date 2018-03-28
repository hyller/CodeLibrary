// RoundButton.cpp : implementation file
//

#include "stdafx.h"
#include "RoundButton.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


// 函数声明
COLORREF GetColor(double dAngle, COLORREF clBright, COLORREF clDark);
void DrawCircle(CDC* pDC, CPoint ptCenter, LONG lRadius, COLORREF clColour, BOOL bDashed = FALSE);
void DrawCircle(CDC* pDC, CPoint ptCenter, LONG lRadius, COLORREF clBright, COLORREF clDark);

////////////////////////////////////////////////////////////////////////////
// CRoundButton

CRoundButton::CRoundButton()
{
}

CRoundButton::~CRoundButton()
{
}


BEGIN_MESSAGE_MAP(CRoundButton, CButton)
	//{{AFX_MSG_MAP(CRoundButton)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRoundButton message handlers

void CRoundButton::PreSubclassWindow() 
{
	CButton::PreSubclassWindow();
	//修改按钮为Owner draw风格
	ModifyStyle(0, BS_OWNERDRAW);
	//获得按钮矩形区域大小
	CRect WndRect;
	GetClientRect(WndRect);
	//把按钮形状变成正方形
	WndRect.bottom = WndRect.right = min(WndRect.bottom,WndRect.right);
	// 获得圆心和半径的数据
	m_ptCentre = WndRect.CenterPoint();
	m_nRadius  = WndRect.bottom/2-1;
	// 设置按钮窗体区域，确保鼠标只能点击圆形按钮部分
	m_ValidRegion.DeleteObject(); 
	SetWindowRgn(NULL, FALSE);
	m_ValidRegion.CreateEllipticRgnIndirect(WndRect);
	SetWindowRgn(m_ValidRegion, TRUE);
	// 转换到父窗口的客户区坐标
	ClientToScreen(WndRect);
	CWnd* pParent = GetParent();
	if (pParent) pParent->ScreenToClient(WndRect);
	// 调整按钮窗体大小
	MoveWindow(WndRect.left, WndRect.top, WndRect.Width(), WndRect.Height(), TRUE);
}

void CRoundButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	ASSERT(lpDrawItemStruct != NULL);
	//获取设备DC
	CDC* pDC   = CDC::FromHandle(lpDrawItemStruct->hDC);
	//取得需要绘制的矩形区域
	CRect rect = lpDrawItemStruct->rcItem;
	//获得按钮状态
	UINT nBtnState = lpDrawItemStruct->itemState;
	//获取按钮样式
	UINT nStyle = GetStyle();
	//取出圆形按钮的半径数据
	int nRadius = m_nRadius;
	//暂存设备DC
	int nSavedDC = pDC->SaveDC();

	//选择一个空刷子
	pDC->SelectStockObject(NULL_BRUSH);
	pDC->FillSolidRect(rect, ::GetSysColor(COLOR_BTNFACE));

	// 当按钮获得焦点时给它绘制一圆形的虚线框
	if (nBtnState & ODS_FOCUS)
		DrawCircle(pDC, m_ptCentre, nRadius--, RGB(0,0,0));

	// 如果不是扁平按钮应该绘制按钮按下和抬起时的边框
	if (nStyle & BS_FLAT) {
		DrawCircle(pDC, m_ptCentre, nRadius--, RGB(0,0,0));
		DrawCircle(pDC, m_ptCentre, nRadius--, ::GetSysColor(COLOR_3DHIGHLIGHT));
	} else {
		if ((nBtnState & ODS_SELECTED))	{
			DrawCircle(pDC, m_ptCentre, nRadius--, 
					   ::GetSysColor(COLOR_3DDKSHADOW), ::GetSysColor(COLOR_3DHIGHLIGHT));
			DrawCircle(pDC, m_ptCentre, nRadius--, 
					   ::GetSysColor(COLOR_3DSHADOW), ::GetSysColor(COLOR_3DLIGHT));
		} else {
			DrawCircle(pDC, m_ptCentre, nRadius--, 
					   ::GetSysColor(COLOR_3DHIGHLIGHT), ::GetSysColor(COLOR_3DDKSHADOW));
			DrawCircle(pDC, m_ptCentre, nRadius--, 
					   ::GetSysColor(COLOR_3DLIGHT), ::GetSysColor(COLOR_3DSHADOW));
		}
	}
	
	// 如果按钮上有文字的话，绘制按钮文字
	CString strText;
	//获得按钮文本
	GetWindowText(strText);

	if (!strText.IsEmpty())
	{
		CRgn rgn;
		rgn.CreateEllipticRgn(m_ptCentre.x-nRadius, m_ptCentre.y-nRadius, 
							  m_ptCentre.x+nRadius, m_ptCentre.y+nRadius);
		pDC->SelectClipRgn(&rgn);

		//获得文本的宽度和高度
		CSize SizeText = pDC->GetTextExtent(strText);
		CPoint pt = CPoint( m_ptCentre.x - SizeText.cx/2, m_ptCentre.x - SizeText.cy/2 );

		if (nBtnState & ODS_SELECTED) pt.Offset(1,1);

		//设置背景为透明
		pDC->SetBkMode(TRANSPARENT);

		if (nBtnState & ODS_DISABLED)
			pDC->DrawState(pt, SizeText, strText, DSS_DISABLED, TRUE, 0, (HBRUSH)NULL);
		else
			pDC->TextOut(pt.x, pt.y, strText);

		pDC->SelectClipRgn(NULL);
		rgn.DeleteObject();
	}

    //恢复设备DC
	pDC->RestoreDC(nSavedDC);
}

COLORREF GetColor(double dAngle, COLORREF clBright, COLORREF clDark)
{
#define Rad2Deg	180.0/3.1415 
#define LIGHT_SOURCE_ANGLE	-2.356		// -2.356 radians = -135 degrees, i.e. From top left

	ASSERT(dAngle > -3.1416 && dAngle < 3.1416);
	double dAngleDifference = LIGHT_SOURCE_ANGLE - dAngle;

	if (dAngleDifference < -3.1415) dAngleDifference = 6.293 + dAngleDifference;
	else if (dAngleDifference > 3.1415) dAngleDifference = 6.293 - dAngleDifference;

	double Weight = 0.5*(cos(dAngleDifference)+1.0);

	BYTE Red   = (BYTE) (Weight*GetRValue(clBright) + (1.0-Weight)*GetRValue(clDark));
	BYTE Green = (BYTE) (Weight*GetGValue(clBright) + (1.0-Weight)*GetGValue(clDark));
	BYTE Blue  = (BYTE) (Weight*GetBValue(clBright) + (1.0-Weight)*GetBValue(clDark));

	return RGB(Red, Green, Blue);
}

void DrawCircle(CDC* pDC, CPoint ptCenter, LONG lRadius, COLORREF clColor, BOOL bDashed)
{
	const int nDashLength = 1;
	LONG lError, lXoffset, lYoffset;
	int  nDash = 0;
	BOOL bDashOn = TRUE;

	ASSERT( (ptCenter.x + lRadius <= LONG_MAX) && (ptCenter.y + lRadius <= LONG_MAX) );
	ASSERT( (ptCenter.x - lRadius >= LONG_MIN) && (ptCenter.y - lRadius >= LONG_MIN) );

	lXoffset = lRadius;
	lYoffset = 0;
	lError   = -lRadius;

	do {
		if (bDashOn) {
			pDC->SetPixelV(ptCenter.x + lXoffset, ptCenter.y + lYoffset, clColor);
			pDC->SetPixelV(ptCenter.x + lXoffset, ptCenter.y - lYoffset, clColor);
			pDC->SetPixelV(ptCenter.x + lYoffset, ptCenter.y + lXoffset, clColor);
			pDC->SetPixelV(ptCenter.x + lYoffset, ptCenter.y - lXoffset, clColor);
			pDC->SetPixelV(ptCenter.x - lYoffset, ptCenter.y + lXoffset, clColor);
			pDC->SetPixelV(ptCenter.x - lYoffset, ptCenter.y - lXoffset, clColor);
			pDC->SetPixelV(ptCenter.x - lXoffset, ptCenter.y + lYoffset, clColor);
			pDC->SetPixelV(ptCenter.x - lXoffset, ptCenter.y - lYoffset, clColor);
		}

		lError += lYoffset++;

		if ((lError += lYoffset) >= 0)
			lError -= --lXoffset * 2;

		if (bDashed && (++nDash == nDashLength)) {
			nDash = 0;
			bDashOn = !bDashOn;
		}

	} while (lYoffset <= lXoffset);	
} 

void DrawCircle(CDC* pDC, CPoint ptCenter, LONG lRadius, COLORREF clBright, COLORREF clDark)
{
	LONG lError, lXoffset, lYoffset;

	ASSERT( (ptCenter.x + lRadius <= LONG_MAX) && (ptCenter.y + lRadius <= LONG_MAX) );
	ASSERT( (ptCenter.x - lRadius >= LONG_MIN) && (ptCenter.y - lRadius >= LONG_MIN) );

	lXoffset = lRadius;
	lYoffset = 0;
	lError   = -lRadius;

	do {
		const double Pi = 3.141592654, 
					 Pi_on_2 = Pi * 0.5,
					 Three_Pi_on_2 = Pi * 1.5;
		COLORREF clColor;
		double   dAngle = atan2(lYoffset, lXoffset);

		clColor = GetColor(dAngle, clBright, clDark);
		pDC->SetPixelV(ptCenter.x + lXoffset, ptCenter.y + lYoffset, clColor);

		clColor = GetColor(Pi_on_2 - dAngle, clBright, clDark);
		pDC->SetPixelV(ptCenter.x + lYoffset, ptCenter.y + lXoffset, clColor);

		clColor = GetColor(Pi_on_2 + dAngle, clBright, clDark);
		pDC->SetPixelV(ptCenter.x - lYoffset, ptCenter.y + lXoffset, clColor);

		clColor = GetColor(Pi - dAngle, clBright, clDark);
		pDC->SetPixelV(ptCenter.x - lXoffset, ptCenter.y + lYoffset, clColor);

		clColor = GetColor(-Pi + dAngle, clBright, clDark);
		pDC->SetPixelV(ptCenter.x - lXoffset, ptCenter.y - lYoffset, clColor);

		clColor = GetColor(-Pi_on_2 - dAngle, clBright, clDark);
		pDC->SetPixelV(ptCenter.x - lYoffset, ptCenter.y - lXoffset, clColor);

		clColor = GetColor(-Pi_on_2 + dAngle, clBright, clDark);
		pDC->SetPixelV(ptCenter.x + lYoffset, ptCenter.y - lXoffset, clColor);

		clColor = GetColor(-dAngle, clBright, clDark);
		pDC->SetPixelV(ptCenter.x + lXoffset, ptCenter.y - lYoffset, clColor);

		lError += lYoffset++;

		if ((lError += lYoffset) >= 0)
			lError -= --lXoffset * 2;

	} while (lYoffset <= lXoffset);	
} 
