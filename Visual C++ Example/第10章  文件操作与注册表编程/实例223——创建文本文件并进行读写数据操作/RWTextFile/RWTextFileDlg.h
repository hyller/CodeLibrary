// RWTextFileDlg.h : header file
//

#if !defined(AFX_RWTEXTFILEDLG_H__28D603F5_197C_4EDD_AEDD_26DBDAC2DA74__INCLUDED_)
#define AFX_RWTEXTFILEDLG_H__28D603F5_197C_4EDD_AEDD_26DBDAC2DA74__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRWTextFileDlg dialog

class CRWTextFileDlg : public CDialog
{
// Construction
public:
	CRWTextFileDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRWTextFileDlg)
	enum { IDD = IDD_RWTEXTFILE_DIALOG };
	CString	m_strWrite;
	CString	m_strRead;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRWTextFileDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRWTextFileDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRead();
	afx_msg void OnWrite();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RWTEXTFILEDLG_H__28D603F5_197C_4EDD_AEDD_26DBDAC2DA74__INCLUDED_)
