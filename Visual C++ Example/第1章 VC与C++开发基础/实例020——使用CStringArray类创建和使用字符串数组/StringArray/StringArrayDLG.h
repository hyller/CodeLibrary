// StringArrayDlg.h : header file
//

#if !defined(AFX_StringArrayDLG_H__C1193588_2671_4992_BC29_555E9A66DDD5__INCLUDED_)
#define AFX_StringArrayDLG_H__C1193588_2671_4992_BC29_555E9A66DDD5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CStringArrayDlg dialog

class CStringArrayDlg : public CDialog
{
// Construction
public:
	CStringArrayDlg(CWnd* pParent = NULL);	// standard constructor
	CStringArray m_array;

// Dialog Data
	//{{AFX_DATA(CStringArrayDlg)
	enum { IDD = IDD_StringArray_DIALOG };
	CListBox	m_list;
	int		m_radio;
	int		m_pos;
	CString	m_str;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStringArrayDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CStringArrayDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCheck();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_StringArrayDLG_H__C1193588_2671_4992_BC29_555E9A66DDD5__INCLUDED_)
