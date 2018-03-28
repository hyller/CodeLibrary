// EnumRegValueDlg.h : header file
//

#if !defined(AFX_ENUMREGVALUEDLG_H__F613320B_2271_45E0_8E88_AF6C7BDD4CCD__INCLUDED_)
#define AFX_ENUMREGVALUEDLG_H__F613320B_2271_45E0_8E88_AF6C7BDD4CCD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEnumRegValueDlg dialog

class CEnumRegValueDlg : public CDialog
{
// Construction
public:
	CEnumRegValueDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CEnumRegValueDlg)
	enum { IDD = IDD_ENUMREGVALUE_DIALOG };
	CListBox	m_ctlList;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnumRegValueDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEnumRegValueDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnEnum();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENUMREGVALUEDLG_H__F613320B_2271_45E0_8E88_AF6C7BDD4CCD__INCLUDED_)
