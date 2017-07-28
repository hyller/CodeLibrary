// BaseTreeControlDlg.h : header file
//

#if !defined(AFX_BASETREECONTROLDLG_H__D61433F1_414A_4C7E_88B5_866E823DCEEC__INCLUDED_)
#define AFX_BASETREECONTROLDLG_H__D61433F1_414A_4C7E_88B5_866E823DCEEC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBaseTreeControlDlg dialog

class CBaseTreeControlDlg : public CDialog
{
// Construction
public:
	CBaseTreeControlDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBaseTreeControlDlg)
	enum { IDD = IDD_BASETREECONTROL_DIALOG };
	CTreeCtrl	m_ctlTree;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBaseTreeControlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CImageList m_imageList;//定义图像列表控件

	// Generated message map functions
	//{{AFX_MSG(CBaseTreeControlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BASETREECONTROLDLG_H__D61433F1_414A_4C7E_88B5_866E823DCEEC__INCLUDED_)
