#if !defined(AFX_LINKNAME_H__D4992523_AAB2_4170_81B4_1B652A555C4F__INCLUDED_)
#define AFX_LINKNAME_H__D4992523_AAB2_4170_81B4_1B652A555C4F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LinkName.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLinkName dialog

class CLinkNameDlg : public CDialog
{
// Construction
public:
	CLinkNameDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLinkName)
	enum { IDD = IDD_DIALOG1 };
	CString	m_linkname;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLinkName)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLinkName)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINKNAME_H__D4992523_AAB2_4170_81B4_1B652A555C4F__INCLUDED_)
