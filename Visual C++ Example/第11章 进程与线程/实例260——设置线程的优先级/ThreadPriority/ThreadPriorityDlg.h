// ThreadPriorityDlg.h : header file
//

#if !defined(AFX_THREADPRIORITYDLG_H__97CBA655_18E0_4534_82E4_1DF46180D994__INCLUDED_)
#define AFX_THREADPRIORITYDLG_H__97CBA655_18E0_4534_82E4_1DF46180D994__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CThreadPriorityDlg dialog

class CThreadPriorityDlg : public CDialog
{
// Construction
public:
	CThreadPriorityDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CThreadPriorityDlg)
	enum { IDD = IDD_THREADPRIORITY_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThreadPriorityDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CThreadPriorityDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStart();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THREADPRIORITYDLG_H__97CBA655_18E0_4534_82E4_1DF46180D994__INCLUDED_)
