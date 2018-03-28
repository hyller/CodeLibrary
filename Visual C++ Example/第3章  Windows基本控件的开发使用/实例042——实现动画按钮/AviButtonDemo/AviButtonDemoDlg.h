// AviButtonDemoDlg.h : header file
//

#if !defined(AFX_AVIBUTTONDEMODLG_H__61C8C7DC_13D4_4B77_9630_58F3F7728B5D__INCLUDED_)
#define AFX_AVIBUTTONDEMODLG_H__61C8C7DC_13D4_4B77_9630_58F3F7728B5D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "AviButton.h"
/////////////////////////////////////////////////////////////////////////////
// CAviButtonDemoDlg dialog

class CAviButtonDemoDlg : public CDialog
{
// Construction
public:
	CAviButtonDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAviButtonDemoDlg)
	enum { IDD = IDD_AVIBUTTONDEMO_DIALOG };
	CAviButton	m_ctlOk;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAviButtonDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAviButtonDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AVIBUTTONDEMODLG_H__61C8C7DC_13D4_4B77_9630_58F3F7728B5D__INCLUDED_)
