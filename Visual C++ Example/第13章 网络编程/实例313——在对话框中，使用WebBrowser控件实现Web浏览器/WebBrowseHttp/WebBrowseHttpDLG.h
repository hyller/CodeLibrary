// WebBrowseHttpDlg.h : header file
//
//{{AFX_INCLUDES()
#include "webbrowser2.h"
//}}AFX_INCLUDES

#if !defined(AFX_WebBrowseHttpDLG_H__BE5B88FE_4014_412A_B311_273D58F0A978__INCLUDED_)
#define AFX_WebBrowseHttpDLG_H__BE5B88FE_4014_412A_B311_273D58F0A978__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWebBrowseHttpDlg dialog

class CWebBrowseHttpDlg : public CDialog
{
// Construction
public:
	CWebBrowseHttpDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CWebBrowseHttpDlg)
	enum { IDD = IDD_WebBrowseHttp_DIALOG };
	CWebBrowser2	m_ctrlWeb;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWebBrowseHttpDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWebBrowseHttpDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMicrosoft();
	afx_msg void OnButtonForward();
	afx_msg void OnButtonReflesh();
	afx_msg void OnButtonBack();
	afx_msg void OnCommandStateChangeExplorer1(long Command, BOOL Enable);
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WebBrowseHttpDLG_H__BE5B88FE_4014_412A_B311_273D58F0A978__INCLUDED_)
