// FileAttributeDlg.h : header file
//

#if !defined(AFX_FileAttributeDLG_H__3C3AA967_65E2_11D6_8F32_00E04CE76240__INCLUDED_)
#define AFX_FileAttributeDLG_H__3C3AA967_65E2_11D6_8F32_00E04CE76240__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFileAttributeDlg dialog

class CFileAttributeDlg : public CDialog
{
// Construction
public:
	CFileAttributeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFileAttributeDlg)
	enum { IDD = IDD_FileAttribute_DIALOG };
	CString	m_strFile;
	CString	m_strATime;
	CString	m_strCTime;
	CString	m_strMTime;
	CString	m_strSize;
	BOOL	m_bArchive;
	BOOL	m_bReadOnly;
	BOOL	m_bSystem;
	BOOL	m_bHidden;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileAttributeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFileAttributeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnGetAttr();
	afx_msg void OnOpen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FileAttributeDLG_H__3C3AA967_65E2_11D6_8F32_00E04CE76240__INCLUDED_)
