#if !defined(AFX_LOGINDLG_H__C733C7B6_2C4F_43B4_AD8B_BFFA529F0982__INCLUDED_)
#define AFX_LOGINDLG_H__C733C7B6_2C4F_43B4_AD8B_BFFA529F0982__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LogInDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLogInDlg dialog

class CLogInDlg : public CDialog
{
// Construction
public:
	CLogInDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLogInDlg)
	enum { IDD = IDD_LOGIN_DIALOG };
	CString	m_userAccount;
	CString	m_userPassword;
	CString	m_userType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLogInDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLogInDlg)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGINDLG_H__C733C7B6_2C4F_43B4_AD8B_BFFA529F0982__INCLUDED_)
