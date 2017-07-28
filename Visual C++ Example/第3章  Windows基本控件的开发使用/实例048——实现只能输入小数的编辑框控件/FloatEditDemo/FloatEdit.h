#if !defined(AFX_FLOATEDIT_H__E7DFBEFD_83D9_4A9D_A254_D1FAEA20DB8B__INCLUDED_)
#define AFX_FLOATEDIT_H__E7DFBEFD_83D9_4A9D_A254_D1FAEA20DB8B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FloatEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFloatEdit window

class CFloatEdit : public CEdit
{
// Construction
public:
	CFloatEdit();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFloatEdit)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFloatEdit();

	int GetStringNum(CString str);

	// Generated message map functions
protected:
	//{{AFX_MSG(CFloatEdit)
	afx_msg void OnChange();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLOATEDIT_H__E7DFBEFD_83D9_4A9D_A254_D1FAEA20DB8B__INCLUDED_)
