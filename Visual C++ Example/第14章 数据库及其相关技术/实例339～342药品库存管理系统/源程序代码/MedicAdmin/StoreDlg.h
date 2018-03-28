#if !defined(AFX_STOREDLG_H__89652CDD_E4AC_4626_BB88_063CF204D3B4__INCLUDED_)
#define AFX_STOREDLG_H__89652CDD_E4AC_4626_BB88_063CF204D3B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StoreDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStoreDlg dialog

class CStoreDlg : public CDialog
{
// Construction
public:
	CStoreDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CStoreDlg)
	enum { IDD = IDD_STORE_DIALOG };
	CString	m_company;
	int		m_day;
	CString	m_id;
	CString	m_name;
	int		m_month;
	int		m_periodQuelity;
	int		m_number;
	CString	m_place;
	CString	m_type;
	float	m_unitPrice;
	int		m_year;
	CString	m_description;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStoreDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CStoreDlg)
	virtual void OnOK();
	afx_msg void OnExitButton();
	virtual void OnCancel();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STOREDLG_H__89652CDD_E4AC_4626_BB88_063CF204D3B4__INCLUDED_)
