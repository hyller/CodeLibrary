// MutexProcessSynDlg.h : header file
//

#if !defined(AFX_MutexProcessSynDLG_H__C31B9FD9_D534_462D_9BF8_32A258C7E36F__INCLUDED_)
#define AFX_MutexProcessSynDLG_H__C31B9FD9_D534_462D_9BF8_32A258C7E36F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMutexProcessSynDlg dialog

class CMutexProcessSynDlg : public CDialog
{
// Construction
public:
	CMutexProcessSynDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMutexProcessSynDlg)
	enum { IDD = IDD_MutexProcessSyn_DIALOG };
	CEdit	m_Edit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMutexProcessSynDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMutexProcessSynDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRun();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MutexProcessSynDLG_H__C31B9FD9_D534_462D_9BF8_32A258C7E36F__INCLUDED_)
