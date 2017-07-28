// DlgDateExchange2.h : main header file for the DlgDateExchange2 application
//

#if !defined(AFX_DlgDateExchange2_H__3A6AA4D5_E373_4DE0_89DA_7BC6EFF79673__INCLUDED_)
#define AFX_DlgDateExchange2_H__3A6AA4D5_E373_4DE0_89DA_7BC6EFF79673__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDlgDateExchange2App:
// See DlgDateExchange2.cpp for the implementation of this class
//

class CDlgDateExchange2App : public CWinApp
{
public:
	CDlgDateExchange2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgDateExchange2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDlgDateExchange2App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DlgDateExchange2_H__3A6AA4D5_E373_4DE0_89DA_7BC6EFF79673__INCLUDED_)
