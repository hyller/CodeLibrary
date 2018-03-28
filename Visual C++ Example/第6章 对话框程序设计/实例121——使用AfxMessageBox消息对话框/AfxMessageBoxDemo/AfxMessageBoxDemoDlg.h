// AfxMessageBoxDemoDlg.h : header file
//

#if !defined(AFX_AFXMESSAGEBOXDEMODLG_H__8DD172E9_31E7_467A_89C4_DDFBF6E733D3__INCLUDED_)
#define AFX_AFXMESSAGEBOXDEMODLG_H__8DD172E9_31E7_467A_89C4_DDFBF6E733D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAfxMessageBoxDemoDlg dialog

class CAfxMessageBoxDemoDlg : public CDialog
{
// Construction
public:
	CAfxMessageBoxDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAfxMessageBoxDemoDlg)
	enum { IDD = IDD_AFXMESSAGEBOXDEMO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAfxMessageBoxDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAfxMessageBoxDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnQuit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AFXMESSAGEBOXDEMODLG_H__8DD172E9_31E7_467A_89C4_DDFBF6E733D3__INCLUDED_)
