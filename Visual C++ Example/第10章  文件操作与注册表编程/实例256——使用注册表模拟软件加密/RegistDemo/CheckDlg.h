#if !defined(AFX_CHECKDLG_H__4944D467_A74F_4CCE_A6F9_B26F5EF79BE0__INCLUDED_)
#define AFX_CHECKDLG_H__4944D467_A74F_4CCE_A6F9_B26F5EF79BE0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CheckDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCheckDlg dialog

class CCheckDlg : public CDialog
{
// Construction
public:
	CCheckDlg(CWnd* pParent = NULL);   // standard constructor
	void GetPassword(CString pass);//获取存储的密码
	void GetUsername(CString user);//获取存储的用户名

// Dialog Data
	//{{AFX_DATA(CCheckDlg)
	enum { IDD = IDD_CHECK };
	CString	m_username;
	CString	m_password;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCheckDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CString username;
	CString password;

	// Generated message map functions
	//{{AFX_MSG(CCheckDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHECKDLG_H__4944D467_A74F_4CCE_A6F9_B26F5EF79BE0__INCLUDED_)
