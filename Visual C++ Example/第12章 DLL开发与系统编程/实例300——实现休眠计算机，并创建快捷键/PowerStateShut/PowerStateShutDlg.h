// PowerStateShutDlg.h : header file
//

#if !defined(AFX_POWERSTATESHUTDLG_H__86342AB1_12DE_48E4_ACA9_08A611904C75__INCLUDED_)
#define AFX_POWERSTATESHUTDLG_H__86342AB1_12DE_48E4_ACA9_08A611904C75__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPowerStateShutDlg dialog

class CPowerStateShutDlg : public CDialog
{
// Construction
public:
	CPowerStateShutDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPowerStateShutDlg)
	enum { IDD = IDD_POWERSTATESHUT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPowerStateShutDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	HACCEL m_accel;

	// Generated message map functions
	//{{AFX_MSG(CPowerStateShutDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnPowerstate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POWERSTATESHUTDLG_H__86342AB1_12DE_48E4_ACA9_08A611904C75__INCLUDED_)
