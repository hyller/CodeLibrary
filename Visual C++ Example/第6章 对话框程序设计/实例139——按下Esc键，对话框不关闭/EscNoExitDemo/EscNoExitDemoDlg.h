// EscNoExitDemoDlg.h : header file
//

#if !defined(AFX_ESCNOEXITDEMODLG_H__C4A909F5_D526_4ACE_9B22_91D1D12F705B__INCLUDED_)
#define AFX_ESCNOEXITDEMODLG_H__C4A909F5_D526_4ACE_9B22_91D1D12F705B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEscNoExitDemoDlg dialog

class CEscNoExitDemoDlg : public CDialog
{
// Construction
public:
	CEscNoExitDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CEscNoExitDemoDlg)
	enum { IDD = IDD_ESCNOEXITDEMO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEscNoExitDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEscNoExitDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCancelbutton();
	afx_msg void OnOkbutton();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ESCNOEXITDEMODLG_H__C4A909F5_D526_4ACE_9B22_91D1D12F705B__INCLUDED_)
