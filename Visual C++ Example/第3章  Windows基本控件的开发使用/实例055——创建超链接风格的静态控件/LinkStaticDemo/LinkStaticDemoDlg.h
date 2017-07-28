// LinkStaticDemoDlg.h : header file
//

#if !defined(AFX_LINKSTATICDEMODLG_H__57AC64A6_8F6B_4255_8A95_FC241C9F0D86__INCLUDED_)
#define AFX_LINKSTATICDEMODLG_H__57AC64A6_8F6B_4255_8A95_FC241C9F0D86__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "LinkStatic.h"
/////////////////////////////////////////////////////////////////////////////
// CLinkStaticDemoDlg dialog

class CLinkStaticDemoDlg : public CDialog
{
// Construction
public:
	CLinkStaticDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CLinkStaticDemoDlg)
	enum { IDD = IDD_LINKSTATICDEMO_DIALOG };
	CLinkStatic	m_ctlLinkStatic;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLinkStaticDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLinkStaticDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINKSTATICDEMODLG_H__57AC64A6_8F6B_4255_8A95_FC241C9F0D86__INCLUDED_)
