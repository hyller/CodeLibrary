#if !defined(AFX_SALEDLG_H__8CFDE888_94EE_4D18_9463_3ABB8EB2C886__INCLUDED_)
#define AFX_SALEDLG_H__8CFDE888_94EE_4D18_9463_3ABB8EB2C886__INCLUDED_

#include "medicSet.h"
#include "saleSet.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SaleDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSaleDlg dialog

class CSaleDlg : public CDialog
{
// Construction
public:
	CSaleDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSaleDlg)
	enum { IDD = IDD_SALE_DIALOG };
	CButton	m_settlement;
	CListCtrl	m_saleList;
	CString	m_name;
	int		m_number;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSaleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CMedicSet* theMedicSet;
	CSaleSet* theSaleSet;

	// Generated message map functions
	//{{AFX_MSG(CSaleDlg)
	virtual BOOL OnInitDialog();
	virtual void OnAdd();
	afx_msg void OnRecoverButton();
	afx_msg void OnDelete();
	afx_msg void OnSettlementButton();
	afx_msg void OnExitButton();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SALEDLG_H__8CFDE888_94EE_4D18_9463_3ABB8EB2C886__INCLUDED_)
