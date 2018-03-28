// SetDesktopPicDlg.h : header file
//

#if !defined(AFX_SETDESKTOPPICDLG_H__95FD7607_22C7_495A_806F_4C985B5B3262__INCLUDED_)
#define AFX_SETDESKTOPPICDLG_H__95FD7607_22C7_495A_806F_4C985B5B3262__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSetDesktopPicDlg dialog

class CSetDesktopPicDlg : public CDialog
{
// Construction
public:
	CSetDesktopPicDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSetDesktopPicDlg)
	enum { IDD = IDD_SETDESKTOPPIC_DIALOG };
	CString	m_strPicFile;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetDesktopPicDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSetDesktopPicDlg)
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

#endif // !defined(AFX_SETDESKTOPPICDLG_H__95FD7607_22C7_495A_806F_4C985B5B3262__INCLUDED_)
