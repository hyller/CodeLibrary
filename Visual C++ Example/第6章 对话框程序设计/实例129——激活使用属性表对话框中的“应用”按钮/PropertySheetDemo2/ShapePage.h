#if !defined(AFX_SHAPEPAGE_H__D8CB570E_EB17_4D4F_9CD5_3AADB7161795__INCLUDED_)
#define AFX_SHAPEPAGE_H__D8CB570E_EB17_4D4F_9CD5_3AADB7161795__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ShapePage.h : header file
//
#define WM_USER_APPLY WM_USER + 1
/////////////////////////////////////////////////////////////////////////////
// CShapePage dialog

class CShapePage : public CPropertyPage
{
	DECLARE_DYNCREATE(CShapePage)

// Construction
public:
	CShapePage();
	~CShapePage();

// Dialog Data
	//{{AFX_DATA(CShapePage)
	enum { IDD = IDD_SHAPE };
	int		m_radio;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CShapePage)
	public:
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CShapePage)
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHAPEPAGE_H__D8CB570E_EB17_4D4F_9CD5_3AADB7161795__INCLUDED_)
