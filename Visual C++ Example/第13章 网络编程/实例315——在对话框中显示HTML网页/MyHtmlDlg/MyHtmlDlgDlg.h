// MyHtmlDlgDlg.h : header file
//

#if !defined(AFX_MYHTMLDLGDLG_H__8F553BA2_C70A_40D1_94A0_446965E045DA__INCLUDED_)
#define AFX_MYHTMLDLGDLG_H__8F553BA2_C70A_40D1_94A0_446965E045DA__INCLUDED_

#include "MyHtmlCtrl.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMyHtmlDlgDlg dialog

class CMyHtmlDlgDlg : public CDialog
{
// Construction
public:
	CMyHtmlDlgDlg(CWnd* pParent = NULL);	// standard constructor
	CMyHtmlCtrl m_WebPage;
// Dialog Data
	//{{AFX_DATA(CMyHtmlDlgDlg)
	enum { IDD = IDD_MYHTMLDLG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyHtmlDlgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyHtmlDlgDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnHome();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYHTMLDLGDLG_H__8F553BA2_C70A_40D1_94A0_446965E045DA__INCLUDED_)
