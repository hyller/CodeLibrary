// EventThreadDlg.h : header file
//

#if !defined(AFX_EventThreadDLG_H__0C1E7B90_CB2D_41D1_9243_31846F26E347__INCLUDED_)
#define AFX_EventThreadDLG_H__0C1E7B90_CB2D_41D1_9243_31846F26E347__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEventThreadDlg dialog

class CEventThreadDlg : public CDialog
{
// Construction
public:
	CEventThreadDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CEventThreadDlg)
	enum { IDD = IDD_EventThread_DIALOG };
	CStatic	m_ctrlIndicator;
	CProgressCtrl	m_ctrlProgress;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEventThreadDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	HICON m_hCreated;
	HICON m_hNotCreated;

	// Generated message map functions
	//{{AFX_MSG(CEventThreadDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBegin();
	afx_msg void OnCreateThread();
	afx_msg void OnKillThread();
	afx_msg void OnStop();
	//}}AFX_MSG
	afx_msg void OnThreadEnded();
	DECLARE_MESSAGE_MAP()
public:
	BOOL m_bBegin;
	BOOL m_bStopped;
	BOOL m_bCreated;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EventThreadDLG_H__0C1E7B90_CB2D_41D1_9243_31846F26E347__INCLUDED_)
