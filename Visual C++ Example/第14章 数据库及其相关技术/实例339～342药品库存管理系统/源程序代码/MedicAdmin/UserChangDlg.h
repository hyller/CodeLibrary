#if !defined(AFX_USERCHANGDLG_H__249B9D4B_2120_4C04_B2E7_E59A04DE926A__INCLUDED_)
#define AFX_USERCHANGDLG_H__249B9D4B_2120_4C04_B2E7_E59A04DE926A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UserChangDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUserChangDlg dialog

class CUserChangDlg : public CDialog
{
// Construction
public:
	CUserChangDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CUserChangDlg)
	enum { IDD = IDD_CHANGE_USER_DIALOG };
	CString	m_account;
	CString	m_password;
	CString	m_type;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUserChangDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUserChangDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERCHANGDLG_H__249B9D4B_2120_4C04_B2E7_E59A04DE926A__INCLUDED_)
