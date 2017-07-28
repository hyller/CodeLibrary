// AutoComboDemoDlg.h : header file
//

#if !defined(AFX_AUTOCOMBODEMODLG_H__D1D0A5D7_E431_4153_BECA_EC0622C5C9B4__INCLUDED_)
#define AFX_AUTOCOMBODEMODLG_H__D1D0A5D7_E431_4153_BECA_EC0622C5C9B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "AutoCombo.h"
/////////////////////////////////////////////////////////////////////////////
// CAutoComboDemoDlg dialog

class CAutoComboDemoDlg : public CDialog
{
// Construction
public:
	CAutoComboDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAutoComboDemoDlg)
	enum { IDD = IDD_AUTOCOMBODEMO_DIALOG };
	CAutoCombo	m_ctlCombo;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAutoComboDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAutoComboDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUTOCOMBODEMODLG_H__D1D0A5D7_E431_4153_BECA_EC0622C5C9B4__INCLUDED_)
