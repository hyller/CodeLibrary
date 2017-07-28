#if !defined(AFX_SEARCHTYPEDLG_H__5E556FFE_0D54_4B02_8628_A8B1ADB9BF0D__INCLUDED_)
#define AFX_SEARCHTYPEDLG_H__5E556FFE_0D54_4B02_8628_A8B1ADB9BF0D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SearchTypeDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSearchTypeDlg dialog

class CSearchTypeDlg : public CDialog
{
// Construction
public:
	CSearchTypeDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSearchTypeDlg)
	enum { IDD = IDD_SEARCH_TYPE_DIALOG };
	CString	m_type;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSearchTypeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSearchTypeDlg)
	afx_msg void OnSearchType();
	afx_msg void OnSearchTypeExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEARCHTYPEDLG_H__5E556FFE_0D54_4B02_8628_A8B1ADB9BF0D__INCLUDED_)
