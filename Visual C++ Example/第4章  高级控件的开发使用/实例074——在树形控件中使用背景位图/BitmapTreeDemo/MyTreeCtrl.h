#if !defined(AFX_MYTREECTRL_H__4D6A3800_2048_463A_8253_125578953E5D__INCLUDED_)
#define AFX_MYTREECTRL_H__4D6A3800_2048_463A_8253_125578953E5D__INCLUDED_

#include "StdAfx.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyTreeCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyTreeCtrl window

class CMyTreeCtrl : public CTreeCtrl
{
// Construction
public:
	CMyTreeCtrl();

// Attributes
public:
	BOOL SetBKImage(LPCTSTR LpszResource);

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyTreeCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyTreeCtrl();

	// Generated message map functions
protected:
	CBitmap m_bitmap;
	//{{AFX_MSG(CMyTreeCtrl)
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnItemexpanded(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnItemexpanding(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYTREECTRL_H__4D6A3800_2048_463A_8253_125578953E5D__INCLUDED_)
