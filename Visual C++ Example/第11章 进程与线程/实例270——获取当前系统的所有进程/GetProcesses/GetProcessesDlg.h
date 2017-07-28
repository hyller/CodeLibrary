// GetProcessesDlg.h : header file
//

#if !defined(AFX_GETPROCESSESDLG_H__543CBF15_5B2C_4174_9E39_0475663883CB__INCLUDED_)
#define AFX_GETPROCESSESDLG_H__543CBF15_5B2C_4174_9E39_0475663883CB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGetProcessesDlg dialog

class CGetProcessesDlg : public CDialog
{
// Construction
public:
	CGetProcessesDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGetProcessesDlg)
	enum { IDD = IDD_GETPROCESSES_DIALOG };
	CListBox	m_ctlList;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetProcessesDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGetProcessesDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnGetprocess();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETPROCESSESDLG_H__543CBF15_5B2C_4174_9E39_0475663883CB__INCLUDED_)
