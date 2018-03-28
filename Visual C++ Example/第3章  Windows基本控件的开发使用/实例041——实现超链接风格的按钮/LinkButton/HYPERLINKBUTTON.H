#if !defined(AFX_HYPERLINKBUTTON_H__EC71AD54_8713_476D_A218_EA5E18C5CC73__INCLUDED_)
#define AFX_HYPERLINKBUTTON_H__EC71AD54_8713_476D_A218_EA5E18C5CC73__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HyperLinkButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHyperLinkButton window

class CHyperLinkButton : public CButton
{
// Construction
public:
	CHyperLinkButton();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHyperLinkButton)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHyperLinkButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CHyperLinkButton)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

public:
	CFont m_fontUnderline;   //鼠标移动到按钮上时的字体
	HCURSOR m_hCurHand;      //鼠标移动到按钮上时的光标
	BOOL m_bLBtnDown;        //鼠标左键是否按下
	BOOL m_bMouseOver;       //鼠标是否处于按钮上方

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HYPERLINKBUTTON_H__EC71AD54_8713_476D_A218_EA5E18C5CC73__INCLUDED_)
