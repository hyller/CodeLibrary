// GradientTextDemo.h : main header file for the GRADIENTTEXTDEMO application
//

#if !defined(AFX_GRADIENTTEXTDEMO_H__DDADC908_C23A_441F_8062_F1CCDA390EDF__INCLUDED_)
#define AFX_GRADIENTTEXTDEMO_H__DDADC908_C23A_441F_8062_F1CCDA390EDF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CGradientTextDemoApp:
// See GradientTextDemo.cpp for the implementation of this class
//

class CGradientTextDemoApp : public CWinApp
{
public:
	CGradientTextDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGradientTextDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CGradientTextDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRADIENTTEXTDEMO_H__DDADC908_C23A_441F_8062_F1CCDA390EDF__INCLUDED_)
