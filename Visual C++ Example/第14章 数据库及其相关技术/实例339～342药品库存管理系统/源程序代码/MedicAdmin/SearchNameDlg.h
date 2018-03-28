#if !defined(AFX_SEARCHNAMEDLG_H__04C8247C_49EA_4B20_9F36_DA1F98409C32__INCLUDED_)
#define AFX_SEARCHNAMEDLG_H__04C8247C_49EA_4B20_9F36_DA1F98409C32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SearchNameDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSearchNameDlg dialog

class CSearchNameDlg : public CDialog
{
// Construction
public:
	CSearchNameDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSearchNameDlg)
	enum { IDD = IDD_SEARCH_NAME_DIALOG };
	CString	m_name;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSearchNameDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSearchNameDlg)
	afx_msg void OnSearchName();
	afx_msg void OnSearchNameExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEARCHNAMEDLG_H__04C8247C_49EA_4B20_9F36_DA1F98409C32__INCLUDED_)
