// DialogStatusBarDlg.h : header file
//

#if !defined(AFX_DIALOGSTATUSBARDLG_H__5EDBC297_BE2B_44A7_A757_1B792802F7AB__INCLUDED_)
#define AFX_DIALOGSTATUSBARDLG_H__5EDBC297_BE2B_44A7_A757_1B792802F7AB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDialogStatusBarDlg dialog

class CDialogStatusBarDlg : public CDialog
{
// Construction
public:
	CDialogStatusBarDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDialogStatusBarDlg)
	enum { IDD = IDD_DIALOGSTATUSBAR_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogStatusBarDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CStatusBar m_bar;												//×´Ì¬À¸¶ÔÏó

	// Generated message map functions
	//{{AFX_MSG(CDialogStatusBarDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGSTATUSBARDLG_H__5EDBC297_BE2B_44A7_A757_1B792802F7AB__INCLUDED_)
