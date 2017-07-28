// PicClockDemoDlg.h : header file
//

#if !defined(AFX_PICCLOCKDEMODLG_H__4BDC09A3_E12A_4B5F_9E36_F872B37FDC16__INCLUDED_)
#define AFX_PICCLOCKDEMODLG_H__4BDC09A3_E12A_4B5F_9E36_F872B37FDC16__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ClockStatic.h"
/////////////////////////////////////////////////////////////////////////////
// CPicClockDemoDlg dialog

class CPicClockDemoDlg : public CDialog
{
// Construction
public:
	CPicClockDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPicClockDemoDlg)
	enum { IDD = IDD_PICCLOCKDEMO_DIALOG };
	CClockStatic	m_ctlClock;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPicClockDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPicClockDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PICCLOCKDEMODLG_H__4BDC09A3_E12A_4B5F_9E36_F872B37FDC16__INCLUDED_)
