// SemaphoreThreadSynDlg.h : header file
//

#if !defined(AFX_SemaphoreThreadSynDLG_H__76267292_8302_4B47_8DB4_21853F21802C__INCLUDED_)
#define AFX_SemaphoreThreadSynDLG_H__76267292_8302_4B47_8DB4_21853F21802C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSemaphoreThreadSynDlg dialog

class CSemaphoreThreadSynDlg : public CDialog
{
// Construction
public:
	CSemaphoreThreadSynDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSemaphoreThreadSynDlg)
	enum { IDD = IDD_SemaphoreThreadSyn_DIALOG };
	CEdit	m_Edit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSemaphoreThreadSynDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSemaphoreThreadSynDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCreatethread();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SemaphoreThreadSynDLG_H__76267292_8302_4B47_8DB4_21853F21802C__INCLUDED_)
