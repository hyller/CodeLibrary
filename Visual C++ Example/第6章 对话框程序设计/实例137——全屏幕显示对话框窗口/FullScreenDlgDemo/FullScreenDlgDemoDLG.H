// FullScreenDlgDemoDlg.h : header file
//

#if !defined(AFX_FullScreenDlgDemoDLG_H__5E04B70C_4F9F_4BE8_A354_1C98AD0228C5__INCLUDED_)
#define AFX_FullScreenDlgDemoDLG_H__5E04B70C_4F9F_4BE8_A354_1C98AD0228C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFullScreenDlgDemoDlg dialog

class CFullScreenDlgDemoDlg : public CDialog
{
// Construction
public:
	CFullScreenDlgDemoDlg(CWnd* pParent = NULL);	// standard constructor
	void GoFullScreen(HWND hwnd,BOOL bFullScreen, RECT *sizerect);
// Dialog Data
	//{{AFX_DATA(CFullScreenDlgDemoDlg)
	enum { IDD = IDD_FullScreenDlgDemo_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFullScreenDlgDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFullScreenDlgDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnGotofullscreen();
	afx_msg void OnExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	BOOL m_bFullScreen;

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FullScreenDlgDemoDLG_H__5E04B70C_4F9F_4BE8_A354_1C98AD0228C5__INCLUDED_)
