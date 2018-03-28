// SplitFileDemoDlg.h : header file
//

#if !defined(AFX_SPLITFILEDEMODLG_H__2C86869A_13FC_467A_91A1_614360BCB4B4__INCLUDED_)
#define AFX_SPLITFILEDEMODLG_H__2C86869A_13FC_467A_91A1_614360BCB4B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSplitFileDemoDlg dialog

class CSplitFileDemoDlg : public CDialog
{
// Construction
public:
	CSplitFileDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSplitFileDemoDlg)
	enum { IDD = IDD_SPLITFILEDEMO_DIALOG };
	CString	m_strfile;
	CString	m_strpath;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSplitFileDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSplitFileDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnGetfile();
	afx_msg void OnGetpath();
	afx_msg void OnSplit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPLITFILEDEMODLG_H__2C86869A_13FC_467A_91A1_614360BCB4B4__INCLUDED_)
