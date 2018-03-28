#if !defined(AFX_MYWIZARD_H__D32916FB_2345_4A02_AE15_58713715C9C0__INCLUDED_)
#define AFX_MYWIZARD_H__D32916FB_2345_4A02_AE15_58713715C9C0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyWizard.h : header file
//
#include "Step1.h"
#include "Step2.h"
#include "Step3.h"
/////////////////////////////////////////////////////////////////////////////
// CMyWizard

class CMyWizard : public CPropertySheet
{
	DECLARE_DYNAMIC(CMyWizard)

// Construction
public:
	CMyWizard(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CMyWizard(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

// Attributes
public:

// Operations
public:
	CStep1 MyStep1; //ÊôÐÔÒ³1 
	CStep2 MyStep2; //ÊôÐÔÒ³2 
	CStep3 MyStep3; //ÊôÐÔÒ³3 
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyWizard)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyWizard();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMyWizard)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYWIZARD_H__D32916FB_2345_4A02_AE15_58713715C9C0__INCLUDED_)
