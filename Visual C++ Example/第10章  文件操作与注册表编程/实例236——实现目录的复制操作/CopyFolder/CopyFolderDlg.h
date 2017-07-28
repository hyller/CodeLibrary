// CopyFolderDlg.h : header file
//

#if !defined(AFX_COPYFOLDERDLG_H__E55F1395_91C7_4E83_BD17_068E375FCC42__INCLUDED_)
#define AFX_COPYFOLDERDLG_H__E55F1395_91C7_4E83_BD17_068E375FCC42__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCopyFolderDlg dialog

class CCopyFolderDlg : public CDialog
{
// Construction
public:
	CCopyFolderDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCopyFolderDlg)
	enum { IDD = IDD_COPYFOLDER_DIALOG };
	CString	m_strDestFolder;
	CString	m_strSourceFolder;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCopyFolderDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCopyFolderDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRfolder();
	afx_msg void OnDfolder();
	afx_msg void OnCopy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COPYFOLDERDLG_H__E55F1395_91C7_4E83_BD17_068E375FCC42__INCLUDED_)
