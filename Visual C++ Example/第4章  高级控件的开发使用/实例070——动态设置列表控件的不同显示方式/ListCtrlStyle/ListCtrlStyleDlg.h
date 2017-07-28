// ListCtrlStyleDlg.h : header file
//

#if !defined(AFX_ListCtrlStyleDLG_H__5D902156_3E5F_4DBA_AFB6_A5B83216413C__INCLUDED_)
#define AFX_ListCtrlStyleDLG_H__5D902156_3E5F_4DBA_AFB6_A5B83216413C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CListCtrlStyleDlg dialog

class CListCtrlStyleDlg : public CDialog
{
// Construction
public:
	CListCtrlStyleDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CListCtrlStyleDlg)
	enum { IDD = IDD_ListCtrlStyle_DIALOG };
	CListCtrl	m_ctlList;
	CString	m_edit;
	int		m_radio;
	CString	m_static;
	int		m_radio2;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListCtrlStyleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CImageList m_pImageList;							//图像列表对象

	// Generated message map functions
	//{{AFX_MSG(CListCtrlStyleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRadio3();
	afx_msg void OnRadio5();
	afx_msg void OnRadio6();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ListCtrlStyleDLG_H__5D902156_3E5F_4DBA_AFB6_A5B83216413C__INCLUDED_)
