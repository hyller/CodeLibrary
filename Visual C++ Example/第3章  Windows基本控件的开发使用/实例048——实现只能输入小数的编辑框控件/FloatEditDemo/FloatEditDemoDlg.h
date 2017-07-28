// FloatEditDemoDlg.h : header file
//

#if !defined(AFX_FLOATEDITDEMODLG_H__C514FA09_6A66_4BBF_AAAC_1FFE3FC68EBF__INCLUDED_)
#define AFX_FLOATEDITDEMODLG_H__C514FA09_6A66_4BBF_AAAC_1FFE3FC68EBF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "FloatEdit.h"
/////////////////////////////////////////////////////////////////////////////
// CFloatEditDemoDlg dialog

class CFloatEditDemoDlg : public CDialog
{
// Construction
public:
	CFloatEditDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFloatEditDemoDlg)
	enum { IDD = IDD_FLOATEDITDEMO_DIALOG };
	CFloatEdit	m_ctlEdit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFloatEditDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFloatEditDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLOATEDITDEMODLG_H__C514FA09_6A66_4BBF_AAAC_1FFE3FC68EBF__INCLUDED_)
