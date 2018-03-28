// SliderSpinDemoDlg.h : header file
//

#if !defined(AFX_SLIDERSPINDEMODLG_H__32418572_BF78_43B5_A7B1_1FB0B1FDD340__INCLUDED_)
#define AFX_SLIDERSPINDEMODLG_H__32418572_BF78_43B5_A7B1_1FB0B1FDD340__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSliderSpinDemoDlg dialog

class CSliderSpinDemoDlg : public CDialog
{
// Construction
public:
	CSliderSpinDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSliderSpinDemoDlg)
	enum { IDD = IDD_SLIDERSPINDEMO_DIALOG };
	CSliderCtrl	m_ctlSlider;
	CSpinButtonCtrl	m_ctlSpin;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSliderSpinDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSliderSpinDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SLIDERSPINDEMODLG_H__32418572_BF78_43B5_A7B1_1FB0B1FDD340__INCLUDED_)
