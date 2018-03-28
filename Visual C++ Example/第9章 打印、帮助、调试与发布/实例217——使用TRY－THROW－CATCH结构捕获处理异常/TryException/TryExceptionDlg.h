// TryExceptionDlg.h : header file
//

#if !defined(AFX_TRYEXCEPTIONDLG_H__DC6AE97B_1ABA_40FC_A424_166B8DC15119__INCLUDED_)
#define AFX_TRYEXCEPTIONDLG_H__DC6AE97B_1ABA_40FC_A424_166B8DC15119__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTryExceptionDlg dialog

class CTryExceptionDlg : public CDialog
{
// Construction
public:
	CTryExceptionDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTryExceptionDlg)
	enum { IDD = IDD_TRYEXCEPTION_DIALOG };
	int		m_num;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTryExceptionDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTryExceptionDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCatch();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRYEXCEPTIONDLG_H__DC6AE97B_1ABA_40FC_A424_166B8DC15119__INCLUDED_)
