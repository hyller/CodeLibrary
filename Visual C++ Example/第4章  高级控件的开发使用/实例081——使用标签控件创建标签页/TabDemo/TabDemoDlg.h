// TabDemoDlg.h : header file
//

#if !defined(AFX_TABDEMODLG_H__4DED03C4_938A_428D_9823_709F9B01AFB5__INCLUDED_)
#define AFX_TABDEMODLG_H__4DED03C4_938A_428D_9823_709F9B01AFB5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTabDemoDlg dialog

class CTabDemoDlg : public CDialog
{
// Construction
public:
	CTabDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTabDemoDlg)
	enum { IDD = IDD_TABDEMO_DIALOG };
	CTabCtrl	m_ctlTab;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTabDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTabDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TABDEMODLG_H__4DED03C4_938A_428D_9823_709F9B01AFB5__INCLUDED_)
