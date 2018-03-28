// SheetDlgDemoDlg.h : header file
//

#if !defined(AFX_SheetDlgDemoDLG_H__C8A3A617_DEF4_430B_974B_6D62D97B8894__INCLUDED_)
#define AFX_SheetDlgDemoDLG_H__C8A3A617_DEF4_430B_974B_6D62D97B8894__INCLUDED_

#include "Page1.h"	// Added by ClassView
#include "Page2.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSheetDlgDemoDlg dialog

class CSheetDlgDemoDlg : public CDialog
{
// Construction
public:
	CPage2 m_page2;//属性页2
	CPage1 m_page1;//属性页1
	CPropertySheet m_sheet;//属性表类
	CSheetDlgDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSheetDlgDemoDlg)
	enum { IDD = IDD_SheetDlgDemo_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSheetDlgDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSheetDlgDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SheetDlgDemoDLG_H__C8A3A617_DEF4_430B_974B_6D62D97B8894__INCLUDED_)
