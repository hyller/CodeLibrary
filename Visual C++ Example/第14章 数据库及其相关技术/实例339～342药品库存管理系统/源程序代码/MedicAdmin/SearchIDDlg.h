#if !defined(AFX_SEARCHIDDLG_H__E5FA79AC_833C_4887_B576_C74551A6692A__INCLUDED_)
#define AFX_SEARCHIDDLG_H__E5FA79AC_833C_4887_B576_C74551A6692A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SearchIDDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSearchIDDlg dialog

class CSearchIDDlg : public CDialog
{
// Construction
public:
	CSearchIDDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSearchIDDlg)
	enum { IDD = IDD_SERACH_ID_DIALOG };
	CString	m_id;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSearchIDDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSearchIDDlg)
	afx_msg void OnSearchId();
	afx_msg void OnExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEARCHIDDLG_H__E5FA79AC_833C_4887_B576_C74551A6692A__INCLUDED_)
