// IPEidtDemoDlg.h : header file
//

#if !defined(AFX_IPEIDTDEMODLG_H__7C738411_4AFC_46E4_9589_E92679673A6D__INCLUDED_)
#define AFX_IPEIDTDEMODLG_H__7C738411_4AFC_46E4_9589_E92679673A6D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CIPEidtDemoDlg dialog

class CIPEidtDemoDlg : public CDialog
{
// Construction
public:
	CIPEidtDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CIPEidtDemoDlg)
	enum { IDD = IDD_IPEIDTDEMO_DIALOG };
	CIPAddressCtrl	m_ctlIpAddress;
	CString	m_ipstr;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIPEidtDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CIPEidtDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnReset();
	afx_msg void OnSet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IPEIDTDEMODLG_H__7C738411_4AFC_46E4_9589_E92679673A6D__INCLUDED_)
