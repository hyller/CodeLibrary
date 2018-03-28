#if !defined(AFX_TEXTCOLORDLG_H__E44BBEF5_826E_47EB_8D5A_4280DA2A504B__INCLUDED_)
#define AFX_TEXTCOLORDLG_H__E44BBEF5_826E_47EB_8D5A_4280DA2A504B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TextColorDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTextColorDlg dialog

class CTextColorDlg: public CDialog
{
// Construction
public:
	CTextColorDlg(CWnd* pParent);   // standard constructor
	CWnd* m_pParent;//´°¿Ú¶ÔÏó

// Dialog Data
	//{{AFX_DATA(CTextColorDlg)
	enum { IDD = IDD_DIALOG1 };
	int		m_red;
	int		m_green;
	int		m_blue;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTextColorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTextColorDlg)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXTCOLORDLG_H__E44BBEF5_826E_47EB_8D5A_4280DA2A504B__INCLUDED_)
