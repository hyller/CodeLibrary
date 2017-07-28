// BitmapTreeDemoDlg.h : header file
//

#if !defined(AFX_BITMAPTREEDEMODLG_H__F9EB2E4F_082E_4669_BD2C_546BF57FD55C__INCLUDED_)
#define AFX_BITMAPTREEDEMODLG_H__F9EB2E4F_082E_4669_BD2C_546BF57FD55C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
/////////////////////////////////////////////////////////////////////////////
// CBitmapTreeDemoDlg dialog
#include "MyTreeCtrl.h"
class CBitmapTreeDemoDlg : public CDialog
{
// Construction
public:
	CBitmapTreeDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBitmapTreeDemoDlg)
	enum { IDD = IDD_BITMAPTREEDEMO_DIALOG };
	CMyTreeCtrl	m_ctlTree;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBitmapTreeDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBitmapTreeDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BITMAPTREEDEMODLG_H__F9EB2E4F_082E_4669_BD2C_546BF57FD55C__INCLUDED_)
