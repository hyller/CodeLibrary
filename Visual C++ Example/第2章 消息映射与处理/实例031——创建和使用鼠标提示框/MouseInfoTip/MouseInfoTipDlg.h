// MouseInfoTipDlg.h : header file
//

#if !defined(AFX_MOUSEINFOTIPDLG_H__013E409B_5598_4D19_93CC_809ABD5E695E__INCLUDED_)
#define AFX_MOUSEINFOTIPDLG_H__013E409B_5598_4D19_93CC_809ABD5E695E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "MFECToolTip.h"
/////////////////////////////////////////////////////////////////////////////
// CMouseInfoTipDlg dialog

class CMouseInfoTipDlg : public CDialog
{
// Construction
public:
	CMouseInfoTipDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMouseInfoTipDlg)
	enum { IDD = IDD_MOUSEINFOTIP_DIALOG };
	CListBox	m_ctlList;
	CString	m_sName;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMouseInfoTipDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CMFECToolTip		m_toolTip;//ÉùÃ÷¶ÔÏó
	// Generated message map functions
	//{{AFX_MSG(CMouseInfoTipDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAdd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOUSEINFOTIPDLG_H__013E409B_5598_4D19_93CC_809ABD5E695E__INCLUDED_)
