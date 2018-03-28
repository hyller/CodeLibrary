#if !defined(AFX_COLORPAGE_H__134234CC_9B54_4C9E_A06F_323F6EBA5F5A__INCLUDED_)
#define AFX_COLORPAGE_H__134234CC_9B54_4C9E_A06F_323F6EBA5F5A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ColorPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CColorPage dialog

class CColorPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CColorPage)

// Construction
public:
	CColorPage();
	~CColorPage();

// Dialog Data
	//{{AFX_DATA(CColorPage)
	enum { IDD = IDD_COLOR };
	int		m_r;
	int		m_g;
	int		m_b;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CColorPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CColorPage)
	afx_msg void OnChangeEdit1();
	afx_msg void OnChangeEdit2();
	afx_msg void OnChangeEdit3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORPAGE_H__134234CC_9B54_4C9E_A06F_323F6EBA5F5A__INCLUDED_)
