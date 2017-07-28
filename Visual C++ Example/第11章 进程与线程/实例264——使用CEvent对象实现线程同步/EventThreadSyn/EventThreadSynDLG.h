// EventThreadSynDlg.h : header file
//

#if !defined(AFX_EventThreadSynDLG_H__D392B8E7_2700_4E56_804C_A07AFD225755__INCLUDED_)
#define AFX_EventThreadSynDLG_H__D392B8E7_2700_4E56_804C_A07AFD225755__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <afxmt.h>
/////////////////////////////////////////////////////////////////////////////
// CEventThreadSynDlg dialog


class CEventThreadSynDlg : public CDialog
{
// Construction
public:
	CEventThreadSynDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CEventThreadSynDlg)
	enum { IDD = IDD_EventThreadSyn_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEventThreadSynDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEventThreadSynDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnEvent();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EventThreadSynDLG_H__D392B8E7_2700_4E56_804C_A07AFD225755__INCLUDED_)
