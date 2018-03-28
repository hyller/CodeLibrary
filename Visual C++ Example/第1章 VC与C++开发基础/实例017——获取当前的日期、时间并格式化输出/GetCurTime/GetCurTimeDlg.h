// GetCurTimeDlg.h : header file
//

#if !defined(AFX_GETCURTIMEDLG_H__AE9C7159_F037_491B_AB86_05DF4AAC9CA9__INCLUDED_)
#define AFX_GETCURTIMEDLG_H__AE9C7159_F037_491B_AB86_05DF4AAC9CA9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGetCurTimeDlg dialog

class CGetCurTimeDlg : public CDialog
{
// Construction
public:
	CGetCurTimeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGetCurTimeDlg)
	enum { IDD = IDD_GETCURTIME_DIALOG };
	CString	m_strDate;
	CString	m_strTime;
	CString	m_strDateTime;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetCurTimeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGetCurTimeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnGet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETCURTIMEDLG_H__AE9C7159_F037_491B_AB86_05DF4AAC9CA9__INCLUDED_)
