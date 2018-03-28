// ListBoxDemoDlg.h : header file
//

#if !defined(AFX_LISTBOXDEMODLG_H__4F70B979_88EB_4C2B_9FF4_35B81295A59E__INCLUDED_)
#define AFX_LISTBOXDEMODLG_H__4F70B979_88EB_4C2B_9FF4_35B81295A59E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CListBoxDemoDlg dialog

class CListBoxDemoDlg : public CDialog
{
// Construction
public:
	CListBoxDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CListBoxDemoDlg)
	enum { IDD = IDD_LISTBOXDEMO_DIALOG };
	CButton	m_ctlIn;
	CButton	m_ctlOut;
	CListBox	m_list2;
	CListBox	m_list1;
	CString	m_unit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListBoxDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CListBoxDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAdd();
	afx_msg void OnIn();
	afx_msg void OnOut();
	afx_msg void OnSelchangeList1();
	afx_msg void OnSelchangeList2();
	afx_msg void OnDblclkList1();
	afx_msg void OnDblclkList2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTBOXDEMODLG_H__4F70B979_88EB_4C2B_9FF4_35B81295A59E__INCLUDED_)
