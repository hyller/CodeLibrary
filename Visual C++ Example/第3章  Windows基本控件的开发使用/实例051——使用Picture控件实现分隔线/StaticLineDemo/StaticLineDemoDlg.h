// StaticLineDemoDlg.h : header file
//

#if !defined(AFX_STATICLINEDEMODLG_H__943A3176_4E7B_4E9F_9CA5_BD823A117B23__INCLUDED_)
#define AFX_STATICLINEDEMODLG_H__943A3176_4E7B_4E9F_9CA5_BD823A117B23__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CStaticLineDemoDlg dialog

class CStaticLineDemoDlg : public CDialog
{
// Construction
public:
	CStaticLineDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CStaticLineDemoDlg)
	enum { IDD = IDD_STATICLINEDEMO_DIALOG };
	CButton	m_ctlShow;
	CButton	m_ctlHide;
	CStatic	m_ctlLine2;
	CStatic	m_ctlLine1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStaticLineDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CStaticLineDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnShow();
	afx_msg void OnHide();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATICLINEDEMODLG_H__943A3176_4E7B_4E9F_9CA5_BD823A117B23__INCLUDED_)
