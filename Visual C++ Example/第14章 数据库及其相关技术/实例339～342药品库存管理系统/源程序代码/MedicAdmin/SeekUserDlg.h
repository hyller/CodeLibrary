#if !defined(AFX_SEEKUSERDLG_H__D49A5B83_6C66_4D60_9CDA_F907913B05EB__INCLUDED_)
#define AFX_SEEKUSERDLG_H__D49A5B83_6C66_4D60_9CDA_F907913B05EB__INCLUDED_
#include "userset.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SeekUserDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSeekUserDlg dialog

class CSeekUserDlg : public CDialog
{
// Construction
public:
	CUserSet* theSet;
	CSeekUserDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSeekUserDlg)
	enum { IDD = IDD_SEEK_USER_DIALOG };
	CListCtrl	m_seekList;
	CString	m_account;
	CString	m_type;
	int		m_typeRadio;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSeekUserDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSeekUserDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEEKUSERDLG_H__D49A5B83_6C66_4D60_9CDA_F907913B05EB__INCLUDED_)
