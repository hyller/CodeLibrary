// CExceptionDemoDlg.h : header file
//

#if !defined(AFX_CEXCEPTIONDEMODLG_H__5FFA74B3_738E_46A9_AC10_827AD844E516__INCLUDED_)
#define AFX_CEXCEPTIONDEMODLG_H__5FFA74B3_738E_46A9_AC10_827AD844E516__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCExceptionDemoDlg dialog

class CCExceptionDemoDlg : public CDialog
{
// Construction
public:
	CCExceptionDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCExceptionDemoDlg)
	enum { IDD = IDD_CEXCEPTIONDEMO_DIALOG };
	CString	m_filename;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCExceptionDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCExceptionDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOpenfile();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CEXCEPTIONDEMODLG_H__5FFA74B3_738E_46A9_AC10_827AD844E516__INCLUDED_)
