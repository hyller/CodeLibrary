// AutoRunProDlg.h : header file
//

#if !defined(AFX_AUTORUNPRODLG_H__80454F2A_8976_49F4_ABCC_458483856639__INCLUDED_)
#define AFX_AUTORUNPRODLG_H__80454F2A_8976_49F4_ABCC_458483856639__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAutoRunProDlg dialog

class CAutoRunProDlg : public CDialog
{
// Construction
public:
	CAutoRunProDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAutoRunProDlg)
	enum { IDD = IDD_AUTORUNPRO_DIALOG };
	CString	m_strExe;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAutoRunProDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAutoRunProDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSet();
	afx_msg void OnOpen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUTORUNPRODLG_H__80454F2A_8976_49F4_ABCC_458483856639__INCLUDED_)
