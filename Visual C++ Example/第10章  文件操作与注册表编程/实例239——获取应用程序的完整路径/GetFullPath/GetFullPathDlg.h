// GetFullPathDlg.h : header file
//

#if !defined(AFX_GETFULLPATHDLG_H__2DCEB357_24C3_4A15_9C3D_57267FDD105D__INCLUDED_)
#define AFX_GETFULLPATHDLG_H__2DCEB357_24C3_4A15_9C3D_57267FDD105D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGetFullPathDlg dialog

class CGetFullPathDlg : public CDialog
{
// Construction
public:
	CGetFullPathDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGetFullPathDlg)
	enum { IDD = IDD_GETFULLPATH_DIALOG };
	CString	m_strPath;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetFullPathDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGetFullPathDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnGet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETFULLPATHDLG_H__2DCEB357_24C3_4A15_9C3D_57267FDD105D__INCLUDED_)
