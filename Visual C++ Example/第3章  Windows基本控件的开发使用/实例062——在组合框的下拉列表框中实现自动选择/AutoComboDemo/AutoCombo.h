#if !defined(AFX_AUTOCOMBO_H__B04B324D_9A5A_4FB7_9066_9EF9EEF5D9BF__INCLUDED_)
#define AFX_AUTOCOMBO_H__B04B324D_9A5A_4FB7_9066_9EF9EEF5D9BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AutoCombo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAutoCombo window

class CAutoCombo : public CComboBox
{
// Construction
public:
	CAutoCombo();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAutoCombo)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAutoCombo();

	// Generated message map functions
protected:
	//{{AFX_MSG(CAutoCombo)
	afx_msg void OnEditupdate();
	//}}AFX_MSG
	BOOL m_bAutoComplete;
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUTOCOMBO_H__B04B324D_9A5A_4FB7_9066_9EF9EEF5D9BF__INCLUDED_)
