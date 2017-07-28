// ColorPickDemoDlg.h : header file
//

#if !defined(AFX_COLORPICKDEMODLG_H__DF2FCEC8_5093_41F2_88CD_A2D0F7EC2372__INCLUDED_)
#define AFX_COLORPICKDEMODLG_H__DF2FCEC8_5093_41F2_88CD_A2D0F7EC2372__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CColorPickDemoDlg dialog

class CColorPickDemoDlg : public CDialog
{
// Construction
public:
	CColorPickDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CColorPickDemoDlg)
	enum { IDD = IDD_COLORPICKDEMO_DIALOG };
	CStatic	m_ctlColor;
	CStatic	m_ctlBmp;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorPickDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CColorPickDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORPICKDEMODLG_H__DF2FCEC8_5093_41F2_88CD_A2D0F7EC2372__INCLUDED_)
