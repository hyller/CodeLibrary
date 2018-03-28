// MSCommProDlg.h : header file
//
//{{AFX_INCLUDES()
#include "mscomm.h"
//}}AFX_INCLUDES

#if !defined(AFX_MSCOMMPRODLG_H__C9159B0B_D9AE_4364_9869_E361218B282B__INCLUDED_)
#define AFX_MSCOMMPRODLG_H__C9159B0B_D9AE_4364_9869_E361218B282B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMSCommProDlg dialog

class CMSCommProDlg : public CDialog
{
// Construction
public:
	CMSCommProDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMSCommProDlg)
	enum { IDD = IDD_MSCOMMPRO_DIALOG };
	CComboBox	m_ctlList;
	CMSComm	m_Comm;
	CString	m_strReceive;
	CString	m_strSend;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMSCommProDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	int m_Port;
	// Generated message map functions
	//{{AFX_MSG(CMSCommProDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOpenport();
	afx_msg void OnSend();
	afx_msg void OnCloseport();
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnOnCommMscomm1();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MSCOMMPRODLG_H__C9159B0B_D9AE_4364_9869_E361218B282B__INCLUDED_)
