#if !defined(AFX_BITMAPSTATUSBAR_H__319ED174_99F2_4AEE_B34E_879D6F0A20D2__INCLUDED_)
#define AFX_BITMAPSTATUSBAR_H__319ED174_99F2_4AEE_B34E_879D6F0A20D2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BitmapStatusBar.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBitmapStatusBar window

class CBitmapStatusBar : public CStatusBar
{
// Construction
public:
	CBitmapStatusBar();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBitmapStatusBar)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBitmapStatusBar();

	// Generated message map functions
protected:
	//{{AFX_MSG(CBitmapStatusBar)
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	//}}AFX_MSG
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BITMAPSTATUSBAR_H__319ED174_99F2_4AEE_B34E_879D6F0A20D2__INCLUDED_)
