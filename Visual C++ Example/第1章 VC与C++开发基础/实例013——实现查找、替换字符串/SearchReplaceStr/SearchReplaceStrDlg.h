// SearchReplaceStrDlg.h : header file
//

#if !defined(AFX_SEARCHREPLACESTRDLG_H__FE346A22_72ED_4937_907A_939933E174CE__INCLUDED_)
#define AFX_SEARCHREPLACESTRDLG_H__FE346A22_72ED_4937_907A_939933E174CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSearchReplaceStrDlg dialog

class CSearchReplaceStrDlg : public CDialog
{
// Construction
public:
	CSearchReplaceStrDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSearchReplaceStrDlg)
	enum { IDD = IDD_SEARCHREPLACESTR_DIALOG };
	CString	m_strData;
	CString	m_strFind;
	CString	m_strReplace;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSearchReplaceStrDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSearchReplaceStrDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnReplace();
	afx_msg void OnSearch();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEARCHREPLACESTRDLG_H__FE346A22_72ED_4937_907A_939933E174CE__INCLUDED_)
