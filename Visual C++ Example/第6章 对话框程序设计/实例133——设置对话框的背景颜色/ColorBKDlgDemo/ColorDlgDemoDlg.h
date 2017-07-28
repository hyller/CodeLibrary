// ColorDlgDemoDlg.h : header file
//

#if !defined(AFX_COLORDLGDEMODLG_H__F944D52D_D0D5_45EA_BDFA_AAFE381EC117__INCLUDED_)
#define AFX_COLORDLGDEMODLG_H__F944D52D_D0D5_45EA_BDFA_AAFE381EC117__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CColorDlgDemoDlg dialog

class CColorDlgDemoDlg : public CDialog
{
// Construction
public:
	CColorDlgDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CColorDlgDemoDlg)
	enum { IDD = IDD_COLORDLGDEMO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorDlgDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	COLORREF crColor;											//ÑÕÉ«
	CBrush m_BKBrush;//»­Ë¢
	// Generated message map functions
	//{{AFX_MSG(CColorDlgDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSetcolor();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORDLGDEMODLG_H__F944D52D_D0D5_45EA_BDFA_AAFE381EC117__INCLUDED_)
