// UseMouseHookDlg.h : header file
//

#if !defined(AFX_UseMouseHookDLG_H__EA7C4E39_BAF4_413F_BC43_177A039C1D0C__INCLUDED_)
#define AFX_UseMouseHookDLG_H__EA7C4E39_BAF4_413F_BC43_177A039C1D0C__INCLUDED_
#include "MousehookDll.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CUseMouseHookDlg dialog

class CUseMouseHookDlg : public CDialog
{
// Construction
public:
	CUseMouseHookDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CUseMouseHookDlg)
	enum { IDD = IDD_UseMouseHook_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseMouseHookDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CMouseHook m_hook; 

	// Generated message map functions
	//{{AFX_MSG(CUseMouseHookDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UseMouseHookDLG_H__EA7C4E39_BAF4_413F_BC43_177A039C1D0C__INCLUDED_)
