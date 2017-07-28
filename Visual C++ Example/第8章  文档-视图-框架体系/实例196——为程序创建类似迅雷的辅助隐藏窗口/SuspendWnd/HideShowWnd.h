#if !defined(AFX_HIDESHOWWND_H__14215AA0_4679_46F5_8FCA_230B3DB9E5EA__INCLUDED_)
#define AFX_HIDESHOWWND_H__14215AA0_4679_46F5_8FCA_230B3DB9E5EA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HideShowWnd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHideShowWnd dialog

class CHideShowWnd : public CDialog
{
// Construction
public:
	CHideShowWnd(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CHideShowWnd)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHideShowWnd)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	bool flag;
	// Generated message map functions
	//{{AFX_MSG(CHideShowWnd)
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HIDESHOWWND_H__14215AA0_4679_46F5_8FCA_230B3DB9E5EA__INCLUDED_)
