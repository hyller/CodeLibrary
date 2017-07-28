// DlgActiveXDemoDlg.h : header file
//
//{{AFX_INCLUDES()
#include "mshflexgrid.h"
//}}AFX_INCLUDES

#if !defined(AFX_DLGACTIVEXDEMODLG_H__68644AD2_EF19_4FD4_A917_C1C51E08C54E__INCLUDED_)
#define AFX_DLGACTIVEXDEMODLG_H__68644AD2_EF19_4FD4_A917_C1C51E08C54E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDlgActiveXDemoDlg dialog

class CDlgActiveXDemoDlg : public CDialog
{
// Construction
public:
	CDlgActiveXDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgActiveXDemoDlg)
	enum { IDD = IDD_DLGACTIVEXDEMO_DIALOG };
	CEdit	m_edit;
	CMSHFlexGrid	m_flexgrid;
	double	m_value;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgActiveXDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	bool m_bEditing;//当前单元格是否正在编辑
	int  m_nRow;//当前单元格的行号
	int  m_nCol;//当前单元格的列号

	// Generated message map functions
	//{{AFX_MSG(CDlgActiveXDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClickMshflexgrid1();
	afx_msg void OnCal();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGACTIVEXDEMODLG_H__68644AD2_EF19_4FD4_A917_C1C51E08C54E__INCLUDED_)
