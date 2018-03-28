// DatePickerDemoDlg.h : header file
//

#if !defined(AFX_DATEPICKERDEMODLG_H__AD1354AC_3259_4C53_A7E7_A4A06822E803__INCLUDED_)
#define AFX_DATEPICKERDEMODLG_H__AD1354AC_3259_4C53_A7E7_A4A06822E803__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDatePickerDemoDlg dialog

class CDatePickerDemoDlg : public CDialog
{
// Construction
public:
	CDatePickerDemoDlg(CWnd* pParent = NULL);	// standard constructor
	CTime	      m_SysTime;
// Dialog Data
	//{{AFX_DATA(CDatePickerDemoDlg)
	enum { IDD = IDD_DATEPICKERDEMO_DIALOG };
	CDateTimeCtrl	m_ctlDateTime;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDatePickerDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDatePickerDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATEPICKERDEMODLG_H__AD1354AC_3259_4C53_A7E7_A4A06822E803__INCLUDED_)
