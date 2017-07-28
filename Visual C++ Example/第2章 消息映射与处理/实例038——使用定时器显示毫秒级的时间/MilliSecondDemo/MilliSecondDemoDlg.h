// MilliSecondDemoDlg.h : header file
//

#if !defined(AFX_MILLISECONDDEMODLG_H__7E7ED039_31C4_47AB_A71E_13ADB72650A3__INCLUDED_)
#define AFX_MILLISECONDDEMODLG_H__7E7ED039_31C4_47AB_A71E_13ADB72650A3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMilliSecondDemoDlg dialog

class CMilliSecondDemoDlg : public CDialog
{
// Construction
public:
	CMilliSecondDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMilliSecondDemoDlg)
	enum { IDD = IDD_MILLISECONDDEMO_DIALOG };
	CString	m_strTime;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMilliSecondDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMilliSecondDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MILLISECONDDEMODLG_H__7E7ED039_31C4_47AB_A71E_13ADB72650A3__INCLUDED_)
