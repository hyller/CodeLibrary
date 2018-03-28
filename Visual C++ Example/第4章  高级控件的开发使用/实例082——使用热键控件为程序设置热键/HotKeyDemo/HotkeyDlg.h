#if !defined(AFX_HOTKEYDLG_H__0F156582_1C98_47C4_A971_B39E0052F8B0__INCLUDED_)
#define AFX_HOTKEYDLG_H__0F156582_1C98_47C4_A971_B39E0052F8B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HotkeyDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHotkeyDlg dialog

class CHotkeyDlg : public CDialog
{
// Construction
public:
	CHotkeyDlg(CWnd* pParent = NULL);   // standard constructor
	
// Dialog Data
	//{{AFX_DATA(CHotkeyDlg)
	enum { IDD = IDD_DIALOG1 };
	CHotKeyCtrl	m_ctlHotKey;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHotkeyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CHotkeyDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HOTKEYDLG_H__0F156582_1C98_47C4_A971_B39E0052F8B0__INCLUDED_)
