// PlSoundDemoDlg.h : header file
//

#if !defined(AFX_PLSOUNDDEMODLG_H__EE253BE6_F6C5_44B1_BC9E_38564DBF481D__INCLUDED_)
#define AFX_PLSOUNDDEMODLG_H__EE253BE6_F6C5_44B1_BC9E_38564DBF481D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPlSoundDemoDlg dialog

class CPlSoundDemoDlg : public CDialog
{
// Construction
public:
	CPlSoundDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPlSoundDemoDlg)
	enum { IDD = IDD_PLSOUNDDEMO_DIALOG };
	CString	m_strStatus;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlSoundDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPlSoundDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnPlayresource();
	afx_msg void OnPlaysystem();
	afx_msg void OnPlaywavefile();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLSOUNDDEMODLG_H__EE253BE6_F6C5_44B1_BC9E_38564DBF481D__INCLUDED_)
