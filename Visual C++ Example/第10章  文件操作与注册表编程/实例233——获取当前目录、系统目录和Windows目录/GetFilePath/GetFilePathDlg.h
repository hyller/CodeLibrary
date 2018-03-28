// GetFilePathDlg.h : header file
//

#if !defined(AFX_GETFILEPATHDLG_H__96E34AF9_837A_4C29_BCBA_14456B316735__INCLUDED_)
#define AFX_GETFILEPATHDLG_H__96E34AF9_837A_4C29_BCBA_14456B316735__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGetFilePathDlg dialog

class CGetFilePathDlg : public CDialog
{
// Construction
public:
	CGetFilePathDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGetFilePathDlg)
	enum { IDD = IDD_GETFILEPATH_DIALOG };
	CString	m_strPath;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetFilePathDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGetFilePathDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCurrent();
	afx_msg void OnWindows();
	afx_msg void OnSystem();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETFILEPATHDLG_H__96E34AF9_837A_4C29_BCBA_14456B316735__INCLUDED_)
