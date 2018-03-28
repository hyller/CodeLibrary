// NoExitButtonDlg.h : header file
//

#if !defined(AFX_NOEXITBUTTONDLG_H__12C7C76D_2805_4C19_BC87_C5B992409BFE__INCLUDED_)
#define AFX_NOEXITBUTTONDLG_H__12C7C76D_2805_4C19_BC87_C5B992409BFE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CNoExitButtonDlg dialog

class CNoExitButtonDlg : public CDialog
{
// Construction
public:
	CNoExitButtonDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CNoExitButtonDlg)
	enum { IDD = IDD_NOEXITBUTTON_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNoExitButtonDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CNoExitButtonDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NOEXITBUTTONDLG_H__12C7C76D_2805_4C19_BC87_C5B992409BFE__INCLUDED_)
