// TimeLimitDlg.h : header file
//

#if !defined(AFX_TIMELIMITDLG_H__2DB3BA5B_5CBB_4CBC_8158_BFF766115A3E__INCLUDED_)
#define AFX_TIMELIMITDLG_H__2DB3BA5B_5CBB_4CBC_8158_BFF766115A3E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTimeLimitDlg dialog

class CTimeLimitDlg : public CDialog
{
// Construction
public:
	CTimeLimitDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTimeLimitDlg)
	enum { IDD = IDD_TIMELIMIT_DIALOG };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimeLimitDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTimeLimitDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMELIMITDLG_H__2DB3BA5B_5CBB_4CBC_8158_BFF766115A3E__INCLUDED_)
