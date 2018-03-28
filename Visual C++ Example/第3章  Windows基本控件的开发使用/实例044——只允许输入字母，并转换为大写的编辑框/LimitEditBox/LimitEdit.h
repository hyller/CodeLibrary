#if !defined(AFX_LIMITEDIT_H__63C90169_DD17_4BD2_A8C5_7B484532A415__INCLUDED_)
#define AFX_LIMITEDIT_H__63C90169_DD17_4BD2_A8C5_7B484532A415__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LimitEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLimitEdit window

class CLimitEdit : public CEdit
{
// Construction
public:
	CLimitEdit();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLimitEdit)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLimitEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(CLimitEdit)
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIMITEDIT_H__63C90169_DD17_4BD2_A8C5_7B484532A415__INCLUDED_)
