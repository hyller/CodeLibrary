// IEOptionsDlg.h : header file
//

#if !defined(AFX_IEOPTIONSDLG_H__F088FE6A_7BF7_4877_A2F5_76359379DF44__INCLUDED_)
#define AFX_IEOPTIONSDLG_H__F088FE6A_7BF7_4877_A2F5_76359379DF44__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CIEOptionsDlg dialog

class CIEOptionsDlg : public CDialog
{
// Construction
public:
	CIEOptionsDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CIEOptionsDlg)
	enum { IDD = IDD_IEOPTIONS_DIALOG };
	CListCtrl	m_ctrlIE;
	CString	m_strTitle;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIEOptionsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	SHDocVw::IShellWindowsPtr m_ShellWindowPtr;//IShellWindowsPtr½Ó¿ÚÖ¸Õë
	void RefreshList();
	// Generated message map functions
	//{{AFX_MSG(CIEOptionsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSettitle();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IEOPTIONSDLG_H__F088FE6A_7BF7_4877_A2F5_76359379DF44__INCLUDED_)
