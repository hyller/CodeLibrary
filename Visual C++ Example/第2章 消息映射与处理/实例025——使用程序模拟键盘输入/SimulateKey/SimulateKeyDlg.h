// SimulateKeyDlg.h : header file
//

#if !defined(AFX_SIMULATEKEYDLG_H__8C39A191_4171_40D1_9732_3A241CF08564__INCLUDED_)
#define AFX_SIMULATEKEYDLG_H__8C39A191_4171_40D1_9732_3A241CF08564__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSimulateKeyDlg dialog

class CSimulateKeyDlg : public CDialog
{
// Construction
public:
	CSimulateKeyDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSimulateKeyDlg)
	enum { IDD = IDD_SIMULATEKEY_DIALOG };
	CEdit	m_ctlEdit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSimulateKeyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSimulateKeyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnInput();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIMULATEKEYDLG_H__8C39A191_4171_40D1_9732_3A241CF08564__INCLUDED_)
