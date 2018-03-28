#if !defined(AFX_LINKSTATIC_H__9B220F25_919E_4B8E_A423_893308A90026__INCLUDED_)
#define AFX_LINKSTATIC_H__9B220F25_919E_4B8E_A423_893308A90026__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LinkStatic.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLinkStatic window

class CLinkStatic : public CStatic
{
// Construction
public:
	CLinkStatic();

// Attributes
public:

// Operations
public:
	void SetTextColor(COLORREF crText);
	void SetLink(BOOL bLink);
	void SetFontUnderline(BOOL bSet);
	void SetFontSize(int nSize);
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLinkStatic)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLinkStatic();
	

	// Generated message map functions
protected:
	//{{AFX_MSG(CLinkStatic)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	//}}AFX_MSG
	COLORREF	m_crText;//文本颜色
	HBRUSH		m_hBrush;//画刷
	LOGFONT		m_lf;
	CFont		m_font;
	BOOL		m_bLink;//是否采用超链接
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINKSTATIC_H__9B220F25_919E_4B8E_A423_893308A90026__INCLUDED_)
