#if !defined(AFX_CHANGEPASSWORDDLG_H__35E42057_3365_42B7_946C_6A953D67074C__INCLUDED_)
#define AFX_CHANGEPASSWORDDLG_H__35E42057_3365_42B7_946C_6A953D67074C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ChangePasswordDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CChangePasswordDlg dialog

class CChangePasswordDlg : public CDialog
{
// Construction
public:
	CChangePasswordDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CChangePasswordDlg)
	enum { IDD = IDD_CHANGE_PASSWORD_DIALOG };
	CString	m_account;
	CString	m_password;
	CString	m_password2;
	CString	m_oldPassword;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChangePasswordDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CChangePasswordDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHANGEPASSWORDDLG_H__35E42057_3365_42B7_946C_6A953D67074C__INCLUDED_)
