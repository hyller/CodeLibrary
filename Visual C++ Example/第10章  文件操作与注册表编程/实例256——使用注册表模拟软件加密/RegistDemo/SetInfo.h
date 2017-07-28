#if !defined(AFX_SETINFO_H__33E36125_DB02_4F62_A410_1C798FDCB510__INCLUDED_)
#define AFX_SETINFO_H__33E36125_DB02_4F62_A410_1C798FDCB510__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetInfo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetInfo dialog

class CSetInfo : public CDialog
{
// Construction
public:
	CSetInfo(CWnd* pParent = NULL);   // standard constructor
	BOOL bSetInfo;//是否设定了密码

// Dialog Data
	//{{AFX_DATA(CSetInfo)
	enum { IDD = IDD_ADDINFO };
	CString	m_conpass;
	CString	m_password;
	CString	m_user;
	//}}AFX_DATA



// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSetInfo)
	afx_msg void OnApply();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETINFO_H__33E36125_DB02_4F62_A410_1C798FDCB510__INCLUDED_)
