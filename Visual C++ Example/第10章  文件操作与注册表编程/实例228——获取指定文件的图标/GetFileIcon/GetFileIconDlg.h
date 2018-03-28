// GetFileIconDlg.h : header file
//

#if !defined(AFX_GETFILEICONDLG_H__A8015297_D181_463A_B9F4_7AE568D6010E__INCLUDED_)
#define AFX_GETFILEICONDLG_H__A8015297_D181_463A_B9F4_7AE568D6010E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGetFileIconDlg dialog

class CGetFileIconDlg : public CDialog
{
// Construction
public:
	CGetFileIconDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGetFileIconDlg)
	enum { IDD = IDD_GETFILEICON_DIALOG };
	CString	m_filename;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetFileIconDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGetFileIconDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnGeticon();
	afx_msg void OnOpen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETFILEICONDLG_H__A8015297_D181_463A_B9F4_7AE568D6010E__INCLUDED_)
