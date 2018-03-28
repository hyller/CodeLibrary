// UseOleEditDlg.h : header file
//

#if !defined(AFX_USEOLEEDITDLG_H__604C4624_E89F_4C89_A373_FA3FC4F3DBCE__INCLUDED_)
#define AFX_USEOLEEDITDLG_H__604C4624_E89F_4C89_A373_FA3FC4F3DBCE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CUseOleEditDlg dialog

class CUseOleEditDlg : public CDialog
{
// Construction
public:
	CUseOleEditDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CUseOleEditDlg)
	enum { IDD = IDD_USEOLEEDIT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseOleEditDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CUseOleEditDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USEOLEEDITDLG_H__604C4624_E89F_4C89_A373_FA3FC4F3DBCE__INCLUDED_)
