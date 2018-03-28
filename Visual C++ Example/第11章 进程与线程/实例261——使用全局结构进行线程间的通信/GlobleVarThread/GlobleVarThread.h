// GlobleVarThread.h : main header file for the GlobleVarThread application
//

#if !defined(AFX_GlobleVarThread_H__0A78C205_C955_4690_997F_B7995F933191__INCLUDED_)
#define AFX_GlobleVarThread_H__0A78C205_C955_4690_997F_B7995F933191__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGlobleVarThreadApp:
// See GlobleVarThread.cpp for the implementation of this class
//

class CGlobleVarThreadApp : public CWinApp
{
public:
	CGlobleVarThreadApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGlobleVarThreadApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGlobleVarThreadApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GlobleVarThread_H__0A78C205_C955_4690_997F_B7995F933191__INCLUDED_)
