// EscNoExitDemo.h : main header file for the ESCNOEXITDEMO application
//

#if !defined(AFX_ESCNOEXITDEMO_H__63A162EF_C609_4A4D_8CA6_37CFCEC31B24__INCLUDED_)
#define AFX_ESCNOEXITDEMO_H__63A162EF_C609_4A4D_8CA6_37CFCEC31B24__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEscNoExitDemoApp:
// See EscNoExitDemo.cpp for the implementation of this class
//

class CEscNoExitDemoApp : public CWinApp
{
public:
	CEscNoExitDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEscNoExitDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEscNoExitDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ESCNOEXITDEMO_H__63A162EF_C609_4A4D_8CA6_37CFCEC31B24__INCLUDED_)
