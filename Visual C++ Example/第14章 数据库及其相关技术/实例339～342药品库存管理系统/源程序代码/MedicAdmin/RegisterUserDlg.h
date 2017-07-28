#if !defined(AFX_REGISTERUSERDLG_H__1FA8A764_91C5_484F_A915_833CFE7112B1__INCLUDED_)
#define AFX_REGISTERUSERDLG_H__1FA8A764_91C5_484F_A915_833CFE7112B1__INCLUDED_
#include "UserSet.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RegisterUserDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRegisterUserDlg dialog

class CRegisterUserDlg : public CDialog
{
// Construction
public:
	CUserSet* theSet;
	CRegisterUserDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRegisterUserDlg)
	enum { IDD = IDD_REGISTER_USER_DIALOG };
	CListCtrl	m_registerUserList;
	CString	m_registerUserAccount;
	CString	m_registerUserName;
	CString	m_registerUserPassword;
	CString	m_registerUserPassword2;
	CString	m_registerUserType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRegisterUserDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRegisterUserDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnOk2();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGISTERUSERDLG_H__1FA8A764_91C5_484F_A915_833CFE7112B1__INCLUDED_)
