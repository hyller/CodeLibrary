// EditTreeControlDlg.h : header file
//

#if !defined(AFX_EditTreeControlDLG_H__D61433F1_414A_4C7E_88B5_866E823DCEEC__INCLUDED_)
#define AFX_EditTreeControlDLG_H__D61433F1_414A_4C7E_88B5_866E823DCEEC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEditTreeControlDlg dialog

class CEditTreeControlDlg : public CDialog
{
// Construction
public:
	CEditTreeControlDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CEditTreeControlDlg)
	enum { IDD = IDD_EditTreeControl_DIALOG };
	CTreeCtrl	m_ctlTree;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditTreeControlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CImageList m_imageList;//定义图像列表控件

	// Generated message map functions
	//{{AFX_MSG(CEditTreeControlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBeginlabeleditTree1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEndlabeleditTree1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkTree1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEdit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EditTreeControlDLG_H__D61433F1_414A_4C7E_88B5_866E823DCEEC__INCLUDED_)
