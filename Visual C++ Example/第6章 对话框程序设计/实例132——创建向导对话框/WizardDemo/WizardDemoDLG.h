// WizardDemoDlg.h : header file
//

#if !defined(AFX_WizardDemoDLG_H__A99E64BB_74DE_11D6_8F32_00E04CE76240__INCLUDED_)
#define AFX_WizardDemoDLG_H__A99E64BB_74DE_11D6_8F32_00E04CE76240__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWizardDemoDlg dialog

class CWizardDemoDlg : public CDialog
{
// Construction
public:
	CWizardDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CWizardDemoDlg)
	enum { IDD = IDD_WizardDemo_DIALOG };
		// NOTE: the ClassWizardDemo will add data members here
	//}}AFX_DATA

	// ClassWizardDemo generated virtual function overrides
	//{{AFX_VIRTUAL(CWizardDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWizardDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBenginWiz();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WizardDemoDLG_H__A99E64BB_74DE_11D6_8F32_00E04CE76240__INCLUDED_)
