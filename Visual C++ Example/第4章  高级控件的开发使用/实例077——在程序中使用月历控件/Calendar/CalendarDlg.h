// CalendarDlg.h : header file
//

#if !defined(AFX_CALENDARDLG_H__94A3E3E9_71BB_11D6_8F32_00E04CE76240__INCLUDED_)
#define AFX_CALENDARDLG_H__94A3E3E9_71BB_11D6_8F32_00E04CE76240__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCalendarDlg dialog
#define	 WM_SELCHANGE WM_USER+1000
class CCalendarDlg : public CDialog
{
// Construction
public:
	CCalendarDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCalendarDlg)
	enum { IDD = IDD_CALENDAR_DIALOG };
	CMonthCalCtrl	m_MonthCalCtrl;
	int		m_nDay;
	int		m_nMonth;
	int		m_nYear;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCalendarDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCalendarDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSetToday();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALENDARDLG_H__94A3E3E9_71BB_11D6_8F32_00E04CE76240__INCLUDED_)
