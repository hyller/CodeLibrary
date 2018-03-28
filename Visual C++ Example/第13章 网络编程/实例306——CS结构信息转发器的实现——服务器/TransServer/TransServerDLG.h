// TransServerDlg.h : header file
//

#if !defined(AFX_TransServerDLG_H__8C42E23A_FC89_4BC5_A851_A62063C0CFB5__INCLUDED_)
#define AFX_TransServerDLG_H__8C42E23A_FC89_4BC5_A851_A62063C0CFB5__INCLUDED_
#include "ListenSocket.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTransServerDlg dialog

class CTransServerDlg : public CDialog
{
// Construction
public:
	CTransServerDlg(CWnd* pParent = NULL);	// standard constructor
	CListenSocket  m_listenSocket;			//¼àÌýÌ×½Ó×Ö

// Dialog Data
	//{{AFX_DATA(CTransServerDlg)
	enum { IDD = IDD_TransServer_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTransServerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTransServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStar();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TransServerDLG_H__8C42E23A_FC89_4BC5_A851_A62063C0CFB5__INCLUDED_)
