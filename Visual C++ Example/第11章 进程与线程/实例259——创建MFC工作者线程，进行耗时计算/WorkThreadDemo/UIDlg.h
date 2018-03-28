#if !defined(AFX_UIDLG_H__DFAA2E51_4304_445A_BB65_A8A8D9D077CA__INCLUDED_)
#define AFX_UIDLG_H__DFAA2E51_4304_445A_BB65_A8A8D9D077CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UIDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUIDlg dialog

class CUIDlg : public CDialog
{
// Construction
public:
	CUIDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CUIDlg)
	enum { IDD = IDD_DIALOG1 };
	CProgressCtrl	m_progress;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUIDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUIDlg)
	afx_msg void OnStar();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UIDLG_H__DFAA2E51_4304_445A_BB65_A8A8D9D077CA__INCLUDED_)
