// BaseEditBoxDlg.h : header file
//

#if !defined(AFX_BASEEDITBOXDLG_H__4E4FC03C_7422_4FD6_B787_1D4A08EAE391__INCLUDED_)
#define AFX_BASEEDITBOXDLG_H__4E4FC03C_7422_4FD6_B787_1D4A08EAE391__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBaseEditBoxDlg dialog

class CBaseEditBoxDlg : public CDialog
{
// Construction
public:
	CBaseEditBoxDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBaseEditBoxDlg)
	enum { IDD = IDD_BASEEDITBOX_DIALOG };
	CString	m_user;
	CString	m_password;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBaseEditBoxDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBaseEditBoxDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSet();
	afx_msg void OnChangeUser();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BASEEDITBOXDLG_H__4E4FC03C_7422_4FD6_B787_1D4A08EAE391__INCLUDED_)
