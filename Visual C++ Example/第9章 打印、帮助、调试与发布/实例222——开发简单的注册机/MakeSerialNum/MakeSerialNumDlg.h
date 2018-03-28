// MakeSerialNumDlg.h : header file
//

#if !defined(AFX_MAKESERIALNUMDLG_H__A2D5C503_6AA6_4840_9428_761330CA1BFF__INCLUDED_)
#define AFX_MAKESERIALNUMDLG_H__A2D5C503_6AA6_4840_9428_761330CA1BFF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMakeSerialNumDlg dialog

class CMakeSerialNumDlg : public CDialog
{
// Construction
public:
	CMakeSerialNumDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMakeSerialNumDlg)
	enum { IDD = IDD_MAKESERIALNUM_DIALOG };
	DWORD	m_usernum;
	DWORD	m_serialnum;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMakeSerialNumDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMakeSerialNumDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMake();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAKESERIALNUMDLG_H__A2D5C503_6AA6_4840_9428_761330CA1BFF__INCLUDED_)
