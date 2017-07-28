// UseExternVarDllDlg.h : header file
//

#if !defined(AFX_USEEXTERNVARDLLDLG_H__01DEFAEC_05DA_4DCE_89CF_18D1D132455A__INCLUDED_)
#define AFX_USEEXTERNVARDLLDLG_H__01DEFAEC_05DA_4DCE_89CF_18D1D132455A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CUseExternVarDllDlg dialog

class CUseExternVarDllDlg : public CDialog
{
// Construction
public:
	CUseExternVarDllDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CUseExternVarDllDlg)
	enum { IDD = IDD_USEEXTERNVARDLL_DIALOG };
	CString	m_strVar;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseExternVarDllDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CUseExternVarDllDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLoad();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USEEXTERNVARDLLDLG_H__01DEFAEC_05DA_4DCE_89CF_18D1D132455A__INCLUDED_)
