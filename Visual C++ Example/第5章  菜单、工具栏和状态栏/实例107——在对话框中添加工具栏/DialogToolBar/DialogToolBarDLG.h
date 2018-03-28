// DialogToolBarDlg.h : header file
//

#if !defined(AFX_DialogToolBarDLG_H__DA010376_EF46_42A7_8F41_189506AF0293__INCLUDED_)
#define AFX_DialogToolBarDLG_H__DA010376_EF46_42A7_8F41_189506AF0293__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDialogToolBarDlg dialog

class CDialogToolBarDlg : public CDialog
{
// Construction
public:
	CDialogToolBarDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDialogToolBarDlg)
	enum { IDD = IDD_DialogToolBar_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogToolBarDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CToolBar m_wndtoolbar;

	// Generated message map functions
	//{{AFX_MSG(CDialogToolBarDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMenuitem32773();
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DialogToolBarDLG_H__DA010376_EF46_42A7_8F41_189506AF0293__INCLUDED_)
