#if !defined(AFX_READEDIT_H__77BC67C9_C471_4CCD_BD70_CA3CB0D775BD__INCLUDED_)
#define AFX_READEDIT_H__77BC67C9_C471_4CCD_BD70_CA3CB0D775BD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ReadEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CReadEdit window

class CReadEdit : public CEdit
{
// Construction
public:
	CReadEdit();

// Attributes
public:
	void AppendString(CString str);

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReadEdit)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CReadEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(CReadEdit)
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_READEDIT_H__77BC67C9_C471_4CCD_BD70_CA3CB0D775BD__INCLUDED_)
