// PartTransDlgDlg.h : header file
//

#if !defined(AFX_PARTTRANSDLGDLG_H__3AC6E59D_6F2F_4281_A09B_FFEEA4F535D4__INCLUDED_)
#define AFX_PARTTRANSDLGDLG_H__3AC6E59D_6F2F_4281_A09B_FFEEA4F535D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPartTransDlgDlg dialog

class CPartTransDlgDlg : public CDialog
{
// Construction
public:
	CPartTransDlgDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPartTransDlgDlg)
	enum { IDD = IDD_PARTTRANSDLG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPartTransDlgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPartTransDlgDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PARTTRANSDLGDLG_H__3AC6E59D_6F2F_4281_A09B_FFEEA4F535D4__INCLUDED_)
