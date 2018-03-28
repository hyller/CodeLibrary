// MCICDPlayerDlg.h : header file
//

#if !defined(AFX_MCICDPlayerDLG_H__F72E7867_6A64_11D6_8F32_00E04CE76240__INCLUDED_)
#define AFX_MCICDPlayerDLG_H__F72E7867_6A64_11D6_8F32_00E04CE76240__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MyMCICD.h"
/////////////////////////////////////////////////////////////////////////////
// CMCICDPlayerDlg dialog

class CMCICDPlayerDlg : public CDialog
{
// Construction
public:
	CMCICDPlayerDlg(CWnd* pParent = NULL);	// standard constructor

	CMyMCICD m_CDAudio;
// Dialog Data
	//{{AFX_DATA(CMCICDPlayerDlg)
	enum { IDD = IDD_MCICDPlayer_DIALOG };
	CComboBox	m_ctlCombo;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMCICDPlayerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMCICDPlayerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnPlay();
	afx_msg void OnStop();
	afx_msg void OnPause();
	afx_msg void OnForward();
	afx_msg void OnBack();
	afx_msg void OnSkipback();
	afx_msg void OnSkipforward();
	afx_msg void OnSelchangeMusicList();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MCICDPlayerDLG_H__F72E7867_6A64_11D6_8F32_00E04CE76240__INCLUDED_)
