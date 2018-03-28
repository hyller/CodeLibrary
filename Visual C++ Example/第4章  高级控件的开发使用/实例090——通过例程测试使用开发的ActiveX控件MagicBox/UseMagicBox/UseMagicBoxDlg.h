// UseMagicBoxDlg.h : header file
//
//{{AFX_INCLUDES()
#include "magicbox.h"
//}}AFX_INCLUDES

#if !defined(AFX_USEMAGICBOXDLG_H__A556ACF1_19CA_4DF3_8389_1BDC402BEDF6__INCLUDED_)
#define AFX_USEMAGICBOXDLG_H__A556ACF1_19CA_4DF3_8389_1BDC402BEDF6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CUseMagicBoxDlg dialog

class CUseMagicBoxDlg : public CDialog
{
// Construction
public:
	CUseMagicBoxDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CUseMagicBoxDlg)
	enum { IDD = IDD_USEMAGICBOX_DIALOG };
	CMagicBox	m_ctlMagicBox;
	int		m_radio;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseMagicBoxDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CUseMagicBoxDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClickBoxMagicbox1(long x, long y);
	afx_msg void OnSet();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USEMAGICBOXDLG_H__A556ACF1_19CA_4DF3_8389_1BDC402BEDF6__INCLUDED_)
