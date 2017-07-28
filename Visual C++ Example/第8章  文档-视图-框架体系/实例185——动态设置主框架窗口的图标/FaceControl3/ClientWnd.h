#if !defined(AFX_CLIENTWND_H__81C4C874_9D84_41F2_9654_E3E17CC2A815__INCLUDED_)
#define AFX_CLIENTWND_H__81C4C874_9D84_41F2_9654_E3E17CC2A815__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClientWnd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CClientWnd window

class CClientWnd : public CWnd
{
// Construction
public:
	CClientWnd();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientWnd)
	//}}AFX_VIRTUAL
protected:
	 COLORREF m_rgbBack;
// Implementation
public:
	virtual ~CClientWnd();

	// Generated message map functions
protected:
	//{{AFX_MSG(CClientWnd)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnChangeframebk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTWND_H__81C4C874_9D84_41F2_9654_E3E17CC2A815__INCLUDED_)
