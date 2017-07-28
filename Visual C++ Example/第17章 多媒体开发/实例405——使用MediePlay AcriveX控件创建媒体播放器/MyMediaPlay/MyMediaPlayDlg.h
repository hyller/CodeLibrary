// MyMediaPlayDlg.h : header file
//
//{{AFX_INCLUDES()
#include "wmpplayer4.h"
//}}AFX_INCLUDES

#if !defined(AFX_MYMEDIAPLAYDLG_H__A8FE8001_56A3_42DE_BEC6_92C3B7D0E7B9__INCLUDED_)
#define AFX_MYMEDIAPLAYDLG_H__A8FE8001_56A3_42DE_BEC6_92C3B7D0E7B9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMyMediaPlayDlg dialog

class CMyMediaPlayDlg : public CDialog
{
// Construction
public:
	CMyMediaPlayDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyMediaPlayDlg)
	enum { IDD = IDD_MYMEDIAPLAY_DIALOG };
	CWMPPlayer4	m_ctlMediaPlay;
	CString	m_strFileName;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyMediaPlayDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyMediaPlayDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOpenfile();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYMEDIAPLAYDLG_H__A8FE8001_56A3_42DE_BEC6_92C3B7D0E7B9__INCLUDED_)
