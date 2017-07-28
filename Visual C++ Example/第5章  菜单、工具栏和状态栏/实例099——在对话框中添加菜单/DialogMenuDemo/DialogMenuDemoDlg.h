// DialogMenuDemoDlg.h : header file
//

#if !defined(AFX_DIALOGMENUDEMODLG_H__DA010376_EF46_42A7_8F41_189506AF0293__INCLUDED_)
#define AFX_DIALOGMENUDEMODLG_H__DA010376_EF46_42A7_8F41_189506AF0293__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDialogMenuDemoDlg dialog

class CDialogMenuDemoDlg : public CDialog
{
// Construction
public:
	CDialogMenuDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDialogMenuDemoDlg)
	enum { IDD = IDD_DIALOGMENUDEMO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogMenuDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDialogMenuDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMenuitem32773();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGMENUDEMODLG_H__DA010376_EF46_42A7_8F41_189506AF0293__INCLUDED_)
