// MemoryMouseInfoDlg.h : header file
//

#if !defined(AFX_MEMORYMOUSEINFODLG_H__25E0E2B3_B007_49BD_887D_8ECCD0CF9405__INCLUDED_)
#define AFX_MEMORYMOUSEINFODLG_H__25E0E2B3_B007_49BD_887D_8ECCD0CF9405__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMemoryMouseInfoDlg dialog

class CMemoryMouseInfoDlg : public CDialog
{
// Construction
public:
	CMemoryMouseInfoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMemoryMouseInfoDlg)
	enum { IDD = IDD_MEMORYMOUSEINFO_DIALOG };
	CString	m_strTotalPhy;
	CString	m_strAvailPhy;
	CString	m_strLoad;
	CString	m_strTotalVir;
	CString	m_strAvailVir;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMemoryMouseInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMemoryMouseInfoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnGetmeminfo();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MEMORYMOUSEINFODLG_H__25E0E2B3_B007_49BD_887D_8ECCD0CF9405__INCLUDED_)
