#if !defined(AFX_CONNECTEDDLG1_H__3340F171_F80C_4EFA_8BD1_DA34EF60FF3E__INCLUDED_)
#define AFX_CONNECTEDDLG1_H__3340F171_F80C_4EFA_8BD1_DA34EF60FF3E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//
#include "ServerSocket.h"
/////////////////////////////////////////////////////////////////////////////
// CConnectedDlg dialog

class CConnectedDlg : public CDialog
{
// Construction
public:
	CConnectedDlg(CServerSocket * tmp,CWnd* pParent = NULL);   // standard constructor
	CServerSocket * myServerSocket;

// Dialog Data
	//{{AFX_DATA(CConnectedDlg)
	enum { IDD = IDD_DIALOG_CONNECTEDDLG };
	CString	m_IDC_EDIT_ADDRESS;
	CString	m_IDC_EDIT_NIKENAME;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConnectedDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CConnectedDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONNECTEDDLG1_H__3340F171_F80C_4EFA_8BD1_DA34EF60FF3E__INCLUDED_)
