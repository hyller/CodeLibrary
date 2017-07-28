// SDIActiveXDemo.h : main header file for the SDIACTIVEXDEMO application
//

#if !defined(AFX_SDIACTIVEXDEMO_H__3C8E2B90_739B_4B4E_845C_92B7E9C26C26__INCLUDED_)
#define AFX_SDIACTIVEXDEMO_H__3C8E2B90_739B_4B4E_845C_92B7E9C26C26__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSDIActiveXDemoApp:
// See SDIActiveXDemo.cpp for the implementation of this class
//

class CSDIActiveXDemoApp : public CWinApp
{
public:
	CSDIActiveXDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSDIActiveXDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSDIActiveXDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SDIACTIVEXDEMO_H__3C8E2B90_739B_4B4E_845C_92B7E9C26C26__INCLUDED_)
