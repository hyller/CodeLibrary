#if !defined(AFX_COLORDLG_H__9D1EA186_F0A8_4352_8D63_4060AECD5FB9__INCLUDED_)
#define AFX_COLORDLG_H__9D1EA186_F0A8_4352_8D63_4060AECD5FB9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ColorDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CColorDlg dialog

class CColorDlg : public CDialog
{
// Construction
public:
	CColorDlg(CWnd* pParent = NULL);   // standard constructor
	int old_r,old_g,old_b;

// Dialog Data
	//{{AFX_DATA(CColorDlg)
	enum { IDD = IDD_DIALOG1 };
	CEdit	m_B;
	CEdit	m_G;
	CEdit	m_R;
	int		m_r;
	int		m_g;
	int		m_b;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CColorDlg)
	afx_msg void OnReset();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORDLG_H__9D1EA186_F0A8_4352_8D63_4060AECD5FB9__INCLUDED_)
