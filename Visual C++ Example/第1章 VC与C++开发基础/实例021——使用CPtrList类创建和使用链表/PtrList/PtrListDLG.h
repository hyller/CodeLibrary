// PtrListDlg.h : header file
//

#if !defined(AFX_PtrListDLG_H__B83BFE1D_6258_4D44_A5B1_8D633216C2A0__INCLUDED_)
#define AFX_PtrListDLG_H__B83BFE1D_6258_4D44_A5B1_8D633216C2A0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPtrListDlg dialog

class CPtrListDlg : public CDialog
{
// Construction
public:
	void Reflesh();
	CPtrListDlg(CWnd* pParent = NULL);	// standard constructor
	CPtrList m_accountlist;

// Dialog Data
	//{{AFX_DATA(CPtrListDlg)
	enum { IDD = IDD_PtrList_DIALOG };
	CListBox	m_list;
	CString	m_name;
	double		m_count;
	double		m_total;
	int		m_radio;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPtrListDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPtrListDlg)
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

#endif // !defined(AFX_PtrListDLG_H__B83BFE1D_6258_4D44_A5B1_8D633216C2A0__INCLUDED_)
