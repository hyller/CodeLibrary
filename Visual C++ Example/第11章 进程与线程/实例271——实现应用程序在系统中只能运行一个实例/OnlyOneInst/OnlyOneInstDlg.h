// OnlyOneInstDlg.h : header file
//

#if !defined(AFX_ONLYONEINSTDLG_H__C0A4EC87_66C6_11D6_8F32_00E04CE76240__INCLUDED_)
#define AFX_ONLYONEINSTDLG_H__C0A4EC87_66C6_11D6_8F32_00E04CE76240__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// COnlyOneInstDlg dialog

class COnlyOneInstDlg : public CDialog
{
// Construction
public:
	COnlyOneInstDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(COnlyOneInstDlg)
	enum { IDD = IDD_ONLYONEINST_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COnlyOneInstDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(COnlyOneInstDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ONLYONEINSTDLG_H__C0A4EC87_66C6_11D6_8F32_00E04CE76240__INCLUDED_)
