// ReadEditDemo.h : main header file for the READEDITDEMO application
//

#if !defined(AFX_READEDITDEMO_H__27268784_695C_4001_9F10_F2E298598A23__INCLUDED_)
#define AFX_READEDITDEMO_H__27268784_695C_4001_9F10_F2E298598A23__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CReadEditDemoApp:
// See ReadEditDemo.cpp for the implementation of this class
//

class CReadEditDemoApp : public CWinApp
{
public:
	CReadEditDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReadEditDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CReadEditDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_READEDITDEMO_H__27268784_695C_4001_9F10_F2E298598A23__INCLUDED_)
