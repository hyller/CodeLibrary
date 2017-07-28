// ViewDlgDemoDlg.h : header file
//

#if !defined(AFX_VIEWDLGDEMODLG_H__EB549D2D_EEB0_4D47_9335_918B3D8B1C7A__INCLUDED_)
#define AFX_VIEWDLGDEMODLG_H__EB549D2D_EEB0_4D47_9335_918B3D8B1C7A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CViewDlgDemoDlg dialog
#include "MyScrollView.h"
class CViewDlgDemoDlg : public CDialog
{
// Construction
public:
	CViewDlgDemoDlg(CWnd* pParent = NULL);	// standard constructor
// Dialog Data
	//{{AFX_DATA(CViewDlgDemoDlg)
	enum { IDD = IDD_VIEWDLGDEMO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CViewDlgDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CViewDlgDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIEWDLGDEMODLG_H__EB549D2D_EEB0_4D47_9335_918B3D8B1C7A__INCLUDED_)
