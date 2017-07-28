// ColorStaticDemoDlg.h : header file
//

#if !defined(AFX_COLORSTATICDEMODLG_H__5863F361_4CCB_40AB_99D1_9C358D10C196__INCLUDED_)
#define AFX_COLORSTATICDEMODLG_H__5863F361_4CCB_40AB_99D1_9C358D10C196__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CColorStaticDemoDlg dialog
class CColorStaticDemoDlg : public CDialog
{
// Construction
public:
	CColorStaticDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CColorStaticDemoDlg)
	enum { IDD = IDD_COLORSTATICDEMO_DIALOG };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorStaticDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CColorStaticDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORSTATICDEMODLG_H__5863F361_4CCB_40AB_99D1_9C358D10C196__INCLUDED_)
