// ColorTextProgressBarDlg.h : header file
//

#if !defined(AFX_COLORTEXTPROGRESSBARDLG_H__A97EA539_ABD3_4B36_9B40_C9C43DE330CD__INCLUDED_)
#define AFX_COLORTEXTPROGRESSBARDLG_H__A97EA539_ABD3_4B36_9B40_C9C43DE330CD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TextProgressBar.h "
/////////////////////////////////////////////////////////////////////////////
// CColorTextProgressBarDlg dialog

class CColorTextProgressBarDlg : public CDialog
{
// Construction
public:
	CColorTextProgressBarDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CColorTextProgressBarDlg)
	enum { IDD = IDD_COLORTEXTPROGRESSBAR_DIALOG };
	CTextProgressBar	m_ctlProgress;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorTextProgressBarDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CColorTextProgressBarDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStar();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORTEXTPROGRESSBARDLG_H__A97EA539_ABD3_4B36_9B40_C9C43DE330CD__INCLUDED_)
