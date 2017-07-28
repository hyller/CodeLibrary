// ColorComboDemoDlg.h : header file
//

#if !defined(AFX_COLORCOMBODEMODLG_H__596393F2_0923_4CF1_A850_F800155291D3__INCLUDED_)
#define AFX_COLORCOMBODEMODLG_H__596393F2_0923_4CF1_A850_F800155291D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ColorCombo.h"
/////////////////////////////////////////////////////////////////////////////
// CColorComboDemoDlg dialog

class CColorComboDemoDlg : public CDialog
{
// Construction
public:
	CColorComboDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CColorComboDemoDlg)
	enum { IDD = IDD_COLORCOMBODEMO_DIALOG };
	CColorCombo	m_ctlCombo;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorComboDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CColorComboDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORCOMBODEMODLG_H__596393F2_0923_4CF1_A850_F800155291D3__INCLUDED_)
