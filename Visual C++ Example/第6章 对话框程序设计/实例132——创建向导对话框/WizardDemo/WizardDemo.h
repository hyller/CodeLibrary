// WizardDemo.h : main header file for the WizardDemo application
//

#if !defined(AFX_WizardDemo_H__A99E64B9_74DE_11D6_8F32_00E04CE76240__INCLUDED_)
#define AFX_WizardDemo_H__A99E64B9_74DE_11D6_8F32_00E04CE76240__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWizardDemoApp:
// See WizardDemo.cpp for the implementation of this class
//

class CWizardDemoApp : public CWinApp
{
public:
	CWizardDemoApp();

// Overrides
	// ClassWizardDemo generated virtual function overrides
	//{{AFX_VIRTUAL(CWizardDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWizardDemoApp)
		// NOTE - the ClassWizardDemo will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WizardDemo_H__A99E64B9_74DE_11D6_8F32_00E04CE76240__INCLUDED_)
