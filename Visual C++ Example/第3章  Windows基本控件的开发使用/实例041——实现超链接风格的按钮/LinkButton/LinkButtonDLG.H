// LinkButtonDlg.h : header file
//

#if !defined(AFX_LinkButtonDLG_H__D320C086_4DFB_45E7_BDCF_D60468A1AAAA__INCLUDED_)
#define AFX_LinkButtonDLG_H__D320C086_4DFB_45E7_BDCF_D60468A1AAAA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "HyperLinkButton.h"
/////////////////////////////////////////////////////////////////////////////
// CLinkButtonDlg dialog

class CLinkButtonDlg : public CDialog
{
// Construction
public:
	CLinkButtonDlg(CWnd* pParent = NULL);	// standard constructor
	CHyperLinkButton	m_ctlHomePage;
	CHyperLinkButton	m_ctlMail;

// Dialog Data
	//{{AFX_DATA(CLinkButtonDlg)
	enum { IDD = IDD_LinkButton_DIALOG };

	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLinkButtonDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLinkButtonDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnEmail();
	afx_msg void OnHomepage();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LinkButtonDLG_H__D320C086_4DFB_45E7_BDCF_D60468A1AAAA__INCLUDED_)
