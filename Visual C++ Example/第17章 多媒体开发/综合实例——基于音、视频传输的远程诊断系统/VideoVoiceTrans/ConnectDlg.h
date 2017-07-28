#if !defined(AFX_ONNECTDLG_H__B098630E_5F44_11D6_8897_000B2B0F84B6__INCLUDED_)
#define AFX_ONNECTDLG_H__B098630E_5F44_11D6_8897_000B2B0F84B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// onnectDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ConnectDlg dialog

class ConnectDlg : public CDialog
{
// Attributes
public:
	CDialog *mdlg;
	
	
// Construction
public:
	ConnectDlg(CWnd* pParent = NULL);   // standard constructor



// Dialog Data
	//{{AFX_DATA(ConnectDlg)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ConnectDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
	public:

	// Generated message map functions
	//{{AFX_MSG(ConnectDlg)
	void SetParent(CDialog *dlg);
	afx_msg void OnConnect();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ONNECTDLG_H__B098630E_5F44_11D6_8897_000B2B0F84B6__INCLUDED_)
