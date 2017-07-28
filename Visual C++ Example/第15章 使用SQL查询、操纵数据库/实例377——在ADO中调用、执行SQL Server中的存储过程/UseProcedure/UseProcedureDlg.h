// UseProcedureDlg.h : header file
//
//{{AFX_INCLUDES()
//}}AFX_INCLUDES

#if !defined(AFX_USEPROCEDUREDLG_H__16796808_4C2B_40E7_B66F_08580FD84B36__INCLUDED_)
#define AFX_USEPROCEDUREDLG_H__16796808_4C2B_40E7_B66F_08580FD84B36__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CUseProcedureDlg dialog

class CUseProcedureDlg : public CDialog
{
// Construction
public:
	CUseProcedureDlg(CWnd* pParent = NULL);	// standard constructor
	_ConnectionPtr m_pConnection;
// Dialog Data
	//{{AFX_DATA(CUseProcedureDlg)
	enum { IDD = IDD_USEPROCEDURE_DIALOG };
	CListBox	m_ctlList;
	CString	m_DName;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseProcedureDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CUseProcedureDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnExcute();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USEPROCEDUREDLG_H__16796808_4C2B_40E7_B66F_08580FD84B36__INCLUDED_)
