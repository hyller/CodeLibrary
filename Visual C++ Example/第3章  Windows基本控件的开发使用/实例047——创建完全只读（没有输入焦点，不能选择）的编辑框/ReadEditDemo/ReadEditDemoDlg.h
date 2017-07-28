// ReadEditDemoDlg.h : header file
//

#if !defined(AFX_READEDITDEMODLG_H__FAC7544D_3392_4026_B060_6A66814485FD__INCLUDED_)
#define AFX_READEDITDEMODLG_H__FAC7544D_3392_4026_B060_6A66814485FD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ReadEdit.h"
/////////////////////////////////////////////////////////////////////////////
// CReadEditDemoDlg dialog

class CReadEditDemoDlg : public CDialog
{
// Construction
public:
	CReadEditDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CReadEditDemoDlg)
	enum { IDD = IDD_READEDITDEMO_DIALOG };
	CReadEdit	m_ctlRead;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReadEditDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CReadEditDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAdd();
	afx_msg void OnClear();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_READEDITDEMODLG_H__FAC7544D_3392_4026_B060_6A66814485FD__INCLUDED_)
