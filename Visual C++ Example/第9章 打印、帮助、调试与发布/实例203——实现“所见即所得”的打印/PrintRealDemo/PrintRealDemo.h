// PrintRealDemo.h : main header file for the PRINTREALDEMO application
//

#if !defined(AFX_PRINTREALDEMO_H__F3B4527E_4668_4E55_936E_13184954BB8D__INCLUDED_)
#define AFX_PRINTREALDEMO_H__F3B4527E_4668_4E55_936E_13184954BB8D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPrintRealDemoApp:
// See PrintRealDemo.cpp for the implementation of this class
//

class CPrintRealDemoApp : public CWinApp
{
public:
	CPrintRealDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrintRealDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CPrintRealDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRINTREALDEMO_H__F3B4527E_4668_4E55_936E_13184954BB8D__INCLUDED_)
