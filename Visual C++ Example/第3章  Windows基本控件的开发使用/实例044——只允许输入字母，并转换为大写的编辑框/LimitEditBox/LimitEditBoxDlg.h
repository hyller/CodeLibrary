// LimitEditBoxDlg.h : header file
//
#include "LimitEdit.h"
#if !defined(AFX_LIMITEDITBOXDLG_H__60D67B42_7556_499B_B9BB_A6DAB5A50F5E__INCLUDED_)
#define AFX_LIMITEDITBOXDLG_H__60D67B42_7556_499B_B9BB_A6DAB5A50F5E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CLimitEditBoxDlg dialog

class CLimitEditBoxDlg : public CDialog
{
// Construction
public:
	CLimitEditBoxDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CLimitEditBoxDlg)
	enum { IDD = IDD_LIMITEDITBOX_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLimitEditBoxDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CLimitEdit m_LimitEdit;//定义控件对象

	// Generated message map functions
	//{{AFX_MSG(CLimitEditBoxDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIMITEDITBOXDLG_H__60D67B42_7556_499B_B9BB_A6DAB5A50F5E__INCLUDED_)
