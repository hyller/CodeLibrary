#if !defined(AFX_COLOARDLG_H__F693EF4C_BCC7_4EAF_9B54_93679677CAEE__INCLUDED_)
#define AFX_COLOARDLG_H__F693EF4C_BCC7_4EAF_9B54_93679677CAEE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ColoarDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CColoarDlg dialog

class CColoarDlg : public CDialog
{
// Construction
public:
	CColoarDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CColoarDlg)
	enum { IDD = IDD_DIALOG1 };
	int		m_Red;
	int		m_Green;
	int		m_Blue;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColoarDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CColoarDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLOARDLG_H__F693EF4C_BCC7_4EAF_9B54_93679677CAEE__INCLUDED_)
