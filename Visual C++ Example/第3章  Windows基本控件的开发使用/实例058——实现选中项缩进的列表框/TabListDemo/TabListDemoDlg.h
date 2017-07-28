// TabListDemoDlg.h : header file
//


#if !defined(AFX_TABLISTDEMODLG_H__ED06AFCB_1255_49F7_A990_606ED5A88A06__INCLUDED_)
#define AFX_TABLISTDEMODLG_H__ED06AFCB_1255_49F7_A990_606ED5A88A06__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "NewListBox.h"
/////////////////////////////////////////////////////////////////////////////
// CTabListDemoDlg dialog

class CTabListDemoDlg : public CDialog
{
// Construction
public:
	CTabListDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTabListDemoDlg)
	enum { IDD = IDD_TABLISTDEMO_DIALOG };
	//}}AFX_DATA
	NewListBox	m_ctlList;
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTabListDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTabListDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TABLISTDEMODLG_H__ED06AFCB_1255_49F7_A990_606ED5A88A06__INCLUDED_)
