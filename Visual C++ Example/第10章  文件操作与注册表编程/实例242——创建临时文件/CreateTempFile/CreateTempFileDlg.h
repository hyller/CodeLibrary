// CreateTempFileDlg.h : header file
//

#if !defined(AFX_CREATETEMPFILEDLG_H__CEBFE27F_718F_40EE_924B_DD31480F80F8__INCLUDED_)
#define AFX_CREATETEMPFILEDLG_H__CEBFE27F_718F_40EE_924B_DD31480F80F8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCreateTempFileDlg dialog

class CCreateTempFileDlg : public CDialog
{
// Construction
public:
	CCreateTempFileDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCreateTempFileDlg)
	enum { IDD = IDD_CREATETEMPFILE_DIALOG };
	CString	m_strTempFilePath;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateTempFileDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCreateTempFileDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCreate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATETEMPFILEDLG_H__CEBFE27F_718F_40EE_924B_DD31480F80F8__INCLUDED_)
