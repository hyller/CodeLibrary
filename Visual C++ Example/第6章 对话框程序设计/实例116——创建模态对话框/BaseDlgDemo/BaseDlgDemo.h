// BaseDlgDemo.h : main header file for the BaseDlgDemo application
//

#if !defined(AFX_BaseDlgDemo_H__85706D5D_182E_4066_871C_D48145939BDD__INCLUDED_)
#define AFX_BaseDlgDemo_H__85706D5D_182E_4066_871C_D48145939BDD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CBaseDlgDemoApp:
// See BaseDlgDemo.cpp for the implementation of this class
//

class CBaseDlgDemoApp : public CWinApp
{
public:
	CBaseDlgDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBaseDlgDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CBaseDlgDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BaseDlgDemo_H__85706D5D_182E_4066_871C_D48145939BDD__INCLUDED_)
