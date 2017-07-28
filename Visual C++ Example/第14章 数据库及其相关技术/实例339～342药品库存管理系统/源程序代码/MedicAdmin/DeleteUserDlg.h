#if !defined(AFX_DELETEUSERDLG_H__65671843_ABED_4699_AD0D_B29DECFFF193__INCLUDED_)
#define AFX_DELETEUSERDLG_H__65671843_ABED_4699_AD0D_B29DECFFF193__INCLUDED_

#include "userset.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DeleteUserDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDeleteUserDlg dialog

class CDeleteUserDlg : public CDialog
{
// Construction
public:
	CUserSet* theSet;
	CDeleteUserDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDeleteUserDlg)
	enum { IDD = IDD_DELETE_USER_DIALOG };
	CComboBox	m_deleteUserTypeCombo;
	CListCtrl	m_deleteUserList;
	CString	m_deleteUserAccount;
	CString	m_deleteUserType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeleteUserDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDeleteUserDlg)
	afx_msg void OnSelchangeDeleteuserTypeCombo();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DELETEUSERDLG_H__65671843_ABED_4699_AD0D_B29DECFFF193__INCLUDED_)
