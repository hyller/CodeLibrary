// WindowsVersionDlg.h : header file
//

#if !defined(AFX_WINDOWSVERSIONDLG_H__A7EAFBE8_EFD5_4C12_A2A3_33462474BEF1__INCLUDED_)
#define AFX_WINDOWSVERSIONDLG_H__A7EAFBE8_EFD5_4C12_A2A3_33462474BEF1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWindowsVersionDlg dialog

class CWindowsVersionDlg : public CDialog
{
// Construction
public:
	CWindowsVersionDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CWindowsVersionDlg)
	enum { IDD = IDD_WINDOWSVERSION_DIALOG };
	CString	m_strInfo;
	CString	m_strServerPack;
	CString	m_strBuildNum;
	CString	m_strMinorVer;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWindowsVersionDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWindowsVersionDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnGetversion();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WINDOWSVERSIONDLG_H__A7EAFBE8_EFD5_4C12_A2A3_33462474BEF1__INCLUDED_)
