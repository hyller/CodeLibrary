// ShutRebootDlg.h : header file
//

#if !defined(AFX_SHUTREBOOTDLG_H__9D4519F4_832C_4ADA_8A4B_FA274588232E__INCLUDED_)
#define AFX_SHUTREBOOTDLG_H__9D4519F4_832C_4ADA_8A4B_FA274588232E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CShutRebootDlg dialog

class CShutRebootDlg : public CDialog
{
// Construction
public:
	CShutRebootDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CShutRebootDlg)
	enum { IDD = IDD_SHUTREBOOT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShutRebootDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CShutRebootDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnShutdown();
	afx_msg void OnReboot();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHUTREBOOTDLG_H__9D4519F4_832C_4ADA_8A4B_FA274588232E__INCLUDED_)
