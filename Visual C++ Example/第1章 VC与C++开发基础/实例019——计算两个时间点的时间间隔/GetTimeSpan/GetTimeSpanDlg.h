// GetTimeSpanDlg.h : header file
//

#if !defined(AFX_GETTIMESPANDLG_H__25BB4D91_9ADE_4CB9_A364_61D4EF157EFC__INCLUDED_)
#define AFX_GETTIMESPANDLG_H__25BB4D91_9ADE_4CB9_A364_61D4EF157EFC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGetTimeSpanDlg dialog

class CGetTimeSpanDlg : public CDialog
{
// Construction
public:
	CGetTimeSpanDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGetTimeSpanDlg)
	enum { IDD = IDD_GETTIMESPAN_DIALOG };
	CString	m_strTime;
	long	m_Days;
	long	m_Hours;
	long	m_Minutes;
	long	m_Seconds;
	long	m_TotalMinutes;
	long	m_TotalHours;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetTimeSpanDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGetTimeSpanDlg)
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

#endif // !defined(AFX_GETTIMESPANDLG_H__25BB4D91_9ADE_4CB9_A364_61D4EF157EFC__INCLUDED_)
