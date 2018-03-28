// CreateDestroyProcessDlg.h : header file
//

#if !defined(AFX_CreateDestroyProcessDLG_H__E9E5388A_6F62_11D6_8F32_00E04CE76240__INCLUDED_)
#define AFX_CreateDestroyProcessDLG_H__E9E5388A_6F62_11D6_8F32_00E04CE76240__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCreateDestroyProcessDlg dialog

class CCreateDestroyProcessDlg : public CDialog
{
// Construction
public:
	CCreateDestroyProcessDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCreateDestroyProcessDlg)
	enum { IDD = IDD_CreateDestroyProcess_DIALOG };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateDestroyProcessDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	HANDLE m_hPro; 
	// Generated message map functions
	//{{AFX_MSG(CCreateDestroyProcessDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStart();
	afx_msg void OnStop();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CreateDestroyProcessDLG_H__E9E5388A_6F62_11D6_8F32_00E04CE76240__INCLUDED_)
