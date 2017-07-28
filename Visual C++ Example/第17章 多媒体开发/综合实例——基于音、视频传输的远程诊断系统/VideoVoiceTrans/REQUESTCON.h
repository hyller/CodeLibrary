#if !defined(AFX_REQUESTCON_H__31E9FB5A_2D16_4AE2_80A5_C015768177DF__INCLUDED_)
#define AFX_REQUESTCON_H__31E9FB5A_2D16_4AE2_80A5_C015768177DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// REQUESTCON.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// REQUESTCON dialog

class REQUESTCON : public CDialog
{
// Attributes
public:
	CDialog *mdlg;
	// Construction
public:
	REQUESTCON(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(REQUESTCON)
	enum { IDD = IDD_REQUESTCON };
	CString	m_Armname;
	CString	m_Code;
	CString	m_Name;
	CString	m_Requestname;
	CString	m_telephone;
	CString	m_Dept;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(REQUESTCON)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
	public:

	// Generated message map functions
	//{{AFX_MSG(REQUESTCON)
	void SetParent(CDialog *dlg);
	afx_msg void OnClear();
	afx_msg void OnConnect();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REQUESTCON_H__31E9FB5A_2D16_4AE2_80A5_C015768177DF__INCLUDED_)
