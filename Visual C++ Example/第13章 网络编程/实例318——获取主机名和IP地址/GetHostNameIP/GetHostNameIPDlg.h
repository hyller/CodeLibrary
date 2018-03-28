// GetHostNameIPDlg.h : header file
//

#if !defined(AFX_GETHOSTNAMEIPDLG_H__F22D1FFA_BFF7_4940_946B_6E6C95B3BDDD__INCLUDED_)
#define AFX_GETHOSTNAMEIPDLG_H__F22D1FFA_BFF7_4940_946B_6E6C95B3BDDD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGetHostNameIPDlg dialog

class CGetHostNameIPDlg : public CDialog
{
// Construction
public:
	CGetHostNameIPDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGetHostNameIPDlg)
	enum { IDD = IDD_GETHOSTNAMEIP_DIALOG };
	CString	m_strName;
	CString	m_strIP;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetHostNameIPDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGetHostNameIPDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnGet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETHOSTNAMEIPDLG_H__F22D1FFA_BFF7_4940_946B_6E6C95B3BDDD__INCLUDED_)
