#if !defined(AFX_CLEANUPDLG_H__9AC4B99C_A0AD_473E_9633_2EFF183F4DCA__INCLUDED_)
#define AFX_CLEANUPDLG_H__9AC4B99C_A0AD_473E_9633_2EFF183F4DCA__INCLUDED_

#include "MedicSet.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CleanUpDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCleanUpDlg dialog

class CCleanUpDlg : public CDialog
{
// Construction
public:
	CCleanUpDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCleanUpDlg)
	enum { IDD = IDD_CLEAN_UP_DIALOG };
	CListCtrl	m_showList;
	int		m_selectRadio;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCleanUpDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CMedicSet* m_theMedicSet;

	// Generated message map functions
	//{{AFX_MSG(CCleanUpDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnExit();
	afx_msg void OnCleanUpButton();
	afx_msg void OnClose();
	afx_msg void OnZeroRadio();
	afx_msg void OnOverdueRadio();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLEANUPDLG_H__9AC4B99C_A0AD_473E_9633_2EFF183F4DCA__INCLUDED_)
