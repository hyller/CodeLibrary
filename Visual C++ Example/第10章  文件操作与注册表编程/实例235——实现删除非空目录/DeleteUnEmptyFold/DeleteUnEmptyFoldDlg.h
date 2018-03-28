// DeleteUnEmptyFoldDlg.h : header file
//

#if !defined(AFX_DELETEUNEMPTYFOLDDLG_H__DF246AC3_5F12_4971_9A22_83E1C5C9AC3A__INCLUDED_)
#define AFX_DELETEUNEMPTYFOLDDLG_H__DF246AC3_5F12_4971_9A22_83E1C5C9AC3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDeleteUnEmptyFoldDlg dialog

class CDeleteUnEmptyFoldDlg : public CDialog
{
// Construction
public:
	CDeleteUnEmptyFoldDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDeleteUnEmptyFoldDlg)
	enum { IDD = IDD_DELETEUNEMPTYFOLD_DIALOG };
	CString	m_strFold;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeleteUnEmptyFoldDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	void RecursiveDelete(CString szPath);
	// Generated message map functions
	//{{AFX_MSG(CDeleteUnEmptyFoldDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnGetfold();
	afx_msg void OnDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DELETEUNEMPTYFOLDDLG_H__DF246AC3_5F12_4971_9A22_83E1C5C9AC3A__INCLUDED_)
