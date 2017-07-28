// ReturnEditDemoDlg.h : header file
//

#if !defined(AFX_RETURNEDITDEMODLG_H__490F599E_8405_4928_A45D_23553C526243__INCLUDED_)
#define AFX_RETURNEDITDEMODLG_H__490F599E_8405_4928_A45D_23553C526243__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CReturnEditDemoDlg dialog

class CReturnEditDemoDlg : public CDialog
{
// Construction
public:
	CReturnEditDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CReturnEditDemoDlg)
	enum { IDD = IDD_RETURNEDITDEMO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReturnEditDemoDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CReturnEditDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RETURNEDITDEMODLG_H__490F599E_8405_4928_A45D_23553C526243__INCLUDED_)
