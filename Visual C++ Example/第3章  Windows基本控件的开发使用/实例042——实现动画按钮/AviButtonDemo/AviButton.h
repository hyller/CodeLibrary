#if !defined(AFX_AVIBUTTON_H__0AC65304_AD25_466E_8D11_73C2BA5B72A6__INCLUDED_)
#define AFX_AVIBUTTON_H__0AC65304_AD25_466E_8D11_73C2BA5B72A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AviButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAviButton window

class CAviButton : public CButton
{
// Construction
public:
	CAviButton();

// Attributes
public:
	UINT m_AviID;//AVI资源ID
// Operations
public:
	

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAviButton)
	public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAviButton();
	void LoadAVI(UINT nAviID);//加载AVI资源

	// Generated message map functions
protected:
	//{{AFX_MSG(CAviButton)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	CAnimateCtrl	m_AnimateCtrl;//动画控件
    BOOL m_bPlaying;//播放控制
	void DrawButton(CDC* pDC, UINT nState, CRect rect);
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AVIBUTTON_H__0AC65304_AD25_466E_8D11_73C2BA5B72A6__INCLUDED_)
