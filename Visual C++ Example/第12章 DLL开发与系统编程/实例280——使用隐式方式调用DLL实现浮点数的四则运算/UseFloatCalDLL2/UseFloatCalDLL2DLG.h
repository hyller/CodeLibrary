// UseFloatCalDLL2Dlg.h : header file
//

#if !defined(AFX_UseFloatCalDLL2DLG_H__665D0A79_8F3A_44AA_97F2_87D49C8D45A9__INCLUDED_)
#define AFX_UseFloatCalDLL2DLG_H__665D0A79_8F3A_44AA_97F2_87D49C8D45A9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CUseFloatCalDLL2Dlg dialog

class CUseFloatCalDLL2Dlg : public CDialog
{
// Construction
public:
	CUseFloatCalDLL2Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CUseFloatCalDLL2Dlg)
	enum { IDD = IDD_UseFloatCalDLL2_DIALOG };
	float	m_floNum1;
	float	m_floNum2;
	float	m_floResult;
	int		m_radio;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseFloatCalDLL2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CUseFloatCalDLL2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCal();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UseFloatCalDLL2DLG_H__665D0A79_8F3A_44AA_97F2_87D49C8D45A9__INCLUDED_)
