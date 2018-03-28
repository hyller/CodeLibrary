// ExListBoxDemoDlg.h : header file
//

#if !defined(AFX_EXLISTBOXDEMODLG_H__13CE309C_D698_437D_9E85_504103FD05A2__INCLUDED_)
#define AFX_EXLISTBOXDEMODLG_H__13CE309C_D698_437D_9E85_504103FD05A2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ExListBox.h"
/////////////////////////////////////////////////////////////////////////////
// CExListBoxDemoDlg dialog

class CExListBoxDemoDlg : public CDialog
{
// Construction
public:
	CExListBoxDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CExListBoxDemoDlg)
	enum { IDD = IDD_EXLISTBOXDEMO_DIALOG };
	CExListBox	m_ctlList2;
	CListBox	m_ctlList1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExListBoxDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CExListBoxDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXLISTBOXDEMODLG_H__13CE309C_D698_437D_9E85_504103FD05A2__INCLUDED_)
