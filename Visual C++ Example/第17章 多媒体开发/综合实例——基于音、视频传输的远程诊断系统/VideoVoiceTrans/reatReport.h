#if !defined(AFX_REATREPORT_H__4FA4646B_D019_4876_B51F_0084E8DFCFAE__INCLUDED_)
#define AFX_REATREPORT_H__4FA4646B_D019_4876_B51F_0084E8DFCFAE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// reatReport.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CreatReport dialog

class CreatReport : public CDialog
{
// Construction
public:
	CreatReport(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CreatReport)
	enum { IDD = IDD_RESULT };
	CString	m_Address;
	CString	m_Type;
	CString	m_Name;
	CString	m_Scribe;
	CString	m_Reporter;
	CTime	m_Data;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CreatReport)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CreatReport)
	afx_msg void OnSavereport();
	virtual void OnCancel();
	afx_msg void OnDatabase();
	afx_msg void OnClear();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REATREPORT_H__4FA4646B_D019_4876_B51F_0084E8DFCFAE__INCLUDED_)
