#if !defined(AFX_ADDRDLG_H__3935A6D8_2AFA_4262_A312_9E972B7DECDE__INCLUDED_)
#define AFX_ADDRDLG_H__3935A6D8_2AFA_4262_A312_9E972B7DECDE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddrDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddrDlg dialog

class CAddrDlg : public CDialog
{
// Construction
public:
	CAddrDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddrDlg)
	enum { IDD = IDD_DIALOG1 };
	CString	m_Addr;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddrDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddrDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDRDLG_H__3935A6D8_2AFA_4262_A312_9E972B7DECDE__INCLUDED_)
