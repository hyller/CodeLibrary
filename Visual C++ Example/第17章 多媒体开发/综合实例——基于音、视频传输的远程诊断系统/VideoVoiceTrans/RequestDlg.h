#if !defined(AFX_REQUESTDLG_H__5FB1D083_5F66_11D6_8897_000B2B0F84B6__INCLUDED_)
#define AFX_REQUESTDLG_H__5FB1D083_5F66_11D6_8897_000B2B0F84B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RequestDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// RequestDlg dialog

class RequestDlg : public CDialog
{
// Construction
public:
	
	char rname[500];
	char raddress[500];

	CDialog *pdlg;



	RequestDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(RequestDlg)
	enum { IDD = IDD_DIALOG2 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(RequestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
	public:

	// Generated message map functions
	//{{AFX_MSG(RequestDlg)
	afx_msg BOOL OnInitDialog();
	afx_msg void OnAccept();
	afx_msg void OnReject();
	void SetParameter(char *hostname,char *hostaddress,CDialog *dlg) ;
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REQUESTDLG_H__5FB1D083_5F66_11D6_8897_000B2B0F84B6__INCLUDED_)
