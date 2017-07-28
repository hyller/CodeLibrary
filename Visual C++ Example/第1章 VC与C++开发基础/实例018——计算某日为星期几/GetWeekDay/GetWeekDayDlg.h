// GetWeekDayDlg.h : header file
//

#if !defined(AFX_GETWEEKDAYDLG_H__8DF91A53_3899_4899_ACE9_446A981CCCF0__INCLUDED_)
#define AFX_GETWEEKDAYDLG_H__8DF91A53_3899_4899_ACE9_446A981CCCF0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGetWeekDayDlg dialog

class CGetWeekDayDlg : public CDialog
{
// Construction
public:
	CGetWeekDayDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGetWeekDayDlg)
	enum { IDD = IDD_GETWEEKDAY_DIALOG };
	CString	m_strWeekDay;
	COleDateTime	m_Time;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetWeekDayDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGetWeekDayDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCal();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETWEEKDAYDLG_H__8DF91A53_3899_4899_ACE9_446A981CCCF0__INCLUDED_)
