// MyEmailClientDlg.h : header file
//

#if !defined(AFX_MYEMAILCLIENTDLG_H__CA4F38A7_8965_11D6_8F32_00E04CE76240__INCLUDED_)
#define AFX_MYEMAILCLIENTDLG_H__CA4F38A7_8965_11D6_8F32_00E04CE76240__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMyEmailClientDlg dialog

class CMyEmailClientDlg : public CDialog
{
// Construction
public:
	CMyEmailClientDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyEmailClientDlg)
	enum { IDD = IDD_MYEMAILCLIENT_DIALOG };
	CString	m_Body;
	CString	m_From;
	CString	m_Password;
	CString	m_POP3;
	CString	m_SMTP;
	CString	m_To;
	CString	m_User;
	CString	m_Subject;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyEmailClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyEmailClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSend();
	afx_msg void OnRetr();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYEMAILCLIENTDLG_H__CA4F38A7_8965_11D6_8F32_00E04CE76240__INCLUDED_)
