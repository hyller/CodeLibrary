#if !defined(AFX_NEWDIALOGBAR_H__75F727DB_9116_4010_A369_DAE727D934B0__INCLUDED_)
#define AFX_NEWDIALOGBAR_H__75F727DB_9116_4010_A369_DAE727D934B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NewDialogBar.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNewDialogBar dialog

class CNewDialogBar : public CDialogBar
{
// Construction
public:
	CNewDialogBar(CWnd* pParent = NULL);   // standard constructor
	virtual BOOL OnInitDialog();
// Dialog Data
	//{{AFX_DATA(CNewDialogBar)
	enum { IDD = IDD_DIALOG_BAR };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewDialogBar)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNewDialogBar)
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnButton1();
	afx_msg void OnMenu1();
	afx_msg void OnMenu2();
	afx_msg void OnMenu3();
	afx_msg void OnMenu4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWDIALOGBAR_H__75F727DB_9116_4010_A369_DAE727D934B0__INCLUDED_)
